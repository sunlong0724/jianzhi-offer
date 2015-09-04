CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(jianzhi_offer CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_FXX_FLAGS} -std=c++11")

add_executable(strToInt  src/strToInt.cc )
add_executable(findNumberInArrs  src/findNumberInArrs.cc )
add_executable(replaceBackspace  src/replaceBackspace.cc )

