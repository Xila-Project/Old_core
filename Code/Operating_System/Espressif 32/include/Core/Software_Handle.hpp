#ifndef SOFTWARE_HANDLE_HPP_INCLUDED
#define SOTFWARE_HANDLE_HPP_INCLUDED

#include "Arduino.h"

class Software_Handle_Class;
class Software_Class;
class Xila_Class;
extern Xila_Class Xila;

class Software_Handle_Class //Software "descriptor" class, used interaly to load the software
{
protected:
    uint8_t Icon;
    uint8_t Type;
    char Name[24]; //used to identify the software,

    Software_Class *(*Load_Function_Pointer)(); //function called by the core to load software and return loaded software (construct class, open executable etc...)

    void (*Startup_Function_Pointer)();

    void (*Background_Function_Pointer)();

    void (*Shutdown_Function_Pointer)();

    //Software_Class* Load_Function(Software_Handle_Class*);

    //char* Get_Name();

    

public:

    bool Is_Equal(Software_Handle_Class const& Software_Handle_To_Compare) const;

    void From_Char_Array(const char* Char_Array);
    void To_Char_Array(char* Char_Array);

    

    enum Software_Type
    {

    };
    
    
    Software_Handle_Class();
    Software_Handle_Class(const char* Char_Array);
    Software_Handle_Class(const char* Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)() = NULL, void (*Background_Function_Pointer)() = NULL, void (*Shutdown_Function_Pointer)() = NULL);
    ~Software_Handle_Class();

    friend class Xila_Class;
    friend class Software_Class;
    friend class Shell_Class;
};

/**
 * @param a 1st software handle to compare.
 * @param b 2nd software handle to compare.
 * 
 * @return 1 if software handle are identical and 0 if not.
*/
bool operator==(Software_Handle_Class const& a, Software_Handle_Class const& b);

#endif