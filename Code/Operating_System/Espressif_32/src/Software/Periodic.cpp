#include "Software/Periodic.hpp"

Periodic_Class *Periodic_Class::Instance_Pointer = NULL;

Periodic_Class::Periodic_Class() : Software_Class(Periodic_Handle)
{
    Xila.Task_Create(Main_Task, "Periodic Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Periodic_Class::~Periodic_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Periodic_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Periodic_Class();
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
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case 0: //Idle state
            Xila.Delay(30);
            break;
        case Instruction('C', 'l'):
            Xila.Software_Close(Periodic_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Minimize(Periodic_Handle);
            break;
        case Xila.Maximize:
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Periodic_Main"));
            break;
        case Xila.Close:
            delete Instance_Pointer;
            Xila.Task_Delete();
            break;
        case Xila.Minimize:
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

    Serial.println(Column);
    Serial.println(Line);

    char Line_String[2], Column_String[3];

    Line_String[0] = Line + '0';
    Line_String[1] = '\0';

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

    Verbose_Print_Line("Create filter");

    DynamicJsonDocument Index(256);
    {
        DynamicJsonDocument Filter(256);
        Filter["index"][Line_String][Column_String] = true;

        Periodic_File = Xila.Drive->open(PERIODIC_FILE_PATH);
        memset(Current_Atom_Name, '\0', sizeof(Current_Atom_Name));
        Verbose_Print_Line("Deserialize");

        if (deserializeJson(Index, Periodic_File, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
        {
            Xila.Event_Dialog(F("Failed to open periodic index."), Xila.Error);
            return;
        }
    }

    Verbose_Print_Line("Deserialized");

    Serial.println(Line_String);
    Serial.println(Column_String);

    JsonObject Index_Object = Index.as<JsonObject>();

    JsonObject Line_Object;
    JsonObject Column_Object;

    for (JsonPair Pair : Index_Object)
    {
        Line_Object = Pair.value().as<JsonObject>();
    }

    for (JsonPair Pair : Line_Object)
    {
        Column_Object = Pair.value().as<JsonObject>();
    }

    for (JsonPair Pair : Column_Object)
    {
        strlcpy(Current_Atom_Name, Pair.value().as<char *>(), sizeof(Current_Atom_Name));
    }

    Periodic_File.close();
}

void Periodic_Class::Get_Main_Data()
{
    Get_Atom_Name();

    Serial.println(Current_Atom_Name);

    DynamicJsonDocument Periodic_Registry(256);

    {
        DynamicJsonDocument Filter(256);
        JsonObject Current_Atom_Object = Filter.createNestedObject(Current_Atom_Name);
        Current_Atom_Object["atomic_mass"] = true;
        Current_Atom_Object["category"] = true;
        Current_Atom_Object["symbol"] = true;
        Current_Atom_Object["number"] = true;

        Periodic_File = Xila.Drive->open(PERIODIC_FILE_PATH);
        DynamicJsonDocument Periodic_Registry(256);
        if (deserializeJson(Periodic_Registry, Periodic_File, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
        {
            Xila.Event_Dialog(F("Failed to read element informations."), Xila.Error);
            return;
        }
    }

    Verbose_Print_Line("Deserialized");

    JsonObject Current_Atom_Object;

    for (JsonPair Pair : Periodic_Registry.as<JsonObject>())
    {
        Current_Atom_Object = Pair.value().as<JsonObject>();
        Serial.println(Pair.key().c_str());
    }

    Verbose_Print_Line("Found");

    char Temporary_Char_Array[64];
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    Verbose_Print_Line("Deserialized");

    strlcpy(Temporary_Char_Array, Current_Atom_Object["symbol"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("SYMBOL_TXT"), Temporary_Char_Array);

    Verbose_Print_Line("Deserialized");

    Xila.Display.Set_Value(F("NUMBER_NUM"), Current_Atom_Object["number"].as<long>());

    Verbose_Print_Line("Deserialized");

    Xila.Display.Set_Text(F("NAMEVAL_TXT"), Current_Atom_Name);

    dtostrf(Current_Atom_Object["atomic_mass"].as<double>(), sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);

    Verbose_Print_Line("Deserialized");

    strlcpy(Temporary_Char_Array, Current_Atom_Object["category"], sizeof(Temporary_Char_Array));
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
    dtostrf(Current_Atom["atomic_mass"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);

    // Density
    dtostrf(Current_Atom["density"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " g/cm3", sizeof(Temporary_Char_Array));

    Xila.Display.Set_Text(F("DENSITYVAL_TXT"), Temporary_Char_Array);

    // Melting point
    dtostrf(Current_Atom["melt"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " K", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MELTVAL_TXT"), Temporary_Char_Array);

    // Boiling point
    dtostrf(Current_Atom["boil"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " K", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("BOILINGVAL_TXT"), Temporary_Char_Array);

    // Phase at STP
    strlcpy(Temporary_Char_Array, Current_Atom["phase"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("PHASE_TXT"), Temporary_Char_Array);

    // Electron configuration
    strlcpy(Temporary_Char_Array, Current_Atom["electron_configuration"], sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("ELECTRONCV_TXT"), Temporary_Char_Array);

    // Electronegativity
    dtostrf(Current_Atom["electronegativity_pauling"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    strlcat(Temporary_Char_Array, " (Pauling scale)", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("ELECTRONNV_TXT"), Temporary_Char_Array);

    // Eelectron affinity
    dtostrf(Current_Atom["electron_affinity"], sizeof(Temporary_Char_Array), 4, Temporary_Char_Array);
    Xila.Display.Set_Text(F("ELECTRONAV_TXT"), Temporary_Char_Array);
}

void Periodic_Class::Get_List()
{
}