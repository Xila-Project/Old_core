# ⚙️ `Task_Type`

Here you will find a full description of `Task_Type`.

## Description

In order to allow the entire system to perform multi-threaded operations, Xila uses `Task_Type`. These execute functions 
These are functions that are executed in parallel to each others. Currently, Xila rely on the FreeRTOS scheduler to manage tasks and `Task_Class` is mainly a class wrapper of `vTaskHandle`. This wrapper also provide additional feature and insights / metrics on tasks.

:::{note}
    By default, each software has a main task created when the software is loaded. If you want to perform multi-threaded operations, you will have to create a second task, using `Task_Type::Create` or `Task_Type(...)` (not the default constructor).
:::

## Example

```cpp
    using namespace Xila;

    class My_Software : public Software_Class
    {
        // ...
        
        void My_Task_Start_Function(void*);
        void My_Task_Function();

        Task_Type My_Task;    // Create a second task.
    };

    static class My_Software_Handle : public Software_Handle_Class
    {
        // ...
    };

    void My_Software::My_Software()
    {
        My_Task.Create()
    }

    void My_Software::My_Task_Start(void* Instance)
    {
        (My_Software*)Instance->My_Task_Function();
    }

    void My_Software::My_Task_Function()
    {
        while(1)    // Endless loop because task must never return.
        {
            // Do stuff.

            Task.Delay(100);   // -- Don't forget to add delay to reset watchdog.

            Main_Task.Pause();
        }
    }
```

## API reference

```{eval-rst}
.. doxygentypedef:: Xila_Namespace::Task_Type

.. doxygenclass:: Xila_Namespace::Task_Class
    :members:
```