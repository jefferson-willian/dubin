cmake_minimum_required(VERSION 2.8)

project(gl2d)

# Source files.
file(GLOB SOURCES "src/*.cpp")

# Flag to compile using c+11.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Include directories.
include_directories(test/external/googletest/googletest/include ../)

# Directories to link libraries.
link_directories()

# Static library.
add_library(gl2d ${SOURCES})
