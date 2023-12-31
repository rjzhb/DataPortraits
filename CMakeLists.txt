cmake_minimum_required(VERSION 3.16)
project(DataPortraits)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src/filter/)
include_directories(${PROJECT_SOURCE_DIR}/src/common/)
include_directories(${PROJECT_SOURCE_DIR}/src/dataloader/)
include_directories(${PROJECT_SOURCE_DIR}/src/utils/)
include_directories(${PROJECT_SOURCE_DIR}/third_party/gtest/include)
include_directories(${GTEST_INCLUDE_DIRS})


add_subdirectory(src)
add_subdirectory(test)

# executable
add_executable(
        DataPortraits benchmark.cpp
        src/filter/bloom_filter.h
        src/filter/bloom_filter.cpp
        src/filter/strided_bloom_filter.cpp
        src/filter/strided_bloom_filter.h
        src/common/define.h
        src/dataloader/dataloader.h
        src/dataloader/dataloader.cpp
        src/utils/string_util.cpp
        src/utils/string_util.h
        src/utils/task_queue.cpp
        src/utils/task_queue.h
        )

