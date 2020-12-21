#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDEd

#include "Xila.hpp"

class Clock_Class : public Software_Class
{
    private:

        static void Main_Task(void*);

        static Clock_Class* Instance_Pointer;

        const char Days[7][10] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };

        const char Months[12][10]
        {
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
            "December"
        };

        uint8_t Current_Tab;

        enum Tabs
        {
            Clock,
            Alarm,
            Timer,
            Chronometer
        };

        bool Alarm_Exist[6];
        int Alarm_Hour[6];
        int Alarm_Minute[6];
        bool Alarm_Enabled[6];
        char Alarm_Title[6][10];

        int Timer_State;
        // 0 : Stop
        // 1 : Running
        // 2 : Paused
        uint32_t Inital_Time;
        uint32_t Last_Update;
        uint32_t Temporary_Time;
        uint32_t Paused_Time;
        uint32_t Laps[32];
        uint8_t Current_Lap;

        Xila_Time Time;

        char Temporary_Char_Array[40];
        uint8_t Offset;

        

        void Refresh_Clock();

        void Refresh_Alarm();

        void Refresh_Timer();

        void Refresh_Chronometer();

        void Add_Alarm();
        void Delete_Alarm();
        uint8_t Selected_Alarm;

    public:
        static Software_Class* Load();

        enum Picture
        {
            Clock_32 = 38
        };

        Clock_Class();
        ~Clock_Class();

};

Software_Handle_Class Clock_Handle("Clock", Clock_Class::Clock_32, Clock_Class::Load);

#endif