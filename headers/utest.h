#pragma once
#ifndef _H_MLN_TESTS_UTEST_H_
#define _H_MLN_TESTS_UTEST_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "internal_utest.h"

typedef struct test_data{
    size_t passes;
    size_t fails;
    size_t skips;
    char* logs;
    size_t logs_size;
    size_t logs_length;
} mln_test_data;

/*If MLN_REMOVE_TESTS_PREFIXES is defined it exposes test macro variants without the MLN_ prefix*/
#ifdef MLN_REMOVE_TESTS_PREFIXES

    #define SET_LOGS_VERBOSITY(verbosity) MLN_SET_LOGS_VERBOSITY(verbosity)
    #define PRE_TESTS MLN_PRE_TESTS
    #define POST_TESTS MLN_POST_TESTS
    #define RUN_TEST(func_name) MLN_RUN_TEST(func_name)
    #define TEST(func_name, ...) MLN_TEST(func_name, __VA_ARGS__)
    #define FAIL() MLN_FAIL()
    #define FAILm(msg, expected, actual, format, assert_failed) MLN_FAILm(msg, expected, actual, format, assert_failed)
    #define PASS() MLN_PASS()
    #define SKIP() MLN_SKIP()
    #define SKIPm(msg) MLN_SKIPm(msg)
    #define ASSERT(condition) MLN_ASSERT(condition)
    #define ASSERTm(condition, msg) MLN_ASSERTm(condition, msg)
    #define ASSERT_FALSE(condition) MLN_ASSERT_FALSE(condition)
    #define ASSERT_FALSEm(condition, msg) MLN_ASSERT_FALSEm(condition, msg) 
    #define ASSERT_EQ(expected, actual_value) MLN_ASSERT_EQ(expected, actual_value) 
    #define ASSERT_EQm(expected, actual_value, msg) MLN_ASSERT_EQm(expected, actual_value, msg)
    #define ASSERT_EQ_FORMAT(expected, actual_value, format) MLN_ASSERT_EQ_FORMAT(expected, actual_value, format)
    #define ASSERT_EQ_FORMATm(expected, actual_value, format, msg) MLN_ASSERT_EQ_FORMATm(expected, actual_value, format, msg)
    #define ASSERT_NEQ(expected, actual_value) MLN_ASSERT_NEQ(expected, actual_value)
    #define ASSERT_NEQm(expected, actual_value, msg) MLN_ASSERT_NEQm(expected, actual_value, msg)
    #define ASSERT_GT(expected, actual_value) MLN_ASSERT_GT(expected, actual_value)
    #define ASSERT_GTm(expected, actual_value, msg) MLN_ASSERT_GTm(expected, actual_value, msg)
    #define ASSERT_GTE(expected, actual_value) MLN_ASSERT_GTE(expected, actual_value)
    #define ASSERT_GTEm(expected, actual_value, msg) MLN_ASSERT_GTEm(expected, actual_value, msg)
    #define ASSERT_LT(expected, actual_value) MLN_ASSERT_LT(expected, actual_value)
    #define ASSERT_LTm(expected, actual_value, msg) MLN_ASSERT_LTm(expected, actual_value, msg)
    #define ASSERT_LTE(expected, actual_value) MLN_ASSERT_LTE(expected, actual_value)
    #define ASSERT_LTEm(expected, actual_value, msg) MLN_ASSERT_LTEm(expected, actual_value, msg)
    #define ASSERT_IN_RANGE(expected, actual_value, tollerance) MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance)
    #define ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg) MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg)
    #define ASSERT_STRN_EQ(expected, actual_value, size) MLN_ASSERT_STRN_EQ(expected, actual_value, size) 
    #define ASSERT_STRN_EQm(expected, actual_value, size, msg) MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg)
    #define ASSERT_STRN_NEQ(expected, actual_value, size) MLN_ASSERT_STRN_NEQ(expected, actual_value, size)
    #define ASSERT_STRN_NEQm(expected, actual_value, size, msg) MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg)
    #define ASSERT_STRN_GT(expected, actual_value, size) MLN_ASSERT_STRN_GT(expected, actual_value, size)
    #define ASSERT_STRN_GTm(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg)
    #define ASSERT_STRN_GTE(expected, actual_value, size) MLN_ASSERT_STRN_GTE(expected, actual_value, size)
    #define ASSERT_STRN_GTEm(expected, actual_value, size, msg) MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg)
    #define ASSERT_STRN_LT(expected, actual_value, size) MLN_ASSERT_STRN_LT(expected, actual_value, size)
    #define ASSERT_STRN_LTm(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg)
    #define ASSERT_STRN_LTE(expected, actual_value, size) MLN_ASSERT_STRN_LTE(expected, actual_value, size)
    #define ASSERT_STRN_LTEm(expected, actual_value, size, msg) MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg)
    #define ASSERT_STR_EQ(expected, actual_value) MLN_ASSERT_STR_EQ(expected, actual_value) 
    #define ASSERT_STR_EQm(expected, actual_value, msg) MLN_ASSERT_STR_EQm(expected, actual_value, msg)
    #define ASSERT_STR_NEQ(expected, actual_value) MLN_ASSERT_STR_NEQ(expected, actual_value)
    #define ASSERT_STR_NEQm(expected, actual_value, msg) MLN_ASSERT_STR_NEQm(expected, actual_value, msg)
    #define ASSERT_STR_GT(expected, actual_value) MLN_ASSERT_STR_GT(expected, actual_value)
    #define ASSERT_STR_GTm(expected, actual_value, msg) MLN_ASSERT_STR_GTm(expected, actual_value, msg)
    #define ASSERT_STR_GTE(expected, actual_value) MLN_ASSERT_STR_GTE(expected, actual_value)
    #define ASSERT_STR_GTEm(expected, actual_value, msg) MLN_ASSERT_STR_GTEm(expected, actual_value, msg)
    #define ASSERT_STR_LT(expected, actual_value) MLN_ASSERT_STR_LT(expected, actual_value)
    #define ASSERT_STR_LTm(expected, actual_value, msg) MLN_ASSERT_STR_LTm(expected, actual_value, msg)
    #define ASSERT_STR_LTE(expected, actual_value) MLN_ASSERT_STR_LTE(expected, actual_value)
    #define ASSERT_STR_LTEm(expected, actual_value, msg) MLN_ASSERT_STR_LTEm(expected, actual_value, msg)
    
#endif

/*
To be used once at the beginning of the function/main where all the tests will be performed
Starting point of the testing procedure
*/
#define MLN_PRE_TESTS           \
    const clock_t __mln_start_time = clock();\
    size_t __mln_verbosity = 0;\
    size_t __mln_total_passes = 0;\
    size_t __mln_total_fails = 0;\
    size_t __mln_total_skips = 0;\
    size_t __mln_current_test_count = 0;\
    size_t __mln_total_test_passes = 0;\
    size_t __mln_total_test_fails = 0;\
    size_t __mln_total_test_skips = 0;\
    mln_test_data __mln_data;\
    __mln_data.logs = NULL;\
    __MLN_RESET_DATA(__mln_data) 

/*
To be used once at the end of the function/main where all the tests will be performed
Ending point of the testing procedure
*/
#define MLN_POST_TESTS          \
    const size_t __mln_total_results = __mln_total_passes + __mln_total_fails + __mln_total_skips;\
    const size_t __mln_total_test_results = __mln_total_test_passes + __mln_total_test_fails + __mln_total_test_skips;\
    const clock_t __mln_end_time = clock();\
    printf("Tests over. Results...\n");\
    printf("Tests passed: %zu/%zu. Total asserts passed: %zu/%zu\n", __mln_total_test_passes, __mln_total_test_results, __mln_total_passes, __mln_total_results);\
    printf("Tests skiped: %zu/%zu. Total asserts skipped: %zu/%zu\n", __mln_total_test_skips, __mln_total_test_results, __mln_total_skips, __mln_total_results);\
    printf("Tests failed: %zu/%zu. Total asserts failed: %zu/%zu\n", __mln_total_test_fails, __mln_total_test_results, __mln_total_fails, __mln_total_results);\
    printf("Tests failed percentage: %Lf%%, Asserts failed percentage: %Lf%% \n", \
    ((long double)(__mln_total_test_fails) / __mln_total_test_results) * 100.0, \
    ((long double)(__mln_total_fails) / __mln_total_results) * 100.0);\
    printf("Approximate seconds elapsed: %.3lf\n", (double)(__mln_end_time - __mln_start_time) / CLOCKS_PER_SEC);\
    printf("Press any keys to close...\n");\
    getchar();

/*
To be used when performing the tests. The func_name must have a matching MLN_TEST(func_name)
MLN_PRE_TESTS must appear once before any tests can be executed
*/
#define MLN_RUN_TEST(func_name) \
    {\
    if(__mln_verbosity >= 2){\
        printf("Testing n.%zu function [%s]...\n", __mln_current_test_count + 1, #func_name);\
    }\
    \
    const clock_t __mln_current_test_start_time = clock();\
    __mln_test_##func_name(&__mln_data, __mln_verbosity);\
    const clock_t __mln_current_test_end_time = clock();\
    \
    __mln_current_test_count++;\
    __mln_total_passes += __mln_data.passes;\
    __mln_total_skips += __mln_data.skips;\
    __mln_total_fails += __mln_data.fails;\
    if(__mln_data.fails != 0){\
        __mln_total_test_fails++;\
    }else if(__mln_data.skips != 0){\
        __mln_total_test_skips++;\
    }else if(__mln_data.passes != 0){\
        __mln_total_test_passes++;\
    }\
    \
    bool __mln_logs_used = false;\
    if(__mln_data.logs_length > 0){\
        printf("%s\nEstimated elapsed seconds: %.3lf\n", __mln_data.logs, (double)(__mln_current_test_end_time - __mln_current_test_start_time) / CLOCKS_PER_SEC);\
        __mln_logs_used = true;\
    }\
    if(__mln_data.fails != 0 && __mln_verbosity > 0){\
        printf("Passes count: %zu, skips count: %zu, fails count: %zu\n", __mln_data.passes, __mln_data.skips, __mln_data.fails);\
        __mln_logs_used = true;\
    }\
    if(__mln_logs_used){\
        printf("\n");\
    }\
    __MLN_RESET_DATA(__mln_data)\
    }

/*
To be used to define test functions. The arguments are the function name and the body of the function.
Example:
MLN_DEFINE_TEST(my_test,
    int a = 0;
    int b = 0;
    MLN_ASSERT_EQ(a, 0)
    MLN_ASSERT_NEQ(b, 1)
)
*/
#define MLN_TEST(func_name, ...) \
    void __mln_test_##func_name(mln_test_data* __mln_out_test_data, const size_t __mln_verbosity){\
    __VA_ARGS__\
    }

/*
Sets the level of verbosity of the tests logs. 
0 = only minimum fails logs
1 = fails logs, minimum skip and pass logs
2 = all logs
verbosity might be evaluated multiple times in this macro
MLN_PRE_TESTS must appear once before this MACRO can be used
*/
#define MLN_SET_LOGS_VERBOSITY(verbosity)\
    if(verbosity <= 0){\
        __mln_verbosity = 0;\
    }else if(verbosity >= 2){\
        __mln_verbosity = 2;\
    }else{\
        __mln_verbosity = 1;\
    }

//
//BYPASSES
//

/*All Bypasses must be used inside a MLN_TEST*/

/*
Can be used inside a test, will automatically fail the current test and stop the execution
*/
#define MLN_FAIL() \
    MLN_FAILm(__MLN_DEFAULT_FAIL_MSG, "Fail", "Fail", "%s", ##MLN_FAIL)

#define MLN_FAILm(msg, expected, actual, format, assert_failed) \
    {\
    __mln_out_test_data->fails++;\
    __MLN_ADD_LOGS(__mln_out_test_data->logs, __mln_out_test_data->logs_length, __mln_out_test_data->logs_size, msg) \
    const char* __mln_format_string = format;\
    const size_t __mln_format_size = sizeof __mln_format_string;\
    printf(#assert_failed " failed! ");\
    if(__mln_format_size >= 2 && __mln_verbosity > 0)\
    {\
        printf("Expected [");\
        printf(__mln_format_string, expected);\
        printf("] Actual [");\
        printf(__mln_format_string, actual);\
        printf("]");\
    }\
    printf("\n");\
    }\
    return;

/*
Can be used inside a test, will automatically pass the current test and stop the execution
*/
#define MLN_PASS() \
    __mln_out_test_data->passes++;\
    return;

/*
Can be used inside a test, will automatically skip the current test and stop the execution
*/
#define MLN_SKIP() \
    MLN_SKIPm(__MLN_DEFAULT_SKIP_MSG)

#define MLN_SKIPm(msg) \
    __mln_out_test_data->skips++;\
    if(__mln_verbosity > 0){\
        __MLN_ADD_LOGS(__mln_out_test_data->logs, __mln_out_test_data->logs_length, __mln_out_test_data->logs_size, msg) \
    }\
    return;
//
//ASSERTS
//

/*Failing an assertion will stop the execution of the current test and will result in a failed test. 
All assertions have a message variant, which logs a string message in case of a fail.
All Assertions must be used inside a MLN_TEST*/

/*
Assert that condition evaluates as a true value (non zero)
*/
#define MLN_ASSERT(condition)   \
    MLN_ASSERTm(condition, __MLN_DEFAULT_FAIL_MSG) 

#define MLN_ASSERTm(condition, msg)   \
    {\
    const bool __mln_result = condition;\
    if(__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, "true", __mln_result ? "true" : "false", "%s", ##MLN_ASSERT) \
    }\
    }

/*
Assert that condition evaluates as a false value (zero)
*/
#define MLN_ASSERT_FALSE(condition)   \
    MLN_ASSERT_FALSEm(condition, __MLN_DEFAULT_FAIL_MSG) 

#define MLN_ASSERT_FALSEm(condition, msg)   \
    {\
    const bool __mln_result = condition;\
    if(!__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, "false", __mln_result ? "true" : "false", "%s", ##MLN_ASSERT_FALSE) \
    }\
    }

/*
Assert that expected == actual_value
*/
#define MLN_ASSERT_EQ(expected, actual_value)   \
    MLN_ASSERT_EQm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) 

#define MLN_ASSERT_EQm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, ==, ##MLN_ASSERT_EQ)

/*
Assert that expected == actual_value, if they are not equal then the 2 arguments will be printed out based on the given format (printf)
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_EQ_FORMAT(expected, actual_value, format)   \
    MLN_ASSERT_EQ_FORMATm(expected, actual_value, format, __MLN_DEFAULT_FAIL_MSG) 

#define MLN_ASSERT_EQ_FORMATm(expected, actual_value, format, msg)   \
    {\
    const bool __mln_result = expected == actual_value;\
    if(__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, expected, actual_value, format, ##MLN_ASSERT_EQ_FORMAT) \
    }\
    }

/*
Assert that expected != actual_value
*/
#define MLN_ASSERT_NEQ(expected, actual_value)   \
    MLN_ASSERT_NEQm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) 

#define MLN_ASSERT_NEQm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, !=, ##MLN_ASSERT_NEQ)
    
/*
Assert that expected > actual_value
*/
#define MLN_ASSERT_GT(expected, actual_value)   \
    MLN_ASSERT_GTm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_GTm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, >, ##MLN_ASSERT_GT)

/*
Assert that expected >= actual_value
*/
#define MLN_ASSERT_GTE(expected, actual_value)   \
    MLN_ASSERT_GTEm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_GTEm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, >=, ##MLN_ASSERT_GTE)

/*
Assert that expected < actual_value
*/
#define MLN_ASSERT_LT(expected, actual_value)   \
    MLN_ASSERT_LTm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_LTm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, <, ##MLN_ASSERT_LT)

/*
Assert that expected <= actual_value
*/
#define MLN_ASSERT_LTE(expected, actual_value)   \
    MLN_ASSERT_LTEm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_LTEm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, <=, ##MLN_ASSERT_LTE)

/*
Assert that expected - tollerance <= actual_value <= expected + tollerance
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance)   \
    MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg)   \
    {\
    const bool __mln_result = (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value);\
    if(__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, #expected, #actual_value, "%s", ##MLN_ASSERT_IN_RANGE) \
    }\
    }

/*
Assert that the first size bytes of the strings are equal (strncmp(expected, actual_value, size) == 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_EQ(expected, actual_value, size)   \
    MLN_ASSERT_STRN_EQm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, ==, ##MLN_ASSERT_STRN_EQ)

/*
Assert that the first size bytes of the strings are not equal (strncmp(expected, actual_value, size) != 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_NEQ(expected, actual_value, size)   \
    MLN_ASSERT_STRN_NEQm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, !=, ##MLN_ASSERT_STRN_NEQ)

/*
Assert that the first size bytes of the expected string comes lexicographically after the first size bytes of the actual string (strncmp(expected, actual_value, size) > 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_GT(expected, actual_value, size)   \
    MLN_ASSERT_STRN_GTm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, >, ##MLN_ASSERT_STRN_GT)

/*
Assert that the first size bytes of the expected string is either equal or comes lexicographically after the first size bytes of the actual string (strncmp(expected, actual_value, size) >= 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_GTE(expected, actual_value, size)   \
    MLN_ASSERT_STRN_GTEm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, >=, ##MLN_ASSERT_STRN_GTE)

/*
Assert that the first size bytes of the expected string comes lexicographically before the first size bytes of the actual string (strncmp(expected, actual_value, size) < 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_LT(expected, actual_value, size)   \
    MLN_ASSERT_STRN_LTm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, <, ##MLN_ASSERT_STRN_LT)

/*
Assert that the first size bytes of the expected string is either equal or comes lexicographically before the first size bytes of the actual string (strncmp(expected, actual_value, size) <= 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STRN_LTE(expected, actual_value, size)   \
    MLN_ASSERT_STRN_LTEm(expected, actual_value, size, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg)   \
    __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, <=, ##MLN_ASSERT_STRN_LTE)

/*
Assert that the first string is equal to the second (strcmp(expected, actual_value) == 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_EQ(expected, actual_value)   \
    MLN_ASSERT_STR_EQm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_EQm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, ==, ##MLN_ASSERT_STR_EQ)

/*
Assert that the first string is not equal to the second (strcmp(expected, actual_value) != 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_NEQ(expected, actual_value)   \
    MLN_ASSERT_STR_NEQm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_NEQm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, !=, ##MLN_ASSERT_STR_NEQ)

/*
Assert that the expected string comes lexicographically after the actual string (strcmp(expected, actual_value) > 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_GT(expected, actual_value)   \
    MLN_ASSERT_STR_GTm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_GTm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, >, ##MLN_ASSERT_STR_GT)

/*
Assert that the expected string is either equal or comes lexicographically after the actual string (strcmp(expected, actual_value) >= 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_GTE(expected, actual_value)   \
    MLN_ASSERT_STR_GTEm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_GTEm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, >=, ##MLN_ASSERT_STR_GTE)

/*
Assert that the expected string comes lexicographically before the actual string (strcmp(expected, actual_value) < 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_LT(expected, actual_value)   \
    MLN_ASSERT_STR_LTm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_LTm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, <, ##MLN_ASSERT_STR_LT)

/*
Assert that the expected string is either equal or comes lexicographically before the actual string (strcmp(expected, actual_value) <= 0).
Expected and actual_value might be evaluated more than once
*/
#define MLN_ASSERT_STR_LTE(expected, actual_value)   \
    MLN_ASSERT_STR_LTEm(expected, actual_value, __MLN_DEFAULT_FAIL_MSG) \

#define MLN_ASSERT_STR_LTEm(expected, actual_value, msg)   \
    __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, <=, ##MLN_ASSERT_STR_LTE)


/*

TODO

ASSERT_MEM_EQ(EXPECTED, ACTUAL, SIZE)
Assert that the first SIZE bytes of memory pointed to by EXPECTED and ACTUAL are equal. If their memory differs, print a hexdump and highlight the lines and individual bytes which do not match.

ASSERT_EQUAL_T(EXPECTED, ACTUAL, TYPE_INFO, UDATA)
Assert that EXPECTED and ACTUAL are equal, using the greatest_equal_cb function pointed to by TYPE_INFO->equal to compare them. The assertion's UDATA argument can be used to pass in arbitrary user data (or NULL) to the callbacks. If the values are not equal and the TYPE_INFO->print function is defined, it will be used to print an "Expected: X, Got: Y" message.

Add define based logic where if MLN_REDUCE_MACROS_TO_FUNCTIONS is defined we add internal functions for test macros (to reduce exe size by calling functions instead of only using macros)
The functions will be for 'internal' usage, the end user will still use the MACROS from this file
*/

#endif