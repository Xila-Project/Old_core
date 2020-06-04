#ifndef SOFTWARE_H_INCLUDED
#define SOTFWARE_H_INCLUDED

#include "Arduino.h"

class Software_Handle_Class
{
    protected:
        static uint8_t Number_Instance; //max class ID
        uint8_t Identificator;
        uint8_t Icon_ID;
        char Name[24];

    public:
        Software_Handle_Class(char const* Software_Name, uint8_t Icon_ID)
        {
            Number_Instance++;
        }
        static void Open();

 };

class GalaxOS_Software_Class //Software descriptor, read by GalaxOS
{
protected:
    
    char Name[20]; //used to name Directory, Menu etc ...
    
    byte First_Page_ID;
    
    byte Last_Page_ID;
    
    void (*Function_Pointer[16])();

    static GalaxOS_Software_Class* Software_Pointer;

    TaskHandle_t Socket_Handle;

    uint16_t Socket_Method;


public:

    GalaxOS_Software_Class(const char* Software_Name, byte const &First_Page_To_Set, byte const &Last_Page_To_Set);
    ~GalaxOS_Software_Class();
    
    //API used by GALAXOS

    void Open();
    void Maximize();
    void Minimize();
    void Close();

    void Open_File();

    void Execute(uint16_t const& Socket_Method_To_Set);
    void Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2);

    void Set_Socket_Method(uint16_t const& Socket_Method_To_Set);
    uint16_t& Get_Socket_Method();

};

#endif
