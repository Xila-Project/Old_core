#include "file_manager.hpp"
#include "object.hpp"

uint8_t File_Manager_Class::Number_Instance = 0;

File_Manager_Class::File_Manager_Class()
{
    if (Number_Instance > 0)
    {
        delete this;
        //error handle
    }

    ++Number_Instance;

    xTaskCreatePinnedToCore(File_Manager_Socket, "File Manager", 4096, NULL, 2, &Socket_Handle, 1);
}

File_Manager_Class::~File_Manager_Class()
{
    vTaskDelete(Socket_Handle);
}

void File_Manager_Class::Display_Path()
{
    GalaxOS.Get_Variable('P', Temporary_File_Path);
    Temporary_File = SD.open(Temporary_File_Path);
    String Item_Name = "";
    if (Temporary_File)
    {
        if (Temporary_File.isDirectory())
        {
            for (int i = 1; i < 19; i++)
            { //Clear Items
                Item_Name = "ITEM" + String(i);
                Item_Name += "_TXT";
                Nextion_Serial.print(Item_Name);
                Nextion_Serial.print(F(".txt=\"\"\xFF\xFF\xFF"));
                Item_Name = "ITEM" + String(i);
                Item_Name += "_BUT";
                Nextion_Serial.print(Item_Name);
                Nextion_Serial.print(F(".pic=15\xFF\xFF\xFF"));
            }
            Temporary_File.rewindDirectory();
            for (byte i = 1; i < 19; i++)
            {
                File Item = Temporary_File.openNextFile();
                if (!Item)
                    break;
                Item_Name = "ITEM" + String(i);
                Item_Name += "_TXT";
                Nextion_Serial.print(Item_Name);
                Nextion_Serial.print(F(".txt=\""));
                Nextion_Serial.print(Item.name());
                Nextion_Serial.print(F("\"\xFF\xFF\xFF"));
                Item_Name = "ITEM" + String(i);
                Item_Name += "_BUT";
                if (Item.isDirectory())
                {
                    Nextion_Serial.print(Item_Name);
                    Nextion_Serial.print(F(".pic=17\xFF\xFF\xFF"));
                }
                else
                {
                    Nextion_Serial.print(Item_Name);
                    Nextion_Serial.print(F(".pic=16\xFF\xFF\xFF"));
                }
                Item.close();
            }
        }
        else
        {
            Item_Name = Temporary_File.name();
            char Item_Name_Char[14];

            Item_Name.toCharArray(Item_Name_Char, 14);

            for (byte i = 1; i < 15; i++)
            {
                if (Item_Name_Char[i] == '.')
                {
                    Item_Name = String(Item_Name_Char[i + 1]) + String(Item_Name_Char[i + 2]) + String(Item_Name_Char[i + 3]);
                }
            }
            Temporary_File.close();
            if (Item_Name == "WAV")
            {
            }
            else if (Item_Name == "BMP")
            {
            }
            else if (Item_Name == "GPF")
            {
            }
            else if (Item_Name == "FPF")
            {
            }
            else if (Item_Name == "GMF")
            {
                //vTaskResume(GalaxOS.Musical_Digital_Player_Handle);
            }
            else
            {
                //Fileditor();
            }
        }
    }
    else
    {
    }
}

void File_Manager_Class::Delete()
{
    String Temporary_File_Path = "";
    switch (GalaxOS.Event_Handler(WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM))
    {
        case 0:

            break;
        case 'Y': 
            SD.rmdir();
            break;
        case 'N' :
            return;
            break;

        case 'C':
            return;
            break;
        default:
            break;
    }
}

void File_Manager_Class::Execute(uint16_t const &Socket_Method_To_Set)
{
    Socket_Method = Socket_Method_To_Set;
    vTaskResume(Socket_Handle);
}

void File_Manager_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle);
}

void File_Manager_Socket(void *pvParameters)
{
    File_Manager_Class *File_Manager_Pointer = GalaxOS.Get_Software_Pointer();
    (void)pvParameters;
    for (;;)
    {
        switch (File_Manager_Pointer->Socket_Method)
        {
        case 0: //Idle case
            Serial.println(F("Periodic Socket : Nothing to do ..."));
            break;
        case 17488: //DP
            File_Manager_Pointer->Display_Path();
            break;
        default:
            Serial.println(F("Unknow Socket Method !"));
            //error handle
            break;
        }
        File_Manager_Pointer->Socket_Method = 0; //work done, reset the selector
        vTaskSuspend(NULL);
    }
}