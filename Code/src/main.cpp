#include "Xila.hpp"

void setup()
{
  Xila.System.Start();
}

void loop()
{
  vTaskDelete(NULL);
}
