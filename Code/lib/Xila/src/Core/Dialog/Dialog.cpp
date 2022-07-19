///
/// @file Dialog.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

extern Xila_Class::Software_Handle Shell_Handle;

///
/// @brief Construct a new Xila_Class::Dialog_Class::Dialog_Class object
///
Xila_Class::Dialog_Class::Dialog_Class()
{
}

///
/// @brief Open a virtual keyboard to input text.
///
/// @param String String to input.
/// @param Size String size.
/// @param Masked_Input Enable / disable masking.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Keyboard(char *String, size_t Size, bool Masked_Input)
{
  Keyboard_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Keyboard);
  Xila.Software_Management.Shell_Set_Variable(Address('S', 't'), Variable_String, String);
  Xila.Software_Management.Shell_Set_Variable(Address('S', 'i'), Variable_Long, &Size);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'a'), Variable_Long, &Masked_Input);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here 
  while (Keyboard_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return Keyboard_State;
}

///
/// @brief Open a virtual keypad to input a float number.
///
/// @param Number Number to input.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Keypad(float &Number)
{
  Keypad_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Keypad);
  Xila.Software_Management.Shell_Set_Variable(Address('N', 'u'), Variable_Long, &Number);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (Keypad_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return Keypad_State;
}

///
/// @brief Open a color picker dialog, that allow user to choose a color.
///
/// @param[in,out] Color Color reference.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Color_Picker(uint16_t &Color)
{
  Color_Picker_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell dialog
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Color_Picker);
  Xila.Task.Delay(40);
  Xila.Software_Management.Shell_Set_Variable(Address('C', 'P'), Pointer, &Color);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Task suspended here
  while (Color_Picker_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return Color_Picker_State;
}

///
/// @brief Open an event dialog.
///
/// @param Message Message to show on dialog.
/// @param Type Event dialog type.
/// @param Button_Text_1 1st button string (by default : "Yes").
/// @param Button_Text_2 2nd button string (by default : "No").
/// @param Button_Text_3 3rd button string (by default : "Cancel").
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Event(const __FlashStringHelper *Message, uint8_t Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  Event_State = None;
  uint8_t Mode = 'F';
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Event);
  Xila.Task.Delay(10);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'e'), Variable_String, Message);
  Xila.Software_Management.Shell_Set_Variable(Address('T', 'y'), Variable_Long, &Type);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'o'), Variable_Long, &Mode);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '1'), Variable_String, Button_Text_1);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '2'), Variable_String, Button_Text_2);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '3'), Variable_String, Button_Text_3);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (Event_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return Event_State;
}

///
/// @brief Open an event dialog.
///
/// @param Message Message to show on dialog.
/// @param Type Event dialog type.
/// @param Button_Text_1 1st button string (by default : "Yes").
/// @param Button_Text_2 2nd button string (by default : "No").
/// @param Button_Text_3 3rd button string (by default : "Cancel").
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Event(const char *Message, uint8_t Type, const char *Button_Text_1, const char *Button_Text_2, const char *Button_Text_3)
{
  Event_State = None;
  uint8_t Mode = 'C';
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell variable
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Event);
  Xila.Task.Delay(10);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'e'), Variable_String, Message);
  Xila.Software_Management.Shell_Set_Variable(Address('T', 'y'), Variable_Long, &Type);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'o'), Variable_Long, &Mode);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '1'), Variable_String, Button_Text_1);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '2'), Variable_String, Button_Text_2);
  Xila.Software_Management.Shell_Set_Variable(Address('B', '3'), Variable_String, Button_Text_3);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (Event_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return Event_State;
}

///
/// @brief Open a loading dialog.
///
/// @param Header Header string.
/// @param Message Message string.
void Xila_Class::Dialog_Class::Load(const __FlashStringHelper *Header, const __FlashStringHelper *Message, uint32_t Duration)
{
  if (Duration > 28000)
  {
    Duration = 28000;
  }
  uint8_t Mode = 'F';
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Load);
  Xila.Software_Management.Shell_Set_Variable(Address('H', 'e'), Variable_String, Header);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'e'), Variable_String, Message);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'o'), Variable_Long, &Mode);
  Xila.Software_Management.Shell_Set_Variable(Address('D', 'u'), Variable_Long, &Duration);
  Xila.Software_Management.Shell_Set_Variable(Address('S', 'o'), Variable_Long, Xila.Software_Management.Openned[0]);
  Xila.Software_Management.Openned[0]->Set_Watchdog_Timeout(30000);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  Xila.Task.Delay(Duration);
}

///
/// @brief Open a load dialog with an animation.
///
/// @param Header Header string.
/// @param Message Message string.
/// @param Duration Duration in milliseconds (by default 0, the load dialog still displayed until Xila.Dialog.Close_Load() is called).
void Xila_Class::Dialog_Class::Load(const char *Header, const char *Message, uint32_t Duration)
{
  if (Duration > 28000)
  {
    Duration = 28000;
  }
  uint8_t Mode = 'C';
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Load);
  Xila.Software_Management.Shell_Set_Variable(Address('H', 'e'), Variable_String, Header);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'e'), Variable_String, Message);
  Xila.Software_Management.Shell_Set_Variable(Address('M', 'o'), Variable_Long, &Mode);
  Xila.Software_Management.Shell_Set_Variable(Address('D', 'u'), Variable_Long, &Duration);
  Xila.Software_Management.Shell_Set_Variable(Address('S', 'o'), Variable_Long, Xila.Software_Management.Openned[0]);
  Xila.Software_Management.Openned[0]->Set_Watchdog_Timeout(30000);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  Xila.Task.Delay(Duration);
}

///
/// @brief Close an openned load dialog.
///
void Xila_Class::Dialog_Class::Close_Load()
{
  uint32_t Duration = Xila.Time.Milliseconds();
  Xila.Software_Management.Shell_Set_Variable(Address('l', 'D'), Variable_Long, &Duration);
}

///
/// @brief Open a dialog that allow user to input credentials, which are checked.
///
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Login()
{
  Login_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Maximize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Login);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (Login_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Return dialog result
  return Login_State;
}

///
/// @brief Open a dialog that allow user to change system power state.
///
void Xila_Class::Dialog_Class::Power()
{
  Power_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Maximize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Power);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (Power_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  // -- Restore context
  Xila.Software_Management.Openned[0] = Caller_Software;
}

///
/// @brief Open a dialog that allow user to select a file to save from the File Manager.
///
/// @param File_To_Open File reference.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Open_File(File &File_To_Open)
{
  File_Manager_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Open_File);
  Xila.Software_Management.Shell_Set_Variable(Address('I', 'P'), Pointer, &File_To_Open);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (File_Manager_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return File_Manager_State;
}

///
/// @brief Open a dialog that allow user to select a file to save from the File Manager.
///
/// @param File_To_Save File reference.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Save_File(File &File_To_Save)
{
  File_Manager_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Save_File);
  Xila.Software_Management.Shell_Set_Variable(Address('I', 'P'), Pointer, &File_To_Save);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (File_Manager_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return File_Manager_State;
}

///
/// @brief Open a dialog that allow user to select a folder to open from the File Manager.
///
/// @param[out] Folder_To_Open Folder reference.
/// @return Xila_Class::Event
Xila_Class::Event Xila_Class::Dialog_Class::Open_Folder(File &Folder_To_Open)
{
  File_Manager_State = None;
  // -- Save context
  Xila_Class::Software *Caller_Software = Xila.Software_Management.Openned[0];
  // -- Initialize shell variable
  Xila.Software_Management.Shell_Send_Instruction(Dialog_Open_Folder);
  Xila.Software_Management.Shell_Set_Variable(Address('I', 'P'), Pointer, &Folder_To_Open);
  Xila.Software_Management.Maximize(Shell_Handle);
  // -- Tasks suspended here
  while (File_Manager_State == Xila.None)
  {
    Caller_Software->Last_Watchdog_Feed = Xila.Time.Milliseconds(); // -- Feed software watchdog
    Xila.Task.Delay(100);
  }
  Xila.Software_Management.Openned[0] = Caller_Software;
  // -- Give semaphore back and return dialog result
  return File_Manager_State;
}