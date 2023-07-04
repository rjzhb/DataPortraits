cmake_minimum_required(VERSION 3.16)
project(CppModelProject)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# 添加 gtest 头文件所在路径
include_directories(${PROJECT_SOURCE_DIR}/third_party/gtest/include)


add_subdirectory(src)
add_subdirectory(Test)
# 添加可执行文件CppModelProject，并链接相应的库
add_executable(CppModelProject main.cpp src/MyClass/MyClass.h src/MyClass/MyClass.cpp src/MultipleManager/MultipleManager.cpp src/MultipleManager/MultipleManager.h)


