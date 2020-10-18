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
  Instance_Pointer = NULL;
}

Software_Class* Ultrasonic_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Ultrasonic_Class;
  }
  return Instance_Pointer;
}

void Ultrasonic_Class::Set_Variable(void* Variable_Pointer, uint8_t Type, uint8_t Adress)
{
  uint32_t Temporary_Long = 0;
  switch (Type)
  {
    case GalaxOS.Code::Variable_String_Local:
      Temporary_Long = (uint32_t)Variable_Pointer;
      break;
  }
  switch (Adress)
  {
    case 'E':
      Echo_Pin = Temporary_Long;
      break;
    case 'T':
      Trig_Pin = Temporary_Long;
      break;
    case 'O':
      Offset = Temporary_Long;
      break;
    default:
      break;
  } 
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
      case 0x4E53: // NS
        if (INSTANCE_POINTER->Shape < 5)
        {
          INSTANCE_POINTER->Shape++;
        }
        else
        {
          INSTANCE_POINTER->Shape = 0;
        }
        INSTANCE_POINTER->Draw_Shape();
        break;
      case 0x4C53: // LS
        if (INSTANCE_POINTER->Shape > 0)
        {
          INSTANCE_POINTER->Shape--;
        }
        else
        {
          INSTANCE_POINTER->Shape = 5;
        }
        INSTANCE_POINTER->Draw_Shape();
        break;
      case 0x4D45: // ME : mease 
        INSTANCE_POINTER->Read();
        break;
      case 0x5331: // S1 : Set variable
        INSTANCE_POINTER->Set(1);
        break;
      case 0x5332: // S2
        INSTANCE_POINTER->Set(2);
        break;
      case 0x5333: // S3
        INSTANCE_POINTER->Set(3);
        break;
      default:
        break;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

void Ultrasonic_Class::Draw_Shape()
{
  switch (Shape)
  {

  }
}

void Ultrasonic_Class::Set(uint8_t Selected_Variable)
{
  Measure[Selected_Variable] = Measure[0];
  Execute(0x4D45);
}

void Ultrasonic_Class::Read()
{
    digitalWrite(Trig_Pin, LOW);
    digitalWrite(Trig_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig_Pin, LOW);
    Measure[0] = pulseIn(Echo_Pin, HIGH);
    if (Measure[0] > 30000)
    {
      Verbose_Print_Line("> Onde perdue");
    }
    else
    {
      Measure[0] /= 2;
      Measure[0] /= 1000000;
      Measure[0] *= SOUND_SPEED_AIR;
      GalaxOS.Display.Set_Value(F("DISTANCE_NUM"), Measure[0]);
      switch (Shape) // calculate
      {
        case 0x00:
          break;
        default:
          break;
      }
      vTaskDelay(pdMS_TO_TICKS(100));
      Execute(0x4D45);
    }
}

#undef INSTANCE_POINTER