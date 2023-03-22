*************************
Account Management Module
*************************

Here you will find a full description of the account management module.

This module is responsible for ensuring a minimum of security (although primitive).
The identifiers are stored in a register specific to each user.

..  warning::
    As mentioned above, user credentials are stored in a register which is not encrypted.
    Thus, the recovery of identifiers is very simple.
    
.. note::
    At the moment, only one user can be logged in at a time. In order to authenticate a second user while a first is connected (lock state), this first user will have to close his session in order to allow this second user to authenticate himself.

API Reference
=============

.. doxygenclass::   Xila_Namespace::Account_Class
    :members:

Example
=======

.. code-block:: cpp

    if (Xila.Account.Check_Credentials("User", "Password") == Xila.Success) // -- Check if the credentials are correct.
    {
        // -- Do stuff when the credentials are rights.
    }
    else
    {
        // -- Do stuff when the credentials are wrong.
    }
    char Username[9];
    strlcpy(Username, Xila.Account.Get_Current_Username(), sizeof(Username));   // -- Get username of the current user.
    if (Xila.Account.Get_State == Xila.Account.Logged)  // -- Check user session state.
    {
        // -- Do stuff when user is connected.
    }
    else if (Xila.Account.Get_State == Xila.Account.Locked)
    {
        // -- Do stuff when user account is locked.
    }
    else
    {
        // -- Do stuff when no user is connected.
    }
