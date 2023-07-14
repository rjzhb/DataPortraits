//
// Created by 86183 on 2023/7/12.
//
#include <thread>
#include <future>
#include <spdlog/spdlog.h>
#include "gtest/gtest.h"
#include "dataloader.h"
#include "strided_bloom_filter.h"
#include "string_util.h"


std::string read_file(const std::string &file_path) {
    std::ifstream input_file(file_path);
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file: " + file_path);
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    return buffer.str();
}

void hashDatasetIntoDisk(const std::string &file,
                         const size_t stride,
                         const size_t tile_size,
                         const size_t filter_size,
                         const size_t block_size,
                         const size_t num_blocks
) {

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(file, block_size, filter_size, stride, tile_size);

    std::string directory = file.substr(0, file.find_last_of('/'));
    std::string file_name = file.substr(file.find_last_of('/') + 1);
    std::string extension = file_name.substr(file_name.find_last_of('.') + 1);
    std::string name = file_name.substr(0, file_name.find_last_of('.'));

//parallel
#pragma omp parallel for
    for (
            size_t i = 0;
            i < num_blocks;
            ++i) {
        std::vector<char> block = loader.getNextBlock();
        if (!block.

                empty()

                ) {
            loader.
                    processBlock(block);
        }
    }

    loader.writeFilterToFile(directory + "/" + name + ".bin");

    //write config
    std::ofstream config_file(directory + "/config.txt");

    config_file << "dataSetName = " << file_name << std::endl;
    config_file << "stride = " << stride << std::endl;
    config_file << "tileSize = " << tile_size << std::endl;
    config_file << "filterSize = " << filter_size << std::endl;
}

TEST(DataSetTest, testDatasetGPTNEO_2_save) {
    std::string file = "../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.txt";

    const size_t stride = 4;
    const size_t tile_size = 4;
    const size_t filter_size = 1000;
    const size_t block_size = (119 * 1024 * 1024) / (stride * tile_size) * 100;
    const size_t num_blocks = 119 * 1024 * 1024 / block_size;

    hashDatasetIntoDisk(file, stride, tile_size, filter_size, block_size, num_blocks);
}

TEST(DataSetTest, testDatasetGPTNEO_2_query) {
    std::string file = "../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.txt";
    std::string directory = file.substr(0, file.find_last_of('/'));
    std::ifstream config_file(directory + "/config.txt");
    std::string dataSetName = ConfigReader<std::string>::read("dataSetName", config_file);

    const size_t stride = ConfigReader<size_t>::read("stride", config_file);
    const size_t tile_size = ConfigReader<size_t>::read("tileSize", config_file);
    const size_t filter_size = ConfigReader<size_t>::read("filterSize", config_file);

    std::string query_ngrams;
    std::cout << "input your query text" << std::endl;
    std::cin >> query_ngrams;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    std::string file_name = file.substr(file.find_last_of('/') + 1);
    std::string extension = file_name.substr(file_name.find_last_of('.') + 1);
    std::string name = file_name.substr(0, file_name.find_last_of('.'));

    filter->readBinFileToFilter(directory + "/" + name + ".bin");
    filter->queryStrided(query_ngrams, stride);

    auto longest_chain = filter->getLongestChain();
    for (size_t i = 0; i < longest_chain.size(); i++) {
        spdlog::info("longest chain {}: [{}]", i, longest_chain[i]);
    }

    filter->clear();
    delete filter;

    spdlog::info("end");
}

TEST(DataSetTest, testDatasetGPTNEO_2_memory_query) {
    const size_t stride = 4;
    const size_t tile_size = 4;
    const size_t filter_size = 6239027;

    const std::string query_str = "#\n"
                                  "# THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
                                  "# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
                                  "# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
                                  "# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
                                  "# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
                                  "# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n"
                                  "# THE SOFTWARE.";
    try {
        std::string file_path = "../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.txt";
        std::string file_contents = read_file(file_path);
        auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

        std::cout << file_contents.size() << std::endl;
        filter->insertStrided(file_contents, stride);
        filter->queryStrided(query_str, stride);

        auto longest_chain = filter->getLongestChain();
        for (size_t i = 0; i < longest_chain.size(); i++) {
            spdlog::info("longest chain {}: [{}]", i, longest_chain[i]);
        }

        filter->clear();
        delete filter;

        spdlog::info("end");
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}