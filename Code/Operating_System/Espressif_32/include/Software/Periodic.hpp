#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "Xila.hpp"

// JSON Data file : 
// Creative Commons Attribution-ShareAlike 3.0 liscence
// https://github.com/Bowserinator/Periodic-Table-JSON

#define Periodic_File(name) Software_Directory_Path "/Periodic/" name

class Periodic_Class : protected Software_Class
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



        void Set_Variable(const void* Variable, uint8_t Type, uint8_t Adress, uint8_t Size = 0);

    public:

        Periodic_Class();
        ~Periodic_Class();

        static void Main_Task(void *);

        static Software_Class* Load();

        enum Image
        {
            Icon_32 = Xila.Display.Periodic
        };

};

Software_Handle_Class Periodic_Handle("Periodic", Periodic_Class::Icon_32, Periodic_Class::Load);

#endif