#include "Tiny_Basic.hpp"
#include "GalaxOS.hpp"

#include <Arduino.h>

TinyBasic_Class *TinyBasic_Class::TinyBasic_Pointer = NULL;

const unsigned char TinyBasic_Class::to_tab[] = {
    'T', 'O' + 0x80,
    0};

const unsigned char TinyBasic_Class::func_tab[] = {
    'P', 'E', 'E', 'K' + 0x80,
    'A', 'B', 'S' + 0x80,
    'A', 'R', 'E', 'A', 'D' + 0x80,
    'D', 'R', 'E', 'A', 'D' + 0x80,
    'R', 'N', 'D' + 0x80,
    0};

unsigned char TinyBasic_Class::inStream = kStreamSerial;
unsigned char TinyBasic_Class::outStream = kStreamSerial;

TinyBasic_Class::TinyBasic_Class(Software_Handle_Class *Software_Hanlde_To_Set) : Software_Class(Software_Hanlde_To_Set, 5)
{
  Instance_Pointer = this;

  xTaskCreatePinnedToCore(TinyBasic_Task, "TinyBasic", 2 * 6 * 1024, NULL, 2, NULL, &Task_Handle, 0);
}

TinyBasic_Class::~TinyBasic_Class()
{
  Execute(0x0043);
  vTaskDelete(Task_Handle);
  Instance_Pointer == NULL;
}

void TinyBasic_Task(void *pvParameters)
{
  (void)pvParameters;
  Serial.begin(CONSOLE_BAUD); // opens serial port
  Serial.println();
  printmsg(initmsg);

  GalaxOS.Display.Draw_Fill(2, 20, 476, 250, COLOR_DARK_GREY);

  // Initialize SD Card

  pinMode(14, INPUT_PULLUP); // change this to 53 on a mega
  //pinMode(15, INPUT_PULLUP); // change this to 53 on a mega
  pinMode(2, INPUT_PULLUP);  // change this to 53 on a mega
  pinMode(4, INPUT_PULLUP);  // change this to 53 on a mega
  pinMode(12, INPUT_PULLUP); // change this to 53 on a mega
  pinMode(13, INPUT_PULLUP); // change this to 53 on a mega

  if (!SD_MMC.begin())
  {
    // failed
    printmsg(sderrormsg);
  }
  else
  {
    sd_is_initialized = true;
  }

  if (SD_MMC.exists(AUTORUN_FILE))
  {
    program_end = program_start;
    fp = SD_MMC.open(AUTORUN_FILE);
    inStream = kStreamFile;
    inhibitOutput = true;
    runAfterLoad = true;
  }

  outStream = kStreamSerial;
  inStream = kStreamSerial;
  inhibitOutput = false;

  // Initalize EEPROM
  int val = EEPROM.read(0); // read the first byte of the eeprom. if it's a number, assume it's a program we can load
  if (val >= '0' && val <= '9')
  {
    program_end = program_start;
    inStream = kStreamEEProm;
    eepos = 0;
    inhibitOutput = true;
    runAfterLoad = true;
  }

  while (1)
  {
    switch (INSTANCE_POINTER->Get_Command())
    {
    case 0:
      break;
      case 
    }
  }
}

/***************************************************************************/
static void TinyBasic_Class::ignore_blanks(void)
{
  while (*txtpos == SPACE || *txtpos == TAB)
    txtpos++;
}

/***************************************************************************/
static void TinyBasic_Class::scantable(const unsigned char *table)
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
void TinyBasic_Class::pushb(unsigned char b)
{
  sp--;
  *sp = b;
}

/***************************************************************************/
unsigned char TinyBasic_Class::popb()
{
  unsigned char b;
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
unsigned char TinyBasic_Class::print_quoted_string(void)
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
void TinyBasic_Class::printmsgNoNL(const unsigned char *msg)
{
  while (pgm_read_byte(msg) != 0)
  {
    outchar(pgm_read_byte(msg++));
  };
}

/***************************************************************************/
void TinyBasic_Class::printmsg(const unsigned char *msg)
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
unsigned char *TinyBasic_Class::findline(void)
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
void TinyBasic_Class::toUppercaseBuffer(void)
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

unsigned char *TinyBasic_Class::filenameWord(void)
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
void TinyBasic_Class::line_terminator(void)
{
  outchar(NL);
  outchar(CR);
}

/***********************************************************/
unsigned char TinyBasic_Class::breakcheck(void)
{
  if (Serial.available())
    return Serial.read() == CTRLC;
  return 0;
}
/***********************************************************/
int TinyBasic_Class::inchar()
{
  int v;

  switch (inStream)
  {
  case (kStreamFile):
#ifdef ENABLE_FILEIO
    v = fp.read();
    if (v == NL)
      v = CR; // file translate
    if (!fp.available())
    {
      fp.close();
      goto inchar_loadfinish;
    }
    return v;
#endif
    break;
  case (kStreamEEProm):
#ifdef ENABLE_EEPROM
    v = EEPROM.read(eepos++);
    if (v == '\0')
    {
      goto inchar_loadfinish;
    }
    return v;
#else
    inStream = kStreamSerial;
    return NL;
#endif
    break;
  case (kStreamSerial):
  default:
    while (1)
    {
      if (Serial.available())
        return Serial.read();
    }
  }

inchar_loadfinish:
  inStream = kStreamSerial;
  inhibitOutput = false;

  if (runAfterLoad)
  {
    runAfterLoad = false;
    triggerRun = true;
  }
  return NL; // trigger a prompt.
}

/***********************************************************/
void TinyBasic_Class::outchar(unsigned char c)
{
  if (inhibitOutput)
    return;

#ifdef ENABLE_FILEIO
  if (outStream == kStreamFile)
  {
    // output to a file
    fp.write(c);
  }
  else
#endif

#ifdef ENABLE_EEPROM
      if (outStream == kStreamEEProm)
  {
    EEPROM.write(eepos++, c);
  }
  else
#endif /* ENABLE_EEPROM */
    Serial.write(c);
}

void TinyBasic_Class::cmd_Files(void)
{
  File dir = SD_MMC.open("/");
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
#endif