cmake_minimum_required(VERSION 3.10)
project(hello_algo CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include)

add_subdirectory(chapter_computational_complexity)
add_subdirectory(chapter_array_and_linkedlist)
add_subdirectory(chapter_stack_and_queue)
add_subdirectory(chapter_hashing)
add_subdirectory(chapter_tree)
add_subdirectory(chapter_heap)