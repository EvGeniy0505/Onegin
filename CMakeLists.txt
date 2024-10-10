cmake_minimum_required(VERSION 3.5)
project(FILE_READ CXX)

set(FILE_READ_LIB "read_from_file.cpp")
set(FILE_READ_TEST "main.cpp" "sort.cpp")

add_library(file_read STATIC ${FILE_READ_LIB})

add_executable(test_file_read ${FILE_READ_TEST})
target_link_libraries(test_file_read file_read)
