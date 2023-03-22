# Task (`Task_Type`)

Here you will find a full description of `Task_Type`.

## Description

In order to allow the entire system to perform multiple tasks at the same time, Xila uses tasks. These are functions that are executed in parallel to each others. Currently, Xila rely on the FreeRTOS scheduler to manage tasks and `Task_Class` is mainly a class wrapper of `vTaskHandle` (but provide to system additional feature and insights / metrics).

:::{important}
    By default, each software have a main task that is automatically created when the software is loaded. This task is the one that will be executed when the software is running. If you want to create a second task, you will have to create it yourself.
:::

## Example

```cpp
    using namespace Xila_Namespace;

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

.. doxygenclass:: Xila_Namespace::Task
    :members:
```