#include "Xila.hpp"

#include "Software/Shell/Shell.hpp"
#include "Software/Preferences/Preferences.hpp"
#include "Software/File_Manager/File_Manager.hpp"
#include "Software/Berry/Berry.hpp"

void setup()
{
  Xila::System.Start();
}

void loop()
{
  vTaskDelete(NULL);
}
