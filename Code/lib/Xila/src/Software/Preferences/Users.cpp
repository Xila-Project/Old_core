/// @file Users.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 06-05-2023
///
/// @copyright Copyright (c) 2023

#include "Software/Preferences/Preferences.hpp"

void Preferences_Class::Execute_Users_Instruction(const Instruction_Type &Instruction)
{
    if (Instruction.Graphics.Get_Target() == Users_Add_User_Button)
    {
        if (Accounts.Create(Users_Add_User_Name_Text_Area.Get_Text(), Users_Add_User_Password_Text_Area.Get_Text()) != Result_Type::Success)
        {
            // TODO : Display error message
        }
    }
    else if (Instruction.Graphics.Get_Target() == Users_Delete_User_Button)
    {
        // TODO :
        // if (Accounts.Delete(Users_Delete_User_Name_Text_Area.Get_Text()) != Result_Type::Success)
        //{
        //    // TODO : Display error message
        //}
    }
    else if (Instruction.Graphics.Get_Target() == Users_Apply_Button)
    {
        if (strcmp(Users_Your_Account_New_Name_Text_Area.Get_Text(), "") != 0)
        {
            Static_String_Type<24> Name;
            this->Get_Owner_User()->Get_Name(Name);
            if (Accounts.Change_Name(Name, Users_Your_Account_New_Name_Text_Area.Get_Text(), Users_Your_Account_Password_Text_Area.Get_Text()) != Result_Type::Success)
            {
                // TODO : Display error message
            }
            Users_Your_Account_New_Name_Text_Area.Set_Text("");
            Users_Your_Account_Password_Text_Area.Set_Text("");
        }
        else if (strcmp(Users_Your_Account_New_Password_Text_Area.Get_Text(), "") != 0 && strcmp(Users_Your_Account_Password_Text_Area.Get_Text(), "") != 0)
        {
            Static_String_Type<24> Name;
            this->Get_Owner_User()->Get_Name(Name);
            if (Accounts.Change_Password(Name, Users_Your_Account_New_Password_Text_Area.Get_Text(), Users_Your_Account_Password_Text_Area.Get_Text()) != Result_Type::Success)
            {
                // TODO : Display error message
            }
            Users_Your_Account_New_Password_Text_Area.Set_Text("");
            Users_Your_Account_Password_Text_Area.Set_Text("");
        }
    }
    else if (Instruction.Graphics.Get_Target() == Users_Delete_Your_Account_Button)
    {
        Static_String_Type<24> Name;
        this->Get_Owner_User()->Get_Name(Name);
        if (Accounts.Delete(Name, Users_Your_Account_Password_Text_Area.Get_Text()) != Result_Type::Success)
        {
            // TODO : Display error message
        }
        Users_Your_Account_Password_Text_Area.Set_Text("");
    }
}

void Preferences_Class::Refresh_Users()
{
    // TODO : Refresh user roller
}

void Preferences_Class::Draw_Users()
{
    using namespace Graphics_Types;

    Users_Tab.Set_Flex_Flow(Flex_Flow_Type::Row);
    Users_Tab.Set_Style_Pad_All(0, 0);
    Users_Tab.Clear_Flag(Flag_Type::Scroll_Elastic);
    Users_Tab.Clear_Flag(Flag_Type::Scroll_Momentum);

    // - Grid layout

    Object_Type Grid;
    Grid.Create(Users_Tab);
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(10, 0);

    // - - Your account section

    const uint8_t Your_Account_Section_Row = 0;

    {
        Label_Type Title_Label;
        Title_Label.Create(Grid, "Your account");
        Title_Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Your_Account_Section_Row, 1);

        Users_Apply_Button.Create(Grid, "Apply", 0, 0, this);
        Users_Apply_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Your_Account_Section_Row, 1);

        Users_Your_Account_Password_Text_Area.Create(Grid);
        Users_Your_Account_Password_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Your_Account_Section_Row + 1, 1);
        Users_Your_Account_Password_Text_Area.Set_Placeholder_Text("Password");
        Users_Your_Account_Password_Text_Area.Set_Password_Mode(true);

        Users_Your_Account_New_Name_Text_Area.Create(Grid);
        Users_Your_Account_New_Name_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Your_Account_Section_Row + 2, 1);
        Users_Your_Account_New_Name_Text_Area.Set_Placeholder_Text("New name");

        Users_Your_Account_New_Password_Text_Area.Create(Grid);
        Users_Your_Account_New_Password_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Your_Account_Section_Row + 3, 1);
        Users_Your_Account_New_Password_Text_Area.Set_Placeholder_Text("New password");
        Users_Your_Account_New_Password_Text_Area.Set_Password_Mode(true);

        Users_Your_Account_New_Password_Confirmation_Text_Area.Create(Grid);
        Users_Your_Account_New_Password_Confirmation_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 6, Grid_Alignment_Type::Stretch, Your_Account_Section_Row + 4, 1);
        Users_Your_Account_New_Password_Confirmation_Text_Area.Set_Placeholder_Text("New password confirmation");
        Users_Your_Account_New_Password_Confirmation_Text_Area.Set_Password_Mode(true);

        Users_Delete_Your_Account_Button.Create(Grid, "Delete", 0, 0, this);
        Users_Delete_Your_Account_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 5, 2, Grid_Alignment_Type::Stretch, Your_Account_Section_Row + 5, 1);
    }

    // - - Other accounts section

    const uint8_t Other_Accounts_Section_Row = Your_Account_Section_Row + 6;

    {
        Label_Type Title_Label;
        Title_Label.Create(Grid, "Other accounts");
        Title_Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Other_Accounts_Section_Row, 1);

        Users_Roller.Create(Grid);
        Users_Roller.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Other_Accounts_Section_Row + 1, 2);

        uint8_t User_Count = Accounts.Get_User_Count();
        char User_List[User_Count * 24 + 1];
        memset(User_List, 0, sizeof(User_List));
        for (uint8_t i = 0; i < User_Count; i++)
        {
            auto User = Accounts.Get_User(i);
            if (User)
            {
                Static_String_Type<25> Name;
                if (User->Get_Name(Name) != "Xila")
                {
                    Name += "\n";
                    strncat(User_List, (const char *)Name, sizeof(User_List));
                }
            }
        }
        Users_Roller.Set_Options(User_List, Roller_Mode_Type::Normal);

        Users_Delete_User_Button.Create(Grid, "Delete", 0, 0, this);
        Users_Delete_User_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 6, 2, Grid_Alignment_Type::Stretch, Other_Accounts_Section_Row + 1, 1);
    }

    // - - Add user section

    const uint8_t Add_User_Section_Row = Other_Accounts_Section_Row + 3;

    {
        Label_Type Title_Label;
        Title_Label.Create(Grid, "Add user");
        Title_Label.Set_Grid_Cell(Grid_Alignment_Type::Center, 0, 8, Grid_Alignment_Type::Center, Add_User_Section_Row, 1);

        Users_Add_User_Name_Text_Area.Create(Grid);
        Users_Add_User_Name_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Add_User_Section_Row + 1, 1);
        Users_Add_User_Name_Text_Area.Set_Placeholder_Text("Name");

        Users_Add_User_Password_Text_Area.Create(Grid);
        Users_Add_User_Password_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 6, Grid_Alignment_Type::Stretch, Add_User_Section_Row + 2, 1);
        Users_Add_User_Password_Text_Area.Set_Placeholder_Text("Password");
        Users_Add_User_Password_Text_Area.Set_Password_Mode(true);

        Users_Add_User_Button.Create(Grid, "Add", 0, 0, this);
        Users_Add_User_Button.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 5, 2, Grid_Alignment_Type::Stretch, Add_User_Section_Row + 1, 1);
    }
}