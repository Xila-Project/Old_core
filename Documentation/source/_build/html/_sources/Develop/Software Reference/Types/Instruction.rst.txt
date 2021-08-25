*********************
Variable Address Type
*********************

Here you will find a full descrption of the instruction type.

Similar to variable addresses, Xila communicates with software using instructions.
These instructions are encoded on 16 bits.
Thus, the system commands (see ...), or the instructions returned by the screen allowing the software to execute the user inputs.

.. warning::
    In order to avoid interfering with the data formatting imposed by the display, please avoid using instruction values : 0x00FF, 0xFF00 and 0xFFFF.

API Reference
===============

.. doxygendefine:: Instruction

.. doxygentypedef:: Xila_Class::Instruction