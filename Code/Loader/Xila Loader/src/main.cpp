#include <Arduino.h>

#include "Loader.hpp"

void setup() {
  Xila_Loader.Start();
}

void loop() {
  vTaskDelete(NULL);
}