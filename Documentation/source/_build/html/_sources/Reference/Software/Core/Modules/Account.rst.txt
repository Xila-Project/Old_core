****************************
Account management reference
****************************

.. toctree::
    :maxdepth:  2
    :caption:   Table Of Contents

Introduction
============

Here you will find a full description of the account management module.

In order to guarantee a minimum of security (although primitive), Xila manages the multiuser.
The identifiers are stored in a register specific to each user.

..  warning::
    As mentioned above, user credentials are stored in a register which is not encrypted.
    Thus, the recovery of identifiers is very simple.
    
.. note::
    At the moment, only one user can be logged in at a time. In order to authenticate a second user while a first is connected (lock state), this first user will have to close his session in order to allow this second user to authenticate himself.

API description
===============

.. doxygenclass:: Xila_Class::Account_Class
    :members: