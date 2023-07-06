//
// Created by 86183 on 2023/7/4.
//

#include "strided_bloom_filter.h"
#include <spdlog/spdlog.h>

StridedBloomFilter::~StridedBloomFilter() = default;

StridedBloomFilter::StridedBloomFilter(StridedBloomFilter &&other) noexcept
        : BloomFilter(std::move(other)) {
}

auto StridedBloomFilter::operator=(StridedBloomFilter &&other) noexcept -> StridedBloomFilter & {
    if (this != &other) {
        BloomFilter::operator=(std::move(other));
    }
    return *this;
}

auto StridedBloomFilter::insertStrided(const std::string &value, size_t stride) -> void {
    for (size_t i = 0; i < value.size(); i += stride * tile_size_) {
        if (i + stride * tile_size_ > value.size()) {
            break;
        }
        insert(value.substr(i, stride * tile_size_));
    }
}

auto StridedBloomFilter::queryStrided(const std::string &value, size_t stride) const -> int {
    int matches = 0;
    std::string chain;
    spdlog::info("stride is {}, tile size is {}", stride, tile_size_);

    for (size_t i = 0; i < value.size() - stride * tile_size_ + 1; ++i) {
        std::string tile_str = value.substr(i, stride * tile_size_);
        spdlog::info("string {} is being queried", tile_str);

        if (contains(tile_str)) {
            ++matches;
            //chaining

        }
    }

    return matches;
}

auto StridedBloomFilter::getChain() const -> std::string {
    return chain_list_;
}
