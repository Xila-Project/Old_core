///
/// @file File_Manager.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief File manager of Shell
/// @version 0.2
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/File_Manager/File_Manager.hpp"

File_Manager_Class::File_Manager_Handle_Class File_Manager_Class::Handle;

File_Manager_Class::File_Manager_Class(const Accounts_Types::User_Type *Owner_User) : Software_Class(Handle, Owner_User)
{
}

File_Manager_Class::~File_Manager_Class()
{
    Log_Verbose("File manager", "Destructor");
    Log_Verbose("File manager", "Path: %p", this);
    Window.Delete();
}

void File_Manager_Class::Set_Interface()
{
    using namespace Xila::Graphics_Types;

    Log_Verbose("File manager", "File manager software interface initialization");

    Window.Create(this);
    Window.Set_Title("File manager");

    Grid.Create(Window.Get_Body());
    const Coordinate_Type Column_Descriptor[] = {LV_GRID_FR(1), 140, LV_GRID_TEMPLATE_LAST};
    const Coordinate_Type Row_Descriptor[] = {40, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(0, 0);

    File_Explorer.Create(Grid);
    File_Explorer.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 1, Grid_Alignment_Type::Stretch, 1, 1);
    File_Explorer.Add_Event(this, Event_Code_Type::Value_Changed);

    Path_Text_Area.Create(Grid);
    Path_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 1, Grid_Alignment_Type::Stretch, 0, 1);
    Path_Text_Area.Set_Text("/");
    Path_Text_Area.Set_One_Line(true);
    Path_Text_Area.Add_Event(this, Event_Code_Type::Focused);
    Path_Text_Area.Add_Event(this, Event_Code_Type::Defocused);

    List.Create(Grid);
    List.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 1, Grid_Alignment_Type::Stretch, 0, 2);
    List.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    List.Set_Style_Border_Side(Border_Side_Type::Left, 0);
    List.Set_Style_Pad_All(0, 0);
    List.Add_Text("Browse");

    Parent_Folder_Button = List.Add_Button(LV_SYMBOL_UP, "Parent");
    Parent_Folder_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Refresh_Button = List.Add_Button(LV_SYMBOL_REFRESH, "Refresh");
    Refresh_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Home_Folder_Button = List.Add_Button(LV_SYMBOL_DIRECTORY, "Home");
    Home_Folder_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Root_Folder_Button = List.Add_Button(LV_SYMBOL_DRIVE, "Root");
    Root_Folder_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

    List.Add_Text("Create");
    New_Folder_Button = List.Add_Button(LV_SYMBOL_DIRECTORY, "New folder");
    New_Folder_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    New_File_Button = List.Add_Button(LV_SYMBOL_FILE, "New file");
    New_File_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

    List.Add_Text("Selection");
    Select_Button = List.Add_Button(LV_SYMBOL_OK, "Select");
    Select_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Deselect_Button = List.Add_Button(LV_SYMBOL_CLOSE, "Cancel");
    Deselect_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Copy_Button = List.Add_Button(LV_SYMBOL_COPY, "Copy");
    Copy_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Cut_Button = List.Add_Button(LV_SYMBOL_CUT, "Cut");
    Cut_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Paste_Button = List.Add_Button(LV_SYMBOL_PASTE, "Paste");
    Paste_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Paste_Button.Add_Flag(Flag_Type::Hidden);
    Rename_Button = List.Add_Button(LV_SYMBOL_EDIT, "Rename");
    Rename_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Delete_Button = List.Add_Button(LV_SYMBOL_TRASH, "Delete");
    Delete_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
    Details_Button = List.Add_Button(LV_SYMBOL_EYE_OPEN, "Details");
    Details_Button.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);

    Details_Dialog.Create(Window);
    Details_Dialog.Set_State(Window_State_Type::Minimized);
    Details_Dialog.Set_Title("Details");

    Details_Table.Create(Details_Dialog);
    Details_Table.Set_Width(Percentage(100));
    Details_Table.Set_Alignment(Alignment_Type::Center);

    Keyboard.Create(Window.Get_Body());
    Keyboard.Add_Flag(Flag_Type::Hidden);
    Keyboard.Add_Flag(Flag_Type::Floating);
    Keyboard.Set_Alignment(Alignment_Type::Bottom_Middle);

    this->Refresh();
}

void File_Manager_Class::Main_Task_Function()
{
    Set_Interface();

    while (1)
    {
        if (this->Instruction_Available())
        {
            this->Execute_Instruction(Get_Instruction());
        }
        else
        {
            if (!this->Window.Is_Valid())
            {
                delete this;
                return;
            }

            Main_Task.Delay(40);
        }
    }
}

void File_Manager_Class::Refresh()
{
    File_Explorer.Set_Path(Path_Text_Area.Get_Text());
}

void File_Manager_Class::Enable_Selection_Mode()
{
    using namespace Graphics_Types;

    Select_Button.Add_Flag(Flag_Type::Hidden);
    Deselect_Button.Clear_Flag(Flag_Type::Hidden);
    Delete_Button.Clear_Flag(Flag_Type::Hidden);
    Rename_Button.Add_Flag(Flag_Type::Hidden);
    Copy_Button.Clear_Flag(Flag_Type::Hidden);
    Cut_Button.Clear_Flag(Flag_Type::Hidden);
    Paste_Button.Clear_Flag(Flag_Type::Hidden);
    Details_Button.Add_Flag(Flag_Type::Hidden);
    File_Explorer.Set_Selection_State(true);
}

void File_Manager_Class::Disable_Selection_Mode()
{
    using namespace Graphics_Types;

    Select_Button.Clear_Flag(Flag_Type::Hidden);
    Deselect_Button.Add_Flag(Flag_Type::Hidden);
    Delete_Button.Add_Flag(Flag_Type::Hidden);
    Rename_Button.Add_Flag(Flag_Type::Hidden);
    Copy_Button.Add_Flag(Flag_Type::Hidden);
    Cut_Button.Add_Flag(Flag_Type::Hidden);
    Details_Button.Add_Flag(Flag_Type::Hidden);
    File_Explorer.Set_Selection_State(false);
}

void File_Manager_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        Log_Verbose("File manager", "Instruction : %d", Instruction.Graphics.Get_Code());

        Graphics_Types::Object_Type Current_Target = Instruction.Graphics.Get_Current_Target();

        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Types::Event_Code_Type::Clicked:
            if (Current_Target == Parent_Folder_Button)
            {
                File_Explorer.Go_Parent_Folder();
                Path_Text_Area.Set_Text(File_Explorer.Get_Path());
            }
            else if (Current_Target == Home_Folder_Button)
            {
                Static_String_Type<64> Home_Folder_Path;
                Accounts.Get_Logged_User()->Get_Home_Folder_Path(Home_Folder_Path);
                Path_Text_Area.Set_Text(Home_Folder_Path);
                Refresh();
                Path_Text_Area.Set_Text(File_Explorer.Get_Path());
                
            }
            else if (Current_Target == Root_Folder_Button)
            {
                Path_Text_Area.Set_Text("/");
                Refresh();
                Path_Text_Area.Set_Text(File_Explorer.Get_Path());
            }
            else if (Current_Target == Refresh_Button)
                Refresh();
            else if (Current_Target == New_File_Button)
                Create_File();
            else if (Current_Target == New_Folder_Button)
                Create_Folder();
            else if (Current_Target == Select_Button)
                Enable_Selection_Mode();
            else if (Current_Target == Deselect_Button)
                Disable_Selection_Mode();
            else if (Current_Target == Delete_Button)
                Delete();
            else if (Current_Target == Rename_Button)
                Rename();
            else if (Current_Target == Copy_Button)
            {
                Cut = false;
                Paste_Button.Clear_Flag(Graphics_Types::Flag_Type::Hidden);
            }
            else if (Current_Target == Cut_Button)
            {
                Cut = true;
                Paste_Button.Clear_Flag(Graphics_Types::Flag_Type::Hidden);
            }
            else if (Current_Target == Paste_Button)
            {

                Paste_Button.Add_Flag(Graphics_Types::Flag_Type::Hidden);
            }
            else if (Current_Target == Details_Button)
                Details();
            break;
        case Graphics_Types::Event_Code_Type::Focused:
            if (Current_Target == Path_Text_Area)
                Keyboard.Set_Text_Area(Path_Text_Area);
            break;
        case Graphics_Types::Event_Code_Type::Defocused:
            Keyboard.Remove_Text_Area();
            break;
        case Graphics_Types::Event_Code_Type::Value_Changed:
            if (Current_Target == File_Explorer)
            {
                Log_Verbose("File manager", "File explorer value changed : ", File_Explorer.Get_Path());
                Path_Text_Area.Set_Text(File_Explorer.Get_Path());
            }
            break;
        }
    }
    else if (Instruction.Get_Sender() == &Softwares)
    {
        using namespace Softwares_Types;
        switch (Instruction.Softwares.Get_Code())
        {
        case Event_Code_Type::Close:
            delete this;
            break;
        }
    }
}

void File_Manager_Class::Details()
{
    Buffer = Path_Text_Area.Get_Text();
    Buffer += "/";
    Buffer += File_Explorer.Get_Selected_Name(0);

    Drive_Types::File_Type Item = Drive.Open(Buffer);

    if (!Item)
        return;

    Details_Table.Set_Row_Count(0);
    Details_Table.Set_Column_Count(0);

    Details_Table.Set_Cell_Value(0, 0, "Attribute");
    Details_Table.Set_Cell_Value(0, 1, "Value");

    Details_Table.Set_Cell_Value(1, 0, "Name");
    Details_Table.Set_Cell_Value(1, 1, Item.Get_Name());

    Details_Table.Set_Cell_Value(1, 0, "Type");
    if (Item.Is_Directory())
        Details_Table.Set_Cell_Value(2, 1, "Directory");
    else
        Details_Table.Set_Cell_Value(2, 1, "File");

    Details_Table.Set_Cell_Value(3, 0, "Size");
    // TODO : Replace with regular char.
    Details_Table.Set_Cell_Value(3, 1, String(Item.Get_Size()).c_str());

    // TODO : Do creation date.
    // Details_Table.Set_Cell_Value(4, 0, "Last write");
    // Detials_Table.Set_Cell_Value(4, 1, Item.getLastWrite());
    // time_t File_Last_Write_Time = Temporary_Item.getLastWrite();
    // tm *File_Last_Write = localtime(&File_Last_Write_Time);
    // sprintf(Temporary_Char_Array, "%02d/%02d/%d %02d:%02d:%02d\n", File_Last_Write->tm_mday, (File_Last_Write->tm_mon) + 1, (File_Last_Write->tm_year) + 1900, File_Last_Write->tm_hour, File_Last_Write->tm_min, File_Last_Write->tm_sec);

    Details_Dialog.Clear_Flag(Graphics_Types::Flag_Type::Hidden);

    Item.Close();
}

void File_Manager_Class::Rename()
{
    Buffer = Path_Text_Area.Get_Text();
    Buffer += "/";
    Buffer += File_Explorer.Get_Selected_Name(0);

    Static_String_Type<256> Buffer_2; // Destination path.

    // TODO : Add dialog

    Drive.Rename(Buffer, Buffer_2);
}

void File_Manager_Class::Delete()
{
    Size_Type Selected_Count = File_Explorer.Get_Selected_Count();

    for (Size_Type i = 0; i < Selected_Count; i++)
    {
        Buffer = Path_Text_Area.Get_Text();
        Buffer += "/";
        Buffer += File_Explorer.Get_Selected_Name(i);

        Drive_Types::File_Type Item = Drive.Open(Buffer);

        if (Item)
        {
            Drive.Remove(Buffer);
        }

        // TODO : Add dialog for error.
    }
    Refresh();
}

void File_Manager_Class::Paste()
{
    /*
        if (Selected_Item.isDirectory())
        {
            DIALOG.Event(F("Cannot cut folder."), Error);
            SHELL->Send_Instruction('R', 'e');
        }
        else
        {
            char Temporary_File_Name[13] = "/";
            strlcat(Current_Path, Temporary_File_Name, sizeof(Current_Path));
            File Destination_File = Drive.Open(Current_Path, FILE_WRITE);
            SHELL->Set_Watchdog_Timeout(30000);
            if (Drive.Copy(Operation_Item, Destination_File) == Success)
            {
                DIALOG.Event(F("File was cut successfully."), Error);
            }
            else
            {
                DIALOG.Event(F("Failed to cut file."), Error);
            }
            SHELL->Set_Watchdog_Timeout();
            Destination_File.Close();
            Operation_Item.Close();
            SHELL->Send_Instruction('G', 'P');
        }
        Display.Set_Picture(F("CUT_BUT"), Images.Cut_24);
        Set_Operation(Browse);
    }*/
}

void File_Manager_Class::Create_File()
{
    Buffer = Path_Text_Area.Get_Text();
    Buffer += "/NewFile ";

    for (uint8_t i = 0; i <= 10; i++)
    {
        if (i < 10)
        {
            Buffer.Set_Character(Buffer.Get_Length() - 1, i + '0');
            if (!Drive.Exists(Buffer))
            {
                Drive_Types::File_Type File = Drive.Open(Buffer, true);
                if (!File)
                {
                    // TODO : Add dialog
                }
                File.Close();
                break;
            }
        }
        else
        {
            // TODO : Add dialog

            break;
        }
    }
    Refresh();
}

void File_Manager_Class::Create_Folder()
{
    Buffer = Path_Text_Area.Get_Text();
    Buffer += "/NewFold ";

    for (uint8_t i = 0; i < 10; i++)
    {
        if (i < 10)
        {
            Buffer.Set_Character(Buffer.Get_Length() - 1, i + '0');
            if (!Drive.Exists(Buffer))
            {
                if (Drive.Make_Directory(Buffer) != Result_Type::Success)
                {
                    // TODO : Add dialog
                }
                break;
            }
        }
        else
        {
            // TODO : Add dialog

            break;
        }
    }
    Refresh();
}