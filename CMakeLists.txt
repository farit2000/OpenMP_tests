cmake_minimum_required(VERSION 3.17)
project(openMP_test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")


set(CMAKE_CXX_STANDARD 20)

add_executable(openMP_test main.cpp)