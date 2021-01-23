#include "Xila.hpp"

class Music_Player_Class : public Software_Class
{
protected:
    static Music_Player_Class* Instance_Pointer;

    static void Main_Task(void *);

    void Pause();

    uint32_t Total_Time;
    uint32_t Remaing_Time;
    

public:
    Music_Player_Class();
    ~Music_Player_Class();

    static Software_Class* Load();

    enum Picture
    {
        Music_Player_32 = 11
    };
    
};

Software_Handle_Class Music_Player_Handle("Music Player", Music_Player_Class::Music_Player_32, Music_Player_Class::Load);
