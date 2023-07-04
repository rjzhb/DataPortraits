# DataPortraits [![CMake](https://github.com/intellistream/ModernCPlusProjectTemplate/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/intellistream/ModernCPlusProjectTemplate/actions/workflows/cmake.yml)
Implementing the Paper: Data Portraits for Recording Foundation Model Training Data
Paper: https://arxiv.org/abs/2303.03919

## Introduction

![image](https://github.com/rjzhb/DataPortraits/assets/105226542/5e4aa17a-9ad5-4fc6-b98d-4b3b0a2ccadb)

![image](https://github.com/rjzhb/DataPortraits/assets/105226542/c02dddab-827f-435b-87fd-c987f4180401)

## Requires spdlog, Google-test
```shell
sudo apt-get install libspdlog-dev.

sudo apt-get install libgtest-dev.
export CMAKE_PREFIX_PATH=/path/to/gtest:$CMAKE_PREFIX_PATH
```

## Code Structure
- benchmark -- application code to use the generated shared library
- cmake -- cmake configuration files
- docs -- any documents
- include -- all the header files
- src -- corresponding source files, will generate a shared library
- test -- test code based on google test

