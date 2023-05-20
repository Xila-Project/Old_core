#include "Xila.hpp"

#include "Shell.hpp"
#include "Preferences.hpp"
#include "File_Manager.hpp"
#include "Berry.hpp"

void setup()
{
  Xila::Softwares.Register_Handle(Shell_Class::Handle);
  Xila::Softwares.Register_Handle(Preferences_Class::Handle);
  Xila::Softwares.Register_Handle(File_Manager_Class::Handle);
  
  Xila::System.Start();
  
  Berry_Class::Load_Softwares_Handles();
}

void loop()
{
  vTaskDelete(NULL);
}
