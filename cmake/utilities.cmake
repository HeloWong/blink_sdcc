function(post_build TARGET)
    message(STATUS "Convert to hex from ihx")
    add_custom_target(${TARGET}.hex ALL
            DEPENDS ${TARGET}
            COMMAND ${PACKIHX} ${TARGET}.ihx > ${TARGET}.hex)
endfunction()

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()