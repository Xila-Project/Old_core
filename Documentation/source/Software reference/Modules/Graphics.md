# 📊 Graphics

Here is the full description of the Graphics module. 

## Description

It is a dumb C++ wrapper for LVGL, a free and open-source graphics library.
It allows the developer to simplify the creation of a graphic interface.

:::{warning}
    It is not recommended to use the LVGL API directly as it is not thread safe.
    The wrapper is designed to support concurrent execution using `Xila_Namespace::Semaphore_Type`.
:::

It depends on the Display module in order to function.

