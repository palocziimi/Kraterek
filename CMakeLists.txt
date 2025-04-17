cmake_minimum_required(VERSION 3.31)
project(Kraterek)

set(CMAKE_CXX_STANDARD 26)

add_executable(Kraterek main.cpp
        Krater.h
        Krater.cpp
        KraterKezelo.cpp
        KraterKezelo.h)