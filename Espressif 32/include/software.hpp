#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"

class GalaxOS_Class;
class Shell_Class;
class Software_Handle_Class;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

class Software_Class //Software class, used by the core in order to communicate with the software
{
protected:
    Software_Class(Software_Handle_Class*, uint8_t&);
    ~Software_Class(); //call when soft is closed

    TaskHandle_t Task_Handle;

    uint16_t *Task_Method_Array;
    uint8_t Write_Position, Read_Position;

    Software_Handle_Class *Handle_Pointer;

    static Software_Class *Instance_Pointer;

    //API used by the core

    void Maximize(); //show
    void Minimize(); //hide

    void Open_File(File& File_To_Set);

    void Execute(uint16_t const &);
    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend class GalaxOS_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};

class Software_Handle_Class //Software "descriptor" class, used interaly to load the software
{
protected:
    uint8_t Icon;
    char *Name;                                 //used to identify the software,
    Software_Class *(*Load_Function_Pointer)(); //function called by the core to load software and return loaded software (construct class, open executable etc...)

    Software_Class *Default_Load_Function();

    //char* Get_Name();

    Software_Handle_Class(char const *Software_Name, uint8_t &Icon_ID);
    ~Software_Handle_Class();

    friend class GalaxOS_Class;
    friend class Software_Class;
    friend class Shell_Class;
};

#endif