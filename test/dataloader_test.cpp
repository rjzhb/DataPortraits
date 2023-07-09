//
// Created by 86183 on 2023/7/6.
//
#include <thread>
#include <future>
#include "gtest/gtest.h"
#include "dataloader.h"
#include "task_queue.h"


TEST(DataLoaderTest, ReadAndWrite) {
    std::string filename = "../../test/test.bin";

    size_t stride = 4;
    size_t tile_size = 4;
    size_t filter_size = 1000;
    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, 2048, filter_size, stride, tile_size);
    while (loader.hasNextBlock()) {
        std::vector<char> block = loader.getNextBlock();
        loader.processBlock(block);
    }

    loader.writeFilterToFile("../../test/hashtable.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("../../test/hashtable.bin");

    EXPECT_EQ(temp, loader.getFilter());
}

TEST(DataLoaderTest, WriteFilterToFile) {
    std::string filename = "../../dataset/ag_news_csv/train.txt";

    size_t stride = 5;
    size_t tile_size = 20;
    size_t filter_size = 10000;
    size_t block_size = DATASET_SIZE / (stride * tile_size) * 1000;
    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, DATASET_SIZE / (stride * tile_size) * 1000, filter_size, stride, tile_size);
    while (loader.hasNextBlock()) {
        std::vector<char> block = loader.getNextBlock();
        loader.processBlock(block);
    }

    loader.writeFilterToFile("../../dataset/ag_news_csv/train.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("../../dataset/ag_news_csv/train.bin");

    EXPECT_EQ(temp, loader.getFilter());
}


TEST(DataLoaderTest, ParallelWriteFilterToFile) {
    std::string filename = "../../dataset/ag_news_csv/train.txt";

    //Blocksize should ideally be exactly divided by stripe * tile_ Size
    size_t stride = 5;
    size_t tile_size = 20;
    size_t filter_size = 10000;
    size_t block_size = DATASET_SIZE / (stride * tile_size) * 1000;
    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);

    size_t num_blocks = 29 * 1024 * 1024 / block_size;

    //parallel
#pragma omp parallel for
    for (size_t i = 0; i < num_blocks; ++i) {
        std::vector<char> block = loader.getNextBlock();
        if (!block.empty()) {
            loader.processBlock(block);
        }
    }

    loader.writeFilterToFile("../../dataset/ag_news_csv/train.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("../../dataset/ag_news_csv/train.bin");

    EXPECT_EQ(temp, loader.getFilter());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
