///
/// @file Core.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila core component source file.
/// @version 0.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

#include "vfs_api.h"
#include "sd_diskio.h"
#include "ff.h"
#include "FS.h"

Xila_Class *Xila_Class::Instance_Pointer = NULL;

Xila_Class Xila;

Xila_Class::Xila_Class()
    : Account(),
      Clipboard(),
      Dialog(),
      Display(),
      Drive(),
      GPIO(),
      Keyboard(),
      Power(),
      Software_Management(),
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

  esp_sleep_enable_ext0_wakeup(Power_Button_Pin, LOW);
}

Xila_Class::~Xila_Class() // destructor
{
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = NULL;
}