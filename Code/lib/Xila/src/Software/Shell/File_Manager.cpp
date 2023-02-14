///
/// @file File_Manager.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief File manager of Shell
/// @version 0.2
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

Shell_Class::File_Manager_Class::File_Manager_Class(Shell_Class *Shell_Pointer)
    : Shell_Pointer(Shell_Pointer)
{
    Window.Create();
    Window.Set_Title("File Manager");

    Grid.Create(Window);
    const Coordinate_Type Column_Descriptor[] = {LV_GRID_FR(1), 140, LV_GRID_TEMPLATE_LAST};
    const Coordinate_Type Row_Descriptor[] = {LV_GRID_FR(1), 40, LV_GRID_TEMPLATE_LAST};
    Grid.Set_Size(Percentage(100), Percentage(100));
    Grid.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Grid.Set_Grid_Descriptor_Array(Column_Descriptor, Row_Descriptor);
    Grid.Set_Style_Pad_All(0, 0);

    Flexbox.Create(Grid);
    Flexbox.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 1, Grid_Alignment_Type::Stretch, 1, 1);
    Flexbox.Set_Flex_Flow(Flex_Flow_Type::Column_Wrap);
    Flexbox.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    Flexbox.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Start, Flex_Alignment_Type::Start);

    Path_Text_Area.Create(Grid);
    Path_Text_Area.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 2, Grid_Alignment_Type::Stretch, 0, 1);
    Path_Text_Area.Set_Text("/");
    Path_Text_Area.Set_One_Line(true);

    List.Create(Grid);
    List.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 1, 1, Grid_Alignment_Type::Stretch, 1, 1);
    List.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    List.Set_Style_Border_Side(Border_Side_Type::Left, 0);
    List.Set_Style_Pad_All(0, 0);

    List.Add_Text("Browse");
    Parent_Folder_Button = List.Add_Button(LV_SYMBOL_UP, "Parent");
    Parent_Folder_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Refresh_Button = List.Add_Button(LV_SYMBOL_REFRESH, "Refresh");
    Refresh_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Home_Folder_Button = List.Add_Button(LV_SYMBOL_DIRECTORY, "Home");
    Home_Folder_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Root_Folder_Button = List.Add_Button(LV_SYMBOL_DRIVE, "Root");
    Root_Folder_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);

    List.Add_Text("Create");
    New_Folder_Button = List.Add_Button(LV_SYMBOL_DIRECTORY, "New folder");
    New_Folder_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    New_File_Button = List.Add_Button(LV_SYMBOL_FILE, "New file");
    New_File_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);

    List.Add_Text("Selection");
    Select_Button = List.Add_Button(LV_SYMBOL_OK, "Select");
    Select_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Deselect_Button = List.Add_Button(LV_SYMBOL_CLOSE, "Cancel");
    Deselect_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Copy_Button = List.Add_Button(LV_SYMBOL_COPY, "Copy");
    Copy_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Cut_Button = List.Add_Button(LV_SYMBOL_CUT, "Cut");
    Cut_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Paste_Button = List.Add_Button(LV_SYMBOL_PASTE, "Paste");
    Paste_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Paste_Button.Add_Flag(Flag_Type::Hidden);
    Rename_Button = List.Add_Button(LV_SYMBOL_EDIT, "Rename");
    Rename_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Delete_Button = List.Add_Button(LV_SYMBOL_TRASH, "Delete");
    Delete_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
    Details_Button = List.Add_Button(LV_SYMBOL_EYE_OPEN, "Details");
    Details_Button.Add_Event(Shell_Pointer, Graphics_Type::Clicked);

    Details_Dialog.Create(Window);
    Details_Dialog.Set_Title("Details");

    Details_Table.Create(Details_Dialog);
    Details_Table.Set_Size(Percentage(100), Percentage(100));
    Details_Table.Set_Alignment(Alignment_Type::Center);
    Details_Table.Add_Flag(Flag_Type::Hidden);

    this->Refresh();
}

Shell_Class::File_Manager_Class::~File_Manager_Class()
{
    Flexbox.Delete();
    Path_Text_Area.Delete();
    List.Delete();
    Details_Dialog.Delete();
    Details_Table.Delete();
    Window.Delete();
}

void Shell_Class::File_Manager_Class::Open(Shell_Class *Shell_Pointer)
{
    Shell_Pointer->File_Manager_Pointer = new File_Manager_Class(Shell_Pointer);
}

void Shell_Class::File_Manager_Class::Close(Shell_Class *Shell_Pointer)
{
    delete Shell_Pointer->File_Manager_Pointer;
    Shell_Pointer->File_Manager_Pointer = NULL;
}

bool Shell_Class::File_Manager_Class::Is_Openned(Shell_Class *Shell_Pointer)
{
    if (Shell_Pointer->File_Manager_Pointer == NULL)
    {
        return false;
    }
    return true;
}

// -- File manager state -- //

void Shell_Class::File_Manager_Class::Refresh()
{
    File_Type Folder = Drive.Open(Path_Text_Area.Get_Text());

    Folder.read();

    if ((!Folder) || (!Folder.Is_Directory()))
    {
        Folder.Close();
        Path_Text_Area.Set_Text("/");
        Folder = Drive.Open("/");
    }

    File_Type File = Folder.Open_Next_File();

    Checkbox_Type Checkbox;
    char Item_Name[33] = {0};

    uint8_t i = 0;
    while (File)
    {
        i++;

        if (Flexbox.Get_Child_Count() < i)
        {
            Checkbox.Create(Flexbox);
            Checkbox.Set_Alignment(Alignment_Type::Out_Left_Middle);
            Checkbox.Add_State(Graphics_Types::State_Type::Disabled);
            Checkbox.Add_Event(Shell_Pointer, Graphics_Type::Clicked);
            Checkbox.Add_Event(Shell_Pointer, Graphics_Type::Long_Pressed);
        }

        if (File.isDirectory())
        {
            strlcat(Item_Name, LV_SYMBOL_DIRECTORY, sizeof(Item_Name));
        }
        else
        {
            strlcat(Item_Name, LV_SYMBOL_FILE, sizeof(Item_Name));
        }

        strlcat(Item_Name, " ", sizeof(Item_Name));
        strlcat(Item_Name, File.name(), sizeof(Item_Name));

        Checkbox.Set_Text(Item_Name);

        memset(Item_Name, '\0', sizeof(Item_Name));
        Checkbox.Clear_Pointer();
    }

    for (; i < Flexbox.Get_Child_Count(); i++)
    {
        Flexbox.Get_Child(i).Delete();
    }

    Folder.Close();
}

void Shell_Class::File_Manager_Class::Enable_Selection_Mode(bool Multiple = false)
{
    if (Multiple)
    {
        Select_Button.Add_Flag(Flag_Type::Hidden);
        Deselect_Button.Clear_Flag(Flag_Type::Hidden);
        Delete_Button.Clear_Flag(Flag_Type::Hidden);
        Rename_Button.Add_Flag(Flag_Type::Hidden);
        Copy_Button.Clear_Flag(Flag_Type::Hidden);
        Cut_Button.Clear_Flag(Flag_Type::Hidden);
        Paste_Button.Clear_Flag(Flag_Type::Hidden);
        Details_Button.Add_Flag(Flag_Type::Hidden);
    }
    else
    {
        Select_Button.Add_Flag(Flag_Type::Hidden);
        Deselect_Button.Clear_Flag(Flag_Type::Hidden);
        Delete_Button.Clear_Flag(Flag_Type::Hidden);
        Rename_Button.Clear_Flag(Flag_Type::Hidden);
        Copy_Button.Clear_Flag(Flag_Type::Hidden);
        Cut_Button.Clear_Flag(Flag_Type::Hidden);
        Paste_Button.Clear_Flag(Flag_Type::Hidden);
        Details_Button.Clear_Flag(Flag_Type::Hidden);

        for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
        {
            Flexbox.Get_Child(i).Clear_State(Graphics_Types::State_Type::Checked);
            Flexbox.Get_Child(i).Clear_State(Graphics_Types::State_Type::Disabled);
        }
    }
}

void Shell_Class::File_Manager_Class::Disable_Selection_Mode()
{
    Select_Button.Clear_Flag(Flag_Type::Hidden);
    Deselect_Button.Add_Flag(Flag_Type::Hidden);
    Delete_Button.Add_Flag(Flag_Type::Hidden);
    Rename_Button.Add_Flag(Flag_Type::Hidden);
    Copy_Button.Add_Flag(Flag_Type::Hidden);
    Cut_Button.Add_Flag(Flag_Type::Hidden);
    Details_Button.Add_Flag(Flag_Type::Hidden);

    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        Flexbox.Get_Child(i).Clear_State(Graphics_Types::State_Type::Checked);
        Flexbox.Get_Child(i).Add_State(Graphics_Types::State_Type::Disabled);
    }
}

uint8_t Shell_Class::File_Manager_Class::Count_Selected_Items()
{
    uint8_t Selected_Item_Count = 0;
    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            Selected_Item_Count++;
        }
    }
    return Selected_Item_Count;
}

void Shell_Class::File_Manager_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        if (Instruction.Graphics.Get_Code() == Graphics_Type::Event_Code_Type::Clicked)
        {
            if (Instruction.Graphics.Get_Object() == Parent_Folder_Button)
            {
                Go_Parent_Folder();
            }
            else if (Instruction.Graphics.Get_Object() == Home_Folder_Button)
            {
                Path_Text_Area.Set_Text(Account.Get_Logged_User()->Get_Home_Folder_Path());
                Refresh();
            }
            else if (Instruction.Graphics.Get_Object() == Root_Folder_Button)
            {
                Path_Text_Area.Set_Text("/");
                Refresh();
            }
            else if (Instruction.Graphics.Get_Object() == Refresh_Button)
            {
                Refresh();
            }
            else if (Instruction.Graphics.Get_Object() == New_File_Button)
            {
                Create_File();
            }
            else if (Instruction.Graphics.Get_Object() == New_Folder_Button)
            {
                Create_Folder();
            }
            else if (Instruction.Graphics.Get_Object() == Select_Button)
            {
                Enable_Selection_Mode(false);
            }
            else if (Instruction.Graphics.Get_Object() == Deselect_Button)
            {
                Disable_Selection_Mode();
            }
            else if (Instruction.Graphics.Get_Object() == Delete_Button)
            {
                Delete();
            }
            else if (Instruction.Graphics.Get_Object() == Rename_Button)
            {
                Rename();
            }
            else if (Instruction.Graphics.Get_Object() == Copy_Button)
            {
                Cut = false;
                Paste_Button.Clear_Flag(Flag_Type::Hidden);
            }
            else if (Instruction.Graphics.Get_Object() == Cut_Button)
            {
                Cut = true;
                Paste_Button.Clear_Flag(Flag_Type::Hidden);
            }
            else if (Instruction.Graphics.Get_Object() == Paste_Button)
            {
                

                Paste_Button.Add_Flag(Flag_Type::Hidden);
            }
            else if (Instruction.Graphics.Get_Object() == Details_Button)
            {
                Details();
            }
            else
            {
                for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
                {
                    if (Instruction.Graphics.Get_Object() == Flexbox.Get_Child(i))
                    {
                        Disable_Selection_Mode();
                        memset(Buffer, '\0', sizeof(Buffer));
                        strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
                        Checkbox_Type Checkbox = Flexbox.Get_Child(i);
                        strlcat(Buffer, Checkbox.Get_Text(), sizeof(Buffer));
                        Path_Text_Area.Set_Text(Buffer);
                        Refresh();
                        break;
                    }
                }
            }
        }
        else if (Instruction.Graphics.Get_Code() == Graphics_Type::Event_Code_Type::Long_Pressed)
        {
            for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
            {
                if (Instruction.Graphics.Get_Object() == Flexbox.Get_Child(i))
                {
                    if (Count_Selected_Items() == 0)
                    {
                        Enable_Selection_Mode();
                    }
                    else
                    {
                        Enable_Selection_Mode(true);
                    }

                    Flexbox.Get_Child(i).Add_State(Graphics_Types::State_Type::Checked);
                    break;
                }
            }
        }
    }
}

void Shell_Class::File_Manager_Class::Details()
{
    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            char Buffer[256];
            memset(Buffer, '\0', sizeof(Buffer));
            strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
            Checkbox_Type Checkbox = Flexbox.Get_Child(i);
            strlcat(Buffer, Checkbox.Get_Text(), sizeof(Buffer));

            File_Type Item = Drive.Open(Buffer);

            if (!Item)
            {
                return;
            }

            Details_Table.Set_Row_Count(0);
            Details_Table.Set_Column_Count(0);

            Details_Table.Set_Cell_Value(0, 0, "Attribute");
            Details_Table.Set_Cell_Value(0, 1, "Value");

            Details_Table.Set_Cell_Value(1, 0, "Name");
            Details_Table.Set_Cell_Value(1, 1, Item.name());

            Details_Table.Set_Cell_Value(1, 0, "Type");
            if (Item.isDirectory())
            {
                Details_Table.Set_Cell_Value(2, 1, "Directory");
            }
            else
            {
                Details_Table.Set_Cell_Value(2, 1, "File");
            }

            Details_Table.Set_Cell_Value(3, 0, "Size");
            // TODO : Replace with regular char.
            Details_Table.Set_Cell_Value(3, 1, String(Item.size()).c_str());

            // TODO : Do creation date.
            // Details_Table.Set_Cell_Value(4, 0, "Last write");
            // Detials_Table.Set_Cell_Value(4, 1, Item.getLastWrite());
            //time_t File_Last_Write_Time = Temporary_Item.getLastWrite();
            //tm *File_Last_Write = localtime(&File_Last_Write_Time);
            //sprintf(Temporary_Char_Array, "%02d/%02d/%d %02d:%02d:%02d\n", File_Last_Write->tm_mday, (File_Last_Write->tm_mon) + 1, (File_Last_Write->tm_year) + 1900, File_Last_Write->tm_hour, File_Last_Write->tm_min, File_Last_Write->tm_sec);
            
            Details_Dialog.Clear_Flag(Flag_Type::Hidden);

            Item.Close();

            break;
        }
    }
}

void Shell_Class::File_Manager_Class::Rename()
{
    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            char Buffer_2[256];

            memset(Buffer, '\0', sizeof(Buffer));
            strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
            Checkbox_Type Checkbox = Flexbox.Get_Child(i);
            strlcat(Buffer, Checkbox.Get_Text(), sizeof(Buffer));

            File Item = Drive.Open(Buffer);

            // TODO : Add dialog

            Drive.Rename(Buffer, Buffer_2);

            break;
        }
    }
    Refresh();
}

void Shell_Class::File_Manager_Class::Delete()
{

    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            memset(Buffer, '\0', sizeof(Buffer));
            strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
            Checkbox_Type Checkbox = Flexbox.Get_Child(i);
            strlcat(Buffer, Checkbox.Get_Text(), sizeof(Buffer));

            File_Type Item = Drive.Open(Buffer);

            if (Item)
            {
                if (Item.isDirectory())
                {
                    Drive.Remove_Directory(Buffer);
                }
                else
                {
                    Drive.Remove(Buffer);
                }
            }
        }
    }
    Refresh();
}

void Shell_Class::File_Manager_Class::Paste()
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

void Shell_Class::File_Manager_Class::Create_File()
{
    memset(Buffer, '\0', sizeof(Buffer));
    strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
    strlcat(Buffer, "/NewFile ", sizeof(Buffer));

    for (uint8_t i = 0; i <= 10; i++)
    {
        if (i < 10)
        {
            Buffer[strlen(Buffer) - 1] = i + '0';
            if (!Drive.Exists(Buffer))
            {
                if (!Drive.Make_Directory(Buffer))
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

void Shell_Class::File_Manager_Class::Create_Folder()
{
    memset(Buffer, '\0', sizeof(Buffer));
    strlcat(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));
    strlcat(Buffer, "/NewFold ", sizeof(Buffer));

    for (uint8_t i = 0; i <= 10; i++)
    {
        if (i < 10)
        {
            Buffer[strlen(Buffer) - 1] = i + '0';
            if (!Drive.Exists(Buffer))
            {
                if (!Drive.Make_Directory(Buffer))
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


void Shell_Class::File_Manager_Class::Go_Parent_Folder()
{
    memset(Buffer, '\0', sizeof(Buffer));
    strlcpy(Buffer, Path_Text_Area.Get_Text(), sizeof(Buffer));

    for (uint8_t i = strlen(Buffer) - 1; i >= 0; i--)
    {

        if (Buffer[i] == '/')
        {
            if (i != 0)
            {
                Buffer[i] = '\0';
            }
            return;
        }
        else
        {
            Buffer[i] = '\0';
        }
    }
    Refresh();
}
