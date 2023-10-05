set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR 8051)

# do some windows specific logic
if(WIN32)
    set(TOOLCHAIN_EXT ".exe")
else()
    set(TOOLCHAIN_EXT "")
endif(WIN32)

# default to Debug build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: Debug Release." FORCE)
endif()

if(DEFINED ENV{SDCC_PATH}) 
    # use the environment variable first    
    file(TO_CMAKE_PATH $ENV{SDCC_PATH} SDCC_TOOLCHAIN_PATH)
    message(STATUS "Using ENV variable SDCC_PATH = ${SDCC_TOOLCHAIN_PATH}")
elseif(COMPILER_ON_PATH) 
    # then check on the current path
    get_filename_component(SDCC_TOOLCHAIN_PATH ${COMPILER_ON_PATH} DIRECTORY)
    message(STATUS "Using SDCC from path = ${SDCC_TOOLCHAIN_PATH}")
else()
    message(FATAL_ERROR "Unable to find SDCC. Either add to your PATH, or define SDCC_PATH to the compiler location")
endif()

# Perform compiler test with the static library
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER ${SDCC_TOOLCHAIN_PATH}/sdcc${TOOLCHAIN_EXT})
# set(CMAKE_CXX_COMPILER ${SDCC_TOOLCHAIN_PATH}/sdcpp${TOOLCHAIN_EXT})
# sdas8051 - The assembler for 8051 type processors.
set(CMAKE_ASM_COMPILER  ${SDCC_TOOLCHAIN_PATH}/sdas8051${TOOLCHAIN_EXT})
# sdld -The linker for 8051 and STM8 type processors
set(CMAKE_LINKER        ${SDCC_TOOLCHAIN_PATH}/sdld${TOOLCHAIN_EXT})
set(CMAKE_OBJCOPY       ${SDCC_TOOLCHAIN_PATH}/sdobjcopy${TOOLCHAIN_EXT})
set(CMAKE_NM_UTIL       ${SDCC_TOOLCHAIN_PATH}/sdnm${TOOLCHAIN_EXT})
set(CMAKE_AR            ${SDCC_TOOLCHAIN_PATH}/sdar${TOOLCHAIN_EXT})
set(CMAKE_RANLIB        ${SDCC_TOOLCHAIN_PATH}/sdranlib${TOOLCHAIN_EXT})
# • packihx - A tool to pack (compress) Intel hex files
set(PACKIHX ${SDCC_TOOLCHAIN_PATH}/packihx${TOOLCHAIN_EXT})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Compiler and linker flags
# set(CMAKE_COMMON_FLAGS "-Wno-unused-parameter")
set(CMAKE_C_FLAGS 	"${MCPU_FLAGS} ${VFP_FLAGS} ${CMAKE_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${MCPU_FLAGS} ${VFP_FLAGS} ${CMAKE_COMMON_FLAGS}")
set(CMAKE_ASM_FLAGS "${MCPU_FLAGS} ${VFP_FLAGS} ${CMAKE_COMMON_FLAGS}")