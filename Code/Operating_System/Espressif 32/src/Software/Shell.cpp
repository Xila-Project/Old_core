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

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Software_Class(6),
                             Mode(0),
                             Offset(0)
{
    Handle_Pointer = &Shell_Handle;
    xTaskCreatePinnedToCore(Main_Task, "Shell Task", 6 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Xila.Open);
}

Shell_Class::~Shell_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Shell_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Shell_Class();
    }
    return Instance_Pointer;
}

void Shell_Class::Startup()
{
    Xila.Open_Software(Shell_Handle);
    Verbose_Print_Line(F("> Open_Shell"));
}

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
        case Pages::Desk:
            Instance_Pointer->Desk_Commands();
            break;
        case Pages::Drawer:
            Instance_Pointer->Drawer_Commands();
            break;
        case Pages::Event:
            Instance_Pointer->Current_Command = Instance_Pointer->Get_Command();
            Instance_Pointer->Main_Commands();
            break;
        case Pages::Keypad:
            Instance_Pointer->Keypad_Commands();
            break;
        case Pages::Keyboard:
            Instance_Pointer->Keyboard_Commands();
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
        case Pages::Login:
            Instance_Pointer->Login_Commands();
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
            break;
        }
        Xila.Delay(5);
    }
}

/////////////////////////////////////////////////////////////////////

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Xila.Display.Get_Current_Page())
    {
    case Install:
        switch (Adress)
        {
        case 'O':
            Temporary_Variable[0] = *(uint32_t *)Variable;
            break;
        case 'o':
            Temporary_Variable[1] = *(uint32_t *)Variable;
            break;
        case 'A': // Autologin
            Temporary_Variable[2] = *(uint8_t *)Variable;
            break;
        case 'D':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[25];
            strlcpy(Temporary_Char_Array[0], (char *)Variable, 25);
            break;
        case 'U':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[9];
            strlcpy(Temporary_Char_Array[1], (char *)Variable, 9);
            break;
        case 'P':
            if (Temporary_Char_Array[2] != NULL)
            {
                delete[] Temporary_Char_Array[2];
            }
            Temporary_Char_Array[2] = new char[25];
            strlcpy(Temporary_Char_Array[2], (char *)Variable, 25);
            break;
        case 's':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[33];
            strlcpy(Temporary_Char_Array[0], (char *)Variable, 33);
            break;
        case 'p':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[81];
            strlcpy(Temporary_Char_Array[1], (char *)Variable, 81);
            break;
        default:
            break;
        }
        break;
    case Preferences_Personal:
        switch (Adress)
        {
        case 'B':
            Desk_Background = *(uint32_t *)Variable;
            break;
        default:
            break;
        }
        break;
    case Preferences_Hardware:
        switch (Adress)
        {
        case 'B':
            Temporary_Variable[0] = *(uint8_t *)Variable;
            break;
        case 'V':
            Temporary_Variable[1] = *(uint8_t *)Variable;
            break;
        case 's':
            Temporary_Variable[2] = *(uint16_t *)Variable;
            break;
        case 'S':
            Temporary_Variable[3] = *(uint8_t *)Variable;
            break;
        default:
            break;
        }
        break;
    case Preferences_System:
        switch (Adress)
        {
        case 'U': // target user
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[9];
            strlcpy(Temporary_Char_Array[0], (char *)Variable, 9);
            break;
        case 'p': // password modificated
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[25];
            strlcpy(Temporary_Char_Array[1], (char *)Variable, 25);
            break;
        case 'u': // user modificated
            if (Temporary_Char_Array[2] != NULL)
            {
                delete[] Temporary_Char_Array[2];
            }
            Temporary_Char_Array[2] = new char[9];
            strlcpy(Temporary_Char_Array[2], (char *)Variable, 9);
            break;
        case 'N': // NTP server
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[33];
            strlcpy(Temporary_Char_Array[0], (char *)Variable, 33);
            break;
        case 'D': // Device name
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[25];
            strlcpy(Temporary_Char_Array[1], (char *)Variable, 25);
            break;
        case 'O': // GMT offset
            Temporary_Variable[0] = *(uint32_t *)Variable;
            break;
        case 'o': // Daylight offset
            Temporary_Variable[1] = *(uint32_t *)Variable;
            break;
        default:
            break;
        }
        break;
    case Preferences_Network:
        switch (Adress)
        {
        case 'N':
            if (Temporary_Char_Array[0] != NULL)
            {
                delete[] Temporary_Char_Array[0];
            }
            Temporary_Char_Array[0] = new char[33];
            strlcpy(Temporary_Char_Array[0], (char *)Variable, 33);
            break;
        case 'P':
            if (Temporary_Char_Array[1] != NULL)
            {
                delete[] Temporary_Char_Array[1];
            }
            Temporary_Char_Array[1] = new char[81];
            strlcpy(Temporary_Char_Array[1], (char *)Variable, 81);
            break;
        default:
            break;
        }
        break;
    case File_Manager:
        switch (Adress)
        {

        case 'P':
            strlcpy(Current_Path, (char *)Variable, sizeof(Current_Path));
            break;
        case 'F':
            strlcpy(Current_File_Name, (char *)Variable, sizeof(Current_File_Name));
            break;
        default:
            break;
        }
    case Keyboard:
        switch (Adress)
        {
        case 'I':
            if (Xila.Dialog_Pointer != NULL)
            {
                strlcpy(Xila.Dialog_Pointer, (char *)Variable, Xila.Dialog_Long);
            }
            break;
        }
    case Keypad:
        if (Adress == 'I')
        {
            memcpy(Xila.Dialog_Long, (float *)Variable, sizeof(uint32_t));
        }
        break;
    default:
        break;
    }
}

void Shell_Class::Open_Keypad()
{
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Display.Set_Current_Page(F("Shell_Keypad"));
    Xila.Display.Set_Value(F("TEMPORARY_FLO"), Xila.Dialog_Long);
    Xila.Display.Click(F("CONVERT_HOT"), 0);
}

void Shell_Class::Open_Keyboard()
{
    Xila.Display.Send_Raw(F("PAGE=dp")); // save page id
    Xila.Display.Set_Current_Page(F("Shell_Keyboard"));

    Xila.Display.Set_Value(F("LENGHT_VAR"), Xila.Dialog_Long);
    Xila.Display.Set_Text(F("INPUT_VAR"), (char *)Xila.Dialog_Pointer);
    Xila.Display.Set_Input_Type(F("INPUT_TXT"), Xila.Dialog_Byte);
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
    case Instruction('E', 'k'):
        Xila.Display.Set_Current_Page(F("PAGE"));
        Xila.Dialog_State = Xila.Success;
        Xila.Shell_Minimize();
        break;
    default:
        Main_Commands();
        break;
    }
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
                Xila.Display.Add_Text(F("INPUT_VAR"), &Char);
            }
        }
    }
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('E', 'K'):
        Xila.Display.Set_Current_Page(F("PAGE"));
        Xila.Dialog_State = Xila.Success;
        Xila.Shell_Minimize();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Install_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('I', 'P'):
        Xila.Event_Dialog(F("Entered passwords does not match."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Shell_Install"));
        break;
    case Instruction('Q', 'u'):
        if (Xila.Event_Dialog(F("Are you sure of the information entered ?"), Xila.Question) != Xila.Button_1)
        {
            return;
        }
        Xila.Display.Set_Current_Page(F("Shell_Install"));
        break;
    case Instruction('C', 'o'):
    {
        if (Xila.Event_Dialog(F("Are you sure of the information entered ?"), Xila.Question) != Xila.Button_1)
        {
            // Regional preferences
            if (Xila.Set_Regionnal_Registry(NULL, Temporary_Variable[0], Temporary_Variable[1]) != Xila.Success)
            {
                Xila.Event_Dialog(F("Cannot set the regional preferences."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
            }
            // User account preferences
            if (Temporary_Variable[2] != 0)
            {
                if (Xila.Set_Account_Registry(Temporary_Char_Array[1]) != Xila.Success)
                {
                    Xila.Event_Dialog(F("Cannot set the account registry."), Xila.Error);
                    Xila.Display.Set_Current_Page(F("Shell_Install"));
                }
            }
            if (Xila.Add_User(Temporary_Char_Array[1], Temporary_Char_Array[2]) != Xila.Success)
            {
                Xila.Event_Dialog(F("Cannot create the user account."), Xila.Error);
                Xila.Display.Set_Current_Page(F("Shell_Install"));
                break;
            }
            delete[] Temporary_Char_Array[0];
            delete[] Temporary_Char_Array[1];
            delete[] Temporary_Char_Array[2];
            Temporary_Char_Array[0] = NULL;
            Temporary_Char_Array[1] = NULL;
            Temporary_Char_Array[2] = NULL;
            Xila.Login();
        }
    }
    break;
    case Instruction('W', 'C'): // WiFi connect
        if (Xila.WiFi_Connect(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to connect to the WiFi network."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Install"));
        }
        else
        {
            Xila.Event_Dialog(F("Succed to connect to the WiFi Network"), Xila.Information);
            Xila.Display.Set_Current_Page(F("Shell_Install"));
        }
        break;
    default:
        break;
    }
}

void Shell_Class::Desk_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0: // IDLE
        Idle();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::File_Manager_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('R', 'e'): // refresh file manager
        Refresh_File_Manager();
        break;
    case Instruction('C', 'l'):
        Empty_Footer_Bar();
        if (Mode > 4)
        {
        }

        Xila.Close_Software();

        break;
    case Instruction('C', 'o'): // copy file
        if (Operation == Copy)  //paste
        {
            if (Selected_Item.isDirectory())
            {
                Xila.Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Copy_File(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Xila.Event_Dialog(F("Failed to copy file."), Xila.Error);
                }
            }
            Selected_Item.close();
            Xila.Display.Set_Picture(F("COPY_BUT"), Copy_24)
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
                Xila.Event_Dialog(F("Cannot copy folder."), Xila.Error);
            }
            else
            {
                if (Xila.Copy_File(Selected_Item, Temporary_Item) != Xila.Success)
                {
                    Xila.Event_Dialog(F("Failed to copy file."), Xila.Error);
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
        case Default:

            break;
        case Open_File:

            break;

        case Open_Folder:

            break;
        case Save_File:

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
    case Instruction('N', 'f'): //new file
        strcpy(Current_Item_Name, "NEWFILE .TXT");
        for (uint8_t i = 0; i <= 10; i++)
        {
            if (i < 10)
            {
                Current_Item_Name[7] = i + '0';
                if (!Xila.Drive->exist(String(Current_Path) + String("/") + String(Current_Item_Name)))
                {
                    if (!Xila.Drive->mkdir(String(Current_Path) + String("/") + String(Current_Item_Name)))
                    {
                        Xila.Event_Dialog(F("Failed to create file."), Xila.Error);
                    }
                    break;
                }
            }
            else
            {
                Xila.Event_Dialog(F("Failed to create file."), Xila.Error);
                break;
            }
        }
        Refresh_File_Manager();
        break;
    case Instruction('N', 'F'):
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
                        Xila.Event_Dialog(F("Failed to create folder."), Xila.Error);
                    }
                    break;
                }
            }
            else
            {
                Xila.Event_Dialog(F("Failed to create folder."), Xila.Error);
                break;
            }
        }
        Refresh_File_Manager();
        break;
    case Instruction('K', 'P'):
        Xila.Keyboard_Dialog(Current_Path, sizeof(Current_Path));
        Refresh_File_Manager();
        break;

    case Instruction('K', 'F'):
        if (Mode == Default)
        {
            Empty_Footer_Bar();
        }
        else if (Mode == Save_File)
        {
            Xila.Keyboard_Dialog(Current_Item_Name, sizeof(Current_Item_Name));
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
            if (Xila.Event_Dialog(F("Are you sure to delete this item."), Xila.Question) == Xila.Button_1)
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
            Xila.Keyboard_Dialog(Temporary_Input, sizeof(Temporary_Input));
            Xila.Drive->rename(String(Current_Path) + String(Temporary_Item.name()), String(Current_Path) + String(Temporary_Input));
            Operation = Browse;
            Empty_Footer_Bar();
            break;
        default:
            if (Temporary_Item.isDirectory())
            {
                if (Mode == Xila.Open_Folder)
                {
                    strlcpy(Current_Item_Name, Temporary_Item.name(), sizeof(Current_Item_Name));
                    Xila.Set_Text(F("FILENAME_TXT"), Current_Item_Name);
                }

                Temporary_Item.rewindDirectory();

                for (uint8_t i = 0; i < Offset; i++) // apply offset
                {
                    Temporary_Item.openNextFile().close();
                }

                char Temporary_Item_Name[13] = "ITEM _TXT";
                strcpy(Current_Item_Name, "ITEM _PIC");

                for (uint8_t i = 1; i <= 30; i++)
                {
                    Item = Temporary_Item.openNextFile();
                    if (i == 1)
                    {
                        if (!Item) // if no 1st file, reset the offset
                        {
                            Offset = 0;
                            Item.close();
                            Temporary_Item.rewindDirectory();
                            Item = Temporary_Item.openNextFile();
                        }
                    }

                    Current_Item_Name[4] = i + '0';
                    Temporary_Item_Name[4] = i + '0';

                    if (Item)
                    {
                        Xila.Display.Set_Text(Temporary_Item_Name, Item.name());
                        if (Item.isDirectory())
                        {
                            Xila.Display.Set_Picture(Current_Item_Name, Folder_16);
                        }
                        else
                        {
                            Xila.Display.Set_Picture(Current_Item_Name, File_16);
                        }
                    }
                    else
                    {
                        Xila.Display.Set_Text(Temporary_Item_Name, "");
                        Xila.Display.Set_Picture(Current_Item_Name, Empty_32);
                    }

                    Item.close();
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
                    case Default:

                        break;
                    case Open_File:

                        break;

                    case Open_Folder:
                        Go_Parent();
                        Execute('R', 'e');
                        break;
                    default:
                        Open_File();
                        break;
                    }
                    break;
                }
                Temporary_Item.close();
                Go_Parent();
            }
        }
    }
    else
    {
        Xila.Event_Dialog(F("Failed to open path."), Xila.Error);
        Execute('R', 'D');
    }
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
        Xila.Keyboard_Dialog(Username, sizeof(Username));
        Refresh_Login();
        break;

    case Instruction('K', 'P'):
        Xila.Keyboard_Dialog(Password, sizeof(Password), true);
        Refresh_Login();

        break;

    case Instruction('L', 'o'): // Lo : Login with entred username and password
        Instance_Pointer->Login();
        break;
    default:
        Main_Commands();
        break;
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
        if (Offset > 241)
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
            if (Xila.Software_Handle_Pointer[Offset + 15] != NULL)
            {
                Offset += 15;
                Refresh_Drawer();
            }
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
    case 0x6436: // dx : Open software from drawer
        Open_From_Drawer(6);
        break;
    case 0x6437: // dx : Open software from drawer
        Open_From_Drawer(7);
        break;
    case 0x6438: // dx : Open software from drawer
        Open_From_Drawer(8);
        break;
    case 0x6439: // dx : Open software from drawer
        Open_From_Drawer(9);
        break;
    case 0x6441: // dx : Open software from drawer
        Open_From_Drawer(10);
        break;
    case 0x6442: // dx : Open software from drawer
        Open_From_Drawer(11);
        break;
    case 0x6443: // dx : Open software from drawer
        Open_From_Drawer(12);
        break;
    case 0x6444: // dx : Open software from drawer
        Open_From_Drawer(13);
        break;
    case 0x6445: // dx : Open software from drawer
        Open_From_Drawer(14);
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_System_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('C', 'U'):
        if (Xila.Change_Username(Temporary_Char_Array[0], Temporary_Char_Array[2]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to change username."), Xila.Error);
        }
        else
        {
            Xila.Event_Dialog(F("Username successfully modified."), Xila.Information);
        }
        Open_Preferences('S');
        break;
    case Instruction('C', 'P'):
        if (Xila.Change_Password(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to change password."), Xila.Error);
        }
        else
        {
            Xila.Event_Dialog(F("Password successfully modified."), Xila.Information);
        }
        Open_Preferences('S');
        break;
    case Instruction('A', 'U'):
        if (Xila.Add_User(Temporary_Char_Array[0], Temporary_Char_Array[1]))
        {
            Xila.Event_Dialog(F("Failed to add user."), Xila.Error);
        }
        else
        {
            Xila.Event_Dialog(F("User successfully added."), Xila.Information);
        }
        Open_Preferences('S');
        break;
    case Instruction('D', 'U'):
        if (Xila.Check_Credentials(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Wrong credentials."), Xila.Error);
        }
        else
        {
            if (Xila.Event_Dialog(F("Are you sure to delete this user ?"), Xila.Question) == Xila.Button_1)
            {
                if (Xila.Delete_User(Temporary_Char_Array[0]) != Xila.Success)
                {
                    Xila.Event_Dialog(F("Cannot delete user."), Xila.Error);
                }
                else
                {
                    Xila.Event_Dialog(F("User successfully deleted."), Xila.Error);
                }
            }
        }
        Open_Preferences('S');
        break;
    case Instruction('O', 'A'):
        Xila.Display.Set_Current_Page(F("Shell_About"));
        break;
    case Instruction('U', 'p'):
        System_Update();
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::System_Update()
{
    if (Xila.Event_Dialog(F("Do you really want to update Xila ? That will make the system restart."), Xila.Warning) != Xila.Button_1)
    {
        return;
    }

    Xila.Display.Set_Current_Page(F("Shell_Load"));
    Xila.Display.Set_Text(F("MESSAGE_TXT"), F("Updating firmware"));
    Xila.Display.Set_Text(F("LOAD_TXT"), F("Update"));
    Xila.Display.Refresh(F("CLOSE_BUT"));

    File Temporary_File = Xila.Drive->open(Display_Executable_Path);
    if (!Temporary_File)
    {
        Open_Preferences('S');
        Xila.Event_Dialog(F("Failed to update : no update file."), Xila.Error);
        return;
    }
    if (Xila.Load_Executable(Temporary_File, 'D') != Xila.Success)
    {
        Open_Preferences('S');
        Xila.Event_Dialog(F("Failed to update"), Xila.Error);
        return;
    }

    Temporary_File = Xila.Drive->open(Microcontroller_Executable_Path);
    if (!Temporary_File)
    {
        Open_Preferences('S');
        Xila.Event_Dialog(F("Failed to update"), Xila.Error);
        return;
    }
    if (Xila.Load_Executable(Temporary_File, 'M') != Xila.Success)
    {
        Open_Preferences('S');
        Xila.Event_Dialog(F("Failed to update"), Xila.Error);
        return;
    }

    Xila.Restart();
}

void Shell_Class::Preferences_Network_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('W', 'C'):
        if (Xila.WiFi_Connect(Temporary_Char_Array[0], Temporary_Char_Array[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to connect to the WiFi Network."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Network"));
        }
        delete[] Temporary_Char_Array[0];
        delete[] Temporary_Char_Array[1];
        Temporary_Char_Array[0] = NULL;
        Temporary_Char_Array[1] = NULL;
        break;
    case Instruction('W', 'A'):
        WiFi.disconnect();
        WiFi.softAP(Xila.Device_Name, Temporary_Char_Array[1]);
        delete[] Temporary_Char_Array[0];
        delete[] Temporary_Char_Array[1];
        Temporary_Char_Array[0] = NULL;
        Temporary_Char_Array[1] = NULL;
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Preferences_Hardware_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case Instruction('T', 'D'):
        Temporary_Item = Xila.Drive->open(F(Test_Path), FILE_WRITE);
        if (!Temporary_Item)
        {
            Xila.Event_Dialog(F("Failed to start the write test."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Hardware"));
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
            Xila.Event_Dialog(F("Failed to start the read test."), Xila.Error);
            Xila.Display.Set_Current_Page(F("Shell_Hardware"));
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
    case Instruction('D', 'C'):
        Xila.Display.Calibrate();
        break;
    case Instruction('S', 'S'):
        Xila.Sound.Set_Volume((uint8_t)Temporary_Variable[2]);
        break;
    case Instruction('S', 'H'):
        if (Xila.Set_Display_Registry((uint8_t)Temporary_Variable[0], (uint16_t)Temporary_Variable[1]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to set display registry."), Xila.Error);
        }
        if (Xila.Set_Sound_Registry((uint8_t)Temporary_Variable[2]) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to set sound registry."), Xila.Error);
        }
        if (Xila.Set_Display_Registry(Temporary_Variable[3], 0xFF, 0xFF) != Xila.Success)
        {
            Xila.Event_Dialog(F("Failed to set display registry."), Xila.Error);
        }
        Xila.Display.Set_Brightness((uint8_t)Temporary_Variable[0]);
        Xila.Sound.Set_Volume((uint8_t)Temporary_Variable[1]);
        Xila.Display_Standby_Time = (uint16_t)Temporary_Variable[2];
        Xila.System_Standby_Time = Temporary_Variable[3];
        break;
    default:
        Main_Commands();
        break;
    }
}

Xila_Event Shell_Class::Load_Registry()
{
    File Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.XRF", FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Temporary_Variable) != DeserializationError::Ok)
        ;
    {
        return Xila.Error;
    }
    Desk_Background = Shell_Registry["Desk Background"] | -1;
    Temporary_Item.close();
    return Xila.Success;
}

Xila_Event Shell_Class::Set_Registry(uint32_t Desk_Background)
{
    File Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.XRF", FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Temporary_Variable);
    Shell_Registry["Desk Background"] = Desk_Background;
    if (serializeJson(Shell_Registry, Temporary_Variable) == 0)
    {
        return Xila.Error;
    }
    Temporary_Item.close();
    this->Desk_Background = Desk_Background;
    return Xila.Success;
}

void Shell_Class::Preferences_Personal_Commands()
{
    Current_Command = Get_Command();
    switch (Current_Command)
    {
    case 0:
        Idle();
        break;
    case Instruction('S', 'P'):
    {
        DynamicJsonDocument Shell_Registry(256);
        Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username), FILE_WRITE);
        if (deserializeJson(Shell_Registry, Temporary_Item) != DeserializationError::Ok)
        {
            Xila.Event_Dialog(F("Cannot set the user shell registry."), Xila.Error);
            Open_Preferences('P');
        }
        else
        {
            Shell_Registry["Color"] = (uint16_t)Temporary_Variable[0];
        }
    }
    break;
    default:
        Main_Commands();
        break;
    }
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

        break;
    case Instruction('L', 'S'): // LS : lock system
        break;

    case Instruction('S', 'S'): // SS : shutdown
        Xila.Display.Set_Current_Page(F("LOAD_TXT"));
        Xila.Shutdown();
        break;
    default:
        Main_Commands();
        break;
    }
}

void Shell_Class::Main_Commands()
{
    switch (Current_Command)
    {
    case Instruction('O', 'k'): // open numeric keypad
        Open_Keypad();
        break;
    case Instruction('L', 'R'):
        Load_Registry();
        break;
    case Instruction('O', 's'): // Os : Shutdown menu
        Xila.Display.Set_Current_Page(F("Shell_Shutdown"));
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
        Xila.Display.Set_Current_Page(F("Shell_About"));
        break;
    case Xila.Keyboard:
        Open_Keyboard();
        break;
    case Xila.Installation_Wizard:
        Xila.Display.Set_Current_Page(F("Shell_Install"));
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
    case Instruction('O', 'F'): // "OF" : Open file manager
        Mode = 0;
        Open_File_Manager();
        break;

    case Instruction('O', 'P'): // "OP" : Open preferiencies (default : personnal)
        Instance_Pointer->Open_Preferences('P');
        break;
    case Instruction('O', 'H'): // "OH" : Open hardware prefencies
        Instance_Pointer->Open_Preferences('H');
        break;
    case Instruction('O', 'N'): // "ON" : Open network
        Instance_Pointer->Open_Preferences('N');
        break;
    case Instruction('O', 'S'): // "OS" : Open system preferencies
        Instance_Pointer->Open_Preferences('S');
        break;
    case Xila.Open: // open routine
        Execute(Xila.Maximize);
        break;
    case Xila.Close: // close
        Open_Load(Shutdown);
        delete Instance_Pointer;
        vTaskDelete(NULL);
        break;
    case Xila.Minimize: // minimize
        vTaskSuspend(NULL);
        break;
    case Xila.Maximize:
        if (Xila.Power_Button_Counter == 1)
        {
            Instance_Pointer->Execute(0x534D);
        }
        Instance_Pointer->Open_Desk();
        break;
    }
}

void Shell_Class::Open_Load(uint8_t Mode)
{
    Xila.Display.Set_Current_Page(F("Shell_Load"));
    switch (Mode)
    {
    case Shutdown:
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Shutdown"));
        Xila.Display.Set_Text(F("LOAD_TXT"), F("Shutting down ..."));
        break;
    case Login:
        break;
    default:
        break;
    }
}

void Shell_Class::Idle()
{
    Xila.Delay(20);
}

void Shell_Class::Open_From_Drawer(uint8_t Slot)
{
    if ((Slot + Offset) < (sizeof(Software_Handle_Pointer) / sizeof(Software_Handle *)))
    {
        if (Xila.Software_Handle_Pointer[Slot + Offset] != NULL)
        {
            Xila.Open_Software(Xila.Software_Handle_Pointer[Slot + Offset]);
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

void Shell_Class::Dock(uint8_t Slot, uint8_t Action)
{
    if (Action == 'M') // maximize
    {
        Xila.Maximize_Software(Slot + 1);
    }
    else if (Action == 'C')
    {
        Xila.Close_Software(Xila.Open_Software_Pointer[Slot + 1]->Handle_Pointer);
    }
}

void Shell_Class::Open_Preferences(char const &Section)
{
    switch (Section)
    {
    case 'P':
        Xila.Display.Set_Current_Page(F("Shell_Personal"));
        if (Desk_Background == -1)
        {
            Xila.Display.Click(F("DEFAULTB_RAD"), 0);
        }
        else
        {
            Xila.Display.Click(F("COLORB_RAD"), 0);
            Xila.Display.Set_Value(F("COLORB_NUM"), Desk_Background);
        }
        break;
    case 'H':
        Xila.Display.Set_Current_Page(F("Shell_Hardware"));
        Xila.Display.Set_Value(F("VOLUME_SLI"), Xila.Sound.Get_Volume());
        Xila.Display.Set_Value(F("DSTANDBY_NUM"), Xila.Display_Standby_Time);
        Xila.Display.Set_Value(F("SSTANDBY_NUM"), Xila.System_Standby_Time);
        switch (Xila.Drive->cardType())
        {
        case CARD_NONE:
            Xila.Display.Set_Value(F("DRIVETYPE_TXT"), F("Drive type : None"));
            break;
        case CARD_SD:
            Xila.Display.Set_Value(F("DRIVETYPE_TXT"), F("Drive type : SDSC"));
            break;
        case CARD_SDHC:
            Xila.Display.Set_Value(F("DRIVETYPE_TXT"), F("Drive type : SDHC"));
            break;
        case CARD_MMC:
            Xila.Display.Set_Value(F("DRIVETYPE_TXT"), F("Drive type : MMC"));
            break;
        case CARD_UNKNOWN:
            Xila.Display.Set_Value(F("DRIVETYPE_TXT"), F("Drive type : Unknow"));
            break;
        }

        Temporary_Variable[0] = Xila.Drive->cardSize() / (1024 * 1024);
        Xila.Display.Set_Value(F("DRIVESIZE_NUM"), Temporary_Variable[0]);
        Temporary_Variable[0] = Xila.Drive->usedBytes() / (1024 * 1024);
        Xila.Display.Set_Value(F("USEDSPACE_NUM"), Temporary_Variable[0]);

        break;
    case 'N':
        Xila.Display.Set_Current_Page(F("Shell_Network"));
        Xila.Display.Set_Text(F("WNAMEVAL_TXT"), WiFi.SSID());
        break;
    case 'S':
        Xila.Display.Set_Current_Page(F("Shell_System"));
        Xila.Display.Set_Text(F("NTPVAL_TXT"), Xila.NTP_Server);
        Xila.Display.Set_Value(F("GMTOFFSET_NUM"), Xila.GMT_Offset);
        Xila.Display.Set_Value(F("DAYLIGHTO_NUM"), Xila.GMT_Offset);
        Xila.Display.Set_Text(F("TUSERVAL_TXT"), Xila.Current_Username);
        Xila.Display.Set_Text(F("DEVICEVAL_TXT"), Xila.Device_Name);
        break;
    default:
        break;
    }
}

void Shell_Class::Logout()
{
    if (Xila.Logout() == Xila.Success)
    {
    }
    Open_Login();
}

void Shell_Class::Open_Desk()
{
    Verbose_Print_Line("> Open desk");
    if (Xila.Current_Username[0] == '\0')
    {
        Open_Login();
        return;
    }
    Xila.Display.Set_Current_Page(F("Shell_Desk"));

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
    Xila.Display.Hide(F("MAXIMIZE_BUT"));
    Xila.Display.Hide(F("CLOSE_BUT"));

    char Temporary_String[] = "SLOT _PIC";

    // List all files on the desk
    /*Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/DESKTOP/");
    Temporary_Item.rewindDirectory();
    Temporary_Item.openNextFile();*/

    // List all running app on the task bar
    for (uint8_t Slot = 2; Slot < 8; Slot++)
    {
        Temporary_String[4] = Slot + 47;
        if (Xila.Open_Software_Pointer[Slot] != NULL)
        {
            Xila.Display.Set_Picture(Temporary_String, Xila.Open_Software_Pointer[Slot]->Handle_Pointer->Icon);
        }
        else
        {
            Xila.Display.Set_Picture(Temporary_String, Empty_32); //if there's
        }
    }
}

void Shell_Class::Open_Drawer()
{
    Xila.Display.Set_Current_Page(F("Shell_Drawer"));
    Offset = 0;
    Refresh_Drawer();
}

void Shell_Class::Refresh_Drawer()
{
    // Item name drawing
    char Temporary_String[11] = "ITEM _TXT";
    for (uint i = 0; i < 15; i++)
    {
        if (i < 10)
        {
            Temporary_String[4] = i + 48;
        }
        else
        {
            if (i == 10)
            {
                strlcpy(Temporary_String, "ITEM  _TXT", sizeof(Temporary_String));
            }
            Temporary_String[4] = 1 + 48;
            Temporary_String[5] = (i - 10) + 48;
        }

        if (Xila.Software_Handle_Pointer[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software_Handle_Pointer[i + Offset]->Name));
        }
        else
        {
            Xila.Display.Set_Text(Temporary_String, "");
        }
    }

    // Item picture drawing
    strlcpy(Temporary_String, "ITEM _PIC", sizeof(Temporary_String));
    for (uint i = 0; i < 15; i++)
    {
        if (i < 10)
        {
            Temporary_String[4] = i + 48;
        }
        else
        {
            if (i == 10)
            {
                strlcpy(Temporary_String, "ITEM  _TXT", sizeof(Temporary_String));
            }
            Temporary_String[4] = 1 + 48;
            Temporary_String[5] = (i - 10) + 48;
        }

        if (Xila.Software_Handle_Pointer[i + Offset] != NULL)
        {
            Xila.Display.Set_Text(Temporary_String, Xila.Software_Handle_Pointer[i + Offset]->Name));
        }
        else
        {
            Xila.Display.Set_Text(Temporary_String, "");
        }
    }
}

// File manager

void Shell_Class::Open_File_Manager()
{
    Xila.Display.Set_Current_Page(F("Shell_File"));
    Offset = 0;
    memset(Current_Path, '/0', sizeof(Current_Path));
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
    Display_Path();
}

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
            if (i = 1)
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

void Shell_Class::Make_Directory(char *Item_Name)
{
    if (!Xila.Drive->exists(Current_Path + Item_Name))
    {
        Xila.Drive->mkdir(Current_Path + Item_Name);
    }
}

// Login

void Shell_Class::Open_Login()
{
    if (Xila.Current_Username[0] == '\0') // Check if logged
    {
        Verbose_Print_Line("> Open login page");
        Xila.Display.Set_Current_Page(F("Shell_Login"));
        strcpy(Username, "Username");
        strcpy(Password, "Password");
    }
    else
    {
        Open_Desk();
    }
}

void Shell_Class::Refresh_Login()
{
    Xila.Display.Set_Text(F("USERNAME_TXT"), Username);
    Xila.Display.Set_Text(F("PASSWORD_TXT"), Password);
}

void Shell_Class::Login()
{

    if (Xila.Check_Credentials(Username, Password) == Xila.Success)
    {
        strcpy(Xila.Current_Username, Username);
        Verbose_Print_Line(F("> Load user files"));
        Xila.Display.Set_Current_Page(F("Shell_Load"));
        Xila.Display.Set_Text(F("HEADER_TXT"), F("Login"));
        Xila.Display.Refresh(F("CLOSE_BUT"));
        Xila.Display.Set_Text(F("LOAD_TXT"), F("Loading user data ..."));

        DynamicJsonDocument Shell_Registry(256);
        File Temporary_Item = Xila.Drive->open("/USERS/" + String(Xila.Current_Username) + "/REGISTRY/SHELL.GRF");
        deserializeJson(Shell_Registry, Temporary_Item);
        /*
                char Temporary_Char_Array[20];
        strcpy(Temporary_Char_Array, Shell_Registry["Registry"]);
        if (strcmp(Temporary_Char_Array, "Shell"))
        {
            //Color = Shell_Registry["Color"] | 16904;
        }
        */
        if (strcmp(Shell_Registry["Registry"], "Shell") == 0)
        {
            Verbose_Print_Line("Simple comp work !!!!");
            //Color = Shell_Registry["Color"] | 16904;
        }

        Xila.Display.Set_Value(F("STATE_VAR"), 2);
        Xila.Delay(1000);
        Open_Desk();
    }
    else // Wrong credentials
    {
        Xila.Event_Dialog(F("Wrong credentials !"), Xila.Error);
        Open_Login();
    }
}
