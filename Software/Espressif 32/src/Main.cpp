#include "Xila.hpp"

void setup()
{
    Xila.Start();

    // External :
    // Xila.Start_External();
}

void loop()
{
    vTaskDelete(NULL);
}
