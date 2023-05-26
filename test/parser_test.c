#include <ctest.h>
#include <dictionary/dictionary.h>
#define _USE_MATH_DEFINES

CTEST(upper_reg,test_upper)
{
    char str[] = "здравствуйте";
    char *test = upper_reg(str,9);

    ASSERT_STR(test,"ЗДРАВСТВУЙТЕ");
}

CTEST(punctuation,test_punctuation)
{
    char test[] = "hello?";
    char test2[] = "hello.";
    char test3[] = "hello";

    ASSERT_EQUAL(punctuation(test),'?');
    ASSERT_EQUAL(punctuation(test2),'.');
    ASSERT_EQUAL(punctuation(test3),'\0');
}

CTEST(make_arr,test_write)
{
    char str[] = "1234";
    char str2[] = "12345678";
    char test[10],test2[10];

    make_arr(test,str,2);
    make_arr(test2,str2,5);

    ASSERT_STR(test,"12");
    ASSERT_STR(test2,"12345");
}