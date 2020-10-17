#ifndef ULTRASONIC_HPP_DEFINED
#define ULTRASONIC_HPP_DEFINED

#include "GalaxOS.hpp"

#define SOUND_SPEED_AIR 343

class Ultrasonic_Class : public Software_Class
{
protected:

    byte Trig_Pin;
    byte Echo_Pin;
    float Offset;

    static Ultrasonic_Class* Instance_Pointer;

    xTaskHandle Socket_Handle;

    void Read();

    void Set_Parameters();
    void Measure();


public:

    Ultrasonic_Class();
    ~Ultrasonic_Class();

    static Software_Class* Load();

    friend void Ultrasonic_Task(void *pvParameters);
};

void Ultrasonic_Task(void *pvParameters);

Software_Handle_Class Ultrasonic_Handle("Ultrasonic", 12, Ultrasonic_Class::Load)

#endif