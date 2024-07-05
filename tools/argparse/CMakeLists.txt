add_library(argparse STATIC src/argparse.c)

target_include_directories(argparse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
