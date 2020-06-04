#include "software.hpp"

GalaxOS_Software_Class *GalaxOS_Software_Class::Software_Pointer = NULL;

GalaxOS_Software_Class::GalaxOS_Software_Class(const char* Software_Name, byte const& First_Page_To_Set, byte const& Last_Page_To_Set) //constructor
{
  strcpy(Name, Software_Name);
  First_Page_ID = First_Page_To_Set;
  Last_Page_ID = Last_Page_To_Set;
}

GalaxOS_Software_Class::~GalaxOS_Software_Class() //desctructor
{
  if (Software_Pointer != this)
  {
    delete Software_Pointer;
  }
  Software_Pointer == NULL;
}

void GalaxOS_Software_Class::Execute(uint16_t const& Socket_Method_To_Set)
{
  Socket_Method = Socket_Method_To_Set;
  vTaskResume(Socket_Handle);
}

void GalaxOS_Software_Class::Execute(char const& Socket_Method_Char1, char const& Socket_Method_Char2)
{
  Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
  vTaskResume(Socket_Handle);
}

void GalaxOS_Software_Class::Set_Socket_Method(uint16_t const& Socket_Method_To_Set)
{
  Socket_Method = Socket_Method_To_Set;
}

uint16_t& GalaxOS_Software_Class::Get_Socket_Method()
{
  return Socket_Method;
}