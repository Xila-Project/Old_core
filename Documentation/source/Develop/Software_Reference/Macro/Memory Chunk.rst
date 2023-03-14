****************************
Memory Chunk Macro Reference
****************************

Here you will find informations about the memory chunk macro.

This macro returns the amount of bytes that match the number of chunk entered (1 chunk = 1024 bytes).

API Reference
=============

.. doxygendefine::  Memory_Chunk

Example
=======

.. code-block:: cpp

    // -- Main software task
    My_Software::Main_Task(void*)
    {
        while (1)
        {
            // -- Do stuff here
        }
    }

    // -- "My Software" constructor, called when my software is loaded into memory.
    My_Software::My_Software()  : Software(My_Software_Handle)
    {
        // -- Create a task and allocate 4096 bytes (4 * 1024 bytes) of memory for the Main_Task(void*) stack.
        Xila.Task.Create(Main_Task, "My Software Task", Memory_Chunk(4));
    }
    