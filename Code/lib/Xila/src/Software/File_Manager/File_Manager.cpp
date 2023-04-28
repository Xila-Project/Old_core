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

File_Manager_Class::File_Manager_Class(const Accounts_Types::User_Type *Owner_User) : Software_Class(&File_Manager_Handle, Owner_User)
{
    Log_Verbose("File manager", "File manager software initialization");
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

    Flexbox.Create(Grid);
    Flexbox.Set_Grid_Cell(Grid_Alignment_Type::Stretch, 0, 1, Grid_Alignment_Type::Stretch, 1, 1);
    Flexbox.Set_Flex_Flow(Flex_Flow_Type::Column_Wrap_Reverse);
    Flexbox.Set_Style_Background_Opacity(Opacity_Type::Transparent, 0);
    // Flexbox.Set_Flex_Alignment(Flex_Alignment_Type::Space_Evenly, Flex_Alignment_Type::Start, Flex_Alignment_Type::Start);
    Flexbox.Set_Style_Background_Color(Color_Type::Red[5], 0);

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
    Details_Table.Set_Size(Percentage(100), Percentage(100));
    Details_Table.Set_Alignment(Alignment_Type::Center);

    Keyboard.Create(Window);
    Keyboard.Add_Flag(Flag_Type::Hidden);

    this->Refresh();
}

File_Manager_Class::~File_Manager_Class()
{
    Log_Verbose("File manager", "Destructor");
    Log_Verbose("File manager", "Path: %p", this);
    Window.Delete();
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
    Log_Verbose("File manager", "Refresh");

    Log_Verbose("File manager", "Path: %s", Path_Text_Area.Get_Text());

    File_Type Folder = Drive.Open(Path_Text_Area.Get_Text());

    if ((!Folder) || (!Folder.Is_Directory()))
    {
        Log_Warning("File manager", "Invalid folder: %s", Path_Text_Area.Get_Text());

        Folder.Close();
        Path_Text_Area.Set_Text("/");
        Folder = Drive.Open("/");
    }

    Log_Verbose("File manager", "Folder: %s", Path_Text_Area.Get_Text());

    uint8_t Item_Count = Folder.Count_Items();

    Log_Verbose("File manager", "Item count: %d", Item_Count);

    // - If there are not enough checkboxes, create more
    {
        Graphics_Types::Checkbox_Class Checkbox;
        while (Flexbox.Get_Child_Count() < Item_Count)
        {
            Checkbox.Create(Flexbox);
            Checkbox.Set_Alignment(Alignment_Type::Out_Left_Middle);
            Checkbox.Add_Event(this, Graphics_Types::Event_Code_Type::Clicked);
            Checkbox.Add_Event(this, Graphics_Types::Event_Code_Type::Long_Pressed);
            Checkbox.Set_Style_Opacity(Opacity_Type::Transparent, LV_PART_INDICATOR);
            Checkbox.Clear_Pointer();
        }
    }

    Log_Verbose("File manager", "Checkbox count: %d", Flexbox.Get_Child_Count());

    Folder.Rewind_Directory();

    Graphics_Types::Checkbox_Type Checkbox;
    Static_String_Type<32> Item_Name;

    File_Type File;

    for (uint8_t i = 0; i < Item_Count; i++)
    {
        File = Folder.Open_Next_File();

        if (!File)
        {
            Log_Verbose("File mana", "!File !!!!");
            break;
        }

        Checkbox = Flexbox.Get_Child(i);
        Checkbox.Clear_Flag(Flag_Type::Hidden);

        if (File.Is_Directory())
            Item_Name = LV_SYMBOL_DIRECTORY;
        else
            Item_Name = LV_SYMBOL_FILE;

        Item_Name += " ";
        Item_Name += File.Get_Name();

        Log_Verbose("File manager", "Item name: %s", (const char *)Item_Name);

        Checkbox.Set_Text((const char *)Item_Name);

        Checkbox.Clear_Pointer();
        File.Close();
    }

    // - Hide remaining unused checkboxes instead of deleting them to avoid memory fragmentation.
    Size_Type Flexbox_Child_Count = Flexbox.Get_Child_Count();
    for (uint8_t i = Item_Count; i < Flexbox_Child_Count; i++)
    {
        Log_Verbose("File manager", "Hide checkbox %d", i);
        Checkbox = Flexbox.Get_Child(i);
        Checkbox.Add_Flag(Flag_Type::Hidden);
    }

    Folder.Close();
}

void File_Manager_Class::Enable_Selection_Mode(bool Multiple = false)
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
            Flexbox.Set_Style_Opacity(Opacity_Type::Cover, LV_PART_INDICATOR);
            // Flexbox.Get_Child(i).Clear_State(Graphics_Types::State_Type::Disabled);
        }
    }
}

void File_Manager_Class::Disable_Selection_Mode()
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
        Flexbox.Set_Style_Opacity(Opacity_Type::Transparent, LV_PART_INDICATOR);
        // Flexbox.Get_Child(i).Add_State(Graphics_Types::State_Type::Disabled);
    }
}

uint8_t File_Manager_Class::Count_Selected_Items()
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

void File_Manager_Class::Execute_Instruction(Instruction_Type Instruction)
{
    if (Instruction.Get_Sender() == &Graphics)
    {
        Log_Verbose("File manager", "Instruction !");

        Object_Type Target = Instruction.Graphics.Get_Target();

        switch (Instruction.Graphics.Get_Code())
        {
        case Graphics_Types::Event_Code_Type::Clicked:
            if (Target == Parent_Folder_Button)
                Go_Parent_Folder();
            else if (Target == Home_Folder_Button)
            {
                Static_String_Type<32> Home_Folder_Path;
                Accounts.Get_Logged_User()->Get_Home_Folder_Path(Home_Folder_Path);
                Path_Text_Area.Set_Text(Home_Folder_Path);
                Refresh();
            }
            else if (Target == Root_Folder_Button)
            {
                Path_Text_Area.Set_Text("/");
                Refresh();
            }
            else if (Target == Refresh_Button)
                Refresh();
            else if (Target == New_File_Button)
                Create_File();
            else if (Target == New_Folder_Button)
                Create_Folder();
            else if (Target == Select_Button)
                Enable_Selection_Mode(false);
            else if (Target == Deselect_Button)
                Disable_Selection_Mode();
            else if (Target == Delete_Button)
                Delete();
            else if (Target == Rename_Button)
                Rename();
            else if (Target == Copy_Button)
            {
                Cut = false;
                Paste_Button.Clear_Flag(Flag_Type::Hidden);
            }
            else if (Target == Cut_Button)
            {
                Cut = true;
                Paste_Button.Clear_Flag(Flag_Type::Hidden);
            }
            else if (Target == Paste_Button)
            {

                Paste_Button.Add_Flag(Flag_Type::Hidden);
            }
            else if (Target == Details_Button)
                Details();
            else
            {
                Log_Verbose("File manager", "Maybe Checkbox clicked !");
                Size_Type Flexbox_Child_Count = Flexbox.Get_Child_Count();
                for (uint8_t i = 0; i < Flexbox_Child_Count; i++)
                {
                    if (Target == Flexbox.Get_Child(i))
                    {
                        Log_Verbose("File manager", "Checkbox %u clicked", i);
                        Graphics_Types::Checkbox_Type Checkbox = Flexbox.Get_Child(i);
                        if (Checkbox.Is_Valid())
                        {
                            Disable_Selection_Mode();
                            Buffer = Path_Text_Area.Get_Text();
                            if (Buffer != "/")
                                Buffer += "/";

                            Log_Verbose("File manager", "Checkbox. : %p", Checkbox.Get_Text());
                            Log_Verbose("File manager", "Checkbox + 2 : %p", Checkbox.Get_Text() + 2);
                            Log_Verbose("File manager", "Checkbox + 2 : %p", Checkbox.Get_Text()[2]);

                            Buffer += &(Checkbox.Get_Text()[sizeof(LV_SYMBOL_DIRECTORY)]); // Skip the first characters (symbol + space)

                            File_Type Item = Drive.Open(Buffer);

                            if (!Item || !Item.Is_Directory())
                            {
                                Item.Close();
                                Log_Verbose("File manager", "Not a directory or invalid : %s ", (const char *)Buffer);
                                return;
                            }

                            Item.Close();

                            Path_Text_Area.Set_Text((const char *)Buffer);
                            Refresh();
                        }
                        break;
                    }
                }
            }
            break;

        case Graphics_Types::Event_Code_Type::Long_Pressed:
            for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
            {
                if (Target == Flexbox.Get_Child(i))
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
            break;
        case Graphics_Types::Event_Code_Type::Focused:
            if (Target == Path_Text_Area)
            {
                Keyboard.Set_Text_Area(Path_Text_Area);
            }
            break;
        case Graphics_Types::Event_Code_Type::Defocused:
            Keyboard.Remove_Text_Area();
            break;
        }
    }
}

void File_Manager_Class::Details()
{
    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            Graphics_Types::Checkbox_Type Checkbox = Flexbox.Get_Child(i);
            if (!Checkbox.Is_Valid())
                return;

            Buffer = Path_Text_Area.Get_Text();
            Buffer += "/";
            Buffer += Checkbox.Get_Text();

            File_Type Item = Drive.Open(Buffer);

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

            Details_Dialog.Clear_Flag(Flag_Type::Hidden);

            Item.Close();

            break;
        }
    }
}

void File_Manager_Class::Rename()
{
    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {

            Graphics_Types::Checkbox_Type Checkbox = Flexbox.Get_Child(i);
            if (!Checkbox.Is_Valid())
                return;

            Buffer = Path_Text_Area.Get_Text();
            Buffer += "/";
            Buffer += Checkbox.Get_Text();

            Static_String_Type<256> Buffer_2; // Destination path.

            // TODO : Add dialog

            Drive.Rename(Buffer, Buffer_2);

            break;
        }
    }
    Refresh();
}

void File_Manager_Class::Delete()
{

    for (uint8_t i = 0; i < Flexbox.Get_Child_Count(); i++)
    {
        if (Flexbox.Get_Child(i).Has_State(Graphics_Types::State_Type::Checked))
        {
            Graphics_Types::Checkbox_Type Checkbox = Flexbox.Get_Child(i);

            if (!Checkbox.Is_Valid())
                return;

            Buffer = Path_Text_Area.Get_Text();
            Buffer += "/";
            Buffer += Checkbox.Get_Text();

            File_Type Item = Drive.Open(Buffer);

            if (Item)
            {
                if (Item.Is_Directory())
                    Drive.Remove_Directory(Buffer);
                else
                    Drive.Remove_File(Buffer);
            }

            // TODO : Add dialog for error.
        }
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
                File_Type File = Drive.Open(Buffer, true);
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

void File_Manager_Class::Go_Parent_Folder()
{
    Log_Verbose("Shell", "Going to parent folder.");

    Buffer = Path_Text_Area.Get_Text();

    for (uint8_t i = Buffer.Get_Length() - 1; i > 0; i--)
    {
        Log_Verbose("Shell", "Character: %s", (const char *)Buffer);
        Log_Verbose("Shell", "Index: %d", i);

        if (Buffer.Get_Character(i) == '/')
        {
            Buffer.Set_Character(i, '\0');

            Log_Verbose("Shell", "New path: %s", (const char *)Buffer);
            break;
        }
        else
        {
            Buffer.Set_Character(i, '\0');
        }
    }

    Path_Text_Area.Set_Text(Buffer);
    Refresh();
}
