cmake_minimum_required(VERSION 3.20)
project(5b C)

set(CMAKE_C_STANDARD 11)

add_executable(5b main.c)
add_subdirectory(libs)
target_link_libraries(5b data_structures)