#include <fstream>
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>
#include "strided_bloom_filter.h"
#include "define.h"
#include "dataloader.h"
#include "string_util.h"

std::string train_query_ngrams = "A bargain hunter's paradise Massachusetts bargain hunters showed up in droves and shopped hard on yesterday's sales tax holiday, buying everything from treadmills and snow blowers to candles and chandeliers, and crediting the 5-percent tax break with bringing them into the stores.\n"
                                 "3 Researchers seek to untangle the e-mail thread E-mail is a victim of its own success. That's the conclusion of IBM Corp. researchers in Cambridge, who have spent nearly a decade conducting field tests at IBM and other companies about how employees work and use electronic mail. It's clear to them that e-mail has become the Internet's killer application.\n"
                                 "3 Microsoft Corp. 2.0: a kinder corporate culture Even a genius can mess up. Bill Gates was a brilliant technologist when he cofounded Microsoft , but as he guided it to greatness in both size and historical consequence, he blundered. He terrorized underlings with his temper and parceled out praise like Scrooge gave to charity. Only the lash inspired the necessary aggressiveness to beat the competition, he thought.\n"
                                 "3 Letters Target the abusers of legal weapons We can all share the outrage, expressed by columnist Steve Bailey (''Summer Sizzler, quot; Aug. 11), at the killings in the city's poor neighborhoods. But there's no need to share his ignorance. He argues for renewal of the so-called assault weapon ban, claiming that otherwise, ''UZIs and AK-47s could again be flooding the streets. quot; His ...\n"
                                 "3 Somewhere between gleam and gloom President Bush has been saying that the US economy has ''turned the corner. quot; Democratic presidential candidate Senator John F. Kerry, in the wake of this month's poor jobs report, quipped that it was more like a U-turn.\n"
                                 "3 Technology company sues five ex-employees  A Marlborough-based technology company is suing five former employees, including three senior managers, for allegedly conspiring against their employer while working on opening a competing business.\n"
                                 "3 Grant to aid Lynn Central Square Central Square in Lynn should be looking a bit brighter. New sidewalks, curbs, fences, lights, landscaping, and road improvements are planned for the Gateway Artisan Block, a key area of the square, with \\$830,000 in state grant money given to Lynn last week.\n"
                                 "3 State grant to aid Lynn; Bank gives Salem \\$10k Central Square in Lynn should be looking a bit brighter. New sidewalks, curbs, fences, lights, landscaping, and road improvements are planned for the Gateway Artisan Block, a key area of the square, with \\$830,000 in state grant money given to Lynn last week.\n"
                                 "3 A New Legal Chapter for a 90's Flameout A lawsuit against Gary Winnick, the former chief of Global Crossing, refocuses attention on what Mr. Winnick knew about his company's finances as it imploded.\n"
                                 "3 Will Russia, the Oil Superpower, Flex Its Muscles? Russia is again emerging as a superpower - but the reason has less to do with nuclear weapons than with oil.";


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

    config_file << "dataSetName:" << file_name << std::endl;
    config_file << "stride:" << stride << std::endl;
    config_file << "tileSize:" << tile_size << std::endl;
    config_file << "filterSize:" << filter_size << std::endl;
}

int main() {
    //dataset path
//    std::string file ="../../dataset/ag_news_csv/train.txt";
    std::string file = "../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.txt";
    std::string is_hash_text{};

    std::cout << "Do you need to hash this dataset first? It will take some time to read and save it on disk. (y/n)"
              << std::endl;
    std::cin >> is_hash_text;

    size_t stride;
    size_t tile_size;
    size_t filter_size;
    size_t dataset_size, block_size, num_blocks;
    size_t memory_limit;

    if (is_hash_text == "y") {
        std::cout << "input stride, tileSize, filterSize" << std::endl;
        std::cin >> stride >> tile_size >> filter_size;
        std::cout << "Please input the size of your dataset in bytes (B)." << std::endl;
        std::cin >> dataset_size;
        std::cout << "tell me your memory limit of computer" << std::endl;
        std::cin >> memory_limit;
        block_size = (memory_limit / sizeof(float)) / (dataset_size / (stride * tile_size * sizeof(float)));
        block_size *= stride * tile_size * sizeof(float);
        // 计算块数
        num_blocks = dataset_size / block_size % 3;
        block_size = dataset_size / num_blocks;
        hashDatasetIntoDisk(file, stride, tile_size, filter_size, block_size, num_blocks);
    } else if (is_hash_text != "y" && is_hash_text != "n") {
        std::cout << "The input seems to be incorrect. The default value is 'no'." << std::endl;
    }

    bool no_read = stride == 0 || tile_size == 0 || filter_size == 0;
    if (no_read) {
//        std::string directory = file.substr(0, file.find_last_of('/'));
//        std::ifstream config_file(directory + "/config.txt");
//
//        if (!config_file.is_open()) {
//            spdlog::error("config file not found");
//            return 0;
//        }
//
//        std::string dataSetName = ConfigReader<std::string>::read("dataSetName", config_file);
//
//        stride = ConfigReader<size_t>::read("stride", config_file);
//        tile_size = ConfigReader<size_t>::read("tileSize", config_file);
//        filter_size = ConfigReader<size_t>::read("filterSize", config_file);

        stride = 4;
        tile_size = 4;
        filter_size = 124780544;
    }

    std::string query_ngrams;
    std::cout << "input your query text" << std::endl;
    std::cin >> query_ngrams;
    spdlog::info("start test");

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    std::string directory = file.substr(0, file.find_last_of('/'));
    std::string file_name = file.substr(file.find_last_of('/') + 1);
    std::string extension = file_name.substr(file_name.find_last_of('.') + 1);
    std::string name = file_name.substr(0, file_name.find_last_of('.'));

    spdlog::info("start read bin file");
    filter->readBinFileToFilter(directory + "/" + name + ".bin");

    spdlog::info("start query");
    filter->queryStrided(query_ngrams, stride);

    spdlog::info("query successful, start getting chain");
    auto longest_chain = filter->getLongestChain();
    for (size_t i = 0; i < longest_chain.size(); i++) {
        spdlog::info("longest chain {}: [{}]", i, longest_chain[i]);
    }

    filter->clear();
    delete filter;

    spdlog::info("end");
    return 0;
}
