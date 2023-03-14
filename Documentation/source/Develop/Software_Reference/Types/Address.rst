*********************
Variable Address Type
*********************

Here you will find a full description of the variable address type.

The variable address type is used by the core to communicate with software asynchronously.
A variable is defined by two attributes: its identifier (encoded on 16 bits) as well as its type (the core returns three types of variable: number (64 bits), string and pointer, however it is possible to use custom types).
This makes it possible in particular to easily return variables from the screen by returning a prefix made up of two characters.

.. warning::
    In order to avoid interfering with the data formatting imposed by the display, please avoid using the values in the identifier: 0x00FF, 0xFF00 and 0xFFFF.

API Reference
===============

.. doxygendefine:: Address

.. doxygentypedef:: Xila_Namespace::Address

Example
=======

.. code-block:: cpp

    void My_Software::Set_Variable(Xila_Namespace::Address Address, uint8_t Type, const void *Data)
    {
        if (Address == Address('V', 'a'))   // -- Check if the address of the variable is equal to "Va".
        {
            // -- Do stuff.
        }
    }