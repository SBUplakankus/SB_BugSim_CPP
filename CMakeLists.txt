cmake_minimum_required(VERSION 3.30)
project(SB_BugSim_CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(SB_BugSim_CPP main.cpp
        Bugs/Bug.cpp
        Bugs/Bug.h
        Board/GameBoard.cpp
        Board/GameBoard.h
        Bugs/Crawler.cpp
        Bugs/Crawler.h
        Bugs/Hopper.cpp
        Bugs/Hopper.h
        Board/CsvParser.cpp
        Board/CsvParser.h
        Graphics/BoardDisplay.cpp
        Graphics/BoardDisplay.h)
