# 👥 Accounts

Here you will find a full description of the account management module.

## Description

This module is responsible for ensuring a minimum of security (although primitive).
The identifiers are stored in a register specific to each user.

```{caution}
    In spite that credentials are hashed, salted and peppered, this module cannot be considered as secure.
```

## Example

```cpp
    using namespace Xila;

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
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Accounts_Class
    :members:
```