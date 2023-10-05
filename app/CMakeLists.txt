set(TARGET_NAME "rd8_uart_demo")
file(GLOB_RECURSE src "*.c" "*.h")

add_executable(${TARGET_NAME} ${src})
target_link_libraries(${TARGET_NAME}
  PUBLIC rd8051hal)

post_build(${TARGET_NAME})