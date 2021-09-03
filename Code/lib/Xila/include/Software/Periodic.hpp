#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "Xila.hpp"

// JSON Data file : 
// Creative Commons Attribution-ShareAlike 3.0 liscence
// https://github.com/Bowserinator/Periodic-Table-JSON

#define Periodic_File(name) Software_Directory_Path "/Periodic/" name

class Periodic_Class : protected Xila_Class::Software
{
    protected:
        static Periodic_Class* Instance_Pointer;

        File Periodic_File;

        char Current_Atom_Name[32];

        uint8_t Tab;

        float X, Y;

        uint8_t Line;

        void Get_Atom_Name();
        void Get_Main_Data();
        void Get_Data();
        void Get_List();

        void Set_Variable(Xila_Class::Address, uint8_t, const void *);

    public:

        Periodic_Class();
        ~Periodic_Class();

        static Xila_Class::Task_Function Main_Task(void *);

        static Xila_Class::Software* Load();

        enum Image
        {
            Icon_32 = Xila.Display.Periodic_Images
        };

};

Xila_Class::Software_Handle Periodic_Handle("Periodic", Periodic_Class::Icon_32, Periodic_Class::Load);

#endif