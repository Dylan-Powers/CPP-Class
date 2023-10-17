cmake_minimum_required(VERSION 3.26)
project(robots)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(robots
        src/cell.cpp
        src/cell.h
        src/main.cpp
        src/map.cpp
        src/map.h
        src/robot.cpp
        src/robot.h)
