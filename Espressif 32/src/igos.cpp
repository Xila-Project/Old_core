#include "Arduino.h"
#include "igos.h"

iGOS_Class::iGOS_Class()
{
  memset(&server[0], 0, 30);
  memset(&path[0], 0, 60);
  memset(&url[0], 0, 90);

  server[0] = '*';

  //command = 6;

  pageLinks = {0, 0};

  textContent = {0, 0, false};

  lowestRAM = 2000;
}

iGOS_Class::~iGOS_Class()
{
}

byte iGOS_Class::cacheURL(char *URLserver, char *URLpath)
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

  //================================================
  // Open URL
  //================================================
  Nextion_Serial.println(F("fill 2,54,443,216,33808ÿÿÿ")); //clear screen

  Serial.print(F("\nOpening cache... "));
  Serial.print(CACHEFILE);
  if (!openCacheFile(false))
  { // Re-open read only cache file
    //error handle
    Serial.println(F("Cache open failed !"));
    return 0;
  }

  vTaskDelay(pdMS_TO_TICKS(100));
  Serial.println(F("\nConnecting ..."));
  Serial.println(URLserver);
  Serial.println(URLpath);

  if (URLserver[0] == '*') // Should never get an * here
  {
    Serial.println(F("Invalid URL !"));
    //error handle
    return 0;
  }
  else
  {
    freeRam();
  }
  if (client.connect(URLserver, 80)) // Connect to server and request HTML
  {
    client.print(F("GET "));
    client.print(URLpath);
    client.print(F(" HTTP/1.1\nHost: "));
    client.println(URLserver);
    client.println(F("User-Agent: Mozilla/4.0 (Mobile; PIP/7.0) PIP/7.0\nConnection: close\n\n"));
  }
  else
  {
    Serial.println(F("Connection failed !"));
    //error handle : reset ?
    return 0;
  }
  vTaskDelay(pdMS_TO_TICKS(500)); // Give the Ethernet shield a mo to get going
  if (!inputWait())
  {
    Serial.println(F("\nEthernet timeout"));
    //error handle
    return 0;
  }
  Serial.println(F("\nParsing..."));
  startTime = millis();
  {
    memcpy(generalBuffer, "HTTP/1.1 \0", 10);
    outputChar = findUntil(generalBuffer, true);
    if (outputChar == 2)
    {
      fileLength = client.parseInt();
      Serial.print(F("Result: "));
      Serial.println(fileLength);
      if (fileLength >= 300)
      {
        displayPage();
        return 0;
      }
    }
    memcpy(generalBuffer, "-Length: \0", 10);
    outputChar = findUntil(generalBuffer, true);
    Serial.print("\n");
    Serial.println(outputChar);
    if (outputChar == 2)
    {
      fileLength = client.parseInt();
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
    else if (outputChar == 1)
    {
      Serial.println(F("\nStopped by <, no file length found"));
      fileLength = 0;
    }
    else
    {
      Serial.println(F("\nTimeout finding file length"));
      fileLength = 0;
    }
    memcpy(generalBuffer, "<body\0", 7);
    outputChar = findUntil(generalBuffer, false);
    if (outputChar = 0)
    {
      Serial.println(F("\nTimeout finding <body>\nShould probably stop now"));
    }
    else
    {
      localState = sENDTAG;
    }
  }
  c = client.read();

  //================================================
  // Loading loop
  //================================================
  while (metaState < sFOOTER)
  {
    c = 0;
    if (client.available())
    {
      //      freeRam();
      c = client.read();
      downloadCount++;
    }
    else if (!inputWait())
    {
      client.stop();
      Serial.println(F(" DONE"));
      Temporary_File.sync();
      return 0;
    }
    nextState = localState;
    outputChar = c;
    if (metaState > sLEADIN)
    {
      Serial.print(F("|\n"));
      Serial.print(client.available());
      Serial.print(F("\t"));
      Serial.print(count);
      Serial.print(F("\tmS "));
      Serial.print(metaState);
      Serial.print(F("\tlS "));
      Serial.print(localState);
      Serial.print(F("\t"));
      if (lastChar > 31)
        Serial.write(lastChar);
      else
        Serial.print(lastChar, DEC);
      Serial.print(F("\t"));
      if (c > 31)
        Serial.write(c);
      else
        Serial.print(c, DEC);
      Serial.print(F("\t|"));
    }

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
        Serial.print(" OutputChar = ");
        Serial.println(hashOut(ampHash), DEC);

        if (metaState != sANCHOR)
        {
          outputChar = hashOut(ampHash);

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

    //================================================
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

        Serial.print(" end tag ");
        Serial.print(tagHash);

        nextState = sTEXT;

        if (tagHash == BODYTAGEND)
        {
          metaState = sFOOTER;
          continue;
        }

        if ((tagHash == SCRIPTTAGEND) || (tagHash == STYLETAGEND))
        {

          Serial.print(F(" SCRIPT/STYLE TAG end"));

          nextState = sTEXT;
          localState = sTEXT;
          metaState = sTEXT;
          continue;
        }
        if ((tagHash == SCRIPTTAG) || (tagHash == STYLETAG))
        {

          Serial.print(F(" SCRIPT/STYLE TAG start "));

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
        outputChar = hashOut(tagHash);
        if (c != '>')
          if (tagHash == 65)
            nextState = sSTUFF; // Is actually an <a tag
          else
            nextState = sENDTAG; // Tag not supported
        tagHash = 0;

        Serial.print(" Next state: ");
        Serial.print(nextState);
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
        storeURL(url);
        Temporary_File.write(TAG_LINK2);

        Serial.print(TAG_LINK2);
      }
      else
      {
        url[i++] = c;
        url[i] = 0;
        if (i > 130)
        {
          nextState = sENDTAG;
          Temporary_File.write(TAG_LINK2);

          Serial.print(TAG_LINK2);
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
      uint32_t speed = 0;

      tftLCD.setCursor(0, 7);
      tftLCD.print(downloadCount);
      tftLCD.print(F(" bytes downloaded @ "));
      speed = downloadCount / ((millis() - startTime) / 1000);
      tftLCD.print(speed);
      tftLCD.println(F(" bytes/sec       "));

      if (fileLength > 0)
      {
        uint32_t percent = 0;
        tftLCD.print(fileLength);
        tftLCD.println(F(" bytes file size   "));
        percent = downloadCount * 100 / fileLength;
        //        tftLCD.print (percent);
        //         tftLCD.println (F("% downloaded"));
        tftLCD.fillRect(0, 0, percent * tftLCD.WIDTH / 100, 8, GREEN);
      }

      tftLCD.print(count);
      tftLCD.println(F(" bytes stored   "));
    }

    // Handle tags with pre breaks
    if ((outputChar & PRE_BREAK))
    {
      Temporary_File.write(10);
      count++;
      Serial.write('%');
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
          Serial.print(cleanChar);
          Serial.print(F(" Set ' '"));
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
          /* (DEBUG1)
            Serial.print (F(" set 0\t"));
            Serial.print (lastChar);
            Serial.print (F("\t"));
            Serial.print (outputChar, DEC);
            #endif*/
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

        Serial.print('@');

        Temporary_File.write(10);
      }
      else if (cleanChar > 31)
      {
        if (metaState != sQUIET)
        {
          Temporary_File.write(cleanChar);

          Serial.write(cleanChar);
        }
      }
      else
      {
        Temporary_File.write(cleanChar);
        count++;

        Serial.print(cleanChar, DEC);
      }
      lastChar = cleanChar;
    }
    else if (outputChar & PRE_BREAK)
      lastChar = TAG_CR;

    // Handle tags with pre breaks
    if ((outputChar & POST_BREAK) && (lastChar != TAG_CR))
    {
      Temporary_File.write(10);
      count++;

      Serial.print('#');

      lastChar = TAG_CR;
    }

    localState = nextState;
  } // Loading loop

  Temporary_File.print('\0');
  client.flush();
  client.stop();

  tftLCD.println();
  tftLCD.print(count);
  tftLCD.print(F(" bytes"));

  Temporary_File.close();

  Serial.print(F("\nCount: "));
  Serial.println(count, DEC);
  freeRam();

  return count;
}

void iGOS_Class::Get_Page()
{
  Serial.print(F("\n>> Button Clicked: "));
  buildURL(pageLinks.index[pageLinks.linkPtr]); // Get URL from page index
  Serial.print(F("Built url: "));
  Serial.println(url);
  splitURL(url);
  Serial.print(F("Split url: "));
  Serial.print(server);
  Serial.print(F(" + "));
  Serial.println(path);
  if (url[0] != '*') // Load default home page
  {
    pageLinks.linkPtr = 0;
    pageLinks.lastLink = 0;
    textContent.pagePtr = 0;
    textContent.lastPage = 0;
    Serial.print(F("Loading URL: "));
    Serial.print(server);
    Serial.println(path);
    Load_Page();
  }
  else
  {               // Something stuffed up
    command = 10; // Command = 5;
    Temporary_File.sync();
    Serial.println("No URL");
  }
}

void iGOS_Class::Page_Up()
{
  Serial.print(F("\n>> Command 1: "));
  if (textContent.pagePtr > 0)
  {
    textContent.pagePtr--;
    command = 6;
    pageLinks.lastLink = 0;
    Serial.print(F("Page up to page "));
    Serial.println(textContent.pagePtr);
    pageLinks.linkPtr = 0;
  }
  else
  { // Can't got up any further
    command = 10;
    Serial.println(F("Cancelled"));
  }
  return;
}

void iGOS_Class::Page_Down()
{
  Serial.print(F("\n>> Command 2: "));
  if (textContent.pagePtr < textContent.lastPage)
  {
    textContent.pagePtr++;
  }
  else
  {
    textContent.pagePtr = 0; // Reset to top
  }
  command = 6;
  pageLinks.linkPtr = 0;
  pageLinks.lastLink = 0;
  Serial.print(F("Page down to page "));
  Serial.println(textContent.pagePtr);
  return;
}

void iGOS_Class::Next_Link()
{
  Serial.print(F("\n>> Command 3: Next link: "));
  if (pageLinks.linkPtr < pageLinks.lastLink)
  {
    pageLinks.linkPtr++;
    command = 6;
    Serial.print(F("Increased link to "));
    Serial.println(pageLinks.linkPtr);
  }
  else
  {
    pageLinks.linkPtr = 0;
    command = 6;
    Serial.print(F("Reset link to "));
    Serial.println(pageLinks.linkPtr);
  }
  return;
}

void iGOS_Class::Previous_Link()
{
  Serial.print(F("\n>> Command 4: Previous link: "));
  if (pageLinks.linkPtr > 0)
  {
    pageLinks.linkPtr--;
    command = 6;
    Serial.print(F("Decreased link to "));
    Serial.println(pageLinks.linkPtr);
  }
  else
  {
    pageLinks.linkPtr = pageLinks.lastLink;
    command = 6;
    Serial.print(F("Reset link to "));
    Serial.println(pageLinks.linkPtr);
  }
  return;
}

void iGOS_Class::Load_Page()
{
  Serial.println(F("\n>> Command 5: Load & cache URL"));
  Temporary_File.sync();
  Temporary_File.close(); // Close read only cache file
  splitURL(url);
  if (cacheURL(server, path)) // Download and cache URL
  {
    pageLinks.lastLink = 0;
    pageLinks.linkPtr = 0;
    command = 6;
    //printCache();
  }
  else
  {
    Temporary_File.close();
    client.stop();
    tftLCD.println(F("\nDownload & caching failed"));
    memcpy(server, "*\0", 2);
    memcpy(path, '\0', 1);
    memcpy(url, '\0', 1);
    pageLinks.lastLink = 0;
    openCacheFile(true);
    command = 6;
    Serial.println("Download & caching failed");
    //      tftLCD.println (F("Press button to continue"));
    //     while (digitalRead (A2) != 0) ;
    //     command = 11;
    break;
  }
  if (!openCacheFile(true)) // Re-open read only cache file
  {
    tftLCD.println(F("Cache open failed"));
    memcpy(server, "*\0", 2);
  }
  else
  {
    pageLinks.lastLink = 0;
    command = 6;
  }
  return;
}

void iGOS_Class::buildURL(uint16_t pointer)
{
  byte i = 0;
  char c = 0;
  uint16_t oldPos = Temporary_File.position();

  if (!Temporary_File.seek(pointer))
  {
    Serial.println(F("Seek failure"));
    return;
  }
  c = Temporary_File.read();
  while (c != TAG_LINK2)
  {
    url[i++] = c;
    c = Temporary_File.read();
  }
  url[i] = 0;
  Temporary_File.seek(oldPos);
  freeRam();
}

void iGOS_Class::displayLinkIndex()
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
    Temporary_File.seek(pageLinks.index[i]);
    byte c = 0, j = 0;
    c = Temporary_File.read();
    while ((c != TAG_LINK2) && (j++ < 100))
    {
      Serial.write(c);
      c = Temporary_File.read();
    }
    Serial.println();
  }
  Serial.println();
  freeRam();
}

void iGOS_Class::displayPageIndex()
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
  freeRam();
}

uint8_t iGOS_Class::printCache()
{
  int16_t c;
  uint16_t count = 0;

  if (!Temporary_File)
  {
    Serial.println(F(" failed, not open"));
    return 0;
  }
  Temporary_File.seek(0);

  Serial.print(F("\nFile size: "));
  Serial.println(Temporary_File.size());

  while ((c = Temporary_File.read()) > 0)
  {
    Serial.print(count++);
    Serial.print(F("\t"));
    if (c > 31)
    {
      Serial.write((char)c);
      Serial.println();
    }
    else
    {
      Serial.print("*");
      Serial.println(c);
    }
  }

  Serial.println(F("\nDone"));

  freeRam();
}

byte iGOS_Class::displayPage()
{
  Serial.print(F("Display cached page :"));
  Serial.println(textContent.pagePtr);

  uint16_t filePtr = textContent.index[textContent.pagePtr]; // Pointer into cached file
  uint8_t c = 1;                                             // Input character
  uint16_t count = 0;                                        // Character count for page index building
  uint16_t colourStack = WHITE;                              // One level stack to remember colour state
  boolean invisiblePrint = false;                            // Turn off output (for URLs, etc)
  uint8_t currentLink = 0;                                   // Curretly highlightd link of the page
  boolean buildingIndex = (pageLinks.lastLink == 0);         // True if this page's URL haven't been index yet

  // Draw header
  tftLCD.fillRect(0, 0, tftLCD.WIDTH, 8, GREY);
  tftLCD.setCursor(0, 0);
  tftLCD.setBGColour(GREY);
  tftLCD.setTextColour(BLACK);
  if (server[0] == '*')
    tftLCD.println(F("Home page"));
  else
    tftLCD.println(url);

  if (!Temporary_File.seek(filePtr))
  {
    tftLCD.println(F("Seek failture"));
    return 0;
  }

  freeRam();
  Serial.print(F("SD File position is: "));
  Serial.println(Temporary_File.position());
  if (buildingIndex)
    Serial.println(F("Building link index"));

  tftLCD.setCursor(0, 1);
  tftLCD.setBGColour(BLACK);
  tftLCD.setTextColour(WHITE);

  // Loop through cache file
  while ((filePtr <= Temporary_File.size()) && (tftLCD.getCursorY() < tftLCD.HEIGHT - 1) && (c != 0))
  {
    c = Temporary_File.read();
    filePtr++;
    count++;

    // Print only visible ASCII characters
    if (c > 31)
    {
      if (!invisiblePrint)
      { // Print only if in visible mode (supresses URLs)
        tftLCD.write(c);

        Serial.write(c);
      }
      else
      {

        //  Serial.print (F("_"));

        ;
      }
    }

    // Handle display codes
    else
    {
      switch (c)
      {
      case TAG_CR:
      case 10:
        // Fill the rest of the current line with black to erase the previous contents
        tftLCD.fillRect(tftLCD.getCursorX(), tftLCD.getCursorY(), tftLCD.WIDTH - tftLCD.getCursorX(), 8, BLACK);
        tftLCD.write(10);

        Serial.println();

        invisiblePrint = false;
        break;
      case 13:
        // Only doing a CR/LF on ASCII 10
        break;

        // Start of a header tag
      case TAG_HEADING1:
        colourStack = tftLCD.getTextColour(); // Store the colour state
        tftLCD.setTextColour(COL_HEADING);
        break;

        // Start of a bold tag
      case TAG_BOLD1:
        colourStack = tftLCD.getTextColour();
        tftLCD.setTextColour(COL_BOLD);
        break;

        // Start of an anchor tag. The actual URL follows
      case TAG_LINK1:
        invisiblePrint = true; // Turn off printing while the URL is loading
        if ((buildingIndex) && (currentLink < LINKINDEXSIZE))
        {
          pageLinks.index[currentLink] = filePtr;
          pageLinks.lastLink++;
        }
        break;

        // End of the URL part. Start of the anchor texyt
      case TAG_LINK2:
        colourStack = tftLCD.getTextColour();
        if (currentLink == pageLinks.linkPtr)
        { // Print inverse colours for the active link
          tftLCD.setTextColour(BLACK);
          tftLCD.setBGColour(COL_LINK);
        }
        else
          tftLCD.setTextColour(COL_LINK);
        invisiblePrint = false; // Turn on printing again
        break;

        // End of the anchor tag
      case TAG_LINK3:
        if (currentLink < LINKINDEXSIZE)
          currentLink++; // Removed && buildingLink
        tftLCD.setTextColour(colourStack);
        tftLCD.setBGColour(BLACK);
        colourStack = WHITE;
        break;

        // End of header or bold tags
      case TAG_HEADING2:
      case TAG_BOLD2:
        tftLCD.setTextColour(colourStack);
        break;

        // List entry tag
      case TAG_LIST:
        tftLCD.write(127);
        break;

        // Horizontal rule tag
      case TAG_HR:
        tftLCD.fillRect(8, tftLCD.getCursorY(), tftLCD.WIDTH - 16, 1, GREY);

        Serial.println(F("------"));
        Serial.println(tftLCD.getCursorX());
        Serial.println(tftLCD.getCursorY());

      default:
        break;
      }
    }
  }
  tftLCD.println();

  // Fill the rest of the screen under the last line with black
  tftLCD.fillRect(0, tftLCD.getCursorY(), tftLCD.WIDTH, tftLCD.HEIGHT - tftLCD.getCursorY() - 8, BLACK);

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
  if (filePtr++ < Temporary_File.size())
  {
    Serial.println(F("filePtr++ < SDFile.size"));
  }
  // Update page index
  if ((textContent.pagePtr == textContent.lastPage) && (textContent.pagePtr < PAGEINDEXSIZE) && (filePtr++ < Temporary_File.size()))
  {
    textContent.lastPage++;
    textContent.index[textContent.lastPage] = filePtr - 2; //textContent.index[textContent.lastPage] + count;
  }

  // Update last link pointer
  if ((buildingIndex) && (pageLinks.lastLink > 0))
  {
    pageLinks.lastLink--;
  }
  displayPageIndex();
  displayLinkIndex();

  Serial.print(F("Char count:\t"));
  Serial.println(count);
  Serial.print(F("filePtr:\t"));
  Serial.println(filePtr);
  Serial.print(F("SD size:\t"));
  Serial.println(Temporary_File.size());
  Serial.print(F("======"));

  // Draw RAM use and page position in header
  tftLCD.setCursor(43, 0);
  tftLCD.setBGColour(GREY);
  tftLCD.setTextColour(BLACK);
  tftLCD.print(lowestRAM);
  tftLCD.setCursor(46, 0);
  tftLCD.print(F(" p"));
  tftLCD.print(textContent.pagePtr + 1);
  tftLCD.print(F("/"));
  tftLCD.println(textContent.lastPage + 1);
  return 1;
}

char iGOS_Class::lowerCase(char c)
{
  if((c > 64) && (c < 91))
  {
    return c += 32;
  }
  else
  {
    return c;
  }
}

uint16_t iGOS_Class::hashOut(uint16_t hash)
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

byte iGOS_Class::findUntil(uint8_t *string, boolean terminate)
{
  char currentChar = 0;
  long timeOut = millis() + 5000;
  char c = 0;
  Serial.print(F("\nLooking for: "));

  for (byte i = 0; string[i] != 0; i++)
  {
    Serial.write(string[i]);
  }
  Serial.println('\n');

  while (millis() < timeOut)
  {
    if (client.available())
    {
      timeOut = millis() + 5000;
      c = client.read();
      if (terminate && (c == '<'))
      {
        return 1; // Pre-empted match
      }
      Serial.write(c);
      if (c == string[currentChar])
      {
        if (string[++currentChar] == 0)
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

boolean iGOS_Class::inputWait()
{
  byte wait = 0;
  long timeOut = millis() + 9000; // Allow 5 seconds of no data
  Serial.println();
  while ((millis() < timeOut) && (!client.available()))
  {
    Serial.print(" ");
    Serial.print(wait * 100);
    delay(++wait * 100);
  }
  if ((!client.available()) && (!client.connected()))
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void iGOS_Class::storeURL(char *local_url)
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
    local_url[i++] = local_url[i + j];
  }
  Serial.print(local_url);
  Serial.print(F("|"));
  Temporary_File.print(local_url);
  freeRam();
}

void iGOS_Class::splitURL(char *localURL)
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
      server[i++] = localURL[urlIndex++];
    }
    server[urlIndex] = 0;
    server[i] = 0;
    if (localURL[urlIndex] > 0)
    {
      i = 0;
      while ((localURL[urlIndex] > 0) && (i < 60))
        path[i++] = localURL[urlIndex++];
      path[i] = 0;
    }
    else
    {
      memcpy(path, "/\0", 2);
    }
  }
  else if (localURL[urlIndex] == '/')
  { // URL starts with a slash
    while (localURL[urlIndex] > 0)
      path[i++] = localURL[urlIndex++];
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
      path[0] = '/';
      urlIndex = 0;
      i = 1;
      do
      {
        path[i++] = localURL[urlIndex];
      } while (localURL[urlIndex++] > 0);
    }
    else if ((hasSlash > 0) && (hasDot > 1))
    {
      urlIndex = 0;
      i = 0;
      while ((localURL[urlIndex] > 0) && (localURL[urlIndex] != '/'))
        server[i++] = localURL[urlIndex++];
      server[urlIndex] = 0;
      i = 0;
      while (localURL[urlIndex] > 0)
        path[i++] = localURL[urlIndex++];
      path[i] = 0;
    }
    else
    {
      urlIndex = 0;
      i = 0;
      while (localURL[urlIndex] > 0)
        server[i++] = localURL[urlIndex++];
      server[urlIndex] = 0;
      memcpy(path, "/\0", 2);
    }
  }
  Serial.print(F("URL: "));
  Serial.println(server);
  Serial.println(path);
  freeRam();
}

uint8_t iGOS_Class::openCacheFile(boolean readOnly)
{
  char cacheFile[10];
  if (server[0] == '*')
  {
    memcpy(cacheFile, HOMEPAGE, sizeof(HOMEPAGE));
  }
  else
  {
    memcpy(cacheFile, CACHEFILE, sizeof(CACHEFILE));
  }
  Serial.print(F("Opening cache... "));
  Serial.println(cacheFile);
  if(readOnly)
  {
    Temporary_File = SD.open(cacheFile, FILE_READ);
  }
  else
  {
  Temporary_File = SD.open(cacheFile, FILE_WRITE);
  }
  if (!Temporary_File)
  {
    Serial.println(F("Failed on open"));
    //error to handle
    return 0;
  }
  return 1;
}

void freeRam() {
  Serial.print(F("Free Heap :"));
  Serial.print(ESP.getFreeHeap());
  Serial.println();
}