#include "Core/Core.hpp"

// Main task for the core
void Xila_Class::Core_Task(void *pvParameters)
{
  Instance_Pointer->Loop();
}