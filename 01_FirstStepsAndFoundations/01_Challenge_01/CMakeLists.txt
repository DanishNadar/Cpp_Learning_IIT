cmake_minimum_required(VERSION 3.31.2) # My cmake version specified
project(hello_world) # Project name

# Specifying C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hello_world hello_world.cpp) # Creating an executable file titled $(argument_1) using code from $(argument_2)
