cmake_minimum_required(VERSION 3.4)
project(Demo1_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp caller1.cpp caller2.cpp)
add_executable(Demo1_4 ${SOURCE_FILES})