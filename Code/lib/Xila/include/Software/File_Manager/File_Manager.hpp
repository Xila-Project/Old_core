///
/// @file File_Manager.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-02-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef File_Manager_Hpp_Included
#define File_Manager_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

class File_Manager_Class : public Software_Type
{

    // - Methods

    // - - Constructors / destructor

    File_Manager_Class(const Accounts_Types::User_Type *Owner_User);
    ~File_Manager_Class();

    void Main_Task_Function() override;
    void Execute_Instruction(Instruction_Type Instruction);

    void Set_Interface();

    void Refresh();

    void Enable_Selection_Mode(bool Multiple);
    void Disable_Selection_Mode();
    uint8_t Count_Selected_Items();

    void Paste();
    void Details();
    void Go_Parent_Folder();
    void Click();
    void Rename();
    void Delete();
    void Create_File();
    void Create_Folder();

    // -- Attributes
    Static_String_Type<256> Buffer;

    bool Cut;

    Graphics_Types::Window_Type Window;

    Graphics_Types::Object_Type Grid;
    Graphics_Types::Object_Type Flexbox;
    Graphics_Types::Text_Area_Type Path_Text_Area;
    Graphics_Types::List_Type List;
    Graphics_Types::Object_Type Parent_Folder_Button;
    Graphics_Types::Object_Type Home_Folder_Button;
    Graphics_Types::Object_Type Root_Folder_Button;
    Graphics_Types::Object_Type Refresh_Button;
    Graphics_Types::Object_Type New_Folder_Button;
    Graphics_Types::Object_Type New_File_Button;
    Graphics_Types::Object_Type Select_Button;
    Graphics_Types::Object_Type Deselect_Button;
    Graphics_Types::Object_Type Delete_Button;
    Graphics_Types::Object_Type Rename_Button;
    Graphics_Types::Object_Type Copy_Button;
    Graphics_Types::Object_Type Cut_Button;
    Graphics_Types::Object_Type Paste_Button;
    Graphics_Types::Object_Type Details_Button;

    Graphics_Types::Dialog_Type Details_Dialog;
    Graphics_Types::Table_Type Details_Table;

    Graphics_Types::Keyboard_Type Keyboard;

    friend class File_Manager_Handle_Class;
};

// - Types

static class File_Manager_Handle_Class : public Software_Handle_Class
{
public:
    File_Manager_Handle_Class() : Software_Handle_Class("File manager"){};

    void Create_Instance(const Accounts_Types::User_Type* Owner_User) const override
    {
        new File_Manager_Class(Owner_User);
    };
} File_Manager_Handle;

#endif