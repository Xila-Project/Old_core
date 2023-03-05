#include "Xila.hpp"
#include "esp_log.h"

void setup()
{
  Xila::System.Start();
}

void loop()
{
  vTaskDelete(NULL);
}
