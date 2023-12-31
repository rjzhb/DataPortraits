//
// Created by 86183 on 2023/7/4.
//
#include <spdlog/spdlog.h>
#include "gtest/gtest.h"
#include "bloom_filter.h"
#include "strided_bloom_filter.h"
#include "define.h"

// Test StridedBloomFilter
TEST(StridedBloomFilterTest, InsertStridedAndQueryStrided) {
    const size_t filter_size = 1000;
    const size_t stride = 3;
    const size_t tile_size = 1;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->insertStrided("hello world", stride);
    filter->insertStrided("foo bar", stride);

    EXPECT_EQ(filter->queryStrided("hello world", stride), 3);
    EXPECT_TRUE(filter->getChain() == (std::vector<std::string>{"hel", "wor"}));
    EXPECT_EQ(filter->queryStrided("worldfoo", stride), 2);
    // the risk of missing some string of interest if it is split by a tile boundary in the corpus
    EXPECT_TRUE(filter->getChain() == (std::vector<std::string>{"hel", "wor", "foo"}));
    delete filter;
}

/**
 *
 * " *|X X|* " means XX is match
1. Corpus:    |The|key|is:|a|b|c|d|e|f|g|h|i|j|k|l|m|n|

2. Hash n-grams: |The key is: a|  |bcde| |fghi| |jklm|

3. query:  |a|b|c|d|e|f|g||h|i|j|k|l|m|n|

4.query n-grams(stride=1): |abcd|  *|bcde|*  |cdef| |defg| *|fghi|* |ghij| |hijk| |ijkl| *|jklm|* |klmn|

5.Matches:   |b|c|d|e|f|g|h|i|j|k|l|m|
 */
TEST(StridedBloomFilterTest2, InsertStridedAndQueryStridedInPaperCase) {
    const size_t filter_size = 1000;
    const size_t stride = 4;
    const size_t tile_size = 4;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->insertStrided("The key is: a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", stride);

    EXPECT_EQ(filter->queryStrided("a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", stride), 3);
    EXPECT_EQ(filter->getChain(), std::vector<std::string>{"b   c   d   e   f   g   h   i   j   k   l   m   "});

    delete filter;
}

TEST(StridedBloomFilterTest3, case1) {
    const size_t filter_size = 1000;
    const size_t stride = 4;
    const size_t tile_size = 4;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->insertStrided("Johns Hopkins University is divided into nine schools, "
                          "five of which serve undergraduates. "
                          "The Homewood Campus, one of the university’s four campuses in and around Baltimore, "
                          "is the primary campus for undergraduates. Freshmen and sophomores are required to live on campus. "
                          "More than 1,300 students participate in the Greek community. "
                          "Hopkins also has additional campuses for its School of Advanced International Studies in Washington, D.C."
                          "; Bologna, Italy; and Nanjing, China. Hopkins’ graduate programs include the top-ranked Bloomberg School of Public Health and the highly ranked School of Education,"
                          " Whiting School of Engineering, School of Medicine and the well-regarded Peabody Institute for music and dance. "
                          "Johns Hopkins Hospital is a top-ranked hospital with highly ranked specialties.", stride);

    EXPECT_EQ(filter->queryStrided(
            "The Homewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for undergraduates.",
            stride), 7);
    EXPECT_EQ(filter->getChain(),
              std::vector<std::string>{
                      "omewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for under"});

    delete filter;
}

TEST(StridedBloomFilterTest4, case2) {
    const size_t filter_size = 1000;
    const size_t stride = 4;
    const size_t tile_size = 4;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->insertStrided("Johns Hopkins University is divided into nine schools, "
                          "five of which serve undergraduates. The Homewood Campus, "
                          "one of the university’s four campuses in and around Baltimore, "
                          "is the primary campus for undergraduates. Freshmen and sophomores "
                          "are required to live on campus. More than 1,300 students participate in the Greek community."
                          " Hopkins also has additional campuses for its School of Advanced International Studies in Washington, D.C."
                          "; Bologna, Italy; and Nanjing, China. Hopkins’ graduate programs include the top-ranked Bloomberg School of Public Health and the highly ranked School of Education, "
                          "Whiting School of Engineering, School of Medicine and the well-regarded Peabody Institute for music and dance. "
                          "Johns Hopkins Hospital is a top-ranked hospital with highly ranked specialties. ",
                          stride);
    filter->queryStrided(
            "The Homewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for undergraduates.",
            stride);

    auto longest_chain = filter->getLongestChain();
    for (size_t i = 0; i < longest_chain.size(); i++) {
        spdlog::info("longest chain {}: {}", i, longest_chain[i]);
    }

    filter->clear();
    delete filter;
}

TEST(StridedBloomFilterTest5, case3) {
    const size_t filter_size = 1000;
    const size_t stride = 4;
    const size_t tile_size = 4;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->readBinFileToFilter("../../test/hashtable.bin");
    filter->queryStrided(
            "The Homewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for undergraduates.",
            stride);
    auto longest_chain = filter->getLongestChain();
    for (size_t i = 0; i < longest_chain.size(); i++) {
        spdlog::info("longest chain {}: {}", i, longest_chain[i]);
    }

    filter->clear();
    delete filter;
}

TEST(StridedBloomFilterTest5, InsertStridedAndQueryStridedInPaperCase2) {
    const size_t filter_size = 1000;
    const size_t stride = 4;
    const size_t tile_size = 4;

    auto *filter = new StridedBloomFilter(filter_size, HASH_FUNCTION_AMOUNT, tile_size);

    filter->readBinFileToFilter("../../test/hashtable.bin");

    EXPECT_EQ(filter->queryStrided("a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", stride), 3);
    EXPECT_EQ(filter->getChain(), std::vector<std::string>{"b   c   d   e   f   g   h   i   j   k   l   m   "});

    delete filter;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
