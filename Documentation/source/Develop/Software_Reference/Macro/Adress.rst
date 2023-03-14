**********************
Adress Macro Reference
**********************

Here you will find informations about the adress macro.

This macro allows to easily convert a string into an address encoded on 16 bits

API Reference
=============

.. doxygendefine:: Address

Example
=======

.. code-block:: c
    
    double My_Variable;

    void My_Software::Set_Variable(Xila_Class::Address Address, Xila_Class::Type Type, const void *Data)
    {
        // -- Binds "MV" (0x4D56) address with My_Variable.
        if (Address == Address('M', 'V'))
        {
                My_Variable = *(double *)Data;
        }
    }