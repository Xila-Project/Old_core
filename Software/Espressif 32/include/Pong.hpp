#ifndef PONG_HPP_INCLUDED
#define PONG_HPP_INCLUDED

#include "Xila.hpp"

class Pong_Class : public Software_Class
{
    protected:

    public:

    enum Picture_ID
    {
        Pong_32 = 10
    };


};

Software_Handle_Class Pong_Handle("Pong", Pong_Class::Pong_32, nullptr);

#endif