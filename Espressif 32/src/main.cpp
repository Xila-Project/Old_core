#include "galaxos.h"
#include "object.h"

void setup() {
    GalaxOS.Start();
}

void loop() {
    vTaskDelete(NULL);
}
