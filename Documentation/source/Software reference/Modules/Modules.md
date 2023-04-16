# 🧩 Module

Here you will find a full description of module.

## Overview

Xila has a modular architecture which means that each system part is a module.
A module is a part of the system responsible for a specific task. It could be an hardware abstraction layer or a library.
This way, it's easier to add new features and to debug the system since it reduces coupling.

`Module_Type` is the base type that could be derived to create a module.

:::{note}
    `Software_Type` is also a child class of `Module_Type`.
:::

:::{note}
    `Module_Type` is an alias of `Module_Class` (used by the internals).
:::

Here is the list of the modules :

```{toctree}
:maxdepth:  1
Accounts
Clipboard
Display
Drive
Flash
GPIO
Graphics
Keyboard
Mathematics
Power
Softwares
Sound
System
WiFi
```

Here you will find a full description of `Module_Type`.

## Description

A module is a part of the system responsible for a specific task. `Module_Type` is the base type that could be used type that represents a module. 
It can be a hardware abstraction layer, a software or a library.
`Module_Type` is a type that represents a module in the system. It's also 

`Module_Type` is an alias of `Module_Class`.

## Example

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Module_Class
    :members:
```