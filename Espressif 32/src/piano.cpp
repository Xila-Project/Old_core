#include "piano.hpp"
uint8_t Piano_Class::Number_Instance = 0;

void Piano_Socket(void *pvParameters)
{
    Piano_Class *Piano_Pointer = GalaxOS.Get_Software_Pointer();
    (void)pvParameters;
    for (;;)
    {
        switch (Piano_Pointer->Socket_Method)
        {
        case 0: //idle state

            break;

        case 0x4320: //C
            Piano_Pointer->Play_Note(0, 0);
            break;

        case 0x4323: //C#
            Piano_Pointer->Play_Note(16, 1);

            break;

        case 0x4420: //D
            Piano_Pointer->Play_Note(32, 2);

            break;

        case 0x4423: //D#
            Piano_Pointer->Play_Note(50, 3);

            break;

        case 0x4520: //E
            Piano_Pointer->Play_Note(68, 4);
            break;

        case 0x4620: //F
            Piano_Pointer->Play_Note(88, 5);
            break;

        case 0x4623: //F#
            Piano_Pointer->Play_Note(108, 6);
            break;

        case 0x4720: //G
            Piano_Pointer->Play_Note(130, 7);
            break;

        case 0x4723: //G#
            Piano_Pointer->Play_Note(154, 8);
            break;

        case 0x4120: //A
            Piano_Pointer->Play_Note(178, 9);
            break;

        case 0x4123: //A#
            Piano_Pointer->Play_Note(205, 10);
            break;

        case 0x4220: //B
            Piano_Pointer->Play_Note(232, 11);
            break;

        case 0x6320: //c
            Piano_Pointer->Play_Note(262, 12);
            break;

        case 0x6323: //c#
            Piano_Pointer->Play_Note(293, 13);
            break;

        case 0x6420: //d
            Piano_Pointer->Play_Note(326, 14);
            break;

        case 0x6423: //d#
            Piano_Pointer->Play_Note(361, 15);
            break;

        case 0x6520: //e
            Piano_Pointer->Play_Note(398, 16);
            break;

        case 0x6620: //f
            Piano_Pointer->Play_Note(437, 17);
            break;

        case 0x6623: //f#
            Piano_Pointer->Play_Note(478, 18);
            break;

        case 0x6720: //g
            Piano_Pointer->Play_Note(522, 19);
            break;

        case 0x6723: //g#
            Piano_Pointer->Play_Note(569, 20);
            break;

        case 0x6120: //a
            Piano_Pointer->Play_Note(618, 21);
            break;

        case 0x6123: //a#
            Piano_Pointer->Play_Note(670, 22);
            break;

        case 0x6220: //b
            Piano_Pointer->Play_Note(726, 23);
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

void Piano_Class::Play_Note(uint32_t Frequency, uint8_t Note)
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