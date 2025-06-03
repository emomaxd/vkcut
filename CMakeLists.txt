cmake_minimum_required(VERSION 3.10)

# Prevent in-source builds (stay out of the source directory)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} AND NOT DEFINED WITH_IN_SOURCE_BUILD)
  message(FATAL_ERROR
      "CMake generation for vkcut is not allowed within the source directory!"
    "\nRemove the CMakeCache.txt and CMakeFiles directories and build out-of-source."
    "\nExample:"
    "\n mkdir build && cd build && cmake .."
  )
endif()

project(vkcut LANGUAGES CXX)

enable_testing()

# -----------------------------------------------------------------------------
# Set up Installation Directories
# -----------------------------------------------------------------------------
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Set output directories for library and executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Static libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Shared libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # Executables

option(BUILD_TEST "Enable building the test suite" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(source)

if (BUILD_TEST)
    add_subdirectory(test)
endif ()
