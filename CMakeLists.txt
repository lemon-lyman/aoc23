cmake_minimum_required(VERSION 3.10)
project(AdventOfCode2023)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(DAY "" CACHE STRING "Build specific day")

# Include common files
add_library(common_lib utils.cpp)

# Link days
if (DAY)
    add_subdirectory("day${DAY}")
else()
    add_subdirectory(day01)
    add_subdirectory(day02)
    add_subdirectory(day03)
endif()

