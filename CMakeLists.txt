cmake_minimum_required(VERSION 3.5)

project(MLN_Tests C)

set(CMAKE_C_STANDARD 99)

include_directories(headers test/headers)

set(testsrc test/source/main.c test/source/tester.c)

add_executable(Tester1 ${testsrc})
add_executable(Tester2 ${testsrc})

target_compile_definitions(Tester1 PRIVATE TEST_REDUCE_TO_MACROS)