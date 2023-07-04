//
// Created by 86183 on 2023/7/4.
//
#include "gtest/gtest.h"
#include "bloom_filter.h"
#include "strided_bloom_filter.h"

// Test StridedBloomFilter
TEST(StridedBloomFilterTest, InsertStridedAndQueryStrided) {
    StridedBloomFilter sbf(1000, 5, 3);
    sbf.insertStrided("hello world", 3);
    sbf.insertStrided("foo bar", 3);
    EXPECT_EQ(sbf.queryStrided("helloworld", 3), 1);
    EXPECT_EQ(sbf.queryStrided("worldfoo", 3), 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
