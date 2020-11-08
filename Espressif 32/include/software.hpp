#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "FS.h"



class Software_Handle_Class;
class GalaxOS_Class;
extern GalaxOS_Class GalaxOS;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

enum Software_Code // System code used by the core to communicate
{
    Close = 0x0043,
    Maximize = 0x004D,
    Minimize = 0x006D,
    Open = 0x004F
};

class Software_Class // Software class, used by the core in order to communicate with the software
{
protected:
    Software_Class(uint8_t);
    virtual ~Software_Class();

    TaskHandle_t Task_Handle;

    static Software_Class *Load();

    static Software_Class *Instance_Pointer;

    static Software_Handle_Class *Handle_Pointer;

    QueueHandle_t Command_Queue_Handle;

    //API used by the core

    void Close();    // Close
    void Maximize(); // Show
    void Minimize(); // Hide

    virtual void Open_File(File &File_To_Open);

    void Execute(uint16_t);
    void Execute(char, char);

    virtual void Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    uint16_t Get_Command();

    friend class GalaxOS_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};

class Software_Handle_Class //Software "descriptor" class, used interaly to load the software
{
protected:
    uint8_t Icon;
    char Name[24]; //used to identify the software,

    Software_Class *(*Load_Function_Pointer)(); //function called by the core to load software and return loaded software (construct class, open executable etc...)

    //Software_Class* Load_Function(Software_Handle_Class*);

    //char* Get_Name();

    friend class GalaxOS_Class;
    friend class Software_Class;
    friend class Shell_Class;

public:
    Software_Handle_Class(char const *Software_Name, uint8_t Icon_ID, Software_Class *(*Load_Function_Pointer_To_Set)());
    ~Software_Handle_Class();
};

#endif