#include "GalaxOS.hpp"

class Music_Player_Class : public Software_Class
{
    protected:

    static Music_Player_Class* Instance_Pointer;

    friend void Music_Player_Task(void *);

    void Pause();

};

void Music_Player_Task(void *);


