#include "Ultrasonic.hpp"

uint8_t Ultrasonic_Class::Number_Instance = 0;

Ultrasonic_Class::Ultrasonic_Class()
{
    if (Number_Instance > 0) //check if an instance alread exist
    {
        delete this;
        return;
    }
    
    Number_Instance++;


}

Ultrasonic_Class::~Ultrasonic_Class()
{
}

void Ultrasonic_Class::Read()
{
  digitalWrite(Trig_Pin, LOW);
  while (Nextion_Serial.available() == 0)
  {
    digitalWrite(Trig_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig_Pin, LOW);
    unsigned long Duration = pulseIn(Echo_Pin, HIGH);
    if (Duration > 30000)
    {
      Serial.println(F("|| > Onde perdue                                         ||"));
    }
    else
    {
      Duration /= 2;
      float Time = Duration / 1000000;
      int Distance = Time * SOUND_SPEED_AIR;
      Serial.print(F("|| > Distance :"));
      Serial.println(Distance);
      Nextion_Serial.print(F("DISTVAL_NUM.val="));
      Nextion_Serial.print(Distance);
      Nextion_Serial.print(F("\xFF\xFF\xFF"));
      vTaskDelay(100);
    }
  }
}