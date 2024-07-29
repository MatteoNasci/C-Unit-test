#pragma once
#ifndef H_MLN_TESTS_UTEST_H_
#define H_MLN_TESTS_UTEST_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MLN_TESTS_VERSION_MAJOR 0
#define MLN_TESTS_VERSION_MINOR 4
#define MLN_TESTS_VERSION_PATCH 1
#define MLN_TESTS_VERSION_TWEAK 0

/* 
Defining MLN_REDUCE_MACROS_TO_FUNCTIONS will force most MACROS to use function calls instead, reducing code size
If MLN_REDUCE_MACROS_TO_FUNCTIONS is defined you need to put MLN_TEST_FUNC_DEFINITIONS in a .c file after including this header for the test functions definitions
If MLN_REDUCE_MACROS_TO_FUNCTIONS is not defined MLN_TEST_FUNC_DEFINITIONS will be empty
*/
/*
If MLN_REMOVE_TESTS_PREFIXES is defined it exposes test macro variants without the MLN_ prefix (the MLN variants will still work regardless)
A list of all usable MACROS and comments on how the MACROS work can be found inside this ifdef
*/
#ifdef MLN_REMOVE_TESTS_PREFIXES
    /* 
    Defining MLN_REDUCE_MACROS_TO_FUNCTIONS will force most MACROS to use function calls instead, reducing code size
    If MLN_REDUCE_MACROS_TO_FUNCTIONS is defined you need to put MLN_TEST_FUNC_DEFINITIONS in a .c file for the test functions definitions
    If MLN_REDUCE_MACROS_TO_FUNCTIONS is not defined MLN_TEST_FUNC_DEFINITIONS will be empty, so it's good practice to use this regardless of the state of MLN_REDUCE_MACROS_TO_FUNCTIONS 
    */
    #define TEST_FUNC_DEFINITIONS MLN_TEST_FUNC_DEFINITIONS
    /*
    To be used once at the beginning of the function/main where all the tests will be performed
    Starting point of the testing procedure
    */
    #define PRE_TESTS MLN_PRE_TESTS
    /*
    To be used once at the end of the function/main where all the tests will be performed
    Ending point of the testing procedure. If wait_input == true then the test will wait untill the user presses a key, to allow you to verify the results on the terminal
    */
    #define POST_TESTS(wait_input) MLN_POST_TESTS(wait_input)
    /*
    Sets the level of verbosity of the tests logs. 
    MINIMUM = only minimum fail logs
    LOW = same as MEDIUM at the moment
    MEDIUM = fail and skip logs
    HIGH = all logs
    verbosity might be evaluated multiple times in this macro
    MLN_PRE_TESTS must appear once before this MACRO can be used
    */
    #define SET_LOGS_VERBOSITY(verbosity) MLN_SET_LOGS_VERBOSITY(verbosity)
    /*
    To be used when performing the tests. The func_name must have a matching MLN_TEST(func_name)
    MLN_PRE_TESTS must appear once before any tests can be executed
    */
    #define RUN_TEST(func_name) MLN_RUN_TEST(func_name)
    /*
    To be used to define test functions. The arguments are the function name and the body of the function.
    Example:
    MLN_TEST(my_test,
        int a = 0;
        int b = 0;
        MLN_ASSERT_EQ(a, 0)
        MLN_ASSERT_NEQ(b, 1)
    )
    */
    #define TEST(func_name, ...) MLN_TEST(func_name, __VA_ARGS__)
    /*
    To be used to group up several MLN_RUN_TEST together. To be defined the same way MLN_TEST are defined.
    Example:
    MLN_SUITE(my_suite,
        MLN_RUN_TEST(my_test)
        MLN_RUN_TEST(my_other_test)
        ...
        MLN_RUN_TEST(my_n_test)
    )

    ...
    void main(){

        MLN_PRE_TESTS

        MLN_RUN_SUITE(suite_name)

        MLN_RUN_TEST(whatever)

        ...
    */
    #define SUITE(suite_name, ...) MLN_SUITE(suite_name, __VA_ARGS__)
    /*
    To be used when performing the tests. The suite_name must have a matching MLN_SUITE(suite_name)
    MLN_PRE_TESTS must appear once before any tests can be executed
    */
    #define RUN_SUITE(suite_name) MLN_RUN_SUITE(suite_name)

    //
    //BYPASSES
    //

    /*All Bypasses must be used inside a MLN_TEST*/

    /*
    Can be used inside a test, will automatically fail the current test and stop the execution
    */
    #define FAIL() MLN_FAIL()
    #define FAILm(msg) MLN_FAILm(msg)
    /*
    Can be used inside a test, will automatically pass the current test and stop the execution
    */
    #define PASS() MLN_PASS()
    /*
    Can be used inside a test, will automatically skip the current test and stop the execution
    */
    #define SKIP() MLN_SKIP()
    #define SKIPm(msg) MLN_SKIPm(msg)

    //
    //ASSERTS
    //

    /*Failing an assertion will stop the execution of the current test and will result in a failed test. 
    All assertions have a message variant (m), which logs a string message in case of a fail. 
    There's also a format variant (f) which allows toy to specify a format for the expected-actual values when printinf them on printf when the assertion fails.
    Another variant is the ignore fail (i), which makes it so that the assert will not stop the test execution when failing, allowing the test to continue (the failed assert and the overall test will still be counted as a fail)
    The variants can be found at the end of the assert MACRO, like MLN_ASSERT_FALSEmi , and their order in the MACRO name is: f -> m -> i. All combinations are present for most asserts (some asserts do not support the 'f' variant).
    All Assertions must be used inside a MLN_TEST*/

    /*
    Assert that condition evaluates as a true value (non zero).
    The arguments might be evaluated more than once
    */
    #define ASSERT(condition) MLN_ASSERT(condition)
    #define ASSERTm(condition, msg) MLN_ASSERTm(condition, msg)
    #define ASSERTi(condition) MLN_ASSERTi(condition)
    #define ASSERTmi(condition, msg) MLN_ASSERTmi(condition, msg)
    /*
    Assert that condition evaluates as a false value (zero).
    The arguments might be evaluated more than once
    */
    #define ASSERT_FALSE(condition) MLN_ASSERT_FALSE(condition)
    #define ASSERT_FALSEm(condition, msg) MLN_ASSERT_FALSEm(condition, msg) 
    #define ASSERT_FALSEi(condition) MLN_ASSERT_FALSEi(condition)
    #define ASSERT_FALSEmi(condition, msg) MLN_ASSERT_FALSEmi(condition, msg) 
    /*
    Assert that condition evaluates as a NULL value
    The arguments might be evaluated more than once
    */
    #define ASSERT_NULL(value) MLN_ASSERT_NULL(value)
    #define ASSERT_NULLm(value, msg) MLN_ASSERT_NULLm(value, msg)
    #define ASSERT_NULLi(value) MLN_ASSERT_NULLi(value)
    #define ASSERT_NULLmi(value, msg) MLN_ASSERT_NULLmi(value, msg)
    /*
    Assert that condition evaluates as a non-NULL value
    The arguments might be evaluated more than once
    */
    #define ASSERT_NNULL(value) MLN_ASSERT_NNULL(value)
    #define ASSERT_NNULLm(value, msg) MLN_ASSERT_NNULLm(value, msg)
    #define ASSERT_NNULLi(value) MLN_ASSERT_NNULLi(value)
    #define ASSERT_NNULLmi(value, msg) MLN_ASSERT_NNULLmi(value, msg)
    /*
    Assert that the first size bytes of memory pointed to by expected and actual are equal. If not, print a hexdump and highlight the lines and individual bytes which do not match.
    The arguments might be evaluated more than once
    */
    #define ASSERT_MEM_EQ(expected, actual, size) MLN_ASSERT_MEM_EQ(expected, actual, size)
    #define ASSERT_MEM_EQm(expected, actual, size, msg) MLN_ASSERT_MEM_EQm(expected, actual, size, msg)
    #define ASSERT_MEM_EQi(expected, actual, size) MLN_ASSERT_MEM_EQi(expected, actual, size)
    #define ASSERT_MEM_EQmi(expected, actual, size, msg) MLN_ASSERT_MEM_EQmi(expected, actual, size, msg)
    /*
    Assert that the first size bytes of memory pointed to by expected and actual are not entirely equal. If not, print a hexdump and highlight the lines and individual bytes which do match.
    The arguments might be evaluated more than once
    */
    #define ASSERT_MEM_NEQ(expected, actual, size) MLN_ASSERT_MEM_NEQ(expected, actual, size)
    #define ASSERT_MEM_NEQm(expected, actual, size, msg) MLN_ASSERT_MEM_NEQm(expected, actual, size, msg)
    #define ASSERT_MEM_NEQi(expected, actual, size) MLN_ASSERT_MEM_NEQi(expected, actual, size)
    #define ASSERT_MEM_NEQmi(expected, actual, size, msg) MLN_ASSERT_MEM_NEQmi(expected, actual, size, msg)
    /*
    Assert that expected == actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_EQ(expected, actual_value) MLN_ASSERT_EQ(expected, actual_value) 
    #define ASSERT_EQm(expected, actual_value, msg) MLN_ASSERT_EQm(expected, actual_value, msg)
    #define ASSERT_EQi(expected, actual_value) MLN_ASSERT_EQi(expected, actual_value) 
    #define ASSERT_EQmi(expected, actual_value, msg) MLN_ASSERT_EQmi(expected, actual_value, msg)
    /*
    Assert that expected == actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_EQf(expected, actual_value, format) MLN_ASSERT_EQf(expected, actual_value, format)
    #define ASSERT_EQfm(expected, actual_value, format, msg) MLN_ASSERT_EQfm(expected, actual_value, format, msg)
    #define ASSERT_EQfi(expected, actual_value, format) MLN_ASSERT_EQfi(expected, actual_value, format)
    #define ASSERT_EQfmi(expected, actual_value, format, msg) MLN_ASSERT_EQfmi(expected, actual_value, format, msg)
    /*
    Assert that expected != actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_NEQ(expected, actual_value) MLN_ASSERT_NEQ(expected, actual_value)
    #define ASSERT_NEQm(expected, actual_value, msg) MLN_ASSERT_NEQm(expected, actual_value, msg)
    #define ASSERT_NEQi(expected, actual_value) MLN_ASSERT_NEQi(expected, actual_value)
    #define ASSERT_NEQmi(expected, actual_value, msg) MLN_ASSERT_NEQmi(expected, actual_value, msg)
    /*
    Assert that expected != actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_NEQf(expected, actual_value, format) MLN_ASSERT_NEQf(expected, actual_value, format)
    #define ASSERT_NEQfm(expected, actual_value, format, msg) MLN_ASSERT_NEQfm(expected, actual_value, format, msg)
    #define ASSERT_NEQfi(expected, actual_value, format) MLN_ASSERT_NEQfi(expected, actual_value, format)
    #define ASSERT_NEQfmi(expected, actual_value, format, msg) MLN_ASSERT_NEQfmi(expected, actual_value, format, msg)
    /*
    Assert that expected > actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_GT(expected, actual_value) MLN_ASSERT_GT(expected, actual_value)
    #define ASSERT_GTm(expected, actual_value, msg) MLN_ASSERT_GTm(expected, actual_value, msg)
    #define ASSERT_GTi(expected, actual_value) MLN_ASSERT_GTi(expected, actual_value)
    #define ASSERT_GTmi(expected, actual_value, msg) MLN_ASSERT_GTmi(expected, actual_value, msg)
    /*
    Assert that expected > actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_GTf(expected, actual_value, format) MLN_ASSERT_GTf(expected, actual_value, format)
    #define ASSERT_GTfm(expected, actual_value, format, msg) MLN_ASSERT_GTfm(expected, actual_value, format, msg)
    #define ASSERT_GTfi(expected, actual_value, format) MLN_ASSERT_GTfi(expected, actual_value, format)
    #define ASSERT_GTfmi(expected, actual_value, format, msg) MLN_ASSERT_GTfmi(expected, actual_value, format, msg)
    /*
    Assert that expected >= actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_GTE(expected, actual_value) MLN_ASSERT_GTE(expected, actual_value)
    #define ASSERT_GTEm(expected, actual_value, msg) MLN_ASSERT_GTEm(expected, actual_value, msg)
    #define ASSERT_GTEi(expected, actual_value) MLN_ASSERT_GTEi(expected, actual_value)
    #define ASSERT_GTEmi(expected, actual_value, msg) MLN_ASSERT_GTEmi(expected, actual_value, msg)
    /*
    Assert that expected >= actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_GTEf(expected, actual_value, format) MLN_ASSERT_GTEf(expected, actual_value, format)
    #define ASSERT_GTEfm(expected, actual_value, format, msg) MLN_ASSERT_GTEfm(expected, actual_value, format, msg)
    #define ASSERT_GTEfi(expected, actual_value, format) MLN_ASSERT_GTEfi(expected, actual_value, format)
    #define ASSERT_GTEfmi(expected, actual_value, format, msg) MLN_ASSERT_GTEfmi(expected, actual_value, format, msg)
    /*
    Assert that expected < actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_LT(expected, actual_value) MLN_ASSERT_LT(expected, actual_value)
    #define ASSERT_LTm(expected, actual_value, msg) MLN_ASSERT_LTm(expected, actual_value, msg)
    #define ASSERT_LTi(expected, actual_value) MLN_ASSERT_LTi(expected, actual_value)
    #define ASSERT_LTmi(expected, actual_value, msg) MLN_ASSERT_LTmi(expected, actual_value, msg)
    /*
    Assert that expected < actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_LTf(expected, actual_value, format) MLN_ASSERT_LTf(expected, actual_value, format)
    #define ASSERT_LTfm(expected, actual_value, format, msg) MLN_ASSERT_LTfm(expected, actual_value, format, msg)
    #define ASSERT_LTfi(expected, actual_value, format) MLN_ASSERT_LTfi(expected, actual_value, format)
    #define ASSERT_LTfmi(expected, actual_value, format, msg) MLN_ASSERT_LTfmi(expected, actual_value, format, msg)
    /*
    Assert that expected <= actual_value
    The arguments might be evaluated more than once
    */
    #define ASSERT_LTE(expected, actual_value) MLN_ASSERT_LTE(expected, actual_value)
    #define ASSERT_LTEm(expected, actual_value, msg) MLN_ASSERT_LTEm(expected, actual_value, msg)
    #define ASSERT_LTEi(expected, actual_value) MLN_ASSERT_LTEi(expected, actual_value)
    #define ASSERT_LTEmi(expected, actual_value, msg) MLN_ASSERT_LTEmi(expected, actual_value, msg)
    /*
    Assert that expected <= actual_value, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_LTEf(expected, actual_value, format) MLN_ASSERT_LTEf(expected, actual_value, format)
    #define ASSERT_LTEfm(expected, actual_value, format, msg) MLN_ASSERT_LTEfm(expected, actual_value, format, msg)
    #define ASSERT_LTEfi(expected, actual_value, format) MLN_ASSERT_LTEfi(expected, actual_value, format)
    #define ASSERT_LTEfmi(expected, actual_value, format, msg) MLN_ASSERT_LTEfmi(expected, actual_value, format, msg)
    /*
    Assert that expected - tollerance <= actual_value <= expected + tollerance
    The arguments might be evaluated more than once
    */
    #define ASSERT_IN_RANGE(expected, actual_value, tollerance) MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance)
    #define ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg) MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg)
    #define ASSERT_IN_RANGEi(expected, actual_value, tollerance) MLN_ASSERT_IN_RANGEi(expected, actual_value, tollerance)
    #define ASSERT_IN_RANGEmi(expected, actual_value, tollerance, msg) MLN_ASSERT_IN_RANGEmi(expected, actual_value, tollerance, msg)
    /*
    Assert that expected - tollerance <= actual_value <= expected + tollerance, if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_IN_RANGEf(expected, actual_value, tollerance, format) MLN_ASSERT_IN_RANGEf(expected, actual_value, tollerance, format)
    #define ASSERT_IN_RANGEfm(expected, actual_value, tollerance, format, msg) MLN_ASSERT_IN_RANGEfm(expected, actual_value, tollerance, format, msg)
    #define ASSERT_IN_RANGEfi(expected, actual_value, tollerance, format) MLN_ASSERT_IN_RANGEfi(expected, actual_value, tollerance, format)
    #define ASSERT_IN_RANGEfmi(expected, actual_value, tollerance, format, msg) MLN_ASSERT_IN_RANGEfmi(expected, actual_value, tollerance, format, msg)
    /*
    Assert that (actual_value < expected - tollerance) || (actual_value > expected + tollerance)
    The arguments might be evaluated more than once
    */
    #define ASSERT_IN_NRANGE(expected, actual_value, tollerance) MLN_ASSERT_IN_NRANGE(expected, actual_value, tollerance)
    #define ASSERT_IN_NRANGEm(expected, actual_value, tollerance, msg) MLN_ASSERT_IN_NRANGEm(expected, actual_value, tollerance, msg)
    #define ASSERT_IN_NRANGEi(expected, actual_value, tollerance) MLN_ASSERT_IN_NRANGEi(expected, actual_value, tollerance)
    #define ASSERT_IN_NRANGEmi(expected, actual_value, tollerance, msg) MLN_ASSERT_IN_NRANGEmi(expected, actual_value, tollerance, msg)
    /*
    Assert that (actual_value < expected - tollerance) || (actual_value > expected + tollerance), if the expression is false then the 2 arguments will be printed out based on the given format (printf)
    The arguments might be evaluated more than once
    */
    #define ASSERT_IN_NRANGEf(expected, actual_value, tollerance, format) MLN_ASSERT_IN_NRANGEf(expected, actual_value, tollerance, format)
    #define ASSERT_IN_NRANGEfm(expected, actual_value, tollerance, format, msg) MLN_ASSERT_IN_NRANGEfm(expected, actual_value, tollerance, format, msg)
    #define ASSERT_IN_NRANGEfi(expected, actual_value, tollerance, format) MLN_ASSERT_IN_NRANGEfi(expected, actual_value, tollerance, format)
    #define ASSERT_IN_NRANGEfmi(expected, actual_value, tollerance, format, msg) MLN_ASSERT_IN_NRANGEfmi(expected, actual_value, tollerance, format, msg)
    /*
    Assert that the first size bytes of the strings are equal (strncmp(expected, actual_value, size) == 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_EQ(expected, actual_value, size) MLN_ASSERT_STRN_EQ(expected, actual_value, size) 
    #define ASSERT_STRN_EQm(expected, actual_value, size, msg) MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg)
    #define ASSERT_STRN_EQi(expected, actual_value, size) MLN_ASSERT_STRN_EQi(expected, actual_value, size) 
    #define ASSERT_STRN_EQmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_EQmi(expected, actual_value, size, msg)
    /*
    Assert that the first size bytes of the strings are not equal (strncmp(expected, actual_value, size) != 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_NEQ(expected, actual_value, size) MLN_ASSERT_STRN_NEQ(expected, actual_value, size)
    #define ASSERT_STRN_NEQm(expected, actual_value, size, msg) MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg)
    #define ASSERT_STRN_NEQi(expected, actual_value, size) MLN_ASSERT_STRN_NEQi(expected, actual_value, size)
    #define ASSERT_STRN_NEQmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_NEQmi(expected, actual_value, size, msg)
    /*
    Assert that the first size bytes of the expected string comes lexicographically after the first size bytes of the actual string (strncmp(expected, actual_value, size) > 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_GT(expected, actual_value, size) MLN_ASSERT_STRN_GT(expected, actual_value, size)
    #define ASSERT_STRN_GTm(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg)
    #define ASSERT_STRN_GTi(expected, actual_value, size) MLN_ASSERT_STRN_GTi(expected, actual_value, size)
    #define ASSERT_STRN_GTmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTmi(expected, actual_value, size, msg)
    /*
    Assert that the first size bytes of the expected string is either equal or comes lexicographically after the first size bytes of the actual string (strncmp(expected, actual_value, size) >= 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_GTE(expected, actual_value, size) MLN_ASSERT_STRN_GTE(expected, actual_value, size)
    #define ASSERT_STRN_GTEm(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg)
    #define ASSERT_STRN_GTEi(expected, actual_value, size) MLN_ASSERT_STRN_GTEi(expected, actual_value, size)
    #define ASSERT_STRN_GTEmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTEmi(expected, actual_value, size, msg)
    /*
    Assert that the first size bytes of the expected string comes lexicographically before the first size bytes of the actual string (strncmp(expected, actual_value, size) < 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_LT(expected, actual_value, size) MLN_ASSERT_STRN_LT(expected, actual_value, size)
    #define ASSERT_STRN_LTm(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg)
    #define ASSERT_STRN_LTi(expected, actual_value, size) MLN_ASSERT_STRN_LTi(expected, actual_value, size)
    #define ASSERT_STRN_LTmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTmi(expected, actual_value, size, msg)
    /*
    Assert that the first size bytes of the expected string is either equal or comes lexicographically before the first size bytes of the actual string (strncmp(expected, actual_value, size) <= 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STRN_LTE(expected, actual_value, size) MLN_ASSERT_STRN_LTE(expected, actual_value, size)
    #define ASSERT_STRN_LTEm(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg)
    #define ASSERT_STRN_LTEi(expected, actual_value, size) MLN_ASSERT_STRN_LTEi(expected, actual_value, size)
    #define ASSERT_STRN_LTEmi(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTEmi(expected, actual_value, size, msg)
    /*
    Assert that the first string is equal to the second (strcmp(expected, actual_value) == 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_EQ(expected, actual_value) MLN_ASSERT_STR_EQ(expected, actual_value) 
    #define ASSERT_STR_EQm(expected, actual_value, msg) MLN_ASSERT_STR_EQm(expected, actual_value, msg)
    #define ASSERT_STR_EQi(expected, actual_value) MLN_ASSERT_STR_EQi(expected, actual_value) 
    #define ASSERT_STR_EQmi(expected, actual_value, msg) MLN_ASSERT_STR_EQmi(expected, actual_value, msg)
    /*
    Assert that the first string is not equal to the second (strcmp(expected, actual_value) != 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_NEQ(expected, actual_value) MLN_ASSERT_STR_NEQ(expected, actual_value)
    #define ASSERT_STR_NEQm(expected, actual_value, msg) MLN_ASSERT_STR_NEQm(expected, actual_value, msg)
    #define ASSERT_STR_NEQi(expected, actual_value) MLN_ASSERT_STR_NEQi(expected, actual_value)
    #define ASSERT_STR_NEQmi(expected, actual_value, msg) MLN_ASSERT_STR_NEQmi(expected, actual_value, msg)
    /*
    Assert that the expected string comes lexicographically after the actual string (strcmp(expected, actual_value) > 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_GT(expected, actual_value) MLN_ASSERT_STR_GT(expected, actual_value)
    #define ASSERT_STR_GTm(expected, actual_value, msg) MLN_ASSERT_STR_GTm(expected, actual_value, msg)
    #define ASSERT_STR_GTi(expected, actual_value) MLN_ASSERT_STR_GTi(expected, actual_value)
    #define ASSERT_STR_GTmi(expected, actual_value, msg) MLN_ASSERT_STR_GTmi(expected, actual_value, msg)
    /*
    Assert that the expected string is either equal or comes lexicographically after the actual string (strcmp(expected, actual_value) >= 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_GTE(expected, actual_value) MLN_ASSERT_STR_GTE(expected, actual_value)
    #define ASSERT_STR_GTEm(expected, actual_value, msg) MLN_ASSERT_STR_GTEm(expected, actual_value, msg)
    #define ASSERT_STR_GTEi(expected, actual_value) MLN_ASSERT_STR_GTEi(expected, actual_value)
    #define ASSERT_STR_GTEmi(expected, actual_value, msg) MLN_ASSERT_STR_GTEmi(expected, actual_value, msg)
    /*
    Assert that the expected string comes lexicographically before the actual string (strcmp(expected, actual_value) < 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_LT(expected, actual_value) MLN_ASSERT_STR_LT(expected, actual_value)
    #define ASSERT_STR_LTm(expected, actual_value, msg) MLN_ASSERT_STR_LTm(expected, actual_value, msg)
    #define ASSERT_STR_LTi(expected, actual_value) MLN_ASSERT_STR_LTi(expected, actual_value)
    #define ASSERT_STR_LTmi(expected, actual_value, msg) MLN_ASSERT_STR_LTmi(expected, actual_value, msg)
    /*
    Assert that the expected string is either equal or comes lexicographically before the actual string (strcmp(expected, actual_value) <= 0).
    The arguments might be evaluated more than once
    */
    #define ASSERT_STR_LTE(expected, actual_value) MLN_ASSERT_STR_LTE(expected, actual_value)
    #define ASSERT_STR_LTEm(expected, actual_value, msg) MLN_ASSERT_STR_LTEm(expected, actual_value, msg)
    #define ASSERT_STR_LTEi(expected, actual_value) MLN_ASSERT_STR_LTEi(expected, actual_value)
    #define ASSERT_STR_LTEmi(expected, actual_value, msg) MLN_ASSERT_STR_LTEmi(expected, actual_value, msg)
    
#endif


//TODO: improve logging verbosity adjustments, right now there's little change between most settings
/*
Collection of internal defines/functions, not designed to be used by the final user
*/
#if 1
    typedef enum mln_verbosity_type { 
        MINIMUM = 0, LOW = 1, MEDIUM = 2, HIGH = 3
    } mln_verbosity_type_t;

    typedef enum mln_default_msg_type { 
        NONE = 0, FAIL = 1, SKIP = 2
    } mln_default_msg_type_t;

    typedef struct mln_test_data{
        size_t passes;
        size_t fails;
        size_t skips;
        size_t unspecified;
        bool printed_logs;
    } mln_test_data_t;

    typedef struct mln_tests_results{
        mln_test_data_t asserts;
        mln_test_data_t tests;
    } mln_tests_results_t;

    typedef struct mln_time_data{
        const clock_t start_time;
        clock_t last_recorded_time;
        clock_t clocks_per_sec;
        clock_t total_tests_time;
    } mln_time_data_t;

    typedef struct mln_func_data{
        void (*func_ptr)(struct mln_run_test_data*);
        char* func_name;
        char* file_name;
        int code_line;
    } mln_func_data_t;

    typedef struct mln_run_test_data{
        mln_func_data_t last_func;
        mln_test_data_t last_test;
        mln_tests_results_t stats;
        mln_time_data_t time;
        mln_verbosity_type_t verbosity;
    } mln_run_test_data_t;

    #define MLN_STRINGIFY(A) #A
    #define MLN_STRINGIFY_NX(A) MLN_STRINGIFY(A)

    #define MLN_GET_TEST_NAME_FROM_FUNC(func_name) mln_test_##func_name
    #define MLN_GET_TEST_NAME_TEXT_FROM_FUNC(func_name) MLN_STRINGIFY_NX(MLN_GET_TEST_NAME_FROM_FUNC(func_name))

    #define MLN_PRE_TESTS MLN_PRE_TESTS_IMPLEMENTATION

    #define MLN_POST_TESTS(wait_input) MLN_POST_TESTS_IMPLEMENTATION(wait_input)

    #define MLN_SUITE(suite_name, ...) MLN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(suite_name), __VA_ARGS__)

    #define MLN_TEST(func_name, ...) MLN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(func_name), __VA_ARGS__)

    #define MLN_SET_LOGS_VERBOSITY(verbosity) MLN_SET_LOGS_VERBOSITY_IMPLEMENTATION(mln_test_data_ptr, verbosity)

    #define MLN_FAIL() MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "Fail", "Fail", "", (false), MLN_STRINGIFY_NX(MLN_FAIL), "%s", STRING, true)

    #define MLN_FAILm(msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "Fail", "Fail", msg, (false), MLN_STRINGIFY_NX(MLN_FAILm), "%s", STRING, true)

    #define MLN_PASS() MLN_PASS_IMPLEMENTATION(mln_test_data_ptr)

    #define MLN_SKIP() MLN_SKIPm_IMPLEMENTATION("", mln_test_data_ptr, MLN_STRINGIFY_NX(MLN_SKIP))

    #define MLN_SKIPm(msg) MLN_SKIPm_IMPLEMENTATION(msg, mln_test_data_ptr, MLN_STRINGIFY_NX(MLN_SKIPm))

    #define MLN_ASSERT(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "true", condition ? "true" : "false", "", (condition), MLN_STRINGIFY_NX(MLN_ASSERT), "%s", STRING, true)

    #define MLN_ASSERTm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "true", condition ? "true" : "false", msg, (condition), MLN_STRINGIFY_NX(MLN_ASSERTm), "%s", STRING, true)

    #define MLN_ASSERT_FALSE(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "false", condition ? "true" : "false", "", (!condition), MLN_STRINGIFY_NX(MLN_ASSERT_FALSE), "%s", STRING, true)

    #define MLN_ASSERT_FALSEm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "false", condition ? "true" : "false", msg, (!condition), MLN_STRINGIFY_NX(MLN_ASSERT_FALSEm), "%s", STRING, true)

    #define MLN_ASSERT_NULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, "", (NULL == value), MLN_STRINGIFY_NX(MLN_ASSERT_NULL), "%p", GENERIC, true)

    #define MLN_ASSERT_NULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, msg, (NULL == value), MLN_STRINGIFY_NX(MLN_ASSERT_NULLm), "%p", GENERIC, true)

    #define MLN_ASSERT_NNULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, "", (NULL != value), MLN_STRINGIFY_NX(MLN_ASSERT_NNULL), "%p", GENERIC, true)

    #define MLN_ASSERT_NNULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, msg, (NULL != value), MLN_STRINGIFY_NX(MLN_ASSERT_NNULLm), "%p", GENERIC, true)

    #define MLN_ASSERT_MEM_EQ(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, true, "", MLN_STRINGIFY_NX(MLN_ASSERT_MEM_EQ), true)

    #define MLN_ASSERT_MEM_EQm(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, true, msg, MLN_STRINGIFY_NX(MLN_ASSERT_MEM_EQm), true)

    #define MLN_ASSERT_MEM_NEQ(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, false, "", MLN_STRINGIFY_NX(MLN_ASSERT_MEM_NEQ), true)

    #define MLN_ASSERT_MEM_NEQm(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, false, msg, MLN_STRINGIFY_NX(MLN_ASSERT_MEM_NEQm), true)

    #define MLN_ASSERT_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQ), "%s", STRING, true)

    #define MLN_ASSERT_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQm), "%s", STRING, true)

    #define MLN_ASSERT_EQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQf), format, GENERIC, true)

    #define MLN_ASSERT_EQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQfm), format, GENERIC, true)

    #define MLN_ASSERT_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQ), "%s", STRING, true)

    #define MLN_ASSERT_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQm), "%s", STRING, true)

    #define MLN_ASSERT_NEQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQf), format, GENERIC, true)

    #define MLN_ASSERT_NEQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQfm), format, GENERIC, true)

    #define MLN_ASSERT_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GT), "%s", STRING, true)

    #define MLN_ASSERT_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTm), "%s", STRING, true)

    #define MLN_ASSERT_GTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTf), format, GENERIC, true)

    #define MLN_ASSERT_GTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTfm), format, GENERIC, true)

    #define MLN_ASSERT_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTE), "%s", STRING, true)

    #define MLN_ASSERT_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEm), "%s", STRING, true)

    #define MLN_ASSERT_GTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEf), format, GENERIC, true)

    #define MLN_ASSERT_GTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEfm), format, GENERIC, true)

    #define MLN_ASSERT_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LT), "%s", STRING, true)

    #define MLN_ASSERT_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTm), "%s", STRING, true)

    #define MLN_ASSERT_LTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTf), format, GENERIC, true)

    #define MLN_ASSERT_LTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTfm), format, GENERIC, true)

    #define MLN_ASSERT_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTE), "%s", STRING, true)

    #define MLN_ASSERT_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEm), "%s", STRING, true)

    #define MLN_ASSERT_LTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEf), format, GENERIC, true)

    #define MLN_ASSERT_LTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEfm), format, GENERIC, true)

    #define MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGE), "%s", STRING, true)

    #define MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEm), "%s", STRING, true)

    #define MLN_ASSERT_IN_RANGEf(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEf), format, GENERIC, true)

    #define MLN_ASSERT_IN_RANGEfm(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEfm), format, GENERIC, true)

    #define MLN_ASSERT_IN_NRANGE(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGE), "%s", STRING, true)

    #define MLN_ASSERT_IN_NRANGEm(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEm), "%s", STRING, true)

    #define MLN_ASSERT_IN_NRANGEf(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEf), format, GENERIC, true)

    #define MLN_ASSERT_IN_NRANGEfm(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEfm), format, GENERIC, true)

    #define MLN_ASSERT_STRN_EQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_EQ), "%s", STRING, true)

    #define MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_EQm), "%s", STRING, true)

    #define MLN_ASSERT_STRN_NEQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_NEQ), "%s", STRING, true)

    #define MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_NEQm), "%s", STRING, true)

    #define MLN_ASSERT_STRN_GT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GT), "%s", STRING, true)

    #define MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTm), "%s", STRING, true)

    #define MLN_ASSERT_STRN_GTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTE), "%s", STRING, true)

    #define MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTEm), "%s", STRING, true)

    #define MLN_ASSERT_STRN_LT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LT), "%s", STRING, true)

    #define MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTm), "%s", STRING, true)

    #define MLN_ASSERT_STRN_LTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTE), "%s", STRING, true)

    #define MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTEm), "%s", STRING, true)

    #define MLN_ASSERT_STR_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_EQ), "%s", STRING, true)

    #define MLN_ASSERT_STR_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_EQm), "%s", STRING, true)

    #define MLN_ASSERT_STR_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_NEQ), "%s", STRING, true)

    #define MLN_ASSERT_STR_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_NEQm), "%s", STRING, true)

    #define MLN_ASSERT_STR_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GT), "%s", STRING, true)

    #define MLN_ASSERT_STR_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTm), "%s", STRING, true)

    #define MLN_ASSERT_STR_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTE), "%s", STRING, true)

    #define MLN_ASSERT_STR_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTEm), "%s", STRING, true)

    #define MLN_ASSERT_STR_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LT), "%s", STRING, true)

    #define MLN_ASSERT_STR_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTm), "%s", STRING, true)

    #define MLN_ASSERT_STR_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTE), "%s", STRING, true)

    #define MLN_ASSERT_STR_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTEm), "%s", STRING, true)

    #define MLN_ASSERTi(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "true", condition ? "true" : "false", "", (condition), MLN_STRINGIFY_NX(MLN_ASSERTi), "%s", STRING, false)

    #define MLN_ASSERTmi(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "true", condition ? "true" : "false", msg, (condition), MLN_STRINGIFY_NX(MLN_ASSERTmi), "%s", STRING, false)

    #define MLN_ASSERT_FALSEi(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "false", condition ? "true" : "false", "", (!condition), MLN_STRINGIFY_NX(MLN_ASSERT_FALSEi), "%s", STRING, false)

    #define MLN_ASSERT_FALSEmi(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), "false", condition ? "true" : "false", msg, (!condition), MLN_STRINGIFY_NX(MLN_ASSERT_FALSEmi), "%s", STRING, false)

    #define MLN_ASSERT_NULLi(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, "", (NULL == value), MLN_STRINGIFY_NX(MLN_ASSERT_NULLi), "%p", GENERIC, false)

    #define MLN_ASSERT_NULLmi(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, msg, (NULL == value), MLN_STRINGIFY_NX(MLN_ASSERT_NULLmi), "%p", GENERIC, false)

    #define MLN_ASSERT_NNULLi(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, "", (NULL != value), MLN_STRINGIFY_NX(MLN_ASSERT_NNULLi), "%p", GENERIC, false)

    #define MLN_ASSERT_NNULLmi(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), NULL, value, msg, (NULL != value), MLN_STRINGIFY_NX(MLN_ASSERT_NNULLmi), "%p", GENERIC, false)

    #define MLN_ASSERT_MEM_EQi(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, true, "", MLN_STRINGIFY_NX(MLN_ASSERT_MEM_EQi), false)

    #define MLN_ASSERT_MEM_EQmi(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, true, msg, MLN_STRINGIFY_NX(MLN_ASSERT_MEM_EQmi), false)

    #define MLN_ASSERT_MEM_NEQi(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, false, "", MLN_STRINGIFY_NX(MLN_ASSERT_MEM_NEQi), false)

    #define MLN_ASSERT_MEM_NEQmi(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_test_data_ptr), expected, actual, size, false, msg, MLN_STRINGIFY_NX(MLN_ASSERT_MEM_NEQmi), false)

    #define MLN_ASSERT_EQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQi), "%s", STRING, false)

    #define MLN_ASSERT_EQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQmi), "%s", STRING, false)

    #define MLN_ASSERT_EQfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQfi), format, GENERIC, false)

    #define MLN_ASSERT_EQfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_EQfmi), format, GENERIC, false)

    #define MLN_ASSERT_NEQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQi), "%s", STRING, false)

    #define MLN_ASSERT_NEQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQmi), "%s", STRING, false)

    #define MLN_ASSERT_NEQfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQfi), format, GENERIC, false)

    #define MLN_ASSERT_NEQfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_NEQfmi), format, GENERIC, false)

    #define MLN_ASSERT_GTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTi), "%s", STRING, false)

    #define MLN_ASSERT_GTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTmi), "%s", STRING, false)

    #define MLN_ASSERT_GTfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTfi), format, GENERIC, false)

    #define MLN_ASSERT_GTfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTfmi), format, GENERIC, false)

    #define MLN_ASSERT_GTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEi), "%s", STRING, false)

    #define MLN_ASSERT_GTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEmi), "%s", STRING, false)

    #define MLN_ASSERT_GTEfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEfi), format, GENERIC, false)

    #define MLN_ASSERT_GTEfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_GTEfmi), format, GENERIC, false)

    #define MLN_ASSERT_LTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTi), "%s", STRING, false)

    #define MLN_ASSERT_LTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTmi), "%s", STRING, false)

    #define MLN_ASSERT_LTfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTfi), format, GENERIC, false)

    #define MLN_ASSERT_LTfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTfmi), format, GENERIC, false)

    #define MLN_ASSERT_LTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEi), "%s", STRING, false)

    #define MLN_ASSERT_LTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEmi), "%s", STRING, false)

    #define MLN_ASSERT_LTEfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEfi), format, GENERIC, false)

    #define MLN_ASSERT_LTEfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_LTEfmi), format, GENERIC, false)

    #define MLN_ASSERT_IN_RANGEi(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEi), "%s", STRING, false)

    #define MLN_ASSERT_IN_RANGEmi(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEmi), "%s", STRING, false)

    #define MLN_ASSERT_IN_RANGEfi(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEfi), format, GENERIC, false)

    #define MLN_ASSERT_IN_RANGEfmi(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(MLN_ASSERT_IN_RANGEfmi), format, GENERIC, false)

    #define MLN_ASSERT_IN_NRANGEi(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, "", (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEi), "%s", STRING, false)

    #define MLN_ASSERT_IN_NRANGEmi(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), #expected, #actual_value, msg, (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEmi), "%s", STRING, false)

    #define MLN_ASSERT_IN_NRANGEfi(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEfi), format, GENERIC, false)

    #define MLN_ASSERT_IN_NRANGEfmi(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (actual_value < expected - tollerance) || (actual_value > expected + tollerance), MLN_STRINGIFY_NX(MLN_ASSERT_IN_NRANGEfmi), format, GENERIC, false)

    #define MLN_ASSERT_STRN_EQi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_EQi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_EQmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_EQmi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_NEQi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_NEQi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_NEQmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_NEQmi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_GTi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_GTmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTmi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_GTEi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTEi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_GTEmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_GTEmi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_LTi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_LTmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTmi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_LTEi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTEi), "%s", STRING, false)

    #define MLN_ASSERT_STRN_LTEmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STRN_LTEmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_EQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_EQi), "%s", STRING, false)

    #define MLN_ASSERT_STR_EQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_EQmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_NEQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_NEQi), "%s", STRING, false)

    #define MLN_ASSERT_STR_NEQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_NEQmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_GTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTi), "%s", STRING, false)

    #define MLN_ASSERT_STR_GTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_GTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTEi), "%s", STRING, false)

    #define MLN_ASSERT_STR_GTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_GTEmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_LTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTi), "%s", STRING, false)

    #define MLN_ASSERT_STR_LTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTmi), "%s", STRING, false)

    #define MLN_ASSERT_STR_LTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, "", (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTEi), "%s", STRING, false)

    #define MLN_ASSERT_STR_LTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_test_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(MLN_ASSERT_STR_LTEmi), "%s", STRING, false)


    #define MLN_DEFAULT_MEM_ASSERT_(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail) \
        {\
            bool mln_stop_test = false;\
            MLN_DEFAULT_MEM_ASSERT(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, (&mln_stop_test))\
            if(mln_stop_test){\
                return;\
            }\
        }

    #ifdef MLN_REDUCE_MACROS_TO_FUNCTIONS

        #define MLN_ADD_LOGS(mln_test_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION_FUNC((mln_test_data_ptr), msg)
        #define MLN_RUN_SUITE(suite_name) MLN_RUN_SUITE_IMPLEMENTATION_FUNC(mln_test_data_ptr, suite_name)
        #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION_FUNC(mln_test_data_ptr, func_name)
        #define MLN_DEFAULT_MEM_ASSERT(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_DEFAULT_MEM_ASSERT_FUNC(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)

        #define MLN_RUN_SUITE_IMPLEMENTATION_FUNC(mln_test_data_ptr, suite_name) mln_run_suite_implementation_func_call(mln_test_data_ptr, &(MLN_GET_TEST_NAME_FROM_FUNC(suite_name)), #suite_name);
        #define MLN_ADD_LOGS_IMPLEMENTATION_FUNC(mln_test_data_ptr, msg) mln_add_logs_implementation_func_call(mln_test_data_ptr, msg);
        #define MLN_RUN_TEST_IMPLEMENTATION_FUNC(mln_test_data_ptr, func_name) mln_run_test_implementation_func_call(mln_test_data_ptr, &(MLN_GET_TEST_NAME_FROM_FUNC(func_name)), #func_name);
        #define MLN_FAILm_IMPLEMENTATION_STRING(mln_test_data_ptr, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) mln_failm_implementation_string_func_call(mln_test_data_ptr, msg, expected, actual, assert_failed, stop_test_on_fail, stop_test_ptr);
        #define MLN_DEFAULT_MEM_ASSERT_FUNC(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) mln_default_mem_assert_func_call(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr);
        #define MLN_GET_CHAR_ARRAY_LENGTH(msg, out_length_ptr) mln_get_char_array_length_func_call(msg, out_length_ptr);
        #define MLN_PRINTF_DEFAULT_MESSAGE(mln_test_data_ptr, msg_type, assert_name) mln_printf_default_message_func_call(mln_test_data_ptr, msg_type, assert_name);

        void mln_failm_implementation_string_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* msg, const char* expected, const char* actual, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr); 
        void mln_add_logs_implementation_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* msg);
        void mln_run_test_implementation_func_call(mln_run_test_data_t* mln_test_data_ptr, void (*func_ptr)(mln_run_test_data_t*), char* func_name_text);
        void mln_run_suite_implementation_func_call(mln_run_test_data_t* mln_test_data_ptr, void (*func_ptr)(mln_run_test_data_t*), char* func_name_text);
        void mln_default_mem_assert_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* data_a, const char* data_b, const size_t size, const bool equality, const char* msg, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr);
        void mln_get_char_array_length_func_call(const char* msg, size_t* out_length_ptr);
        void mln_printf_default_message_func_call(mln_run_test_data_t* mln_test_data_ptr, const mln_default_msg_type_t msg_type, const char* assert_name);

        #define MLN_TEST_FUNC_DEFINITIONS\
            void mln_get_char_array_length_func_call(const char* msg, size_t* out_length_ptr){\
                MLN_GET_CHAR_ARRAY_LENGTH_IMPLEMENTATION(msg, out_length_ptr)\
            }\
            void mln_add_logs_implementation_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* msg){\
                MLN_ADD_LOGS_IMPLEMENTATION(mln_test_data_ptr, msg)\
            }\
            void mln_run_test_implementation_func_call(\
            mln_run_test_data_t* mln_test_data_ptr,\
            void (*in_func_ptr)(mln_run_test_data_t*), \
            char* in_func_name_text){\
                MLN_RUN_TEST_IMPLEMENTATION(mln_test_data_ptr, in_func_ptr, in_func_name_text)\
            }\
            void mln_run_suite_implementation_func_call(\
            mln_run_test_data_t* mln_test_data_ptr,\
            void (*in_func_ptr)(mln_run_test_data_t*), \
            char* in_func_name_text){\
                MLN_RUN_SUITE_IMPLEMENTATION(mln_test_data_ptr, in_func_ptr, in_func_name_text)\
            }\
            void mln_failm_implementation_string_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* msg, const char* expected, const char* actual, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr){\
                MLN_FAILm_IMPLEMENTATION_GENERIC(mln_test_data_ptr, msg, expected, actual, "%s", assert_failed, stop_test_on_fail, stop_test_ptr)\
            }\
            void mln_default_mem_assert_func_call(mln_run_test_data_t* mln_test_data_ptr, const char* data_a, const char* data_b, const size_t size, const bool equality, const char* msg, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr){\
               MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_test_data_ptr, data_a, data_b, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) \
            }\
            void mln_printf_default_message_func_call(mln_run_test_data_t* mln_test_data_ptr, const mln_default_msg_type_t msg_type, const char* assert_name){\
                MLN_PRINTF_DEFAULT_MESSAGE_IMPLEMENTATION(mln_test_data_ptr, msg_type, assert_name)\
            }

    #else

        #define MLN_TEST_FUNC_DEFINITIONS
        #define MLN_ADD_LOGS(mln_test_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION((mln_test_data_ptr), msg)
        #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION(mln_test_data_ptr, (&MLN_GET_TEST_NAME_FROM_FUNC(func_name)), #func_name)
        #define MLN_RUN_SUITE(suite_name) MLN_RUN_SUITE_IMPLEMENTATION(mln_test_data_ptr, (&MLN_GET_TEST_NAME_FROM_FUNC(suite_name)), #suite_name)
        #define MLN_FAILm_IMPLEMENTATION_STRING(mln_test_data_ptr, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_FAILm_IMPLEMENTATION_GENERIC(mln_test_data_ptr, msg, expected, actual, "%s", assert_failed, stop_test_on_fail, stop_test_ptr)
        #define MLN_DEFAULT_MEM_ASSERT(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)
        #define MLN_GET_CHAR_ARRAY_LENGTH(msg, out_length_ptr) MLN_GET_CHAR_ARRAY_LENGTH_IMPLEMENTATION(msg, out_length_ptr)
        #define MLN_PRINTF_DEFAULT_MESSAGE(mln_test_data_ptr, msg_type, assert_name) MLN_PRINTF_DEFAULT_MESSAGE_IMPLEMENTATION(mln_test_data_ptr, msg_type, assert_name) 

    #endif

    #define MLN_GET_CHAR_ARRAY_LENGTH_IMPLEMENTATION(msg, out_length_ptr) \
        {\
            (*out_length_ptr) = 0;\
            size_t mln_i = 0;\
            char mln_letter;\
            if(msg != NULL){\
                do{\
                    mln_letter = (msg)[mln_i++];\
                }while(mln_letter != '\0');\
            }\
            if(mln_i > 0){\
                (*out_length_ptr) = mln_i - 1;\
            }\
        }

    //Used only in tests
    #define MLN_ADD_LOGS_IMPLEMENTATION(mln_test_data_ptr, msg) \
        {\
            size_t mln_msg_sizeof;\
            MLN_GET_CHAR_ARRAY_LENGTH(msg, (&mln_msg_sizeof))\
            if(mln_msg_sizeof > 1){\
                const bool is_last_char_new_line = msg[mln_msg_sizeof - 1] == '\n';\
                MLN_PRINTF(mln_test_data_ptr, is_last_char_new_line ? "%s" : "%s\n", msg)\
            }\
        }

    //used only in tests
    #define MLN_DEFAULT_ASSERT_IMPLEMENTATION(mln_test_data_ptr, expected, actual_value, msg, expression, assert_failed, format, fail_type, stop_test_on_fail) \
        {\
            const bool mln_result = expression;\
            if(mln_result){\
                (mln_test_data_ptr)->last_test.passes++;\
            }else{\
                bool mln_stop_test = false;\
                MLN_FAILm_IMPLEMENTATION_##fail_type((mln_test_data_ptr), msg, expected, actual_value, format, assert_failed, stop_test_on_fail, (&mln_stop_test))\
                if(mln_stop_test){\
                    return;\
                }\
            }\
        }

    //used only in tests
    #define MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_test_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)\
        {\
            bool mln_mem_correct = equality;\
            for(size_t mln_i = 0; mln_i < size; ++mln_i){\
                const unsigned char expected_byte = (unsigned char)expected[mln_i];\
                const unsigned char actual_byte = (unsigned char)actual[mln_i];\
                \
                const bool mln_equal_bytes = expected_byte == actual_byte;\
                if(!mln_equal_bytes){\
                    mln_mem_correct = !equality;\
                    break;\
                }\
            }\
                \
            if(mln_mem_correct){\
                (mln_test_data_ptr)->last_test.passes++;\
            }else{\
                (mln_test_data_ptr)->last_test.fails++;\
                MLN_ADD_LOGS(mln_test_data_ptr, msg)\
                MLN_PRINTF_DEFAULT_MESSAGE(mln_test_data_ptr, FAIL, assert_failed)\
                MLN_PRINTF(mln_test_data_ptr, "0x[Expected]  @@  0x[Actual]\n");\
                for(size_t mln_i = 0; mln_i < size; ++mln_i){\
                    const unsigned char expected_byte = (unsigned char)expected[mln_i];\
                    const unsigned char actual_byte = (unsigned char)actual[mln_i];\
                    \
                    bool mln_is_byte_correct;\
                    if(equality){\
                        mln_is_byte_correct = expected_byte == actual_byte;\
                    }else{\
                        mln_is_byte_correct = expected_byte != actual_byte;\
                    }\
                    MLN_PRINTF(mln_test_data_ptr, "%zu.  %#04hhx%s%#04hhx\n", mln_i, expected_byte, mln_is_byte_correct ? "    " : (equality ? " != " : " == "), actual_byte)\
                }\
                if(stop_test_on_fail){\
                    *stop_test_ptr = true;\
                    return;\
                }\
            }\
        }

    //used only in main
    #define MLN_RUN_TEST_IMPLEMENTATION(mln_test_data_ptr, in_func_ptr, in_func_name_text) \
        {\
            (mln_test_data_ptr)->last_func.func_ptr = in_func_ptr;\
            (mln_test_data_ptr)->last_func.func_name = in_func_name_text;\
            if((mln_test_data_ptr)->verbosity >= HIGH){\
                MLN_PRINTF(mln_test_data_ptr, "Testing n.%zu function [%s]...\n", MLN_GET_TOTAL_TESTS(mln_test_data_ptr, ->), (mln_test_data_ptr)->last_func.func_name);\
            }\
            \
            const clock_t mln_current_test_start_time = clock();\
            (mln_test_data_ptr)->last_func.func_ptr((mln_test_data_ptr));\
            (mln_test_data_ptr)->time.last_recorded_time = clock();\
            ((mln_test_data_ptr)->time.total_tests_time) += (mln_test_data_ptr)->time.last_recorded_time - mln_current_test_start_time;\
            \
            ((mln_test_data_ptr)->stats.asserts.passes) += (mln_test_data_ptr)->last_test.passes;\
            ((mln_test_data_ptr)->stats.asserts.skips) += (mln_test_data_ptr)->last_test.skips;\
            ((mln_test_data_ptr)->stats.asserts.fails) += (mln_test_data_ptr)->last_test.fails;\
            ((mln_test_data_ptr)->stats.asserts.unspecified) += (mln_test_data_ptr)->last_test.unspecified;\
            if((mln_test_data_ptr)->last_test.fails != 0){\
                ((mln_test_data_ptr)->stats.tests.fails)++;\
            }else if((mln_test_data_ptr)->last_test.skips != 0){\
                ((mln_test_data_ptr)->stats.tests.skips)++;\
            }else if((mln_test_data_ptr)->last_test.passes != 0){\
                ((mln_test_data_ptr)->stats.tests.passes)++;\
            }else{\
                ((mln_test_data_ptr)->stats.tests.unspecified)++;\
            }\
            \
            if(((mln_test_data_ptr)->last_test.fails != 0 && (mln_test_data_ptr)->verbosity >= NONE) || (mln_test_data_ptr)->verbosity >= HIGH){\
                MLN_PRINTF(mln_test_data_ptr, "Passes count: %zu, skips count: %zu, fails count: %zu, unspecified count: %zu\n", (mln_test_data_ptr)->last_test.passes, (mln_test_data_ptr)->last_test.skips, (mln_test_data_ptr)->last_test.fails, (mln_test_data_ptr)->last_test.unspecified);\
                (mln_test_data_ptr)->last_test.printed_logs = true;\
            }\
            if((mln_test_data_ptr)->verbosity >= HIGH){\
                (mln_test_data_ptr)->time.clocks_per_sec = CLOCKS_PER_SEC;\
                MLN_PRINTF(mln_test_data_ptr, "Estimated elapsed seconds: %.6Lf\n", (long double)((mln_test_data_ptr)->time.last_recorded_time - mln_current_test_start_time) / ((mln_test_data_ptr)->time.clocks_per_sec));\
                (mln_test_data_ptr)->last_test.printed_logs = true;\
            }\
            if((mln_test_data_ptr)->last_test.printed_logs){\
                MLN_PRINTF(mln_test_data_ptr, "\n");\
            }\
            (mln_test_data_ptr)->last_test.passes = 0;\
            (mln_test_data_ptr)->last_test.fails = 0;\
            (mln_test_data_ptr)->last_test.skips = 0;\
            (mln_test_data_ptr)->last_test.unspecified = 0;\
            (mln_test_data_ptr)->last_test.printed_logs = false;\
        }

    //used only in main
    #define MLN_RUN_SUITE_IMPLEMENTATION(mln_test_data_ptr, in_suite_name_ptr, in_suite_name)\
        {\
            if((mln_test_data_ptr)->verbosity >= HIGH){\
                printf("Testing suite [%s]...\n\n", in_suite_name);\
            }\
            mln_tests_results_t mln_suite_data = { .asserts = { .passes = mln_test_data_ptr->stats.asserts.passes, .fails = mln_test_data_ptr->stats.asserts.fails, .skips = mln_test_data_ptr->stats.asserts.skips, .unspecified = mln_test_data_ptr->stats.asserts.unspecified, .printed_logs = false},\
                                                    .tests = { .passes = mln_test_data_ptr->stats.tests.passes, .fails = mln_test_data_ptr->stats.tests.fails, .skips = mln_test_data_ptr->stats.tests.skips, .unspecified = mln_test_data_ptr->stats.tests.unspecified, .printed_logs = false}};\
            const clock_t mln_current_test_start_time = clock();\
            in_suite_name_ptr((mln_test_data_ptr));\
            (mln_test_data_ptr)->time.last_recorded_time = clock();\
            \
            if((mln_test_data_ptr)->verbosity >= HIGH){\
                printf("Testing suite [%s] completed!\n", in_suite_name);\
                const size_t mln_total_results = MLN_GET_TOTAL_ASSERTS(mln_test_data_ptr, ->) - (mln_suite_data.asserts.passes + mln_suite_data.asserts.skips + mln_suite_data.asserts.fails + mln_suite_data.asserts.unspecified);\
                const size_t mln_total_test_results = MLN_GET_TOTAL_TESTS(mln_test_data_ptr, ->) - (mln_suite_data.tests.passes + mln_suite_data.tests.skips + mln_suite_data.tests.fails + mln_suite_data.tests.unspecified);\
                (mln_test_data_ptr)->time.clocks_per_sec = CLOCKS_PER_SEC;\
                printf("Tests passed: %zu/%zu. Total asserts passed: %zu/%zu\n", (mln_test_data_ptr)->stats.tests.passes - mln_suite_data.tests.passes, mln_total_test_results, (mln_test_data_ptr)->stats.asserts.passes - mln_suite_data.asserts.passes, mln_total_results);\
                printf("Tests skiped: %zu/%zu. Total asserts skipped: %zu/%zu\n", (mln_test_data_ptr)->stats.tests.skips - mln_suite_data.tests.skips, mln_total_test_results, (mln_test_data_ptr)->stats.asserts.skips - mln_suite_data.asserts.skips, mln_total_results);\
                printf("Tests failed: %zu/%zu. Total asserts failed: %zu/%zu\n", (mln_test_data_ptr)->stats.tests.fails - mln_suite_data.tests.fails, mln_total_test_results, (mln_test_data_ptr)->stats.asserts.fails - mln_suite_data.asserts.fails, mln_total_results);\
                printf("Tests unspecified: %zu/%zu. Total asserts unspecified: %zu/%zu\n", (mln_test_data_ptr)->stats.tests.unspecified - mln_suite_data.tests.unspecified, mln_total_test_results, (mln_test_data_ptr)->stats.asserts.unspecified - mln_suite_data.asserts.unspecified, mln_total_results);\
                printf("Approximate seconds elapsed in total: %.6Lf\n\n", (long double)((mln_test_data_ptr)->time.last_recorded_time - mln_current_test_start_time) / (mln_test_data_ptr)->time.clocks_per_sec); \
            }\
        }

    //used only in tests
    #define MLN_FAILm_IMPLEMENTATION_GENERIC(mln_test_data_ptr, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) \
        {\
            (mln_test_data_ptr)->last_test.fails++;\
            MLN_ADD_LOGS(mln_test_data_ptr, msg) \
            MLN_PRINTF_DEFAULT_MESSAGE(mln_test_data_ptr, FAIL, assert_failed)\
            const char* mln_format_string = format;\
            size_t mln_format_size;\
            MLN_GET_CHAR_ARRAY_LENGTH(mln_format_string, (&mln_format_size))\
            if(mln_format_size >= 2){\
                MLN_PRINTF(mln_test_data_ptr, "Expected [")\
                MLN_PRINTF(mln_test_data_ptr, mln_format_string, expected)\
                MLN_PRINTF(mln_test_data_ptr, "] Actual [")\
                MLN_PRINTF(mln_test_data_ptr, mln_format_string, actual)\
                MLN_PRINTF(mln_test_data_ptr, "]")\
            }\
            MLN_PRINTF(mln_test_data_ptr, "\n")\
            if(stop_test_on_fail){\
                *stop_test_ptr = true;\
                return;\
            }\
        }

    //used only in tests
    #define MLN_SKIPm_IMPLEMENTATION(msg, mln_test_data_ptr, assert_failed)\
        (mln_test_data_ptr)->last_test.skips++;\
        if((mln_test_data_ptr)->verbosity >= MEDIUM){\
            MLN_ADD_LOGS(mln_test_data_ptr, msg) \
            MLN_PRINTF_DEFAULT_MESSAGE(mln_test_data_ptr, SKIP, assert_failed)\
        }\
        return;

    //used only in tests
    #define MLN_PASS_IMPLEMENTATION(mln_test_data_ptr)\
        (mln_test_data_ptr)->last_test.passes++;\
        return;

    //used only in main
    #define MLN_SET_LOGS_VERBOSITY_IMPLEMENTATION(mln_test_data_ptr, in_verbosity)\
        switch(in_verbosity){\
            case  MINIMUM:\
                (mln_test_data_ptr)->verbosity = MINIMUM;\
                break;\
            case  LOW:\
                (mln_test_data_ptr)->verbosity = LOW;\
                break;\
            case  MEDIUM:\
                (mln_test_data_ptr)->verbosity = MEDIUM;\
                break;\
            case  HIGH:\
                (mln_test_data_ptr)->verbosity = HIGH;\
                break;\
            default:\
                (mln_test_data_ptr)->verbosity = (in_verbosity < LOW) ? LOW : HIGH;\
        }


    //used only in defining test functions
    #define MLN_TEST_IMPLEMENTATION(full_func_name, ...)\
        void full_func_name##(mln_run_test_data_t* mln_test_data_ptr){\
            (mln_test_data_ptr)->last_func.code_line = __LINE__;\
            (mln_test_data_ptr)->last_func.file_name = __FILE__;\
            __VA_ARGS__ \
        }

    //used only in main
    #define MLN_PRE_TESTS_IMPLEMENTATION \
        const clock_t mln_internal_starting_clock_time = clock();\
        mln_run_test_data_t mln_testing_data = {\
            .last_func = { .func_ptr = NULL, .func_name = NULL, .file_name = NULL, .code_line = 0},\
            .last_test = { .passes = 0, .fails = 0, .skips = 0, .unspecified = 0, .printed_logs = false},\
            .stats = { .asserts = { .passes = 0, .fails = 0, .skips = 0, .unspecified = 0, .printed_logs = false}, .tests = { .passes = 0, .fails = 0, .skips = 0, .unspecified = 0, .printed_logs = false}},\
            .time = { .start_time = mln_internal_starting_clock_time, .last_recorded_time = mln_internal_starting_clock_time, .clocks_per_sec = CLOCKS_PER_SEC, .total_tests_time = 0},\
            .verbosity = HIGH};\
        mln_run_test_data_t* mln_test_data_ptr = &mln_testing_data;

    //used only in main
    #define MLN_POST_TESTS_IMPLEMENTATION(wait_input)        \
        const size_t mln_total_results = MLN_GET_TOTAL_ASSERTS(mln_testing_data, .);\
        const size_t mln_total_test_results = MLN_GET_TOTAL_TESTS(mln_testing_data, .);\
        printf("Tests over. Results...\n");\
        printf("Tests passed: %zu/%zu. Total asserts passed: %zu/%zu\n", mln_testing_data.stats.tests.passes, mln_total_test_results, mln_testing_data.stats.asserts.passes, mln_total_results);\
        printf("Tests skiped: %zu/%zu. Total asserts skipped: %zu/%zu\n", mln_testing_data.stats.tests.skips, mln_total_test_results, mln_testing_data.stats.asserts.skips, mln_total_results);\
        printf("Tests failed: %zu/%zu. Total asserts failed: %zu/%zu\n", mln_testing_data.stats.tests.fails, mln_total_test_results, mln_testing_data.stats.asserts.fails, mln_total_results);\
        printf("Tests unspecified: %zu/%zu. Total asserts unspecified: %zu/%zu\n", mln_testing_data.stats.tests.unspecified, mln_total_test_results, mln_testing_data.stats.asserts.unspecified, mln_total_results);\
        const long double mln_final_test_failed_perc = mln_total_test_results == 0 ? 0 : ((long double)(mln_testing_data.stats.tests.fails) / mln_total_test_results) * 100.0;\
        const long double mln_final_assert_failed_perc = mln_total_results == 0 ? 0 : ((long double)(mln_testing_data.stats.asserts.fails) / mln_total_results) * 100.0;\
        printf("Tests failed percentage: %.6Lf%%, Asserts failed percentage: %.6Lf%% \n", mln_final_test_failed_perc, mln_final_assert_failed_perc);\
        \
        mln_testing_data.time.last_recorded_time = clock();\
        mln_testing_data.time.clocks_per_sec = CLOCKS_PER_SEC;\
        printf("Approximate seconds elapsed in tests: %.6Lf, approximate seconds elapsed in total: %.6Lf\n", \
        (long double)(mln_testing_data.time.total_tests_time) / mln_testing_data.time.clocks_per_sec,\
        (long double)(mln_testing_data.time.last_recorded_time - mln_testing_data.time.start_time) / mln_testing_data.time.clocks_per_sec); \
        if(wait_input){\
            printf("Press any keys to close...\n");\
            getchar();\
        }

    #define MLN_GET_TOTAL_ASSERTS(mln_testing_data, operator)  (mln_testing_data##operator##stats.asserts.passes + mln_testing_data##operator##stats.asserts.fails + mln_testing_data##operator##stats.asserts.skips + mln_testing_data##operator##stats.asserts.unspecified)
    #define MLN_GET_TOTAL_TESTS(mln_testing_data, operator)  (mln_testing_data##operator##stats.tests.passes + mln_testing_data##operator##stats.tests.fails + mln_testing_data##operator##stats.tests.skips + mln_testing_data##operator##stats.tests.unspecified)
    #define MLN_GET_LOCAL_ASSERTS(mln_testing_data, operator)  (mln_testing_data##operator##last_test.passes + mln_testing_data##operator##last_test.fails + mln_testing_data##operator##last_test.skips + mln_testing_data##operator##last_test.unspecified)

    #define MLN_PRINTF(mln_test_data_ptr, ...) \
        (mln_test_data_ptr)->last_test.printed_logs = true;\
        printf(__VA_ARGS__);

    #define MLN_PRINTF_DEFAULT_MESSAGE_IMPLEMENTATION(mln_test_data_ptr, default_msg_type, assert_name)\
    switch(default_msg_type){\
        case FAIL:\
            if((mln_test_data_ptr)->verbosity >= MINIMUM){\
                MLN_PRINTF(mln_test_data_ptr, "Assert n.%zu %s failed in file %s, function: %s at line %d.\n", MLN_GET_LOCAL_ASSERTS(mln_test_data_ptr, ->), assert_name, (mln_test_data_ptr)->last_func.file_name, (mln_test_data_ptr)->last_func.func_name, (mln_test_data_ptr)->last_func.code_line)\
            }\
            break;\
        case SKIP:\
            if((mln_test_data_ptr)->verbosity >= MEDIUM){\
                MLN_PRINTF(mln_test_data_ptr, "Assert n.%zu %s skipped in file %s, function: %s at line %d.\n", MLN_GET_LOCAL_ASSERTS(mln_test_data_ptr, ->), assert_name, (mln_test_data_ptr)->last_func.file_name, (mln_test_data_ptr)->last_func.func_name, (mln_test_data_ptr)->last_func.code_line)\
            }\
            break;\
        case NONE:\
        default:\
            break;\
    }
#endif

#endif