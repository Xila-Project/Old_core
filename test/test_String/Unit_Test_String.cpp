/// @file Unit_Test_String.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief String unit test source file.
/// @version 0.1.0
/// @date 05-04-2023
///
/// @copyright Copyright (c) 2023

#include "Unit_Test_String.hpp"

using namespace Xila_Namespace;

char Test_Character_Array[] = "Hello World!";
char Test_Character_Array_2[] = "Bonjour le monde!";
char Test_Concatenate_Character_Array[] = "Hello World !Bonjour le monde!";
String_Type Test_String("Hello World!");

void Unit_Test_Class::Run()
{
    UNITY_BEGIN();

    Constructors();
    Capacity();
    // Operators();
    // Concatenation();

    UNITY_END();
}

void Unit_Test_Class::Constructors()
{
    // - Default constructor
    {
        String_Type String;
        TEST_ASSERT_EQUAL_PTR(String.Characters_Pointer, NULL);
        TEST_ASSERT_NULL((const char *)String);
        TEST_ASSERT_NULL(String.Characters_Pointer);
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Size());
    }
    {
        String_Type String(Test_Character_Array);
        TEST_ASSERT_EQUAL_STRING(Test_Character_Array, (const char *)String);
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(sizeof(Test_Character_Array), String.Get_Size());
    }
    {
        String_Type String(Test_String);
        TEST_ASSERT_EQUAL_STRING(Test_Character_Array, (const char *)String);
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(sizeof(Test_Character_Array), String.Get_Size());
    }
    // - Character constructor
    for (char i = ' '; i <= '~'; i++)
    {
        char Character_Array[2] = {i, '\0'};
        String_Type String(i);
        TEST_ASSERT_EQUAL_STRING(Character_Array, (const char *)String);
        TEST_ASSERT_EQUAL_UINT(1, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(1, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(sizeof(Character_Array), String.Get_Size());
    }
}

void Unit_Test_Class::Capacity()
{
    uint32_t Heap_Size = ESP.getHeapSize();
    const uint32_t Capacity = 10;
    {
        String_Type String;
        String.Set_Capacity(Capacity);
        TEST_ASSERT_EQUAL_UINT(Capacity, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(Capacity + 1, String.Get_Size());

        String.Set_Capacity(0);
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Size());
        TEST_ASSERT_NULL((const char *)String);
        TEST_ASSERT_NULL(String.Characters_Pointer);
    }
    TEST_ASSERT_EQUAL_UINT(Heap_Size, ESP.getHeapSize());
    {
        String_Type String;
        String.Set_Size(Capacity + 1);
        TEST_ASSERT_EQUAL_UINT(Capacity, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(Capacity + 1, String.Get_Size());

        String.Set_Size(0);
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Size());
        TEST_ASSERT_NULL((const char *)String);
        TEST_ASSERT_NULL(String.Characters_Pointer);
    }
    TEST_ASSERT_EQUAL_UINT(Heap_Size, ESP.getHeapSize());
    {
        String_Type String;
        for (uint8_t i = 0; i < 255; i++)
        {
            Size_Type Capacity = rand() % 255;
            String.Set_Capacity(Capacity);
            TEST_ASSERT_EQUAL_UINT(Capacity, String.Get_Capacity());
            TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
            TEST_ASSERT_EQUAL_UINT(Capacity + 1, String.Get_Size());
        }

        String.Set_Capacity(0);
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Size());
        TEST_ASSERT_NULL((const char *)String);
        TEST_ASSERT_NULL(String.Characters_Pointer);
    }
    TEST_ASSERT_EQUAL_UINT(Heap_Size, ESP.getHeapSize());
    {
        String_Type String;
        for (uint8_t i = 0; i < 255; i++)
        {
            Size_Type Size = rand() % 255;
            String.Set_Size(Size);
            TEST_ASSERT_EQUAL_UINT(Size - 1, String.Get_Capacity());
            TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
            TEST_ASSERT_EQUAL_UINT(Size, String.Get_Size());
        }

        String.Set_Size(0);
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(0, String.Get_Size());
        TEST_ASSERT_NULL((const char *)String);
        TEST_ASSERT_NULL(String.Characters_Pointer);
    }
    TEST_ASSERT_EQUAL_UINT(Heap_Size, ESP.getHeapSize());
}

void Unit_Test_Class::Concatenation()
{
    Size_Type Heap_Size = ESP.getHeapSize();
    {
        String_Type String(Test_Character_Array);
        String.Concatenate(Test_Character_Array_2);
        TEST_ASSERT_EQUAL_STRING(Test_Concatenate_Character_Array, (const char *)String);
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(sizeof(Test_Character_Array), String.Get_Size());
    }
    TEST_ASSERT_EQUAL_UINT(Heap_Size, ESP.getHeapSize());
    {
        String_Type String(Test_Character_Array);
        String.Concatenate(Test_String);
        TEST_ASSERT_EQUAL_STRING(Test_Concatenate_Character_Array, (const char *)String);
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Capacity());
        TEST_ASSERT_EQUAL_UINT(strlen(Test_Character_Array), String.Get_Length());
        TEST_ASSERT_EQUAL_UINT(sizeof(Test_Character_Array), String.Get_Size());
    }
}