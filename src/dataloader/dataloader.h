//
// Created by 86183 on 2023/7/5.
//

#ifndef DATAPORTRAITS_DATALOADER_H
#define DATAPORTRAITS_DATALOADER_H

#include <fstream>
#include <iostream>
#include <vector>
#include "define.h"

class DataLoader {
public:
    DataLoader(const std::string &filename, size_t block_size, size_t stride,
               size_t tile_size_);

    ~DataLoader();

    auto hasNextBlock() const -> bool;

    auto getNextBlock() -> std::vector<char>;

    auto processBlock(std::vector<char> &block) -> void;

    auto writeFilterToFile(const std::string &filename) -> void;

    static auto readFileToVector(const std::string &filename) -> std::vector<char>;

    auto getFilter() const -> std::vector<char>;

    auto getCurrentPos() const -> size_t;

private:
    std::ifstream input_stream_;
    std::ofstream output_stream_;
    size_t block_size_;
    std::vector<char> buffer_;
    size_t buffer_size_;
    size_t current_pos_;
    std::vector<char> filter_;

    size_t stride_{};
    size_t tile_size_{};

    void readBuffer(size_t start_pos);
};

#endif //DATAPORTRAITS_DATALOADER_H
