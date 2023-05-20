///
/// @file Semaphore.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-01-2023
///
/// @copyright Copyright (c) 2023
///

#ifndef Semaphore_Hpp_Included
#define Semaphore_Hpp_Included

#include "Base_Types.hpp"

#include <mutex>

namespace Xila_Namespace
{
    // - Forward declarations
    typedef class Task_Class Task_Type;

    typedef class Auto_Semaphore_Class Auto_Semaphore_Type;

    enum class Semaphore_Type_Type
    {
        Binary,
        Counting,
        Mutex,
        Recursive_Mutex
    };
    
    /// @brief Xila Semaphore type.
    typedef class Semaphore_Class
    {
    public:
        // - Methods
        // - - Constructors / destructors

        /// @brief Construct a new Semaphore object.
        Semaphore_Class();
        Semaphore_Class(const Semaphore_Class &);

        /// @brief Create a Semaphore.
        /// @param Type Semaphore type (Binary, Counting, Mutex, Recursive_Mutex).
        /// @param Initial_Count Initial count (for Counting semaphore).
        /// @param Maximum_Count Maximum count (for Counting semaphore).
        /// @return `Result_Type::Success` if the semaphore was created, Result_Type::Error otherwise.
        Result_Type Create(Semaphore_Type_Type Type, unsigned int Initial_Count = 0, unsigned int Maximum_Count = 1);

        /// @brief Delete the Semaphore.
        void Delete();

        // - - Manipulation

        /// @brief Take the Semaphore.
        /// @param Timeout Timeout to take the semaphore in milliseconds.
        /// @return `Result_Type::Success` if the semaphore was taken, Result_Type::Error otherwise.
        Result_Type Take(uint32_t Timeout = 0xFFFFFFFF);

        /// @brief Take the Semaphore from an ISR.
        /// @param Higher_Priority_Task_Woken Pointer to a variable that will be set to `true` if a higher priority task was woken.
        void Take_From_ISR(Integer_Type *Higher_Priority_Task_Woken);

        /// @brief Take the Semaphore recursively.
        /// @param Timeout Timeout to take the semaphore in milliseconds.
        /// @return `Result_Type::Success` if the semaphore was taken, Result_Type::Error otherwise.
        Result_Type Take_Recursive(uint32_t Timeout = 0xFFFFFFFF);

        /// @brief Take and give the Semaphore automatically by using the scope of the returned variable.
        /// @param Timeout Timeout to take the semaphore in milliseconds.
        /// @return
        Auto_Semaphore_Type Take_Auto(uint32_t Timeout = 0xFFFFFFFF);

        /// @brief Give the Semaphore.
        void Give();

        /// @brief Give the Semaphore from an Interrupt Service Routine.
        void Give_From_ISR(Integer_Type *Higher_Priority_Task_Woken);

        /// @brief Give the Semaphore recursively.
        void Give_Recursive();

        // - - Getters

        /// @brief Return the task that holds the Semaphore.
        /// @return The task that holds the Semaphore.
        Task_Type Get_Mutex_Holder();

        /// @brief Return the count of the Semaphore.
        /// @return The count of the Semaphore.
        unsigned int Get_Count();

        /// @brief Return if a Semaphore is valid (created).
        /// @return `true` if the Semaphore is valid, `false` otherwise.
        bool Is_Valid();

    private:
        // - Attributes

        /// @brief FreeRTOS Semaphore handle.
        SemaphoreHandle_t Semaphore_Handle;

        friend class Auto_Semaphore_Class;
    } Semaphore_Type;

    typedef class Auto_Semaphore_Class
    {
    public:
        // - Methods
        // - - Constructors / destructors

        /// @brief Construct a new Auto Semaphore object and take the Semaphore.

        // Auto_Semaphore_Class(Semaphore_Type Semaphore, uint32_t Timeout = 0xFFFFFFFF);
        Auto_Semaphore_Class(Semaphore_Type &Semaphore, uint32_t Timeout = 0xFFFFFFFF);

        /// @brief Copy constructor.
        Auto_Semaphore_Class(const Auto_Semaphore_Class &);

        ~Auto_Semaphore_Class();

    private:
        SemaphoreHandle_t Semaphore_Handle;

    } Auto_Semaphore_Type;

}

#endif