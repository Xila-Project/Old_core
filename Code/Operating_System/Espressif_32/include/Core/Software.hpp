#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"
#include "Configuration.hpp"

class Software_Handle_Class;
class Xila_Class;
extern Xila_Class Xila;

#define SOFTWARE_TYPE_LOADED 0
#define SOFTWARE_TYPE_COMPILED 1
#define SOFTWARE_TYPE_INTERPRETED 2

#define Instruction(x,y) (x * 256 + y) 

class Software_Class // Software class, API used by the core in order to communicate with the software
{
private:
    uint16_t Current_Instruction;


protected:
    Software_Class(Software_Handle_Class& Software_Handle, uint8_t Queue_Size = DEFAULT_QUEUE_SIZE);
    virtual ~Software_Class();



    TaskHandle_t Task_Handle;

    //static Software_Class *Load();

    //static Software_Class *Instance_Pointer;

    Software_Handle_Class* Handle_Pointer;

    QueueHandle_t Instruction_Queue_Handle;

    // Main methods used by the core to communicate

    void Send_Instruction(uint16_t);
    void Send_Instruction(char, char);

    virtual void Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    uint16_t Get_Instruction();

public:


    enum Image
    {

    };

    friend class Xila_Class;
    friend class Software_Handle_Class;
    friend class Shell_Class;
};

#endif