# 🔋 Power

Here you will find a full description of the power abstraction layer.


## Example

```cpp

    uint8_t Charge_Level = Xila.Power.Get_Charge_Level();   // -- Get battery charge level in percent.
    uint16_t Voltage = Xila.Power.Get_Voltage();            // -- Get battery voltage in millivolts.
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Power_Class
    :members:
```