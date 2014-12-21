cmake_minimum_required(VERSION 2.8.4)
project(for_jhelper)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

ADD_DEFINITIONS(-std=c++11)
ADD_DEFINITIONS(-DYA)

add_executable(test ${TASKS} ${HEADERS})