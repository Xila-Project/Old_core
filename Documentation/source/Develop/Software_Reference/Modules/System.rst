*************
System Module
*************

Here you will find a full description of the system module.

The system module is responsible for managing everything that is critical to the system.

API Reference
=============

.. doxygenclass::   Xila_Namespace::System_Class
    :members:

Example
=======

.. code-block:: c

    #include "Xila.hpp"

    void setup()
    {
        Xila.System.Start();    // -- Start Xila.
        char Device_Name[25];
        strlcpy(Device_Name, Xila.System.Get_Device_Name(), sizeof(Device_Name));   // -- Get device name.
        uint64_t eFuse_MAC = Xila.System.Get_eFuse_MAC();                           // -- Get hardware MAC address.
        char Chip_Model[32];
        strlcpy(Chip_Model, Xila.System.Get_Chip_Model(), sizeof(Chip_Model));      // -- Get chip model.
        uint32_t Chip_Cores = Xila.System.Get_Chip_Cores();                         // -- Get the amount of cores.
        uint32_t CPU_Frequency = Xila.System.Get_CPU_Frequency();                   // -- Get CPU frequency.
        char SDK_Version[32];
        strlcpy(SDK_Version, Xila.System.Get_SDK_Version(), sizeof(SDK_Version));   // -- Get SDK version.
        Xila.System.Refresh_Header();   // -- Refresh header bar.
        Xila.System.Shutdown();         // -- Shutdown Xila.
        Xila.System.Restart();          // -- Restart Xila.
        Xila.System.Hibernate();        // -- Hibernate Xila.
    }

    void loop()
    {
    }