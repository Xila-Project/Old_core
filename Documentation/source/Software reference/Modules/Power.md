# 🔋 Power

Here you will find a full description of the power abstraction layer.

## Overview

Xila provides a power abstraction layer to simplify the use of power related operations and information.

## Example

```cpp
    using namespace Xila;

    uint8_t Charge_Level = Xila.Power.Get_Charge_Level();   // -- Get battery charge level in percent.
    uint16_t Voltage = Xila.Power.Get_Voltage();            // -- Get battery voltage in millivolts.
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Power_Class
    :members:
```