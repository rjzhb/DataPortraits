//
// Created by 86183 on 2023/7/4.
//

#include "strided_bloom_filter.h"
#include <spdlog/spdlog.h>
#include "string_util.h"

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

auto StridedBloomFilter::insertStrided(std::string value, size_t stride) -> void {
    for (size_t i = 0; i < value.size(); i += stride * tile_size_) {
        if (i + stride * tile_size_ > value.size()) {
            break;
        }
        insert(value.substr(i, stride * tile_size_));
    }
}

auto StridedBloomFilter::queryStrided(std::string value, size_t stride) const -> int {
    int matches = 0;
    spdlog::info("stride is {}, tile size is {}", stride, tile_size_);

    if (value.size() < stride * tile_size_) {
        value.append(stride * tile_size_ - value.size(), ' ');
    }

    for (size_t i = 0; i < value.size() - stride * tile_size_ + 1; ++i) {
        std::string tile_str = value.substr(i, stride * tile_size_);
        spdlog::info("string [{}] is being queried, i = {}", tile_str, i);

        bool merge_chain = false;
        if (contains(tile_str)) {
            ++matches;
            //chaining
            merge_chain = calculateIndexDistance(temp_str_, tile_str) == temp_str_.size();
            if (merge_chain) {
                temp_str_.append(tile_str);
            } else {
                spdlog::info("find a chain: {}", temp_str_);
                if (!(!chain_list_.empty() && chain_list_.back() == temp_str_)) {
                    chain_list_.push_back(temp_str_);
                }
                temp_str_ = "";
            }
        }
        if (i == value.size() - stride * tile_size_) {
            std::cout << "get" << std::endl;
        }
        if (i == value.size() - stride * tile_size_ && temp_str_ != "") {
            spdlog::info("find a chain: {}", temp_str_);
            chain_list_.push_back(temp_str_);
        }
    }
    return matches;
}

auto StridedBloomFilter::getChain() const -> std::vector<std::string> {
    return chain_list_;
}


auto StridedBloomFilter::getLongestChain() const -> std::vector<std::string> {
    std::vector<std::string> longest_chains;
    auto max_length = std::max_element(chain_list_.begin(), chain_list_.end(),
                                       [](const std::string &s1, const std::string &s2) {
                                           return s1.length() < s2.length();
                                       })->length();

    for (const auto &s: chain_list_) {
        if (s.length() == max_length) {
            longest_chains.push_back(s);
        }
    }
    return chain_list_;
}
