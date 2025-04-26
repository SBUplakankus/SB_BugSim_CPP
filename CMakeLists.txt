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


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.2/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network REQUIRED)

include_directories(C:/SFML-2.6.2/include)
target_link_libraries(SB_BugSim_CPP sfml-system sfml-window sfml-graphics)
