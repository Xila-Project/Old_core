#include "Xila.hpp"

Xila_Class::Software_Handle My_Software_Handle;

class My_Software : public Xila_Class::Software
{
private:
  static My_Software *Instance_Pointer;

  void My_Function()
  {
    Send_Instruction('M', 'y'); // -- Add instruction "My" to instruction queue.
  }

public:
  // -- Main task
  static void Main_Task(void *)
  {
    // -- Main task must never return, so an infinite loop is required
    while (1)
    {
      // -- Get instruction from instruction queue, then bind with a function / instruction.
      switch (Instance_Pointer->Get_Instruction())
      {
      case Instruction('M', 'y'): // -- Bind My_Function() with the instruciton "My" (0x4D79)
        Instance_Pointer->My_Function();
        break;
      default: // -- Don't forget default statement.
        break;
      }
      Xila.Task.Delay(20); // -- Don't forget to add delays between operations.
    }
  };

  // -- Pages enumeration

  enum Pages
  {
    Pages = 39
  };

  // -- Image enumeration
  enum Image
  {
    Icon_32 = 44
  };

  // -- Software constructor : execute once software instance is created.
  My_Software() : Xila_Class::Software(My_Software_Handle)
  {
    // -- Create main task
    Xila.Task.Create(Main_Task, "My Software Task", Memory_Chunk(4), NULL, &Task_Handle);
  };

  ~My_Software()
  {
    // -- Check if there is a duplicate
    if (Instance_Pointer != this)
    {
      // -- Delete the duplicate
      delete Instance_Pointer;
    }
    // -- Reset instance pointer
    Instance_Pointer = NULL;
  };

  static Xila_Class::Software *Load()
  {
    // -- Check if there is a duplicate
    if (Instance_Pointer != NULL)
    {
      // -- Delete the duplicate
      delete Instance_Pointer;
    }
    // -- Reset instance pointer
    Instance_Pointer = new My_Software();
    // -- Return instance pointer for Xila.
    return Instance_Pointer;
  };
};

Xila_Class::Software_Handle My_Software_Handle("My Software", My_Software::Icon_32, My_Software::Load);

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

  Xila_Class::Software_Handle *Custom_Software_Package[12] =
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
          Tiny_Basic_Handle};

  Xila.Start(Custom_Software_Package, 12);

  Xila.System.Start();
}

void loop()
{
  Xila.Task.Delete();
}
