#ifdef TEST_REDUCE_TO_MACROS
#define MLN_REDUCE_MACROS_TO_FUNCTIONS
#endif

#define MLN_REMOVE_TESTS_PREFIXES

#include "utest.h"
#include "tester.h"

MLN_TEST_FUNC_DEFINITIONS

void hello(){
    printf("Hello\n");
}

TEST(testing_passes , 
    ASSERT(true)
    ASSERTm(5, "msg\n")
    ASSERT_FALSE(false)
    ASSERT_FALSEm(0, "msg\n")
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    ASSERT_NULL(ptr2)
    ASSERT_NULLm(ptr2, "msg\n")
    ASSERT_NNULL(ptr)
    ASSERT_NNULLm(ptr, "msg\n")
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    ASSERT_MEM_EQ(a, b, 10)
    ASSERT_MEM_EQm(a, b, 10, "msg\n")
    ASSERT_MEM_NEQ(a, c, 10)
    ASSERT_MEM_NEQm(a, c, 10, "msg\n")
    ASSERT_EQ((7.5), (7.5))
    ASSERT_EQm('f', 'f', "msg\n")
    ASSERT_EQf('f', 'f', "%c")
    ASSERT_EQfm(4, 4, "%d", "msg\n")
    ASSERT_NEQ(2, 1)
    ASSERT_NEQm(0.25, 0.26, "msg\n")
    ASSERT_NEQf(2, 1, "%d")
    ASSERT_NEQfm(0.25, 0.26, "%f", "msg\n")
    ASSERT_GT(1, 0)
    ASSERT_GTm(0, -1, "msg\n")
    ASSERT_GTf(1, 0, "%d")
    ASSERT_GTfm(0, -1, "%d", "msg\n")
    ASSERT_GTE(0, 0)
    ASSERT_GTEm(3.2, 3.1, "msg\n")
    ASSERT_GTEf(0, 0, "%f")
    ASSERT_GTEfm(3.2, 3.1, "%f", "msg\n")
    ASSERT_LT(0, 1)
    ASSERT_LTm(-1252152, 2, "msg\n")
    ASSERT_LTf(0, 1, "%d")
    ASSERT_LTfm(-1252152, 2, "%d", "msg\n")
    ASSERT_LTE(-1, -1)
    ASSERT_LTEm(0, 1, "msg\n")
    ASSERT_LTEf(-1, -1, "%d")
    ASSERT_LTEfm(0, 1, "%d", "msg\n")
    ASSERT_IN_RANGE(0, 0.001, 0.001)
    ASSERT_IN_RANGEm(3, -1, 5, "msg\n")
    ASSERT_IN_RANGEf(0, 0.001, 0.001, "%f")
    ASSERT_IN_RANGEfm(3, -1, 5, "%d", "msg\n")
    ASSERT_IN_NRANGE(0, 0.01, 0.001)
    ASSERT_IN_NRANGEm(3, -1, 3, "msg\n")
    ASSERT_IN_NRANGEf(0, 0.001, 0.0001, "%f")
    ASSERT_IN_NRANGEfm(3, -1, 3, "%d", "msg\n")
    ASSERT_STRN_EQ("a", "a", 1)
    ASSERT_STRN_EQm("", "", 1, "msg\n")
    ASSERT_STRN_EQm("", "", 0, "msg\n")
    ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg\n")
    ASSERT_STRN_NEQ("expected", "expected fasf", 9)
    ASSERT_STRN_NEQm("446", "actual_value", 3, "msg\n")
    ASSERT_STRN_GT("expected", "actual_value", 3)
    ASSERT_STRN_GTm("expected", "expacted", 4, "msg\n")
    ASSERT_STRN_GTE("expected", "expected", 8)
    ASSERT_STRN_GTEm("expected", "expacted", 8, "msg\n")
    ASSERT_STRN_LT("123", "234", 3)
    ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg\n")
    ASSERT_STRN_LTE("expected", "expected", 8)
    ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg\n")
    ASSERT_STR_EQ("a", "a")
    ASSERT_STR_EQm("expected", "expected", "msg\n")
    ASSERT_STR_NEQ("expected", "expected fasf")
    ASSERT_STR_NEQm("446", "actual_value", "msg\n")
    ASSERT_STR_GT("expected", "actual_value")
    ASSERT_STR_GTm("expected", "expacted", "msg\n")
    ASSERT_STR_GTE("expected", "exp")
    ASSERT_STR_GTEm("expected", "expacted", "msg\n")
    ASSERT_STR_LT("123", "234")
    ASSERT_STR_LTm("a12f3", "c234d", "msg\n")
    ASSERT_STR_LTE("expected", "expected")
    ASSERT_STR_LTEm("axpected", "ectual_value", "msg\n")
)
TEST(testing_passes_prefix , 
    MLN_ASSERT(true)
    MLN_ASSERTm(5, "msg\n")
    MLN_ASSERT_FALSE(false)
    MLN_ASSERT_FALSEm(0, "msg\n")
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    MLN_ASSERT_NULL(ptr2)
    MLN_ASSERT_NULLm(ptr2, "msg\n")
    MLN_ASSERT_NNULL(ptr)
    MLN_ASSERT_NNULLm(ptr, "msg\n")
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    MLN_ASSERT_MEM_EQ(a, b, 10)
    MLN_ASSERT_MEM_EQm(a, b, 10, "msg\n")
    MLN_ASSERT_MEM_NEQ(a, c, 10)
    MLN_ASSERT_MEM_NEQm(a, c, 10, "msg\n")
    MLN_ASSERT_EQ((7.5), (7.5))
    MLN_ASSERT_EQm('f', 'f', "msg\n")
    MLN_ASSERT_EQf('f', 'f', "%c")
    MLN_ASSERT_EQfm(4, 4, "%d", "msg\n")
    MLN_ASSERT_NEQ(2, 1)
    MLN_ASSERT_NEQm(0.25, 0.26, "msg\n")
    MLN_ASSERT_NEQf(2, 1, "%d")
    MLN_ASSERT_NEQfm(0.25, 0.26, "%f", "msg\n")
    MLN_ASSERT_GT(1, 0)
    MLN_ASSERT_GTm(0, -1, "msg\n")
    MLN_ASSERT_GTf(1, 0, "%d")
    MLN_ASSERT_GTfm(0, -1, "%d", "msg\n")
    MLN_ASSERT_GTE(0, 0)
    MLN_ASSERT_GTEm(3.2, 3.1, "msg\n")
    MLN_ASSERT_GTEf(0, 0, "%f")
    MLN_ASSERT_GTEfm(3.2, 3.1, "%f", "msg\n")
    MLN_ASSERT_LT(0, 1)
    MLN_ASSERT_LTm(-1252152, 2, "msg\n")
    MLN_ASSERT_LTf(0, 1, "%d")
    MLN_ASSERT_LTfm(-1252152, 2, "%d", "msg\n")
    MLN_ASSERT_LTE(-1, -1)
    MLN_ASSERT_LTEm(0, 1, "msg\n")
    MLN_ASSERT_LTEf(-1, -1, "%d")
    MLN_ASSERT_LTEfm(0, 1, "%d", "msg\n")
    MLN_ASSERT_IN_RANGE(0, 0.001, 0.01)
    MLN_ASSERT_IN_RANGEm(3, -1, 5, "msg\n")
    MLN_ASSERT_IN_RANGEf(0, 0.001, 0.01, "%f")
    MLN_ASSERT_IN_RANGEfm(3, -1, 5, "%d", "msg\n")
    MLN_ASSERT_IN_NRANGE(0, 0.01, 0.001)
    MLN_ASSERT_IN_NRANGEm(3, -1, 3, "msg\n")
    MLN_ASSERT_IN_NRANGEf(0, 0.001, 0.0001, "%f")
    MLN_ASSERT_IN_NRANGEfm(3, -1, 3, "%d", "msg\n")
    MLN_ASSERT_STRN_EQ("a", "a", 1)
    MLN_ASSERT_STRN_EQm("", "", 1, "msg\n")
    MLN_ASSERT_STRN_EQm("", "", 0, "msg\n")
    MLN_ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg\n")
    MLN_ASSERT_STRN_NEQ("expected", "expected fasf", 9)
    MLN_ASSERT_STRN_NEQm("446", "actual_value", 3, "msg\n")
    MLN_ASSERT_STRN_GT("expected", "actual_value", 3)
    MLN_ASSERT_STRN_GTm("expected", "expacted", 4, "msg\n")
    MLN_ASSERT_STRN_GTE("expected", "expected", 8)
    MLN_ASSERT_STRN_GTEm("expected", "expacted", 8, "msg\n")
    MLN_ASSERT_STRN_LT("123", "234", 3)
    MLN_ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg\n")
    MLN_ASSERT_STRN_LTE("expected", "expected", 8)
    MLN_ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg\n")
    MLN_ASSERT_STR_EQ("a", "a")
    MLN_ASSERT_STR_EQm("expected", "expected", "msg\n")
    MLN_ASSERT_STR_NEQ("expected", "expected fasf")
    MLN_ASSERT_STR_NEQm("446", "actual_value", "msg\n")
    MLN_ASSERT_STR_GT("expected", "actual_value")
    MLN_ASSERT_STR_GTm("expected", "expacted", "msg\n")
    MLN_ASSERT_STR_GTE("expected", "exp")
    MLN_ASSERT_STR_GTEm("expected", "expacted", "msg\n")
    MLN_ASSERT_STR_LT("123", "234")
    MLN_ASSERT_STR_LTm("a12f3", "c234d", "msg\n")
    MLN_ASSERT_STR_LTE("expected", "expected")
    MLN_ASSERT_STR_LTEm("axpected", "ectual_value", "msg\n")
)

TEST(testing_fails , 
    ASSERTi(false)
    ASSERTmi(false, "msg\n")
    ASSERT_FALSEi(true)
    ASSERT_FALSEmi(1, "msg\n")
    char ptr[2] = {'a', 'b'};
    char* ptr2 = NULL;
    ASSERT_NULLi(ptr)
    ASSERT_NULLmi(ptr, "msg\n")
    ASSERT_NULLmi(&hello, "hello")
    ASSERT_NNULLi(ptr2)
    ASSERT_NNULLmi(NULL, "msg\n")
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    ASSERT_MEM_EQi(a, c, 10)
    ASSERT_MEM_EQmi(c, a, 10, "msg\n")
    ASSERT_MEM_NEQi(a, b, 10)
    ASSERT_MEM_NEQmi(b, a, 10, "msg\n")
    ASSERT_EQi((7.5), (7.54))
    ASSERT_EQmi('f', 'af', "msg\n")
    ASSERT_EQfi(37.1, 15, "%.1f")
    ASSERT_EQfmi(3, 4, "%d", "msg\n")
    ASSERT_NEQi(1, 1)
    ASSERT_NEQmi(0.25, 0.25, "msg\n")
    ASSERT_NEQfi('2', '2', "%c")
    ASSERT_NEQfmi(0.26, 0.26, "%f", "msg\n")
    ASSERT_GTi(0, 1)
    ASSERT_GTmi(-5, -1, "msg\n")
    ASSERT_GTfi(1, 10, "%d")
    ASSERT_GTfmi(-3, -1, "%d", "msg\n")
    ASSERT_GTEi(0, 0.001)
    ASSERT_GTEmi(3.2, 3.2001, "msg\n")
    ASSERT_GTEfi(0, 0.001, "%f")
    ASSERT_GTEfmi('a', 'b', "%c", "msg\n")
    ASSERT_LTi(0, -1)
    ASSERT_LTmi(-1252152, -222222222, "msg\n")
    ASSERT_LTfi(40, 1, "%d")
    ASSERT_LTfmi(1252152, 2, "%d", "msg\n")
    ASSERT_LTEi('b', 'a')
    ASSERT_LTEmi(1, 0, "msg\n")
    ASSERT_LTEfi(-1, -1.5, "%.2f")
    ASSERT_LTEfmi(3, 1, "%d", "msg\n")
    ASSERT_IN_RANGEi(0, 0.01, 0.001)
    ASSERT_IN_RANGEmi(3, -1, 3, "msg\n")
    ASSERT_IN_RANGEfi(1, 0.001, 0.01, "%f")
    ASSERT_IN_RANGEfmi(3, -1, 3.99, "%f", "msg\n")
    ASSERT_IN_NRANGEi(0, 0.001, 0.001)
    ASSERT_IN_NRANGEmi(3, -1, 4, "msg\n")
    ASSERT_IN_NRANGEfi(0, 0.001, 0.01, "%f")
    ASSERT_IN_NRANGEfmi(3, -1, 5, "%d", "msg\n")
    ASSERT_STRN_EQi("a", "b", 1)
    ASSERT_STRN_EQmi("ho", "ha", 2, "msg\n")
    ASSERT_STRN_EQmi("expected", "expected fasf", 9, "msg\n")
    ASSERT_STRN_NEQi("", "", 1)
    ASSERT_STRN_NEQmi("446", "446actual_value", 3, "msg\n")
    ASSERT_STRN_LTi("expected", "actual_value", 3)
    ASSERT_STRN_LTmi("expected", "expacted", 4, "msg\n")
    ASSERT_STRN_LTEi("expected ", "expected", 9)
    ASSERT_STRN_LTEmi("expected", "expacted", 8, "msg\n")
    ASSERT_STRN_GTi("123", "234", 3)
    ASSERT_STRN_GTmi("a12f3", "c234d", 5, "msg\n")
    ASSERT_STRN_GTEi("exaected", "expected", 8)
    ASSERT_STRN_GTEmi("axpected", "ectual_value", 1, "msg\n")
    ASSERT_STR_EQi("a", "b")
    ASSERT_STR_EQmi("ho", "ha", "msg\n")
    ASSERT_STR_EQmi("expected", "expected fasf", "msg\n")
    ASSERT_STR_NEQi("", "")
    ASSERT_STR_NEQmi("446", "446", "msg\n")
    ASSERT_STR_LTi("expected", "actual_value")
    ASSERT_STR_LTmi("expected", "expacted", "msg\n")
    ASSERT_STR_LTEi("expected ", "expected")
    ASSERT_STR_LTEmi("expected", "expacted", "msg\n")
    ASSERT_STR_GTi("123", "234")
    ASSERT_STR_GTmi("a12f3", "c234d", "msg\n")
    ASSERT_STR_GTEi("expected", "exqected")
    ASSERT_STR_GTEm("axpected", "ectual_value", "msg\n")
    PASS()
)
TEST(testing_fails_prefix , 
    MLN_ASSERTi(false)
    MLN_ASSERTmi(false, "msg\n")
    MLN_ASSERT_FALSEi(true)
    MLN_ASSERT_FALSEmi(1, "msg\n")
    char ptr[2] = {'a', 'b'};
    char* ptr2 = NULL;
    MLN_ASSERT_NULLi(ptr)
    MLN_ASSERT_NULLmi(ptr, "msg\n")
    MLN_ASSERT_NULLmi(&hello, "hello")
    MLN_ASSERT_NNULLi(ptr2)
    MLN_ASSERT_NNULLmi(NULL, "msg\n")
    unsigned char a[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char b[10] = {2, 0, 6, 48, 128, 255, 6, 4, 0, 99};
    unsigned char c[10] = {2, 0, 9, 48, 128, 255, 8, 8, 0, 99};
    MLN_ASSERT_MEM_EQi(a, c, 10)
    MLN_ASSERT_MEM_EQmi(c, a, 10, "msg\n")
    MLN_ASSERT_MEM_NEQi(a, b, 10)
    MLN_ASSERT_MEM_NEQmi(b, a, 10, "msg\n")
    MLN_ASSERT_EQi((7.5), (7.54))
    MLN_ASSERT_EQmi('f', 'af', "msg\n")
    MLN_ASSERT_EQfi(37.1, 15, "%.1f")
    MLN_ASSERT_EQfmi(3, 4, "%d", "msg\n")
    MLN_ASSERT_NEQi(1, 1)
    MLN_ASSERT_NEQmi(0.25, 0.25, "msg\n")
    MLN_ASSERT_NEQfi('2', '2', "%c")
    MLN_ASSERT_NEQfmi(0.26, 0.26, "%f", "msg\n")
    MLN_ASSERT_GTi(0, 1)
    MLN_ASSERT_GTmi(-5, -1, "msg\n")
    MLN_ASSERT_GTfi(1, 10, "%d")
    MLN_ASSERT_GTfmi(-3, -1, "%d", "msg\n")
    MLN_ASSERT_GTEi(0, 0.001)
    MLN_ASSERT_GTEmi(3.2, 3.2001, "msg\n")
    MLN_ASSERT_GTEfi(0, 0.001, "%f")
    MLN_ASSERT_GTEfmi('a', 'b', "%c", "msg\n")
    MLN_ASSERT_LTi(0, -1)
    MLN_ASSERT_LTmi(-1252152, -222222222, "msg\n")
    MLN_ASSERT_LTfi(40, 1, "%d")
    MLN_ASSERT_LTfmi(1252152, 2, "%d", "msg\n")
    MLN_ASSERT_LTEi('b', 'a')
    MLN_ASSERT_LTEmi(1, 0, "msg\n")
    MLN_ASSERT_LTEfi(-1, -1.5, "%.2f")
    MLN_ASSERT_LTEfmi(3, 1, "%d", "msg\n")
    MLN_ASSERT_IN_RANGEi(0, 0.01, 0.001)
    MLN_ASSERT_IN_RANGEmi(3, -1, 3, "msg\n")
    MLN_ASSERT_IN_RANGEfi(1, 0.001, 0.01, "%f")
    MLN_ASSERT_IN_RANGEfmi(3, -1, 3.99, "%f", "msg\n")
    MLN_ASSERT_IN_NRANGEi(0, 0.001, 0.001)
    MLN_ASSERT_IN_NRANGEmi(3, -1, 4, "msg\n")
    MLN_ASSERT_IN_NRANGEfi(0, 0.001, 0.01, "%f")
    MLN_ASSERT_IN_NRANGEfmi(3, -1, 5, "%d", "msg\n")
    MLN_ASSERT_STRN_EQi("a", "b", 1)
    MLN_ASSERT_STRN_EQmi("ho", "ha", 2, "msg\n")
    MLN_ASSERT_STRN_EQmi("expected", "expected fasf", 9, "msg\n")
    MLN_ASSERT_STRN_NEQi("", "", 1)
    MLN_ASSERT_STRN_NEQmi("446", "446actual_value", 3, "msg\n")
    MLN_ASSERT_STRN_LTi("expected", "actual_value", 3)
    MLN_ASSERT_STRN_LTmi("expected", "expacted", 4, "msg\n")
    MLN_ASSERT_STRN_LTEi("expected ", "expected", 9)
    MLN_ASSERT_STRN_LTEmi("expected", "expacted", 8, "msg\n")
    MLN_ASSERT_STRN_GTi("123", "234", 3)
    MLN_ASSERT_STRN_GTmi("a12f3", "c234d", 5, "msg\n")
    MLN_ASSERT_STRN_GTEi("exaected", "expected", 8)
    MLN_ASSERT_STRN_GTEmi("axpected", "ectual_value", 1, "msg\n")
    MLN_ASSERT_STR_EQi("a", "b")
    MLN_ASSERT_STR_EQmi("ho", "ha", "msg\n")
    MLN_ASSERT_STR_EQmi("expected", "expected fasf", "msg\n")
    MLN_ASSERT_STR_NEQi("", "")
    MLN_ASSERT_STR_NEQmi("446", "446", "msg\n")
    MLN_ASSERT_STR_LTi("expected", "actual_value")
    MLN_ASSERT_STR_LTmi("expected", "expacted", "msg\n")
    MLN_ASSERT_STR_LTEi("expected ", "expected")
    MLN_ASSERT_STR_LTEmi("expected", "expacted", "msg\n")
    MLN_ASSERT_STR_GTi("123", "234")
    MLN_ASSERT_STR_GTmi("a12f3", "c234d", "msg\n")
    MLN_ASSERT_STR_GTEi("expected", "exqected")
    MLN_ASSERT_STR_GTEm("axpected", "ectual_value", "msg\n")
    MLN_PASS()
)

TEST(testing_bypass_pass, 
    PASS()
    FAIL()
)
TEST(testing_bypass_pass_prefix, 
    MLN_PASS()
    MLN_FAIL()
)
TEST(testing_bypass_skip, 
    SKIP()
    FAIL()
)
TEST(testing_bypass_skip_prefix, 
    MLN_SKIP()
    MLN_FAIL()
)
MLN_TEST(testing_bypass_skipm, 
    SKIPm("msgbigbigBigBBBBIIIIGGGG HELLO asfg a\n")
    FAIL()
)
MLN_TEST(testing_bypass_skipm_prefix, 
    MLN_SKIPm("msg\n")
    MLN_FAIL()
)
MLN_TEST(testing_bypass_fail, 
    FAIL()
    PASS()
)
MLN_TEST(testing_bypass_fail_prefix, 
    MLN_FAIL()
    MLN_PASS()
)
MLN_TEST(testing_bypass_failm, 
    int adios = 2;
    FAILm("msg\n")
    PASS()
)
MLN_TEST(testing_bypass_failm_prefix, 
    MLN_FAILm("msg\n")
    MLN_PASS()
)

MLN_TEST(testing_bypass_fail_skip, 
    FAIL()
    PASS()
)
MLN_TEST(testing_bypass_fail_skip_prefix, 
    MLN_FAIL()
    MLN_PASS()
)
MLN_TEST(testing_bypass_failm_skip, 
    int adios = 2;
    FAILm("msg\n")
    PASS()
)
MLN_TEST(testing_bypass_failm_skip_prefix, 
    MLN_FAILm("msg\n")
    MLN_PASS()
)
MLN_TEST(testing_assert_skip, 
    ASSERTi(true)
    ASSERT(false)
    PASS()
)
MLN_TEST(testing_assert_skip_prefix, 
    MLN_ASSERTi(true)
    MLN_ASSERT(false)
    MLN_PASS()
)
MLN_TEST(testing_assert_skip_skip, 
    ASSERTi(true)
    ASSERTi(false)
    PASS()
)
MLN_TEST(testing_assert_skip_skip_prefix, 
    MLN_ASSERTi(true)
    MLN_ASSERTi(false)
    MLN_PASS()
)

MLN_SUITE(my_suite, 
    printf("Needs to pass\n");
    RUN_TEST(testing_bypass_pass)
    printf("Needs to pass\n");
    RUN_TEST(testing_bypass_pass_prefix)

    printf("Needs to skip\n");
    RUN_TEST(testing_bypass_skip)
    printf("Needs to skip\n");
    RUN_TEST(testing_bypass_skip_prefix)
)

int main(int argc, char**argv){
    PRE_TESTS

    SET_LOGS_VERBOSITY(HIGH)

    printf("Needs to pass\n");
    RUN_TEST(testing_passes)
    printf("Needs to pass\n");
    RUN_TEST(testing_passes_prefix)

    MLN_RUN_SUITE(my_suite)

    printf("Needs to skip\n");
    RUN_TEST(testing_bypass_skipm)
    printf("Needs to skip\n");
    RUN_TEST(testing_bypass_skipm_prefix)

    printf("Needs to fail\n");
    RUN_TEST(testing_bypass_fail)
    printf("Needs to fail\n");
    RUN_TEST(testing_bypass_fail_prefix)
    printf("Needs to fail\n");
    RUN_TEST(testing_bypass_failm)
    printf("Needs to fail\n");
    RUN_TEST(testing_bypass_failm_prefix)
    printf("Needs to fail with no passes\n");
    RUN_TEST(testing_bypass_fail_skip)
    printf("Needs to fail with no passes\n");
    RUN_TEST(testing_bypass_fail_skip_prefix)
    printf("Needs to fail with no passes\n");
    RUN_TEST(testing_bypass_failm_skip)
    printf("Needs to fail with no passes\n");
    RUN_TEST(testing_bypass_failm_skip_prefix)
    printf("Needs to fail with 1 pass\n");
    RUN_TEST(testing_assert_skip)
    printf("Needs to fail with 1 pass\n");
    RUN_TEST(testing_assert_skip_prefix)
    printf("Needs to fail with 2 pass\n");
    RUN_TEST(testing_assert_skip_skip)
    printf("Needs to fail with 2 pass\n");
    RUN_TEST(testing_assert_skip_skip_prefix)
    printf("Needs to fail all and not reach the final pass\n");
    RUN_TEST(testing_fails)
    printf("Needs to fail all and not reach the final pass\n");
    RUN_TEST(testing_fails_prefix)


    printf("Needs to do an entire series of tests without interfering with the current one\n");
    test(MEDIUM, false);

    POST_TESTS(false)

    printf("Needs to do an entire series of tests without interfering with the previous two\n");
    test(LOW, false);

    printf("Needs to do an entire series of tests without interfering with the previous three\n");
    test(MINIMUM, false);

}