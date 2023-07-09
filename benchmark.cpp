#include <fstream>
#include <iostream>
#include <string>


int main() {
    std::string filename = "../dataset/ag_news_csv/train.txt";
    std::ifstream input_stream_(filename, std::ios::binary);
    if(!input_stream_.is_open()){
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        throw std::runtime_error("Unable to open file " + filename);
    }
    // Read the file contents into a string
    std::string file_contents;
    std::string line;
    while (std::getline(input_stream_, line)) {
        file_contents += line + '\n';
    }

    // Close the input file
    input_stream_.close();
    // Do something with the file contents
    std::cout << "File contents: " << file_contents << std::endl;

    return 0;
}
