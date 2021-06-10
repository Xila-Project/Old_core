**********************
Advanced Configuration
**********************

Introduction
============

Xila being highly configurable, you will find in this section how to configure it in depth. For basic configuration, you can also check ççççç.

Firstly, Xila use registries to store its configuration. These registries have the .XRF extension and are containted in the /Xila/Registry folder.
Thanks to JavaScript Object Notation (J.S.O.N.), these registries are quite easy to apprehend.

Then, Xila checks registries as they load.
Thus, if a registry is corrupted, it will be automaticaly checked and corrected.
If Xila is not able to repair it, you just have to delete it.
A new one will be automaticaly created with default values.
So don't be afraid to get your hands dirty.

.. warning::
    Just be careful with the "System.xrf" registry. Because this one cannot be repaired.
    If a corruption occur, it is then necessary to manually replace the latter with a healthy file.


Registries Reference
====================

