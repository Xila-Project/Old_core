Getting Started With The Software
=================================

Here you will find how to install Xila on your hardware.

.. contents:: Contents
    :local:

Requirements
------------

You will need the following parts in order to install Xila on your hardware :

* A working Xila hardware :ref:`Hardware`.
* A **computer**.
* A **USB Cable** (USB A to USB B Micro).
* A formated and empty **SD card**.
* A **SD card reader**.
* The installer archive <https://github.com/AlixANNERAUD/Xila/releases/download/0.1.0/Installer.zip>.

Instructions
------------

.. warning::
    In order to do not distrurb the upload process, it's highly recommend to disconnect all other serial adaptaters than the related ESP32.

Firstly, decompress the downloaded ``Installer.zip`` archive in an empty folder. You will find the following file structure :

.. code::

    ├── Drive
    ├── Executables
    └── Xila Installer.py

    
Then, open the ``Xila Install.py`` script and connect the targetted **ESP32** on the comptuer.
After pressing ``Y``, it will start to install ``esptool`` and ``setuptools``.
This process could take sometimes depending on your internet connection.
When the download succeed, it will start esptool which will automaticaly load Xila on the connected ESP32.
Once finished, just press any key to close the windows.

Finally, copy the ``Drive`` directory contents (not the directory itself) in the root of the SD card.

Then, power up Xila hardware and you are good to go 😊.
