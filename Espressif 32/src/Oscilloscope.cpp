#include "Oscilloscope.hpp"

#define INSTANCE_POINTER Oscilloscope_Class::Instance_Pointer

Oscilloscope_Class *Oscilloscope_Class::Instance_Pointer = NULL;

Oscilloscope_Class::Oscilloscope_Class(Software_Handle_Class *Software_Handle_To_Set) : Software_Class(Software_Handle_To_Set, 5)
{

    Instance_Pointer = this;

    xTaskCreatePinnedToCore(Oscilloscope_Task, "Oscilloscope", 2 * 1024, NULL, 1, &Task_Handle, 0);
}

Oscilloscope_Class::~Oscilloscope_Class()
{
    Execute(0x0043);
}

void Oscilloscope_Task(void *pvParameters)
{
    (void)pvParameters;

    // LedC
    ledcSetup(0, 50, 13);
    ledcAttachPin(2, 0);
    for (;;)
    {

        //Oscilloscope_Class::Instance_Pointer->ledcAnalogWrite(0, amplitude);

        uint32_t duty = (8191 / 255) * min(INSTANCE_POINTER->amplitude, 255);
        ledcWrite(0, duty);

        INSTANCE_POINTER->amplitude = INSTANCE_POINTER->amplitude + INSTANCE_POINTER->amplitudeStep;
        if (INSTANCE_POINTER->amplitude <= 0 || INSTANCE_POINTER->amplitude >= 255)
        {
            INSTANCE_POINTER->amplitudeStep = -INSTANCE_POINTER->amplitudeStep;
        }
        vTaskDelay(pdMS_TO_TICKS(30));
    }

    // SigmaDelta
    sigmaDeltaSetup(0, 312500);
    sigmaDeltaAttachPin(5, 0);
    sigmaDeltaWrite(0, 0);
    for (;;)
    {
        static uint8_t i = 0;
        sigmaDeltaWrite(0, i++);
        delayMicroseconds(50);
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

            if (rate == 0) // full speed, channel 0 only
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
            else if (rate == 1) // full speed, channel 1 only
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
            else if (rate == 2) // full speed, dual channel
            {
                for (int i = 0; i < INSTANCE_POINTER->SAMPLES; i++)
                {
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 0][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch0, INSTANCE_POINTER->ch0_mode, INSTANCE_POINTER->ch0_off);
                    INSTANCE_POINTER->data[INSTANCE_POINTER->sample + 1][i] = INSTANCE_POINTER->adRead(INSTANCE_POINTER->ad_ch1, INSTANCE_POINTER->ch1_mode, INSTANCE_POINTER->ch1_off);
                }
            }
            else if (rate >= 3 && rate <= 5) // .5ms, 1ms or 2ms sampling
            {
                const unsigned long r_[] = {5000 / INSTANCE_POINTER->DOTS_DIV, 10000 / DOTS_DIV, 20000 / DOTS_DIV};
                unsigned long st = micros();
                unsigned long r = r_[rate - 3];
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

            ClearAndDrawGraph(); //Update screen
            CheckSW();           // Check UI
            DrawGrid();          // Update screen
            DrawText();          // Update screen
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
                    CheckSW(); // check UI
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
                ClearAndDrawDot(i); // refresh screen
            }
            DrawGrid(); //refresh screen
            DrawText(); // refresh screen
        }
        else
        {
            CheckSW(); //refresh screen
        }
        M5.update(); // refresh screen
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

void Oscilloscope_Class::ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255)
{
    uint32_t duty = (8191 / valueMax) * min(value, valueMax);
    ledcWrite(channel, duty);
}

void Oscilloscope_Class::Update_Waveform()
{
    int clear = 0;

    if (sample == 0)
    {
        clear = 2;
    }
    for (int x = 0; x < (SAMPLES - 1); x++)
    {
        M5.Lcd.drawLine(x, LCD_HEIGHT - data[clear + 0][x], x + 1, LCD_HEIGHT - data[clear + 0][x + 1], BLACK);
        M5.Lcd.drawLine(x, LCD_HEIGHT - data[clear + 1][x], x + 1, LCD_HEIGHT - data[clear + 1][x + 1], BLACK);
        if (ch0_mode != MODE_OFF)
        {
            M5.Lcd.drawLine(x, LCD_HEIGHT - data[sample + 0][x], x + 1, LCD_HEIGHT - data[sample + 0][x + 1], CH1COLOR);
        }
        if (ch1_mode != MODE_OFF)
        {
            M5.Lcd.drawLine(x, LCD_HEIGHT - data[sample + 1][x], x + 1, LCD_HEIGHT - data[sample + 1][x + 1], CH2COLOR);
        }
        CheckSW();
    }
}