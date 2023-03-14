***************************
Instruction Macro Reference
***************************

Here you will find informations about the instructions macro.

This macro allows to easily convert a string into an instruction encoded on 16 bits.

API Reference
=============

.. doxygendefine::  Instruction

Example
=======

.. code-block:: c

    void My_Software::My_Methods()
    {
    // -- Do stuff here.
    }

    // -- Main task
    void My_Software::Main_Task(void *)
    {
        // -- Infinite loop (a task must never return).
        while (1)
        {
            // -- Switch that bind instuctions with methods.
            switch (Instance_Pointer->Get_Instruction())
            {
                // -- Bind "MM" (0x4D4D) instruction with My_Method().
                case Instrucution('M', 'M'):
                    My_Function();
                    break;
                default:
                    break;
            }
            Xila.Task.Delay(20);    // -- Don't forget to add delay between each operation.
        }
    }
