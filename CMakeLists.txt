cmake_minimum_required(VERSION 3.26)
project(parallel_count)

set(CMAKE_CXX_STANDARD 20)

add_executable(parallel_count main.cpp
        CountWords/count_words.cpp
        CountWords/count_words.h
        CountWords/Counter.h
        CountWords/print_topk.cpp
        CountWords/print_topk.h)

target_include_directories(parallel_count PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/CountWords)