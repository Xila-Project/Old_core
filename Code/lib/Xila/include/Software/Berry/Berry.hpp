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

#include "Test.hpp"

using namespace Xila;

// - Forward declaration

typedef struct bvm bvm;
typedef int (*bntvfunc)(bvm *);

class Berry_Softwares_Handle_Class;

/// @brief Berry class
class Berry_Class : public Software_Type
{
    // - Methods

    // - - Constructors / destructor
    Berry_Class(const Accounts_Types::User_Type *Owner_User);
    Berry_Class(const Accounts_Types::User_Type* Owner_User, const Berry_Softwares_Handle_Class* Handle);
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
    
    // - - - - REPL
    void REPL();
    int REPL_Run();
    int REPL_Try_Return(const char* line);
    bool REPL_Is_Multiline();
    int REPL_Compile(char* line);
    int REPL_Call_Script();
    void REPL_Free_Line(char *);
    char *REPL_Get_Line(const char *);

    // - - - Softwares
    void Load_Softwares_Handles();

    // - Attributes

    char* Input_String;

    bvm *Virtual_Machine;

    Graphics_Types::Keyboard_Type Keyboard;
    Graphics_Types::Text_Area_Type Input_Text_Area;
    Graphics_Types::Label_Type Prompt_Label;
    Object_Type Prompt_Container;

    static bool Softwares_Handles_Loaded;

    Graphics_Types::Window_Class Window;

    friend class Berry_Handle_Class;
    friend class Berry_Softwares_Handle_Class;
};

extern char* Prompt_String;

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
        new Berry_Class(Owner_User, this);
    }
};

static Berry_Softwares_Handle_Class Test_Handle("Test");

#endif