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
#include "ArduinoTrace.h"

#include "Configuration/Configuration.hpp"
#include "Configuration/Path.hpp"

namespace Xila_Namespace
{
    typedef class Module_Class
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
        // typedef String String;

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

        /// @brief Time class.
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

        // TODO : Add all base instruction (like minimize, maximize, etc.)
        /// @brief Xila instruction type.
        typedef class Instruction_Class
        {
        private:
            Xila_Namespace::Module_Class *Sender;
            Xila_Namespace::Module_Class *Receiver;

        public:

            class Graphical_Interface_Class
            {
            private:
                uint32_t Code;
                void* Object_Pointer;

            public:
                inline Graphical_Interface_Class() : Code(0) {}
                inline void Set_Code(uint32_t Code) { this->Code = Code; }
                inline void Set_Object_Pointer(void* Object_Pointer) { this->Object_Pointer = Object_Pointer; }
                inline uint32_t Get_Code() const { return Code; }
                inline void* Get_Object_Pointer() const { return Object_Pointer; }
            };


            union
            {
                Graphical_Interface_Class Graphical_Interface;
            };

            Instruction_Class();

            Instruction_Class(Module_Class *Sender, Module_Class *Receiver);

            Instruction_Class(Module_Class *Sender, Module_Class *Receiver, const char *Arguments);

            Module_Class *Get_Sender() const;

            Module_Class *Get_Receiver() const;

            void Set_Sender(Module_Class *Sender);

            void Set_Receiver(Module_Class *Receiver);

            static const Instruction_Class Open;
            static const Instruction_Class Close;
            static const Instruction_Class Minimize;
            static const Instruction_Class Maximize;
            static const Instruction_Class Active;
            static const Instruction_Class Inactive;

        } Instruction_Type;

        /// @brief Xila task type.
        typedef class Task_Class
        {
        public:
            typedef void (*Function_Type)(void *);

            // - Types

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

            // - Methods

            Task_Class(xTaskHandle Handle);
            // - Constructors / Destructors
            Task_Class(Module_Class *Owner_Module, Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data = NULL, Priority_Type Priority = Normal);
            ~Task_Class();

            Result::Type Set_Priority(Priority_Type Priority);

            void Suspend();
            void Resume();

            State_Type Get_State();
            Priority_Type Get_Priority();

            /*
            static void Give_Notification(Task_Class& Task, unsigned int Index = 0);
            static void Give_Notification_From_ISR(Task_Class& Task, void* Data, unsigned int Index = 0);
            static void Take_Notification(Task_Class& Task);
            */

            void Delay(uint32_t Delay_In_Millisecond);
            static void Delay_Static(uint32_t Delay_In_Millisecond);
            void Delay_Until(TickType_t Time_Increment);

            void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);
            static void Check_Watchdogs();

        private:
            void Feed_Watchdog();

            xTaskHandle Task_Handle;

            uint32_t Watchdog_Timer;
            uint32_t Watchdog_Timeout;

            TickType_t Previous_Wake_Time;

            Module_Class *Owner_Module;

            static std::vector<Task_Class *> List; // - Task lists.

        } Task_Type;

        /// @brief Xila Semaphore type.
        typedef class Semaphore_Class
        {
        public:
            typedef enum
            {
                Binary,
                Counting,
                Mutex,
                Recursive_Mutex
            } Type_Type;

            Semaphore_Class();

            Result::Type Create(Type_Type Type, unsigned int Initial_Count, unsigned int Maximum_Count);
            // Event_Type Create_Static()

            void Delete();
            Result::Type Take(uint32_t Timeout = 0xFFFFFFFF);
            void Take_Recursive(Tick_Type Tick_To_Wait);
            void Give();
            void Take_From_ISR(Integer *Higher_Priority_Task_Woken);
            void Give_From_ISR(Integer *Higher_Priority_Task_Woken);
            void Take_Recursive();
            void Give_Recursive();
            // Task_Type Get_Mutex_Holder();
            unsigned int Get_Count();

        private:
            SemaphoreHandle_t Semaphore_Handle;
        } Semaphore_Type;

        /*typedef class Queue_Class
        {
        public:
            Queue_Class();
            ~Queue_Class();

            Result::Type Create(Size_Type Length, Size_Type Item_Size);
            Result::Type Create_Static(Size_Type Length, Size_Type Item_Size);

            void Delete();
            void Reset();

            Result::Type Send(const void *Item, Tick_Type Ticks_To_Wait, bool Send_To_Front = true);
            void Overwrite(const void *Buffer);
            Result::Type Peek(void *Buffer, Tick_Type Ticks_To_Wait);
            Result::Type Receive(void *Buffer, Tick_Type Ticks_To_Wait);

            uint16_t Waiting();

            Size_Type Spaces_Available();

        private:
            QueueHandle_t Queue_Handle;
        } Queue_Type;*/

        // - Methods

        Module_Class(Size_Type Queue_Size = Default_Instruction_Queue_Size);
        ~Module_Class();

        void Send_Instruction(const Instruction_Type &Instruction);
        void Send_Instruction(Module_Class *Sender, const char Arguments[4]);

        Instruction_Type Get_Instruction();
        Size_Type Instruction_Available();

    private:
        QueueHandle_t Instruction_Queue_Handle;

        static std::vector<Module_Class *> List; // - Module lists.

    } Module_Type;

#define Instruction_Macro()

}

#endif
