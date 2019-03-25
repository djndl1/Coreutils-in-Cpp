cmake_minimum_required(VERSION 2.6)
project(coreutils_cpp)

add_executable(coreutils_cpp main.cpp)

install(TARGETS coreutils_cpp RUNTIME DESTINATION bin)
