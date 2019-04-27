cmake_minimum_required(VERSION 3.13)
project(exc)

set(CMAKE_CXX_STANDARD 17)

add_executable(exc src/main.cpp src/Iterator.cpp src/Iterator.h src/Queue.cpp src/Queue.h)