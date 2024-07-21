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

#define __MLN_RESET_DATA(data_name)        \
    if(data_name.logs != NULL){\
        free(data_name.logs);\
    }\
    data_name.logs = NULL;\
    data_name.logs_size = 0;\
    data_name.logs_length = 0;\
    data_name.passes = 0;\
    data_name.fails = 0;\
    data_name.skips = 0;

#define __MLN_ADD_LOGS(logs_name, logs_length, logs_size, msg) \
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

#define __MLN_RESIZE_LOGS(logs_name, logs_length, logs_size, min_size) \
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

#define __MLN_DEFAULT_ASSERTm(expected, actual_value, msg, boolean_operation, assert_failed) \
    {\
    const bool __mln_result = expected boolean_operation actual_value;\
    if(__mln_result){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, #expected, #actual_value, "%s", ##assert_failed) \
    }\
    }

#define __MLN_DEFAULT_ASSERT_STRN(expected, actual_value, size, msg, boolean_operation, assert_failed)   \
    {\
    const bool __mln_expected = strncmp(expected, actual_value, size) boolean_operation 0;\
    if(__mln_expected){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, expected, actual_value, "%s", ##assert_failed) \
    }\
    }

#define __MLN_DEFAULT_ASSERT_STR(expected, actual_value, msg, boolean_operation, assert_failed)   \
    {\
    const bool __mln_expected = strcmp(expected, actual_value) boolean_operation 0;\
    if(__mln_expected){\
        __mln_out_test_data->passes++;\
    }else{\
        MLN_FAILm(msg, expected, actual_value, "%s", ##assert_failed) \
    }\
    }


#endif