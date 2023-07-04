//
// Created by 86183 on 2023/7/4.
//

#include "strided_bloom_filter.h"
#include <spdlog/spdlog.h>

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

auto StridedBloomFilter::insertStrided(const std::string &value) -> void {
    for (size_t i = 0; i < value.size(); i += stride_) {
        if (i + stride_ > value.size()) {
            break;
        }
        insert(value.substr(i, stride_));
    }
}

auto StridedBloomFilter::queryStrided(const std::string &value) const -> int {
    int matches = 0;
    for (size_t i = 0; i < value.size() - stride_ + 1; ++i) {
        spdlog::info("string {} is being queried", value.substr(i, stride_));
        if (contains(value.substr(i, stride_))) {
            ++matches;
        }
    }
    return matches;
}
