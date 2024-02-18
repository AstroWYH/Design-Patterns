cmake_minimum_required(VERSION 3.10)
project(01)

set(MAIN_DIR ${CMAKE_SOURCE_DIR})

set(SRC_LIST
    ${MAIN_DIR}/main.cpp
    ${MAIN_DIR}/Fighter.cpp
    ${MAIN_DIR}/Warrior.cpp
    ${MAIN_DIR}/Mage.cpp)

add_executable(main ${SRC_LIST})