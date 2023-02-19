cmake_minimum_required(VERSION 3.16)
project(qt-gui-example)

set(BINARY_NAME gui_example)
file(GLOB SOURCES  *.cpp)
message("-- Found sources: ${SOURCES}")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_AUTOMOC ON)
qt_add_executable(${BINARY_NAME} ${SOURCES})

set_target_properties(${BINARY_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(${BINARY_NAME} PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

set_target_properties(${BINARY_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
