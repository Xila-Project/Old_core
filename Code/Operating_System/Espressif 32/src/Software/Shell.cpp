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

Shell_Class::Shell_Class() : Software_Class(Shell_Handle, 6),
                             Offset(0),
                             Mode(0)
{
    Xila.Task_Create(Main_Task, "Shell Task", Memory_Chunk(6), NULL, Task_Handle);
}

Shell_Class::~Shell_Class()
{
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
    Xila.Software_Open(Shell_Handle);
}

// -- Main shell methods -- //

void Shell_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Xila.Display.Get_Current_Page())
        {
        case Pages::About:
            Instance_Pointer->Preferences_System_Commands();
            break;
        case Pages::Color_Picker:
            Instance_Pointer->Color_Picker_Commands();
            break;
        case Pages::Desk:
            Instance_Pointer->Desk_Commands();
            break;
        case Pages::Drawer:
            Instance_Pointer->Drawer_Commands();
            break;
        case Pages::Event:
            Instance_Pointer->Event_Commands();
            break;
        case Pages::File_Manager:
            Instance_Pointer->File_Manager_Commands();
            break;
        case Pages::Preferences_Hardware:
            Instance_Pointer->Preferences_Hardware_Commands();
            break;
        case Pages::Install:
            Instance_Pointer->Install_Commands();
            break;
        case Pages::Keyboard:
            Instance_Pointer->Keyboard_Commands();
            break;
        case Pages::Keypad:
            Instance_Pointer->Keypad_Commands();
            break;
        case Pages::Login:
            Instance_Pointer->Login_Commands();
            break;
        case Pages::Load:
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Command();
            Instance_Pointer->Main_Commands();
            break;
        case Pages::Preferences_Network:
            Instance_Pointer->Preferences_Network_Commands();
            break;
        case Pages::Preferences_Personal:
            Instance_Pointer->Preferences_Personal_Commands();
            break;
        case Pages::Shutdown:
            Instance_Pointer->Shutdown_Commands();
            break;
        case Pages::Preferences_System:
            Instance_Pointer->Preferences_System_Commands();
            break;
        case Pages::Welcome:
            Instance_Pointer->Install_Commands();
            break;
        default:
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Command();
            Instance_Pointer->Main_Commands();
            break;
        }
        Xila.Delay(5);
    }
}

void Shell_Class::Main_Commands()
{
    switch (Current_Command)
    {
    case Xila.Idle:
        Xila.Delay(20);
        break;
    case Xila.Watchdog:
        Xila.Feed_Watchdog();
        break;
    case Xila.Color_Picker:
        Open_Color_Picker();
        break;
    case Instruction('L', 'R'):
        Load_Registry();
        break;
    case Instruction('O', 's'): // Os : Shutdown menu
        Open_Shutdown();
        break;
    case Instruction('O', 'L'): // "OL" : Open Login page
        Open_Login();
        break;
    case Instruction('O', 'D'): // "OD" Open Desk page & load it
        Open_Desk();
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        Open_Drawer();
        break;
    case Instruction('O', 'A'): // Open about xila
        Xila.Display.Set_Current_Page(About);
        break;
    case Xila.Virtual_Keyboard:
        Open_Keyboard();
        break;
    case Xila.Virtual_Keypad:
        Open_Keypad();
        break;
    case Xila.Install_Dialog:
        Open_Install();
        break;
    case Xila.Open_File:
        Mode = Xila.Open_File;
        Open_File_Manager();
        break;
    case Xila.Open_Folder:
        Mode = Xila.Open_Folder;
        Open_File_Manager();
        break;
    case Xila.Save_File:
        Mode = Xila.Save_File;
        Open_File_Manager();
        break;
    case Xila.Event:
        // -- Already openend
        break;
    case Xila.Shutting_down:
        Open_Load(Xila.Shutting_down);
        Set_Registry(Desk_Background);
        break;
    case Xila.Restarting:
        Open_Load(Xila.Restarting);
        Set_Registry(Desk_Background);
        break;
    case Xila.Hibernating:
        Open_Load(Xila.Hibernating);
        Set_Registry(Desk_Background);
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
    case Xila.Open: // open routine
        Instance_Pointer->Open_Login();
        break;
    case Xila.Close: // close
        delete Instance_Pointer;
        Xila.Task_Delete();
        break;
    case Xila.Minimize: // minimize
        vTaskSuspend(NULL);
        break;
    case Xila.Maximize:
        if (Xila.Power_Button_Counter >= 1)
        {
            Instance_Pointer->Execute(0x534D);
        }
        break;
    }
}

void Shell_Class::Idle()
{
    Xila.Delay(20);
}

// -- Set variable -- //

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    Serial.println(Xila.Display.Get_Current_Page());

    switch (Xila.Display.Get_Current_Page())
    {
    case Preferences_Hardware:
        switch (Adress)
        {
        case 'B':
            Brightness = *(uint8_t *)Variable;
            break;
        case 'V':
            Xila.Sound.Set_Volume(*(uint8_t *)Variable);
            break;
        default:
            break;
        }
        break;
    case File_Manager:
        switch (Adress)
        {
        case 'F':
            strlcat(Current_Path, (char *)Variable, sizeof(Current_Path));
            Execute('R', 'F');            
            break;
        default:
            break;
        }
        break;
    case Keyboard:
        Verbose_Print_Line("Set dialog");
        Serial.print((char)Adress);
        if (Adress == 'I' && Xila.Dialog_Pointer != NULL)
        {
            Verbose_Print_Line("Set dialog pointer");
            Serial.print(Xila.Dialog_Long[0]);
            strlcpy((char *)Xila.Dialog_Pointer, (char *)Variable, Xila.Dialog_Long[0]);
        }
        break;
    case Keypad:
        if (Adress == 'I' && Xila.Dialog_Pointer != NULL)
        {
            memcpy(Xila.Dialog_Long, (float *)Variable, sizeof(uint32_t));
        }
        break;
    case Color_Picker:
        if (Adress == 'C' && Xila.Dialog_Pointer != NULL)
        {
            memcpy(Xila.Dialog_Long, (uint16_t *)Variable, sizeof(uint16_t));
        }
    default:
        break;
    }
}

// -- Shell registry management -- //

Xila_Event Shell_Class::Load_Registry()
{
    Temporary_Item.close();
    Desk_Background = -1;
    Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.XRF");
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
    Temporary_Item.close();
    return Xila.Success;
}

Xila_Event Shell_Class::Set_Registry(uint32_t Desk_Background)
{
    Temporary_Item.close();
    Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.XRF", FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Temporary_Item);
    Shell_Registry["Desk Background"] = Desk_Background;
    if (serializeJson(Shell_Registry, Temporary_Item) == 0)
    {
        return Xila.Error;
    }
    Temporary_Item.close();
    this->Desk_Background = Desk_Background;
    return Xila.Success;
}

// -- File manager -- //

void Shell_Class::Refresh_File_Manager()
{
    Xila.Display.Set_Text(F("PATH_TXT"), Current_Path);

    /*strcat(Current_Path, Current_File_Name);
    memset(Current_File_Name, '\0', sizeof(Current_File_Name));*/
    Temporary_Item = Xila.Drive->open(Current_Path);
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
            if (Event_Dialog(F("Are you sure to delete this item."), Xila.Question) == Xila.Button_1)
            {
                Xila.Drive->remove(Current_Path);
            }
            Operation = Browse;
            Empty_Footer_Bar();
            break;
        case Rename:
            Xila.Display.Send_Raw(F("PAGE=dp"));
            Go_Parent();
            char Temporary_Input[14];
            memset(Temporary_Input, '\0', sizeof(Temporary_Input));
            Keyboard_Dialog(Temporary_Input, sizeof(Temporary_Input));
            Xila.Drive->rename(String(Current_Path) + String(Temporary_Item.name()), String(Current_Path) + String(Temporary_Input));
            Operation = Browse;
            Empty_Footer_Bar();
            break;
        default:
            if (Temporary_Item.isDirectory())
            {
                if (Mode == Xila.Open_Folder)
                {
                    Selected_Item = Temporary_Item;
                    Xila.Display.Set_Text(F("FILENAME_TXT"), Selected_Item.name());
                }

                Temporary_Item.rewindDirectory();

                // -- Apply offset
                for (uint8_t i = 0; i < Offset; i++)
                {
                    Temporary_Item.openNextFile().close();
                }
                
                char Temporary_Item_Name[13] = "ITEM _TXT";
                char Temporary_Item_Picture[13] = "ITEM _PIC";

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
                        ;
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
                        
                        Xila.Display.Set_Text(Temporary_Item_Name, Item.name() + 1);

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
                    Xila.Delay(10);
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
                    switch (Mode)
                    {
                    case Xila.Save_File:
                        Selected_Item = Temporary_Item;
                        Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_Item.name());
                        break;
                    case Xila.Open_File:
                        Selected_Item = Temporary_Item;
                        Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_Item.name());
                        break;
                    case Xila.Open_Folder:

                        break;
                    default:

                        break;
                    }
                    break;
                }
                Go_Parent();
                Execute('R', 'e');
            }
        }
        Temporary_Item.close();
    }
    else
    {
        Event_Dialog(F("Failed to open path."), Xila.Error);
        Execute('R', 'D');
    }
}

// -- Desk -- //

void Shell_Class::Open_Desk()
{
    Verbose_Print_Line("> Open desk");

    if (Xila.Current_Username[0] == '\0')
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
    /*Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/DESKTOP/");
    Temporary_Item.rewindDirectory();
    Temporary_Item.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot - 1 + '0';
        if (Xila.Open_Software_Pointer[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Open_Software_Pointer[Slot]->Handle_Pointer->Icon);
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
    }
}

void Shell_Class::Desk_Commands()
{
    Current_Command = Get_Command();
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
        Main_Commands();
        break;
    }
}

void Shell_Class::Dock(uint8_t Slot, uint8_t Action)
{
    if (Xila.Open_Software_Pointer[Slot + 1] == NULL)
    {
        return;
    }
    if (Action == 'M') // maximize
    {
        Xila.Maximize_Software(*Xila.Open_Software_Pointer[Slot + 1]->Handle_Pointer);
    }
    else if (Action == 'C')
    {
        Xila.Close_Software(*Xila.Open_Software_Pointer[Slot + 1]->Handle_Pointer);
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
    if (Xila.Software_Handle_Pointer[Offset] == NULL)
    {
        Offset = 0;
    }
    // Item name drawing
    char Temporary_String[11] = "ITEM _TXT";
    for (uint8_t i = 0; i < 15; i++)
    {

        Temporary_String[4] = i + 'A';

        if (Xila.Software_Handle_Pointer[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software_Handle_Pointer[i + Offset]->Name);

            //Serial.print(Temporary_String);
            //Serial.println(Xila.Software_Handle_Pointer[i + Offset]->Name);
        }
        else
        {
            Xila.Display.Set_Text(Temporary_String, "");
        }
        Xila.Delay(1);
    }

    // Item picture drawing
    strcpy(Temporary_String, "ITEM _PIC");
    for (uint8_t i = 0; i < 15; i++)
    {
        Temporary_String[4] = i + 'A';

        if (Xila.Software_Handle_Pointer[i + Offset] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Software_Handle_Pointer[i + Offset]->Icon);
            /*Serial.print(Temporary_String);
            Serial.println(Xila.Software_Handle_Pointer[i + Offset]->Name);*/
        }
        else
        {
            Xila.Display.Hide(Temporary_String);
        }
        Xila.Delay(1);
    }
}

void Shell_Class::Drawer_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('N', 'd'): // Nd : Next drawer items
        if ((Offset + 15) < (sizeof(Xila.Software_Handle_Pointer) / sizeof(Xila.Software_Handle_Pointer[1])))
        {
            if (Xila.Software_Handle_Pointer[Offset + 15] != NULL)
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
        Main_Commands();
        break;
    }
}

void Shell_Class::Open_From_Drawer(uint8_t Slot)
{
    if ((Slot + Offset) < (sizeof(Xila.Software_Handle_Pointer) / sizeof(Software_Handle_Class *)))
    {
        if (Xila.Software_Handle_Pointer[Slot + Offset] != NULL)
        {
            if (Xila.Software_Open(*Xila.Software_Handle_Pointer[Slot + Offset]) != Xila.Success)
            {
                Verbose_Print_Line("Failed to open software");
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

// -- File manager -- //

void Shell_Class::Open_File_Manager()
{
    Xila.Display.Set_Current_Page(File_Manager);
    Offset = 0;
    memset(Current_Path, '\0', sizeof(Current_Path));
    strcpy(Current_Path, "/");

    switch (Mode)
    {
    case Xila.Open_File:
        Fill_Footer_Bar();
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Open"));
        break;
    case Xila.Save_File:
        Fill_Footer_Bar();
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Save"));

        break;
    case Xila.Open_Folder:
        Fill_Footer_Bar();
        Xila.Display.Set_Text(F("SAVEOPEN_BUT"), F("Open"));

        break;
    default:
        Empty_Footer_Bar();
        break;
    }

    Refresh_File_Manager();
}

void Shell_Class::File_Manager_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;

    case Instruction('R', 'F'): // -- Refresh file manager
        Refresh_File_Manager();
        break;
    case Instruction('C', 'l'):
        Empty_Footer_Bar();
        if (Mode == 0)
        {
            Open_Desk();
        }
        else
        {
            Xila.Dialog_State = Xila.Button_3;
            Temporary_Item.close();
            Selected_Item.close();
        }

        break;
    case Instruction('C', 'o'): // copy file
        if (Operation == Copy)  //paste
        {
            if (Selected_Item.isDirectory())
            {
                Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Copy_File(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Event_Dialog(F("Failed to copy file."), Xila.Error);
                }
            }
            Selected_Item.close();
            Xila.Display.Set_Picture(F("COPY_BUT"), Copy_24);
        }
        else
        {
            Operation = Copy;
            Selected_Item.close();
            Xila.Display.Set_Picture(F("COPY_BUT"), Cut_24);
        }
        Refresh_File_Manager();
        break;
    case Instruction('C', 'u'):
        if (Operation == Cut) // paste
        {
            if (Selected_Item.isDirectory())
            {
                Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Copy_File(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Event_Dialog(F("Failed to copy file."), Xila.Error);
                }
            }
            Selected_Item.close();
            Xila.Display.Set_Picture(F("CUT_BUT"), Cut_24);
        }
        else
        {
            Operation = Cut;
            Selected_Item.close();
            Xila.Display.Set_Picture(F("CUT_BUT"), Cut_24);
        }
        Refresh_File_Manager();
        break;
    case Instruction('D', 'e'):
        Operation = Delete;
        Refresh_File_Manager();
        break;
    case Instruction('R', 'e'):
        Operation = Rename;
        Refresh_File_Manager();
        break;
    case Instruction('N', 'P'): // complete
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
        case 0:
            Empty_Footer_Bar();
            break;
        case Xila.Open_File:
            if (!Selected_Item.isDirectory())
            {
                Xila.Dialog_Pointer = &Selected_Item;
                Xila.Dialog_State = Xila.Button_1;
                Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
            }
            break;

        case Xila.Open_Folder:
            if (Selected_Item.isDirectory())
            {
                Xila.Dialog_Pointer = &Selected_Item;
                Xila.Dialog_State = Xila.Button_1;
                Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
            }
            break;
        case Xila.Save_File:
            if (!Selected_Item.isDirectory())
            {
                Xila.Dialog_Pointer = &Selected_Item;
                Xila.Dialog_State = Xila.Button_1;
                Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
            }

            break;
        default:
            break;
        }
        break;
    case Instruction('R', 'D'): // open root directory
        memset(Current_Path, '\0', sizeof(Current_Path));
        Current_Path[0] = '\\';
        Refresh_File_Manager();
        break;
    case Instruction('H', 'D'): // open home directory
        memset(Current_Path, '\0', sizeof(Current_Path));
        strlcpy(Current_Path, Users_Directory_Path, sizeof(Current_Path));
        strlcat(Current_Path, Xila.Current_Username, sizeof(Current_Path));
        Refresh_File_Manager();
        break;
    case Instruction('N', 'f'): // -- Create a new file -- //
        strcpy(Current_Item_Name, "NEWFILE .TXT");
        for (uint8_t i = 0; i <= 10; i++)
        {
            if (i < 10)
            {
                Current_Item_Name[7] = i + '0';
                if (!Xila.Drive->exists(String(Current_Path) + String("/") + String(Current_Item_Name)))
                {
                    if (!Xila.Drive->mkdir(String(Current_Path) + String("/") + String(Current_Item_Name)))
                    {
                        Event_Dialog(F("Failed to create file."), Xila.Error);
                    }
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
        strcpy(Current_Item_Name, "NEWDIRE .TXT");
        for (uint8_t i = 0; i <= 10; i++)
        {
            if (i < 10)
            {
                Current_Item_Name[7] = i + '0';
                if (!Xila.Drive->exists(String(Current_Path) + "/" + String(Current_Item_Name)))
                {
                    if (!Xila.Drive->mkdir(String(Current_Path) + "/" + String(Current_Item_Name)))
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
        break;

    case Instruction('K', 'F'): // -- Open keyboard to input current item name -- //
        if (Mode == 0)
        {
            Empty_Footer_Bar();
        }
        else if (Mode == Xila.Save_File)
        {
            Keyboard_Dialog(Current_Item_Name, sizeof(Current_Item_Name));
        }
        else
        {
            // do nothing
        }
        Refresh_File_Manager();
        break;

    default:
        break;
    }
}

// -- Shortcut methods -- //

void Shell_Class::Go_Parent()
{
    uint8_t i = strlen(Current_Path);
    Current_Path[i] = '\0'; // delete last char (if directory)
    for (; i > 0; i--)
    {
        if (Current_Path[i] == '\\')
        {
            return;
        }
        else
        {
            Current_Path[i] = '\0';
            if (i == 1)
            {
                Current_Path[0] = '\\';
                return;
            }
        }
    }
}

void Shell_Class::Fill_Footer_Bar()
{
    Xila.Display.Click(F("FOOTERBAR_HOT"), 1);
}

void Shell_Class::Empty_Footer_Bar()
{
    Xila.Display.Click(F("FOOTERBAR_HOT"), 0);
}

// -- Load -- //

void Shell_Class::Open_Load(uint8_t Mode)
{
    Xila.Display.Set_Current_Page(Load);
    switch (Mode)
    {
    case Xila.Shutting_down:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Shutdown"));
        Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Shutting down ..."));
        break;
    case Login:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Login"));
        Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Loading user data ..."));
        break;
    case Xila.Restarting:
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
    if (Xila.Current_Username[0] == '\0') // Check if logged
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

void Shell_Class::Login_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0: // IDLE
        Idle();
        break;
    case Instruction('K', 'U'):
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Login();
        break;

    case Instruction('K', 'P'):
        Keyboard_Dialog(Password_1, sizeof(Password_1), true);
        Refresh_Login();
        break;

    case Instruction('L', 'o'): // Lo : Login with entred username and password
        if (Xila.Check_Credentials(Username, Password_1) == Xila.Success)
        {
            strcpy(Xila.Current_Username, Username);

            Open_Load(Login);

            if (Load_Registry() != Xila.Success)
            {
                Event_Dialog(F("Failed to load user registry."), Xila.Error);
            }

            #if ANIMATION == 1
            Xila.Delay(4000);
            #endif

            Xila.Display.Set_Value(F("STATE_VAR"), 2);
            
            #if ANIMATION == 1
            Xila.Delay(1000);
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
        Main_Commands();
        break;
    }
}

void Shell_Class::Logout()
{
    if (Xila.Current_Username[0] != '\0')
    {
        Set_Registry(Desk_Background);
    }
    Xila.Logout();

    Open_Login();
}

// -- Preferences -- //

// -- Personnal -- //

void Shell_Class::Open_Preferences_Personal()
{
    Xila.Display.Set_Current_Page(Preferences_Personal);
    Refresh_Preferences_Personal();
}

void Shell_Class::Preferences_Personal_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('k', 'B'):
    {
        if (Desk_Background < 0)
        {
            Desk_Background = 16904;
        }
        uint16_t Temporary_Color = Desk_Background;
        Xila.Color_Picker_Dialog(Temporary_Color);
        Desk_Background = Temporary_Color;
        break;
    }
    default:
        Main_Commands();
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
}

// -- Hardware -- //

void Shell_Class::Open_Preferences_Hardware()
{
    Xila.Display.Set_Current_Page(Preferences_Hardware);
    Standby_System_Time = Xila.Standby_System_Time;
    Standby_Display_Time = Xila.Standby_Display_Time;
    Refresh_Preferences_Hardware();
}

void Shell_Class::Refresh_Preferences_Hardware()
{
    Xila.Display.Set_Value(F("VOLUME_SLI"), Xila.Sound.Get_Volume());

    Xila.Display.Set_Value(F("SSTANDBY_NUM"), Standby_System_Time);

    switch (Xila.Drive->cardType())
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

    Temporary_Variable[0] = Xila.Drive->cardSize() / (1024 * 1024);
    Xila.Display.Set_Value(F("DRIVESIZE_NUM"), Temporary_Variable[0]);
    Temporary_Variable[0] = Xila.Drive->usedBytes() / (1024 * 1024);
    Xila.Display.Set_Value(F("USEDSPACE_NUM"), Temporary_Variable[0]);
}

void Shell_Class::Preferences_Hardware_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('T', 'D'): // -- Drive testing
    {
        Temporary_Item = Xila.Drive->open(F(Test_Path), FILE_WRITE);
        if (!Temporary_Item)
        {
            Event_Dialog(F("Failed to start the write test."), Xila.Error);
            Xila.Display.Set_Current_Page(Preferences_Hardware);
            break;
        }
        static uint8_t Buffer[512];
        uint16_t i;
        double Time = millis();

        for (i = 0; i < 2048; i++)
        {
            Temporary_Item.write(Buffer, sizeof(Buffer));
        }

        Time = millis() - Time;
        Time /= 1000;               // convert time in sec
        Time = (2048 * 512) / Time; // divide quantity data copied by the time in sec
        Time = Time / 1000;

        Xila.Display.Set_Value(F("WRITESPEED_NUM"), (uint32_t)Time);
        Temporary_Item.close();

        Temporary_Item = Xila.Drive->open(F(Test_Path));
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
        Xila.Drive->remove(F(Test_Path));
        break;
    }
    case Instruction('k', 'S'): // -- Input standby system time
        Temporary_Float = Standby_Display_Time;
        Xila.Keypad_Dialog(Temporary_Float);
        Standby_Display_Time = Temporary_Float;
        Refresh_Preferences_Hardware();
        break;
    case Instruction('k', 's'):
        Temporary_Float = Standby_System_Time;
        Xila.Keypad_Dialog(Temporary_Float);
        Standby_System_Time = Temporary_Float;
        Refresh_Preferences_Hardware();
        break;
    case Instruction('D', 'C'):
        Xila.Display.Calibrate();
        break;
    case Instruction('S', 'S'):
        Xila.Sound.Set_Volume((uint8_t)Temporary_Variable[2]);
        break;
    case Instruction('S', 'a'):
        if (Xila.Set_Display_Registry(Brightness, Standby_Display_Time) != Xila.Success)
        {
            Event_Dialog(F("Failed to set display registry."), Xila.Error);
        }
        if (Xila.Set_Sound_Registry(Xila.Sound.Get_Volume()) != Xila.Success)
        {
            Event_Dialog(F("Failed to set sound registry."), Xila.Error);
        }
        // Add standby registry
        Refresh_Preferences_Hardware();
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- Network -- //

void Shell_Class::Open_Preferences_Network()
{
    Xila.Display.Set_Current_Page(Preferences_Network);
    strlcpy(WiFi_Name, WiFi.SSID().c_str(), sizeof(WiFi_Name));
    Refresh_Preferences_Network();
}

void Shell_Class::Refresh_Preferences_Network()
{
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
}

void Shell_Class::Preferences_Network_Commands()
{
    Current_Command = Get_Command();
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
    case Instruction('W', 'C'):
        if (Xila.WiFi_Connect(WiFi_Name, WiFi_Password) != Xila.Success)
        {
            Event_Dialog(F("Failed to connect to the WiFi Network."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("Successfully connected."), Xila.Information);
        }
        Refresh_Preferences_Network();
        break;
    case Instruction('W', 'A'):
        WiFi.disconnect();
        if (WiFi.softAP(Xila.Device_Name, WiFi_Password) != true)
        {
            Event_Dialog(F("Failed to enable the access point."), Xila.Error);
            Refresh_Preferences_Network();
        }
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- System -- //

void Shell_Class::Open_Preferences_System()
{
    Xila.Display.Set_Current_Page(Preferences_System);
    Autologin = false;
    memset(NTP_Server, '\0', sizeof(NTP_Server));
    strcpy(NTP_Server, Xila.NTP_Server);
    GMT_Offset = Xila.GMT_Offset;
    Daylight_Offset = Xila.Daylight_Offset;
    memset(Target_Username, '\0', sizeof(Target_Username));
    strcpy(Target_Username, Xila.Current_Username);
    memset(Password_1, '\0', sizeof(Password_1));
    memset(Username, '\0', sizeof(Username));
    memset(Device_Name, '\0', sizeof(Device_Name));
    strcpy(Device_Name, Xila.Device_Name);
    Refresh_Preferences_System();
}

void Shell_Class::Preferences_System_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('K', 'N'):
        Keyboard_Dialog(NTP_Server, sizeof(NTP_Server));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'U'):
        Keyboard_Dialog(Target_Username, sizeof(Target_Username));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'P'):
        Keyboard_Dialog(Password_1, sizeof(Password_1));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'u'):
        Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Preferences_System();
        break;
    case Instruction('K', 'D'):
        Keyboard_Dialog(Device_Name, sizeof(Device_Name));
        Refresh_Preferences_System();
        break;
    case Instruction('k', 'O'):
        Temporary_Float = GMT_Offset;
        Xila.Keypad_Dialog(Temporary_Float);
        GMT_Offset = Temporary_Float;
        Refresh_Preferences_System();
        break;
    case Instruction('C', 'U'):
        if (Xila.Change_Username(Target_Username, Username) != Xila.Success)
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
        if (Xila.Change_Password(Target_Username, Password_1) != Xila.Success)
        {
            Event_Dialog(F("Failed to change password."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("Password successfully modified."), Xila.Information);
        }
        Refresh_Preferences_System();
        break;
    case Instruction('A', 'U'):
        if (Xila.Add_User(Target_Username, Password_1))
        {
            Event_Dialog(F("Failed to add user."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("User successfully added."), Xila.Information);
        }
        Refresh_Preferences_System();
        break;
    case Instruction('D', 'U'):
        if (Xila.Check_Credentials(Username, Password_1) != Xila.Success)
        {
            Event_Dialog(F("Wrong credentials."), Xila.Error);
        }
        else
        {
            if (Event_Dialog(F("Are you sure to delete this user ?"), Xila.Question) == Xila.Button_1)
            {
                if (Xila.Delete_User(Username) != Xila.Success)
                {
                    Event_Dialog(F("Cannot delete user."), Xila.Error);
                }
                else
                {
                    Event_Dialog(F("User successfully deleted."), Xila.Error);
                }
            }
        }
        Refresh_Preferences_System();
        break;
    case Instruction('A', 'u'):
        Autologin = !Autologin;
        Refresh_Preferences_System();
        break;
    case Instruction('S', 'a'):
        Xila.Set_Time_Registry(NTP_Server, GMT_Offset, Daylight_Offset);
        Xila.Set_System_Registry(Device_Name);
        break;
    case Instruction('O', 'A'):
        Xila.Display.Set_Current_Page(About);
        break;
    case Instruction('U', 'p'):
        System_Update();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Refresh_Preferences_System()
{
    Xila.Display.Set_Text(F("NTPVAL_TXT"), NTP_Server);
    Xila.Display.Set_Value(F("GMTOFFSET_NUM"), GMT_Offset);
    Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), GMT_Offset);
    Xila.Display.Set_Text(F("TUSERVAL_TXT"), Target_Username);
    Xila.Display.Set_Text(F("DEVICEVAL_TXT"), Device_Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSWORD_TXT"), Password_1);
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

    File Temporary_File = Xila.Drive->open(Display_Executable_Path);
    if (!Temporary_File)
    {
        Refresh_Preferences_System();
        return;
    }
    if (Xila.Load_Executable(Temporary_File, 'D') != Xila.Success)
    {
        Event_Dialog(F("Failed to update"), Xila.Error);
        Refresh_Preferences_System();
        return;
    }

    Temporary_File = Xila.Drive->open(Microcontroller_Executable_Path);
    if (!Temporary_File)
    {
        Refresh_Preferences_System();
        return;
    }
    if (Xila.Load_Executable(Temporary_File, 'M') != Xila.Success)
    {
        Event_Dialog(F("Failed to update"), Xila.Error);
        Refresh_Preferences_System();
        return;
    }

    Xila.Restart();
}

// -- Shutdown -- //

void Shell_Class::Open_Shutdown()
{
    Xila.Display.Set_Current_Page(Shutdown);
}

void Shell_Class::Shutdown_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('R', 'S'): // RS : Restart system
        Xila.Restart();
        break;
    case Instruction('H', 'S'): // HS : hibernate sys
        Xila.Hibernate();
        break;
    case Instruction('L', 'S'): // LS : lock system
        Open_Login();
        break;
    case Instruction('S', 'S'): // SS : shutdown
        Xila.Display.Set_Current_Page(Load);
        Xila.Shutdown();
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- Dialogs -- //

// -- Event dialog -- //

void Shell_Class::Event_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('B', '1'):
        Xila.Dialog_State = Xila.Button_1;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    case Instruction('B', '2'):
        Xila.Dialog_State = Xila.Button_2;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    case Instruction('B', '3'):
        Xila.Dialog_State = Xila.Button_3;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    default:
        Main_Commands();
        break;
    }
}

Xila_Event Shell_Class::Event_Dialog(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
    xSemaphoreTake(Xila.Dialog_Semaphore, portMAX_DELAY);
    Xila.Feed_Watchdog();

    Xila.Display.Send_Raw(F("PAGE=dp")); // save app page id
    Xila.Display.Set_Current_Page(F("Shell_Event"));

    Xila.Dialog_State = Xila.None;

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
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Cross);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Red);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Error"));
        break;
    case Xila.Warning:
        Xila.Display.Set_Text(F("EVENT_PIC"), Xila.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Yellow);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Warning"));
        break;
    case Xila.Information:
        Xila.Display.Set_Text(F("EVENT_PIC"), Xila.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Blue);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Information"));
        break;
    case Xila.Question:
        Xila.Display.Set_Text(F("EVENT_PIC"), Xila.Question_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Green);
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Question"));
    default:
        break;
    }
    Xila.Display.Show(F("CLOSE_BUT"));

    while (Xila.Dialog_State == Xila.None)
    {
        Event_Commands();
    }

    // -- Tasks is suspended here

    Xila.Display.Set_Current_Page(F("PAGE")); //go back to app page

    xSemaphoreGive(Xila.Dialog_Semaphore);
    return Xila.Dialog_State;
}

// -- Install dialog -- //

void Shell_Class::Open_Install()
{
    Xila.Display.Set_Current_Page(F("Shell_Install"));
    Desk_Background = 16904;
    GMT_Offset = 0;
    Daylight_Offset = 0;
    memset(Device_Name, '\0', sizeof(Device_Name));
    strcpy(Device_Name, "ESP32");
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
    Xila.Display.Set_Text(F("DEVICE_TXT"), Device_Name);
    Xila.Display.Set_Text(F("USERVAL_TXT"), Username);
    Xila.Display.Set_Text(F("PASSVAL1_TXT"), Password_1);
    Xila.Display.Set_Text(F("PASSVAL2_TXT"), Password_2);
    Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi_Name);
    Xila.Display.Set_Text(F("WPASSVAL_TXT"), WiFi_Password);
}

void Shell_Class::Install_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
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
        Xila.Color_Picker_Dialog(Temporary_Color);
        Refresh_Install();
        break;
    }
    case Instruction('k', 'O'):
        Temporary_Float = GMT_Offset;
        Xila.Keypad_Dialog(Temporary_Float);
        GMT_Offset = Temporary_Float;
        Refresh_Install();
        break;
    case Instruction('k', 'o'): // --
    {
        Temporary_Float = Daylight_Offset;
        Xila.Keypad_Dialog(Temporary_Float);
        Daylight_Offset = Temporary_Float;
        Refresh_Install();
        break;
    }
    case Instruction('K', 'D'): // -- Device name keyboard input
        Keyboard_Dialog(Device_Name, sizeof(Device_Name));
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
            if (Xila.Set_Time_Registry(NULL, GMT_Offset, Daylight_Offset) != Xila.Success)
            {
                Event_Dialog(F("Cannot set the regional preferences."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
            }
            // -- User account preferences
            if (Autologin == true)
            {
                if (Xila.Set_Account_Registry(Username) != Xila.Success)
                {
                    Event_Dialog(F("Cannot set the account registry."), Xila.Error);
                    Xila.Display.Set_Current_Page(F("Shell_Install"));
                }
            }
            if (Xila.Add_User(Username, Password_1) != Xila.Success)
            {
                Event_Dialog(F("Cannot create the user account."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
                break;
            }
            Xila.Login();
        }
    }
    break;
    case Instruction('W', 'C'): // WiFi connect
        if (Xila.WiFi_Connect(WiFi_Name, WiFi_Password) != Xila.Success)
        {
            Event_Dialog(F("Failed to connect to the WiFi network."), Xila.Error);
        }
        else
        {
            Event_Dialog(F("Succed to connect to the WiFi network"), Xila.Information);
        }
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- Keyboard dialog -- //

void Shell_Class::Open_Keyboard()
{

    Xila.Display.Set_Current_Page(Keyboard);

    Xila.Display.Set_Value(F("LENGHT_VAR"), Xila.Dialog_Long[0]);
    Xila.Display.Set_Text(F("INPUT_VAR"), (char *)Xila.Dialog_Pointer);
    Xila.Display.Set_Input_Type(F("INPUT_TXT"), Xila.Dialog_Long[1]);
}

Xila_Event Shell_Class::Keyboard_Dialog(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
    xSemaphoreTake(Xila.Dialog_Semaphore, portMAX_DELAY);
    Verbose_Print_Line("Keyboard dialog");

    Xila.Feed_Watchdog();

    Xila.Display.Send_Raw(F("PAGE=dp"));

    Xila.Caller_Software_Handle_Pointer = Instance_Pointer;

    Xila.Dialog_State = Xila.None;
    Xila.Dialog_Long[0] = Char_Array_Size;
    Xila.Dialog_Pointer = Char_Array_To_Get;

    Xila.Display.Set_Current_Page(Keyboard);

    Xila.Display.Set_Global_Value(F("LENGTH"), Char_Array_Size - 1);
    Xila.Display.Set_Text(F("INPUT_VAR"), Char_Array_To_Get);
    Xila.Display.Set_Input_Type(F("INPUT_TXT"), Masked_Input);

    while (Xila.Dialog_State == Xila.None)
    {
        Keyboard_Commands();
    }

    Xila.Display.Set_Current_Page(F("PAGE"));

    xSemaphoreGive(Xila.Dialog_Semaphore);

    return Xila.Dialog_State;
}

void Shell_Class::Keyboard_Commands()
{
    if (Xila.Keyboard.available())
    {
        int Char = Xila.Keyboard.read();

        if (Char == PS2_ENTER)
        {
            Xila.Display.Click(F("b210"), 0);
        }
        else if (Char == PS2_BACKSPACE)
        {
            Xila.Display.Click(F("b200"), 0);
        }
        else if (Char == PS2_TAB)
        {
            Xila.Display.Click(F("b201"), 0);
        }
        else
        {
            if (isPrintable(Char))
            {
                char Char_Array[2];
                Char_Array[0] = (char)Char;
                Char_Array[1] = '\0';
                Xila.Display.Add_Text(F("INPUT_VAR"), Char_Array);
            }
        }
    }
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog_State = Xila.Button_1;
        if (*Xila.Caller_Software_Handle_Pointer->Handle_Pointer == Shell_Handle)
        {
        }
        else
        {
            Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        }
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- Keypad dialog -- //

void Shell_Class::Open_Keypad()
{
    Xila.Display.Set_Current_Page(Keypad);
    Xila.Display.Set_Value(F("TEMPORARY_FLO"), Xila.Dialog_Long[0]);
    Xila.Display.Click(F("CONVERT_HOT"), 0);
}

void Shell_Class::Keypad_Commands()
{
    Current_Command = Get_Command();
    if (Xila.Keyboard.available())
    {
        switch (Xila.Keyboard.read())
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
        case PS2_BACKSPACE:
            Xila.Display.Click(F("b200"), 1);
            break;
        case PS2_ENTER:
            Xila.Display.Click(F("b210"), 0);
            break;
        }
    }
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog_State = Xila.Button_1;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    default:
        Main_Commands();
        break;
    }
}

// -- Color picker dialog -- //

void Shell_Class::Open_Color_Picker()
{
    Xila.Display.Set_Current_Page(Color_Picker);

    uint8_t Temporary_Byte = *(uint32_t *)Xila.Dialog_Pointer >> 11;

    Xila.Display.Set_Value(F("RED_SLI"), Temporary_Byte);
    Temporary_Byte = *(uint32_t *)Xila.Dialog_Pointer >> 3;
    Temporary_Byte = Temporary_Byte >> 2;
    Xila.Display.Set_Value(F("GREEN_SLI"), Temporary_Byte);
    Temporary_Byte = *(uint32_t *)Xila.Dialog_Pointer << 3;
    Temporary_Byte = Temporary_Byte >> 3;
    Xila.Display.Set_Value(F("BLUE_SLI"), Temporary_Byte);
    Xila.Display.Click(F("COLOR_NUM"), 0);
}

void Shell_Class::Color_Picker_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('V', 'a'):
        Xila.Dialog_State = Xila.Button_1;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    case Instruction('C', 'a'):
        Xila.Dialog_State = Xila.Button_3;
        Xila.Maximize_Software(*Xila.Caller_Software_Handle_Pointer->Handle_Pointer);
        break;
    default:
        Main_Commands();
        break;
    }
}
