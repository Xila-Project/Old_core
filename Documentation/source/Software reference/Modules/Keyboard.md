# ⌨️ Keyboard

Here you will find a full description of the keyboard abstraction layer.

## Description

The latter is based on the `PS2Keyboard <https://github.com/PaulStoffregen/PS2Keyboard>`_ library by `Paul STOFFREGEN <https://github.com/PaulStoffregen>`_.

## Example

```cpp

    Xila.Keyboard.Clear();                  // -- Clear all registered keystrokes in the buffer.
    if (Xila.Keyboard.Available())          // -- Check if any keystroke is available in the buffer.
    {
        uint8_t Input = Xila.Keyboard.Read();   // -- Read a regular character from the keyboard.
        Input = Xila.Keyboard.Read_Raw();       // -- Read a special input from the keyboard.
    }
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Keyboard_Class
    :members:
```