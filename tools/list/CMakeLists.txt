cmake_minimum_required(VERSION 3.10)
project(list)

set(CMAKE_C_STANDARD 99)

# Add the library target
add_library(list STATIC src/list.c)

# Include directory for list library
target_include_directories(list PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include  # Include directory for token library
)
