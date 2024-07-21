cmake_minimum_required(VERSION 3.5)

project(MLN_Tests C)

set(CMAKE_C_STANDARD 99)

include_directories(headers)

set(testsrc source/main.c)

add_executable(Tester1 ${testsrc})
add_executable(Tester2 ${testsrc})

target_compile_definitions(Tester1 PRIVATE MLN_REDUCE_MACROS_TO_FUNCTIONS)