******************
Task Function Type
******************

Here you will find a full description of task function type.

API Reference
=============

.. doxygentypedef::   Xila_Class::Task_Function

Example
=======

.. code-block:: C

    Xila_Class::Task_Function My_Software::Main_Task(void*)
    {
        while (1)
        {
            // -- Do stuff.
            Xila.Task.Delay(100);   // -- Don't forget to add delay between operations.
        }
    }

    My_Software::My_Software() : Xila_Class::Software(My_Software_Handle)
    {
        Xila.Task.Create(Main_Task, "My Software Task", Memory_Chunk(4), NULL, &Task_Handle);   // -- Create task.
    }

