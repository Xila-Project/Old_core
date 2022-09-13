///
/// @file Flash.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 24-06-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Flash_Hpp_Included
#define Flash_Hpp_Included

#include "Arduino.h"

#include "Esp.h"
#include "rom/spi_flash.h"
#include "esp_sleep.h"
#include "esp_spi_flash.h"
#include <memory>
#include <soc/soc.h>
#include <soc/efuse_reg.h>
#include <esp_partition.h>
extern "C"
{
#include "esp_ota_ops.h"
#include "esp_image_format.h"
}
#include <MD5Builder.h>

#include "../Module.hpp"

///=============================================================================//
///
/// @brief Flash wrapper class.
///

namespace Xila_Namespace
{
    class Flash_Class : public Module_Class
    {
    public:
        // - Types

        typedef enum Partition_Subtype_Enumeration
        {
            Bootloader_Partition = ESP_PARTITION_SUBTYPE_APP_FACTORY, //!< Factory application partition
            OTA_Minimum = ESP_PARTITION_SUBTYPE_APP_OTA_MIN,          //!< Base for OTA partition subtypes
            Xila_Partition = ESP_PARTITION_SUBTYPE_APP_OTA_0,         //!< OTA partition 0
            OTA_1 = ESP_PARTITION_SUBTYPE_APP_OTA_1,                  //!< OTA partition 1
            OTA_2 = ESP_PARTITION_SUBTYPE_APP_OTA_2,                  //!< OTA partition 2
            OTA_3 = ESP_PARTITION_SUBTYPE_APP_OTA_3,                  //!< OTA partition 3
            OTA_4 = ESP_PARTITION_SUBTYPE_APP_OTA_4,                  //!< OTA partition 4
            OTA_5 = ESP_PARTITION_SUBTYPE_APP_OTA_5,                  //!< OTA partition 5
            OTA_6 = ESP_PARTITION_SUBTYPE_APP_OTA_6,                  //!< OTA partition 6
            OTA_7 = ESP_PARTITION_SUBTYPE_APP_OTA_7,                  //!< OTA partition 7
            OTA_8 = ESP_PARTITION_SUBTYPE_APP_OTA_8,                  //!< OTA partition 8
            OTA_9 = ESP_PARTITION_SUBTYPE_APP_OTA_9,                  //!< OTA partition 9
            OTA_10 = ESP_PARTITION_SUBTYPE_APP_OTA_10,                //!< OTA partition 10
            OTA_11 = ESP_PARTITION_SUBTYPE_APP_OTA_11,                //!< OTA partition 11
            OTA_12 = ESP_PARTITION_SUBTYPE_APP_OTA_12,                //!< OTA partition 12
            OTA_13 = ESP_PARTITION_SUBTYPE_APP_OTA_13,                //!< OTA partition 13
            OTA_14 = ESP_PARTITION_SUBTYPE_APP_OTA_14,                //!< OTA partition 14
            OTA_15 = ESP_PARTITION_SUBTYPE_APP_OTA_15,                //!< OTA partition 15
            OTA_Maximum = ESP_PARTITION_SUBTYPE_APP_OTA_MAX,          //!< Max subtype of OTA partition
            Application_Test = ESP_PARTITION_SUBTYPE_APP_TEST,        //!< Test application partition

            Data_OTA = ESP_PARTITION_SUBTYPE_DATA_OTA,             //!< OTA selection partition
            Data_PHY = ESP_PARTITION_SUBTYPE_DATA_PHY,             //!< PHY init data partition
            Data_NVS = ESP_PARTITION_SUBTYPE_DATA_NVS,             //!< NVS partition
            Data_Core_Dump = ESP_PARTITION_SUBTYPE_DATA_COREDUMP,  //!< COREDUMP partition
            Data_NVS_Keys = ESP_PARTITION_SUBTYPE_DATA_NVS_KEYS,   //!< Partition for NVS keys
            Data_eFuse = ESP_PARTITION_SUBTYPE_DATA_EFUSE_EM,      //!< Partition for emulate eFuse bits
            Data_Undefined = ESP_PARTITION_SUBTYPE_DATA_UNDEFINED, //!< Undefined (or unspecified) data partition

            Data_ESPHTTPD = ESP_PARTITION_SUBTYPE_DATA_ESPHTTPD, //!< ESPHTTPD partition
            Data_Fat = ESP_PARTITION_SUBTYPE_DATA_FAT,           //!< FAT partition
            Data_SPIFFS = ESP_PARTITION_SUBTYPE_DATA_SPIFFS,     //!< SPIFFS partition

            Any = ESP_PARTITION_SUBTYPE_ANY, //!< Used to search for partitions with any subtype
        } Partition_Subtype_Type;

        // -- Methods
        uint32_t Get_Size();
        uint32_t Get_Speed();
        FlashMode_t Get_Mode();

        Result::Type Read(uint32_t Offset, uint32_t *Data, size_t Size);

        Result::Type Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size);

        uint32_t Get_Sketch_Size();
        String Get_Sketch_MD5();
        uint32_t Get_Sketch_Free_Space();

    private:
        // -- Methods
        Result::Type Set_Boot_Partition(Partition_Subtype_Type Partition_Subtype);

        Result::Type Erase_Sector(uint32_t Sector);
        Result::Type Write(uint32_t Offset, uint32_t *Data, size_t Size);

        Result::Type Partition_Write(const esp_partition_t *Partition, uint32_t Offset_, uint32_t *Data, size_t Size);
        Result::Type Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size);

        static uint32_t Sketch_Size(sketchSize_t Response);
        uint32_t Magic_Size(uint8_t Byte);
        uint32_t Magic_Speed(uint8_t Byte);
        FlashMode_t Magic_Mode(uint8_t Byte);

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;
    } Flash;

}

#endif