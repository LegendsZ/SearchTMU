cmake_minimum_required(VERSION 3.24)
project(SearchTMU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile the complete executable against all objects
add_executable(SearchTMU)

# Define DEBUG only if CMAKE_BUILD_TYPE is Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

target_sources(SearchTMU PRIVATE
        ${CMAKE_SOURCE_DIR}/src/Source.cpp
        ${CMAKE_SOURCE_DIR}/src/Graph.cpp
)

# Include directories for the executable
target_include_directories(SearchTMU PRIVATE "${CMAKE_SOURCE_DIR}/include")