******************
Software Reference
******************

Here you will find a full description of the software type.

In order to facilitate software management and dynamic memory allocation (avoid fragmentation), the functions and methods of the software are stored in a class..
Thus, when software is booted, an instance of the class of the software in question is created.
Once the software is closed, this same instance is released.
Xila uses this API also to communicate with the software (send instructions, variables etc.).

.. warning::
    Using global space in places of this class results in reduced memory available at startup.
    Indeed, this type of allocation block a part of the memory and will never be deallocated.

API Reference
=============

.. doxygenclass::   Xila_Class::Software
    :members: