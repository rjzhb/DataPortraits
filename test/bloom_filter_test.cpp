//
// Created by 86183 on 2023/7/4.
//
#include "gtest/gtest.h"
#include "bloom_filter.h"

// Test BloomFilter
TEST(BloomFilterTest, InsertAndContains) {
    auto *filter = new BloomFilter(1000, 5);

    filter->insert("hello");
    filter->insert("world");

    EXPECT_TRUE(filter->contains("hello"));
    EXPECT_TRUE(filter->contains("world"));
    EXPECT_FALSE(filter->contains("foo"));
    EXPECT_FALSE(filter->contains("bar"));
    delete filter;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
