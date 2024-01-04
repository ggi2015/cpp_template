cmake_minimum_required(VERSION 3.5)

project (hello_headers)

SET(CMAKE_BUILD_TYPE Debug)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/utils.cpp
    main.cpp
)

# Add an executable with the above sources
add_executable(hello_headers ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
