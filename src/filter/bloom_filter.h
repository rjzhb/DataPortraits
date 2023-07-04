//
// Created by 86183 on 2023/7/4.
//

#ifndef DATAPORTRAITS_BLOOMFILTER_H
#define DATAPORTRAITS_BLOOMFILTER_H


#include <bitset>
#include <iostream>
#include <vector>
#include <string>
#include <functional>


#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <string>

class BloomFilter {
public:
    BloomFilter(size_t size, size_t hashFunctionsAmount);

    ~BloomFilter();

    BloomFilter(BloomFilter &&other) noexcept;

    auto operator=(BloomFilter &&other) noexcept -> BloomFilter&;

    auto insert(const std::string &value) -> void;

    auto contains(const std::string &value) const -> bool;

private:
    std::vector<bool> filter_;
    size_t size_{};
    size_t hashFunctionsAmount_{};
};

#endif /* BLOOMFILTER_H */


#endif //DATAPORTRAITS_BLOOMFILTER_H
