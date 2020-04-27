#include "software.h"

GalaxOS_Software_Class::GalaxOS_Software_Class(String const& Software_Name, byte const& First_Page_To_Set, byte const& Last_Page_To_Set) //constructor
{ 
  Number_Instance++;
  for (byte i = 0; i < 20; i++)
  {
    Name[i] = 32;
  }
  for (byte i = 0; i < 16; i++)
  {
    Function_Pointer[i] = NULL;
  }
    
}

GalaxOS_Software_Class::~GalaxOS_Software_Class() //desctructor
{
  Number_Instance--;
}

void GalaxOS_Software_Class::Set_Function_Pointer(byte const& Function_Pointer_ID, void (*Function_Pointer_To_Set)())
{
  Function_Pointer[Function_Pointer_ID] = Function_Pointer_To_Set;
}

void GalaxOS_Software_Class::Set_Software_Name(char (&Software_Name_To_Set)[20])
{
  strncpy(Name, Software_Name_To_Set, 20);
}