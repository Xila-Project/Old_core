#ifndef PONG_HPP_INCLUDED
#define PONG_HPP_INCLUDED

#include "Xila.hpp"

class Pong_Class : public Software_Class
{
    protected:
    static Pong_Class* Instance_Pointer;

    uint8_t Player_1_Score, Player_2_Score;

    void Refresh_Interface();

    public:
    Pong_Class();
    ~Pong_Class();

    static void Main_Task(void*);

    enum Image
    {
        Icon_32 = Xila.Pong
    };

    static Software_Class* Load();

};

Software_Handle_Class Pong_Handle("Pong", Pong_Class::Icon_32, Pong_Class::Load);

#endif