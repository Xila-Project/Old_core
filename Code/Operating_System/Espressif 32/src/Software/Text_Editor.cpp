#include "Text Editor.hpp"

Text_Editor_Class *Text_Editor_Class::Instance_Pointer = NULL;

Text_Editor_Class::Text_Editor_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Main_Task, "Text Editor Task", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    Execute(Software_Code::Open);
}

Text_Editor_Class::~Text_Editor_Class()
{
}

Software_Class *Text_Editor_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Text_Editor_Class();
    }
    return Instance_Pointer;
}

void Text_Editor_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case 0:
            // IDLE : nothing to do
            Xila.Delay(20);
            break;
        case Software_Code::Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Software_Code::Maximize:
        case Software_Code::Open:
            Xila.Display.Set_Current_Page(F("Text_Editor"));
            break;
        case Software_Code::Minimize:
            break;
        case 0x5355: // SU : scroll up
            Instance_Pointer->Offset += 55;
            Instance_Pointer->Refresh_Text();
            break;
        case 0x5344: // SD : scroll down
            Instance_Pointer->Offset -= 55;
            Instance_Pointer->Refresh_Text();
            break;
        case 0x5254: // RT : refresh text
            Instance_Pointer->Refresh_Text();
            break;
        case 0x4F46: // OF : open file

            break;
        case 0x5346: // SF : Scan file
            Instance_Pointer->Scan();
            break;
        default:
            break;
        }
        Xila.Delay(20);
    }
}

void Text_Editor_Class::Open_File(File File_To_Open)
{
    File_To_Edit = File_To_Open;
    Execute(0x5346);
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
    switch (Type)
    {
    case 'S':
        if (Type == Xila.Variable_Long_Local)
        {
            Offset = *(uint8_t *)Variable; 
            Offset = (Offset * File_To_Edit.size()) / 176;
            Execute('R', 'T');
        }
        break;
    default:
        break;
    }
}

void Text_Editor_Class::Refresh_Text()
{
    File_To_Edit.seek(Offset);
    char Temporary_Character;
    char Temporary_Char_Array[56];
    char Line_Name[11] = "LINE _TXT";
    uint8_t Line_Number = 1;
    uint8_t Column_Number = 0;
    uint8_t Scroll_Bar = (Offset * 176) / File_To_Edit.size();
    char Line_Ending;
    switch (Mode)
    {
    case MacOS:
    case Windows:
        Line_Ending = 0x0D;
        break;
    case Unix:
        Line_Ending = 0x0A;
    default:
        break;
    }
    while (File_To_Edit.available())
    {
        Temporary_Character = File_To_Edit.read();
        if (Temporary_Character == Line_Ending)
        {
            if (Mode == Windows) // skip 0x0A char
            {
                File_To_Edit.read();
            }
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            Line_Number++;
            if (Line_Number > 9)
            {
                strcpy(Line_Name, "LINE1 _TXT");
                Line_Name[5] = (Line_Number % 10) + 48;
            }
            else if (Line_Number > 14)
            {
                break;
            }
            else
            {
                strcpy(Line_Name, "LINE _TXT");
                Line_Name[4] = Line_Number + 48;
            }
            Column_Number == 0;
        }
        else if (Column_Number >= 55)
        {
            Xila.Display.Set_Text(Line_Name, Temporary_Char_Array);
            Line_Number++;
            if (Line_Number > 9)
            {
                strcpy(Line_Name, "LINE1 _TXT");
                Line_Name[5] = (Line_Number % 10) + 48;
            }
            else if (Line_Number > 14)
            {
                break;
            }
            else
            {
                strcpy(Line_Name, "LINE _TXT");
                Line_Name[4] = Line_Number + 48;
            }
            Column_Number == 0;
        }
        else
        {
            Temporary_Char_Array[Column_Number] = Temporary_Character;
            Column_Number++;
        }
    }
}
