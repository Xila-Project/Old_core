#include "Core/Module/String.hpp"
#include <string>
#include "unity.h"

using namespace Xila_Namespace;

const char* Test_Caracter_Array = "Hello World!";
String_Type Test_String = "Hello World!";

void Test_String_Constructor()
{
    {
        String_Type String;
        TEST_ASSERT_EQUAL_STRING("", (const char*)String);
    }
    {
        String_Type String(Test_Caracter_Array);
        TEST_ASSERT_EQUAL_STRING(Test_Caracter_Array, (const char*)String);
    }
    {
        String_Type String(Test_String);
        TEST_ASSERT_EQUAL_STRING(Test_Caracter_Array, (const char*)String);
    }
    {
        String_Type String('A');
        TEST_ASSERT_EQUAL_STRING("A", (const char*)String);
    }
}

void Test_String_Capacity()
{
   
}


void setup()
{
    UNITY_BEGIN();

    UNITY_END();
}