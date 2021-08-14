******************
Hardware Reference
******************

.. toctree::
    :maxdepth: 2
    :caption: Table Of Contents

Introduction
============

Flexibility being the cornerstone of Xila, it is therefore possible to run Xila on a multitude of different configurations.
That is why Xila reference hardware is only here as default option for an easy quick start. It is far from perfect, but is accessible to anyone who owns a soldering iron.
So, you can change the design according to your need.
Currently only the ESP32 based boards and Nextion displays are supported, but that should not last long.
Here, you will find explaination about the general hardware design of Xila.

MCU
===

ESP32 is currently the only MCU supported by Xila.
It offers good performance for a very low price.
Other cards will be supported soon, however, it is unlikely that Xila will be able to run on MCUs less powerful than the ESP32.

Display
=======

Xila needs a screen to work.
Nextion displays are the simplest option for both relieving the MCU of graphics and also allowing rapid development (WYSIWYG IDE).
They are far from perfect, indeed, it requires a lot of energy, expensive, graphically limited, and does not allow application loading on the go (it is necessary to download the firmware each time the software bundles is modified).
Other options are currently being studied in order to overcome these various problems.
However, support for Nextion displays will not be dropped overnight.
In addition, the lack of IOs on the ESP32 will eventually force the use of another MCU.

Battery
=======

In order 

Drive
=====

Currently Xila relies on the use of SD card.
However, using other media such as SPIFFS could be a good alternative.
Indeed, this would reduce the use of the inputs and outputs of the ESP32.
But that would require an adaptation of the code may be necessary in order to limit writes and avoid premature wear of this type of memory.
Moreover, this storage method does not include any error / bad sector correction unlike SD cards.