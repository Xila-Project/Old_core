# ✉️ `Instruction_Type`

Here you will find a full description of the `Instruction_Type`.

## Description

To allow `Modules` and `Software` to communicate with each other, Xila uses `Queue` systems. These allow you to send and receive data asynchronously. In order to have a standard format during this communication, the `Instruction_Type` type has been defined.

## Example

```cpp
    void My_Software::Main_Task(void*)
    {
        while(1)    // -- Endless loop because task must never return.
        {
            switch (Instance_Pointer->Get_Instruction())
            {
            case Instruction('I', 'n'): // -- Check if the instruction is equal to "In".
                // -- Do stuff.
                break;
            default:
                Xila.Task.Delay(100);   // -- Don't forget to add delay to reset watchdog.
                break;
            }

        }
    }
```

## API reference

```{eval-rst}
.. doxygentypedef:: Xila_Namespace::Instruction_Type

.. doxygenclass::   Xila_Namespace::Instruction_Class

```