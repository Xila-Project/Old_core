# `Software_Type`

Here you will find a full description of the `Software_Type`.

## Description

`Software_Type` is the base class of all software on Xila. It's derivated from `Module_Type` to allow polymorphism (a Module can use the same API of another module). `Software_Type` is intended to be derived, by the developer, in order implement the methods and attributes used by the software. When an instance of the software is created (see `Software_Handle_Type`), an instance of the class is created. It's also used by Xila to communicate with the software (send `Instruction_Type`). Once the software is closed, this same instance is freed. Xila also uses this API to communicate with the software (send instructions, variables etc.).

:::{important}
    Declaring variables and functions in the global scope should be **avoided** (except for `Software_Handle_Type`), unless you know what you are doing. Indeed, the global scope is **shared** between all instances of the software and using global scope could lead to unexpected behavior. In addition, using global scope will reduce the memory available for the whole system (since it's static memory). This also apply to static member variables and functions. That do not apply to `Berry` software, since it's using it's own memory space for each instance. 
:::

:::{note}
    `Software_Type` is an alias of `Software_Class` (used by the internals).
:::

## Example

```cpp
    using namespace Xila;

    class My_Software_Class : public Software_Type
    {
    public:

        static void Main_Task(void*)
        {
            while (1)
            {
                switch (Instance_Pointer->Get_Instruction())    // -- Get instruction from the instruction queue.
                {
                case Xila.Idle: // -- Instruction when no instruction is available.
                    Instance_Pointer->Send_Instruction('T', 'e');   // -- Send the instruction "Te" to the instruction queue.
                    Xila.Task.Delay(100);   // -- Don't forget to let compute time to other software.
                    break;
                case Instruction('T', 'e'): // -- Instruction "Te"
                    Instance_Pointer->Set_Watchdog_Timeout(30000);  // -- Set watchdog timeout to maximum (30 seconds), will automatically reset to 5 seconds when delay is called.
                    // -- Do a long task here.
                    Instance_Pointer->Send_Instruction('S', 'V');   // -- Send the instruction "SV" to the instruction queue.
                    break;
                case Instruction('S', 'V'): // -- Instruction "SV"
                    {
                        long Variable_To_Send = 18;
                        Instance_Pointer->Set_Variable(Address('V', 'a'), Xila.Variable_Long, &Variable_To_Send);    // -- Set a long variable at the address "Va" with the value 18.
                    }
                    break;
                default:
                    break;
                }
            }
        }

        static Xila_Namespace::Software* Load()
        {
            if (Instance_Pointer != NULL)
            {
                delete Instance_Pointer;
            }
            Instance_Pointer = new My_Software();
            return Instance_Pointer;
        }

        My_Software() : Xila_Namespace::Software(My_Software_Handle)    // -- Constructor
        {
            Xila.Task.Create(Main_Task, "My Software Task", Memory_Chunk(4), NULL, &Task_Handle);
        }

        ~My_Software()  // -- Destructor
        {
            if (Instance_Pointer != this)
            {
                delete Instance_Pointer;
            }
            Instance_Pointer = NULL;
        }
       
    }
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Software_Class
    :members:
```
