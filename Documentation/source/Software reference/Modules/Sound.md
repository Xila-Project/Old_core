***********************
Sound Abstraction Layer
***********************

Here you will find a full description of the sound abstraction layer.

This abstraction layer takes care of everything related to sound like the playback of audio (WAV, MP3, AAC, Stream etc.).
This API is based on the `AudioI2S <https://github.com/schreibfaul1/ESP32-audioI2S>`_ library by `Schreibfaul <https://github.com/schreibfaul1>`_.

.. warning::

    The ``AudioI2S`` currently does not have a stable version.

API reference
=============

.. doxygenclass::   Xila_Namespace::Sound_Class
    :members:

Example
=======

```cpp

    if (Xila.Sound.Get_Volume() > 128)  // -- Check if the volume is greater than half.
    {
        Xila.Sound.Set_Volume(128); // -- Set the volume to half.
    }
    Xila.Sound.Set_Balance(0);  // -- Set balance to neutral position.
    Xila.Sound.Play("/Music.mp3");  // -- Play a music file from SD.
    Xila.Sound.Set_Loop(true);      // -- Loops playback
    uint32_t File_Size = Xila.Sound.Get_File_Size();            // -- Get current playing file size.
    uint32_t File_Position = Xila.Sound.Get_File_Position();    // -- Get current playing file position.
    uint32_t Sample_Rate = Xila.Sound.Get_Sample_Rate();        // -- Get current playing file sample rate.
    uint8_t Bit_Resolution = Xila.Sound.Get_Bit_Resolution();   // -- Get current playing file bit resolution.
    uint8_t Channels = Xila.Sound.Get_Channels();               // -- Get number of channels in the current playing file.
    uint32_t Bit_Rate = Xila.Sound.Get_Bit_Rate();              // -- Get current playing file bit rate.
    uint32_t Current_Time = Xila.Sound.Get_Current_Time();      // -- Get current playback time.
    uint32_t Duration = Xila.Sound.Get_Duration();              // -- Get current playing file duration.
    Xila.Sound.Pause();                                         // -- Pause the playback.
    Xila.Sound.Set_Current_Time(20);                            // -- Set current playback time to 20 second.
    Xila.Sound.Resume();                                        // -- Resume the playback.
    Xila.Sound.Set_Time_Offset(-5);                             // -- Comes back 5 seconds back.
    Xila.Sound.Mute();                                          // -- Mute the playback.
    Xila.Sound.Stop();                                          // -- Stop the playback
    Xila.Sound.Tone(5000, 200);                                 // -- Generate a 5 kHz tone during 200 ms.
    Xila.Sound.Tone();                                          // -- Disable tone.