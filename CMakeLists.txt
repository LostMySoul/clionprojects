cmake_minimum_required(VERSION 3.13)
project(exc)

set(CMAKE_CXX_STANDARD 17)

add_executable(exc src/Main.cpp src/LinkedHashTable.cpp src/LinkedHashTable.h)