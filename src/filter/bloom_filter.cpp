//
// Created by 86183 on 2023/7/4.
//

#include "bloom_filter.h"
#include <functional>
#include <fstream>

BloomFilter::BloomFilter(size_t size, size_t hash_function_amount)
        : size_(size), hash_function_amount_(hash_function_amount) {
    filter_.resize(size);
}

BloomFilter::~BloomFilter() = default;

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

auto BloomFilter::readBinFileToFilter(const std::string &filename) -> void {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::streamsize size = file.tellg();
    if (size < 0) {
        throw std::runtime_error("Failed to get file size");
    }

    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        throw std::runtime_error("Failed to read file");
    }

    filter_ = buffer;
}
