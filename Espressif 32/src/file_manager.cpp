#include "file_manager.hpp"
#include "galaxos.hpp"

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
    --Number_Instance;
}

void File_Manager_Class::Display_Path()
{
    GalaxOS.Get_Variable('P', Current_File_Path);
    Temporary_File = SD.open(Current_File_Path);
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
            GalaxOS.Open_File(Current_File_Path);
            Temporary_File.close();
            Go_Parent();
        
        }
    }
    else
    {
        //error handle
    }
}

void File_Manager_Class::Go_Parent() //Set Current_File_Path to the parent folder
{
    byte ii = 0;
    for (byte i = Current_File_Path.length(); i >= 0; i--)
    {
        if (Current_File_Path.charAt(i) == 0x2F) //try to find the last 
        {
            ++ii;
        }
    }
    Display_Path();
}

void File_Manager_Class::Delete()
{
    String Temporary_File_Path = "";
    switch (GalaxOS.Event_Handler(WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM))
    {
        case 0:

            break;
        case 'Y': 
            //fs.rmdir();
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
    File_Manager_Class *File_Manager_Pointer;
    GalaxOS.Get_Software_Pointer(File_Manager_Pointer);
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