#include "Core/Core.hpp"

// Software management

uint8_t Xila_Class::Seek_Open_Software_Handle(Software_Handle_Class const &Software_Handle)
{
  for (uint8_t i = 1; i <= 8; i++)
  {
    if (i < 8 && *Open_Software_Pointer[i]->Handle_Pointer == Software_Handle)
    {
      return i;
    }
    else if (i == 8)
    {
      return 0;
    }
  }
}

void Xila_Class::Maximize_Shell()
{
  Maximize_Software(Shell_Handle);
}

void Xila_Class::Open_Software(Software_Handle_Class const &Software_Handle)
{
  uint8_t i = 2;
  if (Software_Handle == Shell_Handle)
  {
    if (Open_Software_Pointer[1] != NULL)
    {
      Maximize_Software(Shell_Handle);
      return;
    }
    else
    {
      Open_Software_Pointer[i] = (*Software_Handle.Load_Function_Pointer)();
      Minimize_Software();
      return;
    }
  }
  for (; i < 8; i++) //check if software is openned already
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (**Software_Handle_Pointer == *Open_Software_Pointer[i]->Handle_Pointer)
      {
        Maximize_Software(*Open_Software_Pointer[i]->Handle_Pointer);
        return;
      }
    }
  }
  // if not, open it in an empty slot
  for (i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] == NULL)
    {
      Open_Software_Pointer[i] = (*Software_Handle.Load_Function_Pointer)();
      return;
    }
  }

  // if not enough place, call event handler

  Event_Dialog(F("Too many openned software."), Error);
}

void Xila_Class::Close_Software(Software_Handle_Class* Software_Handle_To_Close)
{
  if (System_State == SYSTEM_STATE_STANDALONE)
  {
    if (Software_Handle_To_Close == NULL) //by default delete current running software
    {
      for (uint8_t i = 2; i < 8; i++)
      {
        if (Open_Software_Pointer[i] != NULL)
        {
          if (Open_Software_Pointer[i]->Handle_Pointer == Open_Software_Pointer[0]->Handle_Pointer)
          {
            Open_Software_Pointer[i] = NULL;
          }
        }
      }
      Open_Software_Pointer[0]->Execute(Close);
      Open_Software_Pointer[0] = NULL;
    }
    if (Software_Handle_To_Close == NULL)
    {
      for (uint8_t i = 2; i < 8; i++)
      {
        if (Open_Software_Pointer[i] != NULL)
        {
          if (Open_Software_Pointer[i])
        }
      }
    }
  }
  else if (System_State == SYSTEM_STATE_NORMAL)
  {
    if (Software_Handle_To_Close == NULL) //by default delete current running software
    {
      for (uint8_t i = 2; i < 8; i++)
      {
        if (Open_Software_Pointer[i] != NULL)
        {
          if (Open_Software_Pointer[i]->Handle_Pointer == Open_Software_Pointer[0]->Handle_Pointer)
          {
            Open_Software_Pointer[i] = NULL;
          }
        }
      }
      Open_Software_Pointer[0]->Execute(Close);
      Open_Software_Pointer[0] = NULL;
    }
    else
    {
      for (uint8_t i = 2; i < 8; i++)
      {
        if (Open_Software_Pointer[i] != NULL)
        {
          if (Open_Software_Pointer[i]->Handle_Pointer == Software_Handle_To_Close)
          {
            Open_Software_Pointer[i]->Execute(Close);
            Open_Software_Pointer[i] = NULL;
          }
        }
      }
    }
    Maximize_Software(1); //reopen shell
  }
}

void Xila_Class::Minimize_Software()
{
  if (Open_Software_Pointer[0] != NULL)
  {
    Open_Software_Pointer[0]->Execute(Minimize);
    Open_Software_Pointer[0] = NULL;
  }
}

void Xila_Class::Maximize_Software(Software_Handle_Class const &Software_Handle)
{
  if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
  {
    return;
  }
  if (Open_Software_Pointer[i])

    if (System_State == SYSTEM_STATE_STANDALONE)
    {
      if (Software_Handle.Type == SOFTWARE_STANDALONE)
      {
        if (Seek_Open_Software_Handle(Software_Handle) == 0)
        {
          return;
        }
        Minimize_Software();
        Open_Software_Pointer[0] = Open_Software_Pointer[Seek_Open_Software_Handle(Software_Handle)];
      }
      else
      {
        Rollback();
        return;
      }
    }
    else
    {
      if (Software_Handle.Type == SOFTWARE_STANDALONE)
      {
        Open_Software(Software_Handle);
      }
      if (Open_Software_Pointer[0] != NULL)
      {
        Minimize_Software();
      }

      vTaskResume(Open_Software_Pointer[0]->Task_Handle);
      Open_Software_Pointer[0]->Execute(Maximize);
    }
}

Xila_Event Xila_Class::Load_Software_Handle(Software_Handle_Class *Software_Handle_To_Add, const __FlashStringHelper *Header_Path)
{
  if (Software_Handle_To_Add->Type == SOFTWARE_STANDALONE)
  {
    return Error;
  }

  if (!Drive->exists(Header_Path))
  {
    return Error;
  }
  File Temporary_File = Drive->open(Header_Path);
  DynamicJsonDocument Software_Registry(DEFAULT_REGISTRY_SIZE);
  if (deserializeJson(Software_Registry, Temporary_File) != DeserializationError::Ok)
  {
    return;
  }
  if (Software_Registry["Type"] != 0)
  {
    return Error;
  }
  if (strcmp(Software_Registry["Name"], Software_Handle_To_Add->Name) != 0)
  {
    return Error;
  }

  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i] == NULL)
    {
      Software_Handle_Pointer[i] = Software_Handle_To_Add;
    }
  }
}

Xila_Event Xila_Class::Add_Software_Handle(Software_Handle_Class const& Software_Handle_To_Add)
{
  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i] == NULL)
    {
      Software_Handle_Pointer[i] = Software_Handle_To_Add;
      return Success;
    }
    else
    {
      if (i == MAXIMUM_SOFTWARE - 1)
      {
        return Error;
      }
    }
  }
}
