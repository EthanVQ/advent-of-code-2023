cmake_minimum_required(VERSION 3.26)
project(advent_of_code_2023)

set(CMAKE_CXX_STANDARD 17)

add_executable(advent_of_code_2023 main.cpp
        src/day1/day1.cpp
        src/day1/day1.h
        src/day5/day5.cpp
        src/day5/day5.h
        src/day2/day2.cpp
        src/day2/day2.h
        src/tools.cpp
        src/tools.h
)
