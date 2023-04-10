/// @file Berry.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-03-2023
///
/// @copyright Copyright (c) 2023

#ifndef Berry_Hpp_Included
#define Berry_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

// - Forward declaration

typedef struct bvm bvm;
typedef int (*bntvfunc)(bvm *);


/// @brief Berry class
class Berry_Class : public Software_Type
{
    // - Methods

    // - - Constructors / destructor
    Berry_Class(const Accounts_Types::User_Type *Owner_User);
    ~Berry_Class();

    // - - Task
    void Main_Task_Function() override;

    // - - Others
    void Execute_Instruction(const Instruction_Type &Instruction);

    // - - - Berry

    void Virtual_Machine_Create();
    void Virtual_Machine_Delete();
    void Virtual_Machine_Register_Function(const char *Name, bntvfunc Function);
    Result_Type Virtual_Machine_Load_File(const char *Path);
    Result_Type Virtual_Machine_Load_String(const char *String);
    Result_Type Call(Integer_Type);
    Result_Type REPL();

    void Free_Line(char *Pointer)
    {
        Pointer[0] = '\0';  // Mark the buffer as empty
    }

    char *Get_Line(const char *Prompt)
    {
        static Instruction_Type Instruction;
        if (Instruction_Available())
        {
            Instruction = Get_Instruction();
            Execute_Instruction(Instruction);
        }

        Serial.write(Prompt);
        Serial.flush();

        char *Buffer = (char *)malloc(256 * sizeof(char));

        memset(Buffer, 0, 256 * sizeof(char));

        for (uint16_t i = 0; i < 256; i++)
        {
            while (!Serial.available())
            {
                vTaskDelay(10);
            }

            switch (Serial.peek())
            {
            case '\n':
                i = 256;
                break;

            default:
                Buffer[i] = Serial.read();
                Serial.write(Buffer[i]);
                Serial.flush();
                break;
            }
        }

        Serial.read();
        Serial.println();

        return Buffer;
    }

    // - - - Softwares
    void Load_Softwares_Handles();

    // - Attributes

    bvm *Virtual_Machine;

    char* Input_Text[2];

    Graphics_Types::Text_Area_Type Input_Text_Area;
    Graphics_Types::Label_Type Prompt_Label;

    char* Prompt_Label_Text;

    static bool Softwares_Handles_Loaded;

    Graphics_Types::Window_Class Window;

    friend class Berry_Handle_Class;
    friend class Berry_Softwares_Handle_Class;
};

static class Berry_Handle_Class : public Software_Handle_Type
{
public:
    Berry_Handle_Class() : Software_Handle_Type("Berry"){};

    void Create_Instance(const Accounts_Types::User_Type *Owner_User) const override
    {
        new Berry_Class(Owner_User);
    }

} Berry_Handle;

class Berry_Softwares_Handle_Class : public Software_Handle_Type
{
public:
    Berry_Softwares_Handle_Class(const char *Name) : Software_Handle_Type(Name){};

    void Create_Instance(const Accounts_Types::User_Type *Owner_User) const override
    {
        new Berry_Class(Owner_User);
    }
};

#endif