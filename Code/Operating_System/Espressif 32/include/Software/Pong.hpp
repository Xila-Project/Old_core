#ifndef PONG_HPP_INCLUDED
#define PONG_HPP_INCLUDED

#include "Xila.hpp"

class Pong_Class : public Software_Class
{
    protected:

    public:

    enum Picture_ID
    {
        Icon_32 = Xila.Pong
    };


};

Software_Handle_Class Pong_Handle("Pong", Pong_Class::Icon_32, nullptr);

#endif