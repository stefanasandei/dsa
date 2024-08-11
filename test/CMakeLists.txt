cmake_minimum_required(VERSION 3.28)
project(dsa_tests)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

add_executable(dsa_tests base.cpp)

target_link_libraries(dsa_tests external lib)
target_include_directories(dsa_tests PRIVATE ../lib)

include(GoogleTest)
gtest_discover_tests(dsa_tests)
