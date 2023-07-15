//
// Created by 86183 on 2023/7/6.
//
#include <thread>
#include <future>
#include "gtest/gtest.h"
#include "dataloader.h"

TEST(DataLoaderTest, ReadAndWrite) {
    std::string filename = "../../test/test.bin";

    const size_t stride = 4;
    const size_t tile_size = 4;
    const size_t filter_size = 1000;
    const size_t block_size = 1024 * 2;

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);
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

    const size_t stride = 5;
    const size_t tile_size = 20;
    const size_t filter_size = 10000;
    const size_t block_size = DATASET_SIZE / (stride * tile_size) * 1000;

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);
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
    const size_t stride = 20;
    const size_t tile_size = 20;
    const size_t filter_size = 1000;
    const size_t block_size = DATASET_SIZE / (stride * tile_size) * 1000;
    const size_t num_blocks = 29 * 1024 * 1024 / block_size;

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);

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

TEST(DataLoaderTest, ParallelWriteFilterToFile1) {
    std::string filename = "../../dataset/gpt-neo/540L_50TOPK_1.3B/sequences.txt";

    //Blocksize should ideally be exactly divided by stripe * tile_ Size
    const size_t stride = 4;
    const size_t tile_size = 4;
    const size_t filter_size = 12478054;
    const size_t block_size = 15 * 1024 * 1024 / 2;
    const size_t num_blocks = 2;


    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);
    //parallel
#pragma omp parallel for
    for (size_t i = 0; i < num_blocks; ++i) {
        std::vector<char> block = loader.getNextBlock();
        if (!block.empty()) {
            loader.processBlock(block);
        }
    }

    loader.writeFilterToFile("../../dataset/gpt-neo/540L_50TOPK_1.3B/sequences.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("../../dataset/gpt-neo/540L_50TOPK_1.3B/sequences.bin");

    EXPECT_EQ(temp, loader.getFilter());
}



TEST(DataLoaderTest, ParallelWriteFilterToFile2) {
    std::string filename = "../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.txt";

    //Blocksize should ideally be exactly divided by stripe * tile_ Size
    const size_t stride = 1;
    const size_t tile_size = 50;
    const size_t filter_size = 4367319;
    const size_t block_size = 119 * 1024 * 1024 / 2;
    const size_t num_blocks = 2;


    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, block_size, filter_size, stride, tile_size);
    //parallel
#pragma omp parallel for
    for (size_t i = 0; i < num_blocks; ++i) {
        std::vector<char> block = loader.getNextBlock();
        if (!block.empty()) {
            loader.processBlock(block);
        }
    }

    loader.writeFilterToFile("../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("../../dataset/gpt-neo/540L_50TOPK_2.7B/sequences.bin");

    EXPECT_EQ(temp, loader.getFilter());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
