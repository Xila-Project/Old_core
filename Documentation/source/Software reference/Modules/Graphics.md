# 📊 Graphics

Here is the full description of the Graphics module. 

## Description

It is a dumb C++ wrapper for LVGL (a free and open-source graphics library for embedded devices) with additional features.
It allows the developer to create complex graphic interface with ease.

:::{warning}
    It is not recommended to use the LVGL API directly as it is not thread safe.
    The wrapper is designed to support concurrent execution using `Xila_Namespace::Semaphore_Type`.
:::

It depends on the `Display` module.

## Example

```cpp
    using namespace Xila;
    using namespace Xila::Graphics_Types;

    Window_Type Window;
    Window.Create(this);
    Window.Set_Title("Window");

    Object_Type Object;
    Object.Create(Window);
    Object.Set_Position(10, 10);
    Object.Set_Size(100, 100);
    Object.Set_Alignment(Alignment_Type::Center, 0, 10);
```

## API reference

Since it's mainly a wrapper and the library is huge, the documentation is supplied here (maybe later). Please refer to the [LVGL documentation](https://docs.lvgl.io/master/) for more information. 
