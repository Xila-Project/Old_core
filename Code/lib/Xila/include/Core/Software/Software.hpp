///
/// @file Software.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Software_Hpp_Included
#define Software_Hpp_Included

#include "../Module.hpp"

#include "Software_Handle.hpp"

#include <vector>

/*
///
/// @brief String to 16 bits encoded instruction conversion macro.
///
#define Instruction(Sender, Argument_1, Argument_2, Argument_3) (Sender * 16777216 + Argument_1 * 65536 + Argument_2 * 256 + Argument_3)*/

namespace Xila_Namespace
{
    typedef class Software_Class : public Module_Class
    {
    public:
    
        // - Types
        typedef enum State_Enumeration
        {
            Active,
            Maximized,
            Minimized
        } State_Type;

        // - Methods

        // - - Constructor / Destructor
        Software_Class(Software_Handle_Type *Handle_Pointer, Size_Type Main_Task_Stack_Size = Default_Main_Task_Stack_Size, Size_Type Queue_Size = Default_Instruction_Queue_Size);
        virtual ~Software_Class();

        /// @brief Software task handle.
        ///
        Task_Type Main_Task;

        static void Start_Main_Task_Function(void* Instance_Pointer);
        virtual void Main_Task_Function();

        // Handler for external software.
        static void Create_Instance();
        void Minimize();
        void Maximize();
        void Kill();
        void Close();

    private:
        // - Attributes
        // - - Local attributes
        Software_Handle_Type *Handle_Pointer;
        // - - Static attributes
        /// @brief Openned software pointer array
        static std::vector<Software_Class *> List;

    } Software_Type;
}

#endif