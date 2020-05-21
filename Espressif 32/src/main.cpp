#include "galaxos.hpp"

void setup() {
    GalaxOS.Start();
}

void loop() {
    vTaskDelete(NULL);
}
