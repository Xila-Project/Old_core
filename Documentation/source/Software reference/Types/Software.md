# Software (`Software_Type`)

Here you will find a full description of the `Software_Type`.

## Description

`Software_Type` is an alias of the class `Software_Class` which is the base class of all software.
It's itself derived from `Module_Class` class which is the base class of all modules (like `System_Class`, `Accounts_Class`, `Graphics_Class` ...). This was done for the sake of standardization and ease of use.


Here, the software class allows the software developer to derive the software class and implement the methods and functions necessary for its proper functioning. This then makes it possible to contain the variables and functions of the software in a class. Thus, when the software is started, an instance of the class of the software in question is created. Once the software is closed, this same instance is freed. Xila also uses this API to communicate with the software (send instructions, variables etc.).

In order to facilitate software management and dynamic memory allocation (avoid fragmentation), the functions and methods of the software are stored in a class..
Thus, when software is booted, an instance of the class of the software in question is created.
Once the software is closed, this same instance is released.
Xila uses this API also to communicate with the software (send instructions, variables etc.).

:::{warning}
    Using global space in places of this class results in reduced memory available at startup.
    Indeed, this type of allocation block a part of the memory and will never be deallocated.
:::

## Example

```cpp

    Xila_Namespace::Software_Handle My_Software_Handle;

    class My_Software : public Xila_Namespace::Software
    {
    private:
        static My_Software* Instance_Pointer;   // -- Instance pointer for static function like tasks.

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

    Xila_Namespace::Software_Handle My_Software_Handle("My Software", 44, My_Software::Load);
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Software_Class
    :members:
```
