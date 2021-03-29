#include "Ultrasonic.hpp"

Ultrasonic_Class *Ultrasonic_Class::Instance_Pointer = NULL;

Ultrasonic_Class::Ultrasonic_Class() : Software_Class(Ultrasonic_Handle),
                                       Trig_Pin(8),
                                       Echo_Pin(9),
                                       Offset(0),
                                       Shape(0)
{
  Xila.Task.Create(Main_Task, "Ultrasonic Task", Memory_Chunk(4), NULL, &Task_Handle);
}

Ultrasonic_Class::~Ultrasonic_Class()
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = NULL;
}

Software_Class *Ultrasonic_Class::Load()
{
  if (Instance_Pointer != NULL)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = new Ultrasonic_Class();
  return Instance_Pointer;
}

void Ultrasonic_Class::Set_Variable(void *Variable_Pointer, uint8_t Type, uint8_t Adress)
{
  switch (Adress)
  {
  case 'E':
    Echo_Pin = *(uint8_t *)Variable_Pointer;
    break;
  case 'T':
    Trig_Pin = *(uint8_t *)Variable_Pointer;
    break;
  case 'O':
    Offset = *(double *)Variable_Pointer;
    break;
  default:
    break;
  }
}

void Ultrasonic_Class::Main_Task(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    switch (Instance_Pointer->Get_Instruction())
    {
    case 0x0000: // IDLE : measure
      Instance_Pointer->Read();
      Xila.Task.Delay(10);
      break;
    case Open:
      Xila.Display.Set_Current_Page(F("Ultrasonic"));
      break;
    case Close:
      delete Instance_Pointer;
      vTaskDelete(NULL);
      break;
    case Minimize:
      vTaskSuspend(NULL);
      break;
    case Maximize:
      Xila.Display.Set_Current_Page(F("Ultrasonic"));
      break;
    case Instruction('N', 'S'): // NS
      if (Instance_Pointer->Shape < 3)
      {
        Instance_Pointer->Shape++;
      }
      else
      {
        Instance_Pointer->Shape = 0;
      }
      Instance_Pointer->Draw_Shape();
      break;
    case Instruction('L', 'S'): // LS
      if (Instance_Pointer->Shape > 0)
      {
        Instance_Pointer->Shape--;
      }
      else
      {
        Instance_Pointer->Shape = 3;
      }
      Instance_Pointer->Draw_Shape();
      break;
    case Instruction('S', '1'): // S1 : Set variable
      Instance_Pointer->Measure[1] = Instance_Pointer->Measure[0];
      Xila.Display.Set_Value(F("MEASURE1_FLO"), Instance_Pointer->Measure[1]);
      Instance_Pointer->Compute();
      break;
    case Instruction('S', '2'): // S2
      Instance_Pointer->Measure[2] = Instance_Pointer->Measure[0];
      Xila.Display.Set_Value(F("MEASURE2_FLO"), Instance_Pointer->Measure[2]);
      Instance_Pointer->Compute();
      break;
    case Instruction('S', '3'): // S3
      Instance_Pointer->Measure[3] = Instance_Pointer->Measure[0];
      Xila.Display.Set_Value(F("MEASURE3_FLO"), Instance_Pointer->Measure[3]);
      Instance_Pointer->Compute();
      break;
    case Instruction('C', '1'): // S1 : Set variable
      Instance_Pointer->Measure[1] = 0;
      Xila.Display.Set_Value(F("MEASURE1_FLO"), 0);
      Instance_Pointer->Compute();
      break;
    case Instruction('C', '2'): // S2
      Instance_Pointer->Measure[2] = 0;
      Xila.Display.Set_Value(F("MEASURE2_FLO"), 0);
      Instance_Pointer->Compute();
      break;
    case Instruction('C', '3'): // S3
      Instance_Pointer->Measure[3] = 0;
      Xila.Display.Set_Value(F("MEASURE3_FLO"), 0);
      Instance_Pointer->Compute();
      break;
    default:
      break;
    }
    Xila.Task.Delay(10);
  }
}

void Ultrasonic_Class::Draw_Shape()
{
  Xila.Display.Set_Value(F("SHAPE_VAR"), Shape);
  Xila.Display.Click(F("DRAWSHAPE_HOT"), 1);
}

void Ultrasonic_Class::Compute()
{
  switch (Shape)
  {
  case 0:
    Xila.Display.Set_Value(F("SHAPE_FLO"), Measure[1]);
    Xila.Display.Set_Text(F("UNIT4_TXT"), F("mm"));
    break;
  case 1:
    Measure[4] = Measure[1] * Measure[2];
    Xila.Display.Set_Value(F("SHAPE_FLO"), Measure[4]);
    Xila.Display.Set_Text(F("UNIT4_TXT"), F("m²"));
    break;
  case 2:
    if (Measure[1] == 0)
    {
      Measure[1] = sq(Measure[3]);
      Measure[1] -= sq(Measure[2]);
      Measure[1] = sqrt(Measure[1]);
      Xila.Display.Set_Value(F("MEASURE3_FLO"), Measure[1]);
    }
    else if (Measure[2] == 0)
    {
      Measure[2] = sq(Measure[3]);
      Measure[2] -= sq(Measure[1]);
      Measure[2] = sqrt(Measure[2]);
      Xila.Display.Set_Value(F("MEASURE3_FLO"), Measure[2]);
    }
    else
    {
      Measure[3] = sq(Measure[1]);
      Measure[3] += sq(Measure[2]);
      Measure[3] = sqrt(Measure[3]);
      Xila.Display.Set_Value(F("MEASURE3_FLO"), Measure[3]);
    }
    Xila.Display.Set_Value(F("SHAPE_FLO"), 0);
    Xila.Display.Set_Text(F("UNIT4_TXT"), F(""));
    break;
  case 3:
    Measure[4] = Measure[1] * Measure[2];
    Measure[4] *= Measure[3];
    Xila.Display.Set_Value(F("SHAPE_FLO"), Measure[4]);
    Xila.Display.Set_Text(F("UNIT4_TXT"), F("mm³"));
    break;
  }
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
    Xila.Display.Set_Value(F("DISTVAL_NUM"), 0);
  }
  else
  {
    Measure[0] /= 2;
    Measure[0] /= 1000000;
    Measure[0] *= SOUND_SPEED_AIR;
    Measure[0] -= Offset;
    Xila.Display.Set_Value(F("DISTVAL_NUM"), Measure[0]);
  }
}