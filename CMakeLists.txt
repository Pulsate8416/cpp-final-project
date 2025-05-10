cmake_minimum_required(VERSION 3.30)
project(cpp_final_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_final_project main.cpp
        tax_calculator.cpp
        tax_calculator.h
        file_utils.h
        file_utils.cpp)
