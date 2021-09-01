**********
Setup Xila
**********

Here you will find how to get started with Xila hardware and software.

Hardware
========

Requirements
------------

In order build the Xila Hardware Development Kit, you will need the following parts :

.. csv-table::
    :header-rows:   1
    :file:          

If you can also buy here pre-built Hardware Development Kit here, or the assembled PCB, in order to avoid soldering.

Instructions
------------

PCB Assembly
^^^^^^^^^^^^

* Solder all According to this schematic. In order to help the soldering process along, follow this order while soldering :

  * SD card slot
  * Resistors
  * Headphone jack
  * Button
  * Interface connector
  * Headers
  * MOSFET transistor

* Clean the PCB using isopropyl alcohol.

Case Printing
^^^^^^^^^^^^^

* Download here the case files (body + bezel), and load them into your slicer (Cura, Simplify3D, PrusaSlicer ...).

* Set the following settings in the slicer:
  
  * Precision : 0.15 mm
  * Adhesion : Yes (Brim)
  * Support : Yes
  * Infill : 40 %
  * Wall thickness 3.0 mm

* Other parameters depend on the filament you will be using, however it is recommended to use PETG.

* Once printing is complete, carefully remove all supports.

* Using the screws, thread the holes without forcing too much.
  If the screwing is too hard, use a drill and a bit to slightly widen the hole.
  Be careful not to go too fat with the mounting hole, you could damage the box.

Display Modifications (optional)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Solder the **2200 µF capacitor** between **+5V** and **GND** pin of the display.

Battery PCB Modifications
^^^^^^^^^^^^^^^^^^^^^^^^^

* Cut and strip a dupont wire.

* Solder this wire directly to the positive pole of the battery board (on the tab that makes contact between the PCB and the battery).

Final Assembly
^^^^^^^^^^^^^^

* Fit and screw the main board in the box.

* Plug the ESP-32 DOIT DEVKIT V1 in the main board.

* Fit and screw the battery board in the box.
  
* Connect the battery board and the display to the main board according to this schematic : .

* Fit the lithium battery in its holder (Xila should power up, but shut it down in order to prevent bad handling).
  
* Fit and screw the display on the box.

* Fit and screw the bezel over the screen.

Now you can power up Xila by pressing the power button.

Software
========

Requirements
------------

You will need the following parts in order to install Xila on your hardware :

* A working Xila hardware :ref:`Hardware`.
* A **computer**.
* A **USB Cable** (USB A to USB B Micro).
* A formatted and empty **SD card**.
* A **SD card reader**.
* The `installer archive <https://github.com/AlixANNERAUD/Xila/releases/download/0.1.0/Installer.zip>`_.

Instructions
------------

.. warning::
    In order to do not disturb the upload process, it's highly recommend to disconnect all other serial adapters than the related ESP32.

Firstly, decompress the downloaded ``Installer.zip`` archive in an empty folder. You will find the following file structure :

.. code::

    ├── Drive
    ├── Executables
    └── Xila Installer.py

    
Then, open the ``Xila Install.py`` script and connect the targeted **ESP32** on the compurer.
After pressing ``Y``, it will start to install ``esptool`` and ``setuptools``.
This process could take sometimes depending on your internet connection.
When the download succeed, it will start esptool which will automatically load Xila on the connected ESP32.
Once finished, just press any key to close the windows.

Finally, copy the ``Drive`` directory contents (not the directory itself) in the root of the SD card.

Then, power up Xila, and once started, an installation form should appear.

.. image:: Install.*

After completing it, the desktop should now appear.

.. image:: Desk.*
