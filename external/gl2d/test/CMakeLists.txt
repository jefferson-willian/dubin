cmake_minimum_required(VERSION 2.8)

project(gl2d_test)

# Source files.
file(GLOB SOURCES "src/*.cpp")

# Flag to compile using c+11.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Include directories.
include_directories(external/googletest/googletest/include ../include)

# Directories to link libraries.
link_directories(../)

# Compile gtest.
add_subdirectory(external/googletest/googletest)

# Executable.
add_executable(unittest ${SOURCES})

# Link static libraries.
target_link_libraries(unittest gtest pthread gl2d)

target_compile_definitions(unittest PRIVATE _UNIT_TESTING_)
