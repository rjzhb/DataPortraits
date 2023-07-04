//
// Created by 86183 on 2023/7/4.
//
#include "gtest/gtest.h"
#include "bloom_filter.h"
#include "strided_bloom_filter.h"

// Test BloomFilter
TEST(BloomFilterTest, InsertAndContains) {
    BloomFilter bf(1000, 5);
    bf.insert("hello");
    bf.insert("world");
    EXPECT_TRUE(bf.contains("hello"));
    EXPECT_TRUE(bf.contains("world"));
    EXPECT_FALSE(bf.contains("foo"));
    EXPECT_FALSE(bf.contains("bar"));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
