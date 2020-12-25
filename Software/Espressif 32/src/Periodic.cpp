#include "periodic.hpp"

Periodic_Class *Periodic_Class::Instance_Pointer = NULL;

Periodic_Class::Periodic_Class() : Software_Class(6)
{
    xTaskCreatePinnedToCore(Main_Task, "Periodic", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
}

Periodic_Class::~Periodic_Class()
{
    Instance_Pointer = NULL;
}

Software_Class *Periodic_Class::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Periodic_Class;
    }
    return Instance_Pointer;
}

void Periodic_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    switch (Adress)
    {
    case 'X':
        X = *(uint32_t *)Variable;
        break;
    case 'Y':
        Y = *(uint32_t *)Variable;
        break;
    default:
        break;
    }
}

void Periodic_Class::Main_Task(void *pvParamters)
{
    (void)pvParamters;
    Instance_Pointer->Periodic_File = Xila.Drive->open("/SOFTWARE/PERIODIC/PERIODIC.GRF");
    for (;;)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case 0: //Idle state
            Serial.println(F("Periodic Socket : Nothing to do ..."));
            break;
        case 18253: //GM
            Instance_Pointer->Get_Main_Data();
            break;
        case 18252: //GL
            Instance_Pointer->Get_List();
            break;
        case 18244: //GD
            Instance_Pointer->Get_Data();
            break;
        default:
            Serial.println(F("Unknow Socket Method ! "));
            //error handle
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void Periodic_Class::Get_Main_Data()
{
    float Column, Line;

    Column = (float)X;
    Column += 8;
    Column /= 26;
    Column = round(Column);
    Line = (float)Y;
    Line -= 16;
    Line /= 26;
    Line = round(Line);
    Verbose_Print("> Column :");
    Serial.println(Column);
    Verbose_Print("> Line :");
    Serial.println(Line);
    if (Line == 1)
    {
        Current_Atom = 3;
        Column -= 16;
    }
    else if (Line < 4)
    {
        Current_Atom = 9;
        Column -= 10;
    }
    else if (Line < 6)
    {
        Current_Atom = 19;
    }
    else if (Line < 8)
    {
        Current_Atom = 33;
        Column -= 1;
    }
    else if (Line < 10)
    {
        Current_Atom = 16;
        Column -= 3;
    }
    Current_Atom -= Column;
}

void Periodic_Class::Get_Data()
{
    DynamicJsonDocument Element_Filter(256);
    Element_Filter[Name] = true;
    DynamicJsonDocument Periodic_Register(1536);
    deserializeJson(Periodic_Register, Periodic_File);
    char Temporary_Char_Array[61];

    strcpy(Temporary_Char_Array, Periodic_Register[Name]["symbol"]);
    Xila.Display.Set_Text(F("SYMBOL_TXT"), Temporary_Char_Array);

    itoa(Periodic_Register[Name]["number"], Temporary_Char_Array, 10);
    Xila.Display.Set_Text(F("NUMBER_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Name : ");
    strcpy(Temporary_Char_Array + sizeof("Name : "), Periodic_Register[Name]["name"]);
    Xila.Display.Set_Text(F("NAME_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Category : ");
    strcpy(Temporary_Char_Array + sizeof("Category : "), Periodic_Register[Name]["category"]);
    Xila.Display.Set_Text(F("CATEGORY_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Apperance : ");
    if (Periodic_Register[Name]["color"] == NULL)
    {
        strcpy(Temporary_Char_Array + sizeof("Apperance : "), "unknown");
    }
    else
    {
        strcpy(Temporary_Char_Array + sizeof("Apperance : "), Periodic_Register[Name]["color"]);
    }
    Xila.Display.Set_Text(F("APPEARANCE_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Discover : ");
    strcpy(Temporary_Char_Array + sizeof("Discover : "), Periodic_Register[Name]["discovered_by"]);
    Xila.Display.Set_Text(F("DISCOVER_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Mass : ");
    itoa(Periodic_Register[Name]["atomic_mass"], Temporary_Char_Array + sizeof("Mass : "), 10);
    Xila.Display.Set_Text(F("MASS_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Density : ");
    itoa(Periodic_Register[Name]["density"], Temporary_Char_Array + sizeof("Density : "), 10);
    Xila.Display.Set_Text(F("DENSITY_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Melting point : ");
    itoa(Periodic_Register[Name]["melt"], Temporary_Char_Array + sizeof("Melting point : "), 10);
    Xila.Display.Set_Text(F("MELT_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Boiling point : ");
    itoa(Periodic_Register[Name]["boil"], Temporary_Char_Array + sizeof("Boiling point : "), 10);
    Xila.Display.Set_Text(F("NAME_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Phase At S.T.P. : ");
    strcpy(Temporary_Char_Array + sizeof("Phase At S.T.P. : "), Periodic_Register[Name]["phase"]);
    Xila.Display.Set_Text(F("PHASE_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Electron configuration : ");
    strcpy(Temporary_Char_Array + sizeof("Electron configuration : "), Periodic_Register[Name]["electron_configuration"]);
    Xila.Display.Set_Text(F("ELECTRONC_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Electronegativity : ");
    itoa(Periodic_Register[Name]["electronegativity_pauling"], Temporary_Char_Array + sizeof("Electronegativity : "), 10);
    Xila.Display.Set_Text(F("ELECTRONN_TXT"), Temporary_Char_Array);

    strcpy(Temporary_Char_Array, "Electron affinity : ");
    itoa(Periodic_Register[Name]["electron_affinity"], Temporary_Char_Array + sizeof("Electron affinity"), 10);
    Xila.Display.Set_Text(F("DISCOVER_TXT"), Temporary_Char_Array);
}

void Periodic_Class::Get_List()
{
}