#include "Oscilloscope.hpp"

extern GalaxOS_Class GalaxOS;

#define INSTANCE_POINTER Oscilloscope_Class::Instance_Pointer
Oscilloscope_Class *Oscilloscope_Class::Instance_Pointer = NULL;

Oscilloscope_Class::Oscilloscope_Class() : Software_Class(6)
{

    Instance_Pointer = this;

    xTaskCreatePinnedToCore(Oscilloscope_Task, "Oscilloscope", 2 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
    xTaskCreatePinnedToCore(SigmaDelta_Task, "SigmaDelta", 2 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &SigmaDelta_Handle, SOFTWARE_CORE);
}

Oscilloscope_Class::~Oscilloscope_Class()
{
    Instance_Pointer = NULL;
}

Software_Class* Oscilloscope_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    return new Oscilloscope_Class;
  }
  return Instance_Pointer;
}

void SigmaDelta_Task(void *pvParameters)
{
    sigmaDeltaSetup(0, 312500);
    sigmaDeltaAttachPin(5, 0);
    sigmaDeltaWrite(0, 0);
    while (1)
    {
        static uint8_t i = 0;
        sigmaDeltaWrite(0, i++);
        delayMicroseconds(50);
    }
    vTaskDelete(NULL);
}

void Oscilloscope_Task(void *pvParameters)
{
    (void)pvParameters;
    while (1)
    {
        if (INSTANCE_POINTER->trig_mode != INSTANCE_POINTER->TRIG_SCAN)
        {
            unsigned long st = millis();
            short oad = (INSTANCE_POINTER->trig_ch == 0) ? (INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off)) : (INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off));
            for (;;)
            {
                short ad;
                if (INSTANCE_POINTER->trig_ch == 0)
                {
                    ad = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                }
                else
                {
                    ad = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }

                if (INSTANCE_POINTER->trig_edge == INSTANCE_POINTER->TRIG_E_UP)
                {
                    if (ad >= INSTANCE_POINTER->trig_lv && ad > oad)
                    {
                        break;
                    }
                }
                else
                {
                    if (ad <= INSTANCE_POINTER->trig_lv && ad < oad)
                    {
                        break;
                    }
                }
                oad = ad;
                INSTANCE_POINTER->Refresh_User_Interface();
                if (INSTANCE_POINTER->trig_mode == INSTANCE_POINTER->TRIG_SCAN)
                {
                    break;
                }
                if (INSTANCE_POINTER->trig_mode == INSTANCE_POINTER->TRIG_AUTO && (millis() - st) > 100)
                {
                    break;
                }
            }
        }

        // sample and draw depending on the sampling rate
        if (INSTANCE_POINTER->rate <= 5 && INSTANCE_POINTER->Start)
        {
            (INSTANCE_POINTER->sample == 0) ? (INSTANCE_POINTER->sample = 2) : (INSTANCE_POINTER->sample = 0); // change the index for the double buffer

            if (INSTANCE_POINTER->rate == 0) // full speed, channel 0 only
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                }
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = 0;
                }
            }
            else if (INSTANCE_POINTER->rate == 1) // full speed, channel 1 only
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = 0;
                }
            }
            else if (INSTANCE_POINTER->rate == 2) // full speed, dual channel
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
            }
            else if (INSTANCE_POINTER->rate >= 3 && INSTANCE_POINTER->rate <= 5) // .5ms, 1ms or 2ms sampling
            {
                const unsigned long r_[] = {5000 / INSTANCE_POINTER->DOTS_DIV, 10000 / INSTANCE_POINTER->DOTS_DIV, 20000 / INSTANCE_POINTER->DOTS_DIV};
                unsigned long st = micros();
                unsigned long r = r_[INSTANCE_POINTER->rate - 3];
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    while ((st - micros()) < r)
                    {
                        ;
                    }
                    st += r;
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
            }
            INSTANCE_POINTER->Refresh_Waveform();
            INSTANCE_POINTER->Refresh_User_Interface();
        }
        else if (INSTANCE_POINTER->Start)
        { // 5ms - 500ms sampling
            // copy currently showing data to another
            if (INSTANCE_POINTER->sample == 0)
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[2][i] = INSTANCE_POINTER->data[0][i];
                    INSTANCE_POINTER->data[3][i] = INSTANCE_POINTER->data[1][i];
                }
            }
            else
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[0][i] = INSTANCE_POINTER->data[2][i];
                    INSTANCE_POINTER->data[1][i] = INSTANCE_POINTER->data[3][i];
                }
            }

            const unsigned long r_[] = {50000 / INSTANCE_POINTER->DOTS_DIV, 100000 / INSTANCE_POINTER->DOTS_DIV, 200000 / INSTANCE_POINTER->DOTS_DIV,
                                        500000 / INSTANCE_POINTER->DOTS_DIV, 1000000 / INSTANCE_POINTER->DOTS_DIV, 2000000 / INSTANCE_POINTER->DOTS_DIV,
                                        5000000 / INSTANCE_POINTER->DOTS_DIV, 10000000 / INSTANCE_POINTER->DOTS_DIV};
            unsigned long st = micros();
            for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
            {
                while ((st - micros()) < r_[INSTANCE_POINTER->rate - 6])
                {
                    INSTANCE_POINTER->Refresh_User_Interface();
                    if (INSTANCE_POINTER->rate < 6)
                    {
                        break;
                    }
                }
                if (INSTANCE_POINTER->rate < 6) // sampling rate has been changed
                {
                    break;
                }
                st += r_[INSTANCE_POINTER->rate - 6];
                if (st - micros() > r_[INSTANCE_POINTER->rate - 6]) // sampling rate has been changed to shorter interval
                {
                    st = micros();
                }
                if (!INSTANCE_POINTER->Start)
                {
                    i--;
                    continue;
                }
                INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
            }
            INSTANCE_POINTER->Refresh_Waveform();
        }
        else
        {
            INSTANCE_POINTER->Refresh_User_Interface();
        }
    }
}

void Oscilloscope_Class::Refresh_User_Interface()
{
    while (1)
    {
        switch (Get_Command())
        {
        case 0x0000:
            // idle state
            break;
        case 0x5341: // SA : Start
            INSTANCE_POINTER->Start = true;
        case 0x534F: // SO : Stop
            INSTANCE_POINTER->Start = false;
            break;
        case 0x4330: // C0 : Select Channel 0
            INSTANCE_POINTER->Current_Channel == 0;
            break;
        case 0x4331: // C1 : Select Channel 1
            INSTANCE_POINTER->Current_Channel == 1;
            break;
        case 0x5352: //SR : switch range
            if (INSTANCE_POINTER->Current_Channel == 0)
            {
                if (INSTANCE_POINTER->range0 <= RANGE_MAX)
                {
                    INSTANCE_POINTER->range0++;
                }
                else
                {
                    INSTANCE_POINTER->range0 = RANGE_MIN;
                }
                GalaxOS.Display.Set_Text(F("RANGE_TXT"), "Range : " + String(INSTANCE_POINTER->Ranges[INSTANCE_POINTER->range0]) + " V/Div");
            }
            else
            {
                if (INSTANCE_POINTER->range1 <= RANGE_MAX)
                {
                    INSTANCE_POINTER->range1++;
                }
                else
                {
                    INSTANCE_POINTER->range1 = RANGE_MIN;
                }
                GalaxOS.Display.Set_Text(F("RANGE_TXT"), "Range : " + String(INSTANCE_POINTER->Ranges[INSTANCE_POINTER->range1]) + " V/Div");
            }
            break;
        case 0x534D: //SM : switch mode
            if (INSTANCE_POINTER->Current_Channel == 0)
            {
                if (INSTANCE_POINTER->ch0_mode < INSTANCE_POINTER->MODE_OFF)
                {
                    INSTANCE_POINTER->ch0_mode++;
                }
                else
                {
                    INSTANCE_POINTER->ch0_mode = INSTANCE_POINTER->MODE_ON;
                }
                GalaxOS.Display.Set_Text(F("MODE_TXT"), "Mode : " + String(INSTANCE_POINTER->Modes[INSTANCE_POINTER->ch0_mode]));
            }
            else
            {
                if (INSTANCE_POINTER->ch1_mode < INSTANCE_POINTER->MODE_OFF)
                {
                    INSTANCE_POINTER->ch1_mode++;
                }
                else
                {
                    INSTANCE_POINTER->ch1_mode = INSTANCE_POINTER->MODE_ON;
                }
                GalaxOS.Display.Set_Text(F("MODE_TXT"), "Mode : " + String(INSTANCE_POINTER->Modes[INSTANCE_POINTER->ch1_mode]));
            }
            break;

        case 0x4F2B: //O+
            if (INSTANCE_POINTER->Current_Channel == 0)
            {
                if (INSTANCE_POINTER->ch0_off < 4095)
                {
                    INSTANCE_POINTER->ch0_off += 4096 / INSTANCE_POINTER->VREF[INSTANCE_POINTER->range0];
                }
            }
            else
            {
                if (INSTANCE_POINTER->ch1_off < 4095)
                {
                    INSTANCE_POINTER->ch1_off += 4096 / INSTANCE_POINTER->VREF[INSTANCE_POINTER->range1];
                }
            }
            break;
        case 0x4F2D: //0-
            if (INSTANCE_POINTER->Current_Channel == 0)
            {
                if (INSTANCE_POINTER->ch0_off > -4095)
                {
                    INSTANCE_POINTER->ch0_off -= 4096 / INSTANCE_POINTER->VREF[INSTANCE_POINTER->range0];
                }
            }
            else
            {
                if (INSTANCE_POINTER->ch1_off > -4095)
                {
                    INSTANCE_POINTER->ch1_off -= 4096 / INSTANCE_POINTER->VREF[INSTANCE_POINTER->range1];
                }
            }
            break;
        case 0x536D: // Sm : Switch trigger mode
            if (INSTANCE_POINTER->trig_mode < INSTANCE_POINTER->TRIG_SCAN)
            {
                INSTANCE_POINTER->trig_mode++;
            }
            else
            {
                INSTANCE_POINTER->trig_mode = INSTANCE_POINTER->TRIG_AUTO;
            }
        case 0x4C2B: // L+ : Switch trigger level (thresold)
            if (INSTANCE_POINTER->trig_lv < 60)
            {
                INSTANCE_POINTER->trig_lv++;
            }
            break;
        case 0x4C2D: // L- :
            if (INSTANCE_POINTER->trig_lv > 0)
            {
                INSTANCE_POINTER->trig_lv--;
            }
            break;
        case 0x5345: // SE : Switch edge
            INSTANCE_POINTER->trig_edge = !INSTANCE_POINTER->trig_edge;
            break;

        case 0x5372: //Sr : switch rate
            if (INSTANCE_POINTER->rate <= RATE_MAX)
            {
                INSTANCE_POINTER->rate++;
            }
            else
            {
                INSTANCE_POINTER->rate = RATE_MIN;
            }
            break;

        default:
            break;
        }
    }




    while (1)
    {
        if (INSTANCE_POINTER->trig_mode != INSTANCE_POINTER->TRIG_SCAN)
        {
            unsigned long st = millis();
            short oad = (INSTANCE_POINTER->trig_ch == 0) ? (INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off)) : (INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off));
            for (;;)
            {
                short ad;
                if (INSTANCE_POINTER->trig_ch == 0)
                {
                    ad = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                }
                else
                {
                    ad = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }

                if (INSTANCE_POINTER->trig_edge == INSTANCE_POINTER->TRIG_E_UP)
                {
                    if (ad >= INSTANCE_POINTER->trig_lv && ad > oad)
                    {
                        break;
                    }
                }
                else
                {
                    if (ad <= INSTANCE_POINTER->trig_lv && ad < oad)
                    {
                        break;
                    }
                }
                oad = ad;

                //INSTANCE_POINTER->CheckSW(); -> Check UI

                if (INSTANCE_POINTER->trig_mode == INSTANCE_POINTER->TRIG_SCAN)
                {
                    break;
                }
                if (INSTANCE_POINTER->trig_mode == INSTANCE_POINTER->TRIG_AUTO && (millis() - st) > 100)
                {
                    break;
                }
            }
        }

        // sample and draw depending on the sampling rate
        if (INSTANCE_POINTER->rate <= 5 && INSTANCE_POINTER->Start)
        {
            (INSTANCE_POINTER->sample == 0) ? (INSTANCE_POINTER->sample = 2) : (INSTANCE_POINTER->sample = 0); // change the index for the double buffer

            if (INSTANCE_POINTER->rate == 0) // full speed, channel 0 only
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                }
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = 0;
                }
            }
            else if (INSTANCE_POINTER->rate == 1) // full speed, channel 1 only
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = 0;
                }
            }
            else if (INSTANCE_POINTER->rate == 2) // full speed, dual channel
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
            }
            else if (INSTANCE_POINTER->rate >= 3 && INSTANCE_POINTER->rate <= 5) // .5ms, 1ms or 2ms sampling
            {
                const unsigned long r_[] = {5000 / INSTANCE_POINTER->DOTS_DIV, 10000 / INSTANCE_POINTER->DOTS_DIV, 20000 / INSTANCE_POINTER->DOTS_DIV};
                unsigned long st = micros();
                unsigned long r = r_[INSTANCE_POINTER->rate - 3];
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    while ((st - micros()) < r)
                    {
                        ;
                    }
                    st += r;
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
            }
            INSTANCE_POINTER->Refresh_Waveform();
            INSTANCE_POINTER->Refresh_User_Interface();
        }
        else if (INSTANCE_POINTER->Start)
        { // 5ms - 500ms sampling
            // copy currently showing data to another
            if (INSTANCE_POINTER->sample == 0)
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[2][i] = INSTANCE_POINTER->data[0][i];
                    INSTANCE_POINTER->data[3][i] = INSTANCE_POINTER->data[1][i];
                }
            }
            else
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[0][i] = INSTANCE_POINTER->data[2][i];
                    INSTANCE_POINTER->data[1][i] = INSTANCE_POINTER->data[3][i];
                }
            }

            const unsigned long r_[] = {50000 / INSTANCE_POINTER->DOTS_DIV, 100000 / INSTANCE_POINTER->DOTS_DIV, 200000 / INSTANCE_POINTER->DOTS_DIV,
                                        500000 / INSTANCE_POINTER->DOTS_DIV, 1000000 / INSTANCE_POINTER->DOTS_DIV, 2000000 / INSTANCE_POINTER->DOTS_DIV,
                                        5000000 / INSTANCE_POINTER->DOTS_DIV, 10000000 / INSTANCE_POINTER->DOTS_DIV};
            unsigned long st = micros();
            for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
            {
                while ((st - micros()) < r_[rate - 6])
                {
                    INSTANCE_POINTER->Refresh_User_Interface(); // check UI
                    if (rate < 6)
                    {
                        break;
                    }
                }
                if (rate < 6) // sampling rate has been changed
                {
                    break;
                }
                st += r_[rate - 6];
                if (st - micros() > r_[rate - 6]) // sampling rate has been changed to shorter interval
                {
                    st = micros();
                }
                if (!INSTANCE_POINTER->Start)
                {
                    i--;
                    continue;
                }
                INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
            }
            INSTANCE_POINTER->Refresh_Waveform();
        }
    }
}

long Oscilloscope_Class::adRead(short ch, short mode, int off)
{
    long a = analogRead(ch);
    if ((a + off) * VREF[(ch == ad_ch0)])
    {
        a = range0;
    }
    else
    {
        a = range1;
    }
    a = (a / 10000UL) + 30;

    if (a >= LCD_HEIGHT)
    {
        a = LCD_HEIGHT;
    }
    else
    {
        a = a;
    }
    if (mode == MODE_INV)
    {
        return LCD_HEIGHT - a;
    }
    return a;
}

void Oscilloscope_Class::Refresh_Waveform()
{
    int clear = 0;

    if (sample == 0)
    {
        clear = 2;
    }
    if (ch0_mode != MODE_OFF)
    {
        GalaxOS.Display.Add_Value_Waveform(Waveform_ID, 0, (uint32_t*)data[sample + 0], SAMPLES);
    }
    if (ch1_mode != MODE_OFF)
    {
        GalaxOS.Display.Add_Value_Waveform(Waveform_ID, 0, (uint32_t*)data[sample + 1], SAMPLES);
    }
}

#undef INSTANCE_POINTER
