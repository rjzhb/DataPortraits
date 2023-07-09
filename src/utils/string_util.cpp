//
// Created by 86183 on 2023/7/9.
//
#include <iostream>

int calculateIndexDistance(const std::string &str1, const std::string &str2) {
    if (str1.empty()) {
        return 0;
    }

    if (str2.empty()) {
        return str1.size();
    }

    int distance = 0;
    bool flag = false;

    int right = str2.size() - 1;
    int left = 0;

    for (right = str2.size() - 1; right >= 0; right--) {
        if (str2[right] == str1[str1.size() - 1]) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        return str1.size();
    }


    for (left = 0; left < str1.size(); left++) {
        if (str1[left] == str2[0]) {
            if (str1.substr(left, str1.size() - left) == str2.substr(0, right + 1)) {
                return left;
            } else {
                return str1.size();
            }
        }
    }

    return str1.size();
}

bool isDistanceN(const std::string &str1, const std::string &str2, size_t n) {
    if (str1.size() != str2.size()) {
        return false;
    }
    size_t distance = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            ++distance;
            if (distance > n) {
                return false;
            }
        }
    }
    return distance == n;
}

int countOverlap(const std::string &str1, const std::string &str2, size_t n) {
    if (str1.size() != str2.size() || n == 0) {
        return 0;
    }
    int overlap = 0;
    for (size_t i = 0; i < str1.size() - n; ++i) {
        if (isDistanceN(str1.substr(i, n), str2.substr(i + n, n), n - 1)) {
            overlap++;
        }
    }
    return overlap;
}