#include "Ultrasonic.hpp"

Ultrasonic_Class* Ultrasonic_Class::Instance_Pointer = NULL;

#define INSTANCE_POINTER Ultrasonic_Class::Instance_Pointer

Ultrasonic_Class::Ultrasonic_Class() : Software_Class(5),
Trig_Pin(8),
Echo_Pin(9),
Offset(0)
{

}

Ultrasonic_Class::~Ultrasonic_Class()
{
}

Software_Class* Ultrasonic_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Ultrasonic_Class;
  }
  return Instance_Pointer;
}

void Ultrasonic_Task(void* pvParameters)
{
  (void)pvParameters;
  while(1)
  {
    switch (INSTANCE_POINTER->Get_Command())
    {
      case 0x0000: // IDLE : measure
        
        break;
      case Close:
        delete INSTANCE_POINTER;
        vTaskDelete(NULL);
        break;
      case Minimize:
        vTaskSuspend(NULL);
        break;
      case 0x5350: // SP : set parameters
        INSTANCE_POINTER->Set_Parameters();
        break;
      default:
        break;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

void Ultrasonic_Class::Set_Parameters()
{
  GalaxOS.Get_Variable('E', &Echo_Pin, 0, Handle_Pointer);
  GalaxOS.Get_Variable('T', &Trig_Pin, 0, Handle_Pointer);
  GalaxOS.Get_Variable('O', &Offset, 0, Handle_Pointer);
}

void Ultrasonic_Class::Read()
{
  digitalWrite(Trig_Pin, LOW);
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
      GalaxOS.Display.Set_Value(F("DISTANCE_NUM"), Distance);
      vTaskDelay(100);
    }
}