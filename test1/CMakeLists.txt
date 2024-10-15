cmake_minimum_required(VERSION 3.28)
project(test1)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED COMPONENTS SDL2)
add_executable(test1 main.cpp)

target_link_libraries(test1 PRIVATE SDL2::SDL2)

