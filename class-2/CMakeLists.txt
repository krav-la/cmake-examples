cmake_minimum_required(VERSION 3.10)
project(hello_cmake)

set(BINARY_NAME hello)
set(SOURCES main.cpp)

set(BIN_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}/bin")

add_subdirectory(common)

add_executable(${BINARY_NAME} ${SOURCES})

target_link_libraries(${BINARY_NAME} common)
set_target_properties(${BINARY_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH}
)