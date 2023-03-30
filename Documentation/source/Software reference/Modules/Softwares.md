# Softwares

Here you will find a full description of the software management API.

This module is responsible for everything related to software management, such as booting, minimization, closing, watchdog etc.

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Softwares_Class
    :members:
```

## Example

```cpp
    
    extern Software_Handle My_Software_Handle;

    void My_Software::Main_Task(void*)
    {
        while (1)
        {
            switch (Instance_Pointer->Get_Instruction())
            {
                case Xila.Idle:
                    if (Xila.Software_Management.Get_State(My_Software_Handle) == Xila.Minimized)
                    {
                        Xila.Task.Delay(90);    // -- Increase delay time when minimized (90 + 10 ms).
                    }
                    Xila.Task.Delay(10) // -- Delay time when maximized (10 ms);
                    break;
                case Instruction('C', 'l'):
                    Xila.Software_Management.Close(My_Software_Handle);   // -- Ask Xila to close this software.
                    break;
                case Xila.Close:    // -- Received when the software closing was ordered by Xila, allow software to delete dynamic allocated object.
                    // -- Do stuff before closing like cleaning memory.
                    break;
                case Instruction('M', 'i'):
                    Xila.Software_Management.Minimize(My_Software_Handle);  // -- Ask Xila to minimize software.
                    break;
                case Xila.Minimize: // -- Received when the software minimizing was ordered by Xila.
                    // -- Do stuff before minimizing.
                    break;  
                case Instruction('M', 'a'):
                    Xila.Software_Management.Maximize(My_Software_Handle);  // -- Ask Xila to maximize software.
                    break;
                case Xila.Maximize: // -- Received when the software maximizing was ordered by Xila.
                    // -- Do stuff for maximizing like display software page.
                    break;
                case Instruction('T', 'e'):
                    Xila.Software_Management.Feed_Watchdog(My_Software_Handle); // -- Reset watchdog before a long task.
                    // -- Do a long task.
                    break;
                default:
                    break;
            }
        }
    }
```