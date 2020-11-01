#include "GalaxOS.hpp"

class Music_Player_Class : public Software_Class
{
    protected:

    static Music_Player_Class* Instance_Pointer;

    friend void Music_Player_Task(void *);

    void Pause();

    public:

    Music_Player_Class();
    ~Music_Player_Class();

    static Software_Class* Load();

    enum Picture_ID
    {
        Music_Player_32 = 11
    };
};

Software_Handle_Class Music_Player_Handle("Music Player", Music_Player_Class::Music_Player_32, Music_Player_Class::Load);

void Music_Player_Task(void *);


