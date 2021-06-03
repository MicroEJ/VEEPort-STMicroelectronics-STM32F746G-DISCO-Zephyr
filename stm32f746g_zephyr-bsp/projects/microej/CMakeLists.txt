# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)

project(microej)

target_sources(app PRIVATE
"core/src/microej.c"
"core/src/LLBSP_stm32.c"
"core/src/LLMJVM_ZephyrOS.c"
"core/src/microej_time.c"
"core/src/microjvm_main.c")

target_include_directories(app PRIVATE 
"core/inc"
"platform/inc")

set(compile_flags 
    "-fno-strict-aliasing"
	"-Wno-address")

target_compile_options(app PRIVATE ${compile_flags})
   
add_custom_target(
    rename_sections
    ALL
    COMMAND python ${CMAKE_CURRENT_LIST_DIR}/rename-sections.py ${CMAKE_OBJCOPY} ${CMAKE_CURRENT_LIST_DIR}/platform/lib/microejapp.o)

target_link_libraries(app PUBLIC 
"${CMAKE_CURRENT_LIST_DIR}/platform/lib/microejapp.o" 
"${CMAKE_CURRENT_LIST_DIR}/platform/lib/microejruntime.a" 
"-lm")
