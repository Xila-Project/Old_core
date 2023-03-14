********************
Software Handle Type
********************
 
Here you will find a full description of the software handle.

In order to facilitate software management, Xila uses software handles.
The latter contains the basic information of the software in question (Name, Icon) and pointers to a function that to boot the software.
They are in a way the identity cards of the software.

API Reference
=============

.. doxygenclass:: Xila_Namespace::Software_Handle
    :members:

Example
=======

.. code-block:: cpp


    Xila_Namespace::Software_Handle My_Software_Handle_1("My Software 1", 44, My_Software_1::Load); // -- Create a software handle for "My Software 1"
    
    Xila_Namespace::Software_Handle My_Software_Handle_2("My Software 2", 45, My_Software_2::Load); // -- Create a software handle for "My Software 2"

    if (My_Software_Handle_1 != Software_Handle_2)  // -- Check if software handle are different.
    {
        // -- Always true.
    }

    if (!My_Software_Handle_1.Is_Equal(My_Software_Handle_2))    // -- Another way to check if software handle are different.
    {
        // -- Always true.
    }