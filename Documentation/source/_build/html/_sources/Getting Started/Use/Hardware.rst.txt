*********************************
Getting Started With The Hardware
*********************************

Requirements
============

In order build the reference harware kit, you will need the following parts :


If you can also buy here pre-built reference kit here, or the assembled PCB.

Intructions
===========

PCB Assembly
------------

* Solder all According to this schematic, follow this order to solder the components to the PCB :

  * SD card slot
  * Resistors
  * Headphone jack
  * Button
  * Interface connector
  * Headers
  * Mosfet transitor

* Clean the PCB using isopropyl alcohol.

Case Printing
-------------

* Download here the case files (body + bezel), and load them into your slicer (Cura, Simplify3D, PrusaSlicer ...).

* Set the following settings in the slicer:
  
  * Precision : 0.15 mm
  * Adhesion : Yes (Brim)
  * Support : Yes
  * Infill : 40 %
  * Wall thinckness 3.0 mm

* Other parameters depend on the filament you will be using, however it is recommended to use PETG.

* Once printing is complete, carefully remove all supports.

* Using the screws, thread the holes without forcing too much.
  If the screwing is too hard, use a drill and a bit to slightly widen the hole.
  Be careful not to go too fat with the mounting hole, you could damage the box.

Display Modifications
---------------------

* Solder the **2200 µF capacitor** between **+5V** and **GND** pin of the display.

Battery PCB Modifications
-------------------------

* Cut and strip a dupont wire.

* Solder this wire directly to the positive pole of the battery board (on the tab that makes contact between the PCB and the battery).

Final Assembly
--------------

* Fit and screw the main board in the box.

* Plug the ESP-32 DOIT DEVKIT V1 in the main board.

* Fit and screw the battery board in the box.
  
* Connect the battery board and the display to the main board according to this schematic : .

* Fit the lithium battery in its holder (Xila should power up).
  
* Fit and screw the display on the box.

* Fit and screw the bezel over the screen.



