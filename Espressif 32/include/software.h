#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"

class GalaxOS_Software_Class //Software descriptor, read by GalaxOS
{
    private:
        char Name[20]; //used to name Directory, Menu etc ...
        byte First_Page_ID;
        byte Last_Page_ID;
        void (*Function_Pointer[16])();
        static byte Number_Of_Software;
    public:
        GalaxOS_Software_Class(String const& Software_Name, byte const& First_Page_To_Set, byte const& Last_Page_To_Set);
        ~GalaxOS_Software_Class();
        void Set_Software_Name(char  (&Software_Name_To_Set)[20]);
        void Set_Function_Pointer(byte const& Function_Pointer_ID, void (*Function_Pointer_To_Set)());
};

#endif
