cmake_minimum_required(VERSION 3.24)

set(project "Archiver")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        Archiver.cpp UI.cpp)

set(${project}_HEADERS
        Archiver.h UI.h)

add_subdirectory(HuffmanTree)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} HuffmanTree)
