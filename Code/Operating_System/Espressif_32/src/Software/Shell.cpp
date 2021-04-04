/**
 * @file Shell.cpp
 * @brief Xila's user interface source file.
 * @author Alix ANNERAUD
 * @copyright MIT License
 * @version 0.1.0
 * @date 21/05/2020
 * @details Xila user interface software.
 * @section License
 * 
 * Copyright (c) 2020 Alix ANNERAUD
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
*/

#include "Software/Shell.hpp"

// -- Initialize shell -- //

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Software_Class(Shell_Handle),
                             Offset(0),
                             Mode(0)
{
    Desk_Background = -1;
    Xila.Task.Create(Main_Task, "Shell Task", Memory_Chunk(6), NULL, &Task_Handle);
}

Shell_Class::~Shell_Class()
{
    Verbose_Print_Line("Delete shell");
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Shell_Class::Load_Shell()
{
    Verbose_Print_Line("Load Shell");
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Shell_Class();
    return Instance_Pointer;
}

void Shell_Class::Startup()
{
    Verbose_Print_Line("> Open_Shell");

    Xila.Software.Open(Shell_Handle);
}

// -- Main shell methods -- //

void Shell_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Xila.Display.Get_Current_Page())
        {
        case About:
            Instance_Pointer->Preferences_System_Instructions();
            break;
        case Color_Picker:
            Instance_Pointer->Color_Picker_Instructions();
            break;
        case Desk:
            Instance_Pointer->Desk_Instructions();
            break;
        case Drawer:
            Instance_Pointer->Drawer_Instructions();
            break;
        case Event:
            Instance_Pointer->Event_Instructions();
            break;
        case File_Manager_Main:
        case File_Manager_Detail:
            Instance_Pointer->File_Manager_Instructions();
            break;
        case Preferences_Hardware:
            Instance_Pointer->Preferences_Hardware_Instructions();
            break;
        case Install:
            Instance_Pointer->Install_Instructions();
            break;
        case Keyboard:
            Instance_Pointer->Keyboard_Instructions();
            break;
        case Keypad:
            Instance_Pointer->Keypad_Instructions();
            break;
        case Login:
            Instance_Pointer->Login_Instructions();
            break;
        case Load:
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Instruction();
            Instance_Pointer->Main_Instructions();
            break;
        case Preferences_Network:
            Instance_Pointer->Preferences_Network_Instructions();
            break;
        case Preferences_Personal:
            Instance_Pointer->Preferences_Personal_Instructions();
            break;
        case Shutdown:
            Instance_Pointer->Shutdown_Instructions();
            break;
        case Preferences_System:
            Instance_Pointer->Preferences_System_Instructions();
            break;
        case Welcome:
            Instance_Pointer->Install_Instructions();
            break;
        default:
            Xila.Task.Delay(50);
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Instruction();
            Instance_Pointer->Main_Instructions();
            break;
        }
    }
}

void Shell_Class::Main_Instructions()
{
    switch (Current_Command)
    {
    case Idle:
        if (Xila.Software.Get_State(Shell_Handle) == Minimized)
        {
            Xila.Task.Delay(90);
        }
        Xila.Task.Delay(10);
        break;
    case Dialog_Color_Picker:
        Open_Color_Picker();
        break;
    case Instruction('L', 'R'):
        Load_Registry();
        break;
    case Instruction('O', 's'):
    case Dialog_Power:
        Open_Shutdown();
        break;
    case Instruction('O', 'L'): // "OL" : Open Login page
        Open_Login();
        break;
    case Instruction('O', 'D'):
    case Open:
    case Software_Class::Desk: // "OD" Open Desk page & load it
        Open_Desk();
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        Open_Drawer();
        break;
    case Instruction('O', 'A'): // Open about xila
        Xila.Display.Set_Current_Page(About);
        break;
    case Dialog_Keyboard:
        Open_Keyboard();
        break;
    case Dialog_Keypad:
        Open_Keypad();
        break;
    case Dialog_Install:
        Open_Install();
        break;
    case Dialog_Open_File:
        Mode = Dialog_Open_File;
        Open_File_Manager();
        break;
    case Dialog_Open_Folder:
        Mode = Dialog_Open_Folder;
        Open_File_Manager();
        break;
    case Dialog_Save_File:
        Mode = Dialog_Save_File;
        Open_File_Manager();
        break;
    case Dialog_Event:
        // -- Already openend
        break;
    case Shutdown:
        Open_Load(Shutdown);
        Save_Registry();
        break;
    case Restart:
        Open_Load(Restart);
        Save_Registry();
        break;
    case Hibernate:
        Open_Load(Hibernate);
        Save_Registry();
        break;
    case Instruction('O', 'F'): // Open file manager
        Mode = 0;
        Open_File_Manager();
        break;

    case Instruction('O', 'P'): // Open preferiencies (default : personnal)
        Instance_Pointer->Open_Preferences_Personal();
        break;
    case Instruction('O', 'H'): // "OH" : Open hardware prefencies
        Instance_Pointer->Open_Preferences_Hardware();
        break;
    case Instruction('O', 'N'): // "ON" : Open network
        Instance_Pointer->Open_Preferences_Network();
        break;
    case Instruction('O', 'S'): // "OS" : Open system preferencies
        Instance_Pointer->Open_Preferences_System();
        break;
    case Close: // close
        delete Instance_Pointer;
        Xila.Task.Delete();
        break;
    case Minimize: // minimize
        break;
    case Maximize:
        break;
    default:
        Verbose_Print(F("Unknow instruction :"));

        Serial.print(Current_Command, HEX);
        Serial.print('|');
        Serial.println(Xila.Display.Get_Current_Page());
        break;
    }
}

// -- Set variable -- //

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Xila.Display.Get_Current_Page())
    {
    case Preferences_Hardware:
        switch (Adress)
        {
        case 'B':
            Brightness = *(uint8_t *)Variable;
            break;
        case 'V':
            Serial.print(*(uint8_t *)Variable);
            Xila.Sound.Set_Volume(*(uint8_t *)Variable);
            break;
        default:
            break;
        }
        break;
    case File_Manager_Main:
        switch (Adress)
        {
        case 'F':
            if (Current_Path[1] != '\0')
            {
                strcat(Current_Path, "/");
            }
            strlcat(Current_Path, (char *)Variable, sizeof(Current_Path));
            Send_Instruction(Instruction('R', 'F'));
            break;
        default:
            break;
        }
        break;
    case Keyboard:
        Serial.print((char)Adress);
        if (Adress == 'I' && Xila.Dialog.Pointer != NULL)
        {
            Serial.print(Xila.Dialog.Long[0]);
            strlcpy((char *)Xila.Dialog.Pointer, (char *)Variable, Xila.Dialog.Long[0]);
        }
        break;
    case Keypad:
        if (Adress == 'I' && Xila.Dialog.Pointer != NULL)
        {
            memcpy(Xila.Dialog.Long, (float *)Variable, sizeof(uint32_t));
        }
        break;
    case Color_Picker:
        if (Adress == 'C' && Xila.Dialog.Pointer != NULL)
        {
            memcpy(Xila.Dialog.Pointer, (uint16_t *)Variable, sizeof(uint16_t));
        }
    default:
        break;
    }
}

// -- Shell registry management -- //

Xila_Class::Event Shell_Class::Load_Registry()
{
    Temporary_Item.close();
    Desk_Background = -1;

    Temporary_Item = Xila.Drive.Open(Users_Directory_Path + String(Xila.Account.Current_Username) + "/Registry/Shell.xrf");

    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Temporary_Item) != DeserializationError::Ok)
    {
        return Xila.Error;
    }

    /*if (strcmp("Shell", Shell_Registry["Registry"]) != 0)
    {
        return Xila.Error;
    }*/
    Desk_Background = Shell_Registry["Desk Background"] | -1;

    Serial.println(Desk_Background);

    Temporary_Item.close();
    return Xila.Success;
}

Xila_Class::Event Shell_Class::Save_Registry()
{
    Temporary_Item.close();
    Temporary_Item = Xila.Drive.Open(Users_Directory_Path + String(Xila.Account.Current_Username) + "/Registry/Shell.xrf", FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Temporary_Item);
    Shell_Registry["Desk Background"] = Desk_Background;
    if (serializeJson(Shell_Registry, Temporary_Item) == 0)
    {
        return Xila.Error;
    }
    Temporary_Item.close();
    return Xila.Success;
}

// -- File manager -- //

void Shell_Class::Refresh_File_Manager()
{
    Verbose_Print_Line("Refresh file manager");
    Serial.print(Mode, HEX);
    Serial.print(":");
    Serial.println(Operation);
    Serial.println(Current_Path);
    Temporary_Item = Xila.Drive.Open(Current_Path);

    if (Temporary_Item)
    {
        File Item;
        switch (Operation)
        {
        case Copy:
            Selected_Item = Temporary_Item;
            Xila.Display.Set_Picture(F("COPY_BUT"), Paste_24);
            break;
        case Cut:
            Selected_Item = Temporary_Item;
            Xila.Display.Set_Picture(F("CUT_BUT"), Paste_24);
            break;
        case Delete:
            if (Mode == 0)
            {

                if (Event_Dialog(F("Are you sure to delete this item."), Xila.Question) == Xila.Button_1)
                {
                    if (Temporary_Item.isDirectory())
                    {
                        if (Xila.Drive.Remove_Directory(Current_Path) != true)
                        {
                            Event_Dialog(F("Failed to delete directory."), Xila.Error);
                        }
                    }
                    else
                    {
                        if (Xila.Drive.Remove(Current_Path) != true)
                        {
                            Event_Dialog(F("Failed to delete file."), Xila.Error);
                        }
                    }
                }
                Go_Parent();
            }

            Operation = Browse;
            Send_Instruction('R', 'F');
            break;
        case Rename:
            if (Mode == 0)
            {
                Go_Parent();
                char Temporary_Input[14];
                memset(Temporary_Input, '\0', sizeof(Temporary_Input));
                Xila.Drive.Get_Name(Temporary_Item, Temporary_Input, sizeof(Temporary_Input));
                Keyboard_Dialog(Temporary_Input, sizeof(Temporary_Input));
                Xila.Drive.Rename(Temporary_Item.name(), String(Current_Path) + String(Temporary_Input));
                Operation = Browse;
            }
            Operation = Browse;
            Send_Instruction('R', 'F');

            break;
        case Detail:
            Open_File_Manager_Detail();
            Go_Parent();
            break;
        default:
            if (Temporary_Item.isDirectory())
            {
                Xila.Display.Set_Text(F("PATH_TXT"), Current_Path);

                if (Mode == Dialog_Open_Folder)
                {
                    Selected_Item = Temporary_Item;
                }

                Temporary_Item.rewindDirectory();

                // -- Apply offset
                for (uint8_t i = 0; i < Offset; i++)
                {
                    Temporary_Item.openNextFile().close();
                }

                char Temporary_Item_Name[13] = "ITEM _TXT";
                char Temporary_Item_Picture[13] = "ITEM _PIC";
                char Temporary_File_Name[13] = "";

                for (uint8_t i = 1; i <= 30; i++)
                {

                    Item = Temporary_Item.openNextFile();

                    // -- Check if offset is correct, if not, reset offset and rewind directory
                    if (i == 1)
                    {
                        if (!Item)
                        {
                            Offset = 0;
                            Item.close();
                            Temporary_Item.rewindDirectory();
                            Item = Temporary_Item.openNextFile();
                        }
                    }

                    if (i < 10)
                    {

                        Temporary_Item_Name[4] = i + '0';
                        Temporary_Item_Picture[4] = i + '0';
                    }
                    else if (i < 20)
                    {
                        if (i == 10)
                        {
                            strcpy(Temporary_Item_Name, "ITEM  _TXT");
                            strcpy(Temporary_Item_Picture, "ITEM  _PIC");
                        }

                        Temporary_Item_Name[4] = '1';
                        Temporary_Item_Name[5] = (i - 10) + '0';

                        Temporary_Item_Picture[4] = '1';
                        Temporary_Item_Picture[5] = Temporary_Item_Name[5];
                    }
                    else if (i < 30)
                    {
                        Temporary_Item_Name[4] = '2';
                        Temporary_Item_Name[5] = (i - 20) + '0';

                        Temporary_Item_Picture[4] = '2';
                        Temporary_Item_Picture[5] = Temporary_Item_Name[5];
                    }
                    else
                    {
                        Temporary_Item_Name[4] = '3';
                        Temporary_Item_Name[5] = '0';

                        Temporary_Item_Picture[4] = '3';
                        Temporary_Item_Picture[5] = '0';
                    }

                    if (Item)
                    {
                        Xila.Drive.Get_Name(Item, Temporary_File_Name, sizeof(Temporary_File_Name));

                        Xila.Display.Set_Text(Temporary_Item_Name, Temporary_File_Name);

                        if (Item.isDirectory())
                        {
                            Xila.Display.Set_Picture(Temporary_Item_Picture, Folder_16);
                        }
                        else
                        {
                            Xila.Display.Set_Picture(Temporary_Item_Picture, File_16);
                        }
                    }
                    else
                    {
                        Xila.Display.Set_Text(Temporary_Item_Name, "");

                        Xila.Display.Set_Picture(Temporary_Item_Picture, Empty_16);
                    }

                    Item.close();
                    Xila.Task.Delay(5);
                }
            }
            else // if it is a file
            {
                switch (Operation)
                {
                case Copy:
                    Selected_Item = Temporary_Item;
                    Xila.Display.Set_Picture(F("COPY_BUT"), Paste_24);
                    break;
                case Cut:
                    Selected_Item = Temporary_Item;
                    Xila.Display.Set_Picture(F("CUT_BUT"), Paste_24);
                    break;
                default:
                    if (Mode == Dialog_Save_File)
                    {
                        Selected_Item = Temporary_Item;
                    }
                    else if (Mode == Dialog_Open_File)
                    {
                        Selected_Item = Temporary_Item;
                    }
                    break;
                }
                Go_Parent();
                Send_Instruction('R', 'F');
            }
        }
    }
    else
    {
        if (Mode == 0) // Currently cannot open multiple dialog boxes at the same time
        {
            Event_Dialog(F("Failed to open path."), Xila.Error);
        }
        Send_Instruction('R', 'D');
    }
    Refresh_Footerbar();
}

void Shell_Class::Refresh_Footerbar()
{

    switch (Mode)
    {
    case 0:
        Xila.Display.Click(F("FOOTERBAR_HOT"), 0);
        return;
        break;
    case Dialog_Save_File:
        Xila.Display.Click(F("FOOTERBAR_HOT"), 1);
        Xila.Display.Set_Text(F("VALIDATE_BUT"), F("Save"));
        break;
    case Dialog_Open_Folder:
    case Dialog_Open_File:
        Xila.Display.Click(F("FOOTERBAR_HOT"), 1);
        Xila.Display.Set_Text(F("VALIDATE_BUT"), F("Open"));
        break;
    default:
        break;
    }

    if (Selected_Item)
    {
        char Temporary_File_Name[13];
        Xila.Drive.Get_Name(Selected_Item, Temporary_File_Name, sizeof(Temporary_File_Name));
        Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_File_Name);
    }
    else
    {
        Xila.Display.Set_Text(F("FILENAME_TXT"), F(""));
    }
}

// -- File Manager Detail -- //

void Shell_Class::Open_File_Manager_Detail()
{
    Operation = Browse;
    Xila.Display.Set_Current_Page(File_Manager_Detail);
    Refresh_File_Manager_Detail();
}

void Shell_Class::Refresh_File_Manager_Detail()
{
    Temporary_Item = Xila.Drive.Open(Current_Path);

    if (!Temporary_Item)
    {
        Event_Dialog(F("Failed to get file informations."), Xila.Error);
        Open_File_Manager();
    }

    Xila.Display.Set_Text(F("PATHVAL_TXT"), Current_Path);

    char Temporary_Char_Array[25];

    Xila.Drive.Get_Name(Temporary_Item, Temporary_Char_Array, sizeof(Temporary_Char_Array));

    Xila.Display.Set_Text(F("NAMEVAL_TXT"), Temporary_Char_Array);

    if (Temporary_Item.isDirectory())
    {
        Xila.Display.Set_Text(F("TYPEVAL_TXT"), F("Directory"));
    }
    else
    {
        Xila.Display.Set_Text(F("TYPEVAL_TXT"), F("File"));
    }

    sprintf(Temporary_Char_Array, "%-ul Bytes\n", Temporary_Item.size());
    dtostrf(Temporary_Item.size(), (sizeof(Temporary_Char_Array) - 6), 0, Temporary_Char_Array);

    Xila.Display.Set_Text(F("SIZEVAL_TXT"), Temporary_Char_Array);

    time_t File_Last_Write_Time = Temporary_Item.getLastWrite();
    Xila_Time *File_Last_Write = localtime(&File_Last_Write_Time);
    sprintf(Temporary_Char_Array, "%02d/%02d/%d %02d:%02d:%02d\n", File_Last_Write->tm_mday, (File_Last_Write->tm_mon) + 1, (File_Last_Write->tm_year) + 1900, File_Last_Write->tm_hour, File_Last_Write->tm_min, File_Last_Write->tm_sec);

    Xila.Display.Set_Text(F("LASTWVAL_TXT"), Temporary_Char_Array);
}

// -- Desk -- //

void Shell_Class::Open_Desk()
{
    Verbose_Print_Line("> Open desk");

    if (Xila.Account.Current_Username[0] == '\0')
    {
        Open_Login();
        return;
    }

    Xila.Display.Set_Current_Page(Desk);

    Refresh_Desk();

    Xila.Display.Hide(F("MAXIMIZE_BUT"));
    Xila.Display.Hide(F("CLOSE_BUT"));
}

void Shell_Class::Refresh_Desk()
{
    Verbose_Print_Line("Refresh desk");

    if (Desk_Background == -1)
    {
        Xila.Display.Hide(F("COLORB_TXT"));
        Xila.Display.Show(F("IMAGEB_TXT"));
    }
    else
    {
        Xila.Display.Set_Background_Color(F("COLORB_TXT"), Desk_Background);
        Xila.Display.Hide(F("IMAGEB_TXT"));
        Xila.Display.Show(F("COLORB_TXT"));
    }

    Xila.Display.Refresh(F("0"));

    char Temporary_String[] = "SLOT _PIC";

    // List all files on the desk
    /*Temporary_Item = Xila.Drive.Open("/USERS/" + String(Xila.Account.Current_Username) + "/DESKTOP/");
    Temporary_Item.rewindDirectory();
    Temporary_Item.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot - 1 + '0';
        if (Xila.Software.Openned[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software.Openned[Slot]->Handle->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('M', '1'):
        Dock(1, 'M');
        break;
    case Instruction('M', '2'):
        Dock(2, 'M');
        break;
    case Instruction('M', '3'):
        Dock(3, 'M');
        break;
    case Instruction('M', '4'):
        Dock(4, 'M');
        break;
    case Instruction('M', '5'):
        Dock(5, 'M');
        break;
    case Instruction('M', '6'):
        Dock(6, 'M');
        break;
    case Instruction('C', '1'):
        Dock(1, 'C');
        break;
    case Instruction('C', '2'):
        Dock(2, 'C');
        break;
    case Instruction('C', '3'):
        Dock(3, 'C');
        break;
    case Instruction('C', '4'):
        Dock(4, 'C');
        break;
    case Instruction('C', '5'):
        Dock(5, 'C');
        break;
    case Instruction('C', '6'):
        Dock(6, 'C');
        break;
    default:
        Main_Instructions();
        break;
    }
}

void Shell_Class::Dock(uint8_t Slot, uint8_t Action)
{
    if (Xila.Software.Openned[Slot + 1] == NULL)
    {
        return;
    }
    if (Action == 'M') // maximize
    {
        Xila.Software.Maximize(*Xila.Software.Openned[Slot + 1]->Handle);
    }
    else if (Action == 'C')
    {
        Xila.Software.Close(*Xila.Software.Openned[Slot + 1]->Handle);
    }
}

// -- Drawer -- //

void Shell_Class::Open_Drawer()
{
    Xila.Display.Set_Current_Page(Drawer);
    Offset = 0;
    Refresh_Drawer();
}

void Shell_Class::Refresh_Drawer()
{
    if (Xila.Software.Handle[Offset] == NULL)
    {
        Offset = 0;
    }
    // Item name drawing
    char Temporary_String[11] = "ITEM _TXT";
    for (uint8_t i = 0; i < 15; i++)
    {

        Temporary_String[4] = i + 'A';

        if (Xila.Software.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software.Handle[i + Offset]->Name);

            //Serial.print(Temporary_String);
            //Serial.println(Xila.Software.Handle[i + Offset]->Name);
        }
        else
        {
            Xila.Display.Set_Text(Temporary_String, "");
        }
        Xila.Task.Delay(1);
    }

    // Item picture drawing
    strcpy(Temporary_String, "ITEM _PIC");
    for (uint8_t i = 0; i < 15; i++)
    {
        Temporary_String[4] = i + 'A';

        if (Xila.Software.Handle[i + Offset] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software.Handle[i + Offset]->Icon);
            /*Serial.print(Temporary_String);
            Serial.println(Xila.Software.Handle[i + Offset]->Name);*/
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
        Xila.Task.Delay(1);
    }
}

void Shell_Class::Drawer_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {

    case Instruction('N', 'd'): // Nd : Next drawer items
        if ((Offset + 15) < (sizeof(Xila.Software.Handle) / sizeof(Xila.Software.Handle[1])))
        {
            if (Xila.Software.Handle[Offset + 15] != NULL)
            {
                Offset += 15;
                Refresh_Drawer();
            }
        }
        break;
    case Instruction('P', 'd'): // Pd : Previous drawer items
        if (Offset > 14)
        {
            Offset -= 15;
            Refresh_Drawer();
        }
        break;
    case Instruction('d', '0'): // dx : Open software from drawer
        Open_From_Drawer(0);
        break;
    case Instruction('d', '1'): // dx : Open software from drawer
        Open_From_Drawer(1);
        break;
    case Instruction('d', '2'): // dx : Open software from drawer
        Open_From_Drawer(2);
        break;
    case Instruction('d', '3'): // dx : Open software from drawer
        Open_From_Drawer(3);
        break;
    case Instruction('d', '4'): // dx : Open software from drawer
        Open_From_Drawer(4);
        break;
    case Instruction('d', '5'): // dx : Open software from drawer
        Open_From_Drawer(5);
        break;
    case Instruction('d', '6'): // dx : Open software from drawer
        Open_From_Drawer(6);
        break;
    case Instruction('d', '7'): // dx : Open software from drawer
        Open_From_Drawer(7);
        break;
    case Instruction('d', '8'): // dx : Open software from drawer
        Open_From_Drawer(8);
        break;
    case Instruction('d', '9'): // dx : Open software from drawer
        Open_From_Drawer(9);
        break;
    case Instruction('d', 'A'): // dx : Open software from drawer
        Open_From_Drawer(10);
        break;
    case Instruction('d', 'B'): // dx : Open software from drawer
        Open_From_Drawer(11);
        break;
    case Instruction('d', 'C'): // dx : Open software from drawer
        Open_From_Drawer(12);
        break;
    case Instruction('d', 'D'): // dx : Open software from drawer
        Open_From_Drawer(13);
        break;
    case Instruction('d', 'E'): // dx : Open software from drawer
        Open_From_Drawer(14);
        break;
    default:
        Main_Instructions();
        break;
    }
}

void Shell_Class::Open_From_Drawer(uint8_t Slot)
{
    if ((Slot + Offset) < (sizeof(Xila.Software.Handle) / sizeof(Software_Handle_Class *)))
    {
        if (Xila.Software.Handle[Slot + Offset] != NULL)
        {
            if (Xila.Software.Open(*Xila.Software.Handle[Slot + Offset]) != Xila.Success)
            {
                Verbose_Print_Line("Failed to open software");
                Event_Dialog(F("Failed to open software"), Xila.Error);
            }
        }
        else
        {
            Open_Drawer();
        }
    }
    else
    {
        Open_Drawer();
    }
}

// -- File manager main -- //

void Shell_Class::Open_File_Manager()
{
    Xila.Display.Set_Current_Page(File_Manager_Main);
    Offset = 0;
    Operation = Browse;
    memset(Current_Path, '\0', sizeof(Current_Path));
    strcpy(Current_Path, "/");

    Refresh_File_Manager();
}

void Shell_Class::File_Manager_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('R', 'F'): // -- Refresh file manager
        Refresh_File_Manager();
        break;
    case Instruction('C', 'l'):
        if (Mode == 0)
        {
            Send_Instruction('O', 'D');
        }
        else
        {
            Xila.Dialog.State = Xila.Button_3;
        }
        break;
    case Instruction('C', 'o'): // copy file
        Operation = Browse;
        Refresh_File_Manager();
        if (Operation == Copy) //paste
        {
            if (Selected_Item.isDirectory())
            {
                Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Drive.Copy(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Event_Dialog(F("Failed to copy file."), Xila.Error);
                }
            }

            Xila.Display.Set_Picture(F("COPY_BUT"), Copy_24);
        }
        else
        {
            Operation = Copy;

            Xila.Display.Set_Picture(F("COPY_BUT"), Cut_24);
        }

        break;
    case Instruction('C', 'u'):
        Operation = Browse;
        Refresh_File_Manager();
        if (Operation == Cut) // paste
        {
            if (Selected_Item.isDirectory())
            {
                Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Drive.Copy(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Event_Dialog(F("Failed to copy file."), Xila.Error);
                }
            }

            Xila.Display.Set_Picture(F("CUT_BUT"), Cut_24);
        }
        else
        {
            Operation = Cut;

            Xila.Display.Set_Picture(F("CUT_BUT"), Cut_24);
        }

        break;
    case Instruction('D', 'e'):
        Operation = Browse;
        Refresh_File_Manager();
        Operation = Delete;

        break;
    case Instruction('R', 'e'):
        Operation = Browse;
        Refresh_File_Manager();
        Operation = Rename;

        break;
    case Instruction('N', 'P'):
        Offset += 29;
        Refresh_File_Manager();
        break;
    case Instruction('P', 'P'):
        Offset -= 29;
        Refresh_File_Manager();
        break;
    case Instruction('V', 'a'):
        switch (Mode)
        {
        case Dialog_Open_File:
            if (!Selected_Item.isDirectory())
            {
                Xila.Dialog.Pointer = &Selected_Item;
                Xila.Dialog.State = Xila.Button_1;
                Xila.Task.Delay(20);
            }
            break;

        case Dialog_Open_Folder:
            if (Selected_Item.isDirectory())
            {
                Xila.Dialog.Pointer = &Selected_Item;
                Xila.Dialog.State = Xila.Button_1;
                Xila.Task.Delay(20);
            }
            break;
        case Dialog_Save_File:
            if (!Selected_Item.isDirectory())
            {
                Xila.Dialog.Pointer = &Selected_Item;
                Xila.Dialog.State = Xila.Button_1;
                Xila.Task.Delay(20);
            }
            break;
        default:
            break;
        }
        break;
    case Instruction('R', 'D'): // open root directory
        Operation = Browse;
        Verbose_Print_Line("Open root directory");
        memset(Current_Path, '\0', sizeof(Current_Path));
        Current_Path[0] = '/';
        Refresh_File_Manager();
        break;
    case Instruction('H', 'D'): // open home directory
        Operation = Browse;
        memset(Current_Path, '\0', sizeof(Current_Path));
        strlcpy(Current_Path, Users_Directory_Path "/", sizeof(Current_Path));
        strlcat(Current_Path, Xila.Account.Current_Username, sizeof(Current_Path));
        Refresh_File_Manager();
        break;
    case Instruction('N', 'f'): // -- Create a new file -- //
        strcpy(Current_Item_Name, "NEWFILE .TXT");
        for (uint8_t i = 0; i <= 10; i++)
        {
            if (i < 10)
            {
                Current_Item_Name[7] = i + '0';
                if (!Xila.Drive.Exists(String(Current_Path) + String("/") + String(Current_Item_Name)))
                {
                    Xila.Drive.Open(String(Current_Path) + String("/") + String(Current_Item_Name), FILE_WRITE).close();
                    break;
                }
            }
            else
            {
                Event_Dialog(F("Failed to create file."), Xila.Error);
                break;
            }
        }
        Refresh_File_Manager();
        break;
    case Instruction('N', 'F'): // -- Create a new directory --//
        strcpy(Current_Item_Name, "NEWDIRE ");
        for (uint8_t i = 0; i <= 10; i++)
        {
            if (i < 10)
            {
                Current_Item_Name[7] = i + '0';
                if (!Xila.Drive.Exists(String(Current_Path) + "/" + String(Current_Item_Name)))
                {
                    if (!Xila.Drive.Make_Directory(String(Current_Path) + "/" + String(Current_Item_Name)))
                    {
                        Event_Dialog(F("Failed to create folder."), Xila.Error);
                    }
                    break;
                }
            }
            else
            {
                Event_Dialog(F("Failed to create folder."), Xila.Error);
                break;
            }
        }
        Refresh_File_Manager();
        break;
    case Instruction('K', 'P'): // -- Open keyboard to input the path -- //
        Keyboard_Dialog(Current_Path, sizeof(Current_Path));
        Refresh_File_Manager();
        break;
    case Instruction('B', 'a'):
        Operation = Browse;
        Xila.Display.Set_Current_Page(File_Manager_Main);
        Refresh_File_Manager();

        break;
    case Instruction('G', 'D'): // -- Get details on selected item
        Operation = Browse;
        Refresh_File_Manager();
        Operation = Detail;
        break;

    case Instruction('K', 'F'): // -- Open keyboard to input current item name -- //
        if (Mode == Dialog_Save_File)
        {
            Keyboard_Dialog(Current_Item_Name, sizeof(Current_Item_Name));
            strlcat(Current_Path, Current_Item_Name, sizeof(Current_Path));
            Selected_Item = Xila.Drive.Open(Current_Path);
        }
        Refresh_File_Manager();
        break;
    case Instruction('G', 'P'):
        Go_Parent();
        Refresh_File_Manager();
        break;

    default:
        Main_Instructions();
        break;
    }
}

// -- Shortcut methods -- //

void Shell_Class::Go_Parent()
{
    for (uint8_t i = sizeof(Current_Path); i >= 0; i--)
    {

        if (Current_Path[i] == '/')
        {
            if (i != 0)
            {
                Current_Path[i] = '\0';
            }
            return;
        }
        else
        {
            Current_Path[i] = '\0';
        }
    }
}

// -- Load -- //

void Shell_Class::Open_Load(uint8_t Mode)
{
    Xila.Display.Set_Current_Page(Load);
    switch (Mode)
    {
    case Shutdown:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Shutdown"));
        Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Shutting down ..."));
        break;
    case Login:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Login"));
        Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Loading user data ..."));
        break;
    case Restart:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Restart"));
        Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Restarting ..."));
        break;

    default:
        break;
    }
}

// -- Login -- //

void Shell_Class::Open_Login()
{
    if (Xila.Account.State == Xila.Account.Disconnected) // Check if logged
    {
        Verbose_Print_Line("> Open login page");
        Xila.Display.Set_Current_Page(Login);
        memset(Username, '\0', sizeof(Username));
        memset(Password_1, '\0', sizeof(Password_1));
        strcpy(Username, "Username");
        strcpy(Password_1, "Password");
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Refresh_Login()
{
    Xila.Display.Set_Text(F("USERNAME_TXT"), Username);
    Xila.Display.Set_Text(F("PASSWORD_TXT"), Password_1);
}

void Shell_Class::Login_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('K', 'U'):
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Login();
        break;

    case Instruction('K', 'P'):
        Keyboard_Dialog(Password_1, sizeof(Password_1), true);
        Refresh_Login();
        break;

    case Instruction('L', 'o'): // Lo : Login with entred username and password
        if (Xila.Account.Check_Credentials(Username, Password_1) == Xila.Success)
        {
            if (Xila.Account.State == Xila.Account.Locked && (strcmp(Xila.Account.Current_Username, Username) != 0)) // if a preced user was connected and we connect from a new user, have to close all of it's software.
            {
                for (uint8_t i = 2; i < 8; i++)
                {
                    if (Xila.Software.Openned[i] != NULL)
                    {
                        Xila.Software.Close(*Xila.Software.Openned[i]->Handle);
                    }
                }
            }

            strcpy(Xila.Account.Current_Username, Username);

            Open_Load(Login);

            if (Load_Registry() != Xila.Success)
            {
                Event_Dialog(F("Failed to load user registry."), Xila.Error);
            }

#if ANIMATION == 1
            Xila.Task.Delay(4000);
#endif

            Xila.Display.Set_Value(F("STATE_VAR"), 2);

#if ANIMATION == 1
            Xila.Task.Delay(1000);
#endif
            Open_Desk();
        }
        else
        {
            Event_Dialog(F("Wrong credentials !"), Xila.Error);
            Refresh_Login();
        }
        break;
    default:
        Main_Instructions();
        break;
    }
}

void Shell_Class::Logout()
{
    if (Xila.Account.Current_Username[0] != '\0')
    {
        Save_Registry();
    }
    Xila.Account.Logout();

    Open_Login();
}

// -- Preferences -- //

// -- Personnal -- //

void Shell_Class::Open_Preferences_Personal()
{
    Xila.Display.Set_Current_Page(Preferences_Personal);
    strcpy(Username, Xila.Account.Current_Username);
    memset(Password_1, '\0', sizeof(Password_1));
    memset(Password_2, '\0', sizeof(Password_2));
    Refresh_Preferences_Personal();
}

void Shell_Class::Preferences_Personal_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('C', 'B'):
    {
        if (Desk_Background < 0)
        {
            Desk_Background = 16904;
        }
        uint16_t Temporary_Color = Desk_Background;
        Color_Picker_Dialog(Temporary_Color);
        Desk_Background = Temporary_Color;
        break;
    }
    case Instruction('K', 'U'):
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Preferences_System();
    case Instruction('K', 'P'):
        Keyboard_Dialog(Password_1, sizeof(Password_1));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'p'):
        Keyboard_Dialog(Password_2, sizeof(Password_2));
        Refresh_Preferences_System();
        break;
    case Instruction('C', 'U'):
        if (Xila.Account.Change_Username(Xila.Account.Current_Username, Username) != Xila.Success)
        {
            Event_Dialog(F("Failed to change username."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("Username successfully modified."), Xila.Information);
        }
        Refresh_Preferences_System();
        break;
    case Instruction('C', 'P'):
        if (strcmp(Password_1, Password_2) == 0)
        {
            if (Xila.Account.Change_Password(Xila.Account.Current_Username, Password_1) != Xila.Success)
            {
                Event_Dialog(F("Failed to change password."), Xila.Error);
            }
            else
            {
                Event_Dialog(F("Password successfully modified."), Xila.Information);
            }
        }
        else
        {
            Event_Dialog(F("Passwords doesn't match."), Xila.Error);
        }
        Refresh_Preferences_System();
        break;
    case Instruction('D', 'A'): // Disable autologin
        Xila.Account.Set_Autologin(0);
        break;
    case Instruction('E', 'A'): // Enable autologin
        Xila.Account.Set_Autologin(1);
        break;
    case Instruction('D', 'U'):
        if (Event_Dialog(F("Are you sure to delete this user ?"), Xila.Question) == Xila.Button_1)
        {
            if (Xila.Account.Delete(Xila.Account.Current_Username) != Xila.Success)
            {
                Event_Dialog(F("Cannot delete user."), Xila.Error);
            }
            else
            {
                Event_Dialog(F("User successfully deleted."), Xila.Error);
            }
        }
        Refresh_Preferences_System();
        break;
    default:
        Main_Instructions();
        break;
    }
}

void Shell_Class::Refresh_Preferences_Personal()
{
    if (Desk_Background == -1)
    {
        Xila.Display.Click(F("DEFAULTB_RAD"), 0);
    }
    else
    {
        Xila.Display.Click(F("COLORB_RAD"), 0);
        Xila.Display.Set_Value(F("COLORB_NUM"), Desk_Background);
    }
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Xila.Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
}

// -- Hardware -- //

void Shell_Class::Open_Preferences_Hardware()
{
    Xila.Display.Set_Current_Page(Preferences_Hardware);
    Standby_Display_Time = Xila.Display.Standby_Time;
    Refresh_Preferences_Hardware();
}

void Shell_Class::Refresh_Preferences_Hardware()
{
    Xila.Display.Set_Value(F("VOLUME_SLI"), Xila.Sound.Get_Volume());
    Xila.Display.Set_Value(F("SSTANDBY_NUM"), Standby_Display_Time);

    switch (Xila.Drive.Card_Type())
    {
    case CARD_NONE:
        Xila.Display.Set_Text(F("DRIVETYPE_TXT"), F("Drive type : None"));
        break;
    case CARD_SD:
        Xila.Display.Set_Text(F("DRIVETYPE_TXT"), F("Drive type : SDSC"));
        break;
    case CARD_SDHC:
        Xila.Display.Set_Text(F("DRIVETYPE_TXT"), F("Drive type : SDHC"));
        break;
    case CARD_MMC:
        Xila.Display.Set_Text(F("DRIVETYPE_TXT"), F("Drive type : MMC"));
        break;
    case CARD_UNKNOWN:
        Xila.Display.Set_Text(F("DRIVETYPE_TXT"), F("Drive type : Unknow"));
        break;
    }

    Xila.Display.Set_Value(F("DRIVESIZE_NUM"), (Xila.Drive.Card_Size() / (1024 * 1024)));
    //Xila.Display.Set_Value(F("USEDSPACE_NUM"), (Xila.Drive.usedBytes() / (1024 * 1024)));
}

void Shell_Class::Preferences_Hardware_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('T', 'D'): // -- Drive testing
    {
        Temporary_Item = Xila.Drive.Open(F(Test_Path), FILE_WRITE);
        if (!Temporary_Item)
        {
            Event_Dialog(F("Failed to start the write test."), Xila.Error);
            Xila.Display.Set_Current_Page(Preferences_Hardware);
            break;
        }
        static uint8_t Buffer[512] = {255};
        uint16_t i;
        double Time = millis();

        for (i = 0; i < 2048; i++)
        {
            Last_Watchdog_Feed = millis();
            Temporary_Item.write(Buffer, sizeof(Buffer));
        }

        Time = millis() - Time;
        Time /= 1000;               // convert time in sec
        Time = (2048 * 512) / Time; // divide quantity data copied by the time in sec
        Time = Time / 1000;

        Xila.Display.Set_Value(F("WRITESPEED_NUM"), (uint32_t)Time);
        Temporary_Item.close();

        Temporary_Item = Xila.Drive.Open(F(Test_Path));
        if (!Temporary_Item)
        {
            Event_Dialog(F("Failed to start the read test."), Xila.Error);
            Xila.Display.Set_Current_Page(Preferences_Hardware);
            break;
        }

        size_t Length = Temporary_Item.size();
        Time = millis();
        while (Length)
        {
            Last_Watchdog_Feed = millis();
            if (Length > 512)
            {
                Temporary_Item.read(Buffer, sizeof(Buffer));
                Length -= sizeof(Buffer);
            }
            else
            {
                Temporary_Item.read(Buffer, Length);
                Length = 0;
            }
        }

        Time = millis() - Time;
        Time /= 1000;
        Time = Temporary_Item.size() / Time;
        Time = Time / 1000;
        Temporary_Item.close();

        Xila.Display.Set_Value(F("READSPEED_NUM"), (uint32_t)Time);
        Xila.Drive.Remove(F(Test_Path));
        break;
    }
    case Instruction('k', 'S'): // -- Input standby display time
        Temporary_Float = Standby_Display_Time;
        Keypad_Dialog(Temporary_Float);
        Standby_Display_Time = Temporary_Float;
        Refresh_Preferences_Hardware();
        break;
    case Instruction('D', 'C'):
        Xila.Display.Calibrate();
        break;
    case Instruction('S', 'S'):
        Xila.Sound.Set_Volume((uint8_t)Temporary_Variable[2]);
        break;
    case Instruction('S', 'a'):
        Xila.Display.Brightness = Brightness;
        Xila.Display.Standby_Time = Standby_Display_Time;
        if (Xila.Display.Save_Registry() != Xila.Success)
        {
            Event_Dialog(F("Failed to set display registry."), Xila.Error);
        }

        if (Xila.Sound.Save_Registry() != Xila.Success)
        {
            Event_Dialog(F("Failed to set sound registry."), Xila.Error);
        }
        // Add standby registry
        Refresh_Preferences_Hardware();
        break;
    default:
        Main_Instructions();
        break;
    }
}

// -- Network -- //

void Shell_Class::Open_Preferences_Network()
{
    Xila.Display.Set_Current_Page(Preferences_Network);
    strlcpy(WiFi_Name, Xila.WiFi.SSID().c_str(), sizeof(WiFi_Name));
    Refresh_Preferences_Network();
}

void Shell_Class::Refresh_Preferences_Network()
{
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
}

void Shell_Class::Preferences_Network_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('K', 'W'):
        Keyboard_Dialog(WiFi_Name, sizeof(WiFi_Name));
        Refresh_Preferences_Network();
        break;
    case Instruction('K', 'w'):
        Keyboard_Dialog(WiFi_Password, sizeof(WiFi_Password));
        Refresh_Preferences_Network();
        break;
    case Instruction('W', 'D'):
        Xila.WiFi.disconnect();
        Refresh_Preferences_Network();
        break;
    case Instruction('W', 'C'):
        Xila.WiFi.Set_Credentials(Name, WiFi_Password);
        Refresh_Preferences_Network();
        break;
    case Instruction('W', 'A'):
        Xila.WiFi.disconnect();
        if (Xila.WiFi.softAP(Xila.System.Get_Device_Name(), WiFi_Password) != true)
        {
            Event_Dialog(F("Failed to enable the access point."), Xila.Error);
            Refresh_Preferences_Network();
        }
        break;
    default:
        Main_Instructions();
        break;
    }
}

// -- System -- //

void Shell_Class::Open_Preferences_System()
{
    Xila.Display.Set_Current_Page(Preferences_System);
    Autologin = false;

    memset(NTP_Server, '\0', sizeof(NTP_Server));
    strcpy(NTP_Server, Xila.Time.NTP_Server);
    GMT_Offset = Xila.Time.GMT_Offset;
    Daylight_Offset = Xila.Time.Daylight_Offset;

    memset(Username, '\0', sizeof(Username));
    memset(Name, '\0', sizeof(Name));
    strcpy(Name, Xila.System.Get_Device_Name());
    Refresh_Preferences_System();
}

void Shell_Class::Preferences_System_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('K', 'U'):
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'D'):
        Keyboard_Dialog(Name, sizeof(Name));
        Refresh_Preferences_System();
        break;
    case Instruction('k', 'O'):
        Temporary_Float = GMT_Offset;
        Keypad_Dialog(Temporary_Float);
        GMT_Offset = Temporary_Float;
        Refresh_Preferences_System();
        break;
    case Instruction('k', 'o'):
        Temporary_Float = Daylight_Offset;
        Keypad_Dialog(Temporary_Float);
        Daylight_Offset = Temporary_Float;
        Refresh_Preferences_System();
        break;
    case Instruction('A', 'U'):
        if (Xila.Account.Add(Username, ""))
        {
            Event_Dialog(F("Failed to add user."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("User successfully added."), Xila.Information);
        }
        Refresh_Preferences_System();
        break;

    case Instruction('S', 'a'):
        strlcpy(Xila.Time.NTP_Server, NTP_Server, sizeof(Xila.Time.NTP_Server));
        Xila.Time.GMT_Offset = GMT_Offset;
        Xila.Time.Daylight_Offset = Daylight_Offset;
        if (Xila.Time.Save_Registry() != Xila.Success)
        {
            Event_Dialog(F("Failed to save time registry"), Xila.Error);
        }
        strlcpy(Xila.System.Device_Name, Name, sizeof(Xila.System.Device_Name));
        if (Xila.System.Save_Registry() != Xila.Success)
        {
            Event_Dialog(F("Failed to save time registry"), Xila.Error);
        }
        break;
    case Instruction('O', 'A'):
        Xila.Display.Set_Current_Page(About);
        break;
    case Instruction('U', 'p'):
        System_Update();
        break;
    default:
        Main_Instructions();
        break;
    }
}

void Shell_Class::Refresh_Preferences_System()
{
    Xila.Display.Set_Text(F("NTPVAL_TXT"), NTP_Server);
    Xila.Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), GMT_Offset);

    Xila.Display.Set_Text(F("DEVICEVAL_TXT"), Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
}

void Shell_Class::System_Update()
{
    if (Event_Dialog(F("Do you really want to update Xila ? That will make the system restart."), Xila.Warning) != Xila.Button_1)
    {
        return;
    }

    Xila.Display.Set_Current_Page(Load);
    Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Updating firmware"));
    Xila.Display.Set_Text(F("LOAD_TXT"), F("Update"));
    Xila.Display.Refresh(F("CLOSE_BUT"));

    File Temporary_File = Xila.Drive.Open(Display_Executable_Path);
    if (!Temporary_File)
    {
        Refresh_Preferences_System();
        return;
    }
    if (Xila.System.Load_Executable(Temporary_File, 'D') != Xila.Success)
    {
        Event_Dialog(F("Failed to update"), Xila.Error);
        Refresh_Preferences_System();
        return;
    }

    Temporary_File = Xila.Drive.Open(Microcontroller_Executable_Path);
    if (!Temporary_File)
    {
        Refresh_Preferences_System();
        return;
    }
    if (Xila.System.Load_Executable(Temporary_File, 'M') != Xila.Success)
    {
        Event_Dialog(F("Failed to update"), Xila.Error);
        Refresh_Preferences_System();
        return;
    }

    Xila.System.Restart();
}

// -- Shutdown -- //

void Shell_Class::Open_Shutdown()
{

    Xila.Display.Set_Current_Page(Shutdown);
}

void Shell_Class::Shutdown_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('R', 'S'): // RS : Restart system
        Xila.System.Restart();
        break;
    case Instruction('H', 'S'): // HS : hibernate sys
        Xila.System.Hibernate();
        break;
    case Instruction('L', 'S'): // LS : lock system
        Save_Registry();
        Xila.Account.Lock();
        Open_Login();
        break;
    case Instruction('S', 'S'): // SS : shutdown
        Xila.Display.Set_Current_Page(Load);
        Xila.System.Shutdown();
        break;
    default:
        Main_Instructions();
        break;
    }
}

// -- Dialogs -- //

// -- Color dialog -- //

void Shell_Class::Open_Color_Picker()
{
    Xila.Display.Set_Current_Page(Color_Picker);

    uint8_t Temporary_Byte = *(uint32_t *)Xila.Dialog.Pointer >> 11;

    Xila.Display.Set_Value(F("RED_SLI"), Temporary_Byte);
    Temporary_Byte = *(uint32_t *)Xila.Dialog.Pointer >> 3;
    Temporary_Byte = Temporary_Byte >> 2;
    Xila.Display.Set_Value(F("GREEN_SLI"), Temporary_Byte);
    Temporary_Byte = *(uint32_t *)Xila.Dialog.Pointer << 3;
    Temporary_Byte = Temporary_Byte >> 3;
    Xila.Display.Set_Value(F("BLUE_SLI"), Temporary_Byte);
    Xila.Display.Click(F("COLOR_NUM"), 0);
}

void Shell_Class::Color_Picker_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog.State = Xila.Button_1;
        Xila.Task.Delay(20);
        break;
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Button_3;
        Xila.Task.Delay(20);
        break;
    default:
        Main_Instructions();
        break;
    }
}

Xila_Class::Event Shell_Class::Color_Picker_Dialog(uint16_t &Color)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // --
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &Color;
    // --
    Open_Color_Picker();
    // -- Tasks suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        Color_Picker_Instructions();
    }
    // -- Retore software state
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

// -- Event dialog -- //

void Shell_Class::Event_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('B', '1'):
        Xila.Dialog.State = Xila.Button_1;
        Xila.Task.Delay(20);
        break;
    case Instruction('B', '2'):
        Xila.Dialog.State = Xila.Button_1;
        Xila.Task.Delay(20);
        break;
    case Instruction('B', '3'):
        Xila.Dialog.State = Xila.Button_1;
        Xila.Task.Delay(20);
        break;
    default:
        Main_Instructions();
        break;
    }
}

Xila_Class::Event Shell_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Display.Send_Raw(F("PAGE=dp")); // save app page id
    Xila.Display.Set_Current_Page(F("Shell_Event"));

    Xila.Dialog.State = Xila.None;

    if (Button_Text_1 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON1_BUT"), Button_Text_1);
        if (Button_Text_2 != NULL)
        {
            Xila.Display.Set_Text(F("BUTTON2_BUT"), Button_Text_2);
        }
        else
        {
            Xila.Display.Set_Text(F("BUTTON2_BUT"), F(""));
        }
        if (Button_Text_3 != NULL)
        {
            Xila.Display.Set_Text(F("BUTTON3_BUT"), Button_Text_3);
        }
        else
        {
            Xila.Display.Set_Text(F("BUTTON3_BUT"), F(""));
        }
    }

    Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);

    switch (Event_Type)
    {
    case Xila.Error:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Cross);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Red);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Error"));
        break;
    case Xila.Warning:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Yellow);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Warning"));
        break;
    case Xila.Information:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Blue);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Information"));
        break;
    case Xila.Question:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Question_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Green);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Question"));
    default:
        break;
    }
    Xila.Display.Show(F("CLOSE_BUT"));
    // -- Tasks is suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        Event_Instructions();
    }

    Xila.Display.Set_Current_Page(F("PAGE")); //go back to app page

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

// -- Open file dialog -- //

Xila_Class::Event Shell_Class::Open_File_Dialog(File &File_To_Open)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Display.Send_Raw(F("PAGE=dp"));

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &File_To_Open;

    Mode = Dialog_Open_File;
    Open_File_Manager();

    while (Xila.Dialog.State == Xila.None)
    {
        Last_Watchdog_Feed = millis();
        File_Manager_Instructions();
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        File_To_Open = *(File *)Xila.Dialog.Pointer;
    }
    //
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

Xila_Class::Event Shell_Class::Save_File_Dialog(File &File_To_Save)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Display.Send_Raw(F("PAGE=dp"));

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &File_To_Save;

    Mode = Dialog_Save_File;
    Open_File_Manager();

    while (Xila.Dialog.State == Xila.None)
    {
        File_Manager_Instructions();
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        File_To_Save = *(File *)Xila.Dialog.Pointer;
    }
    //
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

Xila_Class::Event Shell_Class::Open_Folder_Dialog(File &Folder_To_Open)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    // -- Save context
    Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
    Xila.Display.Send_Raw(F("PAGE=dp"));
    // --
    Xila.Dialog.Pointer = &Folder_To_Open;
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Caller_Software = Xila.Software.Openned[0];
    // --
    Mode = Dialog_Open_Folder;
    Open_File_Manager();
    // -- Tasks suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        File_Manager_Instructions();
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        Folder_To_Open = *(File *)Xila.Dialog.Pointer;
    }
    // -- Retore software state
    Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
    Xila.Display.Set_Current_Page(F("PAGE"));
    //
    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;
    //
    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

// -- Install dialog -- //

void Shell_Class::Open_Install()
{
    Xila.Display.Set_Current_Page(F("Shell_Install"));
    Desk_Background = 16904;
    GMT_Offset = 0;
    Daylight_Offset = 0;
    memset(Name, '\0', sizeof(Name));
    strcpy(Name, "ESP32");
    memset(Username, '\0', sizeof(Username));
    strcpy(Username, "Username");
    memset(Password_1, '\0', sizeof(Password_1));
    memset(Password_2, '\0', sizeof(Password_2));
    memset(WiFi_Name, '\0', sizeof(WiFi_Name));
    memset(WiFi_Password, '\0', sizeof(WiFi_Password));
}

void Shell_Class::Refresh_Install()
{
    if (Desk_Background < 0)
    {
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 1);
        Xila.Display.Set_Value(F("COLORB_RAD"), 0);
    }
    else
    {
        Xila.Display.Set_Value(F("DEFAULTB_RAD"), 0);
        Xila.Display.Set_Value(F("COLORB_RAD"), 1);
        Xila.Display.Set_Value(F("COLORB_NUM"), Desk_Background);
    }
    Xila.Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), Daylight_Offset);
    Xila.Display.Set_Text(F("DEVICE_TXT"), Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Xila.Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
}

void Shell_Class::Install_Instructions()
{
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('B', 'a'):
        if (Desk_Background < 0)
        {
            Desk_Background = 16904;
        }
        else
        {
            Desk_Background = -1;
        }
        Refresh_Install();
        break;
    case Instruction('A', 'u'): // -- Enable or disable autologin
        Autologin = !Autologin;
        Xila.Display.Set_Value(F("AUTOLOGIN_CHE"), Autologin);
        break;
    case Instruction('C', 'C'): // -- Open color picker for desk color
    {
        if (Desk_Background < 0)
        {
            Desk_Background = 16904;
        }
        uint16_t Temporary_Color = (uint16_t)Desk_Background;
        Color_Picker_Dialog(Temporary_Color);
        Refresh_Install();
        break;
    }
    case Instruction('k', 'O'):
        Temporary_Float = GMT_Offset;
        Keypad_Dialog(Temporary_Float);
        GMT_Offset = Temporary_Float;
        Refresh_Install();
        break;
    case Instruction('k', 'o'): // --
    {
        Temporary_Float = Daylight_Offset;
        Keypad_Dialog(Temporary_Float);
        Daylight_Offset = Temporary_Float;
        Refresh_Install();
        break;
    }
    case Instruction('K', 'D'): // -- Device name keyboard input
        Keyboard_Dialog(Name, sizeof(Name));
        Refresh_Install();
        break;
    case Instruction('K', 'U'): // -- Username keyboard input
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Install();
        break;
    case Instruction('K', 'P'): // -- Password keyboard input
        Keyboard_Dialog(Password_1, sizeof(Password_1));
        Refresh_Install();
        break;
    case Instruction('K', 'p'): // -- Confirm password keyboard input
        Keyboard_Dialog(Password_2, sizeof(Password_2));
        Refresh_Install();
        break;
    case Instruction('K', 'W'): // -- WiFi name keyboard input
        Keyboard_Dialog(WiFi_Name, sizeof(WiFi_Name));
        Refresh_Install();
        break;
    case Instruction('K', 'w'): // -- WiFi password keyboard input
        Keyboard_Dialog(WiFi_Password, sizeof(WiFi_Password));
        Refresh_Install();
        break;
    case Instruction('C', 'o'):
    {
        if (strcmp(Password_1, Password_2) != 0)
        {
            Event_Dialog(F("Passwords does not correspond !"), Xila.Error);
        }
        if (Event_Dialog(F("Are you sure of the information entered ?"), Xila.Question) != Xila.Button_1)
        {
            // -- Regional preferences
            Xila.Time.GMT_Offset = GMT_Offset;
            Xila.Time.Daylight_Offset = Daylight_Offset;
            if (Xila.Time.Save_Registry() != Xila.Success)
            {
                Event_Dialog(F("Cannot set the regional preferences."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
            }
            strlcpy(Xila.Account.Current_Username, Username, sizeof(Xila.Account.Current_Username));
            // -- User account preferences
            if (Autologin == true)
            {
                Xila.Account.Set_Autologin(1);
            }
            else
            {
                Xila.Account.Set_Autologin(0);
            }
            if (Xila.Account.Save_Registry() != Xila.Success)
            {
                Event_Dialog(F("Cannot set the account registry."), Xila.Error);
            }
            if (Xila.Account.Add(Username, Password_1) != Xila.Success)
            {
                Event_Dialog(F("Cannot create the user account."), Xila.Error);
            }
            Xila.Account.Login(Username, Password_1);
        }
    }
    break;
    case Instruction('W', 'C'): // WiFi connect
        Xila.WiFi.Set_Credentials(WiFi_Name, WiFi_Password);

        break;
    default:
        Main_Instructions();
        break;
    }
}

// -- Keyboard dialog -- //

void Shell_Class::Open_Keyboard()
{

    Xila.Display.Set_Current_Page(Keyboard);
    Xila.Display.Set_Value(F("MAXLENGTH_VAR"), Xila.Dialog.Long[0]);
    Xila.Display.Set_Text(F("INPUT_VAR"), (char *)Xila.Dialog.Pointer);
    Xila.Display.Set_Mask(F("INPUT_TXT"), (bool)Xila.Dialog.Long[1]);
    Xila.Keyboard.Clear();
}

Xila_Class::Event Shell_Class::Keyboard_Dialog(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);
    Verbose_Print_Line("Keyboard dialog");

    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // -- Initialize variable
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Long[0] = Char_Array_Size;
    Xila.Dialog.Pointer = Char_Array_To_Get;
    // -- Open keyboard dialog
    Open_Keyboard();
    //
    while (Xila.Dialog.State == Xila.None)
    {
        Keyboard_Instructions();
    }

    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

void Shell_Class::Keyboard_Instructions()
{
    if (Xila.Keyboard.Available())
    {
        char Char_Array[2];
        Char_Array[0] = Xila.Keyboard.Read();
        Char_Array[1] = '\0';
        switch (Char_Array[0])
        {
        case Xila.Keyboard.Enter:
            Xila.Display.Click(F("b210"), 0);
            break;
        case Xila.Keyboard.Backspace:
            Xila.Display.Click(F("b200"), 0);
            break;
        case Xila.Keyboard.Tab:
            Xila.Display.Click(F("b201"), 0);
        default:
            if (isPrintable(Char_Array[0]))
            {
                Xila.Display.Add_Text(F("INPUT_VAR"), Char_Array);
            }
            break;
        }
    }
    Current_Command = Get_Instruction();
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog.State = Xila.Default_Yes;
        Xila.Task.Delay(20);
        break;
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Default_Cancel;
        Xila.Task.Delay(20);
        break;
    default:
        Main_Instructions();
        break;
    }
}

// -- Keypad dialog -- //

Xila_Class::Event Shell_Class::Keypad_Dialog(float &Number_To_Get)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);
    Verbose_Print_Line("Keyboard dialog");

    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // -- Initialize variable
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &Number_To_Get;
    // -- Open keyboard dialog
    Open_Keypad();
    //
    while (Xila.Dialog.State == Xila.None)
    {
        Keypad_Instructions();
    }

    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

void Shell_Class::Open_Keypad()
{
    Xila.Display.Set_Current_Page(Keypad);
    Xila.Display.Set_Value(F("TEMPORARY_FLO"), Xila.Dialog.Long[0]);
    Xila.Display.Click(F("CONVERT_HOT"), 0);
    Xila.Keyboard.Clear();
}

void Shell_Class::Keypad_Instructions()
{
    Current_Command = Get_Instruction();
    if (Xila.Keyboard.Available())
    {
        switch (Xila.Keyboard.Read())
        {
        case '0':
            Xila.Display.Click(F("b0"), 0);
            break;
        case '1':
            Xila.Display.Click(F("b1"), 0);
            break;
        case '2':
            Xila.Display.Click(F("b2"), 0);
            break;
        case '3':
            Xila.Display.Click(F("b3"), 0);
            break;
        case '4':
            Xila.Display.Click(F("b4"), 0);
            break;
        case '5':
            Xila.Display.Click(F("b5"), 0);
            break;
        case '6':
            Xila.Display.Click(F("b6"), 0);
            break;
        case '7':
            Xila.Display.Click(F("b7"), 0);
            break;
        case '8':
            Xila.Display.Click(F("b8"), 0);
            break;
        case '9':
            Xila.Display.Click(F("b9"), 0);
            break;
        case '.':
            Xila.Display.Click(F("b99"), 0);
            break;
        case '-':
            Xila.Display.Click(F("b10"), 0);
            break;
        case Xila.Keyboard.Backspace:
            Xila.Display.Click(F("b200"), 1);
            break;
        case Xila.Keyboard.Enter:
            Xila.Display.Click(F("b210"), 0);
            break;
        }
    }
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog.State = Xila.Default_Yes;
        Xila.Task.Delay(20);
        break;
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Default_Cancel;
        Xila.Task.Delay(20);
        break;
    default:
        Main_Instructions();
        break;
    }
}
