#include "Software/Tiny_Basic.hpp"

#include <Arduino.h>

Tiny_Basic_Class *Tiny_Basic_Class::Instance_Pointer = NULL;
#define INSTANCE_POINTER Tiny_Basic_Class::Instance_Pointer

Tiny_Basic_Class::Tiny_Basic_Class() : Software_Class(8),
                                       inhibitOutput(false),
                                       runAfterLoad(false),
                                       triggerRun(false),
                                       inStream(kStreamXila),
                                       outStream(kStreamXila),
                                       eepos(0),
                                       sd_is_initialized(true)
{
  memset(Lines, '\0', sizeof(Lines));
  Xila.Task_Create(Main_Task, "TinyBasic", Memory_Chunk(4), NULL, &Task_Handle);
}

Tiny_Basic_Class::~Tiny_Basic_Class()
{
  Instance_Pointer = NULL;
}

Software_Class *Tiny_Basic_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Tiny_Basic_Class;
  }
  return Instance_Pointer;
}

void Tiny_Basic_Class::Main_Task(void *pvParameters)
{
  (void)pvParameters;
  Instance_Pointer->Setup();
  while (1)
  {
    Instance_Pointer->Loop();
  }
}

void Tiny_Basic_Class::Read_Command()
{
  switch (Instance_Pointer->Get_Command())
  {
  case Xila.Open:
    break;
  case Xila.Minimize:
    Xila.Task_Suspend();
    break;
  case Xila.Maximize:
    Xila.Display.Set_Current_Page(F("Tiny_Basic"));
    break;
  case Xila.Close:
    delete Instance_Pointer;
    Xila.Task_Delete(NULL);
    break;
  case Instruction('K', 'I'):
    Xila.Keyboard_Dialog(Temporary_Input, sizeof(Temporary_Input));
    Refresh_Interface();
    break;
  default:
    break;
  }
}

void Tiny_Basic_Class::Clear()
{
  Xila.Display.Click(F("SCROLL_HOT"), 1);
  Current_Line = 1;
  memset(Lines[1], '\0', (14 * sizeof(Lines[1])));
}

void Tiny_Basic_Class::Refresh_Interface()
{
  Xila.Display.Set_Text(F("LINE1_TXT"), Lines[1]);
  Xila.Display.Set_Text(F("LINE2_TXT"), Lines[2]);
  Xila.Display.Set_Text(F("LINE3_TXT"), Lines[3]);
  Xila.Display.Set_Text(F("LINE4_TXT"), Lines[4]);
  Xila.Display.Set_Text(F("LINE5_TXT"), Lines[5]);
  Xila.Display.Set_Text(F("LINE6_TXT"), Lines[6]);
  Xila.Display.Set_Text(F("LINE7_TXT"), Lines[7]);
  Xila.Display.Set_Text(F("LINE8_TXT"), Lines[8]);
  Xila.Display.Set_Text(F("LINE9_TXT"), Lines[9]);
  Xila.Display.Set_Text(F("LINE10_TXT"), Lines[10]);
  Xila.Display.Set_Text(F("LINE11_TXT"), Lines[11]);
  Xila.Display.Set_Text(F("LINE12_TXT"), Lines[12]);
  Xila.Display.Set_Text(F("LINE13_TXT"), Lines[13]);
  Xila.Display.Set_Text(F("LINE14_TXT"), Lines[14]);
  Xila.Display.Set_Text(F("INPUT_TXT"), Temporary_Input);
}

void Tiny_Basic_Class::Scroll()
{
  memcpy(Lines[1], Lines[2], sizeof(Lines[1]));
  memcpy(Lines[2], Lines[3], sizeof(Lines[2]));
  memcpy(Lines[3], Lines[4], sizeof(Lines[3]));
  memcpy(Lines[4], Lines[5], sizeof(Lines[4]));
  memcpy(Lines[5], Lines[6], sizeof(Lines[5]));
  memcpy(Lines[6], Lines[7], sizeof(Lines[6]));
  memcpy(Lines[7], Lines[8], sizeof(Lines[7]));
  memcpy(Lines[8], Lines[9], sizeof(Lines[8]));
  memcpy(Lines[9], Lines[10], sizeof(Lines[9]));
  memcpy(Lines[10], Lines[11], sizeof(Lines[10]));
  memcpy(Lines[11], Lines[12], sizeof(Lines[11]));
  memcpy(Lines[12], Lines[13], sizeof(Lines[12]));
  memcpy(Lines[13], Lines[14], sizeof(Lines[13]));
  Xila.Display.Click(F("SCROLL_HOT"), 0); // scroll
}

//////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Rectangle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Heigh, uint16_t const &Widht, uint16_t const &Color, uint16_t const &Fill_Color)
{
  if (Fill_Color != 3)
  {
    Xila.Display.Draw_Rectangle(X_Coordinate, Y_Coordinate, Widht, Heigh, Fill_Color);
  }
  Xila.Display.Draw_Rectangle(X_Coordinate, Y_Coordinate, Widht, Heigh, Color, true);
}

////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Line(uint16_t const &X_Start, uint16_t const &Y_Start, uint16_t const &X_End, uint16_t const &Y_End, uint16_t const &Color)
{
  Xila.Display.Draw_Line(X_Start, X_End, Y_Start, Y_End, Color);
}

///////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Row(uint16_t const &X_Start, uint16_t const &Y_Coordinate, uint16_t const &X_End, uint16_t const &Color)
{
  Xila.Display.Draw_Line(X_Start, Y_Coordinate, X_End, Y_Coordinate, Color);
}

///////////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Column(uint16_t const &X_Coordinate, uint16_t const &Y_Start, uint16_t const &Y_End, uint16_t const &Color)
{
  Xila.Display.Draw_Line(X_Coordinate, Y_Start, X_Coordinate, Y_End, Color);
}

////////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Pixel(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const &Color)
{
  Xila.Display.Draw_Pixel(X_Coordinate, Y_Coordinate, Color);
}

//////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Circle(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, uint16_t const Radius, uint16_t const &Color, uint16_t const &Fill_Color)
{
  if (Fill_Color != 3)
  {
    Xila.Display.Draw_Circle(X_Coordinate, Y_Coordinate, Radius, Fill_Color, false);
  }
  Xila.Display.Draw_Circle(X_Coordinate, Y_Coordinate, Radius, Color, true);
}

////////////////////////////////////////////////////////////////////////////////////////

void Tiny_Basic_Class::Draw_Char(uint16_t const &X_Coordinate, uint16_t const &Y_Coordinate, char const *Char)
{
  Xila.Display.Draw_Text(X_Coordinate, Y_Coordinate, 16, 8, Xila.Main_16, Xila.White, Xila.Dark_Grey, 1, 1, 0, Char);
}

/***************************************************************************/
void Tiny_Basic_Class::ignore_blanks()
{
  while (*txtpos == SPACE || *txtpos == TAB)
    txtpos++;
}

/***************************************************************************/
void Tiny_Basic_Class::scantable(const unsigned char *table)
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
void Tiny_Basic_Class::pushb(unsigned char b)
{
  sp--;
  *sp = b;
}

/***************************************************************************/
unsigned char Tiny_Basic_Class::popb()
{
  unsigned char b;
  b = *sp;
  sp++;
  return b;
}

/***************************************************************************/
void Tiny_Basic_Class::printnum(int num)
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

////////////////////////////////////////////////////////////

void Tiny_Basic_Class::printUnum(unsigned int num)
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
unsigned short Tiny_Basic_Class::testnum()
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
unsigned char Tiny_Basic_Class::print_quoted_string()
{
  int i = 0;
  unsigned char delim = *txtpos;
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
void Tiny_Basic_Class::printmsgNoNL(const unsigned char *msg)
{
  while (pgm_read_byte(msg) != 0)
  {
    outchar(pgm_read_byte(msg++));
  };
}

/***************************************************************************/
void Tiny_Basic_Class::printmsg(const unsigned char *msg)
{
  printmsgNoNL(msg);
  line_terminator();
}

/***************************************************************************/
void Tiny_Basic_Class::getln(char prompt)
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
unsigned char *Tiny_Basic_Class::findline()
{
  unsigned char *line = program_start;
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
void Tiny_Basic_Class::toUppercaseBuffer()
{
  unsigned char *c = program_end + sizeof(LINENUM);
  unsigned char quote = 0;

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
void Tiny_Basic_Class::printline()
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
short int Tiny_Basic_Class::expr4()
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

    unsigned char f = table_index;

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
short int Tiny_Basic_Class::expr3()
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
short int Tiny_Basic_Class::expr2()
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
short int Tiny_Basic_Class::expression()
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

/***************************************************************************/

// returns 1 if the character is valid in a filename
int Tiny_Basic_Class::isValidFnChar(char c)
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

/*****************************************************************/
unsigned char *Tiny_Basic_Class::filenameWord()
{
  // SDL - I wasn't sure if this functionality existed above, so I figured i'd put it here
  unsigned char *ret = txtpos;
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
void Tiny_Basic_Class::line_terminator()
{
  Read_Command();
  if (outStream == kStreamXila)
  {
    if (Current_Line < 14)
    {
      switch (Current_Line) //faster than modulo
      {
      case 1:
        Xila.Display.Set_Text(F("LINE1_TXT"), Lines[1]);
        break;
      case 2:
        Xila.Display.Set_Text(F("LINE2_TXT"), Lines[2]);
        break;
      case 3:
        Xila.Display.Set_Text(F("LINE3_TXT"), Lines[3]);
        break;
      case 4:
        Xila.Display.Set_Text(F("LINE4_TXT"), Lines[4]);
        break;
      case 5:
        Xila.Display.Set_Text(F("LINE5_TXT"), Lines[5]);
        break;
      case 6:
        Xila.Display.Set_Text(F("LINE6_TXT"), Lines[6]);
        break;
      case 7:
        Xila.Display.Set_Text(F("LINE7_TXT"), Lines[7]);
        break;
      case 8:
        Xila.Display.Set_Text(F("LINE8_TXT"), Lines[8]);
        break;
      case 9:
        Xila.Display.Set_Text(F("LINE9_TXT"), Lines[9]);
        break;
      case 10:
        Xila.Display.Set_Text(F("LINE10_TXT"), Lines[10]);
        break;
      case 11:
        Xila.Display.Set_Text(F("LINE11_TXT"), Lines[11]);
        break;
      case 12:
        Xila.Display.Set_Text(F("LINE12_TXT"), Lines[12]);
        break;
      case 13:
        Xila.Display.Set_Text(F("LINE13_TXT"), Lines[13]);
        break;
      }
      Current_Line++;
    }
    else
    {
      Current_Line = 14;
      Scroll();
    }

    Current_Column = 0;
    memset(Lines[Current_Line], '\0', sizeof(Lines[0]));
  }
  else
  {
    outchar(NL);
    outchar(CR);
  }
}

/***********************************************************/

void Tiny_Basic_Class::Setup()
{
  Xila.Display.Set_Current_Page(F("Tiny_Basic"));

  /*Serial.begin(CONSOLE_BAUD); // opens serial port
  Serial.println();*/

  printmsg(initmsg);

  initSD();

  if (Xila.Drive->exists(AUTORUN_FILE))
  {
    program_end = program_start;
    fp = Xila.Drive->open(AUTORUN_FILE);
    inStream = kStreamFile;
    inhibitOutput = true;
    runAfterLoad = true;
  }

  // read the first byte of the eeprom. if it's a number, assume it's a program we can load
  int val = EEPROM.read(0);
  if (val >= '0' && val <= '9')
  {
    program_end = program_start;
    inStream = kStreamEEProm;
    eepos = 0;
    inhibitOutput = true;
    runAfterLoad = true;
  }
}

/***********************************************************/
unsigned char Tiny_Basic_Class::breakcheck()
{
  if (inStream == kStreamXila)
  {
    if (Xila.Keyboard.available())
    {
      if (Xila.Keyboard.read() == PS2_ESC)
      {
        return 1;
      }
    }
  }
  else
  {
    if (Serial.available())
      return Serial.read() == CTRLC;
  }
  return 0;
}
/***********************************************************/
int Tiny_Basic_Class::inchar()
{
  int v;

  switch (inStream)
  {
  case (kStreamFile): // file io
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
  case (kStreamEEProm): //eeprom
    v = EEPROM.read(eepos++);
    if (v == '\0')
    {
      goto inchar_loadfinish;
    }
    return v;
    break;
  case (kStreamSerial): // serial
    while (1)
    {
      if (Serial.available())
        return Serial.read();
    }
    break;
  case (kStreamXila): // Xila (keyboard and display)
    while (1)
    {
      Read_Command();

      if (Xila.Keyboard.available())
      {
        Temporary_Char = Xila.Keyboard.read();
        if (Temporary_Char == PS2_ENTER)
        {
          Xila.Display.Click(F("ENTER_BUT"), 0);
        }
        else if (Temporary_Char == PS2_BACKSPACE)
        {
          Xila.Display.Delete_Text(F("INPUT_TXT"), 1);
        }
        else
        {
          Xila.Display.Add_Text(F("INPUT_VAR"), &Temporary_Char);
        }
      }

      if (Temporary_Input[Current_Position] != '\0')
      {
        return Temporary_Input[Current_Position++];
      }
    }
    break;
  default:
    break;
  }

inchar_loadfinish:
  inStream = kStreamXila;
  //inStream = kStreamSerial;
  inhibitOutput = false;

  if (runAfterLoad)
  {
    runAfterLoad = false;
    triggerRun = true;
  }
  return NL; // trigger a prompt.
}

/***********************************************************/
void Tiny_Basic_Class::outchar(unsigned char c)
{
  if (inhibitOutput)
  {
    return;
  }

  switch (outStream)
  {
  case kStreamFile:
    fp.write(c);
    break;
  case kStreamEEProm:
    EEPROM.write(eepos++, c);
    break;
  case kStreamSerial:
    Serial.write(c);
    break;
  case kStreamXila:
    if (Current_Column >= 68)
    {
      line_terminator();
    }
    Lines[Current_Line][Current_Column] = c;
    Current_Column++;
    break;
  default:
    break;
  }
}

/***********************************************************/
/* SD Card helpers */

boolean Tiny_Basic_Class::initSD()
{
  // TODO:  Clean this up - provide option with more detailed diagnostics
  // if the card is already initialized, we just go with it.
  // there is no support (yet?) for hot-swap of SD Cards. if you need to
  // swap, pop the card, reset the arduino.)

  /*
  if ( sd_is_initialized == true ) return true;

  // due to the way the SD Library works, pin 10 always needs to be
  // an output, even when your shield uses another line for CS
  //pinMode(10, OUTPUT); // change this to 53 on a mega

  if ( !SD.begin( SD_CS )) {
    // failed
    printmsg( sderrormsg );
    return false;
  }
  // success - quietly return 0
  sd_is_initialized = true;

  // and our file redirection flags
  outStream = kStreamSerial;
  inStream = kStreamSerial;
  inhibitOutput = false;

  return false;
  */

  outStream = kStreamXila;
  inStream = kStreamXila;
  inhibitOutput = false;

  sd_is_initialized = true;

  return true; // already handle by Xila
}

/**************************************************************************/

void Tiny_Basic_Class::cmd_Files()
{
  File dir = SD.open("/");
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
    printmsgNoNL((const unsigned char *)entry.name());
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

/*****************************************************************/

void Tiny_Basic_Class::Loop()
{
  unsigned char *start;
  unsigned char *newEnd;
  unsigned char linelen;
  boolean isDigital;
  boolean alsoWait = false;
  int val;

  Xila.Sound.No_Tone(kPiezoPin);

  // configure program space
  program_start = program;
  program_end = program_start;
  sp = program + sizeof(program); // Needed for printnum
  stack_limit = program + sizeof(program) - STACK_SIZE;
  variables_begin = stack_limit - 27 * VAR_SIZE;

  // memory free
  printnum(variables_begin - program_end);
  printmsg(memorymsg);

  // eprom size
  printnum(E2END + 1);
  printmsg(eeprommsg);

warmstart:
  // this signifies that it is running in 'direct' mode.
  current_line = 0;
  sp = program + sizeof(program);
  printmsg(okmsg);

prompt:
  if (triggerRun)
  {
    triggerRun = false;
    current_line = program_start;
    goto execline;
  }

  getln('>');
  toUppercaseBuffer();

  txtpos = program_end + sizeof(unsigned short);

  // Find the end of the freshly entered line
  while (*txtpos != NL)
    txtpos++;

  // Move it to the end of program_memory
  {
    unsigned char *dest;
    dest = variables_begin - 1;
    while (1)
    {
      *dest = *txtpos;
      if (txtpos == program_end + sizeof(unsigned short))
        break;
      dest--;
      txtpos--;
    }
    txtpos = dest;
  }

  // Now see if we have a line number
  linenum = testnum();
  ignore_blanks();
  if (linenum == 0)
    goto direct;

  if (linenum == 0xFFFF)
    goto qhow;

  // Find the length of what is left, including the (yet-to-be-populated) line header
  linelen = 0;
  while (txtpos[linelen] != NL)
    linelen++;
  linelen++;                                        // Include the NL in the line length
  linelen += sizeof(unsigned short) + sizeof(char); // Add space for the line number and line length

  // Now we have the number, add the line header.
  txtpos -= 3;
  *((unsigned short *)txtpos) = linenum;
  txtpos[sizeof(LINENUM)] = linelen;

  // Merge it into the rest of the program
  start = findline();

  // If a line with that number exists, then remove it
  if (start != program_end && *((LINENUM *)start) == linenum)
  {
    unsigned char *dest, *from;
    unsigned tomove;

    from = start + start[sizeof(LINENUM)];
    dest = start;

    tomove = program_end - from;
    while (tomove > 0)
    {
      *dest = *from;
      from++;
      dest++;
      tomove--;
    }
    program_end = dest;
  }

  // If the line has no txt, it was just a delete
  if (txtpos[sizeof(LINENUM) + sizeof(char)] == NL)
    goto prompt;

  // Make room for the new line, either all in one hit or lots of little shuffles
  while (linelen > 0)
  {
    unsigned int tomove;
    unsigned char *from, *dest;
    unsigned int space_to_make;

    space_to_make = txtpos - program_end;

    if (space_to_make > linelen)
      space_to_make = linelen;
    newEnd = program_end + space_to_make;
    tomove = program_end - start;

    // Source and destination - as these areas may overlap we need to move bottom up
    from = program_end;
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
      *start = *txtpos;
      txtpos++;
      start++;
      linelen--;
    }
    program_end = newEnd;
  }
  goto prompt;

unimplemented:
  printmsg(unimplimentedmsg);
  goto prompt;

qhow:
  printmsg(howmsg);
  goto prompt;

qwhat:
  printmsgNoNL(whatmsg);
  if (current_line != NULL)
  {
    unsigned char tmp = *txtpos;
    if (*txtpos != NL)
      *txtpos = '^';
    list_line = current_line;
    printline();
    *txtpos = tmp;
  }
  line_terminator();
  goto prompt;

qsorry:
  printmsg(sorrymsg);
  goto warmstart;

run_next_statement:
  while (*txtpos == ':')
    txtpos++;
  ignore_blanks();
  if (*txtpos == NL)
    goto execnextline;
  goto interperateAtTxtpos;

direct:
  txtpos = program_end + sizeof(LINENUM);
  if (*txtpos == NL)
    goto prompt;

interperateAtTxtpos:
  if (breakcheck())
  {
    printmsg(breakmsg);
    goto warmstart;
  }

  scantable(keywords);

  switch (table_index)
  {
  case KW_DELAY:
  {
    expression_error = 0;
    val = expression();
    Xila.Delay(val);
    goto execnextline;
  }
  case KW_FILES:
    goto files;
  case KW_LIST:
    goto list;
  case KW_CHAIN:
    goto chain;
  case KW_SERCOM:
    /*if (serial1On)
    {
      serial1On = false;
    }
    else
    {
      serial1On = true;
    }*/
    goto prompt;
  case KW_CLEAR:
    Clear();
    goto run_next_statement;
  case KW_NLIST:
    goto nlist;
  case KW_DRAWPIX:
    goto drawpix;
  case KW_DRAWLINE:
    goto drawline;
  case KW_DRAWROW:
    goto drawrow;
  case KW_DRAWCOL:
    goto drawcol;
  case KW_DRAWRECT:
    goto drawrect;
  case KW_DRAWCIRC:
    goto drawcirc;
  case KW_DRAWCHAR:
    goto drawchar;
  case KW_GETPIX:
    goto getpix;

  case KW_LOAD:
    goto load;
  case KW_MEM:
    goto mem;
  case KW_NEW:
    if (txtpos[0] != NL)
      goto qwhat;
    program_end = program_start;
    goto prompt;
  case KW_RUN:
    current_line = program_start;
    goto execline;
  case KW_SAVE:
    goto save;
  case KW_DELETE:
    goto delfile;
  case KW_NEXT:
    goto next;
  case KW_LET:
    goto assignment;
  case KW_IF:
    short int val;
    expression_error = 0;
    val = expression();
    if (expression_error || *txtpos == NL)
      goto qhow;
    if (val != 0)
      goto interperateAtTxtpos;
    goto execnextline;

  case KW_GOTO:
    expression_error = 0;
    linenum = expression();
    if (expression_error || *txtpos != NL)
      goto qhow;
    current_line = findline();
    goto execline;

  case KW_GOSUB:
    goto gosub;
  case KW_RETURN:
    goto gosub_return;
  case KW_REM:
  case KW_QUOTE:
    goto execnextline; // Ignore line completely
  case KW_FOR:
    goto forloop;
  case KW_INPUT:
    goto input;
  case KW_PRINT:
  case KW_QMARK:
    goto print;
  case KW_POKE:
    goto poke;
  case KW_END:
  case KW_STOP:
    // This is the easy way to end - set the current line to the end of program attempt to run it
    if (txtpos[0] != NL)
      goto qwhat;
    current_line = program_end;
    goto execline;
  case KW_BYE:
    // Leave the basic interperater
    return;

  case KW_AWRITE: // AWRITE <pin>, HIGH|LOW
    isDigital = false;
    goto awrite;
  case KW_DWRITE: // DWRITE <pin>, HIGH|LOW
    isDigital = true;
    goto dwrite;

  case KW_RSEED:
    goto rseed;

  case KW_TONEW:
    alsoWait = true;
  case KW_TONE:
    goto tonegen;
  case KW_NOTONE:
    goto tonestop;
  case KW_EFORMAT:
    goto eformat;
  case KW_ESAVE:
    goto esave;
  case KW_ELOAD:
    goto eload;
  case KW_ELIST:
    goto elist;
  case KW_ECHAIN:
    goto echain;
  case KW_WIFI:
    goto wifi;
  case KW_DEFAULT:
    goto assignment;
  default:
    break;
  }

execnextline:
  if (current_line == NULL) // Processing direct commands?
    goto prompt;
  current_line += current_line[sizeof(LINENUM)];

execline:
  if (current_line == program_end) // Out of lines to run
    goto warmstart;
  txtpos = current_line + sizeof(LINENUM) + sizeof(char);
  goto interperateAtTxtpos;

elist:
{
  int i;
  for (i = 0; i < (E2END + 1); i++)
  {
    val = EEPROM.read(i);

    if (val == '\0')
    {
      goto execnextline;
    }

    if (((val < ' ') || (val > '~')) && (val != NL) && (val != CR))
    {
      outchar('?');
    }
    else
    {
      outchar(val);
    }
  }
}
  goto execnextline;

eformat:
{
  for (int i = 0; i < E2END; i++)
  {
    if ((i & 0x03f) == 0x20)
      outchar('.');
    EEPROM.write(i, 0);
  }
  outchar(LF);
}
  goto execnextline;

esave:
{
  outStream = kStreamEEProm;
  eepos = 0;

  // copied from "List"
  list_line = findline();
  while (list_line != program_end)
  {
    printline();
  }
  outchar('\0');

  // go back to standard output, close the file
  //outStream = kStreamSerial;
  outStream = kStreamXila;

  goto warmstart;
}

echain:
  runAfterLoad = true;

eload:
  // clear the program
  program_end = program_start;

  // load from a file into memory
  eepos = 0;
  inStream = kStreamEEProm;
  inhibitOutput = true;
  goto warmstart;

input:
{
  unsigned char var;
  int value;
  ignore_blanks();
  if (*txtpos < 'A' || *txtpos > 'Z')
    goto qwhat;
  var = *txtpos;
  txtpos++;
  ignore_blanks();
  if (*txtpos != NL && *txtpos != ':')
    goto qwhat;
inputagain:
  tmptxtpos = txtpos;
  getln('?');
  toUppercaseBuffer();
  txtpos = program_end + sizeof(unsigned short);
  ignore_blanks();
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto inputagain;
  ((short int *)variables_begin)[var - 'A'] = value;
  txtpos = tmptxtpos;

  goto run_next_statement;
}

forloop:
{
  unsigned char var;
  short int initial, step, terminal;
  ignore_blanks();
  if (*txtpos < 'A' || *txtpos > 'Z')
    goto qwhat;
  var = *txtpos;
  txtpos++;
  ignore_blanks();
  if (*txtpos != '=')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  expression_error = 0;
  initial = expression();
  if (expression_error)
    goto qwhat;

  scantable(to_tab);
  if (table_index != 0)
    goto qwhat;

  terminal = expression();
  if (expression_error)
    goto qwhat;

  scantable(step_tab);
  if (table_index == 0)
  {
    step = expression();
    if (expression_error)
      goto qwhat;
  }
  else
    step = 1;
  ignore_blanks();
  if (*txtpos != NL && *txtpos != ':')
    goto qwhat;

  if (!expression_error && *txtpos == NL)
  {
    struct stack_for_frame *f;
    if (sp + sizeof(struct stack_for_frame) < stack_limit)
      goto qsorry;

    sp -= sizeof(struct stack_for_frame);
    f = (struct stack_for_frame *)sp;
    ((short int *)variables_begin)[var - 'A'] = initial;
    f->frame_type = STACK_FOR_FLAG;
    f->for_var = var;
    f->terminal = terminal;
    f->step = step;
    f->txtpos = txtpos;
    f->current_line = current_line;
    goto run_next_statement;
  }
}
  goto qhow;

gosub:
  expression_error = 0;
  linenum = expression();
  if (!expression_error && *txtpos == NL)
  {
    struct stack_gosub_frame *f;
    if (sp + sizeof(struct stack_gosub_frame) < stack_limit)
      goto qsorry;

    sp -= sizeof(struct stack_gosub_frame);
    f = (struct stack_gosub_frame *)sp;
    f->frame_type = STACK_GOSUB_FLAG;
    f->txtpos = txtpos;
    f->current_line = current_line;
    current_line = findline();
    goto execline;
  }
  goto qhow;

next:
  // Fnd the variable name
  ignore_blanks();
  if (*txtpos < 'A' || *txtpos > 'Z')
    goto qhow;
  txtpos++;
  ignore_blanks();
  if (*txtpos != ':' && *txtpos != NL)
    goto qwhat;

gosub_return:
  // Now walk up the stack frames and find the frame we want, if present
  tempsp = sp;
  while (tempsp < program + sizeof(program) - 1)
  {
    switch (tempsp[0])
    {
    case STACK_GOSUB_FLAG:
      if (table_index == KW_RETURN)
      {
        struct stack_gosub_frame *f = (struct stack_gosub_frame *)tempsp;
        current_line = f->current_line;
        txtpos = f->txtpos;
        sp += sizeof(struct stack_gosub_frame);
        goto run_next_statement;
      }
      // This is not the loop you are looking for... so Walk back up the stack
      tempsp += sizeof(struct stack_gosub_frame);
      break;
    case STACK_FOR_FLAG:
      // Flag, Var, Final, Step
      if (table_index == KW_NEXT)
      {
        struct stack_for_frame *f = (struct stack_for_frame *)tempsp;
        // Is the the variable we are looking for?
        if (txtpos[-1] == f->for_var)
        {
          short int *varaddr = ((short int *)variables_begin) + txtpos[-1] - 'A';
          *varaddr = *varaddr + f->step;
          // Use a different test depending on the sign of the step increment
          if ((f->step > 0 && *varaddr <= f->terminal) || (f->step < 0 && *varaddr >= f->terminal))
          {
            // We have to loop so don't pop the stack
            txtpos = f->txtpos;
            current_line = f->current_line;
            goto run_next_statement;
          }
          // We've run to the end of the loop. drop out of the loop, popping the stack
          sp = tempsp + sizeof(struct stack_for_frame);
          goto run_next_statement;
        }
      }
      // This is not the loop you are looking for... so Walk back up the stack
      tempsp += sizeof(struct stack_for_frame);
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

  if (*txtpos < 'A' || *txtpos > 'Z')
    goto qhow;
  var = (short int *)variables_begin + *txtpos - 'A';
  txtpos++;

  ignore_blanks();

  if (*txtpos != '=')
    goto qwhat;
  txtpos++;
  ignore_blanks();
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;
  // Check that we are at the end of the statement
  if (*txtpos != NL && *txtpos != ':')
    goto qwhat;
  *var = value;
}
  goto run_next_statement;

poke:
{
  short int value;
  short int address;

  // Work out where to put it
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;
  address = value;

  // check for a comma
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  // Now get the value to assign
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;

  // Check that we are at the end of the statement
  if (*txtpos != NL && *txtpos != ':')
    goto qwhat;

  //printf("Poke %i value %i\n",address, value);
  // validate target address is in program space
  if (address < 0 || address > PROG_RAM)
    goto qwhat;

  // destructive overwrite program address with provided value
  program[address] = (char)value;
}
  goto run_next_statement;

list:
  linenum = testnum(); // Retuns 0 if no line found.

  // Should be EOL
  if (txtpos[0] != NL)
    goto qwhat;

  // Find the line
  list_line = findline();
  while (list_line != program_end)
    printline();
  goto warmstart;

print:
  // If we have an empty list then just put out a NL
  if (*txtpos == ':')
  {
    line_terminator();
    txtpos++;
    goto run_next_statement;
  }

  if (*txtpos == ';') // no terminator
  {
    txtpos++;
    goto run_next_statement;
  }

  if (*txtpos == NL)
  {
    goto execnextline;
  }

  while (1)
  {
    ignore_blanks();
    if (print_quoted_string())
    {
      ;
    }
    else if (*txtpos == '"' || *txtpos == '\'')
      goto qwhat;
    else
    {
      short int e;
      expression_error = 0;
      e = expression();
      if (expression_error)
        goto qwhat;
      printnum(e);
    }

    // At this point we have three options, a comma or a new line
    if (*txtpos == ',')
      txtpos++; // Skip the comma and move onto the next
    else if (txtpos[0] == ';' && (txtpos[1] == NL || txtpos[1] == ':'))
    {
      txtpos++; // This has to be the end of the print - no newline
      break;
    }
    else if (*txtpos == NL || *txtpos == ':')
    {
      line_terminator(); // The end of the print statement
      break;
    }
    else
      goto qwhat;
  }
  goto run_next_statement;

mem:
  // memory free
  printnum(variables_begin - program_end);
  printmsg(memorymsg);

  {
    // eprom size
    printnum(E2END + 1);
    printmsg(eeprommsg);

    // figure out the memory usage;
    val = ' ';
    int i;
    for (i = 0; (i < (E2END + 1)) && (val != '\0'); i++)
    {
      val = EEPROM.read(i);
    }
    printnum((E2END + 1) - (i - 1));

    printmsg(eepromamsg);
  }

  goto run_next_statement;

  /*************************************************/

awrite: // AWRITE <pin>,val
dwrite:
{
  short int pinNo;
  short int value;
  unsigned char *txtposBak;

  // Get the pin number
  expression_error = 0;
  pinNo = expression();
  if (expression_error)
    goto qwhat;

  // check for a comma
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  txtposBak = txtpos;
  scantable(highlow_tab);
  if (table_index != HIGHLOW_UNKNOWN)
  {
    if (table_index <= HIGHLOW_HIGH)
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
    expression_error = 0;
    value = expression();
    if (expression_error)
      goto qwhat;
  }
  pinMode(pinNo, OUTPUT);
  if (isDigital)
  {
    digitalWrite(pinNo, value);
  }
  else
  {
    Analog_Write(pinNo, value);
  }
}
  goto run_next_statement;

pinmode: // PINMODE <pin>, I/O
  goto unimplemented;

  /*************************************************/
files:
  // display a listing of files on the device.
  // version 1: no support for subdirectories

  cmd_Files();
  goto warmstart;

chain:
  runAfterLoad = true;

load:
  // clear the program
  program_end = program_start;

  // load from a file into memory

  {
    unsigned char *filename;

    // Work out the filename
    expression_error = 0;
    filename = filenameWord();
    if (expression_error)
      goto qwhat;

    // check if file exists
    if (!SD.exists((char *)filename))
    {
      // file is missing
      printmsg(sdfilemsg);
    }
    else
    {
      // file exists so open it
      fp = SD.open((const char *)filename);
      inStream = kStreamFile;
      inhibitOutput = true;
    }
  }
  goto warmstart;

save:
  // save from memory out to a file

  {
    unsigned char *filename;

    // Work out the filename
    expression_error = 0;
    filename = filenameWord();
    if (expression_error)
      goto qwhat;

    // saving filename...
    Serial.print("Saving: ");
    Serial.println((char *)filename);

    // remove the old file if it exists
    if (SD.exists((char *)filename))
    {
      SD.remove((char *)filename);
    }

    // open the file, switch over to file output
    fp = SD.open((const char *)filename, FILE_WRITE);

    if (fp == (File)NULL)
    {
      Serial.println("Open Failed");
      goto qwhat;
    }
    else
    {
      outStream = kStreamFile;
    }

    // copied from "List"
    list_line = findline();
    while (list_line != program_end)
      printline();

    // go back to standard output, close the file
    //outStream = kStreamSerial;
    outStream = kStreamXila;

    fp.close();
    goto warmstart;
  }

delfile:
  // delete a file

  {
    unsigned char *filename;

    // Work out the filename
    expression_error = 0;
    filename = filenameWord();
    if (expression_error)
      goto qwhat;

    // deleting filename
    Serial.print("Deleting: ");
    Serial.println((char *)filename);

    // remove the file if it exists
    if (SD.exists((char *)filename))
    {
      SD.remove((char *)filename);
    }
    goto warmstart;
  }

rseed:
{
  short int value;

  //Get the pin number
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;

  randomSeed(value);
  goto run_next_statement;
}

nlist:
{
  unsigned int x;

  //Get the x val
  expression_error = 0;
  x = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  linenum = x; // Retuns 0 if no line found.

  // Should be EOL
  if (txtpos[0] != NL)
  {
    goto qwhat;
  }

  // Find the line
  list_line = findline();
  //while (list_line != program_end)
  printline();
  goto warmstart;
}

drawpix:
{
  unsigned int x;
  unsigned int y;
  unsigned int col;

  //Get the x coordinate
  expression_error = 0;
  x = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the y coordinate
  expression_error = 0;
  y = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the color
  expression_error = 0;
  col = expression();
  if (expression_error)
    goto qwhat;

  if (x < 0 || x > DISPLAY_X_RESOLUTION || y < 0 || y > DISPLAY_Y_RESOLUTION || col > 2)
    goto qwhat;

  Draw_Pixel(x, y, col);
  goto run_next_statement;
}

drawline:
{
  unsigned int x0;
  unsigned int y0;
  unsigned int x1;
  unsigned int y1;
  unsigned int col;

  //Get the x0 coordinate
  expression_error = 0;
  x0 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the y0 coordinate
  expression_error = 0;
  y0 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the x1 coordinate
  expression_error = 0;
  x1 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the y1 coordinate
  expression_error = 0;
  y1 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the color
  expression_error = 0;
  col = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  if (x0 < 0 || x0 > DISPLAY_X_RESOLUTION || y0 < 0 || y0 > DISPLAY_Y_RESOLUTION || x1 < 0 || x1 > DISPLAY_X_RESOLUTION || y1 < 0 || y1 > DISPLAY_Y_RESOLUTION || col > 2)
  {
    goto qwhat;
  }

  Draw_Line(x0, y0, x1, y1, col);

  goto run_next_statement;
}

drawrow:
{
  unsigned int line;
  unsigned int x0;
  unsigned int x1;
  unsigned int col;

  //Get the x0 coordinate
  expression_error = 0;
  line = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the y0 coordinate
  expression_error = 0;
  x0 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the x1 coordinate
  expression_error = 0;
  x1 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the color
  expression_error = 0;
  col = expression();
  if (expression_error)
    goto qwhat;

  if (x0 < 0 || x0 > DISPLAY_X_RESOLUTION || x1 < 0 || x1 > DISPLAY_X_RESOLUTION || x1 <= x0 || col > 2)
    goto qwhat;

  Draw_Row(x0, line, x1, col);

  goto run_next_statement;
}

drawcol:
{
  unsigned int line;
  unsigned int y0;
  unsigned int y1;
  unsigned int col;

  //Get the x0 coordinate
  expression_error = 0;
  line = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the y0 coordinate
  expression_error = 0;
  y0 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the x1 coordinate
  expression_error = 0;
  y1 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the color
  expression_error = 0;
  col = expression();
  if (expression_error)
    goto qwhat;

  if (y0 < 0 || y0 > DISPLAY_Y_RESOLUTION || y1 < 0 || y1 > DISPLAY_Y_RESOLUTION || y1 <= y0 || col > 2)
    goto qwhat;

  Draw_Column(line, y0, y1, col);
  goto run_next_statement;
}

drawrect:
{
  unsigned int x0;
  unsigned int y0;
  unsigned int w;
  unsigned int h;
  unsigned int col;
  unsigned int fillC;

  //Get the x0 coordinate
  expression_error = 0;
  x0 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the y0 coordinate
  expression_error = 0;
  y0 = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the width
  expression_error = 0;
  w = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the height
  expression_error = 0;
  h = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the height
  expression_error = 0;
  col = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the height
  expression_error = 0;
  fillC = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  if (x0 < 0 || x0 > DISPLAY_X_RESOLUTION || y0 < 0 || y0 > DISPLAY_Y_RESOLUTION || h < 0 || h > DISPLAY_Y_RESOLUTION || w < 0 || w > DISPLAY_X_RESOLUTION)
  {
    goto qwhat;
  }

  Draw_Rectangle(x0, y0, w, h, col, fillC);
  goto run_next_statement;
}

drawcirc:
{
  unsigned int x0;
  unsigned int y0;
  unsigned int r;
  unsigned char col;
  unsigned char fillC;

  //Get the x0 coordinate
  expression_error = 0;
  x0 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the y0 coordinate
  expression_error = 0;
  y0 = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the width
  expression_error = 0;
  r = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the height
  expression_error = 0;
  col = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
  {
    goto qwhat;
  }
  txtpos++;
  ignore_blanks();

  //Get the height
  expression_error = 0;
  fillC = expression();
  if (expression_error)
  {
    goto qwhat;
  }

  if (x0 < 0 || x0 > DISPLAY_X_RESOLUTION || y0 < 0 || y0 > DISPLAY_Y_RESOLUTION || r < 0 || r > DISPLAY_Y_RESOLUTION)
    goto qwhat;

  Draw_Circle(x0, y0, r, col, fillC);
  goto run_next_statement;
}

drawchar:
{
  unsigned int x;
  unsigned int y;
  char c[2];

  //Get the x coordinate
  expression_error = 0;
  x = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the y coordinate
  expression_error = 0;
  y = expression();
  if (expression_error)
    goto qwhat;

  //Ignore the blanks
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the character
  ignore_blanks();
  //if (*txtpos < ' ' || *txtpos > '~')
  //  goto qwhat;
  c[0] = *txtpos;
  c[1] = '\0';
  txtpos++;

  if (x < 0 || x > DISPLAY_X_RESOLUTION || y < 0 || y > DISPLAY_Y_RESOLUTION)
    goto qwhat;

  Draw_Char(x, y, c);
  //goto prompt;
  goto run_next_statement;
}

getpix:
{

  goto unimplemented; // not possible on nextion display

  /*
    unsigned int x;
    unsigned int y;

    //Get the x coordinate
    expression_error = 0;
    x = expression();
    if (expression_error)
      goto qwhat;

    //Ignore the blanks
    ignore_blanks();
    if (*txtpos != ',')
      goto qwhat;
    txtpos++;
    ignore_blanks();


    //Get the y coordinate
    expression_error = 0;
    y = expression();
    if (expression_error)
      goto qwhat;

    if ( x < 0 || x > TV.hres() || y < 0 || y > TV.vres())
      goto qwhat;

    //TV.set_pixel(x, y, col);
    //goto run_next_statement;
    printnum((int)TV.get_pixel(x, y));
    printmsg(spacemsg);
    goto run_next_statement;*/
}

wifi:

{
  short int value;

  unsigned char *ssid;
  unsigned char *pswd;

  // Get the SSID from an expression
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;
  ssid = (unsigned char *)value;

  // check for a comma
  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  // Now get the password
  expression_error = 0;
  value = expression();
  if (expression_error)
    goto qwhat;
  pswd = (unsigned char *)value;

  Serial.printf("Wifi ssid %s pswd %s\n", ssid, pswd);

  if (Xila.WiFi_Connect((char *)ssid, (char *)pswd) != Xila.Success)
  {
    //not connected
  }

  // Check that we are at the end of the statement
  if (*txtpos != NL && *txtpos != ':')
    goto qwhat;

  // all set with
  goto run_next_statement;
}

tonestop:
  Xila.Sound.No_Tone(kPiezoPin);
  goto run_next_statement;

tonegen:
{
  // TONE freq, duration
  // if either are 0, tones turned off
  short int freq;
  short int duration;

  //Get the frequency
  expression_error = 0;
  freq = expression();
  if (expression_error)
    goto qwhat;

  ignore_blanks();
  if (*txtpos != ',')
    goto qwhat;
  txtpos++;
  ignore_blanks();

  //Get the duration
  expression_error = 0;
  duration = expression();
  if (expression_error)
    goto qwhat;

  if (freq == 0 || duration == 0)
    goto tonestop;

  Xila.Sound.Tone(kPiezoPin, freq, duration);
  if (alsoWait)
  {
    delay(duration);
    alsoWait = false;
  }
  goto run_next_statement;
}
}
