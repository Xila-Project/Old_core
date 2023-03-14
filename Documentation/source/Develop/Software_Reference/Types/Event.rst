**********
Event Type
**********

Here you will find a full description the event type.

The various functions (for example: event dialogs, file management etc.) of Xila often return an Event type in order to indicate the state of an operation.

API Reference
===============

.. doxygenenum:: Xila_Namespace::Event

Example
=======

.. code-block:: cpp

    if (Xila.Dialog.Event("Event dialog test", Xila.Information) == Xila.Default_Button_Yes)
    {
        // -- Do stuff if the "Yes" button was pressed.
    }

    if (Xila.Account.Check_Credentials("Username", "Password") == Xila.Success)
    {
        // -- Do stuff if the credentials are correct.
    }
    else
    {
        // -- Do stuff if the credentials are invalid.
    }