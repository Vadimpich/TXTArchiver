cmake_minimum_required(VERSION 3.24)

set(project "HuffmanTree")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        HuffmanTree.cpp)

set(${project}_HEADERS
        HuffmanTree.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})