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

Xila::Software_Handle_Type Shell_Class::Handle("Shell", Shell_Class::Create_Instance);

// -- Initialize shell -- //

Shell_Class::Shell_Class() : Software_Class(&Handle), Desk(this)
{
    File_Manager_Pointer = NULL;
    Preferences_Pointer = NULL;
    Next_Refresh = 0;
}

Shell_Class::~Shell_Class()
{
    // -- Unload all modules -- //
    File_Manager_Class::Close(this);
    Preferences_Class::Close(this);
    Drawer_Class::Close(this);
}

Software_Type *Shell_Class::Open_Shell()
{
    return new Shell_Class();
}

// -- Main shell methods -- //

void Shell_Class::Main_Task_Function()
{
    while (1)
    {
        if (Instruction_Available())
        {
            Execute_Instruction(Get_Instruction());
        }
        else
        {
            if (Time.Milliseconds() > Next_Refresh)
            {
                Desk.Refresh_Overlay();
                Next_Refresh = Time.Milliseconds() + 1000;
            }
            Main_Task.Delay(40);
        }
    }
}

void Shell_Class::Execute_Instruction(Instruction_Type Instruction)
{

    /*  switch (Instruction.)
      {
      case Dialog_Color_Picker:
          Dialog.Color_Picker_Pointer.Open();
          break;
      case Dialog_Power:
          Dialog.Power();
          break;
      case Dialog_Login:
          Dialog.Login_Pointer->Open(Pages.Dialog_Login);
          break;
      case Open:
          if (!Drive.Exists(Users_Directory_Path))
          {
              Display.Set_Current_Page(Pages.Welcome);
              return;
          }

          if (Account.Get_State() == Account.Logged)
          {
              Load_Registry();
          }
      case Instruction('O', 'D'):
      case Desk: // "OD" Open Desk page & load it
          Desk.Open(Pages.Desk);
          break;
      case Instruction('O', 'd'): // "Od" Open drawer
          Desk.Open(Pages.Drawer);
          break;
      case Instruction('O', 'A'): // Open about xila
          Display.Set_Current_Page(Pages.About);
          break;
      case Dialog_Keyboard:
          Dialog.Keyboard_Pointer->Open();
          break;
      case Dialog_Keypad:
          Dialog.Keypad_Pointer->Open();
          break;
      case Dialog_Open_File:
          File_Manager_Pointer->Open(Dialog_Open_File);
          break;
      case Dialog_Open_Folder:
          File_Manager_Pointer->Open(Dialog_Open_Folder);
          break;
      case Dialog_Save_File:
          File_Manager_Pointer->Open(Dialog_Save_File);
          break;
      case Dialog_Event:
          Dialog.Event_Pointer->Open();
          break;
      case Dialog_Load:
          Dialog.Load_Pointer->Open();
          break;
      case Shutdown:
          DIALOG.Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
          Save_Registry();
          break;
      case Restart:
          DIALOG.Load(Load_Restart_Header_String, Load_Restart_Message_String);
          Save_Registry();
          break;
      case Hibernate:
          DIALOG.Load(Load_Hibernate_Header_String, Load_Hibernate_Message_String);
          Save_Registry();
          break;
      case Instruction('O', 'F'): // Open file manager
          File_Manager_Class::Open(Idle);
          break;

      case Instruction('O', 'P'): // Open preferiencies (default : personal)
          Preferences_Class::Open(Pages.Preferences_Personal);
          break;
      case Instruction('O', 'H'): // "OH" : Open hardware prefencies
          Preferences_Class::Open(Pages.Preferences_Hardware);
          break;
      case Instruction('O', 'N'): // "ON" : Open network
          Preferences_Class::Open(Pages.Preferences_Network);
          break;
      case Instruction('O', 'S'): // "OS" : Open system preferencies
          Preferences_Class::Open(Pages.Preferences_System);
          break;
      case Instruction('O', 'I'):
          Preferences_Class::Open(Pages.Preferences_Install);
          break;
      case Close: // close
          delete Instance_Pointer;
          Task.Delete();
          break;
      case Minimize: // minimize
          break;
      case Maximize:
          Send_Instruction('R', 'e');
          break;
      default:
  */
    if (File_Manager_Class::Is_Openned(this))
    {
        if (File_Manager_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            File_Manager_Pointer->Execute_Instruction(Get_Instruction());
        }
    }
    else if (Preferences_Class::Is_Openned(this))
    {
        if (Preferences_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Preferences_Pointer->Execute_Instruction(Get_Instruction());
        }
    }
    else if (Drawer_Class::Is_Openned(this))
    {
        if (Drawer_Pointer->Window.Get_State() == Graphics_Types::Window_State_Type::Maximized)
        {
            Drawer_Pointer->Execute_Instruction(Get_Instruction());
        }
    }
    else
    {
        Desk.Execute_Instruction(Get_Instruction());
    }
    /*
            break;
        }
    */
}

// -- Shell registry management -- //

/// @brief Load shell registry.
/// @return 
Result_Type Shell_Class::Load_Registry()
{
    /*
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Shell/Shell.xrf"), Account.Get_Logged_User()->Get_Name());

    File_Type Registry_File = Drive.Open(User_Registry_Path, true);
    DynamicJsonDocument Shell_Registry(256);
    if (deserializeJson(Shell_Registry, Registry_File) != DeserializationError::Ok)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();
  
    if (strcmp("Shell", Shell_Registry["Registry"] | "") != 0)
    {
        DESK.Background = Default_Background;
        return Result_Type::Error;
    }
    DESK.Background = Shell_Registry["Desk Background"] | Default_Background;
    */
    return Result_Type::Success;
}

/// @brief Save shell registry.
/// @return 
Result_Type Shell_Class::Save_Registry()
{
    char User_Registry_Path[40];
    snprintf(User_Registry_Path, sizeof(User_Registry_Path), (Users_Directory_Path "/%s/Registry/Shell.xrf"), Account.Get_Current_Username());
    File_Type Registry_File = Drive.Open(User_Registry_Path, true);
    DynamicJsonDocument Shell_Registry(256);
    deserializeJson(Shell_Registry, Registry_File);
    Shell_Registry["Registry"] = "Shell";
    Shell_Registry["Desk Background"] = DESK.Background;
    if (serializeJson(Shell_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();
    return Result_Type::Success;
}
