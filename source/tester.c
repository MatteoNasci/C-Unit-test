#ifdef TEST_REDUCE_TO_MACROS
#define MLN_REDUCE_MACROS_TO_FUNCTIONS
#endif

#define MLN_REMOVE_TESTS_PREFIXES

#include "utest.h"
#include "test_headers/tester.h"

TEST(testing_passes2 , 
    ASSERT(true)
    ASSERTm(5, "msg")
    ASSERT_FALSE(false)
    ASSERT_FALSEm(0, "msg")
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    ASSERT_NULL(ptr2)
    ASSERT_NULLm(ptr2, "msg")
    ASSERT_NNULL(ptr)
    ASSERT_NNULLm(ptr, "msg")
    ASSERT_EQ((7.5), (7.5))
    ASSERT_EQm('f', 'f', "msg\0")
    ASSERT_EQ_FORMAT('f', 'f', "%c")
    ASSERT_EQ_FORMATm(4, 4, "%d", "msg")
    ASSERT_NEQ(2, 1)
    ASSERT_NEQm(0.25, 0.26, "msg\n")
    ASSERT_GT(1, 0)
    ASSERT_GTm(0, -1, "msg")
    ASSERT_GTE(0, 0)
    ASSERT_GTEm(3.2, 3.1, "msg")
    ASSERT_LT(0, 1)
    ASSERT_LTm(-1252152, 2, "msg")
    ASSERT_LTE(-1, -1)
    ASSERT_LTEm(0, 1, "msg")
    ASSERT_IN_RANGE(0, 0.001, 0.01)
    ASSERT_IN_RANGEm(3, -1, 5, "msg")
    ASSERT_STRN_EQ("a", "a", 1)
    ASSERT_STRN_EQm("", "", 1, "msg")
    ASSERT_STRN_EQm("", "", 0, "msg")
    ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg")
    ASSERT_STRN_NEQ("expected", "expected fasf", 9)
    ASSERT_STRN_NEQm("446", "actual_value", 3, "msg")
    ASSERT_STRN_GT("expected", "actual_value", 3)
    ASSERT_STRN_GTm("expected", "expacted", 4, "msg")
    ASSERT_STRN_GTE("expected", "expected", 8)
    ASSERT_STRN_GTEm("expected", "expacted", 8, "msg")
    ASSERT_STRN_LT("123", "234", 3)
    ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg")
    ASSERT_STRN_LTE("expected", "expected", 8)
    ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg")
    ASSERT_STR_EQ("a", "a")
    ASSERT_STR_EQm("expected", "expected", "msg")
    ASSERT_STR_NEQ("expected", "expected fasf")
    ASSERT_STR_NEQm("446", "actual_value", "msg")
    ASSERT_STR_GT("expected", "actual_value")
    ASSERT_STR_GTm("expected", "expacted", "msg")
    ASSERT_STR_GTE("expected", "exp")
    ASSERT_STR_GTEm("expected", "expacted", "msg")
    ASSERT_STR_LT("123", "234")
    ASSERT_STR_LTm("a12f3", "c234d", "msg")
    ASSERT_STR_LTE("expected", "expected")
    ASSERT_STR_LTEm("axpected", "ectual_value", "msg")
)
TEST(testing_passes_prefix2 , 
    MLN_ASSERT(true)
    MLN_ASSERTm(5, "msg")
    MLN_ASSERT_FALSE(false)
    MLN_ASSERT_FALSEm(0, "msg")
    char ptr[] = {'a', 'b'};
    char* ptr2 = NULL;
    MLN_ASSERT_NULL(ptr2)
    MLN_ASSERT_NULLm(ptr2, "msg")
    MLN_ASSERT_NNULL(ptr)
    MLN_ASSERT_NNULLm(ptr, "msg")
    MLN_ASSERT_EQ((7.5), (7.5))
    MLN_ASSERT_EQm('f', 'f', "msg\0")
    MLN_ASSERT_EQ_FORMAT('f', 'f', "%c")
    MLN_ASSERT_EQ_FORMATm(4, 4, "%d", "msg")
    MLN_ASSERT_NEQ(2, 1)
    MLN_ASSERT_NEQm(0.25, 0.26, "msg\n")
    MLN_ASSERT_GT(1, 0)
    MLN_ASSERT_GTm(0, -1, "msg")
    MLN_ASSERT_GTE(0, 0)
    MLN_ASSERT_GTEm(3.2, 3.1, "msg")
    MLN_ASSERT_LT(0, 1)
    MLN_ASSERT_LTm(-1252152, 2, "msg")
    MLN_ASSERT_LTE(-1, -1)
    MLN_ASSERT_LTEm(0, 1, "msg")
    MLN_ASSERT_IN_RANGE(0, 0.001, 0.01)
    MLN_ASSERT_IN_RANGEm(3, -1, 5, "msg")
    MLN_ASSERT_STRN_EQ("a", "a", 1)
    MLN_ASSERT_STRN_EQm("", "", 1, "msg")
    MLN_ASSERT_STRN_EQm("", "", 0, "msg")
    MLN_ASSERT_STRN_EQm("expected", "expected fasf", 8, "msg")
    MLN_ASSERT_STRN_NEQ("expected", "expected fasf", 9)
    MLN_ASSERT_STRN_NEQm("446", "actual_value", 3, "msg")
    MLN_ASSERT_STRN_GT("expected", "actual_value", 3)
    MLN_ASSERT_STRN_GTm("expected", "expacted", 4, "msg")
    MLN_ASSERT_STRN_GTE("expected", "expected", 8)
    MLN_ASSERT_STRN_GTEm("expected", "expacted", 8, "msg")
    MLN_ASSERT_STRN_LT("123", "234", 3)
    MLN_ASSERT_STRN_LTm("a12f3", "c234d", 5, "msg")
    MLN_ASSERT_STRN_LTE("expected", "expected", 8)
    MLN_ASSERT_STRN_LTEm("axpected", "ectual_value", 1, "msg")
    MLN_ASSERT_STR_EQ("a", "a")
    MLN_ASSERT_STR_EQm("expected", "expected", "msg")
    MLN_ASSERT_STR_NEQ("expected", "expected fasf")
    MLN_ASSERT_STR_NEQm("446", "actual_value", "msg")
    MLN_ASSERT_STR_GT("expected", "actual_value")
    MLN_ASSERT_STR_GTm("expected", "expacted", "msg")
    MLN_ASSERT_STR_GTE("expected", "exp")
    MLN_ASSERT_STR_GTEm("expected", "expacted", "msg")
    MLN_ASSERT_STR_LT("123", "234")
    MLN_ASSERT_STR_LTm("a12f3", "c234d", "msg")
    MLN_ASSERT_STR_LTE("expected", "expected")
    MLN_ASSERT_STR_LTEm("axpected", "ectual_value", "msg")
)

MLN_TEST(time_waster2, 
    for(size_t i = 0; i < 998899889; i+=2){
        --i;
    }
    MLN_PASS()
)

TEST(testing_bypass_pass2, 
    PASS()
    FAIL()
)
TEST(testing_bypass_pass_prefix2, 
    MLN_PASS()
    MLN_FAIL()
)
TEST(testing_bypass_skip2, 
    SKIP()
    FAIL()
)
TEST(testing_bypass_skip_prefix2, 
    MLN_SKIP()
    MLN_FAIL()
)
MLN_TEST(testing_bypass_skipm2, 
    SKIPm("msg")
    FAIL()
)
MLN_TEST(testing_bypass_skipm_prefix2, 
    MLN_SKIPm("msg\n")
    MLN_FAIL()
)
MLN_TEST(testing_bypass_fail2, 
    FAIL()
    PASS()
)
MLN_TEST(testing_bypass_fail_prefix2, 
    MLN_FAIL()
    MLN_PASS()
)
MLN_TEST(testing_bypass_failm2, 
    int adios = 2;
    FAILm("msg", adios, 1, "%d", SUCCESS_DEBUG)
    PASS()
)
MLN_TEST(testing_bypass_failm_prefix2, 
    MLN_FAILm("msg\n", 1, -1, "%d", SUCCESS_DEBUG)
    MLN_PASS()
)

MLN_TEST(testing_assert_eq_fail2, 
    int num = 0;
    ASSERT_EQ(num, -1)
    PASS()
)

MLN_TEST(testing_assert_eq_fail_prefix2, 
    MLN_ASSERT_EQ(5, 1)
    MLN_PASS()
)

void test(){
    //TODO testare multipli file c per test e multiple funzioni da cui fare i test (come questo main)

    PRE_TESTS

    SET_LOGS_VERBOSITY(2)

    //Needs to pass
    RUN_TEST(testing_passes2)
    //Needs to pass
    RUN_TEST(testing_passes_prefix2)
    //Needs to pass
    RUN_TEST(testing_bypass_pass2)
    //Needs to pass
    RUN_TEST(testing_bypass_pass_prefix2)

    RUN_TEST(time_waster2)

    //Needs to skip
    RUN_TEST(testing_bypass_skip2)
    //Needs to skip
    RUN_TEST(testing_bypass_skip_prefix2)
    //Needs to skip
    RUN_TEST(testing_bypass_skipm2)
    //Needs to skip
    RUN_TEST(testing_bypass_skipm_prefix2)

    //Needs to fail
    RUN_TEST(testing_bypass_fail2)
    //Needs to fail
    RUN_TEST(testing_bypass_fail_prefix2)
    //Needs to fail
    RUN_TEST(testing_bypass_failm2)
    //Needs to fail
    RUN_TEST(testing_bypass_failm_prefix2)

    //Needs to fail
    RUN_TEST(testing_assert_eq_fail2)
    //Needs to fail 
    RUN_TEST(testing_assert_eq_fail_prefix2)

    POST_TESTS
}