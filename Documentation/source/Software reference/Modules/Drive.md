# 💾 Drive

Here you will find a full description of the drive abstraction layer.

## Description

This module is an abstranction layer for the drive and its file system.

## Example

```cpp
    Xila_Namespace::Drive_Class::Sd_Card_Type Card_Type = Xila.Drive.Type();    // -- Get card type.
    uint64_t Card_Size = Xila.Drive.Size();     // -- Get card size.
    uint64_t Available_Bytes = Xila.Drive.Total_Bytes();    // -- Get current partition available space.
    uint64_t Used_Bytes = Xila.Drive.Used_Bytes();          // -- Get current partition used space.

    Xila.Drive.Make_Directory("/Folder");       // -- Create a new folder.
    bool Exist = Xila.Drive.Exist("/Folder");   // -- Check if the folder was created.
    if (Exist)
    {
        Xila.Drive.Remove_Directory("/Folder"); // -- Delete "Folder".
    }

    File New_File = Xila.Drive.Open("/File", FILE_WRITE);    // -- Open a file in write mode, if the file does not exist, it will be created automatically.
    New_File.print("Hello World");              // -- Add "Hello World" into file.
    New_File.close();                           // -- Close file.
    Xila.Drive.Rename("/File", "/New_File");    // -- Rename "File" into "New_File".
    Xila.Drive.Remove("/New_File");             // -- Delete "New_File".
```
    
## API reference

```{eval-rst}
.. doxygenclass::   Xila_Namespace::Drive_Class
    :members:
```
