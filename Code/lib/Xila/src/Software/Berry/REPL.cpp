/// @file REPL.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 11-04-2023
///
/// @copyright Copyright (c) 2023

#include "Software/Berry/Berry.hpp"

extern "C"
{
#include "berry.h"
#include "be_repl.h"
#include "be_vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}
 
// - - REPL

int Berry_Class::REPL_Try_Return(const char *line)
{
    int res, idx;
    line = be_pushfstring(Virtual_Machine, "return (%s)", line);
    idx = be_absindex(Virtual_Machine, -1);                            /* get the source text absolute index */
    res = be_loadbuffer(Virtual_Machine, "stdin", line, strlen(line)); /* compile line */
    be_remove(Virtual_Machine, idx);                                   /* remove source string */
    return res;
}

bool Berry_Class::REPL_Is_Multiline()
{
    const char *msg = be_tostring(Virtual_Machine, -1);
    size_t len = strlen(msg);
    if (len > 5)
    { /* multi-line text if the error message is 'EOS' at the end */
        return !strcmp(msg + len - 5, "'EOS'");
    }
    return false;
}

int Berry_Class::REPL_Compile(char *line)
{
    int res = REPL_Try_Return(line);
    if (be_getexcept(Virtual_Machine, res) == BE_SYNTAX_ERROR)
    {
        be_pop(Virtual_Machine, 2); /* pop exception values */
        be_pushstring(Virtual_Machine, line);
        REPL_Free_Line(line);
        // safecall(REPL_Free_Line, line); /* free line buffer */
        for (;;)
        {
            const char *src = be_tostring(Virtual_Machine, -1); /* get source code */
            int idx = be_absindex(Virtual_Machine, -1);         /* get the source text absolute index */
            /* compile source line */
            res = be_loadbuffer(Virtual_Machine, "stdin", src, strlen(src));
            if (!res || !REPL_Is_Multiline())
            {
                be_remove(Virtual_Machine, idx); /* remove source code */
                return res;
            }
            be_pop(Virtual_Machine, 2);  /* pop exception values */
            line = REPL_Get_Line(">> "); /* read a new input line */
            be_pushfstring(Virtual_Machine, "\n%s", line);
            REPL_Free_Line(line);
            // safecall(REPL_Free_Line, line); /* free line buffer */
            be_strconcat(Virtual_Machine, -2);
            be_pop(Virtual_Machine, 1); /* pop new line */
        }
    }
    else
    {
        REPL_Free_Line(line);
        // safecall(REPL_Free_Line, line); /* free line buffer */
    }
    return res;
}

int Berry_Class::REPL_Call_Script()
{
    int res = be_pcall(Virtual_Machine, 0); /* call the main function */
    switch (res)
    {
    case BE_OK: /* execution succeed */
        if (!be_isnil(Virtual_Machine, -1))
        { /* print return value when it's not nil */
            be_dumpvalue(Virtual_Machine, -1);
        }
        be_pop(Virtual_Machine, 1); /* pop the result value */
        break;
    case BE_EXCEPTION: /* vm run error */
        be_dumpexcept(Virtual_Machine);
        be_pop(Virtual_Machine, 1); /* pop the function value */
        break;
    default: /* BE_EXIT or BE_MALLOC_FAIL */
        return res;
    }
    return 0;
}

int Berry_Class::REPL_Run()
{
    char *line;
    be_assert(getline != NULL);    
    while ((line = REPL_Get_Line("> ")) != NULL)
    {
        int res = REPL_Compile(line);
        if (res == BE_MALLOC_FAIL)
            return BE_MALLOC_FAIL;
        if (res)
        {
            be_dumpexcept(Virtual_Machine);
        }
        else
        { /* compiled successfully */
            res = REPL_Call_Script();
            if (res)
            {
                return res == BE_EXIT ? be_toindex(Virtual_Machine, -1) : res;
            }
        }
    }
    be_writenewline();
    return 0;
}

void Berry_Class::REPL()
{
    be_loadmodule(Virtual_Machine, "Test");

    // - Set interface

    Window.Set_Title("Berry");
    Window.Get_Body().Set_Flex_Flow(Graphics_Types::Flex_Flow_Type::Column);

    char Prompt_String_Local[(80 + 1) * 24 + 1];
    char Input_String[80 + 1];

    Prompt_String = Prompt_String_Local;
    this->Input_String = Input_String;

    memset(Prompt_String, 0, (80 + 1) * 24 + 1);
    memset(this->Input_String, 0, 80 + 1);

    Prompt_Container.Create(Window.Get_Body());
    Prompt_Container.Set_Width(Percentage(100));
    Prompt_Container.Set_Flex_Grow(1);
    Prompt_Container.Set_Style_Pad_All(0, 0);
    Prompt_Container.Clear_Flag(Graphics_Types::Flag_Type::Scroll_Elastic); // - Remove, very annoying.

    Prompt_Label.Create(Prompt_Container);
    Prompt_Label.Set_Width(Percentage(100));
    Prompt_Label.Set_Text_Static(Prompt_String_Local);

    Input_Text_Area.Create(Window.Get_Body());
    Input_Text_Area.Set_Size(Percentage(100), 40);
    Input_Text_Area.Add_Event(this, Graphics_Types::Event_Code_Type::Focused);
    Input_Text_Area.Add_Event(this, Graphics_Types::Event_Code_Type::Defocused);
    Input_Text_Area.Set_Placeholder_Text(">_");
    Input_Text_Area.Set_Maximum_Length(80);
    Input_Text_Area.Set_One_Line(true);

    Keyboard.Create(Window.Get_Body());
    Keyboard.Remove_Text_Area();
    Keyboard.Add_Event(this, Graphics_Types::Event_Code_Type::Ready);

    Byte_Type Error = REPL_Run();

    Prompt_Label.Delete();
    Input_Text_Area.Delete();

    Prompt_String = NULL;
    this->Input_String = NULL;

    // Add error handling here
}

void Berry_Class::REPL_Free_Line(char *Line)
{
    Line[0] = 0;
    // free(Line);
}

char *Berry_Class::REPL_Get_Line(const char *Prompt)
{
    static Instruction_Type Instruction;

    strlcat(Prompt_String, Prompt, (80 + 1) * 24 + 1);

    // TODO : Add scrolling to the bottom when typing.

    Prompt_Label.Set_Text_Static(Prompt_String);

    while (Input_String[0] == 0)
    {
        if (Instruction_Available())
        {
            Instruction = Get_Instruction();
            Execute_Instruction(Instruction);
        }

        Main_Task.Delay(60);
    }

    strlcat(Prompt_String, Input_String, (80 + 1) * 24 + 1);
    strlcat(Prompt_String, "\n", (80 + 1) * 24 + 1);
    
    Prompt_Label.Set_Text_Static(Prompt_String);

    return Input_String;
}