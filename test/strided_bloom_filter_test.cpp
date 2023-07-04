//
// Created by 86183 on 2023/7/4.
//
#include "gtest/gtest.h"
#include "bloom_filter.h"
#include "strided_bloom_filter.h"

// Test StridedBloomFilter
TEST(StridedBloomFilterTest, InsertStridedAndQueryStrided) {
    auto *filter = new StridedBloomFilter(1000, 5, 1);
    filter->insertStrided("hello world", 3);
    filter->insertStrided("foo bar", 3);
    EXPECT_EQ(filter->queryStrided("hello world", 3), 3);
    EXPECT_EQ(filter->getChain(), "hello wor");
    EXPECT_EQ(filter->queryStrided("worldfoo", 3), 2);
    // the risk of missing some string of interest if it is split by a tile boundary in the corpus
    EXPECT_EQ(filter->getChain(), "worfoo");
    delete filter;
}

TEST(StridedBloomFilterTest2, InsertStridedAndQueryStridedInPaperCase) {
    auto *filter = new StridedBloomFilter(1000, 5, 4);
    filter->insertStrided("The key is: a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", 4);
    EXPECT_EQ(filter->queryStrided("a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", 4), 3);
    EXPECT_EQ(filter->getChain(), "b   c   d   e   f   g   h   i   j   k   l   m   ");
    delete filter;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
