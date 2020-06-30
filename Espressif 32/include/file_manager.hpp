#ifndef FILE_MANAGER_HPP_INCLUDED
#define FILE_MANAGER_HPP_INCLUDED

#include "Arduino.h"
#include <FS.h>
#include "GalaxOS.hpp"


class File_Manager_Class : public Software_Class
{
protected:

    static File_Manager_Class* Instance_Pointer;

    File Temporary_File;

    uint8_t Mode;

    char* Current_File_Path;

    void Display_Path();

    void New();
    void Delete();
    void Rename();

    void Go_Parent();



    File_Manager_Class(Software_Handle_Class*);
    ~File_Manager_Class();

    Software_Class* Load(Software_Handle_Class*);

    friend void File_Manager_Task(void *);
};

void File_Manager_Task(void *);

#endif