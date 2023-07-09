//
// Created by 86183 on 2023/7/9.
//
#include "gtest/gtest.h"
#include "string_util.h"

// Test calculate index distance
TEST(StringUtilTest, TestIndexDistance) {
    std::string s1 = "abcd";
    std::string s2 = "cdef";
    std::string s3 = "efgh";
    std::string s4 = "chjk";
    std::string s5 = "c";

    std::string k1 = "";
    std::string k2 = "ab";

    std::string a1 = "abc";
    std::string a2 = "";

    EXPECT_EQ(calculateIndexDistance(s1, s2), 2);
    EXPECT_EQ(calculateIndexDistance(s1, s3), 4);
    EXPECT_EQ(calculateIndexDistance(s1, s4), 4);
    EXPECT_EQ(calculateIndexDistance(k1, k2), 0);
    EXPECT_EQ(calculateIndexDistance(a1, a2), 3);


}