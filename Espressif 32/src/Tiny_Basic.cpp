#include "Tiny_Basic.hpp"

#include <Arduino.h>

TinyBasic_Class *TinyBasic_Class::Instance_Pointer = NULL;
#define INSTANCE_POINTER TinyBasic_Class::Instance_Pointer

TinyBasic_Class::TinyBasic_Class() : Software_Class(8),
                                     inhibitOutput(false),
                                     runAfterLoad(false),
                                     triggerRun(false),
                                     eepos(0),
                                     inStream(kStreamSerial),
                                     outStream(kStreamSerial),
                                     sd_is_initialized(true)
{
  xTaskCreatePinnedToCore(TinyBasic_Task, "TinyBasic", 4 * 1024, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
}

TinyBasic_Class::~TinyBasic_Class()
{
  Instance_Pointer = NULL;
}

Software_Class *TinyBasic_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new TinyBasic_Class;
  }
  return Instance_Pointer;
}

void TinyBasic_Task(void *pvParameters)
{
  (void)pvParameters;
  INSTANCE_POINTER->printmsg(INSTANCE_POINTER->initmsg);
  Xila.Display.Draw_Fill(2, 20, 476, 250, COLOR_DARK_GREY);

  // Initialize SD Card
  if (!Xila.Drive->begin())
  {
    // failed
    INSTANCE_POINTER->printmsg(INSTANCE_POINTER->sderrormsg);
  }
  else
  {
    INSTANCE_POINTER->sd_is_initialized = true;
  }
  if (Xila.Drive->exists(AUTORUN_FILE))
  {
    INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;
    INSTANCE_POINTER->fp = Xila.Drive->open(AUTORUN_FILE);
    INSTANCE_POINTER->inStream = INSTANCE_POINTER->kStreamFile;
    INSTANCE_POINTER->inhibitOutput = true;
    INSTANCE_POINTER->runAfterLoad = true;
  }
  INSTANCE_POINTER->outStream = INSTANCE_POINTER->kStreamSerial;
  INSTANCE_POINTER->inStream = INSTANCE_POINTER->kStreamSerial;
  INSTANCE_POINTER->inhibitOutput = false;

  // Initalize EEPROM
  int val = EEPROM.read(0); // read the first byte of the eeprom. if it's a number, assume it's a program we can load
  if (val >= '0' && val <= '9')
  {
    INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;
    INSTANCE_POINTER->inStream = INSTANCE_POINTER->kStreamEEProm;
    INSTANCE_POINTER->eepos = 0;
    INSTANCE_POINTER->inhibitOutput = true;
    INSTANCE_POINTER->runAfterLoad = true;
  }

  char *start;
  char *newEnd;
  char linelen;
  boolean isDigital;
  boolean alsoWait = false;

  Xila.Sound.Mute();

  while (1)
  {
    switch (INSTANCE_POINTER->Get_Command())
    {
    case 0:

      break;
    case 0x4543: //"EC"

      // configure program space
      INSTANCE_POINTER->program_start = INSTANCE_POINTER->program;
      INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;
      INSTANCE_POINTER->sp = INSTANCE_POINTER->program + sizeof(INSTANCE_POINTER->program); // Needed for printnum
      INSTANCE_POINTER->stack_limit = INSTANCE_POINTER->program + sizeof(INSTANCE_POINTER->program) - STACK_SIZE;
      INSTANCE_POINTER->variables_begin = INSTANCE_POINTER->stack_limit - 27 * VAR_SIZE;
      // memory free
      INSTANCE_POINTER->printnum(INSTANCE_POINTER->variables_begin - INSTANCE_POINTER->program_end);
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->memorymsg);
      // eprom size
      INSTANCE_POINTER->printnum(EEPROM.length() + 1);
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->eeprommsg);

    warmstart:
      // this signifies that it is running in 'direct' mode.
      INSTANCE_POINTER->current_line = 0;
      INSTANCE_POINTER->sp = INSTANCE_POINTER->program + sizeof(INSTANCE_POINTER->program);
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->okmsg);

    prompt:
      if (INSTANCE_POINTER->triggerRun)
      {
        INSTANCE_POINTER->triggerRun = false;
        INSTANCE_POINTER->current_line = INSTANCE_POINTER->program_start;
        goto execline;
      }

      INSTANCE_POINTER->getln('>');
      INSTANCE_POINTER->toUppercaseBuffer();

      INSTANCE_POINTER->txtpos = INSTANCE_POINTER->program_end + sizeof(unsigned short);

      // Find the end of the freshly entered line
      while (*INSTANCE_POINTER->txtpos != NL)
        INSTANCE_POINTER->txtpos++;

      // Move it to the end of program_memory
      {
        char *dest;
        dest = INSTANCE_POINTER->variables_begin - 1;
        while (1)
        {
          *dest = *INSTANCE_POINTER->txtpos;
          if (INSTANCE_POINTER->txtpos == INSTANCE_POINTER->program_end + sizeof(unsigned short))
            break;
          dest--;
          INSTANCE_POINTER->txtpos--;
        }
        INSTANCE_POINTER->txtpos = dest;
      }

      // Now see if we have a line number
      INSTANCE_POINTER->linenum = INSTANCE_POINTER->testnum();
      INSTANCE_POINTER->ignore_blanks();
      if (INSTANCE_POINTER->linenum == 0)
        goto direct;

      if (INSTANCE_POINTER->linenum == 0xFFFF)
        goto qhow;

      // Find the length of what is left, including the (yet-to-be-populated) line header
      linelen = 0;
      while (INSTANCE_POINTER->txtpos[linelen] != NL)
        linelen++;
      linelen++;                                        // Include the NL in the line length
      linelen += sizeof(unsigned short) + sizeof(char); // Add space for the line number and line length

      // Now we have the number, add the line header.
      INSTANCE_POINTER->txtpos -= 3;
      *((unsigned short *)INSTANCE_POINTER->txtpos) = INSTANCE_POINTER->linenum;
      INSTANCE_POINTER->txtpos[sizeof(TinyBasic_Class::LINENUM)] = linelen;

      // Merge it into the rest of the program
      start = INSTANCE_POINTER->findline();

      // If a line with that number exists, then remove it
      if (start != INSTANCE_POINTER->program_end && *((TinyBasic_Class::LINENUM *)start) == INSTANCE_POINTER->linenum)
      {
        char *dest, *from;
        unsigned tomove;

        from = start + start[sizeof(TinyBasic_Class::LINENUM)];
        dest = start;

        tomove = INSTANCE_POINTER->program_end - from;
        while (tomove > 0)
        {
          *dest = *from;
          from++;
          dest++;
          tomove--;
        }
        INSTANCE_POINTER->program_end = dest;
      }

      // If the line has no txt, it was just a delete
      if (INSTANCE_POINTER->txtpos[sizeof(TinyBasic_Class::LINENUM) + sizeof(char)] == NL)
        goto prompt;

      // Make room for the new line, either all in one hit or lots of little shuffles
      while (linelen > 0)
      {
        unsigned int tomove;
        char *from, *dest;
        unsigned int space_to_make;

        space_to_make = INSTANCE_POINTER->txtpos - INSTANCE_POINTER->program_end;

        if (space_to_make > linelen)
          space_to_make = linelen;
        newEnd = INSTANCE_POINTER->program_end + space_to_make;
        tomove = INSTANCE_POINTER->program_end - start;

        // Source and destination - as these areas may overlap we need to move bottom up
        from = INSTANCE_POINTER->program_end;
        dest = newEnd;
        while (tomove > 0)
        {
          from--;
          dest--;
          *dest = *from;
          tomove--;
        }

        // Copy over the bytes into the new space
        for (tomove = 0; tomove < space_to_make; tomove++)
        {
          *start = *INSTANCE_POINTER->txtpos;
          INSTANCE_POINTER->txtpos++;
          start++;
          linelen--;
        }
        INSTANCE_POINTER->program_end = newEnd;
      }
      goto prompt;

    unimplemented:
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->unimplimentedmsg);
      goto prompt;

    qhow:
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->howmsg);
      goto prompt;

    qwhat:
      INSTANCE_POINTER->printmsgNoNL(INSTANCE_POINTER->whatmsg);
      if (INSTANCE_POINTER->current_line != NULL)
      {
        char tmp = *INSTANCE_POINTER->txtpos;
        if (*INSTANCE_POINTER->txtpos != NL)
          *INSTANCE_POINTER->txtpos = '^';
        INSTANCE_POINTER->list_line = INSTANCE_POINTER->current_line;
        INSTANCE_POINTER->printline();
        *INSTANCE_POINTER->txtpos = tmp;
      }
      INSTANCE_POINTER->line_terminator();
      goto prompt;

    qsorry:
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->sorrymsg);
      goto warmstart;

    run_next_statement:
      while (*INSTANCE_POINTER->txtpos == ':')
        INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos == NL)
      {
        goto execnextline;
      }
      goto interperateAtTxtpos;

    direct:
      INSTANCE_POINTER->txtpos = INSTANCE_POINTER->program_end + sizeof(TinyBasic_Class::LINENUM);
      if (*INSTANCE_POINTER->txtpos == NL)
        goto prompt;

    interperateAtTxtpos:
      if (INSTANCE_POINTER->breakcheck())
      {
        INSTANCE_POINTER->printmsg(INSTANCE_POINTER->breakmsg);
        goto warmstart;
      }

      INSTANCE_POINTER->scantable(INSTANCE_POINTER->keywords);

      switch (INSTANCE_POINTER->table_index)
      {
      case INSTANCE_POINTER->KW_DELAY:
      {
        INSTANCE_POINTER->expression_error = 0;
        val = INSTANCE_POINTER->expression();
        delay(val);
        goto execnextline;
      }
      case INSTANCE_POINTER->KW_FILES:
        goto files;
      case INSTANCE_POINTER->KW_LIST:
        goto list;
      case INSTANCE_POINTER->KW_CHAIN:
        goto chain;
      case INSTANCE_POINTER->KW_LOAD:
        goto load;
      case INSTANCE_POINTER->KW_MEM:
        goto mem;
      case INSTANCE_POINTER->KW_NEW:
        if (INSTANCE_POINTER->txtpos[0] != NL)
          goto qwhat;
        INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;
        goto prompt;
      case INSTANCE_POINTER->KW_RUN:
        INSTANCE_POINTER->current_line = INSTANCE_POINTER->program_start;
        goto execline;
      case INSTANCE_POINTER->KW_SAVE:
        goto save;
      case INSTANCE_POINTER->KW_DELETE:
        goto delfile;
      case INSTANCE_POINTER->KW_NEXT:
        goto next;
      case INSTANCE_POINTER->KW_LET:
        goto assignment;
      case INSTANCE_POINTER->KW_IF:
        short int val;
        INSTANCE_POINTER->expression_error = 0;
        val = INSTANCE_POINTER->expression();
        if (INSTANCE_POINTER->expression_error || *INSTANCE_POINTER->txtpos == NL)
          goto qhow;
        if (val != 0)
          goto interperateAtTxtpos;
        goto execnextline;

      case INSTANCE_POINTER->KW_GOTO:
        INSTANCE_POINTER->expression_error = 0;
        INSTANCE_POINTER->linenum = INSTANCE_POINTER->expression();
        if (INSTANCE_POINTER->expression_error || *INSTANCE_POINTER->txtpos != NL)
          goto qhow;
        INSTANCE_POINTER->current_line = INSTANCE_POINTER->findline();
        goto execline;
      case INSTANCE_POINTER->KW_GOSUB:
        goto gosub;
      case INSTANCE_POINTER->KW_RETURN:
        goto gosub_return;
      case INSTANCE_POINTER->KW_REM:
      case INSTANCE_POINTER->KW_QUOTE:
        goto execnextline; // Ignore line completely
      case INSTANCE_POINTER->KW_FOR:
        goto forloop;
      case INSTANCE_POINTER->KW_INPUT:
        goto input;
      case INSTANCE_POINTER->KW_PRINT:
      case INSTANCE_POINTER->KW_QMARK:
        goto print;
      case INSTANCE_POINTER->KW_POKE:
        goto poke;
      case INSTANCE_POINTER->KW_END:
      case INSTANCE_POINTER->KW_STOP:
        // This is the easy way to end - set the current line to the end of program attempt to run it
        if (INSTANCE_POINTER->txtpos[0] != NL)
          goto qwhat;
        INSTANCE_POINTER->current_line = INSTANCE_POINTER->program_end;
        goto execline;
      case INSTANCE_POINTER->KW_BYE:
        // Leave the basic interperater
        return;
      case INSTANCE_POINTER->KW_AWRITE: // AWRITE <pin>, HIGH|LOW
        isDigital = false;
        goto awrite;
      case INSTANCE_POINTER->KW_DWRITE: // DWRITE <pin>, HIGH|LOW
        isDigital = true;
        goto dwrite;
      case INSTANCE_POINTER->KW_RSEED:
        goto rseed;
      case INSTANCE_POINTER->KW_TONEW:
        alsoWait = true;
      case INSTANCE_POINTER->KW_TONE:
        goto tonegen;
      case INSTANCE_POINTER->KW_NOTONE:
        goto tonestop;
      case INSTANCE_POINTER->KW_EFORMAT:
        goto eformat;
      case INSTANCE_POINTER->KW_ESAVE:
        goto esave;
      case INSTANCE_POINTER->KW_ELOAD:
        goto eload;
      case INSTANCE_POINTER->KW_ELIST:
        goto elist;
      case INSTANCE_POINTER->KW_ECHAIN:
        goto echain;
        goto wifi;
      case INSTANCE_POINTER->KW_DEFAULT:
        goto assignment;
      default:
        break;
      }

    execnextline:
      if (INSTANCE_POINTER->current_line == NULL) // Processing direct commands?
        goto prompt;
      INSTANCE_POINTER->current_line += INSTANCE_POINTER->current_line[sizeof(TinyBasic_Class::LINENUM)];

    execline:
      if (INSTANCE_POINTER->current_line == INSTANCE_POINTER->program_end) // Out of lines to run
        goto warmstart;
      INSTANCE_POINTER->txtpos = INSTANCE_POINTER->current_line + sizeof(TinyBasic_Class::LINENUM) + sizeof(char);
      goto interperateAtTxtpos;
    elist:
    {
      int i;
      for (i = 0; i < (EEPROM.length() + 1); i++)
      {
        val = EEPROM.read(i);

        if (val == '\0')
        {
          goto execnextline;
        }

        if (((val < ' ') || (val > '~')) && (val != NL) && (val != CR))
        {
          INSTANCE_POINTER->outchar('?');
        }
        else
        {
          INSTANCE_POINTER->outchar(val);
        }
      }
    }
      goto execnextline;

    eformat:
    {
      for (int i = 0; i < EEPROM.length(); i++)
      {
        if ((i & 0x03f) == 0x20)
          INSTANCE_POINTER->outchar('.');
        EEPROM.write(i, 0);
      }
      INSTANCE_POINTER->outchar(LF);
    }
      goto execnextline;

    esave:
    {
      INSTANCE_POINTER->outStream = INSTANCE_POINTER->kStreamEEProm;
      INSTANCE_POINTER->eepos = 0;

      // copied from "List"
      INSTANCE_POINTER->list_line = INSTANCE_POINTER->findline();
      while (INSTANCE_POINTER->list_line != INSTANCE_POINTER->program_end)
      {
        INSTANCE_POINTER->printline();
      }
      INSTANCE_POINTER->outchar('\0');

      // go back to standard output, close the file
      INSTANCE_POINTER->outStream = INSTANCE_POINTER->kStreamSerial;

      goto warmstart;
    }

    echain:
      INSTANCE_POINTER->runAfterLoad = true;

    eload:
      // clear the program
      INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;

      // load from a file into memory
      INSTANCE_POINTER->eepos = 0;
      INSTANCE_POINTER->inStream = INSTANCE_POINTER->kStreamEEProm;
      INSTANCE_POINTER->inhibitOutput = true;
      goto warmstart;
    input:
    {
      char var;
      int value;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos < 'A' || *INSTANCE_POINTER->txtpos > 'Z')
        goto qwhat;
      var = *INSTANCE_POINTER->txtpos;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != NL && *INSTANCE_POINTER->txtpos != ':')
        goto qwhat;
    inputagain:
      INSTANCE_POINTER->tmptxtpos = INSTANCE_POINTER->txtpos;
      INSTANCE_POINTER->getln('?');
      INSTANCE_POINTER->toUppercaseBuffer();
      INSTANCE_POINTER->txtpos = INSTANCE_POINTER->program_end + sizeof(unsigned short);
      INSTANCE_POINTER->ignore_blanks();
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto inputagain;
      ((short int *)INSTANCE_POINTER->variables_begin)[var - 'A'] = value;
      INSTANCE_POINTER->txtpos = INSTANCE_POINTER->tmptxtpos;

      goto run_next_statement;
    }

    forloop:
    {
      char var;
      short int initial, step, terminal;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos < 'A' || *INSTANCE_POINTER->txtpos > 'Z')
        goto qwhat;
      var = *INSTANCE_POINTER->txtpos;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != '=')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();

      INSTANCE_POINTER->expression_error = 0;
      initial = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      INSTANCE_POINTER->scantable(INSTANCE_POINTER->to_tab);
      if (INSTANCE_POINTER->table_index != 0)
        goto qwhat;

      terminal = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      INSTANCE_POINTER->scantable(INSTANCE_POINTER->step_tab);
      if (INSTANCE_POINTER->table_index == 0)
      {
        step = INSTANCE_POINTER->expression();
        if (INSTANCE_POINTER->expression_error)
          goto qwhat;
      }
      else
        step = 1;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != NL && *INSTANCE_POINTER->txtpos != ':')
        goto qwhat;

      if (!INSTANCE_POINTER->expression_error && *INSTANCE_POINTER->txtpos == NL)
      {
        struct stack_for_frame *f;
        if (INSTANCE_POINTER->sp + sizeof(struct stack_for_frame) < INSTANCE_POINTER->stack_limit)
          goto qsorry;

        INSTANCE_POINTER->sp -= sizeof(struct stack_for_frame);
        f = (struct stack_for_frame *)INSTANCE_POINTER->sp;
        ((short int *)INSTANCE_POINTER->variables_begin)[var - 'A'] = initial;
        f->frame_type = STACK_FOR_FLAG;
        f->for_var = var;
        f->terminal = terminal;
        f->step = step;
        f->txtpos = INSTANCE_POINTER->txtpos;
        f->current_line = INSTANCE_POINTER->current_line;
        goto run_next_statement;
      }
    }
      goto qhow;

    gosub:
      INSTANCE_POINTER->expression_error = 0;
      INSTANCE_POINTER->linenum = INSTANCE_POINTER->expression();
      if (!INSTANCE_POINTER->expression_error && *INSTANCE_POINTER->txtpos == NL)
      {
        struct stack_gosub_frame *f;
        if (INSTANCE_POINTER->sp + sizeof(struct stack_gosub_frame) < INSTANCE_POINTER->stack_limit)
          goto qsorry;

        INSTANCE_POINTER->sp -= sizeof(struct stack_gosub_frame);
        f = (struct stack_gosub_frame *)INSTANCE_POINTER->sp;
        f->frame_type = STACK_GOSUB_FLAG;
        f->txtpos = INSTANCE_POINTER->txtpos;
        f->current_line = INSTANCE_POINTER->current_line;
        INSTANCE_POINTER->current_line = INSTANCE_POINTER->findline();
        goto execline;
      }
      goto qhow;

    next:
      // Fnd the variable name
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos < 'A' || *INSTANCE_POINTER->txtpos > 'Z')
        goto qhow;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != ':' && *INSTANCE_POINTER->txtpos != NL)
        goto qwhat;

    gosub_return:
      // Now walk up the stack frames and find the frame we want, if present
      INSTANCE_POINTER->tempsp = INSTANCE_POINTER->sp;
      while (INSTANCE_POINTER->tempsp < INSTANCE_POINTER->program + sizeof(INSTANCE_POINTER->program) - 1)
      {
        switch (INSTANCE_POINTER->tempsp[0])
        {
        case STACK_GOSUB_FLAG:
          if (INSTANCE_POINTER->table_index == INSTANCE_POINTER->KW_RETURN)
          {
            struct stack_gosub_frame *f = (struct stack_gosub_frame *)INSTANCE_POINTER->tempsp;
            INSTANCE_POINTER->current_line = f->current_line;
            INSTANCE_POINTER->txtpos = f->txtpos;
            INSTANCE_POINTER->sp += sizeof(struct stack_gosub_frame);
            goto run_next_statement;
          }
          // This is not the loop you are looking for... so Walk back up the stack
          INSTANCE_POINTER->tempsp += sizeof(struct stack_gosub_frame);
          break;
        case STACK_FOR_FLAG:
          // Flag, Var, Final, Step
          if (INSTANCE_POINTER->table_index == INSTANCE_POINTER->KW_NEXT)
          {
            struct stack_for_frame *f = (struct stack_for_frame *)INSTANCE_POINTER->tempsp;
            // Is the the variable we are looking for?
            if (INSTANCE_POINTER->txtpos[-1] == f->for_var)
            {
              short int *varaddr = ((short int *)INSTANCE_POINTER->variables_begin) + INSTANCE_POINTER->txtpos[-1] - 'A';
              *varaddr = *varaddr + f->step;
              // Use a different test depending on the sign of the step increment
              if ((f->step > 0 && *varaddr <= f->terminal) || (f->step < 0 && *varaddr >= f->terminal))
              {
                // We have to loop so don't pop the stack
                INSTANCE_POINTER->txtpos = f->txtpos;
                INSTANCE_POINTER->current_line = f->current_line;
                goto run_next_statement;
              }
              // We've run to the end of the loop. drop out of the loop, popping the stack
              INSTANCE_POINTER->sp = INSTANCE_POINTER->tempsp + sizeof(struct stack_for_frame);
              goto run_next_statement;
            }
          }
          // This is not the loop you are looking for... so Walk back up the stack
          INSTANCE_POINTER->tempsp += sizeof(struct stack_for_frame);
          break;
        default:
          //printf("Stack is stuffed!\n");
          goto warmstart;
        }
      }
      // Didn't find the variable we've been looking for
      goto qhow;

    assignment:
    {
      short int value;
      short int *var;

      if (*INSTANCE_POINTER->txtpos < 'A' || *INSTANCE_POINTER->txtpos > 'Z')
        goto qhow;
      var = (short int *)INSTANCE_POINTER->variables_begin + *INSTANCE_POINTER->txtpos - 'A';
      INSTANCE_POINTER->txtpos++;

      INSTANCE_POINTER->ignore_blanks();

      if (*INSTANCE_POINTER->txtpos != '=')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;
      // Check that we are at the end of the statement
      if (*INSTANCE_POINTER->txtpos != NL && *INSTANCE_POINTER->txtpos != ':')
        goto qwhat;
      *var = value;
    }
      goto run_next_statement;

    poke:
    {
      short int value;
      short int address;

      // Work out where to put it
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;
      address = value;

      // check for a comma
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != ',')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();

      // Now get the value to assign
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      // Check that we are at the end of the statement
      if (*INSTANCE_POINTER->txtpos != NL && *INSTANCE_POINTER->txtpos != ':')
        goto qwhat;

      //printf("Poke %i value %i\n",address, value);
      // validate target address is in program space
      if (address < 0 || address > PROG_RAM)
        goto qwhat;

      // destructive overwrite program address with provided value
      INSTANCE_POINTER->program[address] = (char)value;
    }
      goto run_next_statement;

    list:
      INSTANCE_POINTER->linenum = INSTANCE_POINTER->testnum(); // Retuns 0 if no line found.

      // Should be EOL
      if (INSTANCE_POINTER->txtpos[0] != NL)
        goto qwhat;

      // Find the line
      INSTANCE_POINTER->list_line = INSTANCE_POINTER->findline();
      while (INSTANCE_POINTER->list_line != INSTANCE_POINTER->program_end)
        INSTANCE_POINTER->printline();
      goto warmstart;

    print:
      // If we have an empty list then just put out a NL
      if (*INSTANCE_POINTER->txtpos == ':')
      {
        INSTANCE_POINTER->line_terminator();
        INSTANCE_POINTER->txtpos++;
        goto run_next_statement;
      }

      if (*INSTANCE_POINTER->txtpos == ';') // no terminator
      {
        INSTANCE_POINTER->txtpos++;
        goto run_next_statement;
      }

      if (*INSTANCE_POINTER->txtpos == NL)
      {
        goto execnextline;
      }

      while (1)
      {
        INSTANCE_POINTER->ignore_blanks();
        if (INSTANCE_POINTER->print_quoted_string())
        {
          ;
        }
        else if (*INSTANCE_POINTER->txtpos == '"' || *INSTANCE_POINTER->txtpos == '\'')
          goto qwhat;
        else
        {
          short int e;
          INSTANCE_POINTER->expression_error = 0;
          e = INSTANCE_POINTER->expression();
          if (INSTANCE_POINTER->expression_error)
            goto qwhat;
          INSTANCE_POINTER->printnum(e);
        }

        // At this point we have three options, a comma or a new line
        if (*INSTANCE_POINTER->txtpos == ',')
          INSTANCE_POINTER->txtpos++; // Skip the comma and move onto the next
        else if (INSTANCE_POINTER->txtpos[0] == ';' && (INSTANCE_POINTER->txtpos[1] == NL || INSTANCE_POINTER->txtpos[1] == ':'))
        {
          INSTANCE_POINTER->txtpos++; // This has to be the end of the print - no newline
          break;
        }
        else if (*INSTANCE_POINTER->txtpos == NL || *INSTANCE_POINTER->txtpos == ':')
        {
          INSTANCE_POINTER->line_terminator(); // The end of the print statement
          break;
        }
        else
          goto qwhat;
      }
      goto run_next_statement;

    mem:
      // memory free
      INSTANCE_POINTER->printnum(INSTANCE_POINTER->variables_begin - INSTANCE_POINTER->program_end);
      INSTANCE_POINTER->printmsg(INSTANCE_POINTER->memorymsg);

      {
        // eprom size
        INSTANCE_POINTER->printnum(EEPROM.length() + 1);
        INSTANCE_POINTER->printmsg(INSTANCE_POINTER->eeprommsg);

        // figure out the memory usage;
        val = ' ';
        int i;
        for (i = 0; (i < (EEPROM.length() + 1)) && (val != '\0'); i++)
        {
          val = EEPROM.read(i);
        }
        INSTANCE_POINTER->printnum((EEPROM.length() + 1) - (i - 1));

        INSTANCE_POINTER->printmsg(INSTANCE_POINTER->eepromamsg);
      }
      goto run_next_statement;

      /*************************************************/

    awrite: // AWRITE <pin>,val
    dwrite:
    {
      short int pinNo;
      short int value;
      char *txtposBak;

      // Get the pin number
      INSTANCE_POINTER->expression_error = 0;
      pinNo = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      // check for a comma
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != ',')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();

      txtposBak = INSTANCE_POINTER->txtpos;
      INSTANCE_POINTER->scantable(INSTANCE_POINTER->highlow_tab);
      if (INSTANCE_POINTER->table_index != HIGHLOW_UNKNOWN)
      {
        if (INSTANCE_POINTER->table_index <= HIGHLOW_HIGH)
        {
          value = 1;
        }
        else
        {
          value = 0;
        }
      }
      else
      {

        // and the value (numerical)
        INSTANCE_POINTER->expression_error = 0;
        value = INSTANCE_POINTER->expression();
        if (INSTANCE_POINTER->expression_error)
          goto qwhat;
      }
      pinMode(pinNo, OUTPUT);
      if (isDigital)
      {
        digitalWrite(pinNo, value);
      }
      else
      {
        // TODO: ESP32 DOES NOT SUPPORT
        //analogWrite( pinNo, value );
        goto unimplemented;
        // analogWrite( pinNo, value );
      }
    }
      goto run_next_statement;

    pinmode: // PINMODE <pin>, I/O
      goto unimplemented;

      /*************************************************/
    files:
      // display a listing of files on the device.
      // version 1: no support for subdirectories

      INSTANCE_POINTER->cmd_Files();
      goto warmstart;
      goto unimplemented;
    chain:
      INSTANCE_POINTER->runAfterLoad = true;

    load:
      // clear the program
      INSTANCE_POINTER->program_end = INSTANCE_POINTER->program_start;

      // load from a file into memory
      {
        char *filename;

        // Work out the filename
        INSTANCE_POINTER->expression_error = 0;
        filename = INSTANCE_POINTER->filenameWord();
        if (INSTANCE_POINTER->expression_error)
          goto qwhat;

        // check if file exists
        if (!Xila.Drive->exists((char *)filename))
        {
          // file is missing
          INSTANCE_POINTER->printmsg(INSTANCE_POINTER->sdfilemsg);
        }
        else
        {
          // file exists so open it
          INSTANCE_POINTER->fp = Xila.Drive->open((const char *)filename);
          INSTANCE_POINTER->inStream = INSTANCE_POINTER->kStreamFile;
          INSTANCE_POINTER->inhibitOutput = true;
        }
      }
      goto warmstart;
      goto unimplemented;
    save: // save from memory out to a file
    {
      char *filename;

      // Work out the filename
      INSTANCE_POINTER->expression_error = 0;
      filename = INSTANCE_POINTER->filenameWord();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      // saving filename...

      Serial.print("Saving: ");
      Serial.println((char *)filename);

      // remove the old file if it exists
      if (Xila.Drive->exists((char *)filename))
      {
        Xila.Drive->remove((char *)filename);
      }

      // open the file, switch over to file output
      INSTANCE_POINTER->fp = Xila.Drive->open((const char *)filename, FILE_WRITE);

      if (INSTANCE_POINTER->fp == (File)NULL)
      {
        Serial.println("Open Failed");
        goto qwhat;
      }
      else
      {
        INSTANCE_POINTER->outStream = INSTANCE_POINTER->kStreamFile;
      }

      // copied from "List"
      INSTANCE_POINTER->list_line = INSTANCE_POINTER->findline();
      while (INSTANCE_POINTER->list_line != INSTANCE_POINTER->program_end)
        INSTANCE_POINTER->printline();

      // go back to standard output, close the file
      INSTANCE_POINTER->outStream = INSTANCE_POINTER->kStreamSerial;

      INSTANCE_POINTER->fp.close();
      goto warmstart;
    }
      goto unimplemented;

    delfile:
      // delete a file
      {
        char *filename;

        // Work out the filename
        INSTANCE_POINTER->expression_error = 0;
        filename = INSTANCE_POINTER->filenameWord();
        if (INSTANCE_POINTER->expression_error)
          goto qwhat;

        // deleting filename
        Serial.print("Deleting: ");
        Serial.println((char *)filename);

        // remove the file if it exists
        if (Xila.Drive->exists((char *)filename))
        {
          Xila.Drive->remove((char *)filename);
        }
        goto warmstart;
      }
      goto unimplemented;

    rseed:
    {
      short int value;

      //Get the pin number
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      randomSeed(value);
      goto run_next_statement;
    }

    wifi:
    {
      short int value;

      char *ssid;
      char *pswd;

      // Get the SSID from an expression
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;
      ssid = (char *)value;

      // check for a comma
      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != ',')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();

      // Now get the password
      INSTANCE_POINTER->expression_error = 0;
      value = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;
      pswd = (char *)value;

      Serial.printf("Wifi ssid %s pswd %s\n", ssid, pswd);

      // Check that we are at the end of the statement
      if (*INSTANCE_POINTER->txtpos != NL && *INSTANCE_POINTER->txtpos != ':')
        goto qwhat;

      // all set with
      goto run_next_statement;
    }

      goto unimplemented;

    tonestop:
      Xila.Sound.Mute();
      goto run_next_statement;

    tonegen:
    {
      // TONE freq, duration
      // if either are 0, tones turned off
      short int freq;
      short int duration;

      //Get the frequency
      INSTANCE_POINTER->expression_error = 0;
      freq = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      INSTANCE_POINTER->ignore_blanks();
      if (*INSTANCE_POINTER->txtpos != ',')
        goto qwhat;
      INSTANCE_POINTER->txtpos++;
      INSTANCE_POINTER->ignore_blanks();

      //Get the duration
      INSTANCE_POINTER->expression_error = 0;
      duration = INSTANCE_POINTER->expression();
      if (INSTANCE_POINTER->expression_error)
        goto qwhat;

      if (freq == 0 || duration == 0)
        goto tonestop;

      Xila.Sound.Tone(freq, duration);
      if (alsoWait)
      {
        delay(duration);
        alsoWait = false;
      }
      goto run_next_statement;
    }

    break;
    default:
      break;
    }
  }
}

/***************************************************************************/
void TinyBasic_Class::ignore_blanks(void)
{
  while (*txtpos == SPACE || *txtpos == TAB)
    txtpos++;
}

/***************************************************************************/
void TinyBasic_Class::scantable(const char *table)
{
  int i = 0;
  table_index = 0;
  while (1)
  {
    // Run out of table entries?
    if (pgm_read_byte(table) == 0)
      return;

    // Do we match this character?
    if (txtpos[i] == pgm_read_byte(table))
    {
      i++;
      table++;
    }
    else
    {
      // do we match the last character of keywork (with 0x80 added)? If so, return
      if (txtpos[i] + 0x80 == pgm_read_byte(table))
      {
        txtpos += i + 1; // Advance the pointer to following the keyword
        ignore_blanks();
        return;
      }

      // Forward to the end of this keyword
      while ((pgm_read_byte(table) & 0x80) == 0)
        table++;

      // Now move on to the first character of the next word, and reset the position index
      table++;
      table_index++;
      ignore_blanks();
      i = 0;
    }
  }
}

/***************************************************************************/
void TinyBasic_Class::pushb(char b)
{
  sp--;
  *sp = b;
}

/***************************************************************************/
char TinyBasic_Class::popb()
{
  char b;
  b = *sp;
  sp++;
  return b;
}

/***************************************************************************/
void TinyBasic_Class::printnum(int num)
{
  int digits = 0;

  if (num < 0)
  {
    num = -num;
    outchar('-');
  }
  do
  {
    pushb(num % 10 + '0');
    num = num / 10;
    digits++;
  } while (num > 0);

  while (digits > 0)
  {
    outchar(popb());
    digits--;
  }
}

void TinyBasic_Class::printUnum(unsigned int num)
{
  int digits = 0;

  do
  {
    pushb(num % 10 + '0');
    num = num / 10;
    digits++;
  } while (num > 0);

  while (digits > 0)
  {
    outchar(popb());
    digits--;
  }
}

/***************************************************************************/
unsigned short TinyBasic_Class::testnum(void)
{
  unsigned short num = 0;
  ignore_blanks();

  while (*txtpos >= '0' && *txtpos <= '9')
  {
    // Trap overflows
    if (num >= 0xFFFF / 10)
    {
      num = 0xFFFF;
      break;
    }

    num = num * 10 + *txtpos - '0';
    txtpos++;
  }
  return num;
}

/***************************************************************************/
char TinyBasic_Class::print_quoted_string(void)
{
  int i = 0;
  char delim = *txtpos;
  if (delim != '"' && delim != '\'')
    return 0;
  txtpos++;

  // Check we have a closing delimiter
  while (txtpos[i] != delim)
  {
    if (txtpos[i] == NL)
      return 0;
    i++;
  }

  // Print the characters
  while (*txtpos != delim)
  {
    outchar(*txtpos);
    txtpos++;
  }
  txtpos++; // Skip over the last delimiter

  return 1;
}

/***************************************************************************/
void TinyBasic_Class::printmsgNoNL(const char *msg)
{
  while (pgm_read_byte(msg) != 0)
  {
    outchar(pgm_read_byte(msg++));
  };
}

/***************************************************************************/
void TinyBasic_Class::printmsg(const char *msg)
{
  printmsgNoNL(msg);
  line_terminator();
}

/***************************************************************************/
void TinyBasic_Class::getln(char prompt)
{
  outchar(prompt);
  txtpos = program_end + sizeof(LINENUM);

  while (1)
  {
    char c = inchar();
    switch (c)
    {
    case NL:
    //break;
    case CR:
      line_terminator();
      // Terminate all strings with a NL
      txtpos[0] = NL;
      return;
    case CTRLH:
      if (txtpos == program_end)
        break;
      txtpos--;

      printmsg(backspacemsg);
      break;
    default:
      // We need to leave at least one space to allow us to shuffle the line into order
      if (txtpos == variables_begin - 2)
        outchar(BELL);
      else
      {
        txtpos[0] = c;
        txtpos++;
        outchar(c);
      }
    }
  }
}

/***************************************************************************/
char *TinyBasic_Class::findline(void)
{
  char *line = program_start;
  while (1)
  {
    if (line == program_end)
      return line;

    if (((LINENUM *)line)[0] >= linenum)
      return line;

    // Add the line length onto the current address, to get to the next line;
    line += line[sizeof(LINENUM)];
  }
}

/***************************************************************************/
void TinyBasic_Class::toUppercaseBuffer(void)
{
  char *c = program_end + sizeof(LINENUM);
  char quote = 0;

  while (*c != NL)
  {
    // Are we in a quoted string?
    if (*c == quote)
      quote = 0;
    else if (*c == '"' || *c == '\'')
      quote = *c;
    else if (quote == 0 && *c >= 'a' && *c <= 'z')
      *c = *c + 'A' - 'a';
    c++;
  }
}

/***************************************************************************/
void TinyBasic_Class::printline()
{
  LINENUM line_num;

  line_num = *((LINENUM *)(list_line));
  list_line += sizeof(LINENUM) + sizeof(char);

  // Output the line */
  printnum(line_num);
  outchar(' ');
  while (*list_line != NL)
  {
    outchar(*list_line);
    list_line++;
  }
  list_line++;
  line_terminator();
}

/***************************************************************************/
short int TinyBasic_Class::expr4(void)
{
  // fix provided by Jurg Wullschleger wullschleger@gmail.com
  // fixes whitespace and unary operations
  ignore_blanks();

  if (*txtpos == '-')
  {
    txtpos++;
    return -expr4();
  }
  // end fix

  if (*txtpos == '0')
  {
    txtpos++;
    return 0;
  }

  if (*txtpos >= '1' && *txtpos <= '9')
  {
    short int a = 0;
    do
    {
      a = a * 10 + *txtpos - '0';
      txtpos++;
    } while (*txtpos >= '0' && *txtpos <= '9');
    return a;
  }

  // Is it a function or variable reference?
  if (txtpos[0] >= 'A' && txtpos[0] <= 'Z')
  {
    short int a;
    // Is it a variable reference (single alpha)
    if (txtpos[1] < 'A' || txtpos[1] > 'Z')
    {
      a = ((short int *)variables_begin)[*txtpos - 'A'];
      txtpos++;
      return a;
    }

    // Is it a function with a single parameter
    scantable(func_tab);
    if (table_index == FUNC_UNKNOWN)
      goto expr4_error;

    char f = table_index;

    if (*txtpos != '(')
      goto expr4_error;

    txtpos++;
    a = expression();
    if (*txtpos != ')')
      goto expr4_error;
    txtpos++;
    switch (f)
    {
    case FUNC_PEEK:
      return program[a];
    case FUNC_ABS:
      if (a < 0)
        return -a;
      return a;
    case FUNC_AREAD:
      pinMode(a, INPUT);
      return analogRead(a);
    case FUNC_DREAD:
      pinMode(a, INPUT);
      return digitalRead(a);
    case FUNC_RND:
      return (random(a));
    }
  }

  if (*txtpos == '(')
  {
    short int a;
    txtpos++;
    a = expression();
    if (*txtpos != ')')
      goto expr4_error;

    txtpos++;
    return a;
  }

expr4_error:
  expression_error = 1;
  return 0;
}

/***************************************************************************/
short int TinyBasic_Class::expr3(void)
{
  short int a, b;

  a = expr4();

  ignore_blanks(); // fix for eg:  100 a = a + 1

  while (1)
  {
    if (*txtpos == '*')
    {
      txtpos++;
      b = expr4();
      a *= b;
    }
    else if (*txtpos == '/')
    {
      txtpos++;
      b = expr4();
      if (b != 0)
        a /= b;
      else
        expression_error = 1;
    }
    else
      return a;
  }
}

/***************************************************************************/
short int TinyBasic_Class::expr2(void)
{
  short int a, b;

  if (*txtpos == '-' || *txtpos == '+')
    a = 0;
  else
    a = expr3();

  while (1)
  {
    if (*txtpos == '-')
    {
      txtpos++;
      b = expr3();
      a -= b;
    }
    else if (*txtpos == '+')
    {
      txtpos++;
      b = expr3();
      a += b;
    }
    else
      return a;
  }
}
/***************************************************************************/
short int TinyBasic_Class::expression(void)
{
  short int a, b;

  a = expr2();

  // Check if we have an error
  if (expression_error)
    return a;

  scantable(relop_tab);
  if (table_index == RELOP_UNKNOWN)
    return a;

  switch (table_index)
  {
  case RELOP_GE:
    b = expr2();
    if (a >= b)
      return 1;
    break;
  case RELOP_NE:
  case RELOP_NE_BANG:
    b = expr2();
    if (a != b)
      return 1;
    break;
  case RELOP_GT:
    b = expr2();
    if (a > b)
      return 1;
    break;
  case RELOP_EQ:
    b = expr2();
    if (a == b)
      return 1;
    break;
  case RELOP_LE:
    b = expr2();
    if (a <= b)
      return 1;
    break;
  case RELOP_LT:
    b = expr2();
    if (a < b)
      return 1;
    break;
  }
  return 0;
}

// returns 1 if the character is valid in a filename
int TinyBasic_Class::isValidFnChar(char c)
{
  if (c >= '0' && c <= '9')
    return 1; // number
  if (c >= 'A' && c <= 'Z')
    return 1; // LETTER
  if (c >= 'a' && c <= 'z')
    return 1; // letter (for completeness)
  if (c == '/')
    return 1;
  if (c == '_')
    return 1;
  if (c == '+')
    return 1;
  if (c == '.')
    return 1;
  if (c == '~')
    return 1; // Window~1.txt

  return 0;
}

//****************************************************************************************//

char *TinyBasic_Class::filenameWord()
{
  // SDL - I wasn't sure if this functionality existed above, so I figured i'd put it here
  char *ret = txtpos;
  expression_error = 0;

  // make sure there are no quotes or spaces, search for valid characters
  //while(*txtpos == SPACE || *txtpos == TAB || *txtpos == SQUOTE || *txtpos == DQUOTE ) txtpos++;
  while (!isValidFnChar(*txtpos))
    txtpos++;
  ret = txtpos;

  if (*ret == '\0')
  {
    expression_error = 1;
    return ret;
  }

  // now, find the next nonfnchar
  txtpos++;
  while (isValidFnChar(*txtpos))
    txtpos++;
  if (txtpos != ret)
    *txtpos = '\0';

  // set the error code if we've got no string
  if (*ret == '\0')
  {
    expression_error = 1;
  }

  return ret;
}

/***************************************************************************/
void TinyBasic_Class::line_terminator(void)
{
  outchar(NL);
  outchar(CR);
}

/***********************************************************/
char TinyBasic_Class::breakcheck(void)
{
  if (Serial.available() && Serial.read() == CTRLC)
  {
    return CTRLC;
  }
  return 0;
}
/***********************************************************/
int TinyBasic_Class::inchar()
{
  int v;

  switch (inStream)
  {
  case (kStreamFile):
    // File load
    v = fp.read();
    if (v == NL)
      v = CR; // file translate
    if (!fp.available())
    {
      fp.close();
      goto inchar_loadfinish;
    }
    return v;
    break;
  case (kStreamEEProm):
    // EEProm read
    v = EEPROM.read(eepos++);
    if (v == '\0')
    {
      goto inchar_loadfinish;
    }
    return v;
    //
    inStream = kStreamSerial;
    return NL;
    break;
  case (kStreamSerial):
  default:
    while (1)
    {
      if (Serial.available())
      {

        return Serial.read();
      }
    }
  }

inchar_loadfinish:
  inStream = kStreamSerial;
  INSTANCE_POINTER->inhibitOutput = false;

  if (runAfterLoad)
  {
    runAfterLoad = false;
    triggerRun = true;
  }
  return NL; // trigger a prompt.
}

/***********************************************************/
void TinyBasic_Class::outchar(char c)
{
  if (inhibitOutput)
  {
    return;
  }
  if (outStream == kStreamFile)
  {
    // output to a file
    fp.write(c);
  }
  else if (outStream == kStreamEEProm)
  {
    EEPROM.write(eepos++, c);
  }
  else
  {
    Serial.write(c);
  }
}

void TinyBasic_Class::cmd_Files(void)
{
  File dir = Xila.Drive->open("/");
  dir.seek(0);

  while (true)
  {
    File entry = dir.openNextFile();
    if (!entry)
    {
      entry.close();
      break;
    }

    // common header
    printmsgNoNL(indentmsg);
    printmsgNoNL((const char *)entry.name());
    if (entry.isDirectory())
    {
      printmsgNoNL(slashmsg);
    }

    if (entry.isDirectory())
    {
      // directory ending
      for (int i = strlen(entry.name()); i < 16; i++)
      {
        printmsgNoNL(spacemsg);
      }
      printmsgNoNL(dirextmsg);
    }
    else
    {
      // file ending
      for (int i = strlen(entry.name()); i < 17; i++)
      {
        printmsgNoNL(spacemsg);
      }
      printUnum(entry.size());
    }
    line_terminator();
    entry.close();
  }
  dir.close();
}

#undef INSTANCE_POINTER