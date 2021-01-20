#include "Xila.hpp"
#include "unity.h"

void setup()
{
    Xila.Start();
}

void loop()
{
    vTaskDelete(NULL);
}
