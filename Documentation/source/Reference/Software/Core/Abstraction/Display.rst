*****************
Display Reference
*****************

Here you will find a full description of the display API.

Xila offers an API to easily communicate with the screen.
In addition, this API supports resource protection to avoid collisions when sending information to the screen.
This API rest upon the Nextion Library. For the full API, please visit the library page.

.. warning::
    Because Nextion displays use a serial interface (UART) to communicate, the exchange and processing of information is quite slow.
    To avoid saturation of this interface, it is recommended to deport as many commands as possible directly on the screen.

API Reference
=============

.. doxygenclass::   Xila_Class::Display_Class
    :members: