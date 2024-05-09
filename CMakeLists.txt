cmake_minimum_required(VERSION 3.28)
project(Assignment_2_datastructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Assignment_2_datastructure
        .idea/.gitignore
        .idea/Assignment-2-datastructure.iml
        .idea/material_theme_project_new.xml
        .idea/modules.xml
        .idea/vcs.xml
        main.cpp
        Item.h
        Trees.h)
