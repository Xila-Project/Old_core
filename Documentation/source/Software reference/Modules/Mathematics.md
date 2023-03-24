# ✖️ Mathematics

Here you will find a full description of the mathematics module.

This module is responsible for everything related to mathematics.
It supports a large majority of mathematical functions.
Thus, almost any calculations can be performed using this module.

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Mathematics_Class
    :members:
```

## Example

```cpp

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
    double Number_3 = Xila.Mathematics.Module(90, 23);              // -- Modulo operation between 90 and 23 (is equal to 21).
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
    Number_3 = Xila.Mathematics.Power(2, 8);                            // -- Calculate 2^8 (is equal to 256).
    Number_3 = Xila.Mathematics.Square(8);                              // -- Calculate 8² (is equal to 64).
    Number_3 = Xila.Mathematics.Cube(3);                                // -- Calculate 3 cubed (is equal to 27).
    Number_3 = Xila.Mathematics.Root(6561, 8);                          // -- Calculate the root of 6561 with a base of 8 (is equal to 3).
    Number_3 = Xila.Mathematics.Square_Root(4);                         // -- Calculate the square root of 4 (is equal to 2).
    Number_3 = Xila.Mathematics.Cubic_Root(27);                         // -- Calculate the cubic root of 27 (is equal to 3).
    Number_3 = Xila.Mathematics.Exponential(4);                         // -- Calculate exponential of 4 (is equal to 54.59...).
    Number_3 = Xila.Mathematics.Logarithm(20, 5);                       // -- Calculate the base 5 logarithm of 20 (is equal to ...).
    Number_3 = Xila.Mathematics.Natural_Logarithm(36);                  // -- Calculate the natural logarithm of 36 (is equal to 3.58...).
    Number_3 = Xila.Mathematics.Decimal_Logarithm(85);                  // -- Calculate the decimal logarithm of 85 (is equal to 1.92...).

