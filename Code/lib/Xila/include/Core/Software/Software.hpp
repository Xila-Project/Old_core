///
/// @file Software.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

class Software_Handle;

#include "../Module.hpp"

#include "Software_Handle.hpp"
#include "Task.hpp"
#include "Semaphore.hpp"

///
/// @brief String to 16 bits encoded instruction conversion macro.
///
#define Instruction(Sender, Argument_1, Argument_2, Argument_3) (Sender * 16777216 + Argument_1 * 65536 + Argument_2 * 256 + Argument_3)

class Software : public Module_Class
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
    Software(Software_Handle &Software_Handle, uint8_t Queue_Size = Default_Instruction_Queue_Size);
    virtual ~Software();

    // - - Management

    // -- Friendship -- //
    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

    ///
    /// @brief Openned software pointer array
    ///
    /// Openned[0] : Maximized software
    /// Openned[1 - 7] : All openned software (Slot 1 is for Shell)
    ///
    Software *Openned[8] = {NULL};

    // -- Methods -- //

    void Defrag();

    void Check_Watchdog();

    void Shell_Maximize();
    void Shell_Send_Instruction(Instruction);
    void Shell_Set_Variable(Address, uint8_t, const void *);

    uint8_t Seek_Open_Software_Handle(Software_Handle const &Software_Handle);

    State Get_State(Software_Handle const &Software_Handle);

    void Send_Instruction(Instruction Intruction);

    ///
    /// @brief Convert 2 byte char instruction into Xila Instruction and send it.
    ///
    /// @param Instruction_Char_1 Instruction first byte
    /// @param Instruction_Char_2 Instruction second byte
    inline void Send_Instruction(char Instruction_Char_1, char Instruction_Char_2)
    {
        Send_Instruction(((uint16_t)Instruction_Char_1 << 8) | (uint16_t)Instruction_Char_2);
    }

    virtual void Set_Variable(Address Address, uint8_t Type, const void *Variable);

    Instruction Get_Instruction();

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
    // -- Attributes -- //

    static uint32_t Watchdog_Timer = 0;
    static uint8_t Watchdog_State = 0;

    ///
    /// @brief Temporary variable to receive current instruction from queue.
    ///
    Instruction Current_Instruction;

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