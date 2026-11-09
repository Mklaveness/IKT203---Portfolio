cmake_minimum_required(VERSION 4.3)
project(StacksAndQues)

set(CMAKE_CXX_STANDARD 20)

add_executable(StacksAndQues main.cpp
        Part1/TStack.cpp
        Part1/TStack.h
        Part1/TQueue.cpp
        Part1/TQueue.h
        Part2/StringReversal.h
        Part2/StringReversal.cpp
        Part2/Factorial.h
        Part2/Factorial.cpp
        Part2/WaitLine.h
        Part2/WaitLine.cpp
        Part3/TwoDimensionalGrid.cpp
        Part3/TwoDimensionalGrid.h
        Part3/GridDFS.cpp
        Part3/GridDFS.h
        Part3/GridBFS.cpp
        Part3/GridBFS.h)
