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
    auto *filter = new StridedBloomFilter(1000, 5, 4);

    filter->insertStrided("The key is: a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", 4);

    EXPECT_EQ(filter->queryStrided("a   b   c   d   e   f   g   h   i   j   k   l   m   n   ", 4), 3);
    EXPECT_EQ(filter->getChain(), "b   c   d   e   f   g   h   i   j   k   l   m   ");

    delete filter;
}

TEST(StridedBloomFilterTest3, case1) {
    auto *filter = new StridedBloomFilter(1000, 5, 4);

    filter->insertStrided("Johns Hopkins University is divided into nine schools, five of which serve undergraduates. The Homewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for undergraduates. Freshmen and sophomores are required to live on campus. More than 1,300 students participate in the Greek community. Hopkins also has additional campuses for its School of Advanced International Studies in Washington, D.C.; Bologna, Italy; and Nanjing, China. Hopkins’ graduate programs include the top-ranked Bloomberg School of Public Health and the highly ranked School of Education, Whiting School of Engineering, School of Medicine and the well-regarded Peabody Institute for music and dance. Johns Hopkins Hospital is a top-ranked hospital with highly ranked specialties.", 4);

    EXPECT_EQ(filter->queryStrided("The Homewood Campus, one of the university’s four campuses in and around Baltimore, is the primary campus for undergraduates.", 4), 3);
    EXPECT_EQ(filter->getChain(), "b   c   d   e   f   g   h   i   j   k   l   m   ");

    delete filter;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
