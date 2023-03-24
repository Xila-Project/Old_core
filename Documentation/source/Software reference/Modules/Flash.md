#  Flash

Here you will find a full description of the flash abstraction layer.

## Example

```cpp

    uint32_t Free_Flash_Space = Xila.Flash.Get_Sketch_Free_Space(); // -- Get flash free space in bytes.
    String MD5_Checksum = Xila.Flash.Get_Sketch_MD5();              // -- Get sketch MD5 checksum.
    uint32_t Sketch_Size = Xila.Flash.Sketch_Size();                // -- Get sketch size in bytes.
    uint32_t Flash_Size = Xila.Flash.Get_Size();                    // -- Get flash size in bytes.
    uint32_t Speed = Xila.Flash.Get_Speed();                        // -- Get flash read speed in bytes / seconds.
    FlashMode_t Flash_Mode = Xila.Flash.Get_Mode()                  // -- Get flash mode.
    uint32_t Buffer[128];
    if (Xila.Flash.Read(0x100, Buffer, sizeof(Buffer)) == Xila.Success) // -- Read data from flash at the 0x100 offset.
    {
        // -- Do stuff when the operation succeed.
    }
    esp_partition* Partition = esp_ota_get_next_update_partition(NULL);
    if (Xila.Flash.Read(Partition, 0x200, Buffer, sizeof(Buffer) == Xila.Success)   // -- Read data from the current partition at the 0x200 offset.
    {
        // -- Do stuff when the operation succeed.
    } 
```
## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Flash_Class
    :members:
```