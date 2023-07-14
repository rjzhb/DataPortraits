//
// Created by 86183 on 2023/7/9.
//

#ifndef DATAPORTRAITS_STRING_UTIL_H
#define DATAPORTRAITS_STRING_UTIL_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

template<typename T>
struct ConfigReader {
};

template<>
struct ConfigReader<std::string> {
    static std::string read(const std::string &key, std::ifstream &config_file) {
        std::string value;
        std::string line;
        while (std::getline(config_file, line)) {
            std::string file_key;
            std::istringstream iss(line);
            iss >> file_key;

            if (file_key == key) {
                iss >> value;
                break;
            }
        }

        return value;
    }
};

template<>
struct ConfigReader<size_t> {
    static size_t read(const std::string &key, std::ifstream &config_file) {
        size_t value = 0;
        std::string line;
        while (std::getline(config_file, line)) {
            std::string file_key;
            std::istringstream iss(line);
            iss >> file_key;

            if (file_key == key) {
                iss >> value;
                break;
            }
        }

        return value;
    }
};


auto calculateIndexDistance(const std::string &str1, const std::string &str2) -> int;


#endif //DATAPORTRAITS_STRING_UTIL_H
