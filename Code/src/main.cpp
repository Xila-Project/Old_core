#include "Xila.hpp"

#include "Software/Shell/Shell.hpp"
#include "Software/Preferences/Preferences.hpp"
#include "Software/File_Manager/File_Manager.hpp"
#include "Software/Berry/Berry.hpp"

void setup()
{
  Xila::Softwares.Register_Handle(Shell_Class::Handle);
  Xila::Softwares.Register_Handle(Preferences_Class::Handle);
  Xila::Softwares.Register_Handle(File_Manager_Class::Handle);
  Xila::Softwares.Register_Handle(Berry_Class::Handle);

  Xila::System.Start();
  
  Berry_Class::Load_Softwares_Handles();
}

void loop()
{
  vTaskDelete(NULL);
}
