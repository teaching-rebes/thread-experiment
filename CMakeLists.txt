cmake_minimum_required(VERSION 3.13)  # CMake version check

project(threads)                      # Create project

set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Include the current directory as search path
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES procsthreads.cpp)

SET(GCC_COVERAGE_COMPILE_FLAGS "-static ")
SET(GCC_COVERAGE_LINK_FLAGS    "")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(thread_experiments ${SOURCE_FILES})

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
