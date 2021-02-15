#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED

#include "Xila.hpp"

// JSON Data file : 
// Creative Commons Attribution-ShareAlike 3.0 liscence
// https://github.com/Bowserinator/Periodic-Table-JSON

#define PERIODIC_FILE_PATH "/SOFTWARE/PERIODIC/DATA/PERIODIC.XRF"

class Periodic_Class : protected Software_Class
{
    protected:
        static Periodic_Class* Instance_Pointer;

        File Periodic_File;

        char Current_Atom_Name[32];

        float X, Y;

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

        enum Picture
        {
            Periodic_32 = 46
        };

};

Software_Handle_Class Periodic_Handle("Periodic", Periodic_Class::Periodic_32, Periodic_Class::Load);

#endif