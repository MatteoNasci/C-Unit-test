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
#define MLN_DEFAULT_FAIL_MSG MLN_DEFAULT_FAIL_MSG_D
#define MLN_DEFAULT_FAIL_MSG_D MLN_DEFAULT_FAIL_MSG_C "\n"
#define MLN_DEFAULT_FAIL_MSG_C MLN_DEFAULT_FAIL_MSG_A MLN_DEFAULT_FAIL_MSG_B
#define MLN_DEFAULT_FAIL_MSG_A "Failed in " __FILE__ 
#define MLN_DEFAULT_FAIL_MSG_B " at line " MLN_STRINGIFY_NX(__LINE__)

#define MLN_DEFAULT_SKIP_MSG MLN_DEFAULT_SKIP_MSG_D 
#define MLN_DEFAULT_SKIP_MSG_D MLN_DEFAULT_SKIP_MSG_C "\n"
#define MLN_DEFAULT_SKIP_MSG_C MLN_DEFAULT_SKIP_MSG_A MLN_DEFAULT_SKIP_MSG_B
#define MLN_DEFAULT_SKIP_MSG_A "Skipped in " __FILE__ 
#define MLN_DEFAULT_SKIP_MSG_B " at line " MLN_STRINGIFY_NX(__LINE__)

#define MLN_GET_TEST_NAME_FROM_FUNC(func_name) mln_test_##func_name
#define MLN_GET_TEST_NAME_TEXT_FROM_FUNC(func_name) MLN_STRINGIFY_NX(MLN_GET_TEST_NAME_FROM_FUNC(func_name))

#define MLN_PRE_TESTS MLN_PRE_TESTS_IMPLEMENTATION

#define MLN_POST_TESTS MLN_POST_TESTS_IMPLEMENTATION

#define MLN_TEST(func_name, ...) MLN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(func_name), __VA_ARGS__)

#define MLN_SET_LOGS_VERBOSITY(verbosity) MLN_SET_LOGS_VERBOSITY_IMPLEMENTATION(verbosity, mln_verbosity)

#define MLN_FAIL() MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "Fail", "Fail", MLN_DEFAULT_FAIL_MSG, (false), MLN_STRINGIFY_NX(##MLN_FAIL), "%s", STRING, true)

#define MLN_FAILm(msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "Fail", "Fail", msg, (false), MLN_STRINGIFY_NX(##MLN_FAILm), "%s", STRING, true)

#define MLN_PASS() MLN_PASS_IMPLEMENTATION(mln_data_ptr)

#define MLN_SKIP() MLN_SKIPm_IMPLEMENTATION(MLN_DEFAULT_SKIP_MSG, mln_data_ptr)

#define MLN_SKIPm(msg) MLN_SKIPm_IMPLEMENTATION(msg, mln_data_ptr)

#define MLN_ASSERT(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "true", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (condition), MLN_STRINGIFY_NX(##MLN_ASSERT), "%s", STRING, true)

#define MLN_ASSERTm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "true", condition ? "true" : "false", msg, (condition), MLN_STRINGIFY_NX(##MLN_ASSERTm), "%s", STRING, true)

#define MLN_ASSERT_FALSE(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "false", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (!condition), MLN_STRINGIFY_NX(##MLN_ASSERT_FALSE), "%s", STRING, true)

#define MLN_ASSERT_FALSEm(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "false", condition ? "true" : "false", msg, (!condition), MLN_STRINGIFY_NX(##MLN_ASSERT_FALSEm), "%s", STRING, true)

#define MLN_ASSERT_NULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL == value), MLN_STRINGIFY_NX(##MLN_ASSERT_NULL), "%p", GENERIC, true)

#define MLN_ASSERT_NULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, msg, (NULL == value), MLN_STRINGIFY_NX(##MLN_ASSERT_NULLm), "%p", GENERIC, true)

#define MLN_ASSERT_NNULL(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL != value), MLN_STRINGIFY_NX(##MLN_ASSERT_NNULL), "%p", GENERIC, true)

#define MLN_ASSERT_NNULLm(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, msg, (NULL != value), MLN_STRINGIFY_NX(##MLN_ASSERT_NNULLm), "%p", GENERIC, true)

#define MLN_ASSERT_MEM_EQ(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, true, MLN_DEFAULT_FAIL_MSG, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_EQ), true)

#define MLN_ASSERT_MEM_EQm(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, true, msg, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_EQm), true)

#define MLN_ASSERT_MEM_NEQ(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, false, MLN_DEFAULT_FAIL_MSG, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_NEQ), true)

#define MLN_ASSERT_MEM_NEQm(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, false, msg, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_NEQm), true)

#define MLN_ASSERT_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQ), "%s", STRING, true)

#define MLN_ASSERT_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQm), "%s", STRING, true)

#define MLN_ASSERT_EQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQf), format, GENERIC, true)

#define MLN_ASSERT_EQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQfm), format, GENERIC, true)

#define MLN_ASSERT_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQ), "%s", STRING, true)

#define MLN_ASSERT_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQm), "%s", STRING, true)

#define MLN_ASSERT_NEQf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQf), format, GENERIC, true)

#define MLN_ASSERT_NEQfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQfm), format, GENERIC, true)

#define MLN_ASSERT_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GT), "%s", STRING, true)

#define MLN_ASSERT_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTm), "%s", STRING, true)

#define MLN_ASSERT_GTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTf), format, GENERIC, true)

#define MLN_ASSERT_GTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTfm), format, GENERIC, true)

#define MLN_ASSERT_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTE), "%s", STRING, true)

#define MLN_ASSERT_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEm), "%s", STRING, true)

#define MLN_ASSERT_GTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEf), format, GENERIC, true)

#define MLN_ASSERT_GTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEfm), format, GENERIC, true)

#define MLN_ASSERT_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LT), "%s", STRING, true)

#define MLN_ASSERT_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTm), "%s", STRING, true)

#define MLN_ASSERT_LTf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTf), format, GENERIC, true)

#define MLN_ASSERT_LTfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTfm), format, GENERIC, true)

#define MLN_ASSERT_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTE), "%s", STRING, true)

#define MLN_ASSERT_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEm), "%s", STRING, true)

#define MLN_ASSERT_LTEf(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEf), format, GENERIC, true)

#define MLN_ASSERT_LTEfm(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEfm), format, GENERIC, true)

#define MLN_ASSERT_IN_RANGE(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGE), "%s", STRING, true)

#define MLN_ASSERT_IN_RANGEm(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEm), "%s", STRING, true)

#define MLN_ASSERT_IN_RANGEf(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEf), format, GENERIC, true)

#define MLN_ASSERT_IN_RANGEfm(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEfm), format, GENERIC, true)

#define MLN_ASSERT_STRN_EQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_EQ), "%s", STRING, true)

#define MLN_ASSERT_STRN_EQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_EQm), "%s", STRING, true)

#define MLN_ASSERT_STRN_NEQ(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_NEQ), "%s", STRING, true)

#define MLN_ASSERT_STRN_NEQm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_NEQm), "%s", STRING, true)

#define MLN_ASSERT_STRN_GT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GT), "%s", STRING, true)

#define MLN_ASSERT_STRN_GTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTm), "%s", STRING, true)

#define MLN_ASSERT_STRN_GTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTE), "%s", STRING, true)

#define MLN_ASSERT_STRN_GTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTEm), "%s", STRING, true)

#define MLN_ASSERT_STRN_LT(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LT), "%s", STRING, true)

#define MLN_ASSERT_STRN_LTm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTm), "%s", STRING, true)

#define MLN_ASSERT_STRN_LTE(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTE), "%s", STRING, true)

#define MLN_ASSERT_STRN_LTEm(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTEm), "%s", STRING, true)

#define MLN_ASSERT_STR_EQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_EQ), "%s", STRING, true)

#define MLN_ASSERT_STR_EQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_EQm), "%s", STRING, true)

#define MLN_ASSERT_STR_NEQ(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_NEQ), "%s", STRING, true)

#define MLN_ASSERT_STR_NEQm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_NEQm), "%s", STRING, true)

#define MLN_ASSERT_STR_GT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GT), "%s", STRING, true)

#define MLN_ASSERT_STR_GTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTm), "%s", STRING, true)

#define MLN_ASSERT_STR_GTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTE), "%s", STRING, true)

#define MLN_ASSERT_STR_GTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTEm), "%s", STRING, true)

#define MLN_ASSERT_STR_LT(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LT), "%s", STRING, true)

#define MLN_ASSERT_STR_LTm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTm), "%s", STRING, true)

#define MLN_ASSERT_STR_LTE(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTE), "%s", STRING, true)

#define MLN_ASSERT_STR_LTEm(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTEm), "%s", STRING, true)

#define MLN_ASSERTi(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "true", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (condition), MLN_STRINGIFY_NX(##MLN_ASSERTi), "%s", STRING, false)

#define MLN_ASSERTmi(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "true", condition ? "true" : "false", msg, (condition), MLN_STRINGIFY_NX(##MLN_ASSERTmi), "%s", STRING, false)

#define MLN_ASSERT_FALSEi(condition) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "false", condition ? "true" : "false", MLN_DEFAULT_FAIL_MSG, (!condition), MLN_STRINGIFY_NX(##MLN_ASSERT_FALSEi), "%s", STRING, false)

#define MLN_ASSERT_FALSEmi(condition, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), "false", condition ? "true" : "false", msg, (!condition), MLN_STRINGIFY_NX(##MLN_ASSERT_FALSEmi), "%s", STRING, false)

#define MLN_ASSERT_NULLi(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL == value), MLN_STRINGIFY_NX(##MLN_ASSERT_NULLi), "%p", GENERIC, false)

#define MLN_ASSERT_NULLmi(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, msg, (NULL == value), MLN_STRINGIFY_NX(##MLN_ASSERT_NULLmi), "%p", GENERIC, false)

#define MLN_ASSERT_NNULLi(value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, MLN_DEFAULT_FAIL_MSG, (NULL != value), MLN_STRINGIFY_NX(##MLN_ASSERT_NNULLi), "%p", GENERIC, false)

#define MLN_ASSERT_NNULLmi(value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), NULL, value, msg, (NULL != value), MLN_STRINGIFY_NX(##MLN_ASSERT_NNULLmi), "%p", GENERIC, false)

#define MLN_ASSERT_MEM_EQi(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, true, MLN_DEFAULT_FAIL_MSG, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_EQi), false)

#define MLN_ASSERT_MEM_EQmi(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, true, msg, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_EQmi), false)

#define MLN_ASSERT_MEM_NEQi(expected, actual, size) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, false, MLN_DEFAULT_FAIL_MSG, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_NEQi), false)

#define MLN_ASSERT_MEM_NEQmi(expected, actual, size, msg) MLN_DEFAULT_MEM_ASSERT_((mln_data_ptr), expected, actual, size, false, msg, MLN_STRINGIFY_NX(##MLN_ASSERT_MEM_NEQmi), false)

#define MLN_ASSERT_EQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQi), "%s", STRING, false)

#define MLN_ASSERT_EQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQmi), "%s", STRING, false)

#define MLN_ASSERT_EQfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQfi), format, GENERIC, false)

#define MLN_ASSERT_EQfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected == actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_EQfmi), format, GENERIC, false)

#define MLN_ASSERT_NEQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQi), "%s", STRING, false)

#define MLN_ASSERT_NEQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQmi), "%s", STRING, false)

#define MLN_ASSERT_NEQfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQfi), format, GENERIC, false)

#define MLN_ASSERT_NEQfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected != actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_NEQfmi), format, GENERIC, false)

#define MLN_ASSERT_GTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTi), "%s", STRING, false)

#define MLN_ASSERT_GTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTmi), "%s", STRING, false)

#define MLN_ASSERT_GTfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTfi), format, GENERIC, false)

#define MLN_ASSERT_GTfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected > actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTfmi), format, GENERIC, false)

#define MLN_ASSERT_GTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEi), "%s", STRING, false)

#define MLN_ASSERT_GTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEmi), "%s", STRING, false)

#define MLN_ASSERT_GTEfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEfi), format, GENERIC, false)

#define MLN_ASSERT_GTEfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_GTEfmi), format, GENERIC, false)

#define MLN_ASSERT_LTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTi), "%s", STRING, false)

#define MLN_ASSERT_LTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTmi), "%s", STRING, false)

#define MLN_ASSERT_LTfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTfi), format, GENERIC, false)

#define MLN_ASSERT_LTfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected < actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTfmi), format, GENERIC, false)

#define MLN_ASSERT_LTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEi), "%s", STRING, false)

#define MLN_ASSERT_LTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEmi), "%s", STRING, false)

#define MLN_ASSERT_LTEfi(expected, actual_value, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEfi), format, GENERIC, false)

#define MLN_ASSERT_LTEfmi(expected, actual_value, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected <= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_LTEfmi), format, GENERIC, false)

#define MLN_ASSERT_IN_RANGEi(expected, actual_value, tollerance) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEi), "%s", STRING, false)

#define MLN_ASSERT_IN_RANGEmi(expected, actual_value, tollerance, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), #expected, #actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEmi), "%s", STRING, false)

#define MLN_ASSERT_IN_RANGEfi(expected, actual_value, tollerance, format) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEfi), format, GENERIC, false)

#define MLN_ASSERT_IN_RANGEfmi(expected, actual_value, tollerance, format, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (expected - tollerance <= actual_value) && (expected + tollerance >= actual_value), MLN_STRINGIFY_NX(##MLN_ASSERT_IN_RANGEfmi), format, GENERIC, false)

#define MLN_ASSERT_STRN_EQi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_EQi), "%s", STRING, false)

#define MLN_ASSERT_STRN_EQmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_EQmi), "%s", STRING, false)

#define MLN_ASSERT_STRN_NEQi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_NEQi), "%s", STRING, false)

#define MLN_ASSERT_STRN_NEQmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_NEQmi), "%s", STRING, false)

#define MLN_ASSERT_STRN_GTi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTi), "%s", STRING, false)

#define MLN_ASSERT_STRN_GTmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTmi), "%s", STRING, false)

#define MLN_ASSERT_STRN_GTEi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTEi), "%s", STRING, false)

#define MLN_ASSERT_STRN_GTEmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_GTEmi), "%s", STRING, false)

#define MLN_ASSERT_STRN_LTi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTi), "%s", STRING, false)

#define MLN_ASSERT_STRN_LTmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTmi), "%s", STRING, false)

#define MLN_ASSERT_STRN_LTEi(expected, actual_value, size) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTEi), "%s", STRING, false)

#define MLN_ASSERT_STRN_LTEmi(expected, actual_value, size, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strncmp(expected, actual_value, size) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STRN_LTEmi), "%s", STRING, false)

#define MLN_ASSERT_STR_EQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_EQi), "%s", STRING, false)

#define MLN_ASSERT_STR_EQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) == 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_EQmi), "%s", STRING, false)

#define MLN_ASSERT_STR_NEQi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_NEQi), "%s", STRING, false)

#define MLN_ASSERT_STR_NEQmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) != 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_NEQmi), "%s", STRING, false)

#define MLN_ASSERT_STR_GTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTi), "%s", STRING, false)

#define MLN_ASSERT_STR_GTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) > 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTmi), "%s", STRING, false)

#define MLN_ASSERT_STR_GTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTEi), "%s", STRING, false)

#define MLN_ASSERT_STR_GTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) >= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_GTEmi), "%s", STRING, false)

#define MLN_ASSERT_STR_LTi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTi), "%s", STRING, false)

#define MLN_ASSERT_STR_LTmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) < 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTmi), "%s", STRING, false)

#define MLN_ASSERT_STR_LTEi(expected, actual_value) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, MLN_DEFAULT_FAIL_MSG, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTEi), "%s", STRING, false)

#define MLN_ASSERT_STR_LTEmi(expected, actual_value, msg) MLN_DEFAULT_ASSERT_IMPLEMENTATION((mln_data_ptr), expected, actual_value, msg, (strcmp(expected, actual_value) <= 0), MLN_STRINGIFY_NX(##MLN_ASSERT_STR_LTEmi), "%s", STRING, false)


#define MLN_DEFAULT_MEM_ASSERT_(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail) \
    {\
        bool mln_stop_test = false;\
        MLN_DEFAULT_MEM_ASSERT(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, (&mln_stop_test))\
        if(mln_stop_test){\
            return;\
        }\
    }

#ifdef MLN_REDUCE_MACROS_TO_FUNCTIONS

    #define MLN_RESET_DATA(mln_data_ptr) MLN_RESET_DATA_IMPLEMENTATION_FUNC((mln_data_ptr))
    #define MLN_ADD_LOGS(mln_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION_FUNC((mln_data_ptr), msg)
    #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION_FUNC(func_name)
    #define MLN_DEFAULT_MEM_ASSERT(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_DEFAULT_MEM_ASSERT_FUNC(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)

    #define MLN_RESET_DATA_IMPLEMENTATION_FUNC(mln_data_ptr) mln_reset_data_implementation_func_call(mln_data_ptr);
    #define MLN_ADD_LOGS_IMPLEMENTATION_FUNC(mln_data_ptr, msg) mln_add_logs_implementation_func_call(mln_data_ptr, msg);
    #define MLN_RUN_TEST_IMPLEMENTATION_FUNC(func_name) mln_run_test_implementation_func_call(&(MLN_GET_TEST_NAME_FROM_FUNC(func_name)), #func_name, &mln_data, mln_verbosity, &mln_results, CLOCKS_PER_SEC);
    #define MLN_FAILm_IMPLEMENTATION_STRING(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) mln_failm_implementation_string_func_call(mln_data_ptr, mln_verbosity, msg, expected, actual, assert_failed, stop_test_on_fail, stop_test_ptr);
    #define MLN_DEFAULT_MEM_ASSERT_FUNC(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) mln_default_mem_assert_func_call(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr);

    void mln_failm_implementation_string_func_call(mln_test_data* mln_data_ptr, const size_t mln_verbosity, const char* msg, const char* expected, const char* actual, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr); 
    void mln_reset_data_implementation_func_call(mln_test_data* mln_data_ptr);
    void mln_add_logs_implementation_func_call(mln_test_data* mln_data_ptr, const char* msg);
    void mln_run_test_implementation_func_call(void(*func_ptr)(mln_test_data*, const size_t),  const char* func_name_text, mln_test_data* mln_data_ptr,  const size_t mln_verbosity,  mln_test_results* mln_results_ptr, const clock_t clocks_per_sec);
    void mln_default_mem_assert_func_call(mln_test_data* mln_data_ptr, const char* data_a, const char* data_b, const size_t size, const bool equality, const char* msg, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr);

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
        void mln_failm_implementation_string_func_call(mln_test_data* mln_data_ptr, const size_t mln_verbosity, const char* msg, const char* expected, const char* actual, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr){\
            MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, "%s", assert_failed, stop_test_on_fail, stop_test_ptr)\
        }\
        void mln_default_mem_assert_func_call(mln_test_data* mln_data_ptr, const char* data_a, const char* data_b, const size_t size, const bool equality, const char* msg, const char* assert_failed, const bool stop_test_on_fail, bool* stop_test_ptr){\
           MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_data_ptr, data_a, data_b, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) \
        }
    
#else

    #define MLN_TEST_FUNC_DEFINITIONS
    #define MLN_RESET_DATA(mln_data_ptr) MLN_RESET_DATA_IMPLEMENTATION((mln_data_ptr))
    #define MLN_ADD_LOGS(mln_data_ptr, msg) MLN_ADD_LOGS_IMPLEMENTATION((mln_data_ptr), msg)
    #define MLN_RUN_TEST(func_name) MLN_RUN_TEST_IMPLEMENTATION(MLN_GET_TEST_NAME_FROM_FUNC(func_name), #func_name, (&mln_data), mln_verbosity, (&mln_results), CLOCKS_PER_SEC)
    #define MLN_FAILm_IMPLEMENTATION_STRING(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, "%s", assert_failed, stop_test_on_fail, stop_test_ptr)
    #define MLN_DEFAULT_MEM_ASSERT(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr) MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)

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
        const bool is_last_char_new_line = msg[mln_msg_sizeof-1] == '\n';\
        if(mln_msg_sizeof > 1){\
        \
            const size_t mln_required_size = mln_data_ptr->logs_length + mln_msg_sizeof + (is_last_char_new_line ? 1 : 2);\
            if(mln_required_size > mln_data_ptr->logs_size){\
                MLN_RESIZE_LOGS_IMPLEMENTATION(mln_data_ptr, mln_required_size) \
            }\
        \
            const size_t mln_starting_index = mln_data_ptr->logs_length;\
            size_t mln_i = 0;\
            for(; mln_i < mln_msg_sizeof; ++mln_i){\
                mln_data_ptr->logs[mln_starting_index + mln_i] = msg[mln_i];\
            }\
            if(!is_last_char_new_line){\
                mln_data_ptr->logs[mln_starting_index + mln_i] = '\n';\
                mln_data_ptr->logs[mln_starting_index + mln_i + 1] = '\0';\
                mln_data_ptr->logs_length = mln_starting_index + mln_i + 1;\
            }else{\
                mln_data_ptr->logs[mln_starting_index + mln_i] = '\0';\
                mln_data_ptr->logs_length = mln_starting_index + mln_i;\
            }\
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
#define MLN_DEFAULT_ASSERT_IMPLEMENTATION(mln_data_ptr, expected, actual_value, msg, expression, assert_failed, format, fail_type, stop_test_on_fail) \
    {\
        const bool mln_result = expression;\
        if(mln_result){\
            mln_data_ptr->passes++;\
        }else{\
            bool mln_stop_test = false;\
            MLN_FAILm_IMPLEMENTATION_##fail_type((mln_data_ptr), mln_verbosity, msg, expected, actual_value, #format, assert_failed, stop_test_on_fail, (&mln_stop_test))\
            if(mln_stop_test){\
                return;\
            }\
        }\
    }

//used only in tests
#define MLN_DEFAULT_MEM_ASSERT_IMPLEMENTATION(mln_data_ptr, expected, actual, size, equality, msg, assert_failed, stop_test_on_fail, stop_test_ptr)\
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
            mln_data_ptr->passes++;\
        }else{\
            mln_data_ptr->fails++;\
            MLN_ADD_LOGS(mln_data_ptr, msg)\
            printf("%s%s", assert_failed, " failed! ");\
            printf("0x[Expected]  @@  0x[Actual]\n");\
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
                printf("%zu.  %#04hhx", mln_i, expected_byte);\
                printf("%s", mln_is_byte_correct ? "    " : (equality ? " != " : " == "));\
                printf("%#04hhx\n", actual_byte);\
            }\
            if(stop_test_on_fail){\
                *stop_test_ptr = true;\
                return;\
            }\
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
            printf("%s", (mln_data_ptr)->logs);\
            mln_logs_used = true;\
        }\
        if(((mln_data_ptr)->fails != 0 && mln_verbosity > 0) || mln_verbosity >= 2){\
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
#define MLN_FAILm_IMPLEMENTATION_GENERIC(mln_data_ptr, mln_verbosity, msg, expected, actual, format, assert_failed, stop_test_on_fail, stop_test_ptr) \
    {\
        mln_data_ptr->fails++;\
        MLN_ADD_LOGS(mln_data_ptr, msg) \
        printf("Assert n%zu. %s%s", (mln_data_ptr->passes + mln_data_ptr->skips + mln_data_ptr->fails), assert_failed, " failed! ");\
        const char* mln_format_string = format;\
        size_t mln_format_size;\
        MLN_GET_CHAR_ARRAY_LENGTH(mln_format_string, mln_format_size)\
        if(mln_format_size >= 2 && mln_verbosity > 0){\
            printf("Expected [");\
            printf(mln_format_string, expected);\
            printf("] Actual [");\
            printf(mln_format_string, actual);\
            printf("]");\
        }\
        printf("\n");\
        if(stop_test_on_fail){\
            *stop_test_ptr = true;\
            return;\
        }\
    }

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
    const long double mln_final_test_failed_perc = mln_total_test_results == 0 ? 0 : ((long double)(mln_results.total_test_fails) / mln_total_test_results) * 100.0;\
    const long double mln_final_assert_failed_perc = mln_total_results == 0 ? 0 : ((long double)(mln_results.total_fails) / mln_total_results) * 100.0;\
    printf("Tests failed percentage: %Lf%%, Asserts failed percentage: %Lf%% \n", mln_final_test_failed_perc, mln_final_assert_failed_perc);\
    printf("Approximate seconds elapsed: %.3lf\n", (double)(mln_end_time - mln_start_time) / CLOCKS_PER_SEC);\
    printf("Press any keys to close...\n");\
    getchar();

#endif