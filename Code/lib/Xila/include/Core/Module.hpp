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
#include "FS.h"

#include "Configuration/Configuration.hpp"
#include "Configuration/Path.hpp"



class Module_Class
{
public:
    typedef bool Boolean_Type;
    typedef short Short_Integer;
    typedef int Integer;
    typedef long Long_Integer;
    typedef long long Long_Long_Integer;

    typedef short Unsigned_Short_Integer;
    typedef int Unsigned_Integer;
    typedef long Unsigned_Long_Integer;
    typedef long long Unsigned_Long_Long_Integer;

    typedef float Float;
    typedef double Precision_Float;
    typedef char Character;
    //typedef String String;

    typedef void Void;

    typedef uint32_t Tick_Type;

    /// @brief Size Type;
    typedef size_t Size_Type;

    class Result
    {
    public:
        ///
        /// @brief Functions results enumeration.
        ///
        enum Enumeration
        {
            Success,
            Invalid_Argument,
            Error,       ///< Error event.
            Warning,     ///< Warning event.
            Information, ///< Information event.
            Question,    ///< Question event.
            None
        };

        typedef uint8_t Type;
    };

    class Module
    {
    public:
        /// @brief Modules enumeration and type.
        typedef enum Enumeration
        {
            None,
            Account,
            Clipboard,
            Display,
            Graphical_Interface,
            System,
            Mathematics
        } Type;
    };

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
        void *Sender;
        uint32_t Arguments;
        void *Receiver;

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

        operator uint32_t() const
        {
            return Arguments;
        };

        Instruction_Type() : Sender(NULL), Receiver(NULL), Arguments(0){};

        Instruction_Type(void *Sender, void *Receiver, uint32_t Arguments) : Sender(Sender), Receiver(Receiver), Arguments(0){};

        void *Get_Sender() const
        {
            return Sender;
        };

        void *Get_Receiver() const
        {
            return Receiver;
        };

        uint32_t Get_Arguments() const
        {
            return Arguments;
        };

        void Set_Sender(void *Sender)
        {
            this->Sender = Sender;
        };

        void Set_Receiver(void *Receiver)
        {
            this->Receiver = Receiver;
        };

        void Set_Arguments(uint32_t Arguments)
        {
            this->Arguments = Arguments;
        };
    };

    typedef class Task_Class
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
        Task_Class(xTaskHandle Handle);
        ~Task_Class();

        Result::Type Create(Task_Function *Task_Function, const char *Task_Name, size_t Stack_Size = 4000, Priority_Type Priority = Normal);

        Result::Type Set_Priority(Priority_Type Priority);
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

        void Set_Handle();

    private:
        xTaskHandle Task_Handle;
    } Task_Type;                                                                    
};

#define Instruction_Macro()

#endif
