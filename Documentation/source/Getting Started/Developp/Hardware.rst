***********************************************
Getting Started With The Developpement Hardware
***********************************************

Here you will find how to set the necessary development hardware up.

This development material is optional and you can start developing right away without it.
However, it is recommended because it allows you to debug software more easily and quickly.

Requirements
============

You will need the following parts in order to start developp third party software :

* A working ``Xila hardware``.
* A ``computer``.
* 2 ``USB cable`` (usually USB A to USB B micro).
* A formated and empty ``SD card``.
* A ``SD card reader``.
* The lastest version of ``Platform IO IDE``.
* An ESP-Prog (you can also use other debbuger, but the process differ slightly, see : ...).

Instructions
============

Firstly, disconnect the Xila hardware from power and connect the ESP-Prog according to this schematic :

Then plug the ESP32 and the ESP-Prog in the computer.

Create a new project in Platform IO.

After, add the following line to the ``platformio.ini`` file.

.. code-block::

    lib_deps = alix-anneraud/Xila   ;import Xila as a library.
    upload_protocol = esp-prog      ;use ESP-Prog as a programmer.
    debug_tool = esp-prog           ;use ESP-Prog as a debugger.
    debug_init_break = tbreak setup ;set the first break point at the beggining of the setup function.

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