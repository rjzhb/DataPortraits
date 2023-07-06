//
// Created by 86183 on 2023/7/4.
//

#include "bloom_filter.h"
#include <functional>

BloomFilter::BloomFilter(size_t size, size_t hash_function_amount)
        : size_(size), hash_function_amount_(hash_function_amount) {
    filter_.resize(size);
}

BloomFilter::~BloomFilter() = default;

BloomFilter::BloomFilter(BloomFilter &&other) noexcept {
    *this = std::move(other);
}

auto BloomFilter::operator=(BloomFilter &&other) noexcept -> BloomFilter & {
    if (this != &other) {
        filter_ = std::move(other.filter_);
        size_ = other.size_;
        hash_function_amount_ = other.hash_function_amount_;
        other.filter_.clear();
        other.size_ = 0;
        other.hash_function_amount_ = 0;
    }
    return *this;
}

auto BloomFilter::insert(const std::string &value) -> void {
    for (size_t i = 0; i < hash_function_amount_; ++i) {
        size_t hash = std::hash<std::string>{}(value + std::to_string(i)) % size_;
        filter_[hash] = 1;
    }
}

auto BloomFilter::contains(const std::string &value) const -> bool {
    for (size_t i = 0; i < hash_function_amount_; ++i) {
        size_t hash = std::hash<std::string>{}(value + std::to_string(i)) % size_;
        if (!filter_[hash]) {
            return false;
        }
    }
    return true;
}

auto BloomFilter::setFilter(std::vector<char> &filter) -> void {
    filter_ = filter;
}
