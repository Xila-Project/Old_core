#include "Xila.hpp"
#include "unity.h"
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
