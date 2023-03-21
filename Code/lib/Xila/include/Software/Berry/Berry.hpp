/// @file Berry.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-03-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Berry_Hpp_Included
#define Berry_Hpp_Included

#include "Xila.hpp"

extern "C"
{
#include "Virtual_machine/berry.h"
}

using namespace Xila;

/// @brief Berry class
class Berry_Class : public Software_Type
{
    // - Methods

    // - - Constructors / destructor
    Berry_Class();
    ~Berry_Class();

    // - - Task
    void Main_Task_Function() override;

    // - - Others
    void Execute_Instruction(const Instruction_Type &Instruction);

    // - - - Berry

    void Virtual_Machine_Create();
    void Virtual_Machine_Delete();
    void Virtual_Machine_Register_Function(const char *Name, bntvfunc Function);
    bool Virtual_Machine_Load_File(const char *Path);

    // - - - Softwares
    void Load_Softwares_Handles();

    // - Attributes
    bvm* Virtual_Machine;

    static bool Softwares_Handles_Loaded;

    Graphics_Types::Window_Class Window;

    friend class Berry_Handle_Class;
    friend class Berry_Softwares_Handle_Class;
    
};

static class Berry_Handle_Class : public Software_Handle_Type
{
public:
    Berry_Handle_Class() : Software_Handle_Type("Berry"){};

    void Create_Instance() const override
    {
        new Berry_Class();
    }

} Berry_Handle;

class Berry_Softwares_Handle_Class : public Software_Handle_Type
{
public:
    Berry_Softwares_Handle_Class(const char* Name) : Software_Handle_Type(Name){};

    void Create_Instance() const override
    {
        new Berry_Class();
    }
};

#endif