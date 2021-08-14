*************
Release notes
*************

.. toctree::
    :maxdepth: 2
    :caption: Table Of Contents

Introduction
============

Here you will find all the notes concerning the releases.

Versions
========


0.0.2 - 2021-?-?
----------------

Added
^^^^^

- Add mosfet to switch display supply.
- Add dock defragmentation.
- Add flash management to the API.
- Add memory management to the API.
- Add Get_Cycle_Count to Time module.
- Add Local IP, Gateway IP, Subnet Mask and DNS manual configuration.
- Add WiFi automatic reconnection.
- Add dynamic memory management within Shell (load and unload part of the shell dynamicaly).
- Add mathematic features to the API.
- Add support for external D.A.C.
- Add Load and Power dialog to the API.

Changed
^^^^^^^

- Move Get_Free_Heap() from system to memeory module.
- Improve display power management.
- Increase precision of battery level readings (update battery library).
- Fix simon registry loading.
- Fix deprecated function in Periodic (with "as.<const char*()>" instead of "as.<char*>()").
- Update sound driver.
- Change Internet Browser home page.
- Change variable adress from 8 bits to 16 bits.
- Change Xila.Dialog.Dialog_Open_Folder(File&) to Xila.Dialog.Open_Folder(File&).
- Header refresh is handle by Shell, not by the Core anymore.
- How core and Shell and Core interracts for Dialogs.
- Integrate all types, class, enum in Xila_Class (reduce namespace polution).

Removed
^^^^^^^

- Remove WiFi power sleep mode patch (power button interrupt conflict).


0.0.1 - 2021-04-20
------------------

- Initial release.