#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "GalaxOS.hpp"

class Periodic_Class : public Software_Class
{
    private:

        

        static uint8_t Number_Instance;

        uint16_t Socket_Method;

        xTaskHandle Socket_Handle;

        uint16_t Current_Atom;

        void Get_Main_Data();
        void Get_Data();
        void Get_List();

    public:

        Periodic_Class();
        ~Periodic_Class();

        void Execute(uint16_t const& Socket_Method_To_Set);
        void Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2);

        friend void Periodic_Socket(void *);

};

void Periodic_Task(void *);

#endif