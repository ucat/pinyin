cmake_minimum_required (VERSION 2.8)
project (ucat_pinyin)

set(CMAKE_C_COMPILER_INIT "/opt/compiler/gcc-4.8.2/bin/gcc")
set(CMAKE_CXX_COMPILER_INIT "/opt/compiler/gcc-4.8.2/bin/g++")
set(CMAKE_C_FLAGS "-O0 -ggdb -std=c99")
set(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11")

add_executable (test test.cc data/dict.cc)
