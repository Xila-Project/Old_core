# 🌳 Dependencies

Here is a graph representing all of the dependencies between the different files of Xila.

```{mermaid}

stateDiagram-v2

    state Platform_IO {
        Board
        Flags
    }

    Platform_IO --> Configuration

    state Configuration {
        Configuration.hpp
        Paths.hpp
        Hardware.hpp
    }

    state Base_Types {
       Base_Types.hpp
       IP_Address.hpp
       
    }

    Base_Types --> Module.hpp

    Configuration --> Module.hpp

    Module.hpp --> Modules

    Module.hpp --> Software.hpp

    Module.hpp --> Software_Handle.hpp

    Software_Handle.hpp --> Software.hpp

    state Modules {
        Accounts.hpp
        Clipboard.hpp
        Display.hpp
        Drive.hpp
        Time.hpp
        Flash.hpp
        Keyboard.hpp
        Mathematics.hpp
        Memory.hpp
        Pin.hpp
        Power.hpp

        state Communication.hpp {
            WiFi.hpp
            Bluetooth.hpp

        }

        state Graphics {
            Animation.hpp
            Arc.hpp
            
        }
    }

    Modules --> Core.hpp

    Core.hpp --> Xila.hpp

    Core.hpp --> Sources

    state Sources {
        Core.cpp
    }

    Xila.hpp --> User_Part

    Xila.hpp --> Softwares

    state Softwares {
        Shell.hpp
        ...
    }
    
    state User_Part {
        Main.cpp
    }

```