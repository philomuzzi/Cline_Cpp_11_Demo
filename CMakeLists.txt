cmake_minimum_required(VERSION 3.3)
project(Cline_Cpp_11_Demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Cline_Cpp_11_Demo ${SOURCE_FILES})