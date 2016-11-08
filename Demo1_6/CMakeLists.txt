cmake_minimum_required(VERSION 3.4)
project(Demo1_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp call.cpp call1.cpp class_temp.h class_temp_2.h)
add_executable(Demo1_6 ${SOURCE_FILES})