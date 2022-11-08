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

namespace Xila_Namespace
{
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

        // TODO : Add all base instruction (like minimize, maximize, etc.)
        /// @brief Xila instruction type.
        typedef class Instruction_Class
        {
        private:
            Xila_Namespace::Module_Class *Sender;
            uint32_t Arguments;
            Xila_Namespace::Module_Class *Receiver;

        public:

            operator uint32_t() const
            {
                return Arguments;
            };

            Instruction_Class() : Sender(NULL), Receiver(NULL), Arguments(0){};

            Instruction_Class(Module_Class *Sender, Module_Class *Receiver, uint32_t Arguments) : Sender(Sender),
                                                                                                 Receiver(Receiver),
                                                                                                 Arguments(Arguments){};

            Instruction_Class(Module_Class* Sender, Module_Class* Receiver, const char Arguments[4]) : Sender(Sender),
            Receiver(Receiver)
            {
                 memcpy(&this->Arguments, Arguments, sizeof(this->Arguments));
            }

                                                                                            
            Xila_Namespace::Module_Class *Get_Sender() const
            {
                return Sender;
            };

            Xila_Namespace::Module_Class *Get_Receiver() const
            {
                return Receiver;
            };

            uint32_t Get_Arguments() const
            {
                return Arguments;
            };

            void Set_Sender(Xila_Namespace::Module_Class *Sender)
            {
                this->Sender = Sender;
            };

            void Set_Receiver(Xila_Namespace::Module_Class *Receiver)
            {
                this->Receiver = Receiver;
            };

            void Set_Arguments(const char Arguments[4])
            {
                memcpy(&this->Arguments, Arguments, sizeof(Arguments));
            }

            /*
            Instruction_Class Open((Module_Class*)NULL, NULL, "Open");
            Instruction_Class Close(NULL, NULL, "Clos");
            Instruction_Class Active(NULL, NULL, "Activ");
            Instruction_Class Inactive(NULL, NULL, "Inac");
            */
        
        } Instruction_Type;

        
            

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

        // - Methods

        Module_Class(Size_Type Queue_Size = Default_Instruction_Queue_Size);
        ~Module_Class();

        void Send_Instruction( Instruction_Type &Instruction);
        void Send_Instruction( Module_Class *Sender, const char Arguments[4]);

        


        Instruction_Type Get_Instruction();

        // - Attributes

    private:
        QueueHandle_t Instruction_Queue_Handle;
    } Module_Type;

#define Instruction_Macro()

    bool operator==(const Module_Class::Instruction_Type &First, const Module_Class::Instruction_Type &Second)
    {
        if ((First.Get_Arguments() == Second.Get_Arguments()) && (First.Get_Receiver() == Second.Get_Receiver()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

#endif
