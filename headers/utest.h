#pragma once
#ifndef H_MLN_TESTS_UTEST_H_
#define H_MLN_TESTS_UTEST_H_

#include "internal_utest.h"

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
    0 = only minimum fails logs
    1 = fails logs, minimum skip and pass logs
    2 = all logs
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


#endif