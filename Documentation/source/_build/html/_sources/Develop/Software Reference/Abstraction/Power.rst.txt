***********************
Power Abstraction Layer
***********************

Here you will find a full description of the power abstraction layer.

API Reference
=============

.. doxygenclass::   Xila_Class::Power_Class
    :members:

Example
=======

.. code-block:: C

    uint8_t Charge_Level = Xila.Power.Get_Charge_Level();   // -- Get battery charge level in percent.
    uint16_t Voltage = Xila.Power.Get_Voltage();            // -- Get battery voltage in millivolts.