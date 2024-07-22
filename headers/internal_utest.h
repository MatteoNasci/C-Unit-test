#pragma once
#ifndef _H_MLN_TESTS_INTERNAL_UTEST_H_
#define _H_MLN_TESTS_INTERNAL_UTEST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Collection of internal defines/functions, not designed to be used by the final user
*/

#define __MLN_STRINGIFY(A) #A
#define __MLN_STRINGIFY_NX(A) __MLN_STRINGIFY(A)
#define __MLN_DEFAULT_FAIL_MSG __MLN_DEFAULT_FAIL_MSG_C
#define __MLN_DEFAULT_FAIL_MSG_C __MLN_DEFAULT_FAIL_MSG_A __MLN_DEFAULT_FAIL_MSG_B
#define __MLN_DEFAULT_FAIL_MSG_A "Failed in " __FILE__ 
#define __MLN_DEFAULT_FAIL_MSG_B " at line " __MLN_STRINGIFY_NX(__LINE__)

#define __MLN_DEFAULT_SKIP_MSG __MLN_DEFAULT_SKIP_MSG_C
#define __MLN_DEFAULT_SKIP_MSG_C __MLN_DEFAULT_SKIP_MSG_A __MLN_DEFAULT_SKIP_MSG_B
#define __MLN_DEFAULT_SKIP_MSG_A "Skipped in " __FILE__ 
#define __MLN_DEFAULT_SKIP_MSG_B " at line " __MLN_STRINGIFY_NX(__LINE__)

#ifdef MLN_REDUCE_MACROS_TO_FUNCTIONS

    #define __MLN_RESET_DATA __MLN_RESET_DATA_INTERNAL_FUNC
    #define __MLN_ADD_LOGS __MLN_ADD_LOGS_INTERNAL_FUNC
    #define __MLN_RESIZE_LOGS __MLN_RESIZE_LOGS_INTERNAL_FUNC
    #define __MLN_DEFAULT_ASSERT __MLN_DEFAULT_ASSERT_INTERNAL_FUNC
    #define __MLN_DEFAULT_ASSERT_STRN __MLN_DEFAULT_ASSERT_STRN_INTERNAL_FUNC
    #define __MLN_DEFAULT_ASSERT_STR __MLN_DEFAULT_ASSERT_STR_INTERNAL_FUNC
    
#else

    #define __MLN_RESET_DATA __MLN_RESET_DATA_INTERNAL
    #define __MLN_ADD_LOGS __MLN_ADD_LOGS_INTERNAL
    #define __MLN_RESIZE_LOGS __MLN_RESIZE_LOGS_INTERNAL
    #define __MLN_DEFAULT_ASSERT __MLN_DEFAULT_ASSERT_INTERNAL
    #define __MLN_DEFAULT_ASSERT_STRN __MLN_DEFAULT_ASSERT_STRN_INTERNAL
    #define __MLN_DEFAULT_ASSERT_STR __MLN_DEFAULT_ASSERT_STR_INTERNAL

#endif

#define __MLN_RESET_DATA_INTERNAL(data_name)        \
    if(data_name.logs != NULL){\
        free(data_name.logs);\
    }\
    data_name.logs = NULL;\
    data_name.logs_size = 0;\
    data_name.logs_length = 0;\
    data_name.passes = 0;\
    data_name.fails = 0;\
    data_name.skips = 0;

#define __MLN_ADD_LOGS_INTERNAL(logs_name, logs_length, logs_size, msg) \
    {\
    const size_t __mln_msg_sizeof = sizeof msg;\
    if(__mln_msg_sizeof > 1){\
        const size_t __mln_msg_size = __mln_msg_sizeof - 1;\
    \
        if(logs_length + __mln_msg_sizeof >= logs_size){\
            __MLN_RESIZE_LOGS(logs_name, logs_length, logs_size, logs_length + __mln_msg_sizeof) \
        }\
    \
        const size_t __mln_starting_index = logs_length == 0 ? 0 : logs_length - 1;\
        bool is_last_zero = false;\
        size_t __mln_i = 0;\
        for(; __mln_i < __mln_msg_size; ++__mln_i){\
            is_last_zero = msg[__mln_i] == '\0';\
            logs_name[__mln_starting_index + __mln_i] = msg[__mln_i];\
        }\
        if(!is_last_zero){\
            logs_name[__mln_starting_index + __mln_i] = '\0';\
        }\
        logs_length = sizeof logs_name;\
    }\
    }

#define __MLN_RESIZE_LOGS_INTERNAL(logs_name, logs_length, logs_size, min_size) \
    {\
    if(logs_size == 0){\
        logs_size = min_size;\
        logs_name = malloc(logs_size);\
    }else{\
        while(logs_size < min_size){\
            logs_size = logs_size * 2;\
        }\
        \
        char* __mln_new_logs = malloc(logs_size);\
        memcpy(__mln_new_logs, logs_name, logs_length);\
        free(logs_name);\
        logs_name = __mln_new_logs;\
    }\
    }

#define __MLN_DEFAULT_ASSERT_INTERNAL(expected, actual_value, msg, boolean_operation, assert_failed) \
    {\
    const bool __mln_result = expected boolean_operation actual_value;\
    if(__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, #expected, #actual_value, "%s", ##assert_failed) \
    }\
    }

#define __MLN_DEFAULT_ASSERT_STRN_INTERNAL(expected, actual_value, size, msg, boolean_operation, assert_failed)   \
    {\
    const bool __mln_expected = strncmp(expected, actual_value, size) boolean_operation 0;\
    if(__mln_expected){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, expected, actual_value, "%s", ##assert_failed) \
    }\
    }

#define __MLN_DEFAULT_ASSERT_STR_INTERNAL(expected, actual_value, msg, boolean_operation, assert_failed)   \
    {\
    const bool __mln_expected = strcmp(expected, actual_value) boolean_operation 0;\
    if(__mln_expected){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, expected, actual_value, "%s", ##assert_failed) \
    }\
    }

#define __MLN_RUN_TEST_INTERNAL(func_name) \
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
        printf("%s\n", __mln_data.logs);\
        __mln_logs_used = true;\
    }\
    if(__mln_data.fails != 0 && __mln_verbosity > 0){\
        printf("Passes count: %zu, skips count: %zu, fails count: %zu\n", __mln_data.passes, __mln_data.skips, __mln_data.fails);\
        __mln_logs_used = true;\
    }\
    if((__mln_verbosity == 1 && __mln_data.fails != 0) || __mln_verbosity >= 2){\
        printf("Estimated elapsed seconds: %.3lf\n", (double)(__mln_current_test_end_time - __mln_current_test_start_time) / CLOCKS_PER_SEC);\
        __mln_logs_used = true;\
    }\
    if(__mln_logs_used){\
        printf("\n");\
    }\
    __MLN_RESET_DATA(__mln_data)\
    }

#define __MLN_FAILm_INTERNAL(msg, expected, actual, format, assert_failed) \
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


#endif