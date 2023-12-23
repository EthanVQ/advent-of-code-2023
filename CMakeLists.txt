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
        src/day3/day3.cpp
        src/day3/day3.h
        src/day4/day4.cpp
        src/day4/day4.h
        src/day18/day18.cpp
        src/day18/day18.h
        src/day21/day21.cpp
        src/day21/day21.h
        src/day22/day22.cpp
        src/day22/day22.h
)
