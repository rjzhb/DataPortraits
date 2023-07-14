//
// Created by 86183 on 2023/7/9.
//
#include <iostream>
#include <vector>

auto calculateIndexDistance(const std::string &str1, const std::string &str2) -> int {
    if (str1.empty()) {
        return 0;
    }

    if (str2.empty()) {
        return str1.size();
    }

    bool flag = false;

    int right, left;
    std::vector<int> pos_vec;

    for (right = str2.size() - 1; right >= 0; right--) {
        if (str2[right] == str1[str1.size() - 1]) {
            flag = true;
            pos_vec.push_back(right);
        }
    }

    if (!flag) {
        return str1.size();
    }

    int distance_res = str1.size();

    for (left = 0; left < str1.size(); left++) {
        if (str1[left] == str2[0]) {
            for (auto r: pos_vec) {
                if (str1.substr(left, str1.size() - left) == str2.substr(0, r + 1)) {
                    distance_res = std::min(distance_res, left);
                }
            }
        }
    }

    return distance_res;
}

