file(GLOB_RECURSE src "*.c")
set(TARGET rd8051hal)

add_library(${TARGET} OBJECT
    ${src})

target_include_directories(${TARGET}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/inc
)