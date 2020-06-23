#include "Software.hpp"

// Code reused from "M5Stack ESP32 Oscilloscope"
// https://github.com/botofancalin/M5Stack-ESP32-Oscilloscope

class Oscilloscope_Class : public Software_Class
{
protected:
    static Oscilloscope_Class *Instance_Pointer;

    Oscilloscope_Class(Software_Handle_Class *);
    ~Oscilloscope_Class();

    const int LCD_WIDTH = 320;
    const int LCD_HEIGHT = 240;
    const int SAMPLES = 320;
    const int DOTS_DIV = 30;

    const int ad_ch0 = 35; // Analog 35 pin for channel 0
    const int ad_ch1 = 36; // Analog 36 pin for channel 1
    const long VREF[] = {250, 500, 1250, 2500, 5000};
    const int MILLIVOL_per_dot[] = {33, 17, 6, 3, 2};
    const int MODE_ON = 0;
    const int MODE_INV = 1;
    const int MODE_OFF = 2;
    const char *Modes[] = {"NORM", "INV", "OFF"};
    const int TRIG_AUTO = 0;
    const int TRIG_NORM = 1;
    const int TRIG_SCAN = 2;
    const char *TRIG_Modes[] = {"Auto", "Norm", "Scan"};
    const int TRIG_E_UP = 0;
    const int TRIG_E_DN = 1;
#define RATE_MIN 0
#define RATE_MAX 13
    const char *Rates[] = {"F1-1", "F1-2", "  F2", " 5ms", "10ms", "20ms", "50ms", "0.1s", "0.2s", "0.5s", "1s", "2s", "5s", "10s"};
    short rate = 3;
#define RANGE_MIN 0
#define RANGE_MAX 4
    const char *Ranges[] = {" 1V", "0.5V", "0.2V", "0.1V", "50mV"};
    int range0 = RANGE_MIN;
    short range1 = RANGE_MIN;
    short ch0_mode = MODE_ON;
    short ch1_mode = MODE_OFF;
    int ch0_off = 0;
    int ch1_off = 0;
    short trig_mode = TRIG_AUTO;
    int trig_lv = 40;
    short trig_edge = TRIG_E_UP;
    short trig_ch = 0;
    short Start = 1;
    short menu = 19;
    short data[4][SAMPLES]; // keep twice of the number of channels to make it a double buffer
    short sample = 0;       // index for double buffer
    int amplitude = 0;
    int amplitudeStep = 5;

    TaskHandle_t LedC_Gen;
    TaskHandle_t SigmaDeltaGen;

///////////////////////////////////////////////////////////////////////////////////////////////
#define CH1COLOR YELLOW
#define CH2COLOR CYAN
#define GREY 0x7BEF

    void Print_Graph();

    inline long adRead(short, short, int);

    void ledcAnalogWrite(uint8_t, uint32_t, uint32_t);

    void Update_Waveform();
    
    friend void Oscilloscope_Task(void *);

};

void Oscilloscope_Task(void *);

