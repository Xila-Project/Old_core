///
/// @file Music_Player.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Music player header file
/// @version 0.1
/// @date 05-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Xila.hpp"

#define Timeline_Size 346

#define Next_Queue_Size 16
#define Last_Queue_Size 16

#define Music_Player_File(name) Software_Directory_Path "/MusicPla/" name

class Music_Player_Class : public Xila_Class::Software
{
protected:
    static Music_Player_Class *Instance_Pointer;

    char Temporary_Char_Array[40];
    char Temporary_File_Name[13];
    char Temporary_Radio_Link[129];

    static Xila_Class::Task_Function Main_Task(void *);

    void Pause();

    uint32_t Number_Of_Files;

    File Music_File;
    File Music_Folder;

    uint8_t State;

    enum States
    {
        Stopped,
        Playing,
        Paused
    };
    // 0 : stopped
    // 1 : play
    // 2 : pause

    QueueHandle_t Last_Queue;
    QueueHandle_t Next_Queue;

    uint8_t Volume;

    bool Random = false;
    bool Loop = false;

    uint32_t Time_To_Set;
    uint32_t Total_Time;
    uint32_t Current_Time;

    uint8_t Set;

    void Open_File(uint16_t);
    void Open_File();

    void Open_Folder();

        void Open_Radio(uint8_t);
    void Set_Radio(uint8_t);

    void Set_Variable(Xila_Class::Address, uint8_t, const void *);

    void Set_Time();

    void Play();

    void Generate_Queue();

    void Resume();
    void Stop();

    void Next_Track();
    void Last_Track();

    void Check_Queue();

    void Refresh_Interface();

    uint8_t Count_Music_File();

public:
    Music_Player_Class();
    ~Music_Player_Class();

    static Xila_Class::Software *Load();

    enum Picture
    {
        Music_Player_Icon_32 = Xila.Display.Music_Player_Images,
        Loop_32,
        Pause_32,
        Play_32,
        Random_32,
        Step_Backward_32,
        Fast_Backward_32,
        Step_Forward_32,
        Fast_Forward_32
    };
};

Xila_Class::Software_Handle Music_Player_Handle("Music Player", Music_Player_Class::Music_Player_Icon_32, Music_Player_Class::Load);
