#include "utest.h"

MLN_TEST(testing_stuff , 
    MLN_ASSERTm(1, "Boh")
    MLN_ASSERT(0)
)

int main(int argc, char**argv){

    MLN_PRE_TESTS

    MLN_RUN_TEST(testing_stuff)

    MLN_POST_TESTS
}