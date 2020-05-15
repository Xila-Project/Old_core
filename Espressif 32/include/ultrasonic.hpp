#include "Arduino.h"

class Ultrasonic_Class //Application It self;
{
private:
    byte Trig_Pin;
    byte Echo_Pin;

    static uint8_t Number_Instance;

    uint16_t Socket_Method;

    xTaskHandle Socket_Handle;

    void Read();

public:

    Ultrasonic_Class();
    ~Ultrasonic_Class();

    void Execute(uint16_t const &Socket_Method_To_Set);
    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend void Ultrasonic_Socket(void *pvParameters);
};

void Ultrasonic_Socket(void *pvParameters); 