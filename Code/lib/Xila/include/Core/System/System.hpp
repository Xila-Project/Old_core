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
        // - Methods
         
        // - - Constructor / Destructor
        System_Class();
        ~System_Class();

        // - - Device

        void Get_Device_Name(String_Type& Device_Name);
        uint64_t Get_eFuse_MAC();
        uint8_t Get_Chip_Revision();
        const char *Get_Chip_Model();
        uint32_t Get_Chip_Cores();
        uint32_t Get_CPU_Frequency();
        const char *Get_SDK_Version();

        void Set_Device_Name(const String_Type& Device_Name);

        // - - Time

        // - - - Getters
        Time_Type Get_Time();
        Date_Type Get_Date();
        uint32_t Get_Cycles_Count();
        Time_Type Get_Up_Time();
        uint32_t Get_Up_Time_Milliseconds();
        uint64_t Get_Up_Time_Microseconds();

        uint32_t Get_UTC_Offset();
        uint16_t Get_Daylight_Offset();
        void Get_NTP_Server(String_Type& NTP_Server);
        
        // - - - Setters
        void Set_Time_Zone(uint32_t UTC_Offset, uint16_t Daylight_Offset);
        void Set_NTP_Server(const String_Type& NTP_Server);

        // - - System

        void Start();
        void Stop();

        void Shutdown();
        void Restart();
        void Hibernate();

        static void Task_Start_Function(void *Instance_Pointer);
        void Task_Function();

    protected:
        // - Attributes

        /// @brief Task used to run the system.
        Task_Type Task;

        // - - Device

        /// @brief Device name used as Network hostname ...
        Static_String_Type<32> Device_Name;

        // - - Time

        /// @brief UTC offset in seconds.
        int32_t UTC_Offset;
        /// @brief Daylight offset in seconds.
        int16_t Daylight_Offset;
        /// @brief NTP server name.
        Static_String_Class<32> NTP_Server;


        // - Methods

        // - - System

        void Load();
        void Start_Animation();
        void Stop_Animation();
        void Start_Modules();

        Result_Type Load_Registry();
        Result_Type Save_Registry();
        Result_Type Create_Registry();

        Result_Type Save_Dump();
        Result_Type Load_Dump();

        Result_Type Upgrade(File_Type Executable_File);

        void Second_Sleep_Routine();
        void Panic_Handler(System_Types::Panic_Code Panic_Code);
        void Execute_Startup_Function();

        // - - Animation

        static void Logo_Annimation_Callback(void* Object, int32_t Value);

    
    } System_Type;

    extern System_Type System;
}

#endif