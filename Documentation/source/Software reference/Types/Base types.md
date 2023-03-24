# Base types

Xila provides a set of base types that can be used to create new types. They are stored in the `Xila_Namespace` namespace.

## Description

### Boolean_Type

The `Boolean_Type` is a boolean type that can be either `true` or `false`.

### Fixed data types

| Type | Size | Range |
| --- | --- | --- |
| `Byte_Type` | 8 bits | 0 to 255 |
| `Word_Type` | 16 bits | 0 to 65 535 |
| `DWord_Type` | 32 bits | 0 to 4 294 967 295 |
| `QWord_Type` | 64 bits | 0 to 18 446 744 073 709 551 615 |

### Naturals

| Type | Size |
| --- | --- |
| `Short_Natural_Type` | Half of the registers size |
| `Natural_Type` | Register size |
| `Long_Natural_Type` | Twice the register size |

:::{tip}
    For example on a 32-bit system, a `Natural_Type` is a 32-bits unsigned integer.
:::

### Integers

| Type | Size |
| --- | --- |
| `Short_Integer_Type` | Half of the registers size |
| `Integer_Type` | Register size |
| `Long_Integer_Type` | Twice the register size |

:::{tip}
    For example on a 32-bit system, an `Integer_Type` is a 32-bits signed integer.
:::

### Floating point

| Type | Size |
| --- | --- |
| `Float_Type` | Register size |
| `Long_Float_Type` | Twice the registers size |

:::{tip}
    For example on a 32-bit system, a `Float_Type` is a 32-bits floating point number.
:::

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