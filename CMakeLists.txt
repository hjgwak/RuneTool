cmake_minimum_required(VERSION 3.5)
project(RuneTool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Rune.cpp src/Rune.h src/RuneIO.cpp src/RuneIO.h src/Error.h src/Error.cpp src/programs.h src/programs.cpp)
add_executable(RuneTool ${SOURCE_FILES})