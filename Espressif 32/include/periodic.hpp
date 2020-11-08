#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "GalaxOS.hpp"

// JSON Data file : 
// Creative Commons Attribution-ShareAlike 3.0 liscence
// https://github.com/Bowserinator/Periodic-Table-JSON


class Periodic_Class : protected Software_Class
{
    protected:
        static Periodic_Class* Instance_Pointer;

        File Periodic_File;

        uint8_t Current_Atom;

        uint32_t X, Y;

        char Name[16];

        void Get_Main_Data();
        void Get_Data();
        void Get_List();

        void Set_Variable(const void* Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    public:

        Periodic_Class();
        ~Periodic_Class();

        static void Main_Task(void *);

        static Software_Class* Load();

        enum Picture
        {
            Periodic_32 = 46
        };

};

Software_Handle_Class Periodic_Handle("Periodic", Periodic_Class::Periodic_32, Periodic_Class::Load);

#endif