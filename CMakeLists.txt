cmake_minimum_required(VERSION 3.22)
project(practiceOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(practiceOP main.cpp)
include_directories(libs/tasks)
include_directories(libs/auto_tests)
include_directories(libs/classes)
