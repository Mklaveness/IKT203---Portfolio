cmake_minimum_required(VERSION 4.3)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        TMovie/TMovie.h
        TMovie/TMovie.cpp
        TMovieNode/TMovieNode.h
        TMovieNode/TMovieNode.cpp
        TMovieList/TMovieList.cpp
        TMovieList/TMovieList.h
        FCheckMovie.h
        FCheckMovie.h)
