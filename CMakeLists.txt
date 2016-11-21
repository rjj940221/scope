cmake_minimum_required(VERSION 3.6)
project(scope)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test.c readobj.c scope.h.h)
add_executable(scope ${SOURCE_FILES})