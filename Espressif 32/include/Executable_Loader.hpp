#ifndef EXECUTABLE_LOADER_INCLUDED
#define EXECUTABLE_LOADER_INCLUDED

#include "GalaxOS.hpp"

// Used to load external

class Executable_Loader : protected Software_Class
{
    protected:

    public:
        Executable_Loader();
        ~Executable_Loader();

        void Open_File(File&);

        static Software_Class* Load();

};

Software_Handle_Class Executable_Loader_Handle("Executable Loader", 0, Executable_Loader::Load);

#endif