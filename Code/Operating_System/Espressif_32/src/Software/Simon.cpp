#include "Software/Simon.hpp"

Simon_Class *Simon_Class::Instance_Pointer = NULL;

Simon_Class::Simon_Class() : Software_Class(Simon_Handle),
                             Speed(0)
{
    Xila.Task_Create(Main_Task, "Simon Task", Memory_Chunk(5), NULL, &Task_Handle);
}

Simon_Class::~Simon_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

Software_Class *Simon_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Simon_Class();
    return Instance_Pointer;
}

void Simon_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case 0:
            Xila.Delay(30);
            break;
        case Xila.Watchdog:
            Xila.Feed_Watchdog();
            break;
        case Xila.Close:
            Instance_Pointer->Save_Registry();
            delete Instance_Pointer;
            Xila.Task_Delete();
            break;
        case Xila.Open:
            Instance_Pointer->Load_Registry();
            Xila.Display.Set_Current_Page(F("Simon"));
            Instance_Pointer->Show_Scores();
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Simon"));
            Instance_Pointer->Show_Scores();
            break;
        case Xila.Minimize:
            break;
        case Instruction('M', 'i'):
            Xila.Software_Minimize(Simon_Handle);
            break;
        case Instruction('C', 'l'):
            Xila.Software_Close(Simon_Handle);
            break;
        case Instruction('R', 'e'):
            Instance_Pointer->Press(Red);
            break;
        case Instruction('G', 'r'):
            Instance_Pointer->Press(Green);
            break;
        case Instruction('B', 'l'):
            Instance_Pointer->Press(Blue);
            break;
        case Instruction('Y', 'e'):
            Instance_Pointer->Press(Yellow);
            break;
        case Instruction('S', 't'): // start / stop
            if (Instance_Pointer->Speed == 0)
            {
                Instance_Pointer->Generate_Sequence();
                Xila.Display.Set_Text(F("STARTSTOP_BUT"), F("Stop"));
                Instance_Pointer->Show_Sequence();
            }
            else
            {
                Instance_Pointer->Reset();
                Xila.Display.Set_Text(F("STARTSTOP_BUT"), F("Start"));
            }
            break;

        default:
            break;
        }
    }
}

void Simon_Class::Show_Scores()
{
    Xila.Display.Set_Value(F("SCORE1_NUM"), Highest_Score[0]);
    Xila.Display.Set_Value(F("SCORE2_NUM"), Highest_Score[1]);
    Xila.Display.Set_Value(F("SCORE3_NUM"), Highest_Score[2]);
    Xila.Display.Set_Value(F("SCORE4_NUM"), Highest_Score[3]);
    Xila.Display.Set_Value(F("SCORE5_NUM"), Highest_Score[4]);
    Xila.Display.Set_Value(F("SCORE6_NUM"), Highest_Score[5]);
    Xila.Display.Set_Value(F("SCORE7_NUM"), Highest_Score[6]);
    Xila.Display.Set_Value(F("SCORE_NUM"), Current_Level[1]);
}

void Simon_Class::Load_Registry()
{
    memset(Highest_Score, '\0', sizeof(Highest_Score));
    File Temporary_File = Xila.Drive->open(Simon_Registry_Path);
    DynamicJsonDocument Simon_Registry(256);
    if (deserializeJson(Simon_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Xila.Event_Dialog(F("Failed to load registry."), Xila.Error);
        Temporary_File.close();
        return;
    }
    Highest_Score[0] = Simon_Registry["Highest score"][0];
    Highest_Score[1] = Simon_Registry["Highest score"][1];
    Highest_Score[2] = Simon_Registry["Highest score"][2];
    Highest_Score[3] = Simon_Registry["Highest score"][3];
    Highest_Score[4] = Simon_Registry["Highest score"][4];
    Highest_Score[5] = Simon_Registry["Highest score"][5];
    Highest_Score[6] = Simon_Registry["Highest score"][6];
    Temporary_File.close();
}

void Simon_Class::Save_Registry()
{
    File Temporary_File = Xila.Drive->open(Simon_Registry_Path, FILE_WRITE);
    DynamicJsonDocument Simon_Registry(256);
    Simon_Registry["Highest score"][0] = Highest_Score[0];
    Simon_Registry["Highest score"][1] = Highest_Score[1];
    Simon_Registry["Highest score"][2] = Highest_Score[2];
    Simon_Registry["Highest score"][3] = Highest_Score[3];
    Simon_Registry["Highest score"][4] = Highest_Score[4];
    Simon_Registry["Highest score"][5] = Highest_Score[5];
    Simon_Registry["Highest score"][6] = Highest_Score[6];

    if (serializeJson(Simon_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Xila.Event_Dialog(F("Failed to save registry."), Xila.Error);
        Temporary_File.close();
        return;
    }
    Temporary_File.close();
}

void Simon_Class::Press(uint8_t Color)
{
    if (Speed == 0)
    {
        return;
    }
    if (Sequence[Current_Level[1]] != Color)
    {
        Game_Over();
        return;
    }
    Current_Level[1]++;
    if (Current_Level[1] == Current_Level[0])
    {
        if (Current_Level[1] >= MAXIMUM_LEVEL)
        {
            Win();
            return;
        }
        Current_Level[1] = 0;
        Current_Level[0]++;
        Xila.Display.Set_Value(F("LEVEL_NUM"), Current_Level[0]);
        Speed -= 20;
        Show_Sequence();
    }
}

void Simon_Class::Reset()
{
    Current_Level[0] = 0;
    Current_Level[1] = 0;
    Speed = 0;
}

void Simon_Class::Win()
{
    Xila.Event_Dialog(F("Well done ! You have max out the game."), Xila.Information);
    Highest_Score[7] = Current_Level[0];
    Sort_Scores();
    Save_Registry();
    Show_Scores();
    Reset();
}

void Simon_Class::Sort_Scores()
{
    /*
    for (uint8_t i = 0; i < (sizeof(Highest_Score) - 1); i++)
    {
        for (uint8_t j = 0; i < (sizeof(Highest_Score) - (i + 1)); j++)
        {
            if (Highest_Score[j] > Highest_Score[j + 1])
            {
                uint8_t k = Highest_Score[j];
                Highest_Score[j] = Highest_Score[j + 1];
                Highest_Score[j + 1] = k;
            }
        }
    }*/
}

void Simon_Class::Game_Over()
{
    Xila.Event_Dialog(F("Game over !"), Xila.Information);
    Highest_Score[7] = Current_Level[0];
    Sort_Scores();
    Save_Registry();
    Show_Scores();
    Reset();
}

void Simon_Class::Show_Sequence()
{
    for (uint8_t i = 0; i <= Current_Level[0]; i++)
    {
        switch (Sequence[i])
        {
        case Red:
            Xila.Display.Set_Background_Color(F("RED_BUT"), 40960);
            Xila.Sound.Tone(523, Speed);
            Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("RED_BUT"), 57344);
            Xila.Delay(200);
            break;
        case Green:
            Xila.Display.Set_Background_Color(F("GREEN_BUT"), 17408);
            Xila.Sound.Tone(659, Speed);
            Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("GREEN_BUT"), 34308);
            Xila.Delay(200);
            break;
        case Blue:
            Xila.Display.Set_Background_Color(F("BLUE_BUT"), 780);
            Xila.Sound.Tone(784, Speed);
            Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("BLUE_BUT"), 1300);
            Xila.Delay(200);
            break;
        case Yellow:
            Xila.Display.Set_Background_Color(F("YELLOW_BUT"), 48000);
            Xila.Sound.Tone(988, Speed);
            Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("YELLOW_BUT"), 64896);
            Xila.Delay(200);

            break;
        default:
            Xila.Event_Dialog(F("Exception in the generated sequence."), Xila.Error);
            Show_Scores();
            Reset();
            break;
        }
    }
}

void Simon_Class::Generate_Sequence()
{
    Current_Level[0] = 0;
    Current_Level[1] = 0;
    Speed = 1000;
    for (uint8_t i = 0; i < (MAXIMUM_LEVEL - 1); i++)
    {
        Sequence[i] = uint8_t(esp_random() % 4);
    }
}