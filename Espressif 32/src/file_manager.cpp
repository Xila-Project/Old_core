#include "File_Manager.hpp"

#define INSTANCE_POINTER File_Manager_Class::Instance_Pointer

File_Manager_Class* File_Manager_Class::Instance_Pointer = NULL;

File_Manager_Class::File_Manager_Class(Software_Handle_Class *Software_Handle_To_Set) : Software_Class(Software_Handle_To_Set)
{
    if (Instance_Pointer == NULL)
    {
        delete this;
        //error handle
    }
    Instance_Pointer == this;

    xTaskCreatePinnedToCore(File_Manager_Task, "File Manager", 4 * 1024, NULL, 2, &Task_Handle, 1);
}

File_Manager_Class::~File_Manager_Class()
{
    Execute(0x0043);
    vTaskDelete(Task_Handle);

    Instance_Pointer == NULL;
}

Software_Class *File_Manager_Class::Load(Software_Handle_Class *Software_Handle_To_Set)
{
    if (Instance_Pointer != NULL)
    {
        return Instance_Pointer;
    }
    return new Internet_Browser_Class(Software_Handle_To_Set);
}

void File_Manager_Class::Display_Path()
{
    GalaxOS.Get_Variable('P', Current_File_Path);
    Temporary_File = SD_MMC.open(Current_File_Path);
    String Temporary_String;
    if (Temporary_File)
    {
        if (Temporary_File.isDirectory())
        {
            Temporary_File.rewindDirectory();
            GalaxOS.Display.Set_Text("PATH_TXT", Current_File_Path);
            File Item;
            for (byte i = 1; i < 33; i++)
            {
                Item = Temporary_File.openNextFile();
                if (Item)
                {
                    GalaxOS.Display.Set_Text("ITEM" + String(i) + "_TXT", Item.name());
                    if (Item.isDirectory())
                    {
                        GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 17);
                    }
                    else
                    {
                        GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 16);
                    }
                }
                else
                {
                    GalaxOS.Display.Set_Text("ITEM" + String(i) + "_TXT", "");
                    GalaxOS.Display.Set_Picture("ITEM" + String(i) + "_PIC", 15);
                }

                Item.close();
            }
        }
        else
        {
            GalaxOS.Open_File(SD_MMC.open(Current_File_Path));
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
    byte i = strlen(Current_File_Path);
    while (Current_File_Path[i] != 0x2F || i >= 0)
    {
        Current_File_Path[i] == NULL;
        i--;
    }
    Display_Path();
}

void File_Manager_Class::Rename()
{
    
}

void File_Manager_Class::New()
{
    for (uint8_t i = 1; i < 10; i++)
    {
        if (!SD_MMC.exists(Current_File_Path + "/NEWFILE" + String(i) + ".TXT"))
        {
            SD_MMC.open(Current_File_Path + "/NEWFILE" + String(i) + ".TXT");
            break;
        }
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
        SD_MMC.remove(Current_File_Path);
        //fs.rmdir();
        break;
    case 'N':
        return;
        break;

    case 'C':
        return;
        break;
    default:
        break;
    }
}

void File_Manager_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        while (INSTANCE_POINTER->Read_Position == INSTANCE_POINTER->Write_Poisiton)
        {
            vTaskDelay(pdMS_TO_TICKS(20));
        }
        switch (INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position])
        {
        case NULL: //Idle case
            Serial.println(F("Periodic Socket : Nothing to do ..."));
            break;
        case 17488: //DP
            INSTANCE_POINTER->Display_Path();
            break;
        default:
            Serial.println(F("Unknow Socket Method !"));
            //error handle
            break;
        }
        INSTANCE_POINTER->Task_Method_Array[INSTANCE_POINTER->Read_Position] = NULL;
        INSTANCE_POINTER->Read_Position++;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}