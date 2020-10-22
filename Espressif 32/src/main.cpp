#include "GalaxOS.hpp"

void setup()
{
    xTaskCreatePinnedToCore(GalaxOS_Class::Core_Task, "Core Task", 4 * 1024, NULL, SYSTEM_TASK_PRIORITY, NULL, SYSTEM_CORE);
}

void loop()
{
    vTaskDelete(NULL);
}
