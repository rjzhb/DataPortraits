//
// Created by 86183 on 2023/7/9.
//
#include "gtest/gtest.h"
#include "string_util.h"

// Test calculate index distance
TEST(StringUtilTest, TestIndexDistance) {
    const std::string s1 = "abcd";
    const std::string s2 = "cdef";
    const std::string s3 = "efgh";
    const std::string s4 = "chjk";
    const std::string s5 = "c";

    EXPECT_EQ(calculateIndexDistance(s1, s2), 2);
    EXPECT_EQ(calculateIndexDistance(s1, s3), 4);
    EXPECT_EQ(calculateIndexDistance(s1, s4), 4);
}

TEST(StringUtilTest, TestIndexDistance2) {
    const std::string k1 = "";
    const std::string k2 = "ab";

    const std::string a1 = "abc";
    const std::string a2 = "";
    EXPECT_EQ(calculateIndexDistance(k1, k2), 0);
    EXPECT_EQ(calculateIndexDistance(a1, a2), 3);
}

TEST(StringUtilTest, TestIndexDistance3) {
    const std::string s1 = "hel";
    const std::string s2 = "ell";
    const std::string s3 = "llo";

    EXPECT_EQ(calculateIndexDistance(s1, s2), 1);
    EXPECT_EQ(calculateIndexDistance(s1, s3), 2);
}

TEST(StringUtilTest, TestSimpleChar2String) {
    const std::vector<char> block{'a', 'b', '\0', ' ', '4', '5'};
    const std::vector<char> value = std::vector<char>(block.begin(), block.end());
    const std::string str(value.begin(), value.begin() + value.size());

    std::cout << block.data() << std::endl;
    std::cout << str << std::endl;
}