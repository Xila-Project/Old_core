#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "WiFi.h"
#include "galaxos.h"

void setup() {
    GalaxOS.Start();
}

void loop() {
    vTaskDelete(NULL);
}
