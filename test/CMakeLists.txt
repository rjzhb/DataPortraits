# 添加测试
add_executable(test_MyClass Test.cpp)
add_executable(testMultiple MultipleTest.cpp)

# 链接库和依赖
set(MY_LIBS DataPortraits_lib gtest)

target_link_libraries(test_MyClass PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(testMultiple PRIVATE ${MY_LIBS} ${GTEST_BOTH_LIBRARIES} pthread)

# 添加测试
add_test(NAME test_MyClass COMMAND test_MyClass)
add_test(NAME testMultiple COMMAND testMultiple)
