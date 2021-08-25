***********************
Drive Abstraction Layer
***********************

Here you will find a full descrption of the drive abstraction layer.

This abstraction layer is reponsible to store data on the drive.
Depending on the configuration selected during compilation, Xila uses the `SD <https://github.com/espressif/arduino-esp32/tree/master/libraries/SD>`_ or `SD MMC <https://github.com/espressif/arduino-esp32/tree/master/libraries/SD_MMC>`_ library (the second being faster but occupying more pins).
Thus, the API of Xila is analogous to the API offered by these two libraries.

API Reference
=============

.. doxygenclass::   Xila_Class::Drive_Class
    :members: