cmake_minimum_required(VERSION 3.10)

project(Salda)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SRC_FILES "src/*.c")

add_subdirectory(tools/argparse)
add_subdirectory(tools/SaldaString)
add_subdirectory(tools/list)

include_directories(include)

add_executable(Salda ${SRC_FILES})

target_link_libraries(Salda argparse SaldaString list)

target_include_directories(Salda PUBLIC tools/argparse/include tools/SaldaString/include tools/list/include)

