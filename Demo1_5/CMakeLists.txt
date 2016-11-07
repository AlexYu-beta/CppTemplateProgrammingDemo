cmake_minimum_required(VERSION 3.4)
project(Demo1_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stack.h count_stack.h hetero_stack.h)
add_executable(Demo1_5 ${SOURCE_FILES})