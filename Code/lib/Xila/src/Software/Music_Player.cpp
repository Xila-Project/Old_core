#include "Software/Music_Player.hpp"

Music_Player_Class *Music_Player_Class::Instance_Pointer = NULL;

Xila_Class::Software *Music_Player_Class::Load()
{
    if (Instance_Pointer != NULL)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = new Music_Player_Class();
    return Instance_Pointer;
}

Music_Player_Class::Music_Player_Class() : Xila_Class::Software(Music_Player_Handle),
                                           State(Stopped),
                                           Set(false)
{
    Next_Queue = xQueueCreate(Next_Queue_Size, sizeof(uint32_t));
    Last_Queue = xQueueCreate(Last_Queue_Size, sizeof(uint32_t));
    if (Next_Queue == NULL || Last_Queue == NULL)
    {
        delete this;
    }
    Xila.Task.Create(Main_Task, "Music Player", Memory_Chunk(5), NULL, &Task_Handle);
}

Music_Player_Class::~Music_Player_Class()
{
    Stop();
    if (Instance_Pointer != this)
    {
        delete Instance_Pointer;
    }
    Instance_Pointer = NULL;
}

void Music_Player_Class::Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable)
{
    if (Address == Address('V', 'o') && Type == Xila.Display.Variable_Long)
    {
        Volume = *(uint8_t *)Variable;
    }
    else if (Address == Address('T', 'i') && Type == Xila.Display.Variable_Long)
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
        case Xila.Idle:
            if (Xila.Software_Management.Get_State(Music_Player_Handle) == Xila.Minimized)
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
                        Xila.Display.Click(F("VOLUMEUP_BUT"), 0);
                        break;
                    case Xila.Keyboard.Arrow_Down:
                        Xila.Display.Click(F("VOLUMEDOWN_BUT"), 0);
                        break;
                    default:
                        break;
                    }
                }
            }
            Xila.Task.Delay(10);
            break;

        case Xila.Close:
            delete Instance_Pointer;
            Xila.Task.Delete();
            break;
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Stop();
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Xila.Minimize:
            break;
        case Xila.Hibernate:
        case Xila.Shutdown:
        case Xila.Restart:
        case Instruction('C', 'l'):
            Xila.Software_Management.Close(Music_Player_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Management.Minimize(Music_Player_Handle);
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
            Instance_Pointer->Send_Instruction('R', 'e');
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
            Xila.Sound.Set_Loop(Instance_Pointer->Loop);
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('R', 'a'):
            Instance_Pointer->Random = !Instance_Pointer->Random;
            xQueueReset(Instance_Pointer->Next_Queue);
            Instance_Pointer->Generate_Queue();
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('S', 'V'):
            Xila.Sound.Set_Volume(Instance_Pointer->Volume);
            Instance_Pointer->Send_Instruction('R', 'e');
            break;
        case Instruction('V', '+'):
            if (Xila.Sound.Get_Volume() <= 243)
            {
                Xila.Sound.Set_Volume(Xila.Sound.Get_Volume() + 12);
                Instance_Pointer->Send_Instruction('R', 'e');
            }
            break;
        case Instruction('V', '-'):
            if (Xila.Sound.Get_Volume() >= 12)
            {
                Xila.Sound.Set_Volume(Xila.Sound.Get_Volume() - 12);
                Instance_Pointer->Send_Instruction('R', 'e');
            }

            break;
        case Instruction('S', 'T'):
            Instance_Pointer->Set_Time();
            Instance_Pointer->Send_Instruction('R', 'e');
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
        default:
            break;
        }
    }
}

void Music_Player_Class::Set_Time()
{
    Xila.Sound.Set_Current_Time((Time_To_Set * Total_Time) / Timeline_Size);
    Send_Instruction('R', 'e');
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

    Stop();
    File Temporary_File = Xila.Drive.Open(Music_Player_File("Registry.xrf"));
    DynamicJsonDocument Music_Player_Registry(512);
    if (deserializeJson(Music_Player_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return;
    }
    Temporary_File.close();
    if (strcmp("Music Player", Music_Player_Registry["Registry"] | "") != 0)
    {
        return;
    }
    memset(Temporary_Radio_Link, '\0', sizeof(Temporary_Radio_Link));
    switch (Radio)
    {
    case 1:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 1"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 2:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 2"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 3:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 3"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 4:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 4"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 5:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 5"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 6:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 6"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 7:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 7"] | "", sizeof(Temporary_Radio_Link));
        break;
    case 8:
        strlcpy(Temporary_Radio_Link, Music_Player_Registry["Radio 8"] | "", sizeof(Temporary_Radio_Link));
        break;
    default:
        break;
    }

    Set_Watchdog_Timeout(15000);
    if (Xila.Sound.Play(Temporary_Radio_Link) != Xila.Success)
    {
        Stop();
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
    Temporary_File.close();
}

void Music_Player_Class::Open_Folder()
{
    Stop();
    if (Xila.Dialog.Open_Folder(Music_Folder) != Xila.Default_Yes)
    {
        return;
    }

    if (Music_Folder && Music_Folder.isDirectory())
    {
        Generate_Queue();
        Next_Track();
    }
    else
    {
        Xila.Dialog.Event(F("Unable to open folder."), Xila.Error);
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Refresh_Interface()
{
    // -- Music file / folder
    if (State == Playing || State == Paused)
    {

        if (Music_File)
        {
            Xila.Drive.Get_Name(Music_File, Temporary_Char_Array, sizeof(Temporary_Char_Array));
            Xila.Display.Set_Text(F("TITLE_TXT"), Temporary_Char_Array);
        }
        else
        {
            Xila.Display.Set_Text(F("TITLE_TXT"), Temporary_Radio_Link);
        }

        memset(Temporary_File_Name, '\0', sizeof(Temporary_File_Name));
        strcpy(Temporary_Char_Array, " Folder : ");

        if (Music_Folder)
        {
            Xila.Drive.Get_Name(Music_Folder, Temporary_File_Name, sizeof(Temporary_File_Name));
            strlcat(Temporary_Char_Array, Temporary_File_Name, sizeof(Temporary_Char_Array));
        }
        else
        {
            strcat(Temporary_Char_Array, "-");
        }

        Xila.Display.Set_Text(F("FOLDER_TXT"), Temporary_Char_Array);
    }
    // -- Volume
    Volume = Xila.Sound.Get_Volume();
    Xila.Display.Set_Value(F("VOLUME_SLI"), Volume);
    // -- Playing state
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
    // -- Time line
    Current_Time = Xila.Sound.Get_Current_Time();
    sprintf(Temporary_Char_Array, "%i:%02d", (Current_Time / 60), (Current_Time % 60));
    Xila.Display.Set_Text(F("TIME_TXT"), Temporary_Char_Array);
    Total_Time = Xila.Sound.Get_Duration();
    if (Total_Time != 0)
    {
        Xila.Display.Set_Value(F("TIMELINE_PRO"), (Current_Time * 100) / Total_Time);
    }
    else
    {
        Xila.Display.Set_Value(F("TIMELINE_PRO"), 0);
    }
    sprintf(Temporary_Char_Array, "%i:%02d", (Total_Time / 60), (Total_Time % 60));
    Xila.Display.Set_Text(F("TOTALTIME_TXT"), Temporary_Char_Array);

    // -- Play button
    if (State == Playing)
    {
        Xila.Display.Set_Value(F("PLAY_BUT"), 1);
    }
    else
    {
        Xila.Display.Set_Value(F("PLAY_BUT"), 0);
    }
}

void Music_Player_Class::Play()
{
    Xila.Sound.Set_Current_Time(0);
    if (Xila.Sound.Play(Music_File) != Xila.Success)
    {
        Stop();
        Xila.Dialog.Event(F("Cannot play this music file."), Xila.Error);
    }
    else
    {
        State = Playing;
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Stop()
{
    memset(Temporary_Radio_Link, '\0', sizeof(Temporary_Radio_Link));
    xQueueReset(Next_Queue);
    xQueueReset(Last_Queue);
    Loop = false;
    Random = false;
    State = Stopped;
    Xila.Sound.Stop();
    Music_File.close();
}

void Music_Player_Class::Next_Track()
{
    if (Music_Folder && Music_Folder.isDirectory())
    {
        uint16_t Next_File;
        if (xQueueReceive(Next_Queue, &Next_File, pdMS_TO_TICKS(10)) != pdTRUE)
        {
            Generate_Queue();
            if (xQueueReceive(Next_Queue, &Next_File, pdMS_TO_TICKS(10)) != pdTRUE)
            {
                Stop();
                return;
            }
        }
        Open_File(Next_File);
        xQueueSend(Last_Queue, &Next_File, pdMS_TO_TICKS(10));
        Play();
    }
    else
    {
        Stop();
    }
}

void Music_Player_Class::Last_Track()
{
    if (Music_Folder)
    {

        if (Xila.Sound.Get_Current_Time() < 4)
        {
            uint16_t Last_File;
            if (xQueueReceive(Last_Queue, &Last_File, pdMS_TO_TICKS(10)) != pdTRUE)
            {
                Stop();
                return;
            }

            Open_File(Last_File);

            Play();
        }
        else
        {
            Xila.Sound.Set_Current_Time(0);
        }
    }
    else
    {
        Xila.Sound.Set_Current_Time(0);
    }
    Send_Instruction('R', 'e');
}

void Music_Player_Class::Generate_Queue()
{
    static uint32_t Folder_Position = 0;
    Loop = false;
    if (!Music_Folder || !Music_Folder.isDirectory())
    {
        return;
    }

    uint16_t File_Count = Xila.Drive.Count_Items(Music_Folder);

    if (File_Count == 0)
    {
        return;
    }

    if (Random)
    {
        while (xQueueSend(Next_Queue, &Folder_Position, pdMS_TO_TICKS(10)) == pdTRUE)
        {
            Folder_Position = Xila.System.Random(File_Count);
        }
        Folder_Position = 0;
    }
    else
    {
        while (xQueueSend(Next_Queue, &Folder_Position, pdMS_TO_TICKS(10)) == pdTRUE)
        {
            if (Folder_Position >= File_Count)
            {
                Folder_Position = 0;
            }
            else
            {
                Folder_Position++;
            }
        }
    }
}

void Music_Player_Class::Open_File(uint16_t Folder_Position)
{
    Music_File.close();
    if (!Music_Folder)
    {
        return;
    }

    Music_Folder.rewindDirectory();

    for (uint32_t i = 0; i < Folder_Position; i++)
    {
        Music_Folder.openNextFile().close();
    }
    Music_File = Music_Folder.openNextFile();

    while (Music_File.isDirectory())
    {
        Music_File.close();
        Music_File = Music_Folder.openNextFile();
        if (!Music_File)
        {
            break;
        }
    }
}

void Music_Player_Class::Check_Queue()
{
    if (Xila.Sound.Get_State() == false && Music_Folder && Music_Folder.isDirectory() && State == Playing)
    {
        Xila.Task.Delay(250);
        if (Xila.Sound.Get_State() == false && Music_Folder && Music_Folder.isDirectory() && State == Playing)
        {
            Next_Track();
        }
    }
}