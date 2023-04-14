# 🔡 `String_Type` / `Static_String_Type`


## Description

In order to avoir the `cstring` library which is necessary to reduce the memory footprint of strings, but which is also tedious to use.
Xila implements classes allowing to manipulate character strings in a simple and efficient way.

::::{tab-set}
:::{tab-item} String_Type
`String_Type` is a class that allows to manipulate character strings. It is a dynamic string, which means that it can be modified in size. It is also a class that allows to manage the memory of the character string in a simple and efficient way. In order to avoid wasting memory,some operations have been prohibited (+) which can be substituted by other more efficient operations (+=).
:::

:::{tab-item} Static_String_Type
Similar to `String_Type`, `Static_String_Type` (inherited from `String_Type`) is a class template for manipulating strings. However, unlike `String_Type`, `Static_String_Type` is a static string, i.e. it cannot be changed in size. It is therefore faster to handle, but requires a static memory allocation which is not practical.
:::
::::

:::{warning}
    `String_Type` cannot be pre-allocated when it's declared as a global variable.
    It's due to the fact that it uses dynamic memory allocation, which may not be active at time of global variable creation.
:::

:::{important}
    It's highly recommended to use `Static_String_Type` instead of `String_Type` when possible since it's faster, more efficient and avoid memory fragmentation.
:::

## Example

```cpp

```

## API reference

```{eval-rst}
.. doxygenclass:: Xila_Namespace::String_Class
    :members:

.. doxygenclass:: Xila_Namespace::Static_String_Class
    :members:
```