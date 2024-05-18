cmake_minimum_required(VERSION 3.28)
project(Final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Final
        A2.cpp
        BinarySearchTree.cpp
        HeapTree.cpp
        Item.cpp
        Item.h
        items.txt
        Trees.h)
