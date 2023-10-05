cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 99)

set(GSG_BASE_DIR ${CMAKE_SOURCE_DIR}/)

# Set the toolchain if not defined
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${GSG_BASE_DIR}/cmake/sdcc-toolchain.cmake")
endif()

if(WIN32)
    set(CMAKE_MAKE_PROGRAM ${CMAKE_SOURCE_DIR}/cmake/ninja.exe CACHE STRING "Ninja location")
endif()

if(POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif()

# Define the Project
# CXX enables IntelliSense only. Sources are still compiled as C.
project(rd8051_sdcc LANGUAGES CXX C ASM)

include(${GSG_BASE_DIR}/cmake/utilities.cmake)

add_subdirectory(FW_lib)
add_subdirectory(app)