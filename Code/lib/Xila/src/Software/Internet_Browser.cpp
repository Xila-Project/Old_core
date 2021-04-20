#include "Software/Internet_Browser.hpp"

Internet_Browser_Class *Internet_Browser_Class::Instance_Pointer = NULL;

Software_Class *Internet_Browser_Class::Load()
{
  if (Instance_Pointer != NULL)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = new Internet_Browser_Class();
  return Instance_Pointer;
}

Internet_Browser_Class::Internet_Browser_Class() : Software_Class(Internet_Browser_Handle)
{
  memset(Server, 0, 30);
  memset(Path, 0, 60);
  memset(URL, 0, 90);

  Server[0] = '*';

  pageLinks = {0, 0};

  textContent = {0, 0, false};

  Xila.Task.Create(Main_Task, "Internet Browser", Memory_Chunk(6), NULL, &Task_Handle);
}

Internet_Browser_Class::~Internet_Browser_Class()
{
  Client.stop();
  if (Instance_Pointer != this)
  {
    delete Instance_Pointer;
  }
  Instance_Pointer = NULL;
}

void Internet_Browser_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
  if (Type == Xila.Display.Variable_Long && Adress == 'S')
  {
    if (Cache_File)
    {
      textContent.index[textContent.pagePtr] = Cache_File.size() - *(uint16_t *)Variable;
    }
  }
}

void Internet_Browser_Class::Main_Task(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    switch (Instance_Pointer->Get_Instruction())
    {
    case Idle:
      if (Xila.Software.Get_State(Internet_Browser_Handle) == Minimized)
      {
        Xila.Task.Delay(90);
      }
      else
      {
        while (Xila.Keyboard.Available())
        {
          switch (Xila.Keyboard.Read())
          {
          case Xila.Keyboard.Arrow_Up:
            Instance_Pointer->Send_Instruction('P', 'U');
            break;
          case Xila.Keyboard.Arrow_Down:
            Instance_Pointer->Send_Instruction('P', 'D');
            break;
          case Xila.Keyboard.Arrow_Right:
            Instance_Pointer->Send_Instruction('N', 'L');
            break;
          case Xila.Keyboard.Arrow_Left:
            Instance_Pointer->Send_Instruction('P', 'L');
            break;
          case Xila.Keyboard.Enter:
            Instance_Pointer->Send_Instruction('G', 'L');
            break;
          case Xila.Keyboard.Escape:
            Instance_Pointer->Send_Instruction('M', 'i');
            break;
          case 'H':
          case 'h':
            Instance_Pointer->Send_Instruction('H', 'o');
            break;
          case ' ':
            Instance_Pointer->Send_Instruction('K', 'U');
            break;
          default:
            break;
          }
        }
      }
      Instance_Pointer->Set_Watchdog_Timeout();
      Xila.Task.Delay(10);
      //Idle : nothing to do
      break;
    case Open:
      Xila.Display.Set_Current_Page(F("Internet_Brow"));
      Instance_Pointer->Go_Home();
      break;
    case Minimize:
      break;
    case Maximize:
      Xila.Display.Set_Current_Page(F("Internet_Brow"));
      Instance_Pointer->Send_Instruction('H', 'o');
      break;

    case Close: // NULL + C : Close
      delete Instance_Pointer;
      Xila.Task.Delete();
      break;

    case Instruction('M', 'i'):
      Xila.Software.Minimize(Internet_Browser_Handle);
      break;

    case Hibernate:
    case Shutdown:
    case Restart:
    case Instruction('C', 'l'):
      Xila.Software.Close(Internet_Browser_Handle);
      break;

    case Instruction('D', 'i'):
      if (!Instance_Pointer->Display_Page())
      {
        Xila.Dialog.Event(F("Display page failed."), Xila.Error);
      }

      break;

    case Instruction('C', 'a'):
      if (Instance_Pointer->Cache_URL(Instance_Pointer->Server, Instance_Pointer->Path))
      {
        Instance_Pointer->Send_Instruction('D', 'i');
        Instance_Pointer->pageLinks.linkPtr = 0;
      }
      else
      {
        Instance_Pointer->Send_Instruction('H', 'o');
      }
      Instance_Pointer->pageLinks.lastLink = 0;
      Instance_Pointer->Client.stop();
      Instance_Pointer->Cache_File.close();

      break;
    case Instruction('K', 'U'):
      Xila.Dialog.Keyboard(Instance_Pointer->URL, sizeof(URL));
      Instance_Pointer->Send_Instruction('G', 'U');
      break;
    case Instruction('P', 'D'): //PD
      Instance_Pointer->Page_Down();
      break;

    case Instruction('P', 'U'): //PU
      Instance_Pointer->Page_Up();
      break;

    case Instruction('N', 'L'): //NL
      Instance_Pointer->Next_Link();
      break;
    case Instruction('P', 'L'): //PL
      Instance_Pointer->Previous_Link();
      break;
    case Instruction('G', 'L'): //GL
      Instance_Pointer->Go_Link();
      break;
    case Instruction('G', 'U'): //GU
      Instance_Pointer->Split_URL(Instance_Pointer->URL);
      Instance_Pointer->pageLinks.linkPtr = 0;
      Instance_Pointer->pageLinks.lastLink = 0;
      Instance_Pointer->textContent.pagePtr = 0;
      Instance_Pointer->textContent.lastPage = 0;
      Instance_Pointer->Load_Page();
      break;
    case Instruction('H', 'o'): //HO
      Instance_Pointer->Go_Home();
      break;
    default:
      break;
    }
    Xila.Task.Delay(10);
  }
}

void Internet_Browser_Class::Go_Home()
{
  memset(Server, '\0', sizeof(Server));
  memset(Path, '\0', sizeof(Path));
  memset(URL, '\0', sizeof(URL));
  strcpy(Server, "*");
  strcpy(URL, "*");

  Send_Instruction('D', 'i');
}

byte Internet_Browser_Class::Cache_URL(char *URLserver, char *URLpath)
{
// HTML parser states
#define sLEADIN 0
#define sHEADER 1
#define sTEXT 2
#define sPRE 3
#define sTAG 4
#define sAMP 5
#define sANCHOR 6
#define sSTUFF 7
#define sHREF 8
#define sURL 9
#define sENDTAG 10
#define sQUIET 11
#define sSCRIPT 12
#define sFOOTER 99
#define URL_SIZE = 130

  uint16_t count = 0;         // Output char count
  uint32_t downloadCount = 0; // Download char count
  uint8_t localState = sTEXT; // HTML stream state
  uint8_t metaState = sTEXT;  // HTML output state
  uint8_t nextState = sTEXT;
  uint16_t tagHash = 0; // Hash for tag name
  uint16_t ampHash = 0; // Hash for escape characters
  char url[130];        // Buffer for building parsed URLs
  uint8_t i = 0;
  uint8_t c = 0;             // Input char
  uint8_t lastChar = TAG_CR; // Set to supress leading junk
  uint16_t outputChar = 0;   // Char to build output
  uint32_t fileLength = 0;
  uint8_t cleanChar = 0;
  uint32_t HTTP_Return_Code = 0;

  //================================================
  // Open URL
  //================================================
  Xila.Display.Refresh(F("PANEL_TXT"));
  Xila.Display.Show(F("LOAD_TXT"));
  Xila.Display.Show(F("LOAD_BAR"));
  Xila.Display.Set_Value(F("LOAD_BAR"), 0);

  Cache_File.close();
  Cache_File = Xila.Drive.Open(Internet_Browser_File("Cache.xdf"), FILE_WRITE);

  if (!Cache_File)
  {
    return 0;
  }

  Xila.Task.Delay(100);
  if (WiFi.status() != WL_CONNECTED)
  {
    return 0;
  }

  if (URLserver[0] == '*') // Should never get an * here
  {
    return 0;
  }

  Client.setInsecure();

  Set_Watchdog_Timeout(30000);
  if (Client.connect(URLserver, 443))
  {
    Client.print(F("GET "));
    Client.print(URLpath);
    Client.print(F(" HTTP/1.1\r\n"));
    Client.print(F("Host: "));
    Client.print(URLserver);
    Client.print(F("\r\nUser-Agent: Mozilla/4.0 (Mobile; PIP/7.0) PIP/7.0\r\nConnection: close\r\n\r\n"));
  }
  else
  {
    //error handle : reset ?
    return 0;
  }

  Xila.Task.Delay(500);

  byte Wait = 0;
  while ((Wait < 100) && (!Client.available())) //wait 5 sec unti timeout
  {
    Get_Instruction();

    Xila.Task.Delay(50);
    Wait++;
  }
  if ((!Client.available()) && (!Client.connected()))
  {
    //error handle
    return 0;
  }

  {
    memcpy(generalBuffer, "HTTP/1.1 \0", 10); //looking for the HTTP return code
    outputChar = Find_Until(generalBuffer, true);
    if (outputChar == 2)
    {
      HTTP_Return_Code = Client.parseInt();

      if (HTTP_Return_Code >= 308) // stop parsing if http code isn't between 200 and 300
      {
        return 0;
      }
    }
    memcpy(generalBuffer, "-Length: \0", 10); //looking for the content length
    outputChar = Find_Until(generalBuffer, true);

    if (outputChar == 2)
    {
      fileLength = Client.parseInt();
      if (fileLength < 10)
      {
        fileLength = 0;
      }
      if (fileLength > 0)
      {
      }
    }
    else if (outputChar == 1) //cannot find the file lenght, stop
    {
      fileLength = 0;
    }
    else
    {
      fileLength = 0;
    }

    //to do : write code to find header

    memcpy(generalBuffer, "<body\0", 7); //search the first marker
    outputChar = Find_Until(generalBuffer, false);
    if (outputChar == 0) //cannot find the body
    {
      return 0;
    }
    else
    {
      localState = sENDTAG;
    }
  }
  c = Client.read();

  //================================================
  // Loading loop
  //================================================
  while (metaState < sFOOTER)
  {
    c = 0;
    if (Client.available())
    {
      c = Client.read();
      downloadCount++;
    }
    else
    {
      Wait = 0;
      while ((Wait < 100) && (!Client.available())) //wait 5 sec unti timeout
      {
        Xila.Task.Delay(50);
      }
      if ((!Client.available()) && (!Client.connected()))
      {
        //error handle
        Send_Instruction('D', 'i');

        return 0;
      }
    }

    nextState = localState;
    outputChar = c;

    //================================================
    // State is sAMP &amp;                           4
    //================================================
    if ((c == '&') && ((localState == sTEXT) || (localState == sURL)))
    { // Enter state condition
      if (metaState == sANCHOR)
      {

        url[i++] = c;
      }
      localState = sAMP;
      ampHash = 0;
      continue;
    }
    if (localState == sAMP)
    {
      if (c == ';')
      { // End condition

        if (metaState != sANCHOR)
        {
          outputChar = Hash_Out(ampHash);

          if (outputChar == 0)
          {
            outputChar = 129; // Unkown character
            nextState = sTEXT;
          }
          else
            nextState = sTEXT;
        }
        else
          outputChar = 0;
        if (metaState == sANCHOR)
          nextState = sURL;
      }
      else
      {
        ampHash = (ampHash << 2) + ((int)c) - 32;
        outputChar = 0;
        continue;
      }
    }

    //=================================================
    // State is sTAG                                 3
    //================================================
    if (c == '<')
    { // Enter state condition
      localState = sTAG;
      nextState = sTAG;
      if (metaState != sQUIET)
      {
        metaState = sTEXT;
      }
      tagHash = 0;
      continue;
    }

    if (localState == sTAG)
    {
      nextState = sTAG;
      if ((c == '>') || (c == ' ') || (c == '\t'))
      { // End condition

        nextState = sTEXT;

        if (tagHash == BODYTAGEND)
        {
          metaState = sFOOTER;
          continue;
        }

        if ((tagHash == SCRIPTTAGEND) || (tagHash == STYLETAGEND))
        {

          nextState = sTEXT;
          localState = sTEXT;
          metaState = sTEXT;
          continue;
        }
        if ((tagHash == SCRIPTTAG) || (tagHash == STYLETAG))
        {

          if (c == '>')
            localState = sTEXT;
          else
            localState = sENDTAG;
          metaState = sQUIET;
          tagHash = 0;
          continue;
        }

        if (tagHash == PRETAG)
        {
          nextState = sTEXT;
          metaState = sPRE;
        }
        if (tagHash == PRETAGEND)
        {
          nextState = sTEXT;
          metaState = sTEXT;
        }
        outputChar = Hash_Out(tagHash);
        if (c != '>')
        {
          if (tagHash == 65)
          {
            nextState = sSTUFF; // Is actually an <a tag
          }
          else
          {
            nextState = sENDTAG; // Tag not supported
          }
        }
        tagHash = 0;
      }
      else
      {
        tagHash = (tagHash << 1) + ((int)lowerCase(c)) - 32;
        outputChar = 0;
      }
    }

    //================================================
    // State is sSTUFF in an <a  tag before href="   7
    //================================================
    if (localState == sSTUFF)
    {
      if ((c != ' ') && (c != '\t'))
      { // End condition
        tagHash = lowerCase(c) - 32;
        nextState = sHREF;
      }
      else if (c == '>')
      { // Error in tag termination, wasn't an anchor
        nextState = sTEXT;
        tagHash = 0;
      }
      outputChar = 0;
    }

    //================================================
    // State is sHREF href="                         8
    //================================================
    if (localState == sHREF)
    {
      if (tagHash == HREFTAG)
      { // End condition
        nextState = sURL;
        metaState = sANCHOR;
        i = 0;
      }
      else if ((c == '"') || (c == '\'') || (c == '>'))
      { // No href match
        nextState = sSTUFF;
        tagHash = 0;
      }
      else
        tagHash = (tagHash << 1) + ((int)toLowerCase(c)) - 32;
      outputChar = 0;
    }

    //================================================
    // State is sURL in href="url"                   9
    //================================================
    if (localState == sURL)
    {
      if ((c == '"') || (c == '\''))
      { // End condition

        url[i++] = 0;

        nextState = sENDTAG;
        Store_URL(url);
        Cache_File.write(TAG_LINK2);
      }
      else
      {

        url[i++] = c;

        url[i] = 0;

        if (i >= (sizeof(url) - 1))
        {
          nextState = sENDTAG;
          Cache_File.write(TAG_LINK2);
        }
      }
      outputChar = 0;
    }

    //================================================
    // State is sENDTAG after href="url"             10
    //================================================
    if (localState == sENDTAG)
    {
      if ((c == '>') && (metaState != sQUIET))
      { // End condition
        metaState = sTEXT;
        nextState = sTEXT;
      }
      else
        continue;
      outputChar = 0;
    }

    //================================================
    // State is sTEXT - Output stage                10
    //================================================
    cleanChar = outputChar & ATTR_MASK;

    if ((cleanChar == 10) || (cleanChar == '\t'))
    {
      if (fileLength > 0)
      {
        uint8_t Percent = uint8_t(downloadCount * 100 / fileLength);
        Xila.Display.Set_Value(F("LOAD_BAR"), Percent);
      }
    }

    // Handle tags with pre breaks
    if ((outputChar & PRE_BREAK))
    {
      Cache_File.write(10);
      count++;
    }

    // Write \n and \r verbatim inside PRE tag
    if (metaState == sPRE)
    {
      if (cleanChar == 13)
      {
        cleanChar = 0;
      }
      if (cleanChar == 10)
      {
        cleanChar = TAG_CR;
      }
    }

    // Convert any \n \r \t to spaces for possible supression
    else
    {
      if ((cleanChar == 10) || (cleanChar == 13) || (cleanChar == '\t'))
      {
        if (lastChar != TAG_CR)
        {
          cleanChar = ' ';
        }
        else
        {
          cleanChar = 0;
        }
      }
      if ((cleanChar == ' ') || (cleanChar == TAG_CR))
        if ((lastChar == ' ') || (lastChar == '>') || (lastChar == TAG_CR) || (cleanChar < 32))
        {
          cleanChar = 0;
        }
    }

    // Write out the charater
    if (cleanChar > 0)
    {
      count++;

      if (cleanChar > 129)
        cleanChar = 129;

      if ((cleanChar == TAG_CR) && !(outputChar & PRE_BREAK))
      {

        Cache_File.write(10);
      }
      else if (cleanChar > 31)
      {
        if (metaState != sQUIET)
        {
          Cache_File.write(cleanChar);
        }
      }
      else
      {
        Cache_File.write(cleanChar);
        count++;
      }
      lastChar = cleanChar;
    }
    else if (outputChar & PRE_BREAK)
      lastChar = TAG_CR;

    // Handle tags with pre breaks
    if ((outputChar & POST_BREAK) && (lastChar != TAG_CR))
    {
      Cache_File.write(10);
      count++;

      lastChar = TAG_CR;
    }

    localState = nextState;
  } // Loading loop
  Cache_File.print('\0');
  //Client.flush();
  Client.stop();

  Cache_File.flush();
  return 1;
}

void Internet_Browser_Class::Go_Link()
{
  Build_URL(pageLinks.index[pageLinks.linkPtr]); // Get URL from page index
  if (URL[0] != '*')                             // Load default home page
  {
    pageLinks.linkPtr = 0;
    pageLinks.lastLink = 0;
    textContent.pagePtr = 0;
    textContent.lastPage = 0;
    Load_Page();
  }
}

void Internet_Browser_Class::Page_Up()
{
  if (textContent.pagePtr > 0)
  {
    textContent.pagePtr--;
    pageLinks.lastLink = 0;
    pageLinks.linkPtr = 0;
    Send_Instruction('D', 'i');
  }
}

void Internet_Browser_Class::Page_Down()
{
  if (textContent.pagePtr < textContent.lastPage)
  {
    textContent.pagePtr++;
  }
  else
  {
    textContent.pagePtr = 0; // Reset to top
  }
  pageLinks.linkPtr = 0;
  pageLinks.lastLink = 0;
  Send_Instruction('D', 'i');
  return;
}

void Internet_Browser_Class::Next_Link()
{
  if (pageLinks.linkPtr < pageLinks.lastLink)
  {
    pageLinks.linkPtr++;
  }
  else
  {
    pageLinks.linkPtr = 0;
  }
  Send_Instruction('D', 'i');
  return;
}

void Internet_Browser_Class::Previous_Link()
{
  if (pageLinks.linkPtr > 0)
  {
    pageLinks.linkPtr--;
  }
  else
  {
    pageLinks.linkPtr = pageLinks.lastLink;
  }
  Send_Instruction('D', 'i');
}

void Internet_Browser_Class::Load_Page()
{
  Split_URL(URL);
  Send_Instruction('C', 'a');
}

void Internet_Browser_Class::Build_URL(uint16_t pointer)
{
  byte i = 0;
  char c = 0;
  uint16_t oldPos = Cache_File.position();

  if (!Cache_File.seek(pointer))
  {
    return;
  }
  c = Cache_File.read();
  while (c != TAG_LINK2)
  {
    URL[i++] = c;
    c = Cache_File.read();
  }
  URL[i] = 0;
  Cache_File.seek(oldPos);
}

void Internet_Browser_Class::displayLinkIndex()
{

  if (pageLinks.lastLink == 0)
  {
    return;
  }
  for (byte i = 0; i <= pageLinks.lastLink; i++)
  {
    Cache_File.seek(pageLinks.index[i]);
    byte c = 0, j = 0;
    c = Cache_File.read();
    while ((c != TAG_LINK2) && (j++ < 100))
    {
      c = Cache_File.read();
    }
  }
}

byte Internet_Browser_Class::Display_Page()
{
  uint16_t filePtr = textContent.index[textContent.pagePtr]; // Pointer into cached file
  uint8_t c = 1;                                             // Input character
  uint16_t count = 0;                                        // Character count for page index building
  uint16_t Last_Color = 65535;                               // Two level stack to remember colour state
  uint16_t Current_Color = 65535;
  boolean invisiblePrint = false;                    // Turn off output (for URLs, etc)
  uint8_t currentLink = 0;                           // Curretly highlightd link of the page
  boolean buildingIndex = (pageLinks.lastLink == 0); // True if this page's URL haven't been index yet
  uint16_t Cursor_Y;
  char Text_To_Print[66];
  uint8_t Text_Char_Count;

  Xila.Display.Hide(F("LOAD_BAR"));
  Xila.Display.Hide(F("LOAD_TXT"));
  Xila.Display.Refresh(F("PANEL_TXT"));

  Xila.Display.Set_Maximum_Value(F("SCROLL_SLI"), Cache_File.size());
  Xila.Display.Set_Value(F("SCROLL_SLI"), Cache_File.size() - filePtr);

  //Draw header

  Cache_File.close();
  if (Server[0] == '*')
  {
    Xila.Display.Set_Text(F("URL_TXT"), F("Home Page"));

    Cache_File = Xila.Drive.Open(Internet_Browser_File("Homepage.xdf"));
  }
  else
  {
    Xila.Display.Set_Text("URL_TXT", URL);
    Cache_File = Xila.Drive.Open(Internet_Browser_File("Cache.xdf"));
  }

  if (!Cache_File)
  {
    Xila.Dialog.Event(F("Failed to open cache file."), Xila.Error);
    memcpy(Server, "*\0", 2);
    return 0;
  }

  if (!Cache_File.seek(filePtr))
  {
    //error handle
    Xila.Dialog.Event(F("Seek failure in cache file."), Xila.Error);
    return 0;
  }

  if (buildingIndex)
  {
  }

  memset(Text_To_Print, '\0', sizeof(Text_To_Print));

  Text_Char_Count = 0;

  Cursor_Y = 50;
  Xila.Display.Set_Value(F("Y_VAR"), Cursor_Y);

  // 65 max char

  // Loop through cache fizle
  while ((filePtr <= Cache_File.size()) && (Cursor_Y < 272 - 1) && (c != 0))
  {
    if (Text_Char_Count >= 65) //Serial.print if auto return to line (max 65 normal)
    {
      switch (Current_Color)
      {
      case 65534: //Bold style
        Xila.Display.Set_Value(F("C_VAR"), Current_Color);
        Current_Color = Last_Color;
        break;
      case 65533: //Highlight style
        Xila.Display.Set_Value(F("C_VAR"), Current_Color);
        Current_Color = Last_Color;
        Last_Color = 65535;
        break;
      case 65532: //Link style
        Xila.Display.Set_Value(F("C_VAR"), Current_Color);
        Current_Color = Last_Color;
        Last_Color = 65535;
        break;
      case 65531: //Heading style

        Xila.Display.Set_Value(F("C_VAR"), Current_Color);
        Current_Color = Last_Color;
        break;
      default:
        Xila.Display.Set_Value(F("C_VAR"), Current_Color);
        break;
      }
      Xila.Display.Set_Text(F("T_VAR"), Text_To_Print);
      Xila.Display.Click(F("D_HOT"), 0);
      Cursor_Y += 14; //new line
      Text_Char_Count = 0;
      memset(Text_To_Print, '\0', sizeof(Text_To_Print));
    }
    c = Cache_File.read();
    filePtr++;
    count++;
    // Print only visible ASCII characters
    if (c > 31)
    {
      if (!invisiblePrint)
      {
        // Print only if in visible mode (supresses URLs)
        Text_To_Print[Text_Char_Count++] = c;
      }
    }

    // Handle display codes
    else
    {
      switch (c)
      {
      case TAG_CR:

      case 10: // Print rest of buffer and return to line
        Text_Char_Count = 0xFF;
        invisiblePrint = false;

        break;

      case 13: // Only doing a CR/LF on ASCII 10
        break;

      case TAG_HEADING1:            // Start of a header tag
        Last_Color = Current_Color; // Store the colour state
        Current_Color = 65531;
        break;

      case TAG_BOLD1: // Start of a bold tag
        Last_Color = Current_Color;
        Current_Color = 65534; // Almost white, code for bold text
        break;

      case TAG_LINK1:          // Start of an anchor tag. The actual URL follows
        invisiblePrint = true; // Turn off Serial.printing while the URL is loading

        if ((buildingIndex) && (currentLink < LINKINDEXSIZE))
        {
          pageLinks.index[currentLink] = filePtr;
          pageLinks.lastLink++;
        }
        break;

      case TAG_LINK2: // End of the URL part. Start of the anchor text
        Last_Color = Current_Color;
        if (currentLink == pageLinks.linkPtr) // Print inverse colors for the active link
        {
          Current_Color = 65533;
        }
        else
        {
          Current_Color = 65532; // Link color : blue
        }
        invisiblePrint = false; // Turn on Serial.printing again

        break;

      case TAG_LINK3: // End of the anchor tag
        if (currentLink < LINKINDEXSIZE)
        {
          currentLink++; // Removed && buildingLink
        }
        Text_Char_Count = 0xFF;
        break;

      case TAG_HEADING2: // End of header or bold tags
        Text_Char_Count = 0xFF;
        break;

      case TAG_BOLD2:
        Text_Char_Count = 0xFF;
        break;

        // List entry tag
      case TAG_LIST:
        //tftLCD.write(127); print del char ???
        break;

        // Horizontal rule tag
      case TAG_HR:
        Xila.Display.Draw_Rectangle(32, Cursor_Y + 6, 400, 2, 65535, false);
        Cursor_Y += 14;
        break;

      default:
        break;
      }
    }
  }

  // Update page index
  if ((textContent.pagePtr == textContent.lastPage) && (textContent.pagePtr < PAGEINDEXSIZE) && (filePtr++ < Cache_File.size()))
  {
    textContent.lastPage++;
    textContent.index[textContent.lastPage] = filePtr - 2; //textContent.index[textContent.lastPage] + count;
  }

  // Update last link pointer
  if ((buildingIndex) && (pageLinks.lastLink > 0))
  {
    pageLinks.lastLink--;
  }

  Cache_File.flush();

  return 1;
}

char Internet_Browser_Class::lowerCase(char c)
{
  if ((c > 64) && (c < 91))
  {
    return c += 32;
  }
  else
  {
    return c;
  }
}

uint16_t Internet_Browser_Class::Hash_Out(uint16_t hash)
{
  uint16_t output = 0;

  for (byte i = 0; i < NUMTAGS; i++)
  {
    if (hash == pgm_read_word(&tag_codes[i++]))
    {
      output = pgm_read_word(&tag_codes[i]);
      i = NUMTAGS;
    }
  }
  return output;
}

byte Internet_Browser_Class::Find_Until(uint8_t *String_To_Find, boolean terminate)
{
  uint8_t currentChar = 0;
  long timeOut = Xila.Time.Milliseconds() + 5000;
  char c = 0;
  while (Xila.Time.Milliseconds() < timeOut)
  {
    if (Client.available())
    {
      timeOut = Xila.Time.Milliseconds() + 5000;
      c = Client.read();
      if (terminate && (c == '<'))
      {
        return 1; // Pre-empted match
      }
      if (c == String_To_Find[currentChar])
      {
        if (String_To_Find[++currentChar] == 0)
        {
          return 2; // Found
        }
      }
      else
      {
        currentChar = 0;
      }
    }
  }
  return 0; // Timeout
}

void Internet_Browser_Class::Store_URL(char *local_url)
{
  byte i = 0;
  byte j = 0;
  if ((local_url[5] == '/') && (local_url[6] == '/'))
  {
    j = 6; // Strip leading http://

    local_url[i++] = TAG_HTTP;
  }
  else if ((local_url[6] == '/') && (local_url[7] == '/'))
  {
    j = 7; // Strip leading https://

    local_url[i++] = TAG_HTTP;
  }
  while (local_url[i] > 0)
  {
    i++;

    local_url[i] = local_url[i + j];
  }
  Cache_File.print(local_url);
}

void Internet_Browser_Class::Split_URL(char *localURL)
{
  byte i = 0;
  byte urlIndex = 0;
  byte hasDot = 0;
  byte hasSlash = 0;

  if (localURL[urlIndex] == TAG_HTTP)
  {
    urlIndex++;
    while ((localURL[urlIndex] > 0) && (localURL[urlIndex] != '/'))
    {
      Server[i++] = localURL[urlIndex++];
    }
    Server[urlIndex] = 0;
    Server[i] = 0;
    if (localURL[urlIndex] > 0)
    {
      i = 0;
      while ((localURL[urlIndex] > 0) && (i < 60))
        Path[i++] = localURL[urlIndex++];
      Path[i] = 0;
    }
    else
    {
      memcpy(Path, "/\0", 2);
    }
  }
  else if (localURL[urlIndex] == '/')
  { // URL starts with a slash
    while (localURL[urlIndex] > 0)
      Path[i++] = localURL[urlIndex++];
    localURL[urlIndex] = 0;
  }
  else
  { // URL is plain
    while (localURL[urlIndex] > 0)
    {
      if (localURL[urlIndex] == '.')
      {
        hasDot++;
      }
      if (localURL[urlIndex++] == '/')
      {
        hasSlash++;
      }
    }
    if (hasDot == 1)
    {
      Path[0] = '/';
      urlIndex = 0;
      i = 1;
      do
      {
        Path[i++] = localURL[urlIndex];
      } while (localURL[urlIndex++] > 0);
    }
    else if ((hasSlash > 0) && (hasDot > 1))
    {
      urlIndex = 0;
      i = 0;
      while ((localURL[urlIndex] > 0) && (localURL[urlIndex] != '/'))
      {
        Server[i++] = localURL[urlIndex++];
      }
      Server[urlIndex] = 0;
      i = 0;
      while (localURL[urlIndex] > 0)
        Path[i++] = localURL[urlIndex++];
      Path[i] = 0;
    }
    else
    {
      urlIndex = 0;
      i = 0;
      while (localURL[urlIndex] > 0)
      {
        Server[i++] = localURL[urlIndex++];
      }
      Server[urlIndex] = 0;
      memcpy(Path, "/\0", 2);
    }
  }
}