//
// Created by 86183 on 2023/7/6.
//
#include "gtest/gtest.h"
#include "../src/dataloader/dataloader.h"

TEST(DataLoaderTest, ReadAndWrite) {
    std::string filename = "test.bin";

    // Create a test file with random data
    std::ofstream outfile(filename, std::ios::binary);
    std::vector<char> block(2048);
    std::generate(block.begin(), block.end(), []() { return std::rand() % 256; });
    outfile.write(block.data(), block.size());
    outfile.close();

    // Read the test file and write it to a new file
    DataLoader loader(filename, 2048);
    while (loader.hasNextBlock()) {
        std::vector<char> block = loader.getNextBlock();
        loader.processBlock(block, 5, 4);
    }

    loader.writeFilterToFile("hashtable.bin");
    // Compare the two files
    auto temp = loader.readFileToVector("hashtable.bin");

    EXPECT_EQ(temp, loader.getFilter());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
