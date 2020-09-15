#include "Shell.hpp"

Shell_Class *Instance_Pointer = NULL;

Shell_Class::Shell_Class(Software_Handle_Class *Software_Handle_Pointer) : Software_Class(Software_Handle_Pointer, 6)
{

    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
}

Shell_Class::~Shell_Class() : ~Software_Class()
{
}

Software_Class* Shell_Class::Load(Software_Handle_Class* Software_Handle_Pointer)
{
    return new Shell_Class(Software_Handle_Pointer);
}

void Shell_Task(void* pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Shell_Class::Instance_Pointer->Task_Method)
        {
        case 0: //default
            //Nothing to do : idle
            break;
        case 0x4F44: //OD
            Shell_Class::Instance_Pointer->Open_Desk();
            break;
        case 0x4F4D: //OM
            Shell_Class::Instance_Pointer->Open_Menu();
            break;
        case 0x4F49: //OI
            Shell_Class::Instance_Pointer->Open_Item();
            break;
        default:
            break;
        }
        Shell_Class::Instance_Pointer->Task_Method = 0;
        vTaskSuspend(NULL);
    }
}

void Shell_Class::Open_Desk()
{
    GalaxOS.Display.Set_Current_Page(Page_Desk);
    char Temporary_String[] = "SLOT _PIC";

    for (uint8_t Slot = 0; Slot < 6; Slot++)
    {
        Temporary_String[4] = Slot;
        for (uint8_t Item = 0; Item < 6; Item++)
        {
            if (GalaxOS.Software_Pointer[Item] != NULL)
            {
                GalaxOS.Display.Set_Picture(Temporary_String, GalaxOS.Software_Pointer[Item]->Handle_Pointer->Icon);
            }
            else
            {
                GalaxOS.Display.Set_Picture(Temporary_String, 39); //if there's
            }
        }
    }

    delete Temporary_String;
}

void Shell_Class::Open_Menu()
{
    GalaxOS.Display.Set_Current_Page(Page_Menu);
    GalaxOS.Display.Set_Text(F("USERNAME_TXT"), GalaxOS.Get_Current_Username());
}

void Shell_Class::Open_Item()
{
    char Software_Name[24];
    GalaxOS.Get_Variable('S', Software_Name);
    GalaxOS.Open_Software(Software_Name);
}

void Shell_Class::Login()
{
    GalaxOS.Load_User_Files();
}