******************
Mathematics Module
******************

Here you will find a full description of the mathematics module.

This module is responsible for everything related to mathematics.
It supports a large majority of mathematical functions.
Thus, almost any calculations can be performed using this module.

API Reference
=============

.. doxygenclass::   Xila_Class::Mathematics_Class
    :members:

Example
=======

.. code-block:: C

    char String_To_Convert[] = "-3.14";
    double Number_1 = Xila.Mathematics.String_To_Float(String_To_Convert);
    
    if (Xila.Mathematics.Is_NAN(Number_1) == false)   // -- Check if Number_1 is a number.
    {

    }
    if (Xila.Mathematics.Is_Infinite(Number_1) == false)  // -- Check if Number_1 is infinite.
    {

    }
    double Number_2 = 2;
    Number_2 = Xila.Mathematics.Copy_Sign(Number_1, Number_2);      // -- Copy Number_1 sign to Number_2 (now equal to -2)
    Number_1 = Xila.Mathematics.Floor(Number_1);                    // -- Floor Number_1 (now equal to -3).
    double Number_3 = Xila.Mathematics.Module(90, 23);  // -- Modulo operation between 90 and 23 (is equal to 21).
    Number_3 = Xila.Mathematics.Greatest_Common_Divisor(96, 36);    // -- Calculate the greatest common divisor between 96 and 36 (is equal to 12).
    Number_3 = Xila.Mathematics.Least_Common_Multiple(96, 36);      // -- Calculate the least common multiple between 96 and 36 (is equal to 288).
    Number_3 = Xila.Mathematics.Radians(180);                       // -- Convert 180 degrees to radians (is equal to Pi).
    Number_3 = Xila.Mathematics.Radians(Xila.Mathematics.Pi/2);     // -- Convert Pi/2 radians to degrees (is equal to 90°).
    Number_3 = Xila.Mathematics.Factorial(8);                       // -- Calculate 16! (is equal to 40 320).
    Number_3 = Xila.Mathematics.Absolute(-6);                       // -- Calculate absolute value of -6 (is equal to 6).
    Number_3 = Xila.Mathematics.Inverse(2);                         // -- Calculate the inverse of 2 (is equal to 0.5).
    Number_3 = Xila.Mathematics.Combination(5, 4);                  // -- Calculate the number of combination of 4 out of 5 (is equal to 5).

    Number_3 = Xila.Mathematics.Sine((5 * Xila.Mathematics.Pi)/6);      // -- Calculate the sine of 5*Pi/6 (is equal to -0.5).
    Number_3 = Xila.Mathematics.Cosine((2 * Xila.Mathematics.Pi)/3);    // -- Calculate the cosine of 2*Pi/3 (is equal to -0.5).
    Number_3 = Xila.Mathematics.Tangent(Xila.Mathematics.Pi/4);         // -- Calculate the tangent of Pi/4 (is equal to 1).7

    