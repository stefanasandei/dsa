cmake_minimum_required(VERSION 3.28)
project(lib)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE DSA_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE DSA_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

add_library(lib STATIC ${DSA_HEADERS} ${DSA_SOURCES})

include_directories(.)
