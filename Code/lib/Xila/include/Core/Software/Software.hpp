///
/// @file Software.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Task.hpp"

class Software_Handle;

class Software
{
protected:
    // - Types

    typedef enum
    {
        Minimized, ///< Maximized state.
        Maximized  ///< Minimized state.
    } State;

    typedef Task_Class Task_Type;

    // - Methods

    // - - Constructor / Destructor
    Software(Xila_Class::Software_Handle &Software_Handle, uint8_t Queue_Size = Default_Instruction_Queue_Size);
    virtual ~Software();

    // -n- Methods
    void Send_Instruction(Xila_Class::Instruction Intruction);

    ///
    /// @brief Convert 2 byte char instruction into Xila Instruction and send it.
    ///
    /// @param Instruction_Char_1 Instruction first byte
    /// @param Instruction_Char_2 Instruction second byte
    inline void Send_Instruction(char Instruction_Char_1, char Instruction_Char_2)
    {
        Send_Instruction(((uint16_t)Instruction_Char_1 << 8) | (uint16_t)Instruction_Char_2);
    }

    virtual void Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable);

    Xila_Class::Instruction Get_Instruction();

    void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

    // - Attributes

    /// @brief Software task handle.
    ///
    Task_Type Main_Task;

    ///
    /// @brief Software handle pointer.
    ///
    Software_Handle *Handle;

    friend class Xila_Class;
    friend class Shell_Class;

private:
    ///
    /// @brief Temporary variable to receive current instruction from queue.
    ///
    Xila_Class::Instruction Current_Instruction;

    ///
    /// @brief Queue handle.
    ///
    QueueHandle_t Instruction_Queue_Handle;

    ///
    /// @brief Last software watchdog feed.
    ///
    uint32_t Last_Watchdog_Feed;

    ///
    /// @brief Watchdog defined timeout.
    ///
    uint16_t Watchdog_Timeout;
};