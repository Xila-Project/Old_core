#include "Software/Periodic.hpp"

Periodic_Class *Periodic_Class::Instance_Pointer = NULL;

Periodic_Class::Periodic_Class()
    : Xila_Class::Software(Periodic_Handle),
      X(7),
      Y(30)
{
    Xila.Task.Create(Main_Task, "Periodic Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Periodic_Class::~Periodic_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Xila_Class::Software *Periodic_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Periodic_Class();
    return Instance_Pointer;
}

void Periodic_Class::Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable)
{
    switch (Address)
    {
    case Address('X', 'C'):
        X = *(uint32_t *)Variable;
        break;
    case Address('Y', 'C'):
        Y = *(uint32_t *)Variable;
        break;
    default:
        break;
    }
}

void Periodic_Class::Main_Task(void *pvParamters)
{
    (void)pvParamters;
    Xila.Task.Delay(10);
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case Xila.Idle: //Xila.Idle state
            if (Xila.Software_Management.Get_State(Periodic_Handle) == Xila.Minimized)
            {
                Xila.Task.Delay(90);
            }
            Xila.Task.Delay(10);
            break;
        case Xila.Hibernate:
        case Xila.Shutdown:
        case Xila.Restart:
        case Instruction('C', 'l'):
            Xila.Software_Management.Close(Periodic_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Management.Minimize(Periodic_Handle);
            break;
        case Xila.Maximize:
            if (Instance_Pointer->Tab == 0)
            {
                Xila.Display.Set_Current_Page(F("Periodic_Main"));
                Instance_Pointer->Get_Main_Data();
            }
            else
            {
                Xila.Display.Set_Current_Page(F("Periodic_Data"));
                Instance_Pointer->Get_Data();
            }
            break;
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Periodic_Main"));
            Instance_Pointer->Tab = 0;
            Instance_Pointer->Send_Instruction('G', 'M');
            break;
        case Xila.Close:
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Xila.Minimize:
            break;
        case Instruction('G', 'M'): //GM
            Instance_Pointer->Get_Atom_Name();
            Instance_Pointer->Get_Main_Data();
            break;
        case Instruction('G', 'D'): //GD
            Instance_Pointer->Tab = 1;
            Instance_Pointer->Get_Data();
            break;
        case Instruction('B', 'a'):
            Xila.Display.Set_Current_Page(F("Periodic_Main"));
            Instance_Pointer->Tab = 0;
            Instance_Pointer->Get_Main_Data();
            break;
        default:
            break;
        }
    }
}

void Periodic_Class::Get_Atom_Name()
{
    uint8_t Column;

    Column = (X - 7) / 26;

    Line = (Y - 30) / 26;

    switch (Line)
    {
    case 0:
        if (Column > 0 && Column < 17)
        {
            Current_Atom_Name[0] = 0xFF;
            return;
        }
        break;
    case 1:
    case 2:
        if (Column > 1 && Column < 12)
        {
            Current_Atom_Name[0] = 0xFF;
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
            Current_Atom_Name[0] = 0xFF;
            return;
        }
        break;
    case 7:
    case 8:
        if (Column < 3)
        {
            Current_Atom_Name[0] = 0xFF;
            return;
        }
        break;
    }
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

    DynamicJsonDocument Index(256);

    {
        // -- Create a filter
        DynamicJsonDocument Filter(256);
        Filter[Line_String][Column_String] = true;
        // -- Open file and initlize the buffer
        Periodic_File = Xila.Drive.Open(Periodic_File("Index.xdf"));
        ReadBufferingStream Periodic_File_Buffer(Periodic_File, 256);
        // -- Deserialize file
        if (deserializeJson(Index, Periodic_File_Buffer, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
        {
            // -- Show an error and return if periodic index is corrupted
            Xila.Dialog.Event(F("Failed to open periodic index."), Xila.Error);
            return;
        }
    }
    // -- Browse the index
    JsonObject Index_Object = Index.as<JsonObject>();
    JsonObject Line_Object;
    memset(Current_Atom_Name, '\0', sizeof(Current_Atom_Name));
    for (JsonPair Pair : Index_Object)
    {
        Line_Object = Pair.value().as<JsonObject>();
    }
    for (JsonPair Pair : Line_Object)
    {
        strlcpy(Current_Atom_Name, Pair.value().as<const char*>(), sizeof(Current_Atom_Name));
    }

    Periodic_File.close();
}

void Periodic_Class::Get_Main_Data()
{
    if (Current_Atom_Name[0] == 0xFF)
    {
        return;
    }

    if (Current_Atom_Name[0] == '\0')
    {
        Xila.Display.Set_Current_Page(F("Periodic_Main"));
        return;
    }

    DynamicJsonDocument Data_Registry(512);

    {
        DynamicJsonDocument Filter(256);
        Filter[Current_Atom_Name]["name"] = true;
        Filter[Current_Atom_Name]["atomic_mass"] = true;
        Filter[Current_Atom_Name]["category"] = true;
        Filter[Current_Atom_Name]["symbol"] = true;
        Filter[Current_Atom_Name]["number"] = true;

        switch (Line)
        {
        case 0:
            Periodic_File = Xila.Drive.Open(Periodic_File("1.xdf"));
            break;
        case 1:
            Periodic_File = Xila.Drive.Open(Periodic_File("2.xdf"));
            break;
        case 2:
            Periodic_File = Xila.Drive.Open(Periodic_File("3.xdf"));
            break;
        case 3:
            Periodic_File = Xila.Drive.Open(Periodic_File("4.xdf"));
            break;
        case 4:
            Periodic_File = Xila.Drive.Open(Periodic_File("5.xdf"));
            break;
        case 5:
            Periodic_File = Xila.Drive.Open(Periodic_File("6.xdf"));
            break;
        case 6:
            Periodic_File = Xila.Drive.Open(Periodic_File("7.xdf"));
            break;
        case 7:
            Periodic_File = Xila.Drive.Open(Periodic_File("8.xdf"));
            break;
        case 8:
            Periodic_File = Xila.Drive.Open(Periodic_File("9.xdf"));
            break;
        default:
            return;
            break;
        }

        ReadBufferingStream Periodic_File_Buffer(Periodic_File, 512);
        if (deserializeJson(Data_Registry, Periodic_File_Buffer, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
        {
            Xila.Dialog.Event(F("Failed to read element informations."), Xila.Error);
            Periodic_File.close();
            return;
        }

        Periodic_File.close();
    }

    JsonObject Periodic_Object = Data_Registry.as<JsonObject>();

    JsonObject Current_Atom_Object;

    for (JsonPair Pair : Periodic_Object)
    {
        Current_Atom_Object = Pair.value().as<JsonObject>();
    }

    // -- Name
    if (Current_Atom_Object["name"].as<const char*>() == NULL)
    {
        Xila.Dialog.Event(F("Failed to load element datas"), Xila.Error);
        return;
    }
    else
    {
        Xila.Display.Set_Text(F("NAMEVAL_TXT"), Current_Atom_Object["name"].as<const char*>());
    }

    // -- Symbol
    if (Current_Atom_Object["symbol"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("SYMBOL_TXT"), Current_Atom_Object["symbol"].as<const char*>());
    }

    // -- Category
    if (Current_Atom_Object["category"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("CATEGORYVA_TXT"), Current_Atom_Object["category"].as<const char*>());
    }

    // -- Number
    Xila.Display.Set_Value(F("NUMBER_NUM"), Current_Atom_Object["number"].as<int>());

    // -- Atomic mass
    char Temporary_Char_Array[24];
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));

    dtostrf(Current_Atom_Object["atomic_mass"].as<double>(), 21, 8, Temporary_Char_Array);
    uint8_t i;
    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));

    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);
}

void Periodic_Class::Get_Data()
{

    if (Current_Atom_Name[0] == 0xFF)
    {
        return;
    }

    if (Current_Atom_Name[0] == '\0')
    {
        Xila.Display.Set_Current_Page(F("Periodic_Main"));
        return;
    }

    Xila.Display.Set_Current_Page(F("Periodic_Data"));

    DynamicJsonDocument Data_Registry(2048);
    {
        // -- Create a filter
        DynamicJsonDocument Filter(256);
        Filter[Current_Atom_Name] = true;
        // -- Open data file and initialize the buffer
        switch (Line)
        {
        case 0:
            Periodic_File = Xila.Drive.Open(Periodic_File("1.xdf"));
            break;
        case 1:
            Periodic_File = Xila.Drive.Open(Periodic_File("2.xdf"));
            break;
        case 2:
            Periodic_File = Xila.Drive.Open(Periodic_File("3.xdf"));
            break;
        case 3:
            Periodic_File = Xila.Drive.Open(Periodic_File("4.xdf"));
            break;
        case 4:
            Periodic_File = Xila.Drive.Open(Periodic_File("5.xdf"));
            break;
        case 5:
            Periodic_File = Xila.Drive.Open(Periodic_File("6.xdf"));
            break;
        case 6:
            Periodic_File = Xila.Drive.Open(Periodic_File("7.xdf"));
            break;
        case 7:
            Periodic_File = Xila.Drive.Open(Periodic_File("8.xdf"));
            break;
        case 8:
            Periodic_File = Xila.Drive.Open(Periodic_File("9.xdf"));
            break;
        default:
            return;
            break;
        }

        ReadBufferingStream Periodic_File_Buffer(Periodic_File, 256);
        // -- Deserialize file
        if (deserializeJson(Data_Registry, Periodic_File_Buffer, DeserializationOption::Filter(Filter)) != DeserializationError::Ok)
        {
            // -- Show an error and return if data file is corrupted
            Xila.Dialog.Event(F("Failed to read element informations."), Xila.Error);
            Periodic_File.close();
            return;
        }

        Periodic_File.close();
    }

    JsonObject Data_Object = Data_Registry.as<JsonObject>();
    JsonObject Current_Atom_Object;
    for (JsonPair Pair : Data_Object)
    {
        Current_Atom_Object = Pair.value().as<JsonObject>();
    }

    char Temporary_Char_Array[64];

    /*float Temporary_Float;
    uint32_t Temporary_Long;*/

    // Name
    if (Current_Atom_Object["name"].as<const char*>() == NULL)
    {
        Xila.Dialog.Event(F("Failed to load element datas"), Xila.Error);
        return;
    }
    else
    {
        Xila.Display.Set_Text(F("NAMEVAL_TXT"), Current_Atom_Object["name"].as<const char*>());
    }

    // -- Symbol
    if (Current_Atom_Object["symbol"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("SYMBOL_TXT"), Current_Atom_Object["symbol"].as<const char*>());
    }

    // Atom number
    Xila.Display.Set_Value(F("NUMBER_NUM"), Current_Atom_Object["number"].as<int>());

    // Category
    if (Current_Atom_Object["category"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("CATEGORYVA_TXT"), Current_Atom_Object["category"].as<const char*>());
    }

    // Appearance
    if (Current_Atom_Object["appearance"].as<const char*>() == NULL)
    {
        Xila.Display.Set_Text(F("APPEARANCV_TXT"), F("unknow"));
    }
    else
    {
        Xila.Display.Set_Text(F("APPEARANCV_TXT"), Current_Atom_Object["appearance"].as<const char*>());
    }

    // Discover
    if (Current_Atom_Object["discovered_by"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("DISCOVERV_TXT"), Current_Atom_Object["discovered_by"].as<const char*>());
    }

    // Mass
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["atomic_mass"].as<double>(), (sizeof(Temporary_Char_Array) - 3), 8, Temporary_Char_Array);
    uint8_t i;
    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " u", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MASSVAL_TXT"), Temporary_Char_Array);

    // Density
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["density"].as<double>(), sizeof(Temporary_Char_Array) - 5, 4, Temporary_Char_Array);

    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " g/l", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("DENSITYVAL_TXT"), Temporary_Char_Array);

    // -- Melting point
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["melt"], sizeof(Temporary_Char_Array) - 3, 4, Temporary_Char_Array);

    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " K", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("MELTVAL_TXT"), Temporary_Char_Array);

    // -- Boiling point
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["boil"], sizeof(Temporary_Char_Array) - 3, 4, Temporary_Char_Array);

    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " K", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("BOILINGVAL_TXT"), Temporary_Char_Array);

    // -- Phase at STP
    if (Current_Atom_Object["phase"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("PHASEVAL_TXT"), Current_Atom_Object["phase"].as<const char*>());
    }

    // -- Electron configuration
    if (Current_Atom_Object["electron_configuration"].as<const char*>() != NULL)
    {
        Xila.Display.Set_Text(F("ELECTRONCV_TXT"), Current_Atom_Object["electron_configuration"].as<const char*>());
    }

    // -- Electronegativity
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["electronegativity_pauling"], sizeof(Temporary_Char_Array) - 17, 4, Temporary_Char_Array);

    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    strlcat(Temporary_Char_Array, " (Pauling scale)", sizeof(Temporary_Char_Array));
    Xila.Display.Set_Text(F("ELECTRONNV_TXT"), Temporary_Char_Array);

    // Eelectron affinity
    memset(Temporary_Char_Array, '\0', sizeof(Temporary_Char_Array));
    dtostrf(Current_Atom_Object["electron_affinity"].as<double>(), sizeof(Temporary_Char_Array) - 2, 4, Temporary_Char_Array);

    for (i = sizeof(Temporary_Char_Array) - 1; i > 0; i--)
    {
        if (Temporary_Char_Array[i] == '0' || Temporary_Char_Array[i] == '\0')
        {
            Temporary_Char_Array[i] = '\0';
        }
        else
        {
            if (Temporary_Char_Array[i] == '.')
            {
                Temporary_Char_Array[i] = '\0';
            }
            break;
        }
    }
    for (i = 0; i < sizeof(Temporary_Char_Array); i++)
    {
        if (Temporary_Char_Array[i] != ' ')
        {
            break;
        }
    }
    strcpy(Temporary_Char_Array, Temporary_Char_Array + i);
    Xila.Display.Set_Text(F("ELECTRONAV_TXT"), Temporary_Char_Array);
}

void Periodic_Class::Get_List()
{
}