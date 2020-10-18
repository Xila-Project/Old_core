#include "piano.hpp"

Piano_Class* Piano_Class::Instance_Pointer = NULL;
#define INSTANCE_POINTER Piano_Class::Instance_Pointer

Piano_Class::Piano_Class() : Software_Class(6),
Offset(0),
Duration(200),
MIDI_Output(false)
{
    xTaskCreatePinnedToCore(Piano_Task, "Piano Task", 4*1024, NULL, 1, &Task_Handle, 0);
}

Piano_Class::~Piano_Class()
{
    Instance_Pointer = NULL;
}

void Piano_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        switch (INSTANCE_POINTER->Get_Command())
        {
        case 0: //idle state
            vTaskDelay(pdMS_TO_TICKS(10));
            break;

        case 0x4320: //C
            INSTANCE_POINTER->Play_Note(0);
            break;

        case 0x4323: //C#
            INSTANCE_POINTER->Play_Note(1);

            break;

        case 0x4420: //D
            INSTANCE_POINTER->Play_Note(2);

            break;

        case 0x4423: //D#
            INSTANCE_POINTER->Play_Note(3);

            break;

        case 0x4520: //E
            INSTANCE_POINTER->Play_Note(4);
            break;

        case 0x4620: //F
            INSTANCE_POINTER->Play_Note(5);
            break;

        case 0x4623: //F#
            INSTANCE_POINTER->Play_Note(6);
            break;

        case 0x4720: //G
            INSTANCE_POINTER->Play_Note(7);
            break;

        case 0x4723: //G#
            INSTANCE_POINTER->Play_Note(8);
            break;

        case 0x4120: //A
            INSTANCE_POINTER->Play_Note(9);
            break;

        case 0x4123: //A#
            INSTANCE_POINTER->Play_Note(10);
            break;

        case 0x4220: //B
            INSTANCE_POINTER->Play_Note(11);
            break;

        case 0x6320: //c
            INSTANCE_POINTER->Play_Note(12);
            break;

        case 0x6323: //c#
            INSTANCE_POINTER->Play_Note(13);
            break;

        case 0x6420: //d
            INSTANCE_POINTER->Play_Note(14);
            break;

        case 0x6423: //d#
            INSTANCE_POINTER->Play_Note(15);
            break;

        case 0x6520: //e
            INSTANCE_POINTER->Play_Note(16);
            break;

        case 0x6620: //f
            INSTANCE_POINTER->Play_Note(17);
            break;

        case 0x6623: //f#
            INSTANCE_POINTER->Play_Note(18);
            break;

        case 0x6720: //g
            INSTANCE_POINTER->Play_Note(19);
            break;

        case 0x6723: //g#
            INSTANCE_POINTER->Play_Note(20);
            break;

        case 0x6120: //a
            INSTANCE_POINTER->Play_Note(21);
            break;

        case 0x6123: //a#
            INSTANCE_POINTER->Play_Note(22);
            break;

        case 0x6220: //b
            INSTANCE_POINTER->Play_Note(23);
            break;

        default:
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void Piano_Class::Play_Note(uint8_t Note)
{
    Current_Note = Note_Frequency[Note] + Offset;
    GalaxOS.Sound.Tone(Current_Note, Duration);
    GalaxOS.Display.Set_Text(F("FREQUENCY_TXT"), "Frequency : " + String(Current_Note));
    GalaxOS.Display.Set_Text(F("MIDICODE_TXT"), "MIDI Code : " + String(Note));   
    if (MIDI_Output == true)
    {
        Serial.write(144);
        Serial.write(Note);
        Serial.write(128);
        delay(Duration);
        Serial.write(128);
        Serial.write(Note);
        Serial.write(128);
    }
}

#undef INSTANCE_POINTER