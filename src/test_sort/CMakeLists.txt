CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(test_sort CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_FXX_FLAGS} -g -std=c++11")

add_executable(test_sort main.cc )
