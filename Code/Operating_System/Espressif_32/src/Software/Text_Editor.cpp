#include "Software/Text Editor.hpp"

Text_Editor_Class *Text_Editor_Class::Instance_Pointer = NULL;

Text_Editor_Class::Text_Editor_Class() : Software_Class(Text_Editor_Handle)
{
    Xila.Task_Create(Main_Task, "Text Editor Task", 4 * 1024, NULL, &Task_Handle);
    Send_Instruction(Xila.Open);
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

void Text_Editor_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case 0:
            // IDLE : nothing to do
            Xila.Delay(20);
            break;
        case Xila.Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Xila.Maximize:
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Text_Editor"));
            break;
        case Xila.Minimize:
            break;
        case Instruction('C', 'l'):
            Xila.Software_Close(Text_Editor_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Minimize(Text_Editor_Handle);
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('S', 'U'): // SU : scroll up
            Instance_Pointer->Offset += 55;
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('S', 'D'): // SD : scroll down
            Instance_Pointer->Offset -= 55;
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('R', 'T'): // RT : refresh text
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('O', 'F'): // OF : open file
            Instance_Pointer->File_To_Edit.close();
            Instance_Pointer->Scan();
            Xila.Open_File_Dialog(Instance_Pointer->File_To_Edit);
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
}

void Text_Editor_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Adress)
    {
    case 'S':
        if (Type == Xila.Variable_Long_Local)
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

void Text_Editor_Class::Refresh_Interface()
{
    if (!File_To_Edit)
    {
        Xila.Event_Dialog(F("Failed to read file."), Xila.Error);
        return;
    }
    File_To_Edit.seek(Offset);
    char Temporary_Character;
    char Temporary_Char_Array[56];

    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    char Line_Name[11] = "LINE01_TXT";
    uint8_t Line_Number = 1;
    uint8_t Column_Number = 0;
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

        if (Line_Number > 15)
        {
            break;
        }
        Serial.write(Temporary_Character);

        if (Temporary_Character == Line_Ending)
        {
            if (Mode == Windows) // skip 0x0A char
            {
                File_To_Edit.read();
            }
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
            Xila.Delay(10);
            Line_Number++;
            Column_Number = 0;
            sprintf(Line_Name, "LINE%02i_TXT", Line_Number);   
        }
        else if (Column_Number >= 55)
        {
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
            Xila.Delay(10);
            Line_Number++;
            Column_Number = 0;
            sprintf(Line_Name, "LINE%02i_TXT", Line_Number);
        }
        else
        {
            Temporary_Char_Array[Column_Number++] = Temporary_Character;
        }
    }
}
