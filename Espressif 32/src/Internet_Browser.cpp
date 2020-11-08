#include "Internet_Browser.hpp"

Internet_Browser_Class *Internet_Browser_Class::Instance_Pointer = NULL;

Software_Class *Internet_Browser_Class::Load()
{
  if (Instance_Pointer == NULL)
  {
    Instance_Pointer = new Internet_Browser_Class;
  }
  return Instance_Pointer;
}

Internet_Browser_Class::Internet_Browser_Class() : Software_Class(5)
{
  memset(Server, 0, 30);
  memset(Path, 0, 60);
  memset(URL, 0, 90);

  Server[0] = '*';

  pageLinks = {0, 0};

  textContent = {0, 0, false};

  xTaskCreatePinnedToCore(Main_Task, "Internet_Browser", 8192, NULL, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE);
  Execute(Software_Code::Maximize);
}

Internet_Browser_Class::~Internet_Browser_Class()
{
  Instance_Pointer = NULL;
}

void Internet_Browser_Class::Set_Variable(const void *Variable, uint8_t Type, uint8_t Adress, uint8_t Size)
{
  if (Adress == 'U')
  {
    strcpy(URL, (char *)Variable);
  }
}

void Internet_Browser_Class::Main_Task(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    switch (Instance_Pointer->Get_Command())
    {
    case 0:
      vTaskDelay(pdMS_TO_TICKS(20));
      //Idle : nothing to do
      break;
    case Software_Code::Maximize: // NULL + M : Maximize
      GalaxOS.Display.Set_Current_Page(F("Internet_Brow"));
      Instance_Pointer->Go_Home();
      //do something when
      break;
    case Software_Code::Minimize: // NULL + m : Minimize
      vTaskSuspend(NULL);
      break;
    case Software_Code::Close: // NULL + C : Close
      delete Instance_Pointer;
      vTaskDelete(NULL);
      break;
    case 0x4E4C: //NL
      Instance_Pointer->Next_Link();
      break;
    case 0x5044: //PD
      Instance_Pointer->Page_Down();
      break;
    case 0x504C: //PL
      Instance_Pointer->Previous_Link();
      break;
    case 0x5055: //PU
      Instance_Pointer->Page_Up();
      break;
    case 0x474C: //GL
      Instance_Pointer->Go_Link();
      break;
    case 0x4755: //GU
      Instance_Pointer->Go_URL();
      break;
    case 0x484F: //HO
      Instance_Pointer->Go_Home();
      break;
    default:
      Serial.println(F("Unknow Socket Method ! "));
      //error handle
      break;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

void Internet_Browser_Class::Go_Home()
{
  Serial.println(F("Go Home"));
  memset(Server, 0, 30);
  memset(Path, 0, 60);
  memset(URL, 0, 90);
  Server[0] = '*';
  Server[1] = '\0';
  URL[0] = '*';
  URL[1] = '\0';
  if (!Display_Page())
  {
    Serial.println(F("Display Cache Failed !"));
  }
  Cache_File.flush();
}

void Internet_Browser_Class::Go_URL()
{
  Split_URL(URL);
  if (Cache_URL(Server, Path))
  {
    Serial.println(F("Succed to cache URL"));
    pageLinks.lastLink = 0;
    pageLinks.linkPtr = 0;
  }
  else
  {
    Cache_File.close();
    Client.stop();
    Serial.println(F("Download & Caching Failed !"));
    memset(Server, '\0', sizeof(Server));
    Server[0] = '*';
    memset(Path, '\0', sizeof(Path));
    memset(URL, '\0', sizeof(URL));
    pageLinks.lastLink = 0;
    return;
  }
  if (!Display_Page())
  {
    Serial.println(F("Display Cache Failed !"));
  }
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
  uint32_t startTime = 0;
  uint32_t HTTP_Return_Code = 0;

  //================================================
  // Open URL
  //================================================
  GalaxOS.Display.Draw_Rectangle(2, 54, 443, 216, 16904, false);

  Serial.print(F("\nOpening cache... "));

  Cache_File = GalaxOS.Drive->open("/SOFTWARE/IGOS/CACHE.GDF", FILE_WRITE);
  if (!Cache_File)
  {
    Serial.println(F("Cache open failed !"));
    return 0;
  }

  vTaskDelay(pdMS_TO_TICKS(100));
  Serial.println(F("\nConnecting ..."));
  Serial.println(URLserver);
  Serial.println(URLpath);

  if (WiFi.status() != WL_CONNECTED)
  {
    GalaxOS.Event_Handler(F("WiFi not connected."), GalaxOS.Error);
    //error handle : not connected
    return 0;
  }

  if (URLserver[0] == '*') // Should never get an * here
  {
    Serial.println(F("Invalid URL !"));
    //error handle
    return 0;
  }

  if (Client.connect(URLserver, 80))
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
    Serial.println(F("Connection failed !"));
    //error handle : reset ?
    return 0;
  }
  vTaskDelay(pdMS_TO_TICKS(500));

  byte Wait = 0;
  while ((Wait < 100) && (!Client.available())) //wait 5 sec unti timeout
  {
    vTaskDelay(pdMS_TO_TICKS(50));
    Wait++;
  }
  if ((!Client.available()) && (!Client.connected()))
  {
    //error handle
    Serial.println(F("\nWiFi timeout"));
    return 0;
  }

  Serial.println(F("\nParsing..."));
  startTime = millis();

  {
    memcpy(generalBuffer, "HTTP/1.1 \0", 10); //looking for the HTTP return code
    outputChar = Find_Until(generalBuffer, true);
    if (outputChar == 2)
    {
      HTTP_Return_Code = Client.parseInt();
      Serial.print(F("Result: "));
      Serial.println(HTTP_Return_Code);
      if (HTTP_Return_Code >= 308) // stop parsing if http code isn't between 200 and 300
      {
        Display_Page(); //display current
        return 0;
      }
    }
    memcpy(generalBuffer, "-Length: \0", 10); //looking for the content length
    outputChar = Find_Until(generalBuffer, true);
    Serial.print("\n"); //new line
    Serial.println(outputChar);
    if (outputChar == 2)
    {
      fileLength = Client.parseInt();
      if (fileLength < 10)
      {
        fileLength = 0;
      }
      if (fileLength > 0)
      {
        Serial.print(F("File length: "));
        Serial.println(fileLength);
      }
    }
    else if (outputChar == 1) //cannot find the file lenght, stop
    {
      Serial.println(F("\nStopped by <, no file length found"));
      fileLength = 0;
    }
    else
    {
      Serial.println(F("\nTimeout finding file length"));
      fileLength = 0;
    }

    //to do : write code to find header

    memcpy(generalBuffer, "<body\0", 7); //search the first marker
    outputChar = Find_Until(generalBuffer, false);
    if (outputChar == 0) //cannot find the body
    {
      Serial.println(F("\nTimeout finding <body>\nShould probably stop now"));
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
        vTaskDelay(pdMS_TO_TICKS(50));
      }
      if ((!Client.available()) && (!Client.connected()))
      {
        //error handle
        Serial.println(F("\nWiFi timeout"));
        Client.stop();
        Cache_File.flush();
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
        url[i++] = c;
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

    //==============================f==================
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
        if (i > 130)
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
      //uint32_t speed = downloadCount / ((millis() - startTime) / 1000); deleted because make esp32 crash (divide by zero)

      if (fileLength > 0)
      {
        //uint8_t Percent = uint8_t(downloadCount * 100 / fileLength);
        //Serial.println(Percent);
        /*Nextion_Serial.print(F("LOAD_BAR.val="));
        Nextion_Serial.print(Percent);
        Nextion_Serial.print(F("\xFF\xFF\xFF"));*/
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

  Serial.println(F("Finish parsing"));

  Cache_File.print('\0');
  //Client.flush();
  Client.stop();

  Cache_File.flush();

  Serial.print(F("\nCount: "));
  Serial.println(count, DEC);

  //Nextion_Serial.print(F("LOAD_BAR.val=0\xFF\xFF\xFF"));

  return 1;
}

void Internet_Browser_Class::Go_Link()
{
  Serial.println(F("\n>> Go Link :"));
  Build_URL(pageLinks.index[pageLinks.linkPtr]); // Get URL from page index
  Serial.print(F("Built url: "));
  Serial.println(URL);
  Split_URL(URL);
  Serial.print(F("Split url: "));
  Serial.print(Server);
  Serial.print(F(" + "));
  Serial.println(Path);
  if (URL[0] != '*') // Load default home page
  {
    pageLinks.linkPtr = 0;
    pageLinks.lastLink = 0;
    textContent.pagePtr = 0;
    textContent.lastPage = 0;
    Serial.print(F("Loading URL: "));
    Serial.print(Server);
    Serial.println(Path);
    Load_Page();
  }
  else // Something stuffed up
  {
    Cache_File.flush();
    Serial.println("No URL");
    return;
  }
}

void Internet_Browser_Class::Page_Up()
{
  Serial.print(F("\n>> Page Up : "));
  if (textContent.pagePtr > 0)
  {
    textContent.pagePtr--;
    pageLinks.lastLink = 0;
    Serial.print(F("Page up to page "));
    Serial.println(textContent.pagePtr);
    pageLinks.linkPtr = 0;
    Display_Page();
  }
  else
  { // Can't got up any further
    Serial.println(F("Cancelled"));
  }
  return;
}

void Internet_Browser_Class::Page_Down()
{
  Serial.print(F("\n>> Page Down : "));
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
  Serial.print(F("Page down to page "));
  Serial.println(textContent.pagePtr);
  Display_Page();
  return;
}

void Internet_Browser_Class::Next_Link()
{
  Serial.print(F("\n>> Next Link : "));
  if (pageLinks.linkPtr < pageLinks.lastLink)
  {
    pageLinks.linkPtr++;
    Serial.print(F("Increased link to "));
    Serial.println(pageLinks.linkPtr);
  }
  else
  {
    pageLinks.linkPtr = 0;
    Serial.print(F("Reset link to "));
    Serial.println(pageLinks.linkPtr);
  }
  Display_Page();
  return;
}

void Internet_Browser_Class::Previous_Link()
{
  Serial.print(F("\n>> Previous link : "));
  if (pageLinks.linkPtr > 0)
  {
    pageLinks.linkPtr--;
    Serial.print(F("Decreased link to "));
    Serial.println(pageLinks.linkPtr);
  }
  else
  {
    pageLinks.linkPtr = pageLinks.lastLink;
    Serial.print(F("Reset link to "));
    Serial.println(pageLinks.linkPtr);
  }
  Display_Page();
  return;
}

void Internet_Browser_Class::Load_Page()
{
  Serial.println(F("\n|| Cache & display URL"));
  Cache_File.flush();
  Cache_File.close(); // Close read only cache file
  Split_URL(URL);
  if (Cache_URL(Server, Path)) // Download and cache URL
  {
    Serial.println(F("Succed to cache URL"));
    pageLinks.lastLink = 0;
    pageLinks.linkPtr = 0;
  }
  else
  {
    Cache_File.close();
    Client.stop();
    memset(Server, '\0', sizeof(Server));
    memset(Path, '\0', sizeof(Path));
    memset(URL, '\0', sizeof(URL));
    Server[0] = '*';

    pageLinks.lastLink = 0;

    Serial.println(F("Download & caching failed"));
    //error handle
  }

  pageLinks.lastLink = 0;
  Display_Page();

  return;
}

void Internet_Browser_Class::Build_URL(uint16_t pointer)
{
  byte i = 0;
  char c = 0;
  uint16_t oldPos = Cache_File.position();

  if (!Cache_File.seek(pointer))
  {
    Serial.println(F("Seek failure"));
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
  Serial.print(F("\nLink index:"));
  Serial.print(F("\nlinkPtr:\t"));
  Serial.println(pageLinks.linkPtr);
  Serial.print(F("lastLink:\t"));
  Serial.println(pageLinks.lastLink);
  if (pageLinks.lastLink == 0)
    return;
  Serial.println(F("Link Index"));
  for (byte i = 0; i <= pageLinks.lastLink; i++)
  {
    Serial.print(i);
    Serial.print(F("\t"));
    Serial.print(pageLinks.index[i]);
    Serial.print(F("\t"));
    Cache_File.seek(pageLinks.index[i]);
    byte c = 0, j = 0;
    c = Cache_File.read();
    while ((c != TAG_LINK2) && (j++ < 100))
    {
      Serial.write(c);
      c = Cache_File.read();
    }
    Serial.println();
  }
  Serial.println();
}

void Internet_Browser_Class::displayPageIndex()
{
  Serial.print(F("\nPage index:"));
  Serial.print(F("\npagePtr:\t"));
  Serial.println(textContent.pagePtr);
  Serial.print(F("lastPage:\t"));
  Serial.println(textContent.lastPage);
  Serial.println(F("Page Index"));

  for (byte i = 0; i <= textContent.lastPage; i++)
  {
    Serial.print(i);
    Serial.print(F("\t"));
    Serial.println(textContent.index[i]);
  }
  Serial.println();
}

byte Internet_Browser_Class::Display_Page()
{
  Serial.println();
  Serial.print(F("Display cached page :"));
  Serial.println(textContent.pagePtr);

  GalaxOS.Display.Hide(F("LOAD_BAR"));
  GalaxOS.Display.Hide(F("LOAD_TXT"));

  uint16_t filePtr = textContent.index[textContent.pagePtr]; // Pointer into cached file
  uint8_t c = 1;                                             // Input character
  uint16_t count = 0;                                        // Character count for page index building
  uint16_t Last_Color = 65535;                               // Two level stack to remember colour state
  uint16_t Current_Color = 65535;

  boolean invisiblePrint = false;                    // Turn off output (for URLs, etc)
  uint8_t currentLink = 0;                           // Curretly highlightd link of the page
  boolean buildingIndex = (pageLinks.lastLink == 0); // True if this page's URL haven't been index yet
  uint16_t Cursor_Y;
  uint16_t Cursor_X;
  char Text_To_Print[80];
  uint16_t Width_Count;
  uint8_t Text_Char_Count;

  GalaxOS.Display.Draw_Rectangle(0, 50, 464, 222, 16904, false);

  //Draw header

  if (Server[0] == '*')
  {
    GalaxOS.Display.Set_Text(F("URL_TXT"), F("Home Page"));
    Cache_File = GalaxOS.Drive->open("/SOFTWARE/IGOS/HOMEPAGE.GDF", FILE_READ);
  }
  else
  {
    GalaxOS.Display.Set_Text("URL_TXT", URL);
    Cache_File = GalaxOS.Drive->open("/SOFTWARE/IGOS/CACHE.GDF", FILE_READ);
  }

  if (!Cache_File)
  {
    Serial.println(F("Failed to open cache !"));
    memcpy(Server, "*\0", 2);
    return 0;
  }

  if (!Cache_File.seek(filePtr))
  {
    //error handle
    Serial.println(F("Seek failture"));
    return 0;
  }

  Serial.print(F("SD File position is: "));
  Serial.println(Cache_File.position());

  if (buildingIndex)
  {
    Serial.println(F("Building link index"));
  }

  Cursor_Y = 50;

  memset(Text_To_Print, '\0', sizeof(Text_To_Print));

  Text_Char_Count = 0;
  Width_Count = 0;

  // Loop through cache fizle
  while ((filePtr <= Cache_File.size()) && (Cursor_Y < 272 - 1) && (c != 0))
  {
    if (Width_Count >= 449) //print if auto return to line (max 56 normal)
    {
      Text_To_Print[Text_Char_Count] = '\0';
      switch (Current_Color)
      {
      case 65534: //Bold style
        GalaxOS.Display.Draw_Text(4, Cursor_Y, 456, 14, 1, 65535, 16904, 0, 1, 1, Text_To_Print);

        Current_Color = Last_Color;
        break;

      case 65533: //Highlight style
        GalaxOS.Display.Draw_Text(4, Cursor_Y, 456, 14, 0, 34308, 16904, 0, 1, 1, Text_To_Print);

        Current_Color = Last_Color;
        Last_Color = 65535;
        break;

      case 65532: //Link style
        GalaxOS.Display.Draw_Text(4, Cursor_Y, 456, 14, 0, 1300, 16904, 0, 1, 1, Text_To_Print);
        Current_Color = Last_Color;
        Last_Color = 65535;
        break;

      case 65531: //Heading style
        GalaxOS.Display.Draw_Text(4, Cursor_Y, 456, 14, 0, 64896, 16904, 0, 1, 1, Text_To_Print);
        Current_Color = Last_Color;
        break;

      default:
        GalaxOS.Display.Draw_Text(4, Cursor_Y, 456, 14, 0, Current_Color, 16904, 0, 1, 1, Text_To_Print);
        break;
      }

      Cursor_Y += 14; //new line
      Text_Char_Count = 0;
      Width_Count = 0;
      vTaskDelay(pdMS_TO_TICKS(250));
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
        Text_To_Print[Text_Char_Count] = c;
        if (c < 0x5B) // maj size
        {
          Width_Count += 8; // 8 px char
        }
        else
        {
          Width_Count += 7;
        }
        Text_Char_Count++;
      }
    }

    // Handle display codes
    else
    {
      switch (c)
      {
      case TAG_CR:

      case 10: // Print rest of buffer and return to line
        Width_Count = 65535;
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
        invisiblePrint = true; // Turn off printing while the URL is loading

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
        invisiblePrint = false; // Turn on printing again

        break;

      case TAG_LINK3: // End of the anchor tag
        if (currentLink < LINKINDEXSIZE)
        {
          currentLink++; // Removed && buildingLink
        }
        Width_Count = 65535;
        break;

      case TAG_HEADING2: // End of header or bold tags
        Width_Count = 65535;
        break;

      case TAG_BOLD2:
        Width_Count = 65535;
        break;

        // List entry tag
      case TAG_LIST:
        //tftLCD.write(127); print del char ???
        break;

        // Horizontal rule tag
      case TAG_HR:
        GalaxOS.Display.Draw_Rectangle(32, Cursor_Y + 6, 400, 2, 65535, false);
        Cursor_Y += 14;
        break;

      default:
        break;
      }
    }
  }

  Serial.print(F("\nCurrent page: "));
  Serial.println(textContent.pagePtr);

  Serial.print(F("Character count: "));
  Serial.print(count);

  if (textContent.pagePtr == textContent.lastPage)
  {
    Serial.println(F("pagePtr == lastPage"));
  }
  else
  {
    Serial.println(F("pagePtr < lastPage"));
  }
  if (textContent.pagePtr < PAGEINDEXSIZE)
  {
    Serial.println(F("pagePtr < PAGEINDEXSIZE"));
  }
  if (filePtr++ < Cache_File.size())
  {
    Serial.println(F("filePtr++ < SDFile.size"));
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

  //displayPageIndex();
  //displayLinkIndex();

  Serial.print(F("Char count:\t"));
  Serial.println(count);
  Serial.print(F("filePtr:\t"));
  Serial.println(filePtr);
  Serial.print(F("SD size:\t"));
  Serial.println(Cache_File.size());

  Cache_File.flush();

  // Draw RAM use and page position in header
  /*tftLCD.setCursor(43, 0);
  tftLCD.setBGColour(GREY);
  tftLCD.setTextColour(BLACK);
  tftLCD.print(lowestRAM);
  tftLCD.setCursor(46, 0);
  tftLCD.print(F(" p"));
  tftLCD.print(textContent.pagePtr + 1);
  tftLCD.print(F("/"));
  tftLCD.println(textContent.lastPage + 1);*/
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
  long timeOut = millis() + 5000;
  char c = 0;
  Serial.print(F("\nLooking for: "));

  for (byte i = 0; String_To_Find[i] != 0; i++)
  {
    Serial.write(String_To_Find[i]);
  }
  Serial.println('\n');

  while (millis() < timeOut)
  {
    if (Client.available())
    {
      timeOut = millis() + 5000;
      c = Client.read();
      if (terminate && (c == '<'))
      {
        return 1; // Pre-empted match
      }
      Serial.write(c);
      if (c == String_To_Find[currentChar])
      {
        if (String_To_Find[++currentChar] == 0)
        {
          Serial.println(F("[FOUND]"));
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
  Serial.print(F("\nURL to Split: "));
  Serial.println(localURL);
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
    Serial.print(F("Dots:"));
    Serial.println(hasDot);
    Serial.print(F("Slashes:"));
    Serial.println(hasSlash);
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
  Serial.print(F("URL: "));
  Serial.println(Server);
  Serial.println(Path);
}
