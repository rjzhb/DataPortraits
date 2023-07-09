//
// Created by 86183 on 2023/7/5.
//

#include <spdlog/spdlog.h>
#include "dataloader.h"

DataLoader::DataLoader(const std::string &filename, size_t block_size, size_t filter_size, size_t stride,
                       size_t tile_size) :
        input_stream_(filename, std::ios::binary),
        stride_(stride),
        filter_size_(filter_size),
        tile_size_(tile_size),
        block_size_(block_size),
        output_stream_(filename + ".out", std::ios::binary),
        buffer_(block_size),
        buffer_size_(0),
        current_pos_(0) {

    filter_.resize(filter_size_);

    // Check if the file is opened successfully
    if (!input_stream_.is_open()) {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        throw std::runtime_error("Unable to open file " + filename);
    }
    if (!output_stream_.is_open()) {
        std::cerr << "Error: Failed to open output file " << filename << ".out" << std::endl;
        throw std::runtime_error("Unable to open output file " + filename + ".out");
    }

    // Read the first block
    readBuffer(0);
}

DataLoader::~DataLoader() {
    input_stream_.close();
    output_stream_.close();
}

bool DataLoader::hasNextBlock() const {
    return current_pos_ < buffer_size_ || !input_stream_.eof();
}

std::vector<char> DataLoader::getNextBlock() {
    std::vector<char> block;
    size_t block_size = std::min(buffer_size_ - current_pos_, block_size_);

    // If there is enough data in the buffer, return it
    if (block_size > 0) {
        block = std::vector<char>(buffer_.begin() + current_pos_,
                                  buffer_.begin() + current_pos_ + block_size);
        current_pos_ += block_size;
    }
        // If the buffer is empty, return an empty block
    else if (input_stream_.eof()) {
        return block;
    }
        // Otherwise, read the next block from the file
    else {
        readBuffer(current_pos_);
        block = getNextBlock();
    }

    return block;
}


void DataLoader::processBlock(std::vector<char> &block) {
    for (size_t i = 0; i < block.size(); i += stride_ * tile_size_) {
        if (i + stride_ * tile_size_ > block.size()) {
            break;
        }

        std::vector<char> value;
        if (i + stride_ * tile_size_ < block.size()) {
            value = std::vector<char>(block.begin() + i, block.begin() + i + stride_ * tile_size_);
        } else {
            spdlog::info("Block allocation is uneven.");
            value = std::vector<char>(block.begin() + i, block.end());
        }

        for (size_t j = 0; j < HASH_FUNCTION_AMOUNT; ++j) {
            std::string str(value.begin(), value.begin() + value.size());
            size_t hash = std::hash<std::string>{}(str + std::to_string(j)) % filter_size_;
            filter_[hash] = 1;
        }
    }
}

void DataLoader::readBuffer(size_t start_pos) {
    input_stream_.seekg(start_pos);
    input_stream_.read(buffer_.data(), block_size_);
    buffer_size_ = input_stream_.gcount();
    current_pos_ = 0;
}


void DataLoader::writeFilterToFile(const std::string &filename) {
    // Open the output file stream
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);
    if (!outfile.is_open()) {
        throw std::runtime_error("Failed to open output file");
    }

    // Write the filter to the file
    outfile.write(filter_.data(), filter_.size());

    // Close the output file stream
    outfile.close();
}

std::vector<char> DataLoader::readFileToVector(const std::string &filename) {
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

    return buffer;
}

auto DataLoader::getFilter() const -> std::vector<char> {
    return filter_;
}

auto DataLoader::getCurrentPos() const -> size_t {
    return current_pos_;
}
