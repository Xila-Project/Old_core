***********************************************
Getting Started With The Software Developpement
***********************************************

Here you will find how to install developpement tools in order to developp third party software for Xila.

Requirements
============

You will need the following parts in order to start developp third party software :

* A working ``Xila hardware``.
* A ``computer``.
* 2 ``USB cable`` (usually USB A to USB B micro).
* A formated and empty ``SD card``.
* A ``SD card reader``.
* The lastest version of ``Platform IO IDE``.
* The lastest version of the ``Nextion editor``.

Instructions
============

Firstly, create a new project in Platform IO.

Then, add the following line to the ``platformio.ini`` file.

.. code-block::

    lib_deps = alix-anneraud/Xila   ;import Xila as a library.

You can test your installation with the following sketch :

.. code-block:: c

    #include "Xila.hpp"

    void setup()
    {
        Xila.System.Start();
    }

    void loop()
    {
        Xila.Task.Delete();
    }

When you launch the compilation or the download of the software, **Platform IO** will take care of installing **Xila** as well as all its dependencies.

You are now ready to start developing software for **Xila**.
Consult .... in order to have more details on the functioning of **Xila**.