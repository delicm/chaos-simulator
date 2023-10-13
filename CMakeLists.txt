cmake_minimum_required(VERSION 3.10)
project(Chaos)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# List the source files explicitly
set(SOURCES
    src/core.cpp
    src/action_handling.cpp
    src/running.cpp
    src/main.cpp
)

# Add the source files to the project
add_executable(chaos_sim ${SOURCES})

# Include the source directory
target_include_directories(chaos_sim PRIVATE src)

# Specify the path to SFML
list(APPEND CMAKE_PREFIX_PATH "/home/mdelic/Software/C-Includes/SFML/SFML-2.6.0/lib/cmake/SFML")

# Find the SFML library
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Link the SFML library to your executable
target_link_libraries(chaos_sim PRIVATE sfml-graphics)

# Check for debug build
if(DEBUG)
    message("Building in Debug mode")
    target_compile_options(chaos_sim PRIVATE -g)   # Add -g for debugging
    target_compile_definitions(chaos_sim PRIVATE DEBUG) # Define DEBUG macro
endif()
