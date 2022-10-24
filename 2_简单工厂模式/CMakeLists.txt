cmake_minimum_required(VERSION 3.10)
project(02)

set(MAIN_DIR ${CMAKE_SOURCE_DIR})

set(SRC_LIST
    ${MAIN_DIR}/main.cpp)

add_executable(main ${SRC_LIST})