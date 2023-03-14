*************
Dialog Module
*************

Here you will find a full descrption of the dialog module.

This module is responsible for everything related to the dialog boxes.
When a dialog box is called, the context is then saved, and restored as soon as the user has finished interacting with it.

.. notes::
    A dialog box stops the execution of the task that calls it during its display time.

API Reference
=============

.. doxygenclass:: Xila_Namespace::Dialog_Class
    :members:

Example
=======

.. code-block:: cpp

    if (Xila.Dialog.Login() == Xila.Success)    // -- Open a login dialog and check if the user has successfully logged in.
    {
        Xila.Dialog.Event("Successfully logged in !", Xila.Information);    // -- Open an informative event dialog.
    }
    else
    {
        Xila.Dialog.Event("Failed to log in !", Xila.Error);    // -- Open an error event dialog.
    }
    uint16_t Color;
    Xila.Dialog.Color_Picker(Color);    // -- Open a color picker dialog.
    File Test_File;
    Xila.Dialog.Open_File(Test_File);       // -- Open an open file dialog.
    Test_File.close();
    Xila.Dialog.Save(Test_File);            // -- Open a save file dialog.
    Test_File.close();
    File Test_Folder;
    Xila.Dialog.Open_Folder(Test_Folder);   // -- Open an open folder dialog.
    char Input_String[32];
    Xila.Dialog.Keyboard(Input_String, sizeof(Input_String), false);    // -- Open a non-masked keyboard dialog.
    float Input_Number;
    Xila.Dialog.Keypad(Input_Number);       // -- Open a keypad dialog.
    Xila.Dialog.Power();                    // -- Open a power dialog.
    Xila.Dialog.Load("Load stuff.", "Currently loading stuff"); // -- Open a load dialog.
    Xila.Task.Delay(5000);                  // -- Wait 5 seconds.
    Xila.Dialog.Close_Load();               // -- Close load dialog.

   
   