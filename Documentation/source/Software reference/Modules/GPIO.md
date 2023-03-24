# 🔛 Input / Output

Here you will find a full description of the GPIO library.

## Description

The GPIO library is a wrapper for the Arduino implementation of the GPIO.

## Example

```cpp
    void Interrupt_Handler()
    {
        // -- Do stuff
    }

    void GPIO_Test()
    {
        Xila.GPIO.Set_Mode(12, Xila.GPIO.Output);    // -- Set GPIO 5 as an output.

        Xila.GPIO.Digital_Write(12, Xila.GPIO.High);    // -- Set GPIO to an high state.

        Xila.GPIO.Set_Mode(12, Xila.GPIO.Input_Pull_Up);    // -- Set GPIO 5 as an input with a pull resistor attached.
        uint16_t State = Xila.GPIO.Digital_Read(12);        // -- Read GPIO digital state.
        State = Xila.GPIO.Analog_Read(12);                  // -- Read GPIO analog state.

        Xila.GPIO.Attach_Interrupt(12, Interrupt_Handler, Xila.GPIO.Rising);   // -- Attach an the Interrupt_Handler() function to the pin twelve when the pin signal rise.
        Xila.GPIO.Detach_Interrupt(12); // -- Disable interrupt on pin 12.
    }
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Pin_Class
    :members:
```