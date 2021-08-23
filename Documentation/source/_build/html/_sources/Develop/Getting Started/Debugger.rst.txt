*******************************
Getting Started With A Debugger
*******************************

Here you will find how to start with a debugger.

.. note::

    The debugger is optional, you can start developing right away without it.
    However, it is recommended because it allows you to debug software more easily and quickly.

Requirements
============

You will need the following parts in order to start develop third party software :

* A working ``Xila hardware``.
* A ``computer``.
* 2 ``USB cable`` (usually USB A to USB B micro).
* A formatted and empty ``SD card``.
* A ``SD card reader``.
* The latest version of `Platform IO IDE <https://platformio.org/platformio-ide>`_.
* A configured Xila project.
* An ESP-Prog (you can also use other debugger, but the process differ slightly, see `platform io debugging page <https://docs.platformio.org/en/latest/plus/debugging.html>`_ for more informations).

Instructions
============

Firstly, disconnect the Xila hardware from power and connect the ESP-Prog according to this schematic :

Then plug the ESP32 and the ESP-Prog in the computer.

Create a new project in Platform IO.

After, add the following line to the ``platformio.ini`` file.

.. code-block::

    upload_protocol = esp-prog      ;use ESP-Prog as a programmer.
    debug_tool = esp-prog           ;use ESP-Prog as a debugger.
    debug_init_break = tbreak setup ;set the first break point at the beginning of the setup function.

.. note::
    Depending on the debugger used as well as the platform, the configuration file may differ slightly.
    See `platform io debugging page <https://docs.platformio.org/en/latest/plus/debugging.html>`_ for more informations.

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
Consult :ref:`hardware reference` in order to have more details on the functioning of **Xila**.