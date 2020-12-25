#include "Executable_Loader.hpp"

Executable_Loader::Executable_Loader() : Software_Class(2)
{
}

Executable_Loader::~Executable_Loader()
{
    Instance_Pointer = NULL;
}

Software_Class *Executable_Loader::Load()
{
    if (Instance_Pointer == NULL)
    {
        Instance_Pointer = new Executable_Loader();
    }
    return Instance_Pointer;
}

void Executable_Loader::Open_File(File &File_To_Open)
{
    if (File_To_Open.size() == 0)
    {
        //error : empty file
        File_To_Open.close();
        return;
    }
    if (Update.begin(File_To_Open.size()))
    {
        if (Update.writeStream(File_To_Open) != File_To_Open.size())
        {
            //error : update perform partialy
            File_To_Open.close();
            return;
        }
        if (Update.end() && Update.isFinished())
        {
            //info : update completed
        }
        else
        {
            //error : update went wrong
        }
    }
    else
    {
        //error : not enought space to perform OTA
    }
};