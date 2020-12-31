#ifndef ULTRASONIC_HPP_DEFINED
#define ULTRASONIC_HPP_DEFINED

#include "Xila.hpp"

#define SOUND_SPEED_AIR 343

class Ultrasonic_Class : public Software_Class
{
protected:

    byte Trig_Pin;
    byte Echo_Pin;
    double Offset;

    uint8_t Shape;

    float Measure[5];

    static Ultrasonic_Class* Instance_Pointer;

    void Read();
    void Compute();
    void Draw_Shape();

    void Set_Variable(void*, uint8_t, uint8_t);


public:

    Ultrasonic_Class();
    ~Ultrasonic_Class();

    static Software_Class* Load();

    static void Main_Task(void*);

    enum Picture_ID
    {
        Ultrasonic_32 = 47
    };
};

Software_Handle_Class Ultrasonic_Handle("Ultrasonic", Ultrasonic_Class::Ultrasonic_32, Ultrasonic_Class::Load);

#endif