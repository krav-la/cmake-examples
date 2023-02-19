cmake_minimum_required(VERSION 3.18)
project(qml-example VERSION 1.0 LANGUAGES CXX)

set(BINARY_NAME qml_example)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)

qt_add_executable(${BINARY_NAME}
    main.cpp
)

target_link_libraries(${BINARY_NAME} PRIVATE Qt6::Gui Qt6::Quick)

qt_add_qml_module(${BINARY_NAME}
    URI qml
    VERSION 2.0
    QML_FILES main.qml
)

set_target_properties(${BINARY_NAME} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/
)