#include "Software/Music_Player.hpp"

Music_Player_Class *Music_Player_Class::Instance_Pointer = NULL;

Software_Class *Music_Player_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Music_Player_Class();
    return Instance_Pointer;
}

Music_Player_Class::Music_Player_Class() : Software_Class(6),
                                           State(Stopped)
{
}

Music_Player_Class::~Music_Player_Class()
{
}

void Music_Player_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    if (Adress == 'V')
    {
        Volume = *(uint8_t *)Variable;
    }
    else if (Adress == 'T')
    {
        Time_To_Set = *(uint32_t *)Variable;
    }
}

void Music_Player_Class::Main_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (Instance_Pointer->Get_Command())
        {
        case Xila.Idle:
            Instance_Pointer->Refresh_Interface();
            Xila.Delay(20);
            break;
        case Xila.Close:
            Instance_Pointer->Music_File.close();
            Instance_Pointer->Music_Folder.close();
            delete Instance_Pointer;
            vTaskDelete(NULL);
            break;
        case Instruction('C', 'l'):
            Instance_Pointer->Stop();
            Xila.Close_Software();
            break;
        case Instruction('P', 'P'):
            if (Instance_Pointer->State == Playing)
            {
                Instance_Pointer->Pause();
            }
            else if (Instance_Pointer->State == Paused)
            {
                Instance_Pointer->Resume();
            }
            break;
        case Instruction('N', 'T'):
            Instance_Pointer->Next_Track();
            break;
        case Instruction('L', 'T'):
            Instance_Pointer->Last_Track();
            break;
        case Instruction('L', 'o'):
            Instance_Pointer->Loop = !Instance_Pointer->Loop;
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('R', 'a'):
            Instance_Pointer->Random = !Instance_Pointer->Random;
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('S', 'V'):
            Xila.Sound.Set_Volume(Instance_Pointer->Volume);
            break;
        case Instruction('S', 'T'):
            Instance_Pointer->Set_Time();
            break;
        case Instruction('O', 'f'):
            Instance_Pointer->Open_File();
            break;
        case Instruction('O', 'F'):
            Instance_Pointer->Open_Folder();
            break;
        case 0xFF:
            break;
        }
        Xila.Delay(10);
    }
}

void Music_Player_Class::Set_Time()
{
    if (State != Stopped)
    {
        Xila.Sound.Set_Time(Total_Time * Total_Time / TIMELINE_SIZE);
        Xila.Display.Set_Value(F("TIMELINE_PRO"), Time_To_Set * 100 / 346);
    }
}

void Music_Player_Class::Open_File()
{
    Music_File.close();
    Music_Folder.close();
    Xila_Event Reply = Xila.Open_File_Dialog(Music_File);
    if (Reply != Xila.Success)
    {
        Xila.Event_Dialog(F("Unable to open file."), Xila.Error);
        return;
    }
    if (Music_File)
    {
        Play();
    }
}

void Music_Player_Class::Open_Folder()
{
    Music_File.close();
    Music_Folder.close();
    Xila_Event Reply = Xila.Open_Folder_Dialog(Instance_Pointer->Music_Folder);
    if (Reply != Xila.Success)
    {
        Xila.Event_Dialog(F("Unable to open folder."), Xila.Error);
        return;
    }
    if (Music_Folder)
    {
        Music_Folder.rewindDirectory();
        Number_Of_Files = 0;
        do
        {
            Music_File = Music_Folder.openNextFile();
            Number_Of_Files++;

        } while (Music_File);
        Number_Of_Files--;
        Play();
    }
}

void Music_Player_Class::Refresh_Interface()
{
    Volume = Xila.Sound.Get_Volume();
    Xila.Display.Set_Value(F("VOLUME_SLI"), Volume);

    if (State == Stopped)
    {
        Xila.Display.Set_Picture(F("PLAY_TXT"), Play_32);

        Xila.Display.Set_Text(F("FILENAME_TXT"), F("File:"));
        Xila.Display.Set_Text(F("NEXTFILE_TXT"), F("Next:"));
        Xila.Display.Set_Text(F("FOLDER_TXT"), F("Folder:"));

        Xila.Display.Set_Text(F("TIME_TXT"), F("00:00"));
        Xila.Display.Set_Text(F("TOTALTIME_TXT"), F("00:00"));
        Xila.Display.Set_Value(F("TIMELINE_PRO"), 0);
    }
    else
    {
        Current_Time = Xila.Sound.Get_Time() / 1000;
        Total_Time = Xila.Sound.Get_Total_Time();

        uint8_t Seconds, Minutes;

        Seconds = Current_Time % 60;
        Minutes = Current_Time / 60;

        Xila.Display.Set_Text(F("TIME_TXT"), String(Minutes) + ":" + String(Seconds));

        Seconds = Total_Time % 60;
        Minutes = Total_Time / 60;

        Xila.Display.Set_Text(F("TOTALTIME_TXT"), String(Minutes) + ":" + String(Seconds));

        if (State == Paused)
        {
            Xila.Display.Set_Picture(F("PLAY_TXT"), Pause_32);
        }
        else if (State == Playing)
        {
            Xila.Display.Set_Picture(F("PLAY_TXT"), Play_32);
        }

        if (Music_File)
        {
            Xila.Display.Set_Text(F("FILENAME_TXT"), "File: " + String(Music_File.name()));
        }
        if (Next_Music_File)
        {
            Xila.Display.Set_Text(F("NEXTFILE_TXT"), "Next: " + String(Next_Music_File.name()));
        }
        if (Music_Folder)
        {
            Xila.Display.Set_Text(F("FOLDER_TXT"), "Folder:" + String(Music_Folder.name()));
        }
    }
}

void Music_Player_Class::Play()
{
    uint8_t Reply;
    if (Loop == true)
    {
        Reply = Xila.Sound.Play(Music_File);
        if (Reply == 0)
        {
            Xila.Event_Dialog(F("Failed to play music file."), Xila.Error);
            Refresh_Interface();
        }
        return;
    }

    if (Music_Folder)
    {
        Music_File.close();
        if (Random == true)
        {
            // open randomly a file from the directory
            Music_Folder.rewindDirectory();
            for (uint32_t i = random(0, Number_Of_Files); i < (Number_Of_Files - 1); i++)
            {
                Music_Folder.openNextFile().close();
            }
            Music_File = Music_Folder.openNextFile();
        }
        else
        {
            Music_File = Music_Folder.openNextFile();
            if (!Music_File)
            {
                Music_Folder.rewindDirectory();
                Music_File = Music_Folder.openNextFile();
            }
        }
        Reply = Xila.Sound.Play(Music_File);
        if (Reply != 0)
        {
            Xila.Event_Dialog(F("Cannot play this music file."), Xila.Error);
        }
    }
    else
    {
        Music_File.close();
        if (Music_File)
        {
            Reply = Xila.Sound.Play(Music_File);
            if (Reply != 0)
            {
                Xila.Event_Dialog(F("Cannot play this music file."), Xila.Error);
            }
        }
        else
        {
            Xila.Event_Dialog(F("Cannot play file"), Xila.Error);
        }
    }
}

void Music_Player_Class::Stop()
{
    Music_File.close();
    Music_Folder.close();
    State = Stopped;
    Xila.Sound.Stop();
    Refresh_Interface();
}

void Music_Player_Class::Resume()
{
    if (State != Stopped)
    {
        Xila.Sound.Resume();
        Xila.Display.Set_Picture(F("PLAY_TXT"), Play_32);
        State = Playing;
    }

    Refresh_Interface();
}

void Music_Player_Class::Pause()
{
    if (State != Stopped)
    {
        Xila.Sound.Pause();
        Xila.Display.Set_Picture(F("PLAY_TXT"), Pause_32);
        State = Paused;
    }
    Refresh_Interface();
}