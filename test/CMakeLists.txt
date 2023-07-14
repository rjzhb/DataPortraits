# Define test executables and link libraries
set(TESTS
        bloom_filter_test
        strided_bloom_filter_test
        dataloader_test
        string_util_test
        dataset_test
        )

foreach(TEST ${TESTS})
    add_executable(${TEST} ${TEST}.cpp)
    target_link_libraries(${TEST} PRIVATE DataPortraits_lib gtest gtest_main pthread)
    add_test(NAME ${TEST} COMMAND ${TEST})
endforeach()