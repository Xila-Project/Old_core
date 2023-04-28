/********************************************************************
** Copyright (c) 2018-2020 Guan Wenliang
** This file is part of the Berry default interpreter.
** skiars@qq.com, https://github.com/Skiars/berry
** See Copyright Notice in the LICENSE file or at
** https://github.com/Skiars/berry/blob/master/LICENSE
********************************************************************/
#include "Software/Berry/Berry.hpp"

extern "C"
{
#include "berry.h"
#include "be_mem.h"
#include "be_sys.h"
#include <stdio.h>
#include <string.h>
}

/* this file contains configuration for the file system. */

/* standard input and output */

BERRY_API void be_writebuffer(const char *buffer, size_t length)
{
    strlcat(Prompt_String, buffer, (80 + 1) * 24 + 1);
    Log.Print(buffer);
    // be_fwrite(stdout, buffer, length);
}

BERRY_API char *be_readstring(char *buffer, size_t size)
{
    strlcat(Prompt_String, buffer, (80 + 1) * 24 + 1);
    Log.Print(buffer);
    while (true)
    {
        Task_Type::Delay_Static(100);
    }
    
    return NULL;

    // return be_fgets(stdin, buffer, (int)size);
}

void *be_fopen(const char *filename, const char *modes)
{
    Log_Verbose("Berry", "Opening file: %s", filename);
    Log_Verbose("Berry", "Opening file with mode: %c", modes);
    File_Type *File = new File_Type;
    switch (modes[0])
    {
    case 'w':
        *File = Drive.Open(filename, true);
        break;
    case 'a':
        *File = Drive.Open(filename, true, true);
        break;
    default:
        *File = Drive.Open(filename);
        break;
    }
  
    if (*File)
    {
        return File;
    }
    else
    {
        delete File;
        return NULL;
    }
}

int be_fclose(void *hfile)
{
    Log_Verbose("Berry", "Closing file");
    if (hfile == NULL || hfile == stdout || hfile == stderr || hfile == stdin)
    {
        return false;
    }

    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        (*File).Close();
        delete File;
        return true;
    }
    
    delete File;
    return false;
    
}

size_t be_fwrite(void *hfile, const void *buffer, size_t length)
{
    if (hfile == NULL || hfile == stdout || hfile == stderr || hfile == stdin)
    {
        return 0;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        File->Write((const uint8_t*)buffer, length);
        return length;
    }
    return 0;
}

size_t be_fread(void *hfile, void *buffer, size_t length)
{
    Log_Verbose("Berry", "Reading file");
    if (hfile == NULL || hfile == stdout || hfile == stderr || hfile == stdin)
    {
        return 0;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        return File->Read((uint8_t*)buffer, length);
    }
    return 0;
}

char *be_fgets(void *hfile, void *buffer, int size)
{

    return NULL;
}

int be_fseek(void *hfile, long offset)
{
    if (hfile == NULL)
    {
        return false;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        return File->Seek(offset);
    }
    return false;
}

long int be_ftell(void *hfile)
{
    if (hfile == NULL)
    {
        return 0;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        return File->Get_Position();
    }
    return 0;
}

long int be_fflush(void *hfile)
{
    if (hfile == NULL)
    {
        return false;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        File->Flush();
        return 1;
    }
    return 0;
}

size_t be_fsize(void *hfile)
{
    if (hfile == NULL)
    {
        return 0;
    }
    File_Type* File = (File_Type*)hfile;
    if (*File)
    {
        return File->Get_Size();
    }
    return 0;
}

#if BE_USE_FILE_SYSTEM

int be_isdir(const char *path)
{
    if (path == NULL)
    {
        return false;
    }
    File_Type File = Drive.Open(path);
    if (File)
    {
        return File.Is_Directory();
    }
    return false;
}

int be_isfile(const char *path)
{
    if (path == NULL)
    {
        return false;
    }
    File_Type File = Drive.Open(path);
    if (File)
    {
        return !File.Is_Directory();
    }
    return false;
}

int be_isexist(const char *path)
{
    if (Drive.Exists(path))
    {
        return true;
    }
    return false;
}

char *be_getcwd(char *buf, size_t size)
{
    // TODO
    return buf;
}

int be_chdir(const char *path)
{
    // TODO 
    return 0;
    //return f_chdir(path);
}

int be_mkdir(const char *path)
{
    if (Drive.Make_Directory(path) == Result_Type::Success)
    {
        return 0;
    }
    return 1;
}

int be_unlink(const char *filename)
{
    return false;
}

int be_dirfirst(bdirinfo *info, const char *Path)
{
    File_Type* Directory = new File_Type;
    *Directory = Drive.Open(Path);
    File_Type* File = new File_Type;
    if (*Directory)
    {
        Directory->Rewind_Directory();
        *File = Directory->Open_Next_File();
        if (*File)
        {
            info->dir = Directory;
            info->file = File;
            return 0;
        }
    }
    delete Directory;
    delete File;
    info->dir = NULL;
    info->file = NULL;
    return 1;
}

int be_dirnext(bdirinfo *info)
{
    if (info->dir == NULL)
    {
        return true;
    }
    if (info->file == NULL)
    {
        info->file = new File_Type;
    }
    File_Type* Directory = (File_Type*)info->dir;
    *(File_Type*)info->file = Directory->Open_Next_File();
    
    if (*(File_Type*)info->file)
    {
        return false;
    }
    
    delete (File_Type*)info->file;
    info->file = NULL;

    File_Type* File = (File_Type*)info->file; 

    info->name = File->Get_Name();
    return true;
}

int be_dirclose(bdirinfo *info)
{
    if (info->dir != NULL)
    {
        if (*(File_Type*)info->dir)
        {
            File_Type* Directory = (File_Type*)info->dir;
            Directory->Close();
        }
        delete (File_Type*)info->dir;
        delete (File_Type*)info->file;
        info->dir = NULL;
        info->file = NULL;
        
    }
    return true;
}

#endif /* BE_USE_OS_MODULE || BE_USE_FILE_SYSTEM */
