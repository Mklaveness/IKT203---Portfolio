cmake_minimum_required(VERSION 4.3)
project(Fundamental_Recursion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fundamental_Recursion main.cpp
        "Part 1/basic_recursion.h"
        "Part 1/basic_recursion.cpp"
        "Part 2/binary_recursion.h"
        "Part 2/binary_recursion.cpp"
        "Part 3/advanced_recursion.h"
        "Part 3/advanced_recursion.cpp")
