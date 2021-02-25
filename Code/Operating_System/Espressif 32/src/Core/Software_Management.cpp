#include "Core/Core.hpp"

// -- Software management -- //

void Xila_Class::Feed_Watchdog()
{
  Last_Watchdog_Feed = millis();
}

void Xila_Class::Delay(uint32_t Delay_In_Millisecond)
{
  Last_Watchdog_Feed = millis();
  vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

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

Xila_Event Xila_Class::Software_Open(Software_Handle_Class const& Software_Handle)
{
  // -- if software handle is shell handle, reopen it or maximize it

  uint8_t i = 2;
  if (Software_Handle == Shell_Handle)
  {
    if (Open_Software_Pointer[1] != NULL)
    {
      Maximize_Software(Shell_Handle);
      return Success;
    }
    else
    {
      Open_Software_Pointer[1] = (*Shell_Handle.Load_Function_Pointer)();
      Open_Software_Pointer[0] = Open_Software_Pointer[1];
      return Success;
    }
  }

  // -- checking if software is already openned
  for (i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (Software_Handle == *Open_Software_Pointer[i]->Handle_Pointer)
      {
        Maximize_Software(*Open_Software_Pointer[i]->Handle_Pointer);
        return Success;
      }
    }
  }

  // -- if the software isn't minimized, load it. -- //

  for (i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] == NULL)
    {
      Open_Software_Pointer[i] = (*Software_Handle.Load_Function_Pointer)();
      Open_Software_Pointer[0] = Open_Software_Pointer[i];
      return Success;
    }
  }
  return Error;
}

void Xila_Class::Close_Software()
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
  // -- Maximize shell
  Maximize_Shell();
}

void Xila_Class::Close_Software(Software_Handle_Class const &Software_Handle)
{

  for (uint8_t i = 2; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (*Open_Software_Pointer[i]->Handle_Pointer == Software_Handle)
      {
        Xila_Task_Handle Temporary_Task_Handle;
        Temporary_Task_Handle = Open_Software_Pointer[i]->Task_Handle;
        Open_Software_Pointer[i]->Execute(Close);
        vTaskResume(Temporary_Task_Handle);
        // -- Waiting for the software to close
        for (uint8_t ii = 0; ii <= 200; ii++)
        {
          if (eTaskGetState(Temporary_Task_Handle) == eDeleted)
          {
            break;
          }
          vTaskDelay(pdMS_TO_TICKS(20));
        }
        // -- Force closing the software, if not closed within 4000 ms
        if (eTaskGetState(Temporary_Task_Handle) != eDeleted)
        {
          delete Open_Software_Pointer[i];
          vTaskDelete(Temporary_Task_Handle);
        }
        Open_Software_Pointer[i] = NULL;

        // -- Don't forget to remove maximized pointer.
        if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
        {
          Open_Software_Pointer[0] = NULL;
        }

        break;
      }
    }
  }

  // -- Finaly, maximize shell
  Maximize_Shell();
}

void Xila_Class::Minimize_Software()
{
  if (Open_Software_Pointer[0] != NULL)
  {
    Open_Software_Pointer[0]->Execute(Minimize);
    Open_Software_Pointer[0] = NULL;
  }
}

Xila_Event Xila_Class::Maximize_Software(Software_Handle_Class const &Software_Handle)
{
  // -- Check if the software was already open or if another software is currently openned.
  if (Open_Software_Pointer[0]->Handle_Pointer != NULL)
  {
    if (*Open_Software_Pointer[0]->Handle_Pointer == Software_Handle)
    {
      return Success;
    }
    else
    {
      Minimize_Software();
    }
  }

  // -- Looking for the concern software
  for (uint8_t i = 1; i < 8; i++)
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (Software_Handle == *Open_Software_Pointer[i]->Handle_Pointer)
      {
        vTaskResume(Open_Software_Pointer[i]->Task_Handle);
        Open_Software_Pointer[i]->Execute(Maximize);
        Open_Software_Pointer[0] = Open_Software_Pointer[i];
        return Success;
      }
    }
  }
  return Error;
}

void Xila_Class::Force_Close_Software()
{
  if (*Open_Software_Pointer[0]->Handle_Pointer == Shell_Handle)
  {
    vTaskDelete(Open_Software_Pointer[1]->Task_Handle);
    delete Open_Software_Pointer[1];
    if (Open_Software_Pointer[1] == Open_Software_Pointer[0])
    {
      Open_Software_Pointer[0] = NULL;
    }
    Open_Software_Pointer[1] = NULL;
    Software_Open(Shell_Handle);
  }
  else
  {

    if (Open_Software_Pointer[0] != NULL)
    {
      vTaskDelete(Open_Software_Pointer[0]->Task_Handle);
      delete Open_Software_Pointer[0];
    }
    Maximize_Shell();
  }
}

void Xila_Class::Add_Software_Handle(Software_Handle_Class &Software_Handle_To_Add)
{
  for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
  {
    if (Software_Handle_Pointer[i] == NULL)
    {
      Software_Handle_Pointer[i] = &Software_Handle_To_Add;
      return;
    }
  }
}

// -- Shell shortcut -- //

void Xila_Class::Execute_Shell(Xila_Command const &Command)
{
  Open_Software_Pointer[1]->Execute(Command);
}

void Xila_Class::Maximize_Shell()
{
  Maximize_Software(Shell_Handle);
}