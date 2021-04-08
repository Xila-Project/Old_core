#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "Configuration.hpp"
#include "Software_Handle.hpp"

//class Software_Handle_Class;    // Forward declaration

///
/// @brief Xila task handle type
///
typedef void *Xila_Task_Handle;

///
/// @brief Xila task function type
///
typedef void (*Xila_Task_Function)(void *);

///
/// @brief Xila instruction type
///
typedef uint16_t Xila_Instruction;

class Xila_Class;
extern Xila_Class Xila;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

#define Instruction(x, y) (x * 256 + y)

///
/// @brief Software class
///
/// @details This API is used by core in order to echange with software.
///
class Software_Class
{
protected:
    Software_Class(Software_Handle_Class &Software_Handle, uint8_t Queue_Size = Default_Instruction_Queue_Size);
    virtual ~Software_Class();

    ///
    /// @brief Instructions used by the core (with the prefix "#")
    ///
    enum Instructions
    {
        // -- General instructions
        Idle = 0,
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
        // -- Shell specials instructions

        Desk = 'D',                // Open desk
        Dialog_Open_File = 'f',    // Open open file dialog
        Dialog_Open_Folder = 'F',  // Open open folder dialog
        Dialog_Save_File = 'e',    // Open save file dialog
        Dialog_Keyboard = 'K',     // Open keyboard dialog
        Dialog_Keypad = 'k',       // Open keyapd dialog
        Dialog_Color_Picker = 'c', // Open color picker dialog
        Dialog_Power = 'P',        // Open power dialog
        Dialog_Event = 'E',        // Open event dialog
    };

    typedef enum
    {
        Minimized,
        Maximized
    } State;

    TaskHandle_t Task_Handle;

    ///
    /// @brief Software handle pointer
    ///
    Software_Handle_Class *Handle;

    void Send_Instruction(Xila_Instruction Intruction);

    ///
    /// @brief Convert "readable" instruction into xila instruction and send it.
    ///
    /// @param Instruction_Char_1 Instruction first byte
    /// @param Instruction_Char_2 Instruction second byte
    inline void Send_Instruction(char Instruction_Char_1, char Instruction_Char_2)
    {
        Send_Instruction(((uint16_t)Instruction_Char_1 << 8) | (uint16_t)Instruction_Char_2);
    }

    virtual void Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    Xila_Instruction Get_Instruction();

    void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

    friend class Xila_Class;
    friend class Shell_Class;

private:
    uint16_t Current_Instruction;
    QueueHandle_t Instruction_Queue_Handle;
    uint32_t Last_Watchdog_Feed;
    uint16_t Watchdog_Timeout;
};

#endif