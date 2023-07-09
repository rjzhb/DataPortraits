//
// Created by 86183 on 2023/7/4.
//

#ifndef STRIDEDBLOOMFILTER_H
#define STRIDEDBLOOMFILTER_H


#include "bloom_filter.h"

class StridedBloomFilter : public BloomFilter {
public:
    StridedBloomFilter(size_t size, size_t hash_function_amount, size_t tile_size)
            : BloomFilter(size, hash_function_amount), tile_size_(tile_size) {}

    ~StridedBloomFilter();

    StridedBloomFilter(StridedBloomFilter &&other) noexcept;

    auto operator=(StridedBloomFilter &&other) noexcept -> StridedBloomFilter &;

    //gain the result of last query
    auto getChain() const -> std::vector<std::string>;

    auto getLongestChain() const -> std::vector<std::string>;

    auto insertStrided(std::string &value, size_t stride) -> void;

    auto queryStrided(std::string value, size_t stride) const -> int;

private:
    mutable std::vector<std::string> chain_list_;
    //size of tile
    size_t tile_size_{};
    mutable std::string temp_str_;
};


#endif //STRIDEDBLOOMFILTER_H
