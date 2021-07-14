#include "Xila.hpp"

void setup()
{
  extern Xila_Class::Software_Handle Calculator_Handle;
  extern Xila_Class::Software_Handle Clock_Handle;
  extern Xila_Class::Software_Handle Internet_Browser_Handle;
  extern Xila_Class::Software_Handle Music_Player_Handle;
  extern Xila_Class::Software_Handle Oscilloscope_Handle;
  extern Xila_Class::Software_Handle Paint_Handle;
  extern Xila_Class::Software_Handle Periodic_Handle;
  extern Xila_Class::Software_Handle Piano_Handle;
  extern Xila_Class::Software_Handle Pong_Handle;
  extern Xila_Class::Software_Handle Simon_Handle;
  extern Xila_Class::Software_Handle Text_Editor_Handle;
  extern Xila_Class::Software_Handle Tiny_Basic_Handle;

  Xila_Class::Software_Handle* Custom_Software_Package[12] =
  {
    Calculator_Handle,
    Clock_Handle,
    Internet_Browser_Handle,
    Music_Player_Handle,
    Oscilloscope_Handle,
    Paint_Handle,
    Periodic_Handle,
    Piano_Handle,
    Pong_Handle,
    Simon_Handle,
    Text_Editor_Handle,
    Tiny_Basic_Handle
  };

  Xila.Start(Custom_Software_Package, 12);

  Xila.System.Start();
}

void loop()
{
  Xila.Task.Delete();
}
