cmake_minimum_required(VERSION 3.8)
project(HW_5_Baratheon)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES main.cpp classRomanNum.cpp classRomanNum.h)
set(SOURCE_FILES testRoman.cpp Roman.cpp Roman.h)
add_executable(HW_5_Baratheon ${SOURCE_FILES})