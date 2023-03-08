cmake_minimum_required(VERSION 3.16)
project(file_library)

file(GLOB SOURCES *.cpp)

add_library(file-mng ${SOURCES})
set_target_properties(file-mng PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
target_include_directories(file-mng INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
