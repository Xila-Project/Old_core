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

#include "../Graphics/Graphics.hpp"
#include "../Drive/Drive.hpp"

#ifndef Default_Daylight_Offset
#define Default_Daylight_Offset 60 * 60
#endif
#ifndef Default_UTC_Offset
#define Default_UTC_Offset 60 * 60
#endif
#ifndef Default_NTP_Server
#define Default_NTP_Server "0.fr.pool.ntp.org"
#endif

//==============================================================================//

///
/// @brief System module API
///

namespace Xila_Namespace
{
    namespace System_Types
    {
        /// @brief Panic codes used by the panic handler.
        enum class Panic_Type : uint32_t
        {
            Missing_System_Files,     ///< Missing system files (registries).
            Failed_To_Update_Display, ///< Failed to update display.
            Damaged_System_Registry,  ///< Damaged system registry.
            Installation_Conflict,    ///< Installation conflict (between MCU and Drive).
            Drive_Failure,            ///< System drive failure (disconnected).
            Failed_To_Start_Display,  ///< Failed to start display.
            Failed_To_Start_Graphics,
            Failed_To_Start_Sound,
            Failed_To_Start_Power,
            Failed_To_Start_Communication,
            Failed_To_Start_Accounts,
            Failed_To_Start_Drive,
            Failed_To_Start_Softwares,

            Low_Memory,        ///< Low memory (fragmentation, too much software openned).
            Memory_Corruption, ///< Memory corruption.
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

        /// - - - Getters

        /// @brief Get the device name.
        /// @param Device_Name Pointer to a string to store the device name.
        /// @return String containing the device name.
        String_Type &Get_Device_Name(String_Type &Device_Name);

        /// @brief Get the device MAC address.
        /// @return Device MAC address.
        uint64_t Get_eFuse_MAC();

        /// @brief Get the device chip revision.
        /// @return Device chip revision.
        uint8_t Get_Chip_Revision();

        /// @brief Get the device chip model.
        /// @return String containing the chip model.
        const char *Get_Chip_Model();

        /// @brief Get the device chip cores.
        /// @return Device chip cores.
        uint32_t Get_Chip_Cores();

        /// @brief Get the device chip frequency.
        /// @return Device chip frequency.
        uint32_t Get_CPU_Frequency();

        /// - - - Setters

        /// @brief Set the device name.
        void Set_Device_Name(const char *Device_Name);

        // - - Time

        // - - - Getters

        /// @brief Get the current time.
        /// @param Synchronization_Timeout Timeout to wait for NTP synchronization. 
        /// @return `Time_Type` containing the current time.
        Time_Type Get_Time(uint32_t Synchronization_Timeout = 5000);

        /// @brief Get the current date.
        /// @return `Date_Type` containing the current date.
        Date_Type Get_Date();

        /// @brief Get cycles count since the system start.
        /// @return Cycles count since the system start.
        uint32_t Get_Cycles_Count();

        /// @brief Get the system uptime.
        /// @return `Time_Type` containing the system uptime.
        Time_Type Get_Up_Time();

        /// @brief Get the system uptime in milliseconds.
        /// @return System uptime in milliseconds.
        uint32_t Get_Up_Time_Milliseconds();

        /// @brief Get the system uptime in microseconds.
        /// @return System uptime in microseconds.
        uint64_t Get_Up_Time_Microseconds();

        /// @brief Get UTC offset.
        /// @return UTC offset in seconds.
        uint32_t Get_UTC_Offset();

        /// @brief Get daylight offset.
        /// @return Daylight offset in seconds.
        uint16_t Get_Daylight_Offset();

        /// @brief Get NTP server.
        /// @param NTP_Server Pointer to a string to store the NTP server.
        void Get_NTP_Server(String_Type &NTP_Server);

        // - - - Setters

        /// @brief Set the time zone.
        /// @param UTC_Offset UTC offset in seconds.
        /// @param Daylight_Offset Daylight offset in seconds.
        void Set_Time_Zone(uint32_t UTC_Offset, uint16_t Daylight_Offset);

        /// @brief Set the NTP server.
        /// @param NTP_Server Pointer to a string containing the NTP server.
        void Set_NTP_Server(const char *NTP_Server);

        /// @brief Refresh NTP client.
        void Refresh_NTP_Client();

        // - - System

        /// @brief Start the system.
        void Start();

        /// @brief Shutdown the system.
        void Shutdown();

        /// @brief Restart the system.
        void Restart();

        
        static void Task_Start_Function(void *Instance_Pointer);
        void Task_Function();

    protected:
        // - Attributes

        /// @brief Task used to run the system.
        Task_Type Task;

        // - - Log
        Semaphore_Type Log_Semaphore;

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

        // - - Animation
        void Start_Load_Animation(Graphics_Types::Object_Type *, Graphics_Types::Animation_Type *);
        static void Load_Animation_Callback(void *Object, int32_t Value);
        void Stop_Load_Animation(Graphics_Types::Object_Type *, Graphics_Types::Animation_Type *);

        // - - Modules
        void Start_Modules();

        // - - System
        void Load();

        Result_Type Load_Registry();
        Result_Type Save_Registry();
        Result_Type Create_Registry();

        Result_Type Upgrade(Drive_Types::File_Type Executable_File);

        void Panic_Handler(System_Types::Panic_Type Panic_Code);

        // - - Animation

    } System_Type;

    extern System_Type System;

}

#endif