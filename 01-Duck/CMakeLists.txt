cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER "/d/mingw64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "/d/mingw64/bin/g++.exe")

# cmake -G “MinGW Makefiles” ..

project(DUCK)

include_directories(${CMAKE_SOURCE_DIR}/duck/)
include_directories(${CMAKE_SOURCE_DIR}/behavior/)

set(MAIN_DIR ${CMAKE_SOURCE_DIR})
set(DUCK_DIR ${CMAKE_SOURCE_DIR}/duck)
set(BEHAVIOR_DIR ${CMAKE_SOURCE_DIR}/behavior)

set(SRC_LIST
    ${MAIN_DIR}/main.cpp
    ${DUCK_DIR}/Duck.cpp
    ${DUCK_DIR}/MallardDuck.cpp
    ${BEHAVIOR_DIR}/FlyNoWay.cpp
    ${BEHAVIOR_DIR}/FlyWithWings.cpp
    ${BEHAVIOR_DIR}/QuackMute.cpp
    ${BEHAVIOR_DIR}/QuackSqueak.cpp)

add_executable(main ${SRC_LIST})