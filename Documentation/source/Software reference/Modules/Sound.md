# 🔈 Sound

Here you will find a full description of the sound abstraction layer.

## Overview

Sound is a module that allows to play multiples streams of audio to multiples outputs. It is using [Arduino Audio Tools](https://github.com/pschatzmann/arduino-audio-tools) library from [Phil Schatzmann](http://pschatzmann.ch/).

```{mermaid}
flowchart LR
    subgraph Inputs
        direction LR
        File
        Web_stream[Web stream]
    end
    Inputs-->Mixer
    Mixer-->Volume
    subgraph Outputs
        direction LR
        D.A.C.
        P.W.M.
        Bluetooth
    end
    Volume-->Outputs
```

## Types

The sound module is using the following types :

```{toctree}
    :maxdepth: 1

Sound/I2S_Stream



## Example

```cpp
    using namespace Xila_Namespace;

    auto Volume = Sound.Get_Volume();


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
```

## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Sound_Class
    :members:
```
