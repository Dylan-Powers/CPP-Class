cmake_minimum_required(VERSION 3.26)
project(SPA3)

set(CMAKE_CXX_STANDARD 17)

add_executable(SPA3 main.cpp
        date.cpp
        date.h
        appointments.cpp
        appointments.h)
