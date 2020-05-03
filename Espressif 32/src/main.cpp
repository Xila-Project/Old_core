#include "galaxos.hpp"
#include "object.hpp"

void setup() {
    GalaxOS.Start();
}

void loop() {
    vTaskDelete(NULL);
}
