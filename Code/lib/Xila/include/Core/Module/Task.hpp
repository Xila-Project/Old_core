#ifndef Task_Hpp_Included
#define Task_Hpp_Included

#include "Arduino.h"

#include "Base_Types.hpp"

#include <list>

namespace Xila_Namespace
{

    typedef class Module_Class Module_Type;

    typedef class Task_Class
    {
    public:
        typedef void (*Function_Type)(void *);

        // - Types

        typedef void Task_Function(void *);

        enum class Priority_Type
        {
            Idle = 0,
            Background,
            Low,
            Normal,
            High,
            System,
            Driver
        };

        enum class State_Type
        {
            Running = eRunning,
            Ready = eReady,
            Blocked = eBlocked,
            Suspended = eSuspended,
            Deleted = eDeleted,
            Invalid = eInvalid,
        };

        // - Methods
        
        // - Constructors / Destructors
        Task_Class(Module_Class *Owner_Module, Function_Type Task_Function, const char *Name,
                   Size_Type Stack_Size, void *Data = NULL, Priority_Type Priority = Priority_Type::Normal);
        Task_Class(Module_Class* Owner_Module);
        Task_Class(const Task_Class& Task);
        Task_Class(xTaskHandle Task_Handle);

        ~Task_Class();

        Result_Type Set_Priority(Priority_Type Priority);

        Result_Type Create(Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Priority_Type Priority);
        void Suspend();
        void Resume();
        void Delete();

        State_Type Get_State();
        Priority_Type Get_Priority();
        const Module_Type* Get_Owner_Module();
        Size_Type Get_Lowest_Free_Stack();
        char* Get_Name();

        void Delay(uint32_t Delay_In_Millisecond);

        /*
        static void Give_Notification(Task_Class& Task, unsigned int Index = 0);
        static void Give_Notification_From_ISR(Task_Class& Task, void* Data, unsigned int Index = 0);
        static void Take_Notification(Task_Class& Task);
        */

        static void Delay_Static(uint32_t Delay_In_Millisecond);
        void Delay_Until(TickType_t Time_Increment);

        void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

        static void Check_Watchdogs();
        static void Suspend_All();
        static void Delete_Module_Tasks(Module_Class *Module);

        void Feed_Watchdog();

        uint32_t Get_Watchdog_Timer();
        uint32_t Get_Watchdog_Timeout();

    private:
        // - Attributes
        xTaskHandle Task_Handle;

        uint32_t Watchdog_Timer;
        uint32_t Watchdog_Timeout;

        TickType_t Previous_Wake_Time;

        Module_Class *Owner_Module;

        static std::list<Task_Class *> List; // - Task lists.

    } Task_Type;

}

#endif