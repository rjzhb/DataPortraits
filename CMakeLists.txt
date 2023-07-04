cmake_minimum_required(VERSION 3.16)
project(DataPortraits)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# 添加 gtest 头文件所在路径
include_directories(${PROJECT_SOURCE_DIR}/third_party/gtest/include)

add_subdirectory(src)
add_subdirectory(test)
# 添加可执行文件DataPortraits，并链接相应的库
add_executable(DataPortraits main.cpp src/MyClass/MyClass.h src/MyClass/MyClass.cpp src/MultipleManager/MultipleManager.cpp src/MultipleManager/MultipleManager.h)


