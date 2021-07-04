///
/// @file Shell.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila main user interface source file.
/// @version 0.1.0
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

Software_Handle_Class Shell_Handle("Shell", Shell_Class::Images.Empty_32, Shell_Class::Load_Shell, Shell_Class::Startup);

// -- Initialize shell -- //

Shell_Class *Shell_Class::Instance_Pointer = NULL;

Shell_Class::Shell_Class() : Software_Class(Shell_Handle)
{

    Xila.Task.Create(Main_Task, "Shell Task", Memory_Chunk(8), NULL, &Task_Handle);
}

Shell_Class::~Shell_Class()
{
    // -- Unload all modules -- //
    Dialog_Class::Close();
    File_Manager_Class::Close();
    Preferences_Class::Close();
    // -- Check if there's a duplicate
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Shell_Class::Load_Shell()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Shell_Class();
    return Instance_Pointer;
}

void Shell_Class::Startup()
{
    Xila.Software.Open(Shell_Handle);
}

// -- Main shell methods -- //

void Shell_Class::Main_Task(void *)
{
    while (1)
    {
        switch (Xila.Display.Get_Current_Page())
        {
        case Pages.About:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_System_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Color_Picker:
            if (Preferences_Class::State())
            {
                DIALOG->Execute_Color_Picker_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Desk:
            DESK.Execute_Desk_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Drawer:
            DESK.Execute_Drawer_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Dialog_Event:
            if (Dialog_Class::State())
            {
                DIALOG->Execute_Event_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.File_Manager_Main:
        case Pages.File_Manager_Detail:
            if (File_Manager_Class::State())
            {
                FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Hardware:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Hardware_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Install:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Install_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Keyboard:
            if (Dialog_Class::State())
            {
                DIALOG->Execute_Keyboard_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Dialog_Keypad:
            if (Dialog_Class::State())
            {
                DIALOG->Execute_Keypad_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Login:
            DESK.Execute_Login_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Dialog_Load:
            SHELL->Execute_Instruction(SHELL->Get_Instruction());
            break;
        case Pages.Preferences_Network:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Network_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_Personal:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_Personal_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Shutdown:
            if (Dialog_Class::State())
            {
                DIALOG->Execute_Shutdown_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Preferences_System:
            if (Preferences_Class::State())
            {
                PREFERENCES->Execute_System_Instruction(SHELL->Get_Instruction());
            }
            else
            {
                SHELL->Execute_Instruction(SHELL->Get_Instruction());
            }
            break;
        case Pages.Welcome:
            DESK.Execute_Desk_Instruction(SHELL->Get_Instruction());
            break;
        default:
            Xila.Task.Delay(50);
            SHELL->Execute_Instruction(SHELL->Get_Instruction());
            break;
        }
    }
}

void Shell_Class::Execute_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Idle:
        if (Xila.Software.Get_State(Shell_Handle) == Minimized)
        {
            Xila.Task.Delay(90);
        }
        else
        {
            while (Xila.Keyboard.Available())
            {
                switch (Xila.Keyboard.Read())
                {
                case Xila.Keyboard.Escape:
                    Xila.Display.Click("CLOSE_BUT", 0);
                    break;

                default:
                    break;
                }
            }
        }
        Xila.Task.Delay(10);
        break;
    case Dialog_Color_Picker:
        DIALOG->Open(Pages.Dialog_Color_Picker);
        break;
    case Instruction('O', 's'):
    case Dialog_Power:
        DIALOG->Open(Dialog_Power);
        break;
    case Instruction('O', 'L'): // "OL" : Open Login page
        Desk.Open(Pages.Login);
        break;
    case Open:
        if (!Xila.Drive.Exists(Users_Directory_Path))
        {
            Xila.Display.Set_Current_Page(Pages.Welcome);
            return;
        }

        if (Xila.Account.Get_State() == Xila.Account.Logged)
        {
            Load_Registry();
        }
    case Instruction('O', 'D'):
    case Software_Class::Desk: // "OD" Open Desk page & load it
        DESK.Open(Pages.Desk);
        break;
    case Instruction('O', 'd'): // "Od" Open drawer
        DESK.Open(Pages.Drawer);
        break;
    case Instruction('O', 'A'): // Open about xila
        Xila.Display.Set_Current_Page(Pages.About);
        break;
    case Dialog_Keyboard:
        DIALOG->Open(Dialog_Keyboard);
        break;
    case Dialog_Keypad:
        DIALOG->Open(Dialog_Keypad);
        break;
    case Dialog_Open_File:
        FILE_MANAGER->Open(Dialog_Open_File);
        break;
    case Dialog_Open_Folder:
        FILE_MANAGER->Open(Dialog_Open_Folder);
        break;
    case Dialog_Save_File:;
        FILE_MANAGER->Open(Dialog_Save_File);
        break;
    case Dialog_Event:
        // -- Already openend
        break;
    case Software_Class::Shutdown:
        DIALOG->Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
        Save_Registry();
        break;
    case Restart:
        DIALOG->Load(Load_Restart_Header_String, Load_Restart_Message_String);
        Save_Registry();
        break;
    case Hibernate:
        DIALOG->Load(Load_Hibernate_Header_String, Load_Hibernate_Message_String);
        Save_Registry();
        break;
    case Instruction('O', 'F'): // Open file manager
        FILE_MANAGER->Open(Idle);
        break;

    case Instruction('O', 'P'): // Open preferiencies (default : personnal)
        PREFERENCES->Open('P');
        break;
    case Instruction('O', 'H'): // "OH" : Open hardware prefencies
        PREFERENCES->Open('H');
        break;
    case Instruction('O', 'N'): // "ON" : Open network
        PREFERENCES->Open('N');
        break;
    case Instruction('O', 'S'): // "OS" : Open system preferencies
        PREFERENCES->Open('S');
        break;
    case Instruction('O', 'I'):
        PREFERENCES->Open('I');
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
        break;
    }
}

// -- Set variable -- //

void Shell_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Xila.Display.Get_Current_Page())
    {
    case Pages.Preferences_Hardware:
        if (Preferences_Class::State())
        {
            switch (Adress)
            {
            case 'B':
                if (Type == Xila.Display.Variable_Long)
                {
                    Xila.Display.Brightness = *(uint8_t *)Variable;
                }
                break;
            case 'V':
                if (Type == Xila.Display.Variable_Long)
                {
                    Xila.Sound.Set_Volume(*(uint8_t *)Variable);
                }
                break;
            default:
                break;
            }
        }
        break;
    case Pages.File_Manager_Main:
        if (File_Manager_Class::State())
        {
            switch (Adress)
            {
            case 'F':
                if (FILE_MANAGER->Current_Path[1] != '\0')
                {
                    strcat(FILE_MANAGER->Current_Path, "/");
                }
                strlcat(FILE_MANAGER->Current_Path, (char *)Variable, sizeof(FILE_MANAGER->Current_Path));
                SHELL->Send_Instruction('R', 'e');
                break;
            default:
                break;
            }
        }
        break;
    case Pages.Dialog_Keyboard:
        if (Dialog_Class::State() && Adress == 'I' && Xila.Dialog.Pointer != NULL)
        {
            strlcpy((char *)Xila.Dialog.Pointer, (char *)Variable, Xila.Dialog.Long[0]);
        }
        break;
    case Pages.Dialog_Keypad:
        if (Dialog_Class::State() && Adress == 'I')
        {
            strlcpy(DIALOG->Temporary_Float_String, (char *)Variable, sizeof(DIALOG->Temporary_Float_String));
        }
        break;
    case Pages.Dialog_Color_Picker:
        if (Dialog_Class::State() && Adress == 'C' && Xila.Dialog.Pointer != NULL)
        {
            memcpy(Xila.Dialog.Pointer, (uint16_t *)Variable, sizeof(uint16_t));
        }
        break;
    default:
        break;
    }
}

// -- Shell registry management -- //

Xila_Class::Event Shell_Class::Load_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Xila.Account.Get_Current_Username());
    File Registry_File = Xila.Drive.Open(User_Registry_Path);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok)
    {
        Registry_File.close();
        return Xila.Error;
    }
    Registry_File.close();
    if (strcmp("Shell", Shell_Registry["Registry"] | "") != 0)
    {
        DESK.Background = Default_Background;
        return Xila.Error;
    }
    DESK.Background = Shell_Registry["Desk Background"] | Default_Background;
    return Xila.Success;
}

Xila_Class::Event Shell_Class::Save_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Xila.Account.Get_Current_Username());
    File Registry_File = Xila.Drive.Open(User_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Registry_File);
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry["Desk Background"] = DESK.Background;
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.close();
        return Xila.Error;
    }
    Registry_File.close();
    return Xila.Success;
}
