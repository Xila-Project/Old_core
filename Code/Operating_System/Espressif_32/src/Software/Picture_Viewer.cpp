#include "Software/Picture_Viewer.hpp"

Image_Viewer_Class *Image_Viewer_Class::Instance_Pointer = NULL;

Image_Viewer_Class::Image_Viewer_Class() : Software_Class(Image_Viewer_Handle)
{
    Xila.Task.Create(Main_Task, "Picture viewer", Memory_Chunk(5), NULL, &Task_Handle);
}

Image_Viewer_Class::~Image_Viewer_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
    Image_File.close();
}

Software_Class* Image_Viewer_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Image_Viewer_Class();
    return Instance_Pointer;
}

void Image_Viewer_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case Idle:
            Xila.Task.Delay(30);
            break;
        case Open:
            Xila.Display.Set_Current_Page(F("Pictviewer"));
            break;
        case Close:
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Maximize:
            Xila.Display.Set_Current_Page(F("Pictviewer"));
            Instance_Pointer->Send_Instruction('D', 'I');
            break;
        case Minimize:
            break;

        case Instruction('C', 'l'):
            Xila.Software.Close(Image_Viewer_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software.Minimize(Image_Viewer_Handle);
            break;
        case Instruction('O', 'I'):
            Xila.Dialog.Open_File(Instance_Pointer->Image_File);
            if (!Instance_Pointer->Image_File)
            {
                Verbose_Print_Line("Failed to open file.");
            }
            Instance_Pointer->Send_Instruction(Instruction('D', 'I'));
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
        Xila.Task.Delay(20);
    }
}

void Image_Viewer_Class::Get_Metadata()
{
    Image_File.seek(0x00);
    uint8_t Temporary_Char_Array_1[4] = {'B', 'M'};
    uint8_t Temporary_Char_Array_2[4];
    Image_File.read(Temporary_Char_Array_2, 2);

    if (memcmp(Temporary_Char_Array_1, Temporary_Char_Array_2, 2) != 0)
    {
        Xila.Dialog.Event(F("Corrupted bitmap file."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Pictviewer"));
    }

    // File size
    Image_File.seek(0x02);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Size = (size_t)Temporary_Char_Array_2[0] | ((size_t)Temporary_Char_Array_2[1] << 8) | ((size_t)Temporary_Char_Array_2[2] << 16) | ((size_t)Temporary_Char_Array_2[3] << 24);
    Serial.println(Size);

    // Start offset
    Image_File.seek(0x0A);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Offset = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] << 8 | (size_t)Temporary_Char_Array_2[2] << 16 | (size_t)Temporary_Char_Array_2[3] << 24;
    Serial.println(Offset);

    // Header size
    Image_File.seek(0x0E);
    Image_File.read(Temporary_Char_Array_2, sizeof(Temporary_Char_Array_2));
    Header_Size = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] << 8 | (size_t)Temporary_Char_Array_2[2] << 16 | (size_t)Temporary_Char_Array_2[3] << 24;
    Serial.println(Header_Size);

    // Width
    Image_File.seek(0x12);
    Image_File.read(Temporary_Char_Array_2, 4);
    Width = (uint16_t)Temporary_Char_Array_2[0] | (uint16_t)Temporary_Char_Array_2[1] << 8;
    Serial.println(Width);

    // Height
    Image_File.seek(0x16);
    Image_File.read(Temporary_Char_Array_2, 2);
    Height = (uint16_t)Temporary_Char_Array_2[0] | (uint16_t)Temporary_Char_Array_2[1] << 8;
    Serial.println(Height);

    // Color planes
    Image_File.seek(0x1A);
    Image_File.read(Temporary_Char_Array_2, 2);
    Color_Planes = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] << 8;
    Serial.println(Color_Planes);

    // Color depth
    Image_File.seek(0x1C);
    Image_File.read(Temporary_Char_Array_2, 2);
    Color_Depth = (size_t)Temporary_Char_Array_2[0] | (size_t)Temporary_Char_Array_2[1] << 8;
    Serial.println(Color_Depth);
}

void Image_Viewer_Class::Draw_Image()
{
    Xila.Task.Delay(20);
    Image_File.seek(Offset);
    Xila.Display.Set_Text(F("FILENAME_TXT"), Image_File.name());
    Xila.Display.Set_Value(F("WIDTH_VAR"), Width);
    Xila.Display.Set_Value(F("HEIGHT_VAR"), Height);
    Xila.Display.Set_Value(F("SIZE_NUM"), Size);
    Xila.Display.Set_Trigger(F("DRAW_TIM"), true);

    Xila.Task.Delay(20);
//    uint16_t Red, Green, Blue;

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

        Color[0] = 0xF8;
        Color[1] = 0x00;

        for (uint8_t i = 0; i < 255; i++)
        {
            Xila.Display.Write(Color[0]);
            Xila.Display.Write(Color[1]);
        }

    /*
        while (Image_File.available())
        {
            Image_File.readBytes(Temporary_Char_Array, sizeof(Temporary_Char_Array));

            Blue = (Temporary_Char_Array[0] >> 3) & 0x1F;
            Green = ((Temporary_Char_Array[1] >> 2) & 0x3F) << 5;
            Red = ((Temporary_Char_Array[2] >> 3) & 0x1F) << 11;

            memcpy(Color, &(uint16_t)Blue | Green | Red, sizeof(Color));

            Color[0] = Temporary_Char_Array[0] >> 3 & 0x1F; // blue
            
            Color[0] |= Color[0] << 3 | Temporary_Char_Array[1] >> 5;
            Color[1] = Temporary_Char_Array[1] >> 2;
            Color[1] |= Color[0] << 2 | Temporary_Char_Array[2] >> 3;
            Xila.Display.Write(Color[0]);
            Xila.Display.Write(Color[1]);
            Serial.println(Color[0])
        }*/

        Xila.Task.Delay(1000);
        Xila.Display.Set_Reparse_Mode(0);
    }
    else
    {
        Xila.Display.Set_Reparse_Mode(0);
        Xila.Dialog.Event(F("Unsupported bitmap file."), Xila.Error);
        Xila.Display.Set_Current_Page(F("Pictviewer"));
    }
}
