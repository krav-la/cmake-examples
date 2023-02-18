cmake_minimum_required(VERSION 3.10)
project(common)

set(SOURCES
    MyLogger.cpp
)
add_library(common OBJECT ${SOURCES})
target_include_directories(common PUBLIC ${CMAKE_SOURCE_DIR}/common)
