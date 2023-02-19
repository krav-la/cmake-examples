cmake_minimum_required(VERSION 3.18)
project(qt-examples)

set(BINARY_NAME example CACHE STRING "Example binary name")
set(EXAMPLE qml-example CACHE STRING "Example Type")
set_property(CACHE EXAMPLE PROPERTY STRINGS
             "qml-example" "qt-gui-example")

if (EXAMPLE STREQUAL "qml-example")
    add_subdirectory(qml-example)
else()
    add_subdirectory(qt-gui-example)
endif()