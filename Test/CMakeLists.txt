cmake_minimum_required(VERSION 3.20)

project("Test")

file(GLOB_RECURSE SOURCE src/*.cpp)

enable_testing()

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
