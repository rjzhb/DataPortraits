//
// Created by 86183 on 2023/7/4.
//
#include "gtest/gtest.h"
#include "bloom_filter.h"
#include "strided_bloom_filter.h"

// Test StridedBloomFilter
TEST(StridedBloomFilterTest, InsertStridedAndQueryStrided) {
    StridedBloomFilter filter(1000, 5, 3);
    filter.insertStrided("hello world");
    filter.insertStrided("foo bar");
    EXPECT_EQ(filter.queryStrided("hello world"), 3);
    EXPECT_EQ(filter.queryStrided("worldfoo"), 2);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
