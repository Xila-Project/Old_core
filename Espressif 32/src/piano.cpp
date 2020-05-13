#include "piano.hpp"
#include "object.hpp"

uint8_t Piano_Class::Number_Instance = 0;

void Piano_Socket(void *pvParameters)
{
    Piano_Class *Piano_Pointer = GalaxOS.Get_Software_Pointer();
    (void)pvParameters;
    for (;;)
    {
        switch (Piano_Pointer->Socket_Handle)
        {
        case 0: //idle state
            
            break;
        
        case : //PL
            Piano_Pointer->Play_Note();
            break;

        default:
            break;
        }
        Piano_Pointer->Socket_Method = 0;
        vTaskSuspend(Piano_Pointer->Socket_Handle);
    }
}

void Piano_Class::Execute(uint32_t const& Socket_Method_To_Set)
{
    Socket_Method = Socket_Method_To_Set;
    vTaskResume(Socket_Handle);
}

void Piano_Class::Play_Note()
{
    ledcAttachPin(GalaxOS.Get_Speaker_Pin(), 0);
  String Temporary = "";
  unsigned long Duration = 200;
  Frequency += GalaxOS.Get_C_Frequency();
  Note += GalaxOS.Get_C_MIDI();
  Temporary = "Frequency : " + String(Frequency, DEC);
  Nextion_Serial.print(F("FREQUENCY_TXT.txt=\""));
  Nextion_Serial.print(Temporary);
  Nextion_Serial.print(F("\xFF\xFF\xFF"));
  Temporary = "MIDI Code : " + String(Note, DEC);
  Nextion_Serial.print(F("MIDICODE_TXT.txt=\""));
  Nextion_Serial.print(Temporary);
  Nextion_Serial.print(F("\xFF\xFF\xFF"));
  if (GalaxOS.MIDIOutEnable == true)
  {
    Serial.write(144);
    Serial.write(Note);
    Serial.write(128);
    delay(Duration);
    Serial.write(128);
    Serial.write(Note);
    Serial.write(128);
  }
  ledcWriteTone(0, Frequency);
  vTaskDelay(pdMS_TO_TICKS(Duration));
  ledcWriteTone(0, 0);
}