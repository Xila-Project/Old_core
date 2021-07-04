///
/// @file Dialog.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Dialog of Shell
/// @version 0.1
/// @date 29-06-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Shell/Shell.hpp"
#include "Software/Shell/Translation.hpp"

// -- Constructor -- //

Shell_Class::Dialog_Class::Dialog_Class()
{
    memset(Temporary_Float_String, '\0', sizeof(Temporary_Float_String));
}

Shell_Class::Dialog_Class::~Dialog_Class()
{

}

// -- Open dialog -- //

void Shell_Class::Dialog_Class::Open(uint8_t Mode)
{
    if (DIALOG == NULL)
    {
        DIALOG = new Dialog_Class;
    }

    switch (Mode)
    {
    case Pages.Dialog_Keypad:
        Xila.Display.Set_Current_Page(Dialog_Keypad);
        Xila.Mathematics.Float_To_String(*(double *)Xila.Dialog.Pointer, -1, 9, DIALOG->Temporary_Float_String);
        Xila.Display.Set_Text(F("INPUT_VAR"), DIALOG->Temporary_Float_String);
        Xila.Keyboard.Clear();
        break;
    case Pages.Dialog_Keyboard:
        Xila.Display.Set_Current_Page(Pages.Dialog_Keyboard);
        Xila.Display.Set_Value(F("MAXLENGTH_VAR"), Xila.Dialog.Long[0]);
        Xila.Display.Set_Text(F("INPUT_VAR"), (char *)Xila.Dialog.Pointer);
        Xila.Display.Set_Mask(F("INPUT_TXT"), (bool)Xila.Dialog.Long[1]);
        Xila.Keyboard.Clear();
        break;
    case Pages.Dialog_Color_Picker:
    {
        Xila.Display.Set_Current_Page(Dialog_Color_Picker);
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
    break;

    default:
        break;
    }
}

bool Shell_Class::Dialog_Class::State()
{
    if (DIALOG == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Dialog_Class::Close()
{
    if (State())
    {
#if Animation == 1
        Xila.Display.Set_Value(F("STATE_VAR"), 2);
        Xila.Task.Delay(1000);
#endif
        delete DIALOG;
    }
}

// -- Load dialog -- //

void Shell_Class::Dialog_Class::Load(const __FlashStringHelper *Header, const __FlashStringHelper *Message, uint16_t Duration)
{
    Xila.Display.Set_Current_Page(Pages.Dialog_Load);
    Xila.Display.Set_Text(F("SUBHEADER_TXT"), Header);
    Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);

    if (Duration != 0)
    {
        Xila.Task.Delay(Duration);
        DIALOG->Close();
    }
}

void Shell_Class::Dialog_Class::Load(const char *Header, const char *Message, uint16_t Duration)
{
    Xila.Display.Set_Current_Page(Pages.Dialog_Load);
    Xila.Display.Set_Text(F("SUBHEADER_TXT"), Header);
    Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);

    if (Duration != 0)
    {
        Xila.Task.Delay(Duration);
        DIALOG->Close();
    }
}

// -- Keyboard dialog -- //

Xila_Class::Event Shell_Class::Dialog_Class::Keyboard(char *Char_Array_To_Get, size_t Char_Array_Size, bool Masked_Input)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);
    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // -- Initialize variable
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Long[0] = Char_Array_Size - 1;
    Xila.Dialog.Long[1] = Masked_Input;
    Xila.Dialog.Pointer = Char_Array_To_Get;
    // -- Open keyboard dialog
    Open(Pages.Dialog_Keyboard);
    //
    while (Xila.Dialog.State == Xila.None)
    {
        DIALOG->Execute_Keyboard_Instruction(SHELL->Get_Instruction());
    }

    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

void Shell_Class::Dialog_Class::Execute_Keyboard_Instruction(Xila_Instruction Instruction)
{
    while (Xila.Keyboard.Available())
    {
        char Temporary_Char = Xila.Keyboard.Read();
        switch (Temporary_Char)
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
            if (isPrintable(Temporary_Char))
            {
                Xila.Display.Set_Text(F("T_VAR"), Temporary_Char);
                Xila.Display.Click(F("K_HOT"), 0);
            }
            break;
        }
    }

    switch (Instruction)
    {
    case Instruction('V', 'a'):
        Xila.Dialog.State = Xila.Default_Yes;
        Close();
        break;
    case SHELL->Dialog_Power:
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Default_Cancel;
        Close();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Keypad dialog -- //

Xila_Class::Event Shell_Class::Dialog_Class::Keypad(float &Number_To_Get)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);
    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // -- Initialize variable
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &Number_To_Get;
    // -- Open keyboard dialog
    Open(Pages.Dialog_Keypad);
    //
    while (Xila.Dialog.State == Xila.None)
    {
        DIALOG->Execute_Keypad_Instruction(SHELL->Get_Instruction());
    }

    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

void Shell_Class::Dialog_Class::Execute_Keypad_Instruction(Xila_Instruction Instruction)
{
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
    switch (Instruction)
    {
    case Instruction('V', 'a'):
        *(float *)Xila.Dialog.Pointer = strtof(Temporary_Float_String, NULL);
        Xila.Dialog.State = Xila.Default_Yes;
        Close();
        break;
    case Dialog_Power:
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Default_Cancel;
        Close();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Shutdown -- //

void Shell_Class::Dialog_Class::Execute_Shutdown_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'S'): // RS : Restart system
        Load(Load_Restart_Header_String, Load_Restart_Message_String);
        SHELL->Save_Registry();
        SHELL->Set_Watchdog_Timeout(30000);
        Xila.System.Restart();
        break;
    case Instruction('H', 'S'): // HS : hibernate sys
        Load(Load_Restart_Header_String, Load_Restart_Message_String);
        SHELL->Save_Registry();
        SHELL->Set_Watchdog_Timeout(30000);
        Xila.System.Hibernate();
        break;
    case Instruction('L', 'S'): // LS : lock system
        SHELL->Save_Registry();
        Xila.Account.Lock();
        SHELL->Send_Instruction('O', 'L');
        break;
    case Instruction('S', 'S'): // SS : shutdown
        Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
        SHELL->Save_Registry();
        SHELL->Set_Watchdog_Timeout(30000);
        Xila.System.Shutdown();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Dialogs -- //

// -- Color dialog -- //

void Shell_Class::Dialog_Class::Execute_Color_Picker_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('V', 'a'):
        Xila.Dialog.State = Xila.Default_Yes;
        Close();
        break;
    case Dialog_Power:
    case Instruction('C', 'a'):
        Xila.Dialog.State = Xila.Default_Cancel;
        Close();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

Xila_Class::Event Shell_Class::Dialog_Class::Color_Picker(uint16_t &Color)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    // -- Save context
    Xila.Display.Send_Raw(F("PAGE=dp"));
    Xila.Dialog.Caller_Software = Instance_Pointer;
    // --
    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &Color;
    // --
    Open(Pages.Dialog_Color_Picker);
    // -- Tasks suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        DIALOG->Execute_Color_Picker_Instruction(SHELL->Get_Instruction());
    }
    // -- Retore software state
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

// -- Event dialog -- //

void Shell_Class::Dialog_Class::Execute_Event_Instruction(Xila_Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('B', '1'):
        Xila.Dialog.State = Xila.Button_1;
        Close();
        break;
    case Instruction('B', '2'):
        Xila.Dialog.State = Xila.Button_2;
        Close();
        break;
    case Instruction('B', '3'):
        Xila.Dialog.State = Xila.Button_3;
        Close();
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

Xila_Class::Event Shell_Class::Dialog_Class::Event(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Display.Send_Raw(F("PAGE=dp")); // save app page id
    Xila.Display.Set_Current_Page(F("Shell_Event"));

    Xila.Dialog.State = Xila.None;

    if (Button_Text_1 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON1_BUT"), Button_Text_1);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON1_BUT"), F("Yes"));
    }
    if (Button_Text_2 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON2_BUT"), Button_Text_2);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON2_BUT"), F("No"));
    }

    if (Button_Text_3 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON3_BUT"), Button_Text_3);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON3_BUT"), F("Cancel"));
    }
    Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);

    switch (Event_Type)
    {
    case Xila.Error:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Cross);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Red);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Error"));
        break;
    case Xila.Warning:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Yellow);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Warning"));
        break;
    case Xila.Information:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Blue);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Information"));
        break;
    case Xila.Question:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Question_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Green);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Question"));
    default:
        break;
    }
    Xila.Display.Show(F("CLOSE_BUT"));
    // -- Tasks is suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        DIALOG->Execute_Event_Instruction(SHELL->Get_Instruction());
    }

    Xila.Display.Set_Current_Page(F("PAGE")); //go back to app page

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Event(const char *Message, uint8_t Event_Type, const char *Button_Text_1, const char *Button_Text_2, const char *Button_Text_3)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Display.Send_Raw(F("PAGE=dp")); // save app page id
    Xila.Display.Set_Current_Page(F("Shell_Event"));

    Xila.Dialog.State = Xila.None;

    if (Button_Text_1 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON1_BUT"), Button_Text_1);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON1_BUT"), F("Yes"));
    }
    if (Button_Text_2 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON2_BUT"), Button_Text_2);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON2_BUT"), F("No"));
    }

    if (Button_Text_3 != NULL)
    {
        Xila.Display.Set_Text(F("BUTTON3_BUT"), Button_Text_3);
    }
    else
    {
        Xila.Display.Set_Text(F("BUTTON3_BUT"), F("Cancel"));
    }
    Xila.Display.Set_Text(F("MESSAGE_TXT"), Message);

    switch (Event_Type)
    {
    case Xila.Error:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Cross);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Red);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Error"));
        break;
    case Xila.Warning:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Yellow);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Warning"));
        break;
    case Xila.Information:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Exclamation_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Blue);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Information"));
        break;
    case Xila.Question:
        Xila.Display.Set_Text(F("ICON_TXT"), Xila.Display.Question_Mark);
        Xila.Display.Set_Font_Color(F("ICON_TXT"), Xila.Display.Green);
        Xila.Display.Set_Text(F("SUBHEADER_TXT"), F("Question"));
    default:
        break;
    }
    Xila.Display.Show(F("CLOSE_BUT"));
    // -- Tasks is suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        DIALOG->Execute_Event_Instruction(SHELL->Get_Instruction());
    }

    Xila.Display.Set_Current_Page(F("PAGE")); //go back to app page

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

// -- Open file dialog -- //

Xila_Class::Event Shell_Class::Dialog_Class::Open_File(File &File_To_Open)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Display.Send_Raw(F("PAGE=dp"));

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &File_To_Open;

    File_Manager_Class::Open(Dialog_Open_File);

    while (Xila.Dialog.State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        File_To_Open = *(File *)Xila.Dialog.Pointer;
    }
    //
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Save_File(File &File_To_Save)
{
    xSemaphoreTake(Xila.Dialog.Semaphore, portMAX_DELAY);

    Xila.Display.Send_Raw(F("PAGE=dp"));

    Xila.Dialog.Caller_Software = Instance_Pointer;

    Xila.Dialog.State = Xila.None;
    Xila.Dialog.Pointer = &File_To_Save;

    File_Manager_Class::Open(Dialog_Save_File);

    while (Xila.Dialog.State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        File_To_Save = *(File *)Xila.Dialog.Pointer;
    }
    //
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);

    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;

    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Open_Folder(File &Folder_To_Open)
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
    File_Manager_Class::Open(Dialog_Open_File);
    // -- Tasks suspended here
    while (Xila.Dialog.State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
    }
    if (Xila.Dialog.State == Xila.Button_1)
    {
        Folder_To_Open = *(File *)Xila.Dialog.Pointer;
    }
    // -- Retore software state
    Xila.Software.Openned[0] = Xila.Dialog.Caller_Software;
    Xila.Display.Set_Current_Page(F("PAGE"));

    Xila.Task.Delay(20);
    //
    Xila.Dialog.Pointer = NULL;
    Xila.Dialog.Long[0] = 0;
    Xila.Dialog.Long[1] = 0;
    Xila.Dialog.Caller_Software = NULL;
    //
    xSemaphoreGive(Xila.Dialog.Semaphore);
    return Xila.Dialog.State;
}