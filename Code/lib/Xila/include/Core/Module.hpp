///
/// @file Modules.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Modules_Hpp_Included
#define Modules_Hpp_Included

#include <vector>
#include "Arduino.h"
#include "ArduinoJson.h"
#include "Configuration/Configuration.hpp"

class Module_Class
{
public:
    /// @brief Size Type;
    typedef size_t Size_Type;

    ///
    /// @brief Functions results enumeration.
    ///
    enum Result_Enumeration
    {
        Success,
        Invalid_Argument,
        Error,       ///< Error event.
        Warning,     ///< Warning event.
        Information, ///< Information event.
        Question,    ///< Question event.
        None
    };

    typedef uint8_t Result_Type;

    /// @brief Modules enumeration and type.
    typedef enum Module_Enumeration
    {
        Account,
        Clipboard,
        Display,
        Graphical_Interface,
        System,
        Mathematics
    } Module_Type;

    /// @brief Time
    class Time_Type
    {
    private:
        uint8_t Second;
        uint8_t Minute;
        uint8_t Hour;

        uint8_t Day;
        uint8_t Month;
        uint16_t Year;

    public:
        Time_Type();
        Time_Type(uint8_t Second, uint8_t Minute, uint8_t Hour, uint8_t Day, uint8_t Month, uint16_t Year);

        void Set(uint8_t Day, uint8_t Month, uint16_t Year);
        void Set_Day(uint8_t Day);
        void Set_Month(uint8_t Month);
        void Set_Year(uint16_t Year);

        uint8_t Get_Day();
        uint8_t Get_Month();
        uint16_t Get_Year();
    };

    /// @brief Xila instruction type.
    class Instruction_Type
    {
    private:
        Module_Type Sender;
        uint32_t Arguments;

    public:
        /*
        /// @brief Instructions used by the core (with the prefix "#").
        enum Instructions_Enumeration : Xila_Class::Instruction
        {
            // -- Software state instructions
            Open = 'O',
            Close = 'C',
            Maximize = 'M',
            Minimize = 'm',
            // -- System state instructions
            Shutdown = 200,
            Restart,
            Hibernate = 'H',
            Watchdog = 'W',
        };
        */

        Instruction_Type(Module_Type Sender, uint32_t Arguments)
        {
            this->Sender = Sender;
            this->Arguments = Arguments;
        };

        Module_Type Get_Sender()
        {
            return Sender;
        };

        uint32_t Get_Arguments()
        {
            return Arguments;
        };

        void Set_Sender(Module_Type Sender)
        {
            this->Sender = Sender;
        };

        void Set_Arguments(uint32_t Arguments){

        };
    };

    class Task_Class
    {
    public:
        typedef void Task_Function(void *);

        typedef enum Priority_Enumeration
        {
            Idle = 0,
            Background,
            Low,
            Normal,
            High,
            System,
            Driver
        } Priority_Type;

        typedef enum State_Enumeration
        {
            Running = eRunning,
            Ready = eReady,
            Blocked = eBlocked,
            Suspended = eSuspended,
            Deleted = eDeleted,
            Invalid = eInvalid,
        } State_Type;

        Task_Class();
        ~Task_Class();

        Result_Type Create(Task_Function *Task_Function, const char *Task_Name, size_t Stack_Size = 4000, Priority_Type Priority = Normal);

        Result_Type Set_Priority(Priority_Type Priority);
        void Suspend();
        void Resume();
        void Delete();

        State_Type Get_State();
        Priority_Type Get_Priority();

        /*
        static void Give_Notification(Task_Class& Task, unsigned int Index = 0);
        static void Give_Notification_From_ISR(Task_Class& Task, void* Data, unsigned int Index = 0);
        static void Take_Notification(Task_Class& Task);
        */

        static void Delay(uint32_t Delay_In_Millisecond);
        static void Delay_Until(TickType_t *Previous_Wake_Time, const TickType_t Time_Increment);

    private:
        xTaskHandle Task_Handle;
    };
};

#endif
