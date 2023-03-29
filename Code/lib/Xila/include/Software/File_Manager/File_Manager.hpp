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
    char Buffer[256];

    bool Cut;

    Graphics_Types::Window_Type Window;

    Object_Type Grid;
    Object_Type Flexbox;
    Graphics_Types::Text_Area_Type Path_Text_Area;
    List_Type List;
    Button_Type Parent_Folder_Button;
    Button_Type Home_Folder_Button;
    Button_Type Root_Folder_Button;
    Button_Type Refresh_Button;
    Button_Type New_Folder_Button;
    Button_Type New_File_Button;
    Button_Type Select_Button;
    Button_Type Deselect_Button;
    Button_Type Delete_Button;
    Button_Type Rename_Button;
    Button_Type Copy_Button;
    Button_Type Cut_Button;
    Button_Type Paste_Button;
    Button_Type Details_Button;

    Graphics_Types::Dialog_Type Details_Dialog;
    Table_Type Details_Table;

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