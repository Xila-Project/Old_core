/**
 * @file Core.cpp
 * @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 * @brief Main xila componennt declaration
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Core/Core.hpp"

#include "vfs_api.h"
#include "sd_diskio.h"
#include "ff.h"
#include "FS.h"

Xila_Class *Xila_Class::Instance_Pointer = NULL;

Xila_Class Xila;

Xila_Class::Xila_Class() : Account(),
                           Clipboard(),
                           Dialog(),
                           Display(),
                          Drive(),
                           Keyboard(),
                           Power(),
                           Software(),
                           Sound(),
                           System(),
                           Time(),
                           WiFi()

{
  if (Instance_Pointer != NULL)
  {
    Xila.System.Panic_Handler(Xila.System.Memory_Corruption);
  }
  Instance_Pointer = this;

  esp_sleep_enable_ext0_wakeup(POWER_BUTTON_PIN, LOW);
}

Xila_Class::~Xila_Class() // destructor
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = NULL;
}