# 🔡 String and static string (`String_Type` / `Static_String_Type`)


## Description

In order to do without the `cstring` library which is tedious while minimizing the memory footprint of the management of character strings, Xila implements classes allowing to manipulate character strings in a simple and efficient way.

### `String_Type`

`String_Type` is a class that allows to manipulate character strings. It is a dynamic string, which means that it can be modified in size. It is also a class that allows to manage the memory of the character string in a simple and efficient way. Afin d'éviter le gaspillage de mémoire, certaines opérations ont été interdites (addition, ) qui peuvent être substitué par d'autres opérations plus efficaces (concatenation directe, ).

:::{warning}
    `String_Type` cannot be created as static global variable.
    Indeed, it is a dynamic string and therefore requires a dynamic memory allocation, which is not active at time of global variable creation.
:::

### `Static_String_Type`

Similar to `String_Type`, `Static_String_Type` (inherited from `String_Type`) is a class template for manipulating strings. However, unlike `String_Type`, `Static_String_Type` is a static string, i.e. it cannot be changed in size. It is therefore faster to handle, but requires a static memory allocation which is not practical.

:::{important}
    It's highly recommended to use `Static_String_Type` instead of `String_Type` when possible since it's faster, more efficient and avoid memory fragmentation.
:::


## Example



## API reference

```{eval-rst}
.. doxygenclass:: Xila_Namespace::String_Class
    :members:

.. doxygenclass:: Xila_Namespace::Static_String_Class
    :members:
```{eval-rst}