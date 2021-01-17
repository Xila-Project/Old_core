#include "Xila.hpp"

/**
 * @file Oscilloscope.hpp
 * @brief Oscilloscope Software header file.
 * @author Botofancalin - Alix ANNERAUD (adaptation to Xila)
 * @copyright Botofancalin - Alix ANNERAUD (only rewritten code)
 * @version 0.1.0
 * @date 
 * @details An oscilloscope application
 * @section Licence
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 * https://github.com/botofancalin/M5Stack-ESP32-Oscilloscope
 */

class Oscilloscope_Class : private Software_Class
{
protected:
    static Oscilloscope_Class *Instance_Pointer;

    TaskHandle_t SigmaDelta_Handle;

    const uint8_t Waveform_ID = 4;

    uint8_t Current_Channel;

    uint32_t Last_Interface_Refresh;

    

    // Constant

    const int LCD_WIDTH = 340;
    const int LCD_HEIGHT = 250;
    const int SAMPLES = 350;
    const int DOTS_DIV = 75;

    int ad_ch0 = 35; // Analog 35 pin for channel 0
    int ad_ch1 = 36; // Analog 36 pin for channel 1

    const long VREF[5] = {250, 500, 1250, 2500, 5000};
    const int MILLIVOL_per_dot[5] = {33, 17, 6, 3, 2};

    // channel mode
    const int MODE_ON = 0;
    const int MODE_INV = 1;
    const int MODE_OFF = 2;
    const char *Modes[3] = {"Normal", "Inverted", "Off"};
    short ch0_mode = MODE_ON;
    short ch1_mode = MODE_OFF;

    // Triggering
    const int TRIG_AUTO = 0;
    const int TRIG_NORM = 1;
    const int TRIG_SCAN = 2;
    const char *TRIG_Modes[3] = {"Autoc", "Normal", "Scan"};
    const int TRIG_E_UP = 0;
    const int TRIG_E_DN = 1;

    // Time rate
#define RATE_MIN 0
#define RATE_MAX 13

    const char *Rates[14] = {"F1-1", "F1-2", "F2", "5ms", "10ms", "20ms", "50ms", "0.1s", "0.2s", "0.5s", "1s", "2s", "5s", "10s"};
    short rate = 3;

    // Voltage range
#define RANGE_MIN 0
#define RANGE_MAX 4
    const char *Ranges[5] = {"1", "0.5", "0.2", "0.1", "0.05"};
    int range0 = RANGE_MIN;
    short range1 = RANGE_MIN;

    // Offset
    int ch0_off = 0;
    int ch1_off = 0;

    // Triggering mode
    short trig_mode = TRIG_AUTO;
    // Tringerring level
    int trig_lv = 40;
    // Trigger edge
    short trig_edge = TRIG_E_UP;
    short trig_ch = 0;
    short Start = 1;
    short menu = 19;

    short data[4][350]; // keep twice of the number of channels to make it a double buffer

    short sample = 0; // index for double buffer
    int amplitude = 0;
    int amplitudeStep = 5;

    ///////////////////////////////////////////////////////////////////////////////////////////////

    void Run();

    inline long adRead(short, short, int);

    void Refresh_Waveform();

    void Refresh_Interface();

    void Check_Commands();

    friend void Oscilloscope_Task(void *); //main task
    friend void SigmaDelta_Task(void *);   // used to generate sigmadelta signal

public:

    static void Main_Task(void*);
    
    
    //static void SigmaDelta_Task(void*);

    static Software_Class *Load();

    enum Picture_ID
    {
        Oscilloscope_32 = 17
    };

    Oscilloscope_Class();
    ~Oscilloscope_Class();
};

Software_Handle_Class Oscilloscope_Handle("Oscilloscope", Oscilloscope_Class::Oscilloscope_32, Oscilloscope_Class::Load);
