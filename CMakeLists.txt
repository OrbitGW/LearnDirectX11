cmake_minimum_required(VERSION 3.15)

project(LearnDX11 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_PATH)

file(GLOB SRC_PATH ./sources/01/*.cpp ./sources/01/*.h)
add_executable(Tut01 WIN32 ${SRC_PATH})

file(GLOB SRC_PATH ./sources/02/*.cpp ./sources/02/*.h)
add_executable(Tut02 WIN32 ${SRC_PATH})