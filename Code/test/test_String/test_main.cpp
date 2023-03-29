#include "Arduino.h"

#include <string>

#include "Core/Module/String.hpp"

#include "unity.h"

char Test_Character_Array[] = "Hello World!";
String_Type Test_String("Hello World!");

namespace Xila_Namespace
{
    class Unit_Test_Class
    {
    private:


    public:
        void Constructor()
        {
            {
                String_Type String;
                TEST_ASSERT(String.Characters_Pointer == NULL);
                TEST_ASSERT((const char *)String == NULL);
                TEST_ASSERT_EQUAL(0, String.Get_Capacity());
                TEST_ASSERT_EQUAL(0, String.Get_Length());
            }
            {
                String_Type String(Test_Character_Array);
                TEST_ASSERT_EQUAL_STRING(Test_Character_Array, (const char *)String);
            }
            {
                String_Type String(Test_String);
                TEST_ASSERT_EQUAL_STRING(Test_Character_Array, (const char *)String);
            }
            {
                String_Type String('A');
                TEST_ASSERT_EQUAL_STRING("A", (const char *)String);
            }
        }

        void Capacity()
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
                    TEST_ASSERT((const char *)String == NULL);
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
                    TEST_ASSERT((const char *)String == NULL);
                }
                {
                    String_Type String(Test_Character_Array);
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array), String.Get_Capacity());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array), String.Get_Length());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array) + 1, String.Get_Size());
                }
                {
                    String_Type String(Test_String);
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array), String.Get_Capacity());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array), String.Get_Length());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array) + 1, String.Get_Size());
                }
                {
                    String_Type String(Test_Character_Array);
                    String.Set_Size(String.Get_Size() + strlen(Test_Character_Array));
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array) * 2, String.Get_Capacity());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array), String.Get_Length());
                    TEST_ASSERT_EQUAL(strlen(Test_Character_Array) * 2 + 1, String.Get_Size());
                }
            }
        }

        void Manipulation()
        {
            {
                String_Type String(Test_Character_Array);
                String.Clear();
                TEST_ASSERT_EQUAL_STRING("", (const char *)String);
            }
        }

        void Concatenation()
        {
        }

    } Unit_Test;
};

using namespace Xila_Namespace;

void setup()
{
    UNITY_BEGIN();

    Unit_Test.Constructor();
    Unit_Test.Capacity();
    Unit_Test.Manipulation();

    UNITY_END();
}

void loop()
{
}