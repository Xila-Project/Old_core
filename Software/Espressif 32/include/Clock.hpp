#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDEd

#include "Xila.hpp"

class Clock_Class : public Software_Class
{
private:
    static void Main_Task(void *);

    static Clock_Class *Instance_Pointer;

    uint8_t Current_Tab;
    Xila_Time Time;

    enum Tabs
    {
        Clock,
        Alarm,
        Timer,
        Chronometer
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
    bool Alarm_Exist[6];
    int Alarm_Hour[6];
    int Alarm_Minute[6];
    bool Alarm_Enabled[6];
    char Alarm_Title[6][10];
    static uint32_t Next_Alarm;

    // Chronometer

    //uint8_t Scrollbar;

    //uint32_t Laps[32];
    //uint8_t Current_Lap;

    // Shared with timer :

    uint8_t State;
    // 0 : Stop
    // 1 : Running
    // 2 : Paused
    uint32_t Inital_Time;
    uint32_t Paused_Time;
    uint32_t Last_Update;

    uint32_t Temporary_Time;

    // Timer

    uint8_t Hours, Minutes, Seconds;

    char Temporary_Char_Array[40];
    uint8_t Offset;

    void Refresh_Clock();

    void Refresh_Alarms(); // alarm list
    void Refresh_Alarm(); //set alarm

    void Refresh_Timer();

    void Refresh_Chronometer();

    void Add_Alarm();
    void Delete_Alarm();

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    uint8_t Selected_Alarm;

public:
    static Software_Class *Load();

    static void Background_Function();

    enum Picture
    {
        Clock_32 = 38
    };

    Clock_Class();
    ~Clock_Class();
};

Software_Handle_Class Clock_Handle("Clock", Clock_Class::Clock_32, Clock_Class::Load, NULL, Clock_Class::Background_Function);

#endif