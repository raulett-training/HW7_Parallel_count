cmake_minimum_required(VERSION 3.20)
project(parallel_count)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_SYSTEM_NAME Windows)
#SET(CMAKE_C_COMPILER gcc)
#SET(CMAKE_CXX_COMPILER g++)

add_executable(parallel_count main.cpp
        CountWords/count_words.cpp
        CountWords/print_topk.cpp
        MergeCounters.cpp
)

target_include_directories(parallel_count PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/CountWords
        ${CMAKE_CURRENT_SOURCE_DIR}/ParallelQueue
        ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(parallel_count PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(parallel_count PRIVATE
            /EHsc
            /W4
            /WX
    )
endif()