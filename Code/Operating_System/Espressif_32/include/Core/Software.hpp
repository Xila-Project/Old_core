#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "Configuration.hpp"

class Software_Handle_Class;    // Forward declaration

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
private:
    uint16_t Current_Instruction;

protected:
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
        Install_Dialog = 'I',      // Open installation form
        Desk = 'D',                // Open desk
        Open_File_Dialog = 'f',    // Open open file dialog
        Open_Folder_Dialog = 'F',  // Open open folder dialog
        Save_File_Dialog = 'e',    // Open save file dialog
        Keyboard_Dialog = 'K',     // Open keyboard dialog
        Keypad_Dialog = 'k',       // Open keyapd dialog
        Color_Picker_Dialog = 'c', // Open color picker dialog
        Power_Dialog = 'P',        // Open power dialog
        Event = 'E',               // Open event dialog
    };

    Software_Class(Software_Handle_Class &Software_Handle, uint8_t Queue_Size = DEFAULT_QUEUE_SIZE);
    virtual ~Software_Class();

    TaskHandle_t Task_Handle;
    Software_Handle_Class *Handle_Pointer;
    QueueHandle_t Instruction_Queue_Handle;

    void Send_Instruction(uint16_t);
    void Send_Instruction(char, char);

    virtual void Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    uint16_t Get_Instruction();

public:


    friend class Xila_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};

#endif