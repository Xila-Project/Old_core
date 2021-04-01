#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDEd

#include "Xila.hpp"

#define Clock_File(name) Software_Directory_Path "/Clock/" name

class Clock_Class : public Software_Class
{

private:
    static void Main_Task(void *);

    static Clock_Class *Instance_Pointer;

    uint8_t Current_Tab;
    Xila_Time Time;

    enum Pages
    {
        Clock = 6,
        Alarm,
        Chronometer,
        Timer
    };

    // Clock

    const char Days[7][10] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"};

    const char Months[12][10]{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    // Alarm
    int Alarm_Hour[6];
    int Alarm_Minute[6];
    enum Alarm_States
    {
        Disabled,
        Enabled
    };
    bool Alarm_State[6];
    char Alarm_Title[6][10];
    
    



    static uint32_t Next_Alarm; // next alarm in millis();

    // Chronometer

    //uint8_t Scrollbar;

    //uint32_t Laps[32];
    //uint8_t Current_Lap;

    // Shared with timer :

    enum States
    {
        Stopped,
        Running,
        Paused
    };

    uint8_t State;

    uint8_t Timer_State;
    uint32_t Timer_Initial_Time;
    uint32_t Timer_Paused_Time;


    // 0 : Stop
    // 1 : Running
    // 2 : Paused

    uint32_t Chronometer_Inital_Time;
    uint32_t Chronometer_Paused_Time;

    uint32_t Temporary_Time;

    // Timer

    uint8_t Hours, Minutes, Seconds;

    char Temporary_Char_Array[40];

    uint8_t Offset;

    Xila_Instruction Current_Instruction;

    void Clock_Instructions();
    void Alarm_Instructions();
    void Chronometer_Instructions();
    void Timer_Instructions();
    void Main_Instructions();

    void Refresh_Clock();

    void Refresh_Alarms(); // alarm list
    void Refresh_Alarm();  //set alarm
    void Refresh_Next_Alarm();

    void Refresh_Timer();

    void Refresh_Chronometer();

    void Add_Alarm();
    void Delete_Alarm();

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    uint8_t Selected_Alarm;
    
    void Select_Alarm(uint8_t Alarm_To_Select);

    void Load_Registry();
    void Save_Registry();

public:
    Clock_Class();
    ~Clock_Class();

    static Software_Class *Load();

    static void Startup_Function();

    static void Background_Task(void *);

    enum Picture
    {
        Icon_32 = Xila.Display.Clock
    };
};

Software_Handle_Class Clock_Handle("Clock", Clock_Class::Icon_32, Clock_Class::Load, Clock_Class::Startup_Function);

#endif