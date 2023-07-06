//
// Created by 86183 on 2023/7/4.
//


#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <bitset>
#include <iostream>
#include <vector>
#include <string>
#include <functional>


class BloomFilter {
public:
    BloomFilter(size_t size, size_t hash_function_amount);

    ~BloomFilter();

    BloomFilter(BloomFilter &&other) noexcept;

    auto operator=(BloomFilter &&other) noexcept -> BloomFilter &;

    auto insert(const std::string &value) -> void;

    auto contains(const std::string &value) const -> bool;

    auto setFilter(std::vector<char> &filter) -> void;

private:
    std::vector<char> filter_;
    size_t size_{};
    size_t hash_function_amount_{};
};


#endif //BLOOMFILTER_H
