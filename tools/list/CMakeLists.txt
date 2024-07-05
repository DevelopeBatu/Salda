cmake_minimum_required(VERSION 3.10)
project(list)

set(CMAKE_C_STANDARD 99)

include_directories(../../include)

add_library(list STATIC src/list.c)

target_include_directories(list PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
