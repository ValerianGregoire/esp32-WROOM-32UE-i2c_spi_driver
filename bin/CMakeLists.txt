cmake_minimum_required(VERSION 3.10)
project(bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories (optional)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Recursively search for all CMakeLists.txt in the src directory
file(GLOB_RECURSE cmake_files RELATIVE ${CMAKE_SOURCE_DIR} src/*/CMakeLists.txt)

# Loop through each found CMakeLists.txt and include the directory
foreach(cmake_file ${cmake_files})
    get_filename_component(dir ${cmake_file} DIRECTORY)
    add_subdirectory(${dir})
endforeach()
