#include "Xila.hpp"

#include "Shell.hpp"
#include "Preferences.hpp"
#include "File_Manager.hpp"
#include "Berry.hpp"

using namespace Xila;

void setup()
{
  Softwares.Register_Handle(Shell_Class::Handle);
  Softwares.Register_Handle(Preferences_Class::Handle);
  Softwares.Register_Handle(File_Manager_Class::Handle);
  
  System.Start();
  
  Berry_Class::Load_Softwares_Handles();
}

void loop()
{
  vTaskDelete(NULL);
}
