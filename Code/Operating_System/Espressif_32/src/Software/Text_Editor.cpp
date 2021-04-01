#include "Software/Text Editor.hpp"

Text_Editor_Class *Text_Editor_Class::Instance_Pointer = NULL;

Text_Editor_Class::Text_Editor_Class() : Software_Class(Text_Editor_Handle)
{
    Xila.Task.Create(Main_Task, "Text Editor Task", 4 * 1024, NULL, &Task_Handle);
    Send_Instruction(Open);
}

Text_Editor_Class::~Text_Editor_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Text_Editor_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Text_Editor_Class();
    return Instance_Pointer;
}

void Text_Editor_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Adress)
    {
    case 'S':
        if (Type == Xila.Display.Variable_Long)
        {
            Offset = *(uint8_t *)Variable;
            Offset = (Offset * File_To_Edit.size()) / 176;
            Send_Instruction('R', 'T');
        }
        break;
    default:
        break;
    }
}

void Text_Editor_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case Idle:
            // IDLE : nothing to do
            if (Xila.Software.Get_State(Text_Editor_Handle) == Minimized)
            {
                Xila.Task.Delay(90);
            }
            Xila.Task.Delay(20);
            break;
        case Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Maximize:
            Xila.Display.Set_Current_Page(F("Text_Editor"));
            Instance_Pointer->Refresh_Interface();
            break;
        case Open:
            Xila.Display.Set_Current_Page(F("Text_Editor"));
            break;
        case Minimize:
            break;
        case Instruction('C', 'l'):
            Xila.Software.Close(Text_Editor_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software.Minimize(Text_Editor_Handle);
            break;
        case Instruction('R', 'T'): // RT : refresh text
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('O', 'F'): // OF : open file
            Instance_Pointer->File_To_Edit.close();
            Xila.Dialog.Open_File(Instance_Pointer->File_To_Edit);
            Instance_Pointer->Scan();
            Instance_Pointer->Refresh_Interface();

            break;
        case Instruction('S', 'F'): // SF : Scan file
            Instance_Pointer->Scan();
            break;
        default:
            break;
        }
    }
}

void Text_Editor_Class::Scan()
{
    if (!File_To_Edit)
    {
        Xila.Dialog.Event(F("Failed to read file."), Xila.Error);
        return;
    }

    Offset = 0;
    if (File_To_Edit.find(0x0D))
    {
        if (File_To_Edit.read() == 0x0A)
        {
            Mode = Windows;
        }
        else
        {
            Mode = MacOS;
        }
    }
    else if (File_To_Edit.find(0x0A))
    {
        Mode = Unix;
    }
    else
    {
        Mode = Undefined;
    }
    Serial.println(Mode, HEX);
}

void Text_Editor_Class::Refresh_Interface()
{
    char Line_Name[11] = "LINE _TXT";
    uint8_t Line_Number = 0;

    if (!File_To_Edit)
    {
        Xila.Display.Set_Value(F("SCROLLBAR_SLI"), 0);
        Xila.Display.Set_Text(F("FILENAME_TXT"), "");
        for (; Line_Number < 14; Line_Number++)
        {
            Line_Name[4] = '0' + Line_Number;
            Xila.Display.Set_Text(Line_Name, "");
        }
        return;
    }

    File_To_Edit.seek(Offset);
    char Temporary_Character;
    char Temporary_Char_Array[114]; // double to allow 
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    Xila.Drive.Get_Name(File_To_Edit, Temporary_Char_Array, sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_Char_Array);

    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    uint8_t Column_Number = 0;
    uint8_t Column_Position = 0;
    char Line_Ending = 0x0D;

    switch (Mode)
    {
    case MacOS:
    case Windows:
        Line_Ending = 0x0D;
        break;
    case Unix:
        Line_Ending = 0x0A;
        break;
    }

    while (File_To_Edit.available())
    {
        Temporary_Character = File_To_Edit.read();

        if (Line_Number > 14)
        {
            Verbose_Print_Line("Max line");
            break;
        }
        Serial.write(Temporary_Character);

        if (Temporary_Character == Line_Ending)
        {

            if (Mode == Windows) // skip 0x0A char
            {
                File_To_Edit.read();
            }
            Xila.Task.Delay(5);

            Line_Name[4] = 'A' + Line_Number;
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
            Line_Number++;
            Column_Number = 0;
            Column_Position = 0;
        }
        else if (Column_Number >= 55)
        {
            Xila.Task.Delay(5);
            Line_Name[4] = 'A' + Line_Number;
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
            Line_Number++;
            Column_Number = 0;
            Column_Position = 0;
        }
        else
        {
            if (Temporary_Character == '\"')
            {
                Temporary_Char_Array[Column_Position++] = '\\';
                Temporary_Char_Array[Column_Position++] = '\"';
                Column_Number++;
            }
            else if (Temporary_Character == '\\')
            {
                Temporary_Char_Array[Column_Position++] = '\\';
                Temporary_Char_Array[Column_Position++] = '\\';
                Column_Number++;
            }
            else if (isPrintable(Temporary_Character))
            {
                Temporary_Char_Array[Column_Position++] = Temporary_Character;
                Column_Number++;
            }
            /*else
            {
                Temporary_Char_Array[Column_Position++] = Xila.Display.State_Button;
                Column_Number++;
            }*/
        }
    }
}
