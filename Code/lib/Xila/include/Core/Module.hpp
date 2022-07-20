///
/// @file Modules.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Modules_Hpp_Included
#define Modules_Hpp_Included

#include "Arduino.h"
#include "ArduinoJson.hpp"

class Module_Class
{
public:

    // - Types

    /// @brief Size Type;
    typedef size_t Size_Type;

    ///
    /// @brief Functions results enumeration.
    ///
    enum Result_Enumeration
    {
        Success,
        Invalid_Argument,
        Error,       ///< Error event.
        Warning,     ///< Warning event.
        Information, ///< Information event.
        Question,    ///< Question event.
        None
    };

    typedef uint8_t Result_Type;

    /// @brief Modules enumeration and type.
    typedef enum Module_Enumeration
    {
        None,
        Account,
        Clipboard,
        Account,
        Display,
        Graphical_Interface,
        System,
        Mathematics
    } Module_Type;


    /// @brief Time 
    class Time_Type
    {
    private:
    
        uint8_t Second;
        uint8_t Minute;
        uint8_t Hour;
        
        uint8_t Day;
        uint8_t Month;
        uint16_t Year;

    public:
        Date_Type();
        Date_Type(uint8_t Second, uint8_t Minute, uint8_t Hour, uint8_t Day, uint8_t Month, uint16_t Year);

        void Set(uint8_t Day, uint8_t Month, uint16_t Year);
        void Set_Day(uint8_t Day);
        void Set_Month(uint8_t Month);
        void Set_Year(uint16_t Year);

        uint8_t Get_Day();
        uint8_t Get_Month();
        uint16_t Get_Year();
    };
    
    /// @brief Xila instruction type.
    union Instruction_Type
    {

        /*
        /// @brief Instructions used by the core (with the prefix "#").
        enum Instructions_Enumeration : Xila_Class::Instruction
        {
            // -- Software state instructions
            Open = 'O',
            Close = 'C',
            Maximize = 'M',
            Minimize = 'm',
            // -- System state instructions
            Shutdown = 200,
            Restart,
            Hibernate = 'H',
            Watchdog = 'W',
        };
        */

        uint32_t Instruction;

        struct
        {
            Module_Type Sender;
            uint8_t Argument[3];
        };
    };
};

#endif
