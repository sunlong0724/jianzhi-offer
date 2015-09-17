CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(jianzhi_offer CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_FXX_FLAGS} -g -std=c++11")

add_executable(strToInt  src/strToInt.cc )
add_executable(findNumberInArrs  src/findNumberInArrs.cc )
add_executable(replaceBackspace  src/replaceBackspace.cc )
add_executable(list  src/list.cc )

include_directories(googletest/googletest/include)
add_executable(main src/main.cc)
target_link_libraries(main gtest)

add_executable(tree src/tree.cc)

add_subdirectory(googletest/googletest)
