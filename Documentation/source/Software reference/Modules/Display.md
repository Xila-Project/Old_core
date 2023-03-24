# 🖥️ Display

Here you will find a full description of the display abstraction layer.

## Description

This abstraction layer is responsible to drive the display.
In addition, this API supports resource protection to avoid data collisions when sending information.
This API rest upon the Nextion Library. For the full API, please visit the library page.

## Example

```cpp
    using namespace Xila;

    Xila.Display.Begin(921600, 16, 17); // -- Initialize communication with the screen to 921600 baud at pin 16 and 17.
    Xila.Display.Set_Current_Page(39);  // -- Change page to 39.
    Xila.Display.Draw_Rectangle(20, 40, 100, 200, 65535, false);    // -- Draws a filled rectangle at coordinates (20, 40) with a width of 100 and a length of 200.
    Xila.Display.Set_Text("Text", "Hello World");   // -- Set "Hello World" text in Text object.
    Xila.Display.Set_Brightness(50, false); // -- Set the brightness to half without saving it (display EEPROM).
    Xila.Display.Sleep();   // -- Turn off the display.
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Display_Class
    :members:
```

