#include "Software/Periodic.hpp"

Periodic_Class *Periodic_Class::Instance_Pointer = NULL;

Periodic_Class::Periodic_Class() : Software_Class(6)
{
    Xila.Task_Create(Main_Task, "Periodic Task", Memory_Chunk(4), NULL, &Task_Handle);
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
        case Instruction('G', 'M'): //GM
            Instance_Pointer->Get_Main_Data();
            break;
        case Instruction('G', 'L'): //GL
            Instance_Pointer->Get_List();
            break;
        case Instruction('G', 'D'): //GD
            Instance_Pointer->Get_Data();
            break;
        default:
            Serial.println(F("Unknow Socket Method ! "));
            //error handle
            break;
        }
        Xila.Delay(20);
    }
}

void Periodic_Class::Get_Atom_Name()
{
    uint8_t Column, Line;

    Column = (X - 7) / 26;

    Line = (Y - 30) / 26;

    switch (Line)
    {
    case 0:
        if (Column > 0 && Column < 17)
        {
            return;
        }
        break;
    case 1:
    case 2:
        if (Column > 1 && Column < 12)
        {
            return;
        }
        break;
    case 3:
    case 4:
        break;
    case 5:
    case 6:
        if (Column == 2)
        {
            return;
        }
        break;
    case 7:
    case 8:
        if (Column < 3)
        {
            return;
        }
        break;
    }

    char Line_String[2], Column_String[3];

    Line_String[0] = Line + '0';
    if (Column < 10)
    {
        Column_String[0] = Column + '0';
        Column_String[1] = '\0';
        Column_String[2] = '\0';
    }
    else
    {
        Column_String[0] = '1';
        Column_String[1] = (Column % 10) + '0';
        Column_String[2] = '\0';
    }

    DynamicJsonDocument Filter(64);
    JsonObject Line_Object = Filter.createNestedObject(Line_String);
    Line_Object[Column_String] = true;
    DynamicJsonDocument Index(256);
    Periodic_File = Xila.Drive->open(PERIODIC_FILE_PATH);
    memset(Current_Atom_Name, '\0', sizeof(Current_Atom_Name));
    if (deserializeJson(Index, Periodic_File, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
    {
        Xila.Event_Dialog(F("Failed to open periodic index."), Xila.Error);
        return;
    }
    Line_Object = Index[Line_Object];
    strlcpy(Current_Atom_Name, Line_Object[Column_String], sizeof(Current_Atom_Name));
    Periodic_File.close();
}

void Periodic_Class::Get_Main_Data()
{

    DynamicJsonDocument Filter(256);
    JsonObject Current_Atom = Filter.createNestedObject(Current_Atom_Name);
    Current_Atom["atomic_mass"] = true;
    Current_Atom["category"] = true;
    Current_Atom["symbol"] = true;
    Current_Atom["number"] = true;

    Periodic_File = Xila.Drive->open(PERIODIC_FILE_PATH);
    DynamicJsonDocument Periodic_Registry(256);
    if (deserializeJson(Periodic_Registry, Periodic_File, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
    {
        Xila.Event_Dialog(F("Failed to read element informations."), Xila.Error);
        return;
    }

    Current_Atom = Periodic_Registry[Current_Atom_Name];

    char Temporary_Char_Array[64];
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    strlcpy(Temporary_Char_Array, Current_Atom["symbol"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("SYMBOL_TXT"), Temporary_Char_Array);

    Xila.Display.Set_Value(F("NUMBER_NUM"), Current_Atom["number"].as<long>());

    Xila.Display.Set_Text(F("NAMEVAL_TXT"), Current_Atom_Name);

    dtostrf(Current_Atom["atomic_mass"].as<double>(), sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);

    strlcpy(Temporary_Char_Array, Current_Atom["category"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("CATEGORYVAL_TXT"), Temporary_Char_Array);
}

void Periodic_Class::Get_Data()
{
    DynamicJsonDocument Filter(256);
    Filter[Current_Atom_Name] = true;

    DynamicJsonDocument Periodic_Registry(2048);
    if (deserializeJson(Periodic_Registry, Periodic_File, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
    {
        Xila.Event_Dialog(F("Failed to read element informations."), Xila.Error);
        return;
    }

    JsonObject Current_Atom = Periodic_Registry[Current_Atom_Name];

    char Temporary_Char_Array[64];

    /*float Temporary_Float;
    uint32_t Temporary_Long;*/

    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    // -- Symbol
    strlcpy(Temporary_Char_Array, Current_Atom["symbol"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("SYMBOL_TXT"), Temporary_Char_Array);

    // Atom number
    Xila.Display.Set_Value(F("NUMBER_NUM"), Current_Atom["number"].as<long>());

    // Name
    strlcpy(Temporary_Char_Array, Current_Atom["name"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("NAMEVAL_TXT"), Temporary_Char_Array);

    // Category
    strlcpy(Temporary_Char_Array, Current_Atom["category"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("CATEGORYV_TXT"), Temporary_Char_Array);

    // Appearance
    if (Current_Atom["color"] == NULL)
    {
        strlcpy(Temporary_Char_Array, "unknown", sizeof(Temporary_Char_Array));
    }
    else
    {
        strlcpy(Temporary_Char_Array, Current_Atom["color"], sizeof(Temporary_Char_Array));
    }
    Xila.Display.Set_Text(F("APPEARANCE_TXT"), Temporary_Char_Array);

    // Discover
    strlcpy(Temporary_Char_Array, Current_Atom["discovered_by"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("DISCOVERV_TXT"), Temporary_Char_Array);

    // Mass
    strcpy(Temporary_Char_Array, "Mass : ");
    dtostrf(Current_Atom["atomic_mass"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);

    // Density
    dtostrf(Current_Atom["density"], sizeof(Temporary_Char_Array), 4, sizeof(Temporary_Char_Array));
    strlcat(Temporary_Char_Array, " g/cm^3", sizeof(Temporary_Char_Array));
    
    Xila.Display.Set_Text(F("DENSITYVAL_TXT"), Temporary_Char_Array);

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