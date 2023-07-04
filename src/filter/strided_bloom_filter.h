//
// Created by 86183 on 2023/7/4.
//

#ifndef DATAPORTRAITS_STRIDEDBLOOMFILTER_H
#define DATAPORTRAITS_STRIDEDBLOOMFILTER_H


#include "bloom_filter.h"

class StridedBloomFilter : public BloomFilter {
public:
    StridedBloomFilter(size_t size, size_t hashFunctionsAmount, size_t stride)
            : BloomFilter(size, hashFunctionsAmount), stride_(stride) {}

    ~StridedBloomFilter();

    StridedBloomFilter(StridedBloomFilter &&other) noexcept;

    auto operator=(StridedBloomFilter &&other) noexcept -> StridedBloomFilter &;

    auto insertStrided(const std::string &value, size_t n) -> void;

    auto queryStrided(const std::string &value, size_t n) const -> int;

private:
    size_t stride_;
};


#endif //DATAPORTRAITS_STRIDEDBLOOMFILTER_H