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

Music_Player_Class::Music_Player_Class() : Software_Class(Music_Player_Handle),
                                           State(Stopped),
                                           Set(false)
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
            if (Xila.Software.Get_State(Music_Player_Handle) == Minimized)
            {
                Xila.Task.Delay(90);
            }
            else
            {
                while (Xila.Keyboard.Available())
                {
                    switch (Xila.Keyboard.Read())
                    {
                    case ' ':
                        Instance_Pointer->Send_Instruction('P', 'P');
                        break;
                    case 'L':
                    case 'l':
                        Instance_Pointer->Send_Instruction('L', 'o');
                        break;
                    case 'R':
                    case 'r':
                        Instance_Pointer->Send_Instruction('R', 'a');
                        break;
                    case Xila.Keyboard.Arrow_Left:
                        Instance_Pointer->Send_Instruction('F', 'B');
                        break;
                    case Xila.Keyboard.Arrow_Right:
                        Instance_Pointer->Send_Instruction('F', 'F');
                        break;
                    case Xila.Keyboard.Arrow_Up:
                        Xila.Display.Click(F("VOLUMEUP_TXT"), 0);
                        break;
                    case Xila.Keyboard.Arrow_Down:
                        Xila.Display.Click(F("VOLUMEDOWN_TXT"), 0);
                        break;
                    default:
                        break;
                    }
                }
            }
            Xila.Task.Delay(10);
            break;
        case Restart:
        case Shutdown:
        case Close:
            Instance_Pointer->Stop();
            Instance_Pointer->Music_Folder.close();
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Open:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Stop();
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
        case Instruction('S', '1'):
            Instance_Pointer->Set_Radio(1);
            break;
        case Instruction('S', '2'):
            Instance_Pointer->Set_Radio(2);
            break;
        case Instruction('S', '3'):
            Instance_Pointer->Set_Radio(3);
            break;
        case Instruction('S', '4'):
            Instance_Pointer->Set_Radio(4);
            break;
        case Instruction('S', '5'):
            Instance_Pointer->Set_Radio(5);
            break;
        case Instruction('S', '6'):
            Instance_Pointer->Set_Radio(6);
            break;
        case Instruction('S', '7'):
            Instance_Pointer->Set_Radio(7);
            break;
        case Instruction('S', '8'):
            Instance_Pointer->Set_Radio(8);
            break;
        case Instruction('R', '1'):
            Instance_Pointer->Open_Radio(1);
            break;
        case Instruction('R', '2'):
            Instance_Pointer->Open_Radio(2);
            break;
        case Instruction('R', '3'):
            Instance_Pointer->Open_Radio(3);
            break;
        case Instruction('R', '4'):
            Instance_Pointer->Open_Radio(4);
            break;
        case Instruction('R', '5'):
            Instance_Pointer->Open_Radio(5);
            break;
        case Instruction('R', '6'):
            Instance_Pointer->Open_Radio(6);
            break;
        case Instruction('R', '7'):
            Instance_Pointer->Open_Radio(7);
            break;
        case Instruction('R', '8'):
            Instance_Pointer->Open_Radio(8);
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
            Xila.Sound.Set_Time_Offset(10);
            break;
        case Instruction('F', 'B'):
            Xila.Sound.Set_Time_Offset(-10);
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
            Instance_Pointer->Dialog_Open_Folder();
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

void Music_Player_Class::Open_Radio(uint8_t Radio)
{
    Verbose_Print_Line("Open radio");
    File Temporary_File = Xila.Drive.Open(Music_Player_File("Registry.xrf"));
    DynamicJsonDocument Music_Player_Registry(512);
    Verbose_Print_Line("Deserialize radio");
    if (deserializeJson(Music_Player_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return;
    }
    Temporary_File.close();

    if (strcmp(Music_Player_Registry["Registry"], "Music Player") != 0)
    {
        return;
    }

    memset(Temporary_Radio_Link, '\0', sizeof(Temporary_Radio_Link));

    switch (Radio)
    {
    case 1:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 1"], sizeof(Temporary_Radio_Link));
        break;
    case 2:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 2"], sizeof(Temporary_Radio_Link));
        break;
    case 3:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 3"], sizeof(Temporary_Radio_Link));
        break;
    case 4:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 4"], sizeof(Temporary_Radio_Link));
        break;
    case 5:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 5"], sizeof(Temporary_Radio_Link));
        break;
    case 6:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 6"], sizeof(Temporary_Radio_Link));
        break;
    case 7:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 7"], sizeof(Temporary_Radio_Link));
        break;
    case 8:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 8"], sizeof(Temporary_Radio_Link));
        break;
    }

    if (!Xila.Sound.Play(Temporary_Radio_Link))
    {
        State = Stopped;
        Xila.Dialog.Event(F("Cannot play this radio."), Xila.Error);
    }
    else
    {
        State = Playing;
    }
}

void Music_Player_Class::Set_Radio(uint8_t Radio)
{
    if (Xila.Dialog.Keyboard(Temporary_Radio_Link, sizeof(Temporary_Radio_Link)) == Xila.Default_Cancel)
    {
        return;
    }
    File Temporary_File = Xila.Drive.Open(Music_Player_File("Registry.xrf"), FILE_WRITE);
    DynamicJsonDocument Music_Player_Registry(512);
    deserializeJson(Music_Player_Registry, Temporary_File);
    Music_Player_Registry["Registry"] = "Music Player";
    switch (Radio)
    {
    case 1:
        Music_Player_Registry["Radio 1"] = Temporary_Radio_Link;
        break;
    case 2:
        Music_Player_Registry["Radio 2"] = Temporary_Radio_Link;
        break;
    case 3:
        Music_Player_Registry["Radio 3"] = Temporary_Radio_Link;
        break;
    case 4:
        Music_Player_Registry["Radio 4"] = Temporary_Radio_Link;
        break;
    case 5:
        Music_Player_Registry["Radio 5"] = Temporary_Radio_Link;
        break;
    case 6:
        Music_Player_Registry["Radio 6"] = Temporary_Radio_Link;
        break;
    case 7:
        Music_Player_Registry["Radio 7"] = Temporary_Radio_Link;
        break;
    case 8:
        Music_Player_Registry["Radio 8"] = Temporary_Radio_Link;
        break;
    }
    serializeJson(Music_Player_Registry, Temporary_File);
}

void Music_Player_Class::Dialog_Open_Folder()
{
    Stop();
    Music_Folder.close();
    Xila.Dialog.Dialog_Open_Folder(Music_Folder);
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
    Total_Time = Xila.Sound.Get_Duration();

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

    if (State == Playing)
    {
        Xila.Display.Set_Picture(F("PLAY_BUT"), Pause_32);
    }
    else
    {
        Xila.Display.Set_Picture(F("PLAY_BUT"), Play_32);
    }

    if (Music_File)
    {
        Xila.Drive.Get_Name(Music_File, Temporary_Char_Array, sizeof(Temporary_Char_Array));
        Xila.Display.Set_Text(F("FILENAME_TXT"), Temporary_Char_Array);
    }

    memset(Temporary_File_Name, '\0', sizeof(Temporary_File_Name));

    if (Next_Music_File)
    {
        strcpy(Temporary_Char_Array, "   Next : ");
        Xila.Drive.Get_Name(Next_Music_File, Temporary_File_Name, sizeof(Temporary_File_Name));
        strlcat(Temporary_Char_Array, Temporary_File_Name, sizeof(Temporary_Char_Array));

        if (Music_Folder)
        {
            Xila.Drive.Get_Name(Music_Folder, Temporary_File_Name, sizeof(Temporary_File_Name));
            strlcat(Temporary_Char_Array, Temporary_File_Name, sizeof(Temporary_Char_Array));
        }
    }
    else
    {
        strcpy(Temporary_Char_Array, "   Next : -");
    }
    Xila.Display.Set_Text(F("NEXTFILE_TXT"), Temporary_Char_Array);
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