cmake_minimum_required(VERSION 3.24)
project(external)

set(CMAKE_CXX_STANDARD 23)

add_library(external INTERFACE)

# google test
add_subdirectory(googletest)
target_link_libraries(external INTERFACE GTest::gtest_main)
target_include_directories(external INTERFACE googletest/googletest/include)
