cmake_minimum_required(VERSION 3.20)
project(3DMaze)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(3DMaze
        Lab073DMaze.cpp
        Maze.h
        MazeInterface.h)
