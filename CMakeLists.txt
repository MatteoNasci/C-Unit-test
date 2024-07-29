cmake_minimum_required(VERSION 3.5)

file(READ "headers/utest.h" ver)

string(REGEX MATCH "MLN_TESTS_VERSION_MAJOR ([0-9]*)" _ ${ver})
set(ver_major ${CMAKE_MATCH_1})

string(REGEX MATCH "MLN_TESTS_VERSION_MINOR ([0-9]*)" _ ${ver})
set(ver_minor ${CMAKE_MATCH_1})

string(REGEX MATCH "MLN_TESTS_VERSION_PATCH ([0-9]*)" _ ${ver})
set(ver_patch ${CMAKE_MATCH_1})

string(REGEX MATCH "MLN_TESTS_VERSION_TWEAK ([0-9]*)" _ ${ver})
set(ver_tweak ${CMAKE_MATCH_1})

message("version: ${ver_major}.${ver_minor}.${ver_patch}.${ver_tweak}")

project(MLN_Tests VERSION ${ver_major}.${ver_minor}.${ver_patch}.${ver_tweak} LANGUAGES C)

set(CMAKE_C_STANDARD 99)

include_directories(headers test/headers)

set(testsrc test/source/main.c test/source/tester.c)

add_executable(Tester1 ${testsrc})
add_executable(Tester2 ${testsrc})

target_compile_definitions(Tester1 PRIVATE TEST_REDUCE_TO_MACROS)