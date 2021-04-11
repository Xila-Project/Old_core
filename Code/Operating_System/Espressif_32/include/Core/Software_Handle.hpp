#ifndef SOFTWARE_HANDLE_HPP_INCLUDED
#define SOTFWARE_HANDLE_HPP_INCLUDED

#include "Configuration.hpp"
#include "Arduino.h"

class Software_Handle_Class; // Forward declaration
class Software_Class;        // Forward declaration
class Xila_Class;            // Forward declaration
extern Xila_Class Xila;

/**
 * @class Software_Handle_Class
 * 
 * @details
 */
class Software_Handle_Class //Software "descriptor" class, used interaly to load the software
{
protected:
    ///
    /// @brief Software name
    ///
    char Name[Default_Software_Name_Length]; //used to identify the software,

    ///
    /// @brief Software icon
    ///
    uint8_t Icon;

    ///
    /// @brief Function pointer called by Xila to load software.
    /// @details Function allocate memory and return allocated software memory pointer and then send an "Open" instruction in the queue.
    ///
    Software_Class *(*Load_Function_Pointer)();

    ///
    /// @brief Function pointer that is called by Xila at startup.
    /// @details That is usefull when you whan to start a background task, or launch your application at the startup.
    ///
    void (*Startup_Function_Pointer)();

public:
    bool Is_Equal(Software_Handle_Class const &Software_Handle_To_Compare) const;

    Software_Handle_Class();
    Software_Handle_Class(const char *Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)() = NULL);
    ~Software_Handle_Class();

    friend class Xila_Class;
    friend class Software_Class;
    friend class Shell_Class;
};

bool operator==(Software_Handle_Class const &a, Software_Handle_Class const &b);

#endif