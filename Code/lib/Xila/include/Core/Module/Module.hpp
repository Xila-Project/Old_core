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
#include "FS.h"
#include "ArduinoTrace.h"

// - - Base types

#include "Base_Types.hpp"

// - - Other types

#include "../Log/Log.hpp"
#include "../Communication/IP_Address.hpp"
#include "Task.hpp"
#include "Instruction.hpp"
#include "Semaphore.hpp"
#include "Queue.hpp"
#include "String.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Registry.hpp"

#include "../Configuration/Path.hpp"

#define Stringizing(x) #x

namespace Xila_Namespace
{
    /// @brief Module type enumeration.
    typedef class Module_Class
    {
    public:  
        // - Methods

        // - - Constructor / destructor
        Module_Class(Size_Type Queue_Size = Default_Instruction_Queue_Size);
        ~Module_Class();

        // - - Management
        Result_Type Send_Instruction(const Instruction_Type &Instruction);
        Size_Type Instruction_Available();

        // - - Getters
        Instruction_Type Get_Instruction();

    private:
        // - Attributes
        QueueHandle_t Instruction_Queue_Handle;

        static std::vector<Module_Class *> List; // - Module lists.

    } Module_Type;
}

#endif
