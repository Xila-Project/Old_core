/// @file Flash.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#ifdef Xila_Flash_Hardware_ESP32

#include "Flash/Flash.hpp"

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

using namespace Xila_Namespace;
using namespace Xila_Namespace::Flash_Types;

Flash_Type Xila_Namespace::Flash;

Size_Type Flash_Class::Get_Sketch_Size()
{
    return ESP.getSketchSize();
}

Result_Type Flash_Class::Read(uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    if (spi_flash_read(Offset, (uint32_t *)Data, Size) != ESP_OK)
        return Result_Type::Error;

    return Result_Type::Success;
}

Result_Type Flash_Class::Partition_Read(const Partition_Type *Partition, uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    if (esp_partition_read((const esp_partition_t *)Partition, Offset, Data, Size) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Flash_Class::Erase_Sector(uint32_t Sector)
{
    if (spi_flash_erase_sector(Sector) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Flash_Class::Write(uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    if (spi_flash_write(Offset, (uint32_t *)Data, Size) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Flash_Class::Partition_Erase_Range(const Partition_Type *Partition, uint32_t Offset, Size_Type Size)
{
    if (esp_partition_erase_range((const esp_partition_t *)Partition, Offset, Size) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Flash_Class::Partition_Write(const Partition_Type *Partition, uint32_t Offset, uint32_t *Data, Size_Type Size)
{
    if (esp_partition_write((const esp_partition_t *)Partition, Offset, Data, Size) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Result_Type Flash_Class::Set_Boot_Partition(uint8_t Partition_Subtype)
{
    if (esp_ota_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, (esp_partition_subtype_t)Partition_Subtype, NULL)) != ESP_OK)
        return Result_Type::Error;
    return Result_Type::Success;
}

Size_Type Flash_Class::Get_Sketch_Free_Space()
{
    return ESP.getFreeSketchSpace();
}

String_Type& Flash_Class::Get_Sketch_MD5(String_Type &String)
{
    String = ESP.getSketchMD5().c_str();
    return String;
}

Size_Type Flash_Class::Get_Size()
{
    return ESP.getFlashChipSize();
}

QWord_Type Flash_Class::Get_Speed()
{
    return ESP.getFlashChipSpeed();
}

Natural_Type Flash_Class::Get_Mode()
{
    return ESP.getFlashChipMode();
}

const Partition_Type *Flash_Class::Find(Natural_Type Type, Natural_Type Subtype, const char *Label, Natural_Type Index)
{
    if (Index == 0)
        return esp_partition_find_first((esp_partition_type_t)Type, (esp_partition_subtype_t)Subtype, Label);

    auto Partition_Iterator = esp_partition_find((esp_partition_type_t)Type, (esp_partition_subtype_t)Subtype, Label);
    for (uint8_t i = 0; i < Index; i++)
        Partition_Iterator = esp_partition_next(Partition_Iterator);

    auto Partition = esp_partition_get(Partition_Iterator);
    esp_partition_iterator_release(Partition_Iterator);

    return Partition;
}

#endif