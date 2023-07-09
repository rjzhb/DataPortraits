# add test
add_executable(test_bloom_filter bloom_filter_test.cpp)
add_executable(test_strided_bloom_filter strided_bloom_filter_test.cpp)
add_executable(test_data_loader dataloader_test.cpp)
add_executable(test_string_util string_util_test.cpp)

# link
set(MY_LIBS DataPortraits_lib gtest)

target_link_libraries(test_bloom_filter PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test_strided_bloom_filter PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test_data_loader PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(test_string_util PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)

# add test
add_test(NAME test_bloom_filter COMMAND test_bloom_filter)
add_test(NAME test_strided_bloom_filter COMMAND test_strided_bloom_filter)
add_test(NAME test_data_loader COMMAND test_data_loader)
add_test(NAME test_string_util COMMAND test_string_util)