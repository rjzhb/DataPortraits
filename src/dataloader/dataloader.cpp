//
// Created by 86183 on 2023/7/5.
//

#include "dataloader.h"
#include "define.h"

DataLoader::DataLoader(const std::string &filename, size_t block_size) :
        input_stream_(filename, std::ios::binary),
        block_size_(block_size),
        output_stream_(filename + ".out", std::ios::binary),
        buffer_(block_size),
        buffer_size_(0),
        current_pos_(0) {
    filter_.resize(SIZE);
    // Check if the file is opened successfully
    if (!input_stream_.is_open()) {
        throw std::runtime_error("Unable to open file " + filename);
    }
    if (!output_stream_.is_open()) {
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


void DataLoader::processBlock(std::vector<char> &block, size_t stride, size_t tile_size) {
    // 将 block 这个字符串，每 strided * tile_size 个字符串
    for (size_t i = 0; i < block.size(); i += stride * tile_size) {
        if (i + stride * tile_size > block.size()) {
            break;
        }

        std::vector<char> value;
        if (i + stride * tile_size < block.size()) {
            value = std::vector<char>(block.begin() + i, block.begin() + i + stride * tile_size);
        } else {
            value = std::vector<char>(block.begin() + i, block.end());
        }

        for (size_t j = 0; j < HASH_FUNCTION_AMOUNT; ++j) {
            std::string str(value.begin(), value.begin() + value.size());
            size_t hash_value = std::hash<std::string>{}(str + std::to_string(j));
            size_t index = hash_value % SIZE;
            filter_[index] = true;
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
