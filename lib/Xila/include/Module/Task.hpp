#ifndef Task_Hpp_Included
#define Task_Hpp_Included

#include "Base_Types.hpp"

#include <vector>

namespace Xila_Namespace
{

    typedef class Module_Class Module_Type;

    enum class Task_Priority_Type
    {
        Idle = 0,
        Background,
        Low,
        Normal,
        High,
        System,
        Driver
    };

    typedef class Task_Class
    {
    public:
        typedef void (*Function_Type)(void *);

        // - Types

        typedef void Task_Function(void *);

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
        Task_Class() = delete;

        /// @brief Construct a new task and start it.
        /// @param Owner_Module
        /// @param Task_Function
        /// @param Name
        /// @param Stack_Size
        /// @param Data
        /// @param Priority
        Task_Class(Module_Class *Owner_Module, Function_Type Task_Function, const char *Name,
                   Size_Type Stack_Size, void *Data = NULL, Task_Priority_Type Priority = Task_Priority_Type::Normal);

        /// @brief Construct a Task_Class.
        /// @param Owner_Module Task owner module.
        Task_Class(Module_Class *Owner_Module);

        /// @brief Copy constructor.
        /// @param Task Task to copy.
        Task_Class(const Task_Class &Task);

        /// @brief Construct a new Task_Class object from a FreeRTOS task handle.
        /// @param Task_Handle FreeRTOS task handle.
        Task_Class(xTaskHandle Task_Handle);

        /// @brief Destroy the Task_Class object.
        ~Task_Class();

        // - - Manipulation

        /// @brief Create a task.
        /// @param Task_Function Task function.
        /// @param Name Task name.
        /// @param Stack_Size Task stack size.
        /// @param Data Data to pass to the task.
        /// @param Priority Task priority.
        /// @return Result_Type::Success if the task has been created, Result_Type::Error otherwise.
        Result_Type Create(Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Task_Priority_Type Priority = Task_Priority_Type::Normal);

        /// @brief Suspend the task.
        void Suspend();

        /// @brief Resume the task.
        void Resume();

        /// @brief Delete the task.
        void Delete();

        /// @brief Delay the task and `Feed_Watchdog`.
        /// @param Delay_In_Millisecond Delay in milliseconds.
        void Delay(uint32_t Delay_In_Millisecond);

        /// @brief Delay the task (static method).
        /// @param Delay_In_Millisecond Delay in milliseconds.
        static void Delay_Static(uint32_t Delay_In_Millisecond);

        /// @brief Delay the task.
        /// @param Delay_In_Microseconds 
        static void Delay_Microseconds(uint32_t Delay_In_Microseconds);

        /// @brief Delay the task until a specific time.
        /// @param Time_Increment Time in ticks.
        void Delay_Until(TickType_t Time_Increment);

        /// @brief Feed the watchdog and add an extra delay.
        /// @param Delay_In_Millisecond Delay in milliseconds (maximum).
        void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

        /// @brief Feed the task watchdog (check if a task is not frozen).
        void Feed_Watchdog();

        /// @brief Check if the task is suspended.
        static void Check_Watchdogs();

        /// @brief Suspend all tasks.
        static void Suspend_All();

        /// @brief Resume all tasks.
        static void Delete_Module_Tasks(Module_Class *Module);

        /// @brief Set the task priority.
        Result_Type Set_Priority(Task_Priority_Type Priority);

        /// @brief Get the task state.
        /// @return Task state.
        State_Type Get_State();

        /// @brief Get the task priority.
        /// @return Task priority.
        Task_Priority_Type Get_Priority();

        /// @brief Get the task owner module.
        /// @return Task owner module.
        const Module_Type *Get_Owner_Module();

        /// @brief Get the task stack size.
        Size_Type Get_Lowest_Free_Stack();

        /// @brief Get the task name.
        char *Get_Name();

        /// @brief Get the task watchdog timer.
        /// @return Task watchdog timer.
        uint32_t Get_Watchdog_Timer();

        /// @brief Get the task watchdog timeout.
        /// @return Task watchdog timeout.
        uint32_t Get_Watchdog_Timeout();

    private:
        // - Attributes

        /// @brief Task handle.
        xTaskHandle Task_Handle;

        /// @brief Task watchdog timeout (time when the task is considered as frozen).
        uint32_t Watchdog_Timeout;

        /// @brief
        TickType_t Previous_Wake_Time;

        /// @brief Task owner module.
        Module_Class *Owner_Module;

        static std::vector<Task_Class *> List; // - Task lists.
    } Task_Type;

}

#endif