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

Music_Player_Class::Music_Player_Class() : Software_Class(Music_Player_Handle)
{
    Xila.Task.Create(Main_Task, "Music Player", Memory_Chunk(5), NULL, &Task_Handle);
}

Music_Player_Class::~Music_Player_Class()
{
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

void Music_Player_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
    if (Adress == 'V' && Type == Xila.Display.Variable_Long)
    {
        Volume = *(uint8_t *)Variable;
        Verbose_Print("Set volume variable:");
        Serial.println(Volume);
    }
    else if (Adress == 'T' && Type == Xila.Display.Variable_Long)
    {
        Time_To_Set = *(uint32_t *)Variable;
    }
}

void Music_Player_Class::Main_Task(void *pvParameters)
{
    while (1)
    {
        switch (Instance_Pointer->Get_Instruction())
        {
        case Idle:
            Xila.Task.Delay(20);
            break;
        case Close:
            Instance_Pointer->Stop();
            Instance_Pointer->Music_Folder.close();
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Open:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Refresh_Interface();
            break;
        case Maximize:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Refresh_Interface();
            break;
        case Minimize:
            break;

        case Instruction('C', 'l'):
            Xila.Software.Close(Music_Player_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software.Minimize(Music_Player_Handle);
            break;
        case Instruction('P', 'P'):
            if (Instance_Pointer->State == Playing)
            {
                Instance_Pointer->State = Paused;
                Xila.Sound.Pause();
            }
            else if (Instance_Pointer->State == Stopped)
            {
            }
            else
            {
                Instance_Pointer->State = Playing;
                Xila.Sound.Resume();
            }
            Instance_Pointer->Refresh_Interface();
            break;
        case Instruction('F', 'o'):
            Instance_Pointer->Next_Track();
            break;
        case Instruction('B', 'a'):
            Instance_Pointer->Last_Track();
            break;
        case Instruction('F', 'F'):
            Xila.Sound.Set_Offset_Time(10);
            break;
        case Instruction('F', 'B'):
            Xila.Sound.Set_Offset_Time(-10);
            break;

        case Instruction('L', 'o'):
            Instance_Pointer->Loop = !Instance_Pointer->Loop;
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('R', 'a'):
            Instance_Pointer->Random = !Instance_Pointer->Random;
            Instance_Pointer->Send_Instruction('R', 'e');
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
        case Instruction('R', 'e'):
            Instance_Pointer->Refresh_Interface();
            Instance_Pointer->Check_Queue();
            break;
        case Instruction('R', 'Q'):
            Instance_Pointer->Refresh_Queue();
            break;
        default:
            break;
        }
    }
}

void Music_Player_Class::Set_Time()
{
    Xila.Sound.Set_Current_Time((Time_To_Set * Total_Time) / TIMELINE_SIZE);
    Refresh_Interface();
}

void Music_Player_Class::Open_File()
{
    Stop();
    Music_Folder.close();

    Xila.Dialog.Open_File(Music_File);

    if (Music_File && !Music_File.isDirectory())
    {
        Play();
    }
    else
    {
        Xila.Dialog.Event(F("Unable to open file."), Xila.Error);
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Open_Folder()
{
    Stop();
    Music_Folder.close();
    Xila.Dialog.Open_Folder(Music_Folder);
    if (Music_Folder && Music_Folder.isDirectory())
    {
        Generate_Queue();
        Refresh_Queue();
        Play();
    }
    else
    {
        Xila.Dialog.Event(F("Unable to open folder."), Xila.Error);
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Refresh_Interface()
{
    Volume = Xila.Sound.Get_Volume();

    Xila.Display.Set_Value(F("VOLUME_SLI"), Volume);

    Current_Time = Xila.Sound.Get_Current_Time();
    Total_Time = Xila.Sound.Get_Total_Time();

    sprintf(Temporary_Char_Array, "%i:%02d", (Current_Time / 60), (Current_Time % 60));
    Xila.Display.Set_Text(F("TIME_TXT"), Temporary_Char_Array);

    sprintf(Temporary_Char_Array, "%i:%02d", (Total_Time / 60), (Total_Time % 60));
    Xila.Display.Set_Text(F("TOTALTIME_TXT"), Temporary_Char_Array);

    if (Random)
    {
        Xila.Display.Show(F("RANDOMSIGN_TXT"));
    }
    else
    {
        Xila.Display.Hide(F("RANDOMSIGN_TXT"));
    }

    if (Loop)
    {
        Xila.Display.Show(F("LOOPSIGN_TXT"));
    }
    else
    {
        Xila.Display.Hide(F("LOOPSIGN_TXT"));
    }

    if (Total_Time != 0)
    {
        Xila.Display.Set_Value(F("TIMELINE_PRO"), (Current_Time * 100) / Total_Time);
    }
    else
    {
        Xila.Display.Set_Value(F("TIMELINE_PRO"), 0);
    }

    if (Xila.Sound.Get_State() == false)
    {
        Xila.Display.Set_Picture(F("PLAY_BUT"), Play_32);
    }
    else
    {
        Xila.Display.Set_Picture(F("PLAY_BUT"), Pause_32);
    }

    if (Music_File)
    {
        Xila.Drive.Get_Name(Music_File, Temporary_Char_Array, sizeof(Temporary_Char_Array));
        Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_Char_Array);
    }
    if (Next_Music_File)
    {
        Xila.Drive.Get_Name(Next_Music_File, Temporary_Char_Array, sizeof(Temporary_Char_Array));
        Xila.Display.Set_Text(F("NEXTFVAL_TXT"), Temporary_Char_Array);
    }
    else
    {
        Xila.Display.Set_Text(F("NEXTFVAL_TXT"), F(""));
    }
    if (Music_Folder)
    {
        //strcpy(Temporary_Char_Array, " Folder: ");
        Xila.Drive.Get_Name(Music_Folder, Temporary_Char_Array, sizeof(Temporary_Char_Array));

        //strlcat(Temporary_Char_Array, Xila.Drive.Get_Name(Music_Folder), sizeof(Temporary_Char_Array));
        Xila.Display.Set_Text(F("FOLDERVAL_TXT"), Temporary_Char_Array);
    }
    else
    {
        Xila.Display.Set_Text(F("FOLDERVAL_TXT"), F(""));
    }
}



void Music_Player_Class::Play()
{
    State = Playing;

    if (Music_Folder && Music_Folder.isDirectory()) // If play from a folder
    {
        if (Music_File && !Music_File.isDirectory())
        {
            if (!Xila.Sound.Play(Music_File))
            {
                State = Stopped;
                Xila.Dialog.Event(F("Cannot play this music file."), Xila.Error);
            }
        }
    }
    else // If playing from a file
    {
        if (!Xila.Sound.Play(Music_File))
        {
            State = Stopped;
            Xila.Dialog.Event(F("Cannot play this music file."), Xila.Error);
        }
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Stop()
{
    State = Stopped;
    Xila.Sound.Stop();
    Music_File.close();
    Next_Music_File.close();
}

void Music_Player_Class::Next_Track()
{
    if (Music_Folder)
    {
        for (uint8_t i = 0; i < ((sizeof(Queue) / sizeof(uint32_t)) - 2); i++)
        {
            Serial.print(i);
            Queue[i] = Queue[i + 1];
        }
        Queue[Current + 1] = 0;

        State = Playing;

        Refresh_Queue();
        Play();
    }
    else
    {
        Stop();
    }
}

void Music_Player_Class::Last_Track()
{
    if (Xila.Sound.Get_Current_Time() < 4)
    {
        Xila.Sound.Set_Current_Time(0);
    }
    else
    {
        if (Music_Folder)
        {
            Queue[0] = 0;
            for (uint8_t i = ((sizeof(Queue) / sizeof(uint32_t)) - 1); i > 0; i--)
            {
                Serial.print(i);
                Queue[i] = Queue[i - 1];
            }
            Refresh_Queue();
            Play();
        }
        else
        {
            Xila.Sound.Set_Current_Time(0);
        }
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Generate_Queue()
{
    Loop = false;

    if (!Music_Folder || !Music_Folder.isDirectory())
    {
        return;
    }

    uint32_t File_Count = Xila.Drive.Count_Files(Music_Folder);

    if (Random)
    {
        for (uint8_t i = 0; i < (sizeof(Queue) / sizeof(uint32_t)); i++)
        {
            Queue[i] = Xila.System.Random(File_Count);
        }
    }
    else
    {
        for (uint8_t i = 0; i < (sizeof(Queue) / sizeof(uint32_t)); i++)
        {
            Queue[i] = i;
        }
    }
}

void Music_Player_Class::Refresh_Queue()
{
    Stop();
    if (!Music_Folder || !Music_Folder.isDirectory())
    {
        return;
    }
    // -- Queue checking and generation
    if (Queue[Current] == 0) // empty queue
    {
        Generate_Queue();
    }
    else if (Loop) // loop
    {
        Queue[Current + 1] = Queue[Current];
    }
    uint32_t File_Count = Xila.Drive.Count_Files(Music_Folder);
    if (Queue[Current + 1] == 0) // complete queue
    {
        if (Random)
        {
            Queue[Current + 1] = Xila.System.Random(File_Count);
        }
        else
        {
            if (Queue[Current] < File_Count - 1)
            {
                Queue[Current + 1] = Queue[Current] + 1;
            }
            else
            {
                Queue[Current + 1] = Empty;
            }
        }
    }

    // -- File refreshing : open next file
    Music_Folder.rewindDirectory();
    Music_File.close();
    Music_File = Music_Folder.openNextFile();
    if (!Music_File) // empty folder
    {
        return;
    }
    Music_File.close();
    Music_Folder.rewindDirectory();
    for (uint8_t i = 1; i < Queue[Current]; i++)
    {
        Music_Folder.openNextFile().close();
    }
    Music_File = Music_Folder.openNextFile();
    if (!Music_File || Music_File.isDirectory())
    {
        Queue[Current] = 0;
        Send_Instruction('R', 'Q');
    }
    // -- File refreshing : open next file
    if (Queue[Current + 1] != 0)
    {
        Music_Folder.rewindDirectory();
        Next_Music_File.close();
        Next_Music_File = Music_Folder.openNextFile();
        if (!Next_Music_File) // empty folder
        {
            return;
        }
        Next_Music_File.close();
        Next_Music_File.rewindDirectory();
        for (uint8_t i = 1; i < Queue[Current + 1]; i++)
        {
            Music_Folder.openNextFile().close();
        }
        Next_Music_File = Music_Folder.openNextFile();
        if (!Next_Music_File || Next_Music_File.isDirectory())
        {
            Queue[Current + 1] = 0;
            Send_Instruction('R', 'Q');
        }
    }
}

void Music_Player_Class::Check_Queue()
{
    if (Xila.Sound.Get_State() == false && Music_Folder)
    {
        if (State == Playing)
        {
            Next_Track();
        }
    }
}