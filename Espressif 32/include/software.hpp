#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "FS.h"

class GalaxOS_Class;
class Shell_Class;
class Software_Handle_Class;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

class Software_Class // Software class, used by the core in order to communicate with the software
{
protected:

    Software_Class(Software_Handle_Class*, uint8_t);

    TaskHandle_t Task_Handle;

    Software_Handle_Class* Handle_Pointer;

    static Software_Class* Instance_Pointer;

    QueueHandle_t Command_Queue_Handle;

    //API used by the core

    void Close(); // Close
    void Maximize(); // Show
    void Minimize(); // Hide

    void Open_File(File& File_To_Set);

    void Execute(uint16_t const &);
    void Execute(char const &, char const &);

    uint16_t& Get_Command();

    friend class GalaxOS_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};

class Software_Handle_Class //Software "descriptor" class, used interaly to load the software
{
protected:
    uint8_t Icon;
    char *Name;                                 //used to identify the software,
    Software_Class *(*Load_Function_Pointer)(Software_Handle_Class*); //function called by the core to load software and return loaded software (construct class, open executable etc...)

    Software_Class *Default_Load_Function(Software_Handle_Class*);

    //char* Get_Name();

    Software_Handle_Class(char const *Software_Name, uint8_t &Icon_ID);
    ~Software_Handle_Class();

    friend class GalaxOS_Class;
    friend class Software_Class;
    friend class Shell_Class;
};

#endif