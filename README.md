# DataPortraits [![CMake](https://github.com/intellistream/ModernCPlusProjectTemplate/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/intellistream/ModernCPlusProjectTemplate/actions/workflows/cmake.yml)
Implementing the Paper: Data Portraits for Recording Foundation Model Training Data

## Requires Log4cxx
```shell
sudo apt-get install -y liblog4cxx-dev
```

## Code Structure
- benchmark -- application code to use the generated shared library
- cmake -- cmake configuration files
- docs -- any documents
- include -- all the header files
- src -- corresponding source files, will generate a shared library
- test -- test code based on google test

