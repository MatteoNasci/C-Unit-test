#pragma once
#ifndef H_MLN_TESTS_INTERNAL_UTEST_H_
#define H_MLN_TESTS_INTERNAL_UTEST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*
Collection of internal defines/functions, not designed to be used by the final user
*/

typedef struct test_data{
    size_t passes;
    size_t fails;
    size_t skips;
    char* logs;
    size_t logs_size;
    size_t logs_length;
} mln_test_data;

typedef struct test_results{
    size_t total_passes;
    size_t total_fails;
    size_t total_skips;
    size_t current_test_count;
    size_t total_test_passes;
    size_t total_test_fails;
    size_t total_test_skips;
} mln_test_results;

#define MLN_STRINGIFY(A) #A
#define MLN_STRINGIFY_NX(A) MLN_STRINGIFY(A)
#define MLN_DEFAULT_FAIL_MSG MLN_DEFAULT_FAIL_MSG_C
#define MLN_DEFAULT_FAIL_MSG_C MLN_DEFAULT_FAIL_MSG_A MLN_DEFAULT_FAIL_MSG_B
#define MLN_DEFAULT_FAIL_MSG_A "Failed in " __FILE__ 
#define MLN_DEFAULT_FAIL_MSG_B " at line " MLN_STRINGIFY_NX(__LINE__)

#define MLN_DEFAULT_SKIP_MSG MLN_DEFAULT_SKIP_MSG_C
#define MLN_DEFAULT_SKIP_MSG_C MLN_DEFAULT_SKIP_MSG_A MLN_DEFAULT_SKIP_MSG_B
#define MLN_DEFAULT_SKIP_MSG_A "Skipped in " __FILE__ 
#define MLN_DEFAULT_SKIP_MSG_B " at line " MLN_STRINGIFY_NX(__LINE__)

#define MLN_GET_TEST_NAME_FROM_FUNC(func_name) mln_test_##func_name
#define MLN_GET_TEST_NAME_TEXT_FROM_FUNC(func_name) MLN_STRINGIFY_NX(MLN_GET_TEST_NAME_FROM_FUNC(func_name))

#define MLN_PRE_TESTS MLN_PRE_TESTS_IMPLEMENTATION

#define MLN_POST_TESTS MLN_POST_TESTS_IMPLEMENTATION

#define MLN_TEST(func_name, ...) MLN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(func_name), __VA_ARGS__)

#define MLN_SET_LOGS_VERBOSITY(verbosity) MLN_SET_LOGS_VERBOSITY_IMPLEMENTATION(verbosity, mln_verbosity)

#define MLN_FAIL() MLN_FAILm_IMPLEMENTATION_STRING((mln_data_ptr), mln_verbosity, MLN_DEFAULT_FAIL_MSG, "Fail", "Fail", "%s", ##MLN_FAIL)

#define MLN_FAILm(msg) MLN_FAILm_IMPLEMENTATION_STRING((mln_data_ptr), mln_verbosity, msg, "Fail", "Fail", "%s", ##MLN_FAILm)

#define MLN_PASS() MLN_PASS_IMPLEMENTATION(mln_data_ptr)

#define MLN_SKIP() MLN_SKIPm_IMPLEMENTATION(MLN_DEFAULT_SKIP_MSG, mln_data_ptr)

#define MLN_SKIPm(msg) MLN_SKIPm_IMPLEMENTATION(msg, mln_data_ptr)

#define MLN_ASSERT(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION("true", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (condition), ##MLN_ASSERT, "%s", STRING)

#define MLN_ASSERTm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION("true", condition ? "true" : "false", msg, (condition), ##MLN_ASSERTm, "%s", STRING)

#define MLN_ASSERT_FALSE(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION("false", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (!condition), ##MLN_ASSERT_FALSE, "%s", STRING)

#define MLN_ASSERT_FALSEm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION("false", condition ? "true" : "false", msg, (!condition), ##MLN_ASSERT_FALSEm, "%s", STRING)

#define MLN_ASSERT_NULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL == value), ##MLN_ASSERT_NULL, "%p", GENERIC)

#define MLN_ASSERT_NULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(NULL, value, msg, (NULL == value), ##MLN_ASSERT_NULLm, "%p", GENERIC)

#define MLN_ASSERT_NNULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL != value), ##MLN_ASSERT_NNULL, "%p", GENERIC)

#define MLN_ASSERT_NNULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(NULL, value, msg, (NULL != value), ##MLN_ASSERT_NNULLm, "%p", GENERIC)

#define MLN_ASSERT_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), ##MLN_ASSERT_EQ, "%s", STRING)

#define MLN_ASSERT_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected == actual_value), ##MLN_ASSERT_EQm, "%s", STRING)

#define MLN_ASSERT_EQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), ##MLN_ASSERT_EQf, format, GENERIC)

#define MLN_ASSERT_EQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected == actual_value), ##MLN_ASSERT_EQfm, format, GENERIC)

#define MLN_ASSERT_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), ##MLN_ASSERT_NEQ, "%s", STRING)

#define MLN_ASSERT_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected != actual_value), ##MLN_ASSERT_NEQm, "%s", STRING)

#define MLN_ASSERT_NEQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), ##MLN_ASSERT_NEQf, format, GENERIC)

#define MLN_ASSERT_NEQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected != actual_value), ##MLN_ASSERT_NEQfm, format, GENERIC)

#define MLN_ASSERT_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), ##MLN_ASSERT_GT, "%s", STRING)

#define MLN_ASSERT_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected > actual_value), ##MLN_ASSERT_GTm, "%s", STRING)

#define MLN_ASSERT_GTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), ##MLN_ASSERT_GTf, format, GENERIC)

#define MLN_ASSERT_GTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected > actual_value), ##MLN_ASSERT_GTfm, format, GENERIC)

#define MLN_ASSERT_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), ##MLN_ASSERT_GTE, "%s", STRING)

#define MLN_ASSERT_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected >= actual_value), ##MLN_ASSERT_GTEm, "%s", STRING)

#define MLN_ASSERT_GTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), ##MLN_ASSERT_GTEf, format, GENERIC)

#define MLN_ASSERT_GTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected >= actual_value), ##MLN_ASSERT_GTEfm, format, GENERIC)

#define MLN_ASSERT_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), ##MLN_ASSERT_LT, "%s", STRING)

#define MLN_ASSERT_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected < actual_value), ##MLN_ASSERT_LTm, "%s", STRING)

#define MLN_ASSERT_LTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), ##MLN_ASSERT_LTf, format, GENERIC)

#define MLN_ASSERT_LTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected < actual_value), ##MLN_ASSERT_LTfm, format, GENERIC)

#define MLN_ASSERT_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), ##MLN_ASSERT_LTE, "%s", STRING)

#define MLN_ASSERT_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected <= actual_value), ##MLN_ASSERT_LTEm, "%s", STRING)

#define MLN_ASSERT_LTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), ##MLN_ASSERT_LTEf, format, GENERIC)

#define MLN_ASSERT_LTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected <= actual_value), ##MLN_ASSERT_LTEfm, format, GENERIC)

#define MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), ##MLN_ASSERT_IN_RANGE, "%s", STRING)

#define MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(#expected, #actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), ##MLN_ASSERT_IN_RANGEm, "%s", STRING)

#define MLN_ASSERT_IN_RANGEf(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), ##MLN_ASSERT_IN_RANGEf, format, GENERIC)

#define MLN_ASSERT_IN_RANGEfm(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), ##MLN_ASSERT_IN_RANGEfm, format, GENERIC)

#define MLN_ASSERT_STRN_EQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) == 0), ##MLN_ASSERT_STRN_EQ, "%s", STRING)

#define MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) == 0), ##MLN_ASSERT_STRN_EQm, "%s", STRING)

#define MLN_ASSERT_STRN_NEQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) != 0), ##MLN_ASSERT_STRN_NEQ, "%s", STRING)

#define MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) != 0), ##MLN_ASSERT_STRN_NEQm, "%s", STRING)

#define MLN_ASSERT_STRN_GT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) > 0), ##MLN_ASSERT_STRN_GT, "%s", STRING)

#define MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) > 0), ##MLN_ASSERT_STRN_GTm, "%s", STRING)

#define MLN_ASSERT_STRN_GTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) >= 0), ##MLN_ASSERT_STRN_GTE, "%s", STRING)

#define MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) >= 0), ##MLN_ASSERT_STRN_GTEm, "%s", STRING)

#define MLN_ASSERT_STRN_LT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) < 0), ##MLN_ASSERT_STRN_LT, "%s", STRING)

#define MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) < 0), ##MLN_ASSERT_STRN_LTm, "%s", STRING)

#define MLN_ASSERT_STRN_LTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) <= 0), ##MLN_ASSERT_STRN_LTE, "%s", STRING)

#define MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strncmp(expected, actual_value, size) <= 0), ##MLN_ASSERT_STRN_LTEm, "%s", STRING)

#define MLN_ASSERT_STR_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) == 0), ##MLN_ASSERT_STR_EQ, "%s", STRING)

#define MLN_ASSERT_STR_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) == 0), ##MLN_ASSERT_STR_EQm, "%s", STRING)

#define MLN_ASSERT_STR_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) != 0), ##MLN_ASSERT_STR_NEQ, "%s", STRING)

#define MLN_ASSERT_STR_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) != 0), ##MLN_ASSERT_STR_NEQm, "%s", STRING)

#define MLN_ASSERT_STR_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) > 0), ##MLN_ASSERT_STR_GT, "%s", STRING)

#define MLN_ASSERT_STR_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) > 0), ##MLN_ASSERT_STR_GTm, "%s", STRING)

#define MLN_ASSERT_STR_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) >= 0), ##MLN_ASSERT_STR_GTE, "%s", STRING)

#define MLN_ASSERT_STR_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) >= 0), ##MLN_ASSERT_STR_GTEm, "%s", STRING)

#define MLN_ASSERT_STR_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) < 0), ##MLN_ASSERT_STR_LT, "%s", STRING)

#define MLN_ASSERT_STR_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) < 0), ##MLN_ASSERT_STR_LTm, "%s", STRING)

#define MLN_ASSERT_STR_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) <= 0), ##MLN_ASSERT_STR_LTE, "%s", STRING)

#define MLN_ASSERT_STR_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, (strcmp(expected, actual_value) <= 0), ##MLN_ASSERT_STR_LTEm, "%s", STRING)

/*

TODO

ASSERT_MEM_EQ(EXPECTED, ACTUAL, SIZE)
Assert that the first SIZE bytes of memory pointed to by EXPECTED and ACTUAL are equal. If their memory differs, print a hexdump and highlight the lines and individual bytes which do not match.

ASSERT_EQUAL_T(EXPECTED, ACTUAL, TYPE_INFO, UDATA)
Assert that EXPECTED and ACTUAL are equal, using the greatest_equal_cb function pointed to by TYPE_INFO->equal to compare them. The assertion's UDATA argument can be used to pass in arbitrary user data (or NULL) to the callbacks. If the values are not equal and the TYPE_INFO->print function is defined, it will be used to print an "Expected: X, Got: Y" message.
*/


#ifdef MLN_REDUCE_MACROS_TO_FUNCTIONS

    #define MLN_RESET_DATA(mln_data_ptr) MLN_RESET_DATA_IMPLEMENTATION_FUNC((mln_data_ptr))
    #define MLN_ADD_LOGS(mln_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION_FUNC((mln_data_ptr), msg)
    #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION_FUNC(func_name)

    #define MLN_RESET_DATA_IMPLEMENTATION_FUNC(mln_data_ptr) mln_reset_data_implementation_func_call(mln_data_ptr);
    #define MLN_ADD_LOGS_IMPLEMENTATION_FUNC(mln_data_ptr, msg) mln_add_logs_implementation_func_call(mln_data_ptr, msg);
    #define MLN_RUN_TEST_IMPLEMENTATION_FUNC(func_name) mln_run_test_implementation_func_call(&(MLN_GET_TEST_NAME_FROM_FUNC(func_name)), #func_name, &mln_data, mln_verbosity, &mln_results, CLOCKS_PER_SEC);
    #define MLN_FAILm_IMPLEMENTATION_STRING(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed) mln_failm_implementation_string_func_call(mln_data_ptr, mln_verbosity, msg, expected, actual, #assert_failed); 

    void mln_failm_implementation_string_func_call(mln_test_data* mln_data_ptr, const size_t mln_verbosity, const char* msg, const char* expected, const char* actual, const char* assert_failed); 
    void mln_reset_data_implementation_func_call(mln_test_data* mln_data_ptr);
    void mln_add_logs_implementation_func_call(mln_test_data* mln_data_ptr, const char* msg);
    void mln_run_test_implementation_func_call(void(*func_ptr)(mln_test_data*, const size_t),  const char* func_name_text, mln_test_data* mln_data_ptr,  const size_t mln_verbosity,  mln_test_results* mln_results_ptr, const clock_t clocks_per_sec);


    #define MLN_TEST_FUNC_DEFINITIONS\
        void mln_reset_data_implementation_func_call(mln_test_data* mln_data_ptr){\
            MLN_RESET_DATA_IMPLEMENTATION(mln_data_ptr)\
        }\
        \
        void mln_add_logs_implementation_func_call(mln_test_data* mln_data_ptr, const char* msg){\
            MLN_ADD_LOGS_IMPLEMENTATION(mln_data_ptr, msg)\
        }\
        \
        void mln_run_test_implementation_func_call(\
        void(*func_ptr)(mln_test_data*, const size_t), \
        const char* func_name_text,\
        mln_test_data* mln_data_ptr, \
        const size_t mln_verbosity, \
        mln_test_results* mln_results_ptr,\
        const clock_t clocks_per_sec){\
            MLN_RUN_TEST_IMPLEMENTATION(func_ptr, func_name_text, mln_data_ptr, mln_verbosity, mln_results_ptr, clocks_per_sec)\
        }\
        \
        void mln_failm_implementation_string_func_call(mln_test_data* mln_data_ptr, const size_t mln_verbosity, const char* msg, const char* expected, const char* actual, const char* assert_failed){\
            MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, "%s", assert_failed)\
        }
    
#else

    #define MLN_TEST_FUNC_DEFINITIONS
    #define MLN_RESET_DATA(mln_data_ptr) MLN_RESET_DATA_IMPLEMENTATION((mln_data_ptr))
    #define MLN_ADD_LOGS(mln_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION((mln_data_ptr), msg)
    #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(func_name), #func_name, (&mln_data), mln_verbosity, (&mln_results), CLOCKS_PER_SEC)
    #define MLN_FAILm_IMPLEMENTATION_STRING(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed) MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, "%s", #assert_failed)

#endif

//Used only in main function
#define MLN_RESET_DATA_IMPLEMENTATION(mln_data_ptr)        \
    if((mln_data_ptr)->logs != NULL){\
        free((mln_data_ptr)->logs);\
    }\
    (mln_data_ptr)->logs = NULL;\
    (mln_data_ptr)->logs_size = 0;\
    (mln_data_ptr)->logs_length = 0;\
    (mln_data_ptr)->passes = 0;\
    (mln_data_ptr)->fails = 0;\
    (mln_data_ptr)->skips = 0;


#define MLN_GET_CHAR_ARRAY_LENGTH(msg, out_length) \
    {\
        (out_length) = 0;\
        size_t mln_i = 0;\
        char mln_letter;\
        if(msg != NULL){\
            do{\
                mln_letter = (msg)[mln_i++];\
            }while(mln_letter != '\0');\
        }\
        if(mln_i > 0){\
            (out_length) = mln_i - 1;\
        }\
    }


//Used only in tests
#define MLN_ADD_LOGS_IMPLEMENTATION(mln_data_ptr, msg) \
    {\
    size_t mln_msg_sizeof;\
    MLN_GET_CHAR_ARRAY_LENGTH(msg, mln_msg_sizeof)\
    if(mln_msg_sizeof > 1){\
    \
        if(mln_data_ptr->logs_length + mln_msg_sizeof >= mln_data_ptr->logs_size){\
            MLN_RESIZE_LOGS_IMPLEMENTATION(mln_data_ptr, mln_data_ptr->logs_length + mln_msg_sizeof + 1) \
        }\
    \
        const size_t mln_starting_index = mln_data_ptr->logs_length;\
        bool is_last_zero = false;\
        size_t mln_i = 0;\
        for(; mln_i < mln_msg_sizeof; ++mln_i){\
            is_last_zero = msg[mln_i] == '\0';\
            mln_data_ptr->logs[mln_starting_index + mln_i] = msg[mln_i];\
        }\
        if(!is_last_zero){\
            mln_data_ptr->logs[mln_starting_index + mln_i] = '\0';\
        }\
        MLN_GET_CHAR_ARRAY_LENGTH(mln_data_ptr->logs, mln_data_ptr->logs_length)\
    }\
    }

//used only in tests
#define MLN_RESIZE_LOGS_IMPLEMENTATION(mln_data_ptr, min_size) \
    {\
    if(mln_data_ptr->logs_size == 0){\
        mln_data_ptr->logs_size = min_size;\
        mln_data_ptr->logs = malloc(mln_data_ptr->logs_size);\
    }else{\
        while(mln_data_ptr->logs_size < min_size){\
            mln_data_ptr->logs_size = mln_data_ptr->logs_size * 2;\
        }\
        \
        char* mln_new_logs = malloc(mln_data_ptr->logs_size);\
        memcpy(mln_new_logs, mln_data_ptr->logs, mln_data_ptr->logs_length);\
        free(mln_data_ptr->logs);\
        mln_data_ptr->logs = mln_new_logs;\
    }\
    }

//used only in tests
#define MLN_DEFAULT_ASSERT_IMPLEMENTATION(expected, actual_value, msg, expression, assert_failed, format, fail_type) \
    {\
    const bool mln_result = expression;\
    if(mln_result){\
        mln_data_ptr->passes++;\
    }else{\
        MLN_FAILm_IMPLEMENTATION_##fail_type((mln_data_ptr), mln_verbosity, msg, expected, actual_value, #format, #assert_failed)\
    }\
    }

//used only in main
#define MLN_RUN_TEST_IMPLEMENTATION(func_ptr, func_name_text, mln_data_ptr, mln_verbosity, mln_results_ptr, clocks_per_sec) \
    {\
    if(mln_verbosity >= 2){\
        printf("Testing n.%zu function [%s]...\n", mln_results_ptr->current_test_count + 1, func_name_text);\
    }\
    \
    const clock_t mln_current_test_start_time = clock();\
    func_ptr((mln_data_ptr), mln_verbosity);\
    const clock_t mln_current_test_end_time = clock();\
    \
    (mln_results_ptr->current_test_count)++;\
    (mln_results_ptr->total_passes) += (mln_data_ptr)->passes;\
    (mln_results_ptr->total_skips) += (mln_data_ptr)->skips;\
    (mln_results_ptr->total_fails) += (mln_data_ptr)->fails;\
    if((mln_data_ptr)->fails != 0){\
        (mln_results_ptr->total_test_fails)++;\
    }else if((mln_data_ptr)->skips != 0){\
        (mln_results_ptr->total_test_skips)++;\
    }else if((mln_data_ptr)->passes != 0){\
        (mln_results_ptr->total_test_passes)++;\
    }\
    \
    bool mln_logs_used = false;\
    if((mln_data_ptr)->logs_length > 0){\
        printf("%s\n", (mln_data_ptr)->logs);\
        mln_logs_used = true;\
    }\
    if((mln_data_ptr)->fails != 0 && mln_verbosity > 0){\
        printf("Passes count: %zu, skips count: %zu, fails count: %zu\n", (mln_data_ptr)->passes, (mln_data_ptr)->skips, (mln_data_ptr)->fails);\
        mln_logs_used = true;\
    }\
    if((mln_verbosity == 1 && (mln_data_ptr)->fails != 0) || mln_verbosity >= 2){\
        printf("Estimated elapsed seconds: %.3lf\n", (double)(mln_current_test_end_time - mln_current_test_start_time) / (clocks_per_sec));\
        mln_logs_used = true;\
    }\
    if(mln_logs_used){\
        printf("\n");\
    }\
    MLN_RESET_DATA(mln_data_ptr)\
    }

//used only in tests
#define MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed) \
    {\
    mln_data_ptr->fails++;\
    MLN_ADD_LOGS(mln_data_ptr, msg) \
    const char* mln_format_string = format;\
    size_t mln_format_size;\
    MLN_GET_CHAR_ARRAY_LENGTH(mln_format_string, mln_format_size)\
    printf("%s%s", assert_failed, " failed! ");\
    if(mln_format_size >= 2 && mln_verbosity > 0)\
    {\
        printf("Expected [");\
        printf(mln_format_string, expected);\
        printf("] Actual [");\
        printf(mln_format_string, actual);\
        printf("]");\
    }\
    printf("\n");\
    }\
    return;

//used only in tests
#define MLN_SKIPm_IMPLEMENTATION(msg, mln_data_ptr)\
    mln_data_ptr->skips++;\
    if(mln_verbosity > 0){\
        MLN_ADD_LOGS(mln_data_ptr, msg) \
    }\
    return;

//used only in tests
#define MLN_PASS_IMPLEMENTATION(mln_data_ptr)\
    mln_data_ptr->passes++;\
    return;

//used only in main
#define MLN_SET_LOGS_VERBOSITY_IMPLEMENTATION(in_verbosity, out_verbosity)\
    if(in_verbosity <= 0){\
        out_verbosity = 0;\
    }else if(in_verbosity >= 2){\
        out_verbosity = 2;\
    }else{\
        out_verbosity = 1;\
    }

//used only in defining test functions
#define MLN_TEST_IMPLEMENTATION(full_func_name, ...)\
    void full_func_name (mln_test_data* mln_data_ptr, const size_t mln_verbosity){\
    __VA_ARGS__ \
    }

//used only in main
#define MLN_PRE_TESTS_IMPLEMENTATION          \
    const clock_t mln_start_time = clock();\
    size_t mln_verbosity = 0;\
    mln_test_results mln_results;\
    mln_results.total_passes = 0;\
    mln_results.total_fails = 0;\
    mln_results.total_skips = 0;\
    mln_results.current_test_count = 0;\
    mln_results.total_test_passes = 0;\
    mln_results.total_test_fails = 0;\
    mln_results.total_test_skips = 0;\
    mln_test_data mln_data;\
    mln_data.logs = NULL;\
    MLN_RESET_DATA(&mln_data) 

//used only in main
#define MLN_POST_TESTS_IMPLEMENTATION         \
    const size_t mln_total_results = mln_results.total_passes + mln_results.total_fails + mln_results.total_skips;\
    const size_t mln_total_test_results = mln_results.total_test_passes + mln_results.total_test_fails + mln_results.total_test_skips;\
    const clock_t mln_end_time = clock();\
    printf("Tests over. Results...\n");\
    printf("Tests passed: %zu/%zu. Total asserts passed: %zu/%zu\n", mln_results.total_test_passes, mln_total_test_results, mln_results.total_passes, mln_total_results);\
    printf("Tests skiped: %zu/%zu. Total asserts skipped: %zu/%zu\n", mln_results.total_test_skips, mln_total_test_results, mln_results.total_skips, mln_total_results);\
    printf("Tests failed: %zu/%zu. Total asserts failed: %zu/%zu\n", mln_results.total_test_fails, mln_total_test_results, mln_results.total_fails, mln_total_results);\
    printf("Tests failed percentage: %Lf%%, Asserts failed percentage: %Lf%% \n", \
    ((long double)(mln_results.total_test_fails) / mln_total_test_results) * 100.0, \
    ((long double)(mln_results.total_fails) / mln_total_results) * 100.0);\
    printf("Approximate seconds elapsed: %.3lf\n", (double)(mln_end_time - mln_start_time) / CLOCKS_PER_SEC);\
    printf("Press any keys to close...\n");\
    getchar();

#endif