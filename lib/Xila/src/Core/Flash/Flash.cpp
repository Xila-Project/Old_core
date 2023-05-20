/// @file Flash.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Flash/Flash.hpp"

#include "esp_partition.h"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Flash_Types;

Flash_Type Xila_Namespace::Flash;

uint32_t Xila_Namespace::Flash_Class::Get_Sketch_Size()
{
    return Sketch_Size(SKETCH_SIZE_TOTAL);
}

Result_Type Xila_Namespace::Flash_Class::Read(uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (spi_flash_read(Offset, (uint32_t *)Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (esp_partition_read(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Erase_Sector(uint32_t Sector)
{
    if (spi_flash_erase_sector(Sector) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Write(uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (spi_flash_write(Offset, (uint32_t *)Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size)
{
    if (esp_partition_erase_range(Partition, Offset, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Partition_Write(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size)
{
    if (esp_partition_write(Partition, Offset, Data, Size) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type Xila_Namespace::Flash_Class::Set_Boot_Partition(Partition_Subtype_Type Partition_Subtype)
{
    if (Partition_Subtype > Xila_Partition)
    {
        return Result_Type::Error;
    }
    if (esp_ota_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, (esp_partition_subtype_t)Partition_Subtype, NULL)) == ESP_OK)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

uint32_t Xila_Namespace::Flash_Class::Get_Sketch_Free_Space()
{
    const esp_partition_t *Partition = esp_ota_get_next_update_partition(NULL);
    if (!Partition)
    {
        return 0;
    }
    return Partition->size;
}

String_Type &Xila_Namespace::Flash_Class::Get_Sketch_MD5(String_Type &String)
{
    String = ESP.getSketchMD5().c_str();
    return String;
}

uint32_t Xila_Namespace::Flash_Class::Sketch_Size(sketchSize_t Response)
{
    esp_image_metadata_t data;
    const esp_partition_t *running = esp_ota_get_running_partition();
    if (!running)
        return 0;
    const esp_partition_pos_t running_pos = {
        .offset = running->address,
        .size = running->size,
    };
    data.start_addr = running_pos.offset;
    esp_image_verify(ESP_IMAGE_VERIFY, &running_pos, &data);
    if (Response)
    {
        return running_pos.size - data.image_len;
    }
    else
    {
        return data.image_len;
    }
}

Size_Type Xila_Namespace::Flash_Class::Get_Size()
{
    return ESP.getFlashChipSize();
}

Size_Type Xila_Namespace::Flash_Class::Get_Speed()
{
    return ESP.getFlashChipSpeed();
}

Flash_Mode_Type Xila_Namespace::Flash_Class::Get_Mode()
{
    return (Flash_Mode_Type) ESP.getFlashChipMode();
}