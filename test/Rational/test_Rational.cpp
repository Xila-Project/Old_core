#include <Arduino.h>

#include "Mathematics/Rational.hpp"

#include <unity.h>

using namespace Xila_Namespace;
using namespace Xila_Namespace::Mathematics_Types;

namespace Xila_Namespace
{
    class Unit_Test_Class
    {
    public:
        void Constructor()
        {
            {
                Rational_Class Rational(1, 2);
                TEST_ASSERT_EQUAL(1, Rational.Get_Numerator());
                TEST_ASSERT_EQUAL(2, Rational.Get_Denominator());
            }
      
        }

    } Unit_Test;
}

void setup()
{
    UNITY_BEGIN();

    UNITY_TEST_ASSERT_EQUAL_FLOAT(1.0, 1.0, 0, "Test 1");

    UNITY_END();
}

void loop()
{
}