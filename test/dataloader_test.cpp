//
// Created by 86183 on 2023/7/6.
//
#include <thread>
#include <future>
#include "gtest/gtest.h"
#include "dataloader.h"
#include "task_queue.h"

TEST(DataLoaderTest, ReadAndWrite) {
    std::string filename = "test.bin";

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, 2048, 5, 4);
    while (loader.hasNextBlock()) {
        std::vector<char> block = loader.getNextBlock();
        loader.processBlock(block);
    }

    loader.writeFilterToFile("hashtable.bin");
    // Compare the two filter
    auto temp = loader.readFileToVector("hashtable.bin");

    EXPECT_EQ(temp, loader.getFilter());
}

TEST(DataLoaderTest, WriteFilterToFile) {
    std::string filename = "../../dataset/ag_news_csv/train.txt";

    //Blocksize should ideally be exactly divided by stripe * tile_ Size
    size_t stride = 5;
    size_t tile_size = 20;

    // Read the test file and write data of bloomfilter hash into a new file
    DataLoader loader(filename, DATASET_SIZE / (stride * tile_size) * 1000, stride, tile_size);
    // Create a task queue and thread pool for processing data blocks
    TaskQueue queue(100);
    std::vector<std::future<void>> futures;
    const int num_threads = std::thread::hardware_concurrency();
    for (int i = 0; i < num_threads; ++i) {
        futures.emplace_back(std::async(std::launch::async, process_worker, std::ref(loader), std::ref(queue)));
    }

    // Read data blocks and add them to the task queue
    while (loader.hasNextBlock()) {
        std::vector<char> block = loader.getNextBlock();
        if (!block.empty()) {
            Task task = {block, loader.getCurrentPos()};
            queue.push(task);
        }
    }

    // Wait for all data blocks to be processed
    for (std::future<void> &future: futures) {
        future.wait();
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
