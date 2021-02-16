#include "Software/Simon.hpp"

Simon_Class *Simon_Class::Instance_Pointer = NULL;

Simon_Class::Simon_Class() : Software_Class(10)
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = this;

    Xila.Task_Create(Main_Task, "Simon Task", Memory_Chunk(4), NULL, &Task_Handle);
    Execute(Xila.Open);
}

Simon_Class::~Simon_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
}

Software_Class* Simon_Class::Load()
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
        switch (Instance_Pointer->Get_Command())
        {
        case 0:
            Xila.Delay(30);
            break;
        case Xila.Close:
            Instance_Pointer->Save_Registry();
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Xila.Open:
            Instance_Pointer->Load_Registry();
            Xila.Display.Set_Current_Page(F("Simon"));
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Simon"));
            break;
        case Xila.Minimize:
            break;
        case Instruction('M', 'i'):
            Xila.Minimize_Software();
            break;
        case Instruction('C', 'l'):
            Xila.Close_Software();
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
    Xila.Display.Set_Value(F("SCORE_NUM"), Current_Level);
}

void Simon_Class::Load_Registry()
{
    memset(Highest_Score, '\0', sizeof(Highest_Score));
    File Temporary_File = Xila.Drive->open(F(Simon_Registry_Path));
    DynamicJsonDocument Simon_Registry(256);
    deserializeJson(Simon_Registry, Temporary_File);
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
    DynamicJsonDocument Simon_Registry(256);
    JsonArray Highest_Score_Array = Simon_Registry["Highest score"];
    Highest_Score_Array.add(Highest_Score[0]);
    Highest_Score_Array.add(Highest_Score[1]);
    Highest_Score_Array.add(Highest_Score[2]);
    Highest_Score_Array.add(Highest_Score[3]);
    Highest_Score_Array.add(Highest_Score[4]);
    Highest_Score_Array.add(Highest_Score[5]);
    Highest_Score_Array.add(Highest_Score[6]);
    File Temporary_File = Xila.Drive->open(F(Simon_Registry_Path));
    serializeJson(Simon_Registry, Temporary_File);
    Temporary_File.close();
}

void Simon_Class::Press(uint8_t Color)
{
    if (Speed == 0)
    {
        return;
    }
    if (Sequence[Current_Level] != Color)
    {
        Game_Over();
        return;
    }
    Current_Level++;
    if (Current_Level >= MAXIMUM_LEVEL)
    {
        Win();
        return;
    }
    Xila.Display.Set_Value(F("LEVEL_NUM"), Current_Level);
    Speed -= 20;
    Show_Sequence();
}

void Simon_Class::Reset()
{
    Current_Level = 0;
    Speed = 0;
}

void Simon_Class::Win()
{
    Xila.Event_Dialog(F("Well done ! You have max out the game."), Xila.Information);
     Highest_Score[7] = Current_Level;
    Sort_Scores();
    Save_Registry();
    Show_Scores();
    Reset();
}

void Simon_Class::Sort_Scores()
{
    for(uint8_t i = 0; i < (sizeof(Highest_Score) - 1); i++)
    {
        for (uint8_t j = 0; i < (sizeof(Highest_Score) - (i+1)); j++)
        {
            if (Highest_Score[j] > Highest_Score[j+1])
            {
                uint8_t k = Highest_Score[j];
                Highest_Score[j] = Highest_Score[j+1];
                Highest_Score[j+1] = k;
            }
        }
    }
}

void Simon_Class::Game_Over()
{
    Xila.Event_Dialog(F("Game over !"), Xila.Information);
    Highest_Score[7] = Current_Level;
    Sort_Scores();
    Save_Registry();
    Show_Scores();
    Reset();
}

void Simon_Class::Show_Sequence()
{
    for (uint8_t i = 0; i < Current_Level; i++)
    {
        switch (Sequence[i])
        {
        case Red:
            Xila.Display.Set_Background_Color(F("RED_BUT"), 57344);
            Xila.Sound.Tone(523, Speed);
            //Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("RED_BUT"), 57344);
            Xila.Delay(200);
            break;
        case Green:
            Xila.Display.Set_Background_Color(F("GREEN_BUT"), 34308);
            Xila.Sound.Tone(659, Speed);
            //Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("GREEN_BUT"), 34308);
            Xila.Delay(200);
            break;
        case Blue:
            Xila.Display.Set_Background_Color(F("BLUE_BUT"), 1300);
            Xila.Sound.Tone(784, Speed);
            //Xila.Delay(Speed);
            Xila.Display.Set_Background_Color(F("BLUE_BUT"), 1300);
            Xila.Delay(200);
            break;
        case Yellow:
            Xila.Display.Set_Background_Color(F("YELLOW_BUT"), 64896);
            Xila.Sound.Tone(988, Speed);
            //Xila.Delay(Speed);
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
    Current_Level = 0;
    Speed = 1000;
    for (uint8_t i = 0; i < MAXIMUM_LEVEL; i++)
    {
        Sequence[i] = uint8_t(esp_random() % 4);
    }
}