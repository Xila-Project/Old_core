# 🤏 `Software_Handle_Type`
 
Here you will find a full description of the `Software_Handle_Type`.

## Overview

In order to manage software, `Softwares` modules uses `Software_Handle_Type`. The latter contains the basic information of the software in question (name and constructor call). It's also used to identify a software (see `Software_Type`). `Software_Handle_Type` is intended to be derived by the developer, in order to create a software handle for each software.

:::{important}
    Software handle must be declared in the global scope to be registered by Xila. Indeed, the it's the software handle's constructor that register the handle. `static` class attributes do not work due to compiler optimization.
:::

:::{note}
    `Software_Handle_Type` is an alias of `Software_Handle_Class` (used by the internals).
:::

## Example

```cpp
    using namespace Xila;

    class My_Software_Class : public Software_Type
    {
        
        // ...
    };

    static class My_Software_Handle_Class : public Software_Handle_Type
    {
    public:
        My_Software_Handle_Class() : Software_Handle_Type("My software") {} // - Register the software handle.

        Software_Type* Create_Instance()
        {
            return new My_Software_Class(); // - Return a new instance of the software.
        }
    } My_Software_Handle;
```

## API reference

```{eval-rst}
.. doxygenclass:: Xila_Namespace::Software_Handle_Class
    :members:
```

