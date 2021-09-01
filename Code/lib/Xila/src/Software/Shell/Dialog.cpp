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
    Keyboard_Pointer = NULL;
    Keypad_Pointer = NULL;
    Event_Pointer = NULL;
    Load_Pointer = NULL;
    Login_Pointer = NULL;
}

Shell_Class::Dialog_Class::~Dialog_Class()
{
    if (KEYBOARD->State())
    {
        delete KEYBOARD;
    }
    if (KEYPAD->State())
    {
        delete KEYPAD;
    }
    if (EVENT->State())
    {
        delete EVENT;
    }
    if (LOAD->State())
    {
        delete LOAD;
    }
    if (LOGIN->State())
    {
        delete LOGIN;
    }
}

// -- Color picker dialog -- //

void Shell_Class::Dialog_Class::Color_Picker_Class::Open()
{
    Xila.Display.Set_Current_Page(Pages.Dialog_Color_Picker);
    Xila.Task.Delay(20);
}

void Shell_Class::Dialog_Class::Color_Picker_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'e'):
    {
        // -- Convert 16 bits color into 3 * 8 bits (24 bits RGB)
        uint8_t Temporary_Byte = *Color >> 11;
        Xila.Display.Set_Value(F("RED_SLI"), Temporary_Byte);
        Temporary_Byte = *Color >> 3;
        Temporary_Byte = Temporary_Byte >> 2;
        Xila.Display.Set_Value(F("GREEN_SLI"), Temporary_Byte);
        Temporary_Byte = *Color << 3;
        Temporary_Byte = Temporary_Byte >> 3;
        Xila.Display.Set_Value(F("BLUE_SLI"), Temporary_Byte);
        Xila.Display.Click(F("COLOR_NUM"), 0);
    }
    break;
    case Instruction('V', 'a'):
        Xila.Dialog.Color_Picker_State = Xila.Default_Yes;
        break;
    case Instruction('C', 'a'):
        Xila.Dialog.Color_Picker_State = Xila.Default_Cancel;
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Event dialog -- //

void Shell_Class::Dialog_Class::Event_Class::Open()
{
    if (!State())
    {
        EVENT = new Event_Class;
    }

    EVENT->Mode = 0;
    EVENT->Message = NULL;
    EVENT->Type = 0;
    EVENT->Button_Text[0] = NULL;
    EVENT->Button_Text[1] = NULL;
    EVENT->Button_Text[2] = NULL;

    Xila.Display.Set_Current_Page(Pages.Dialog_Event);
    Xila.Task.Delay(20);
}

void Shell_Class::Dialog_Class::Event_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'e'):
        if (EVENT->Mode == 'F') // -- __FlashStringHelper strings
        {
            if (EVENT->Button_Text[0] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON1_BUT"), (const __FlashStringHelper *)EVENT->Button_Text[0]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON1_BUT"), F("Yes"));
            }
            if (EVENT->Button_Text[1] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON2_BUT"), (const __FlashStringHelper *)EVENT->Button_Text[1]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON2_BUT"), F("No"));
            }
            if (EVENT->Button_Text[2] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON3_BUT"), (const __FlashStringHelper *)EVENT->Button_Text[2]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON3_BUT"), F("Cancel"));
            }
            if (EVENT->Message != NULL)
            {
                Xila.Display.Set_Text(F("MESSAGE_TXT"), (const __FlashStringHelper *)EVENT->Message);
            }
        }
        if (EVENT->Mode == 'C') // -- __FlashStringHelper strings
        {
            if (EVENT->Button_Text[0] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON1_BUT"), (const char *)EVENT->Button_Text[0]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON1_BUT"), F("Yes"));
            }
            if (EVENT->Button_Text[1] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON2_BUT"), (const char *)EVENT->Button_Text[1]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON2_BUT"), F("No"));
            }
            if (EVENT->Button_Text[2] != NULL)
            {
                Xila.Display.Set_Text(F("BUTTON3_BUT"), (const char *)EVENT->Button_Text[2]);
            }
            else
            {
                Xila.Display.Set_Text(F("BUTTON3_BUT"), F("Cancel"));
            }
            if (EVENT->Message != NULL)
            {
                Xila.Display.Set_Text(F("MESSAGE_TXT"), (const char *)EVENT->Message);
            }
        }

        switch (EVENT->Type)
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
        break;
    case Instruction('B', '1'):
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Event_State = Xila.Button_1;
        SHELL->Send_Instruction('C', 'l');
        break;
    case Instruction('B', '2'):
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Event_State = Xila.Button_2;
        SHELL->Send_Instruction('C', 'l');
        break;
    case Instruction('B', '3'):
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Event_State = Xila.Button_3;
        SHELL->Send_Instruction('C', 'l');
        break;
    case Instruction('C', 'l'):
        DUMP("close event");
        delete EVENT;
        EVENT = NULL;
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

bool Shell_Class::Dialog_Class::Event_Class::State()
{
    if (EVENT == NULL)
    {
        return false;
    }
    return true;
}

// -- Load dialog -- //

void Shell_Class::Dialog_Class::Load_Class::Open()
{
    if (!State())
    {
        LOAD = new Load_Class;
    }

    LOAD->Mode = 0;
    LOAD->Header = NULL;
    LOAD->Message = NULL;

    Xila.Display.Set_Current_Page(Pages.Dialog_Load);
    Xila.Task.Delay(20);
}

bool Shell_Class::Dialog_Class::Load_Class::State()
{
    if (LOAD == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Dialog_Class::Load_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    if (Duration != 0 && Xila.Time.Milliseconds() > Duration)
    {
        Xila.Display.Set_Value(F("STATE_VAR"), 2);
        Xila.Task.Delay(1000);
        Xila.Display.Set_Current_Page(Page);
        Xila.Software_Management.Openned[0] = Caller_Software;
        delete this;
        LOAD = NULL;
    }

    switch (Instruction)
    {
    case Instruction('R', 'e'):
        if (LOAD->Duration != 0)
        {
            LOAD->Duration = Xila.Time.Milliseconds() + LOAD->Duration - 1000;
        }
        if (LOAD->Mode == 'F') // -- __FlashStringHelper strings
        {
            if (LOAD->Header != NULL)
            {
                Xila.Display.Set_Text(F("SUBHEADER_TXT"), (const __FlashStringHelper *)LOAD->Header);
            }
            if (LOAD->Message != NULL)
            {
                Xila.Display.Set_Text(F("MESSAGE_TXT"), (const __FlashStringHelper *)LOAD->Message);
            }
        }
        if (EVENT->Mode == 'C') // -- __FlashStringHelper strings
        {
            if (LOAD->Header != NULL)
            {
                Xila.Display.Set_Text(F("SUBHEADER_TXT"), (const char *)LOAD->Header);
            }
            if (LOAD->Message != NULL)
            {
                Xila.Display.Set_Text(F("MESSAGE_TXT"), (const char *)LOAD->Message);
            }
        }
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Login dialog -- //

void Shell_Class::Dialog_Class::Login_Class::Open(bool Login)
{
    if (!State())
    {
        LOGIN = new Login_Class;
    }

    strlcpy(LOGIN->Username, "Username", sizeof(LOGIN->Username));
    strlcpy(LOGIN->Password, "Password", sizeof(LOGIN->Password));

    LOGIN->Login = Login;

    Xila.Display.Set_Current_Page(Pages.Dialog_Login);
    Xila.Task.Delay(20);
}

bool Shell_Class::Dialog_Class::Login_Class::State()
{
    if (LOGIN == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Dialog_Class::Login_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'e'):
        Xila.Display.Set_Text(F("USERNAME_TXT"), Username);
        Xila.Display.Set_Text(F("PASSWORD_TXT"), Password);
        break;
    case Instruction('K', 'U'):
        memset(Username, '\0', sizeof(Username));
        DIALOG.Keyboard(Username, sizeof(Username));
        Xila.Display.Set_Current_Page(Page);
        Xila.Display.Set_Current_Page(Pages.Dialog_Login);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('K', 'P'):
        memset(Password, '\0', sizeof(Password));
        DIALOG.Keyboard(Password, sizeof(Password), true);
        Xila.Display.Set_Current_Page(Page);
        Xila.Display.Set_Current_Page(Pages.Dialog_Login);
        SHELL->Send_Instruction('R', 'e');
        break;
    case Instruction('C', 'l'):
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Login_State = Xila.Default_Cancel;
        delete this;
        LOGIN = NULL;
        break;
    case Instruction('L', 'o'):

        if (Xila.Account.Check_Credentials(Username, Password) == Xila.Success)
        {
            if (Login == true)
            {
                Xila.Account.Login(Username, Password);
            } 
            Xila.Display.Set_Current_Page(Page);
            
            Xila.Dialog.Login_State = Xila.Success;
            delete this;
            LOGIN = NULL;
        }
        else
        {
            DIALOG.Event(Event_Error_Wrong_Credentials, Xila.Error);
            SHELL->Send_Instruction('R', 'e');
        }
        break;
    default:
        SHELL->Send_Instruction(Instruction);
        break;
    }
}

// -- Keyboard dialog -- //

void Shell_Class::Dialog_Class::Keyboard_Class::Open()
{
    if (!State())
    {
        KEYBOARD = new Keyboard_Class;
    }

    Xila.Display.Set_Current_Page(Pages.Dialog_Keyboard);
    KEYBOARD->String = NULL;
    KEYBOARD->Size = 0;
    KEYBOARD->Masked_Input = false;
    Xila.Keyboard.Clear();
    Xila.Task.Delay(20);
}

bool Shell_Class::Dialog_Class::Keyboard_Class::State()
{
    if (KEYBOARD == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Dialog_Class::Keyboard_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
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
        Xila.Display.Set_Current_Page(KEYBOARD->Page);

        Xila.Dialog.Keyboard_State = Xila.Default_Yes;
        delete KEYBOARD;
        KEYBOARD = NULL;
        break;
    case Instruction('C', 'a'):
        Xila.Display.Set_Current_Page(KEYBOARD->Page);

        Xila.Dialog.Keyboard_State = Xila.Default_Cancel;
        delete KEYBOARD;
        KEYBOARD = NULL;
        break;
    case Instruction('R', 'e'):
        Xila.Display.Set_Value(F("MAXLENGTH_VAR"), KEYBOARD->Size);
        Xila.Display.Set_Text(F("INPUT_VAR"), (const char *)KEYBOARD->String);
        Xila.Display.Set_Mask(F("INPUT_TXT"), (bool)KEYBOARD->Masked_Input);
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Keypad dialog -- //

void Shell_Class::Dialog_Class::Keypad_Class::Open()
{
    if (!State())
    {
        KEYPAD = new Keypad_Class;
    }

    Xila.Display.Set_Current_Page(Pages.Dialog_Keypad);
    Xila.Keyboard.Clear();
    Xila.Task.Delay(20);
}

bool Shell_Class::Dialog_Class::Keypad_Class::State()
{
    if (KEYPAD == NULL)
    {
        return false;
    }
    return true;
}

void Shell_Class::Dialog_Class::Keypad_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
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
        *Number = strtof(Temporary_Float_String, NULL);
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Keypad_State = Xila.Default_Yes;
        delete this;
        KEYPAD = NULL;
        break;
    case Instruction('C', 'a'):
        Xila.Display.Set_Current_Page(Page);

        Xila.Dialog.Keypad_State = Xila.Default_Cancel;
        delete this;
        KEYPAD = NULL;
        break;
    case Instruction('R', 'e'):
        Xila.Mathematics.Float_To_String(*(double *)Number, -1, 9, Temporary_Float_String);
        Xila.Display.Set_Text(F("INPUT_VAR"), KEYPAD->Temporary_Float_String);
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

// -- Power dialog -- //

void Shell_Class::Dialog_Class::Power_Class::Execute_Instruction(Xila_Class::Instruction Instruction)
{
    switch (Instruction)
    {
    case Instruction('R', 'S'): // RS : Restart system
        DIALOG.Load(Load_Restart_Header_String, Load_Restart_Message_String);
        SHELL->Save_Registry();
        SHELL->Set_Watchdog_Timeout(30000);
        Xila.System.Restart();
        break;
    case Instruction('H', 'S'): // HS : hibernate sys
        DIALOG.Load(Load_Restart_Header_String, Load_Restart_Message_String);
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
        DIALOG.Load(Load_Shutdown_Header_String, Load_Shutdown_Message_String);
        SHELL->Save_Registry();
        SHELL->Set_Watchdog_Timeout(30000);
        Xila.System.Shutdown();
        break;
    case Instruction('C', 'l'):
        Xila.Dialog.Power_State = Xila.Default_Cancel;
        break;
    default:
        SHELL->Execute_Instruction(Instruction);
        break;
    }
}

void Shell_Class::Dialog_Class::Power_Class::Open()
{
    Xila.Display.Set_Current_Page(Pages.Dialog_Power);
    Xila.Task.Delay(20);
}

// -- Local dialogs

///
/// @brief Open a virtual keyboard to input text.
///
/// @param String String to input.
/// @param Size String size.
/// @param Masked_Input Enable / disable masking.
/// @return Xila_Class::Event
Xila_Class::Event Shell_Class::Dialog_Class::Keyboard(char *String, size_t Size, bool Masked_Input)
{
    Xila.Dialog.Keyboard_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    // -- Initalize shell
    KEYBOARD->Open();
    KEYBOARD->Page = Xila.Display.Get_Current_Page();
    KEYBOARD->String = String;
    KEYBOARD->Size = Size;
    KEYBOARD->Masked_Input = Masked_Input;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Keyboard_State == Xila.None)
    {
        Keyboard_Class::Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Task.Delay(20); // -- Wait 20 ms to switch page
    // --
    return Xila.Dialog.Keyboard_State; // -- Dialog result
}

///
/// @brief Open a virtual keypad to input a float number.
///
/// @param Number Number to input.
/// @return Xila_Class::Event
Xila_Class::Event Shell_Class::Dialog_Class::Keypad(float &Number)
{
    Xila.Dialog.Keypad_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    // -- Initalize shell
    KEYPAD->Open();
    KEYPAD->Page = Xila.Display.Get_Current_Page();
    KEYPAD->Number = &Number;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Keypad_State == Xila.None)
    {
        KEYPAD->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.Keypad_State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Color_Picker(uint16_t &Color)
{
    Xila.Dialog.Color_Picker_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Initalize shell
    Color_Picker_Pointer.Open();
    Color_Picker_Pointer.Color = &Color;
    SHELL->Send_Instruction('R', 'e');
    // -- Task suspended here
    while (Xila.Dialog.Color_Picker_State == Xila.None)
    {
        Color_Picker_Pointer.Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Display.Set_Current_Page(Page);
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.Color_Picker_State;
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
Xila_Class::Event Shell_Class::Dialog_Class::Event(const __FlashStringHelper *Message, uint8_t Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
    Xila.Dialog.Event_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    // -- Initalize shell
    EVENT->Open();
    EVENT->Page = Xila.Display.Get_Current_Page();
    EVENT->Mode = 'F';
    EVENT->Message = Message;
    EVENT->Type = Type;
    EVENT->Button_Text[0] = Button_Text_1;
    EVENT->Button_Text[1] = Button_Text_2;
    EVENT->Button_Text[2] = Button_Text_3;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Event_State == Xila.None)
    {
        EVENT->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.Event_State;
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
Xila_Class::Event Shell_Class::Dialog_Class::Event(const char *Message, uint8_t Type, const char *Button_Text_1, const char *Button_Text_2, const char *Button_Text_3)
{
    Xila.Dialog.Event_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);

    // -- Initalize shell
    EVENT->Open();
    EVENT->Page = Xila.Display.Get_Current_Page();
    EVENT->Mode = 'C';
    EVENT->Message = Message;
    EVENT->Type = Type;
    EVENT->Button_Text[0] = Button_Text_1;
    EVENT->Button_Text[1] = Button_Text_2;
    EVENT->Button_Text[2] = Button_Text_3;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Event_State == Xila.None)
    {
        EVENT->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.Event_State;
}

///
/// @brief Open a loading dialog.
///
/// @param Header Header string.
/// @param Message Message string.
void Shell_Class::Dialog_Class::Load(const __FlashStringHelper *Header, const __FlashStringHelper *Message, uint32_t Duration)
{
    if (Duration > 28000)
    {
        Duration = 28000;
    }
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    // -- Initalize shell
    Load_Pointer->Open();
    Load_Pointer->Page = Xila.Display.Get_Current_Page();
    Load_Pointer->Caller_Software = SHELL;
    Load_Pointer->Header = Header;
    Load_Pointer->Message = Message;
    Load_Pointer->Mode = 'F';
    Load_Pointer->Duration = 0;
    Load_Pointer->Caller_Software = NULL;
    Load_Pointer->Page = 255;
    SHELL->Send_Instruction('R', 'e');
    Xila.Task.Delay(Duration);
}

///
/// @brief Open a Load dialog with an animation (similar to the boot screen).
///
/// @param Header Header string.
/// @param Message Message string.
/// @param Duration Duration in milliseconds (by default 0, the load dialog still displayed until Xila.Dialog.Close_Load() is called).
void Shell_Class::Dialog_Class::Load(const char *Header, const char *Message, uint32_t Duration)
{
    if (Duration > 28000)
    {
        Duration = 28000;
    }
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Initalize shell
    Load_Pointer->Open();
    Load_Pointer->Page = Page;
    Load_Pointer->Caller_Software = SHELL;
    Load_Pointer->Header = Header;
    Load_Pointer->Message = Message;
    Load_Pointer->Mode = 'C';
    Load_Pointer->Duration = 0;
    Load_Pointer->Caller_Software = NULL;
    Load_Pointer->Page = 255;
    SHELL->Send_Instruction('R', 'e');
    Xila.Task.Delay(Duration);
}

void Shell_Class::Dialog_Class::Close_Load()
{
    if (Load_Pointer->State())
    {
        Load_Pointer->Duration = Xila.Time.Milliseconds();
    }
}

///
/// @brief Open a login dialog.
///
/// @return Xila_Class::Event
Xila_Class::Event Shell_Class::Dialog_Class::Login()
{
    Xila.Dialog.Login_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    // -- Maximize shell
    LOGIN->Open(true);
    LOGIN->Page = Xila.Display.Get_Current_Page();
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Login_State == Xila.None)
    {
        LOGIN->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Return dialog result
    return Xila.Dialog.Login_State;
}

///
/// @brief Open a Power management dialog.
///
void Shell_Class::Dialog_Class::Power()
{
    Xila.Dialog.Power_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Maximize shell
    Power_Pointer.Open();
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.Power_State == Xila.None)
    {
        Power_Pointer.Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Display.Set_Current_Page(Page);
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
}

///
/// @brief Open a File Manager dialog to open file.
///
/// @param File_To_Open File to open.
/// @return Xila_Class::Event
Xila_Class::Event Shell_Class::Dialog_Class::Open_File(File &File_To_Open)
{
    Xila.Dialog.File_Manager_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Initalize shell
    FILE_MANAGER->Open(Xila.Dialog_Open_File);
    FILE_MANAGER->Item_Pointer = &File_To_Open;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.File_Manager_State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Display.Set_Current_Page(Page);
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.File_Manager_State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Save_File(File &File_To_Save)
{
    Xila.Dialog.File_Manager_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Initalize shell
    FILE_MANAGER->Open(Xila.Dialog_Save_File);
    FILE_MANAGER->Item_Pointer = &File_To_Save;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.File_Manager_State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Display.Set_Current_Page(Page);
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.File_Manager_State;
}

Xila_Class::Event Shell_Class::Dialog_Class::Open_Folder(File &Folder_To_Open)
{
    Xila.Dialog.File_Manager_State = Xila.None;
    // -- Save context
    Xila.Display.Send_Raw(F("sendme"));
    Xila.Task.Delay(20);
    Xila_Class::Page Page = Xila.Display.Get_Current_Page();
    // -- Initalize shell
    FILE_MANAGER->Open(Xila.Dialog_Open_Folder);
    FILE_MANAGER->Item_Pointer = &Folder_To_Open;
    SHELL->Send_Instruction('R', 'e');
    // -- Tasks suspended here
    while (Xila.Dialog.File_Manager_State == Xila.None)
    {
        FILE_MANAGER->Execute_Instruction(SHELL->Get_Instruction());
        Xila.Task.Delay(20);
    }
    // -- Restore context
    Xila.Display.Set_Current_Page(Page);
    // -- Wait 20 ms to switch page
    Xila.Task.Delay(20);
    // -- Give semaphore back and return dialog result
    return Xila.Dialog.File_Manager_State;
}