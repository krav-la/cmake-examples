cmake_minimum_required(VERSION 3.16)
project(example)

set(FILE_LIB_NAME file_lib)

add_subdirectory(file-manager)

add_executable(myapp main.cpp)
target_link_libraries(myapp file-mng)

set_target_properties(myapp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)