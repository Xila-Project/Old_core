# Base types

Xila provides a set of base types that can be used to create new types. They are stored in the `Xila_Namespace` namespace.

## Example

```cpp
    using namespace Xila;             // - - Import Xila namespace.
    //
    Boolean_Type My_Boolean = true;             // - - Create a boolean variable.
    // -  
    Byte_Type My_Byte = 0x01;                   // - - Create a byte variable.
    Word_Type My_Word = 0x0123;                 // - - Create a word variable.
    DWord_Type My_DWord = 0x012345;             // - - Create a double word variable.
    QWord_Type My_QWord = 0x0123456789ABCDEF;   // - - Create a quad word variable.
    // - Integer types
    Short_Type My_Short = 0x0001;               // - - Create a short variable.
    Integer_Type My_Integer = 0x00000001;       // - - Create a integer variable.
    Long_Type My_Long = 0x0000000000000001;     // - - Create a long variable. 
    
    // -
    Float_Type My_Float = 0.0;      // -- Create a float variable.
    Double_Type My_Double = 0.0;    // -- Create a double variable.

```

:::{important}
    On 64-bit systems, the `Long_Type` type is equivalent to the `long long` type.
:::