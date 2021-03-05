#include "Software/Picture_Viewer.hpp"

Picture_Viewer_Class *Picture_Viewer_Class::Instance_Pointer = NULL;

Picture_Viewer_Class::Picture_Viewer_Class() : Software_Class(Picture_Viewer_Handle)
{

}

Picture_Viewer_Class::~Picture_Viewer_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Image_File.close();
}

Software_Class* Picture_Viewer_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Picture_Viewer_Class();
    return Instance_Pointer;
}

void Picture_Viewer_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case 0:
            Xila.Delay(30);
            break;
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Pictviewer"));
            break;
        case Xila.Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Pictviewer"));
            Instance_Pointer->Send_Instruction(Instruction('D', 'I'));
            break;
        case Xila.Minimize:
            vTaskSuspend(NULL);
            break;
        case Instruction('C', 'l'):
            Xila.Software_Close(Picture_Viewer_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Minimize(Picture_Viewer_Handle);
            break;
        case Instruction('O', 'I'):
            Xila.Open_File_Dialog(Instance_Pointer->Image_File);
            Instance_Pointer->Send_Instruction('D', 'I');
            break;
        case Instruction('D', 'I'):
            if (!Instance_Pointer->Image_File)
            {
                break;
            }
            Instance_Pointer->Get_Metadata();
            Instance_Pointer->Draw_Image();
            break;
        default:

            break;
        }
        Xila.Delay(20);
    }
}

void Picture_Viewer_Class::Get_Metadata()
{
    Image_File.seek(0x00);
    uint8_t Temporary_Char_Array_1[4] = {'B', 'M'};
    uint8_t Temporary_Char_Array_2[4];
    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 2) != 0)
    {
        Xila.Event_Dialog(F("Corrupted bitmap file."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Pictviewer"));
    }

    // File size
    Image_File.seek(0x04);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Size = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] | (size_t)Temporary_Char_Array_2[2] | (size_t)Temporary_Char_Array_2[3];

    // Start offset
    Image_File.seek(0x0A);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Offset = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] | (size_t)Temporary_Char_Array_2[2] | (size_t)Temporary_Char_Array_2[3];

    // Header size
    Image_File.seek(0x0E);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Header_Size = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] | (size_t)Temporary_Char_Array_2[2] | (size_t)Temporary_Char_Array_2[3];

    // Width
    Image_File.seek(0x12);
    Image_File.read(Temporary_Char_Array_2, 2);
    Width = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1];

    // Height
    Image_File.seek(0x14);
    Image_File.read(Temporary_Char_Array_2, 2);
    Height = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1];

    // Color planes
    Image_File.seek(0x16);
    Image_File.read(Temporary_Char_Array_2, 2);
    Color_Planes = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1];

    // Color depth
    Image_File.seek(0x18);
    Image_File.read(Temporary_Char_Array_2, 2);
    Color_Depth = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1];
}

void Picture_Viewer_Class::Draw_Image()
{
    Image_File.seek(Offset);
    Xila.Display.Set_Text(F("FILENAME_TXT"), Image_File.name());
    Xila.Display.Set_Value(F("WIDTH_VAR"), Width);
    Xila.Display.Set_Value(F("HEIGHT_VAR"), Height);
    Xila.Display.Set_Value(F("SIZE_NUM"), (Size / 1024));
    Xila.Display.Set_Trigger(F("DRAW_TIM"), true);
    if (Color_Depth == 1)
    {
        while (Image_File.available())
        {
            uint8_t Temporary_Byte;
            Temporary_Byte = Image_File.read();
            for (uint8_t i = 7; i > 0; i--)
            {
                if (bitRead(Temporary_Byte, i) == 0)
                {
                    Xila.Display.Write(255);
                    Xila.Display.Write(255);
                }
                else
                {
                    Xila.Display.Write(0);
                    Xila.Display.Write(0);
                }
            }
        }
        Xila.Display.Set_Reparse_Mode(0);
    }
    else if (Color_Depth == 16)
    {
        while (Image_File.available())
        {
            Image_File.readBytes(Color, 2);
            Xila.Display.Write(Color[0]);
            Xila.Display.Write(Color[1]);
        }
        Xila.Display.Set_Reparse_Mode(0);
    }
    else if (Color_Depth == 24)
    {
        char Temporary_Char_Array[3];
        while (Image_File.available())
        {
            Image_File.readBytes(Temporary_Char_Array, sizeof(Temporary_Char_Array));
            Color[0] = Temporary_Char_Array[0] >> 3;
            Color[0] |= Color[0] << 3 | Temporary_Char_Array[1] >> 5;
            Color[1] = Temporary_Char_Array[1] >> 2;
            Color[1] |= Color[0] << 2 | Temporary_Char_Array[2] >> 3;
            Xila.Display.Write(Color[0]);
            Xila.Display.Write(Color[1]);
        }
        Xila.Display.Set_Reparse_Mode(0);
    }
    else
    {
        Xila.Display.Set_Reparse_Mode(0);
        Xila.Event_Dialog(F("Unsupported bitmap file."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Pictviewer"));
    }
}
