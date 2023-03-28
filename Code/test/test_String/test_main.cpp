#include <string>

#include "Core/Module/String.hpp"

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
   {
        String_Type String;
        TEST_ASSERT_EQUAL(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL(0, String.Get_Length());
        TEST_ASSERT_EQUAL(0, String.Get_Size());
    {
        String_Type String;
        String.Set_Capacity(10);
        TEST_ASSERT_EQUAL(10, String.Get_Capacity());
        TEST_ASSERT_EQUAL(0, String.Get_Length());
        TEST_ASSERT_EQUAL(11, String.Get_Size());

        String.Set_Capacity(0);
        TEST_ASSERT_EQUAL(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL(0, String.Get_Length());
        TEST_ASSERT_EQUAL(0, String.Get_Size());
        TEST_ASSERT((const char*)String == NULL);
    }
    {
        String_Type String;
        String.Set_Size(10);
        TEST_ASSERT_EQUAL(9, String.Get_Capacity());
        TEST_ASSERT_EQUAL(0, String.Get_Length());
        TEST_ASSERT_EQUAL(10, String.Get_Size());

        String.Set_Size(0);
        TEST_ASSERT_EQUAL(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL(0, String.Get_Length());
        TEST_ASSERT_EQUAL(0, String.Get_Size());
        TEST_ASSERT((const char*)String == NULL);
    }
    {
        String_Type String(Test_Caracter_Array);
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array), String.Get_Length());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array) + 1, String.Get_Size());
    }
    {
        String_Type String(Test_String);
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array), String.Get_Length());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array) + 1, String.Get_Size());
    }
    {
        String_Type String(Test_Caracter_Array);
        String.Set_Size(String.Get_Size() + strlen(Test_Caracter_Array));
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array) * 2, String.Get_Capacity());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array), String.Get_Length());
        TEST_ASSERT_EQUAL(strlen(Test_Caracter_Array) * 2 + 1, String.Get_Size());
    }
}

void Test_String_Manipulation()
{
    {
        String_Type String(Test_Caracter_Array);
        String.Clear();
        TEST_ASSERT_EQUAL_STRING("", (const char*)String);
    }
}

void Test_String_Concatenation()
{

}

void setup()
{
    UNITY_BEGIN();

    Test_String_Constructor();
    Test_String_Capacity();
    Test_String_Manipulation();


    UNITY_END();
}

void loop()
{
}