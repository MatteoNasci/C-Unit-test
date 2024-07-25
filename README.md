#include "headers/utest.h" and you're ready to test (utest.h needs to be able to include internal_utest.h).

#define MLN_REDUCE_MACROS_TO_FUNCTIONS before the include will force most MACROS to use function calls instead, reducing code size. In this case use MLN_TEST_FUNC_DEFINITIONS after the include once in your .c .

#define MLN_REMOVE_TESTS_PREFIXES before the include to expose test macro variants without the MLN_ prefix (the MLN variants will still work regardless).

For a list of all the MACROS you can use and how to use them check the utesh.h file
