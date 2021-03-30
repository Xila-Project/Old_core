#include "Xila.hpp"

#define TIMELINE_SIZE 346

class Music_Player_Class : public Software_Class
{
protected:
    static Music_Player_Class *Instance_Pointer;

    char Temporary_Char_Array[20];

    static void Main_Task(void *);

    void Pause();

    uint32_t Number_Of_Files;

    File Music_File;
    File Next_Music_File;
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

    uint32_t Queue[24] = {0};

    enum Queue_Position
    {
        Empty = 0,
        Current = ((sizeof(Queue) / sizeof(uint32_t)) - 2),
    };

    uint8_t Volume;

    bool Random = false;
    bool Loop = false;

    uint32_t Time_To_Set;
    uint32_t Total_Time;
    uint32_t Current_Time;


    void Refresh_Queue();

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t);

    void Dialog_Open_Folder();
    void Open_File();

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

    static Software_Class *Load();

    enum Picture
    {
        Music_Player_Icon_32 = Xila.Display.Music_Player,
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

Software_Handle_Class Music_Player_Handle("Music Player", Music_Player_Class::Music_Player_Icon_32, Music_Player_Class::Load);
