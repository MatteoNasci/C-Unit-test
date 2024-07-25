#ifdef TEST_REDUCE_TO_MACROS
#define MLN_REDUCE_MACROS_TO_FUNCTIONS
#endif

#define MLN_REMOVE_TESTS_PREFIXES

#include "utest.h"
#include "test_headers/tester.h"

extern void hello();

TEST(testing_passes2 , 
    ASSERT(true, false)
    ASSERTm(5, "msg\n", false)
    ASSERT_FALSE(false, false)
    ASSERT_FALSEm(0, "msg\n", false)
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    ASSERT_NULL(ptr2, false)
    ASSERT_NULLm(ptr2, "msg\n", false)
    ASSERT_NNULL(ptr, false)
    ASSERT_NNULLm(ptr, "msg\n", false)
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    ASSERT_MEM_EQ(a, b, 10, false)
    ASSERT_MEM_EQm(a, b, 10, "msg\n", false)
    ASSERT_MEM_NEQ(a, c, 10, false)
    ASSERT_MEM_NEQm(a, c, 10, "msg\n", false)
    ASSERT_EQ((7.5), (7.5), false)
    ASSERT_EQm('f', 'f', "msg\n", false)
    ASSERT_EQf('f', 'f', "%c", false)
    ASSERT_EQfm(4, 4, "%d", "msg\n", false)
    ASSERT_NEQ(2, 1, false)
    ASSERT_NEQm(0.25, 0.26, "msg\n", false)
    ASSERT_NEQf(2, 1, "%d", false)
    ASSERT_NEQfm(0.25, 0.26, "%f", "msg\n", false)
    ASSERT_GT(1, 0, false)
    ASSERT_GTm(0, -1, "msg\n", false)
    ASSERT_GTf(1, 0, "%d", false)
    ASSERT_GTfm(0, -1, "%d", "msg\n", false)
    ASSERT_GTE(0, 0, false)
    ASSERT_GTEm(3.2, 3.1, "msg\n", false)
    ASSERT_GTEf(0, 0, "%f", false)
    ASSERT_GTEfm(3.2, 3.1, "%f", "msg\n", false)
    ASSERT_LT(0, 1, false)
    ASSERT_LTm(-1252152, 2, "msg\n", false)
    ASSERT_LTf(0, 1, "%d", false)
    ASSERT_LTfm(-1252152, 2, "%d", "msg\n", false)
    ASSERT_LTE(-1, -1, false)
    ASSERT_LTEm(0, 1, "msg\n", false)
    ASSERT_LTEf(-1, -1, "%d", false)
    ASSERT_LTEfm(0, 1, "%d", "msg\n", false)
    ASSERT_IN_RANGE(0, 0.001, 0.01, false)
    ASSERT_IN_RANGEm(3, -1, 5, "msg\n", false)
    ASSERT_IN_RANGEf(0, 0.001, 0.01, "%f", false)
    ASSERT_IN_RANGEfm(3, -1, 5, "%d", "msg\n", false)
    ASSERT_STRN_EQ("a", "a", 1, false)
    ASSERT_STRN_EQm("", "", 1, "msg\n", false)
    ASSERT_STRN_EQm("", "", 0, "msg\n", false)
    ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg\n", false)
    ASSERT_STRN_NEQ("expected", "expected fasf", 9, false)
    ASSERT_STRN_NEQm("446", "actual_value", 3, "msg\n", false)
    ASSERT_STRN_GT("expected", "actual_value", 3, false)
    ASSERT_STRN_GTm("expected", "expacted", 4, "msg\n", false)
    ASSERT_STRN_GTE("expected", "expected", 8, false)
    ASSERT_STRN_GTEm("expected", "expacted", 8, "msg\n", false)
    ASSERT_STRN_LT("123", "234", 3, false)
    ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg\n", false)
    ASSERT_STRN_LTE("expected", "expected", 8, false)
    ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg\n", false)
    ASSERT_STR_EQ("a", "a", false)
    ASSERT_STR_EQm("expected", "expected", "msg\n", false)
    ASSERT_STR_NEQ("expected", "expected fasf", false)
    ASSERT_STR_NEQm("446", "actual_value", "msg\n", false)
    ASSERT_STR_GT("expected", "actual_value", false)
    ASSERT_STR_GTm("expected", "expacted", "msg\n", false)
    ASSERT_STR_GTE("expected", "exp", false)
    ASSERT_STR_GTEm("expected", "expacted", "msg\n", false)
    ASSERT_STR_LT("123", "234", false)
    ASSERT_STR_LTm("a12f3", "c234d", "msg\n", false)
    ASSERT_STR_LTE("expected", "expected", false)
    ASSERT_STR_LTEm("axpected", "ectual_value", "msg\n", false)
)
TEST(testing_passes_prefix2 , 
    MLN_ASSERT(true, false)
    MLN_ASSERTm(5, "msg\n", false)
    MLN_ASSERT_FALSE(false, false)
    MLN_ASSERT_FALSEm(0, "msg\n", false)
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    MLN_ASSERT_NULL(ptr2, false)
    MLN_ASSERT_NULLm(ptr2, "msg\n", false)
    MLN_ASSERT_NNULL(ptr, false)
    MLN_ASSERT_NNULLm(ptr, "msg\n", false)
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    MLN_ASSERT_MEM_EQ(a, b, 10, false)
    MLN_ASSERT_MEM_EQm(a, b, 10, "msg\n", false)
    MLN_ASSERT_MEM_NEQ(a, c, 10, false)
    MLN_ASSERT_MEM_NEQm(a, c, 10, "msg\n", false)
    MLN_ASSERT_EQ((7.5), (7.5), false)
    MLN_ASSERT_EQm('f', 'f', "msg\n", false)
    MLN_ASSERT_EQf('f', 'f', "%c", false)
    MLN_ASSERT_EQfm(4, 4, "%d", "msg\n", false)
    MLN_ASSERT_NEQ(2, 1, false)
    MLN_ASSERT_NEQm(0.25, 0.26, "msg\n", false)
    MLN_ASSERT_NEQf(2, 1, "%d", false)
    MLN_ASSERT_NEQfm(0.25, 0.26, "%f", "msg\n", false)
    MLN_ASSERT_GT(1, 0, false)
    MLN_ASSERT_GTm(0, -1, "msg\n", false)
    MLN_ASSERT_GTf(1, 0, "%d", false)
    MLN_ASSERT_GTfm(0, -1, "%d", "msg\n", false)
    MLN_ASSERT_GTE(0, 0, false)
    MLN_ASSERT_GTEm(3.2, 3.1, "msg\n", false)
    MLN_ASSERT_GTEf(0, 0, "%f", false)
    MLN_ASSERT_GTEfm(3.2, 3.1, "%f", "msg\n", false)
    MLN_ASSERT_LT(0, 1, false)
    MLN_ASSERT_LTm(-1252152, 2, "msg\n", false)
    MLN_ASSERT_LTf(0, 1, "%d", false)
    MLN_ASSERT_LTfm(-1252152, 2, "%d", "msg\n", false)
    MLN_ASSERT_LTE(-1, -1, false)
    MLN_ASSERT_LTEm(0, 1, "msg\n", false)
    MLN_ASSERT_LTEf(-1, -1, "%d", false)
    MLN_ASSERT_LTEfm(0, 1, "%d", "msg\n", false)
    MLN_ASSERT_IN_RANGE(0, 0.001, 0.01, false)
    MLN_ASSERT_IN_RANGEm(3, -1, 5, "msg\n", false)
    MLN_ASSERT_IN_RANGEf(0, 0.001, 0.01, "%f", false)
    MLN_ASSERT_IN_RANGEfm(3, -1, 5, "%d", "msg\n", false)
    MLN_ASSERT_STRN_EQ("a", "a", 1, false)
    MLN_ASSERT_STRN_EQm("", "", 1, "msg\n", false)
    MLN_ASSERT_STRN_EQm("", "", 0, "msg\n", false)
    MLN_ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg\n", false)
    MLN_ASSERT_STRN_NEQ("expected", "expected fasf", 9, false)
    MLN_ASSERT_STRN_NEQm("446", "actual_value", 3, "msg\n", false)
    MLN_ASSERT_STRN_GT("expected", "actual_value", 3, false)
    MLN_ASSERT_STRN_GTm("expected", "expacted", 4, "msg\n", false)
    MLN_ASSERT_STRN_GTE("expected", "expected", 8, false)
    MLN_ASSERT_STRN_GTEm("expected", "expacted", 8, "msg\n", false)
    MLN_ASSERT_STRN_LT("123", "234", 3, false)
    MLN_ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg\n", false)
    MLN_ASSERT_STRN_LTE("expected", "expected", 8, false)
    MLN_ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg\n", false)
    MLN_ASSERT_STR_EQ("a", "a", false)
    MLN_ASSERT_STR_EQm("expected", "expected", "msg\n", false)
    MLN_ASSERT_STR_NEQ("expected", "expected fasf", false)
    MLN_ASSERT_STR_NEQm("446", "actual_value", "msg\n", false)
    MLN_ASSERT_STR_GT("expected", "actual_value", false)
    MLN_ASSERT_STR_GTm("expected", "expacted", "msg\n", false)
    MLN_ASSERT_STR_GTE("expected", "exp", false)
    MLN_ASSERT_STR_GTEm("expected", "expacted", "msg\n", false)
    MLN_ASSERT_STR_LT("123", "234", false)
    MLN_ASSERT_STR_LTm("a12f3", "c234d", "msg\n", false)
    MLN_ASSERT_STR_LTE("expected", "expected", false)
    MLN_ASSERT_STR_LTEm("axpected", "ectual_value", "msg\n", false)
)

TEST(testing_fails2 , 
    ASSERT(false, false)
    ASSERTm(false, "msg\n", false)
    ASSERT_FALSE(true, false)
    ASSERT_FALSEm(1, "msg\n", false)
    char ptr[2] = {'a', 'b'};
    char* ptr2 = NULL;
    ASSERT_NULL(ptr, false)
    ASSERT_NULLm(ptr, "msg\n", false)
    ASSERT_NULLm(&hello, "hello", false)
    ASSERT_NNULL(ptr2, false)
    ASSERT_NNULLm(NULL, "msg\n", false)
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    ASSERT_MEM_EQ(a, c, 10, false)
    ASSERT_MEM_EQm(c, a, 10, "msg\n", false)
    ASSERT_MEM_NEQ(a, b, 10, false)
    ASSERT_MEM_NEQm(b, a, 10, "msg\n", false)
    ASSERT_EQ((7.5), (7.54), false)
    ASSERT_EQm('f', 'af', "msg\n", false)
    ASSERT_EQf(37.1, 15, "%.1f", false)
    ASSERT_EQfm(3, 4, "%d", "msg\n", false)
    ASSERT_NEQ(1, 1, false)
    ASSERT_NEQm(0.25, 0.25, "msg\n", false)
    ASSERT_NEQf('2', '2', "%c", false)
    ASSERT_NEQfm(0.26, 0.26, "%f", "msg\n", false)
    ASSERT_GT(0, 1, false)
    ASSERT_GTm(-5, -1, "msg\n", false)
    ASSERT_GTf(1, 10, "%d", false)
    ASSERT_GTfm(-3, -1, "%d", "msg\n", false)
    ASSERT_GTE(0, 0.001, false)
    ASSERT_GTEm(3.2, 3.2001, "msg\n", false)
    ASSERT_GTEf(0, 0.001, "%f", false)
    ASSERT_GTEfm('a', 'b', "%c", "msg\n", false)
    ASSERT_LT(0, -1, false)
    ASSERT_LTm(-1252152, -222222222, "msg\n", false)
    ASSERT_LTf(40, 1, "%d", false)
    ASSERT_LTfm(1252152, 2, "%d", "msg\n", false)
    ASSERT_LTE('b', 'a', false)
    ASSERT_LTEm(1, 0, "msg\n", false)
    ASSERT_LTEf(-1, -1.5, "%.2f", false)
    ASSERT_LTEfm(3, 1, "%d", "msg\n", false)
    ASSERT_IN_RANGE(0, 0.01, 0.001, false)
    ASSERT_IN_RANGEm(3, -1, 3, "msg\n", false)
    ASSERT_IN_RANGEf(1, 0.001, 0.01, "%f", false)
    ASSERT_IN_RANGEfm(3, -1, 3.99, "%f", "msg\n", false)
    ASSERT_STRN_EQ("a", "b", 1, false)
    ASSERT_STRN_EQm("ho", "ha", 2, "msg\n", false)
    ASSERT_STRN_EQm("expected", "expected fasf", 9, "msg\n", false)
    ASSERT_STRN_NEQ("", "", 1, false)
    ASSERT_STRN_NEQm("446", "446actual_value", 3, "msg\n", false)
    ASSERT_STRN_LT("expected", "actual_value", 3, false)
    ASSERT_STRN_LTm("expected", "expacted", 4, "msg\n", false)
    ASSERT_STRN_LTE("expected ", "expected", 9, false)
    ASSERT_STRN_LTEm("expected", "expacted", 8, "msg\n", false)
    ASSERT_STRN_GT("123", "234", 3, false)
    ASSERT_STRN_GTm("a12f3", "c234d", 5, "msg\n", false)
    ASSERT_STRN_GTE("exaected", "expected", 8, false)
    ASSERT_STRN_GTEm("axpected", "ectual_value", 1, "msg\n", false)
    ASSERT_STR_EQ("a", "b", false)
    ASSERT_STR_EQm("ho", "ha", "msg\n", false)
    ASSERT_STR_EQm("expected", "expected fasf", "msg\n", false)
    ASSERT_STR_NEQ("", "", false)
    ASSERT_STR_NEQm("446", "446", "msg\n", false)
    ASSERT_STR_LT("expected", "actual_value", false)
    ASSERT_STR_LTm("expected", "expacted", "msg\n", false)
    ASSERT_STR_LTE("expected ", "expected", false)
    ASSERT_STR_LTEm("expected", "expacted", "msg\n", false)
    ASSERT_STR_GT("123", "234", false)
    ASSERT_STR_GTm("a12f3", "c234d", "msg\n", false)
    ASSERT_STR_GTE("expected", "exqected", false)
    ASSERT_STR_GTEm("axpected", "ectual_value", "msg\n", true)
    PASS()
)
TEST(testing_fails_prefix2 , 
    MLN_ASSERT(false, false)
    MLN_ASSERTm(false, "msg\n", false)
    MLN_ASSERT_FALSE(true, false)
    MLN_ASSERT_FALSEm(1, "msg\n", false)
    char ptr[2] = {'a', 'b'};
    char* ptr2 = NULL;
    MLN_ASSERT_NULL(ptr, false)
    MLN_ASSERT_NULLm(ptr, "msg\n", false)
    MLN_ASSERT_NULLm(&hello, "hello", false)
    MLN_ASSERT_NNULL(ptr2, false)
    MLN_ASSERT_NNULLm(NULL, "msg\n", false)
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    MLN_ASSERT_MEM_EQ(a, c, 10, false)
    MLN_ASSERT_MEM_EQm(c, a, 10, "msg\n", false)
    MLN_ASSERT_MEM_NEQ(a, b, 10, false)
    MLN_ASSERT_MEM_NEQm(b, a, 10, "msg\n", false)
    MLN_ASSERT_EQ((7.5), (7.54), false)
    MLN_ASSERT_EQm('f', 'af', "msg\n", false)
    MLN_ASSERT_EQf(37.1, 15, "%.1f", false)
    MLN_ASSERT_EQfm(3, 4, "%d", "msg\n", false)
    MLN_ASSERT_NEQ(1, 1, false)
    MLN_ASSERT_NEQm(0.25, 0.25, "msg\n", false)
    MLN_ASSERT_NEQf('2', '2', "%c", false)
    MLN_ASSERT_NEQfm(0.26, 0.26, "%f", "msg\n", false)
    MLN_ASSERT_GT(0, 1, false)
    MLN_ASSERT_GTm(-5, -1, "msg\n", false)
    MLN_ASSERT_GTf(1, 10, "%d", false)
    MLN_ASSERT_GTfm(-3, -1, "%d", "msg\n", false)
    MLN_ASSERT_GTE(0, 0.001, false)
    MLN_ASSERT_GTEm(3.2, 3.2001, "msg\n", false)
    MLN_ASSERT_GTEf(0, 0.001, "%f", false)
    MLN_ASSERT_GTEfm('a', 'b', "%c", "msg\n", false)
    MLN_ASSERT_LT(0, -1, false)
    MLN_ASSERT_LTm(-1252152, -222222222, "msg\n", false)
    MLN_ASSERT_LTf(40, 1, "%d", false)
    MLN_ASSERT_LTfm(1252152, 2, "%d", "msg\n", false)
    MLN_ASSERT_LTE('b', 'a', false)
    MLN_ASSERT_LTEm(1, 0, "msg\n", false)
    MLN_ASSERT_LTEf(-1, -1.5, "%.2f", false)
    MLN_ASSERT_LTEfm(3, 1, "%d", "msg\n", false)
    MLN_ASSERT_IN_RANGE(0, 0.01, 0.001, false)
    MLN_ASSERT_IN_RANGEm(3, -1, 3, "msg\n", false)
    MLN_ASSERT_IN_RANGEf(1, 0.001, 0.01, "%f", false)
    MLN_ASSERT_IN_RANGEfm(3, -1, 3.99, "%f", "msg\n", false)
    MLN_ASSERT_STRN_EQ("a", "b", 1, false)
    MLN_ASSERT_STRN_EQm("ho", "ha", 2, "msg\n", false)
    MLN_ASSERT_STRN_EQm("expected", "expected fasf", 9, "msg\n", false)
    MLN_ASSERT_STRN_NEQ("", "", 1, false)
    MLN_ASSERT_STRN_NEQm("446", "446actual_value", 3, "msg\n", false)
    MLN_ASSERT_STRN_LT("expected", "actual_value", 3, false)
    MLN_ASSERT_STRN_LTm("expected", "expacted", 4, "msg\n", false)
    MLN_ASSERT_STRN_LTE("expected ", "expected", 9, false)
    MLN_ASSERT_STRN_LTEm("expected", "expacted", 8, "msg\n", false)
    MLN_ASSERT_STRN_GT("123", "234", 3, false)
    MLN_ASSERT_STRN_GTm("a12f3", "c234d", 5, "msg\n", false)
    MLN_ASSERT_STRN_GTE("exaected", "expected", 8, false)
    MLN_ASSERT_STRN_GTEm("axpected", "ectual_value", 1, "msg\n", false)
    MLN_ASSERT_STR_EQ("a", "b", false)
    MLN_ASSERT_STR_EQm("ho", "ha", "msg\n", false)
    MLN_ASSERT_STR_EQm("expected", "expected fasf", "msg\n", false)
    MLN_ASSERT_STR_NEQ("", "", false)
    MLN_ASSERT_STR_NEQm("446", "446", "msg\n", false)
    MLN_ASSERT_STR_LT("expected", "actual_value", false)
    MLN_ASSERT_STR_LTm("expected", "expacted", "msg\n", false)
    MLN_ASSERT_STR_LTE("expected ", "expected", false)
    MLN_ASSERT_STR_LTEm("expected", "expacted", "msg\n", false)
    MLN_ASSERT_STR_GT("123", "234", false)
    MLN_ASSERT_STR_GTm("a12f3", "c234d", "msg\n", false)
    MLN_ASSERT_STR_GTE("expected", "exqected", false)
    MLN_ASSERT_STR_GTEm("axpected", "ectual_value", "msg\n", true)
    MLN_PASS()
)

TEST(testing_bypass_pass2, 
    PASS()
    FAIL(false)
)
TEST(testing_bypass_pass_prefix2, 
    MLN_PASS()
    MLN_FAIL(false)
)
TEST(testing_bypass_skip2, 
    SKIP()
    FAIL(false)
)
TEST(testing_bypass_skip_prefix2, 
    MLN_SKIP()
    MLN_FAIL(false)
)
MLN_TEST(testing_bypass_skipm2, 
    SKIPm("msgbigbigBigBBBBIIIIGGGG HELLO asfg a\n")
    FAIL(false)
)
MLN_TEST(testing_bypass_skipm_prefix2, 
    MLN_SKIPm("msg\n")
    MLN_FAIL(false)
)
MLN_TEST(testing_bypass_fail2, 
    FAIL(false)
    PASS()
)
MLN_TEST(testing_bypass_fail_prefix2, 
    MLN_FAIL(false)
    MLN_PASS()
)
MLN_TEST(testing_bypass_failm2, 
    int adios = 2;
    FAILm("msg\n", false)
    PASS()
)
MLN_TEST(testing_bypass_failm_prefix2, 
    MLN_FAILm("msg\n", false)
    MLN_PASS()
)

MLN_TEST(testing_bypass_fail_skip2, 
    FAIL(true)
    PASS()
)
MLN_TEST(testing_bypass_fail_skip_prefix2, 
    MLN_FAIL(true)
    MLN_PASS()
)
MLN_TEST(testing_bypass_failm_skip2, 
    int adios = 2;
    FAILm("msg\n", true)
    PASS()
)
MLN_TEST(testing_bypass_failm_skip_prefix2, 
    MLN_FAILm("msg\n", true)
    MLN_PASS()
)
MLN_TEST(testing_assert_skip2, 
    ASSERT(true, true)
    ASSERT(false, true)
    PASS()
)
MLN_TEST(testing_assert_skip_prefix2, 
    MLN_ASSERT(true, true)
    MLN_ASSERT(false, true)
    MLN_PASS()
)

void test(){
    MLN_PRE_TESTS

    MLN_SET_LOGS_VERBOSITY(2)

    printf("Needs to pass\n");
    MLN_RUN_TEST(testing_passes2)
    printf("Needs to pass\n");
    MLN_RUN_TEST(testing_passes_prefix2)
    printf("Needs to pass\n");
    MLN_RUN_TEST(testing_bypass_pass2)
    printf("Needs to pass\n");
    MLN_RUN_TEST(testing_bypass_pass_prefix2)

    printf("Needs to skip\n");
    MLN_RUN_TEST(testing_bypass_skip2)
    printf("Needs to skip\n");
    MLN_RUN_TEST(testing_bypass_skip_prefix2)
    printf("Needs to skip\n");
    MLN_RUN_TEST(testing_bypass_skipm2)
    printf("Needs to skip\n");
    MLN_RUN_TEST(testing_bypass_skipm_prefix2)

    printf("Needs to fail\n");
    MLN_RUN_TEST(testing_bypass_fail2)
    printf("Needs to fail\n");
    MLN_RUN_TEST(testing_bypass_fail_prefix2)
    printf("Needs to fail\n");
    MLN_RUN_TEST(testing_bypass_failm2)
    printf("Needs to fail\n");
    MLN_RUN_TEST(testing_bypass_failm_prefix2)
    printf("Needs to fail with no passes\n");
    MLN_RUN_TEST(testing_bypass_fail_skip2)
    printf("Needs to fail with no passes\n");
    MLN_RUN_TEST(testing_bypass_fail_skip_prefix2)
    printf("Needs to fail with no passes\n");
    MLN_RUN_TEST(testing_bypass_failm_skip2)
    printf("Needs to fail with no passes\n");
    MLN_RUN_TEST(testing_bypass_failm_skip_prefix2)
    printf("Needs to fail with 1 pass\n");
    MLN_RUN_TEST(testing_assert_skip2)
    printf("Needs to fail with 1 pass\n");
    MLN_RUN_TEST(testing_assert_skip_prefix2)
    printf("Needs to fail all and not reach the final pass\n");
    MLN_RUN_TEST(testing_fails2)
    printf("Needs to fail all and not reach the final pass\n");
    MLN_RUN_TEST(testing_fails_prefix2)

    MLN_POST_TESTS
}