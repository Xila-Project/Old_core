#ifndef FILE_MANAGER_HPP_INCLUDED
#define FILE_MANAGER_HPP_INCLUDED

#include "Arduino.h"
#include "galaxos.hpp"

class File_Manager_Class
{
private:
    static uint8_t Number_Instance;

    uint16_t Socket_Method;

    xTaskHandle Socket_Handle;

    File Temporary_File;

    String Current_File_Path;

    void Display_Path();

    void Delete();

    void Go_Parent();

public:
    File_Manager_Class();
    ~File_Manager_Class();

    void Execute(uint16_t const &Socket_Method_To_Set);
    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend void File_Manager_Socket(void *pvParameters);
};

void File_Manager_Socket(void *pvParameters);

#endif