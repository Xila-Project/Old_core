#include "Xila.hpp"

void setup()
{
    Xila.Start();
}

void loop()
{
    vTaskDelete(NULL);
}
