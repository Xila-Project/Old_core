#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "GalaxOS.hpp"

class Periodic_Class : protected Software_Class
{
    protected:
        static Periodic_Class* Instance_Pointer;

        uint8_t Current_Atom;

        uint32_t X, Y;

        void Get_Main_Data();
        void Get_Data();
        void Get_List();

        void Set_Variable(const void* Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    public:

        Periodic_Class();
        ~Periodic_Class();

        friend void Periodic_Task(void *);

        static Software_Class* Load();

};

void Periodic_Task(void *);

Software_Handle_Class Periodic_Handle("Periodic", 12, Periodic_Class::Load);

#endif