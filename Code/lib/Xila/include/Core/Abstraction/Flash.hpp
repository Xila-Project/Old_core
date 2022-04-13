///
/// @file Flash.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 24-06-2021
///
/// @copyright Copyright (c) 2021
///

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

#ifndef FLASH_HPP_DEFINED
#define FLASH_HPP_DEFINED

inline uint32_t Xila_Class::Flash_Class::Get_Sketch_Size()
{
    return Sketch_Size(SKETCH_SIZE_TOTAL);
}

inline Xila_Class::Event Xila_Class::Flash_Class::Read(uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (spi_flash_read(Offset, (uint32_t *)Data, Size) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (esp_partition_read(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Erase_Sector(uint32_t Sector)
{
    if (spi_flash_erase_sector(Sector) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Write(uint32_t Offset, uint32_t* Data, size_t Size)
{
    if (spi_flash_write(Offset, (uint32_t*)Data, Size) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Partition_Erase_Range(const esp_partition_t* Partition, uint32_t Offset, size_t Size)
{
    if (esp_partition_erase_range(Partition, Offset, Size) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Partition_Write(const esp_partition_t* Partition, uint32_t Offset, uint32_t* Data, size_t Size)
{
    if (esp_partition_write(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Success;
    }
    return Error;
}

inline Xila_Class::Event Xila_Class::Flash_Class::Set_Boot_Partition(const uint8_t Partition_Number)
{
    if (Partition_Number > Xila_Partition)
    {
        return Error;
    }
    if (esp_ota_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_MIN + Partition_Number)) == ESP_OK)
    {
        return Success;
    }
    return Error;
}



#endif