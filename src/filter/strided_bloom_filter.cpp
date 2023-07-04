//
// Created by 86183 on 2023/7/4.
//

#include "strided_bloom_filter.h"

StridedBloomFilter::~StridedBloomFilter() = default;

StridedBloomFilter::StridedBloomFilter(StridedBloomFilter &&other) noexcept
        : BloomFilter(std::move(other)), stride_(other.stride_) {
    other.stride_ = 0;
}

auto StridedBloomFilter::operator=(StridedBloomFilter &&other) noexcept -> StridedBloomFilter & {
    if (this != &other) {
        BloomFilter::operator=(std::move(other));
        stride_ = other.stride_;
        other.stride_ = 0;
    }
    return *this;
}

auto StridedBloomFilter::insertStrided(const std::string &value, size_t n) -> void {
    for (size_t i = 0; i < value.size(); i += stride_) {
        if (i + n > value.size()) {
            break;
        }
        insert(value.substr(i, n));
    }
}

auto StridedBloomFilter::queryStrided(const std::string &value, size_t n) const -> int {
    int matches = 0;
    for (size_t i = 0; i < value.size() - n + 1; ++i) {
        if (contains(value.substr(i, n))) {
            ++matches;
        }
    }
    return matches;
}
