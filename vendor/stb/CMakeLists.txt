cmake_minimum_required(VERSION 3.1)
project(stb)

add_library(stb)
target_sources(stb PRIVATE src/stb_implementation.cpp)
target_include_directories(stb PUBLIC include)