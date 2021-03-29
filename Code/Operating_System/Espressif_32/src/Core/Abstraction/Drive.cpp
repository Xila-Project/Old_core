///
/// @file Drive.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

// SD
#include "vfs_api.h"
#include "sd_diskio.h"
#include "ff.h"

// SD MMC
#include "vfs_api.h"

extern "C"
{
#include <sys/unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdmmc_defs.h"
#include "sdmmc_cmd.h"
}
#include "ff.h"

// Custom methods

///
/// @brief Copy file from two openned file
///
/// @param Origin_File File to duplicate
/// @param Destination_File File to write
/// @return Xila_Class::Event::Success or Xila_Class::Event::Error
Xila_Class::Event Xila_Class::Drive_Class::Copy(File &Origin_File, File &Destination_File)
{
    uint8_t Readed_Bytes;
    uint8_t Buffer[255];
    if (!Origin_File || !Destination_File)
    {
        return Error;
    }
    while ((Readed_Bytes = Origin_File.read(Buffer, sizeof(Buffer))) > 0)
    {
        Destination_File.write(Buffer, Readed_Bytes);
        Xila.Task.Delay(2);
    }
    return Success;
}

///
/// @brief
///
/// @param Folder
/// @return uint16_t return the number of files inside a folder
uint16_t Xila_Class::Drive_Class::Count_Files(File &Folder)
{
    if (Folder)
    {
        return 0;
    }
    if (!Folder.isDirectory())
    {
        return 0;
    }
    uint32_t i = 0;
    File Temporary_File = Folder.openNextFile();
    while (Temporary_File)
    {
        i++;
        Temporary_File.close();
        Temporary_File = Folder.openNextFile();
    }
    return i;
}

///
 /// @brief 
 /// 
 /// @param File 
 /// @param File_Name 
 /// @param Size 
 /// @return Xila_Class::Event 
Xila_Class::Event Xila_Class::Drive_Class::Get_Name(File const &File, char *File_Name, size_t Size)
{
  const char *Temporary_File_Name = File.name();
  if (File_Name == NULL)
  {
    Verbose_Print_Line("NULL file name pointer !");
    return Error;
  }
  if (File_Name == NULL)
  {
    return Error;
  }

  memset(File_Name, '\0', Size);

  if (!File)
  {
    return Error;
  }
  for (uint8_t i = (strlen(File_Name) - 1); i >= 0; i--)
  {
    if (File_Name[i] == '/')
    {
      strlcpy(File_Name, Temporary_File_Name + i + 1, Size);
      break;
    }
  }
  return Success;
}


#if SD_MODE == 0

Xila_Class::Drive_Class::Drive_Class(FSImplPtr impl)
    : FS(impl),
      _card(NULL)
{
}

bool Xila_Class::Drive_Class::begin(const char *mountpoint, bool mode1bit)
{
    if (_card)
    {
        return true;
    }
    //mount
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
    sdmmc_host_t host = {
        .flags = SDMMC_HOST_FLAG_4BIT,
        .slot = SDMMC_HOST_SLOT_1,
        .max_freq_khz = SDMMC_FREQ_DEFAULT,
        .io_voltage = 3.3f,
        .init = &sdmmc_host_init,
        .set_bus_width = &sdmmc_host_set_bus_width,
        .get_bus_width = &sdmmc_host_get_slot_width,
        .set_bus_ddr_mode = &sdmmc_host_set_bus_ddr_mode,
        .set_card_clk = &sdmmc_host_set_card_clk,
        .do_transaction = &sdmmc_host_do_transaction,
        .deinit = &sdmmc_host_deinit,
        .io_int_enable = &sdmmc_host_io_int_enable,
        .io_int_wait = &sdmmc_host_io_int_wait,
        .command_timeout_ms = 0};
    host.max_freq_khz = SDMMC_FREQ_HIGHSPEED;
#ifdef BOARD_HAS_1BIT_SDMMC
    mode1bit = true;
#endif
    if (mode1bit)
    {
        host.flags = SDMMC_HOST_FLAG_1BIT; //use 1-line SD mode
        slot_config.width = 1;
    }

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 0};

    esp_err_t ret = esp_vfs_fat_sdmmc_mount(mountpoint, &host, &slot_config, &mount_config, &_card);
    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            log_e("Failed to mount filesystem. If you want the card to be formatted, set format_if_mount_failed = true.");
        }
        else if (ret == ESP_ERR_INVALID_STATE)
        {
            _impl->mountpoint(mountpoint);
            log_w("SD Already mounted");
            return true;
        }
        else
        {
            log_e("Failed to initialize the card (%d). Make sure SD card lines have pull-up resistors in place.", ret);
        }
        _card = NULL;
        return false;
    }
    _impl->mountpoint(mountpoint);
    return true;
}

void Xila_Class::Drive_Class::end()
{
    if (_card)
    {
        esp_vfs_fat_sdmmc_unmount();
        _impl->mountpoint(NULL);
        _card = NULL;
    }
}

sdcard_type_t Xila_Class::Drive_Class::cardType()
{
    if (!_card)
    {
        return CARD_NONE;
    }
    return (_card->ocr & SD_OCR_SDHC_CAP) ? CARD_SDHC : CARD_SD;
}

uint64_t Xila_Class::Drive_Class::cardSize()
{
    if (!_card)
    {
        return 0;
    }
    return (uint64_t)_card->csd.capacity * _card->csd.sector_size;
}

uint64_t Xila_Class::Drive_Class::totalBytes()
{
    FATFS *fsinfo;
    DWORD fre_clust;
    if (f_getfree("0:", &fre_clust, &fsinfo) != 0)
        return 0;
    uint64_t size = ((uint64_t)(fsinfo->csize)) * (fsinfo->n_fatent - 2)
#if _MAX_SS != 512
                    * (fsinfo->ssize);
#else
                    * 512;
#endif
    return size;
}

uint64_t Xila_Class::Drive_Class::usedBytes()
{
    FATFS *fsinfo;
    DWORD fre_clust;
    if (f_getfree("0:", &fre_clust, &fsinfo) != 0)
        return 0;
    uint64_t size = ((uint64_t)(fsinfo->csize)) * ((fsinfo->n_fatent - 2) - (fsinfo->free_clst))
#if _MAX_SS != 512
                    * (fsinfo->ssize);
#else
                    * 512;
#endif
    return size;
}

#elif SD_MODE == 1

Xila_Class::Drive_Class::Drive_Class(FSImplPtr impl) : FS(impl),
                                                       _pdrv(0xFF)
{
}

bool Xila_Class::Drive_Class::begin(uint8_t ssPin, SPIClass &spi, uint32_t frequency, const char *mountpoint, uint8_t max_files)
{
    if (_pdrv != 0xFF)
    {
        return true;
    }

    spi.begin();

    _pdrv = sdcard_init(ssPin, &spi, frequency);
    if (_pdrv == 0xFF)
    {
        return false;
    }

    if (!sdcard_mount(_pdrv, mountpoint, max_files))
    {
        sdcard_unmount(_pdrv);
        sdcard_uninit(_pdrv);
        _pdrv = 0xFF;
        return false;
    }

    _impl->mountpoint(mountpoint);
    return true;
}

void Xila_Class::Drive_Class::end()
{
    if (_pdrv != 0xFF)
    {
        _impl->mountpoint(NULL);
        sdcard_unmount(_pdrv);

        sdcard_uninit(_pdrv);
        _pdrv = 0xFF;
    }
}

sdcard_type_t Xila_Class::Drive_Class::cardType()
{
    if (_pdrv == 0xFF)
    {
        return CARD_NONE;
    }
    return sdcard_type(_pdrv);
}

uint64_t Xila_Class::Drive_Class::cardSize()
{
    if (_pdrv == 0xFF)
    {
        return 0;
    }
    size_t sectors = sdcard_num_sectors(_pdrv);
    size_t sectorSize = sdcard_sector_size(_pdrv);
    return (uint64_t)sectors * sectorSize;
}

uint64_t Xila_Class::Drive_Class::totalBytes()
{
    FATFS *fsinfo;
    DWORD fre_clust;
    if (f_getfree("0:", &fre_clust, &fsinfo) != 0)
        return 0;
    uint64_t size = ((uint64_t)(fsinfo->csize)) * (fsinfo->n_fatent - 2)
#if _MAX_SS != 512
                    * (fsinfo->ssize);
#else
                    * 512;
#endif
    return size;
}

uint64_t Xila_Class::Drive_Class::usedBytes()
{
    FATFS *fsinfo;
    DWORD fre_clust;
    if (f_getfree("0:", &fre_clust, &fsinfo) != 0)
        return 0;
    uint64_t size = ((uint64_t)(fsinfo->csize)) * ((fsinfo->n_fatent - 2) - (fsinfo->free_clst))
#if _MAX_SS != 512
                    * (fsinfo->ssize);
#else
                    * 512;
#endif
    return size;
}

#endif
