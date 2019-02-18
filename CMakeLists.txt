cmake_minimum_required(VERSION 3.13)
project(exc0)

set(CMAKE_CXX_STANDARD 17)

add_executable(exc0 src/main.cpp src/container/Container.cpp src/container/Container.h src/box/Box.cpp src/exception/ContainerException.cpp src/box/Box.cpp src/box/Box.h)