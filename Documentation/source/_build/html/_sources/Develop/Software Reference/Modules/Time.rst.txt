***********
Time Module
***********

Here you will find a full descrption of the time module.

This module is responsible for everything related to time.

API Reference
=============

.. doxygenclass::   Xila_Class::Time_Class
    :members:

Example
=======

.. code-block:: C

    Xila.Time.Synchronize();    // -- Ask Xila to synchronize time (not necessary, done by the core every 10 seconds).
    tm Current_Time = Xila.Time.Get_Time(); // -- Get time.
    uint32_t Cycle_Count = Xila.Time.Get_Cycle_Count(); // -- Get cycle count since the power up of the board.
    uint32_t Milliseconds = Xila.Time.Milliseconds();   // -- Get milliseconds count since the power up of the board.
    uint64_t Microseconds = Xila.Time.Microseconds();   // -- Get Microseconds count since the power up of the board.
