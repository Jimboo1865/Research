cmake_minimum_required(VERSION 3.10)
project(GaussianSmear)

set(CMAKE_CXX_STANDARD 17)

add_executable(input_generator inputGenerator.cpp)

add_executable(smear_tool main.cpp smear.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.in DESTINATION ${CMAKE_CURRENT_BINARY_DIR})