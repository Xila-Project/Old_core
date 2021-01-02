#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "FS.h"

class Software_Handle_Class;
class Xila_Class;
extern Xila_Class Xila;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

#define Instruction(x,y) (x * 256 + y) 

class Software_Class // Software class, API used by the core in order to communicate with the software
{
protected:
    Software_Class(uint8_t);
    virtual ~Software_Class();

    TaskHandle_t Task_Handle;

    static Software_Class *Load();

    static Software_Class *Instance_Pointer;

    static Software_Handle_Class* Handle_Pointer;

    QueueHandle_t Command_Queue_Handle;

    virtual void Open_File(File &File_To_Open);

    void Execute(uint16_t);
    void Execute(char, char);

    virtual void Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    uint16_t Get_Command();

    friend class Xila_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};


#endif