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
    Xila.Task_Create(Main_Task, "Music Player", Memory_Chunk(5), NULL, &Task_Handle);
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
    if (Adress == 'V')
    {
        Volume = *(uint8_t *)Variable;
        Verbose_Print("Set volume variable:");
        Serial.println(Volume);
    }
    else if (Adress == 'T')
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
            Xila.Delay(20);
            break;
        case Xila.Close:
            Instance_Pointer->Stop();
            Instance_Pointer->Music_File.close();
            Instance_Pointer->Music_Folder.close();
            delete Instance_Pointer;
            Xila.Task_Delete();
            break;
        case Xila.Open:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Refresh_Interface();
            break;
        case Xila.Maximize:
            Xila.Display.Set_Current_Page(F("Music_Player"));
            Instance_Pointer->Refresh_Interface();
            break;
        case Xila.Minimize:
            break;

        case Instruction('C', 'l'):
            Xila.Software_Close(Music_Player_Handle);
            break;
        case Instruction('M', 'i'):
            Xila.Software_Minimize(Music_Player_Handle);
            break;
        case Instruction('P', 'P'):
            if (Xila.Sound.Get_State() == true)
            {
                Xila.Sound.Pause();
            }
            else
            {
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
        case Instruction('R', 'e'):
            Instance_Pointer->Refresh_Interface();
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
    Music_File.close();
    Music_Folder.close();

    Xila.Open_File_Dialog(Music_File);

    if (Music_File)
    {
        Play();
    }
    else
    {
        Xila.Event_Dialog(F("Unable to open file."), Xila.Error);
    }
}

void Music_Player_Class::Open_Folder()
{
    Music_File.close();
    Music_Folder.close();
    Xila.Open_Folder_Dialog(Music_Folder);
    if (Music_Folder)
    {
        Music_Folder.rewindDirectory();
        Number_Of_Files = 0;
        do
        {
            Music_File.close();
            Music_File = Music_Folder.openNextFile();
            Number_Of_Files++;

        } while (Music_File);

        Number_Of_Files--;
        Play();
    }
    else
    {
        Xila.Event_Dialog(F("Unable to open folder."), Xila.Error);
    }
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
        Xila.Display.Set_Text(F("FILENAME_TXT"), Xila.Get_File_Name(Music_File));
    }
    if (Next_Music_File)
    {
        strcpy(Temporary_Char_Array, " Next: ");
        strlcat(Temporary_Char_Array, Xila.Get_File_Name(Next_Music_File), sizeof(Temporary_Char_Array));
    }
    else
    {
        Xila.Display.Set_Text(F("NEXTFILE_TXT"), F(" Next: "));
    }
    if (Music_Folder)
    {
        strcpy(Temporary_Char_Array, " Folder: ");
        strlcat(Temporary_Char_Array, Xila.Get_File_Name(Music_Folder), sizeof(Temporary_Char_Array));
        Xila.Display.Set_Text(F("FOLDER_TXT"), Temporary_Char_Array);
    }
    else
    {
        Xila.Display.Set_Text(F("FOLDER_TXT"), F(" Folder:"));
    }
}

void Music_Player_Class::Random_File()
{

    if (Music_Folder && Music_Folder.isDirectory())
    {
        uint32_t i = Xila.Random();
        i = i * Xila.Count_Files(Music_Folder);
        i /= ;

        Music_Folder.rewindDirectory();
        Next_Music_File.close();
        Next_Music_File = Music_Folder.openNextFile();
        if (!Next_Music_File) // empty folder
        {
            return;
        }
        Next_Music_File.close();

        for (uint8_t j = 0; j < i; i++)
        {
            Music_Folder.openNextFile().close();
        }
        Next_Music_File.close();
        Next_Music_File = Music_Folder.openNextFile();
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

    if (Music_Folder) // If play from a folder
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

        if (!Xila.Sound.Play(Music_File))
        {
            Xila.Event_Dialog(F("Cannot play this music file."), Xila.Error);
        }
        Refresh_Interface();
    }
    else // If playing from a file
    {
        if (!Xila.Sound.Play(Music_File))
        {
            Xila.Event_Dialog(F("Cannot play this music file."), Xila.Error);
        }
        Refresh_Interface();
    }
}

void Music_Player_Class::Stop()
{
    Xila.Sound.Stop();
    Music_File.close();
    Music_Folder.close();

    Refresh_Interface();
}

void Music_Player_Class::Next_Track()
{
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

            Music_Folder.openNextFile()
        }
    }
}