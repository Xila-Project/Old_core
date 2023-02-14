///
/// @file System.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 29-03-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef System_Hpp_Included
#define System_Hpp_Included

#include "../Module/Module.hpp"

//==============================================================================//

///
/// @brief System module API
///

namespace Xila_Namespace
{
    namespace System_Types
    {
        /// @brief Panic codes used by the panic handler.
        enum class Panic_Code
        {
            Missing_System_Files,     ///< Missing system files (registries).
            Damaged_System_Registry,  ///< Damaged system registry.
            Installation_Conflict,    ///< Installation conflict (between MCU and Display or Drive).
            System_Drive_Failure,     ///< System drive failure (disconnected).
            Failed_To_Start_Display,  ///< Failed to start display.
            Failed_To_Start_Graphics,
            Failed_To_Update_Display, ///< Failed to update display.
            Low_Memory,               ///< Low memory (fragmentation, too much software openned).
            Memory_Corruption,        ///< Memory corruption.
        };
    };

    typedef class System_Class : public Module_Class
    {
    public:
        // -- Constructors
        System_Class();
        ~System_Class();

        // -- Methods
        const char *Get_Device_Name();
        uint64_t Get_eFuse_MAC();
        uint8_t Get_Chip_Revision();
        const char *Get_Chip_Model();
        uint32_t Get_Chip_Cores();
        uint32_t Get_CPU_Frequency();
        const char *Get_SDK_Version();

        void Start();

        void Shutdown();
        void Restart();
        void Hibernate();

        static void Task_Start_Function(void *Instance_Pointer);
        void Task_Function();

    protected:
        // System's task :
        Task_Type Task;

        ///
        /// @brief Device name used as Network hostname ...
        ///
        char Device_Name[25];

        // -- Methods

        void Load();

        Result_Type Load_Registry();
        Result_Type Save_Registry();

        Result_Type Save_Dump();
        Result_Type Load_Dump();

        Result_Type Upgrade(File_Type Executable_File);

        // - Animation

        static void Logo_Annimation_Callback(void* Object, int32_t Value);

        void Second_Sleep_Routine();


        void Panic_Handler(System_Types::Panic_Code Panic_Code);

        void Execute_Startup_Function();
    } System_Type;

    extern System_Type System;
}

#endif