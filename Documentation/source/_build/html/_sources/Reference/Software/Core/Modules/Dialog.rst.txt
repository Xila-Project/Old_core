*****************
Account reference
*****************

.. toctree::
    :maxdepth:  2
    :caption:   Table Of Contents

Introduction
============

Here you will find a full descrption of the dialog module.

In order to facilitate interactions with the user, Xila offers a complete dialog box API.
Thus, it suffices to call a function to display a dialog box.
The context is then saved, then restored as soon as the control is in.

.. notes::
    A dialog box stops the execution of the task that calls it during its display time.

API description
===============

.. doxygenclass:: Xila_Class::Dialog_Class
