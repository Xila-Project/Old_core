#ifndef IGOS_H_INCLUDED
#define IGOS_H_INCLUDED

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "WiFi.h"
#include "galaxos.h"

#define CACHEFILE      "CACHE.HTM"              // Cached HTML filename
#define HOMEPAGE       "HOME.HTM"               // First load homepage name
#define PAGEINDEXSIZE  10                       // Must small - each page uses 3 bytes
#define LINKINDEXSIZE  20                       // Must small - each link uses 2 bytes 
#define TIMEOUT        5000                     // Timeout on ethernet reads

// Render colour presets
#define COL_TEXT     0xFFFF  // White
#define COL_HEADING  0xFFE0  // Yellow
#define COL_BOLD     0x07E0  // Green  0xF800 //0xFC30  // Red-ish
#define COL_LINK     0x1B1F  // Blue-ish

// Specific hash -> tag mappings
#define BODYTAG       1069   // <body>
#define BODYTAGEND    1309   // </body>
#define PRETAG        553    // <pre>
#define PRETAGEND     673    // </pre>
#define HREFTAG       2253   // href=
#define STYLETAG      2577   // <style>
#define STYLETAGEND   3057   // </style>
#define SCRIPTTAG     4920   // <script>
#define SCRIPTTAGEND  5880   // </script>
#define PIP           546    // <pip> custom tag

// Use non-printable ASCII characters for tag codes
#define TAG_CR        14   // ~
#define TAG_HEADING1  15   // [
#define TAG_HEADING2  16   // ]
#define TAG_BOLD1     17   // (
#define TAG_BOLD2     18   // )
#define TAG_LINK1     19   // { <a
#define TAG_LINK2     20   // | URL
#define TAG_LINK3     21   // } </a>
#define TAG_HR        22   // %
#define TAG_LIST      23   // *
#define TAG_PRE       24   // `
#define TAG_PRE2      25   // '
#define TAG_HTTP      26   // http://

/*
#define TAG_CR        182  //¶  14   // ~
#define TAG_HEADING1  167  //§  15   // [
#define TAG_HEADING2  168  //¨  16   // ]
#define TAG_BOLD1     185  //¹  17   // (
#define TAG_BOLD2     186  //º  18   // )
#define TAG_LINK1     188  //¼  19   // { <a
#define TAG_LINK2     189  //½  20   // | URL
#define TAG_LINK3     190  //¾  21   // } </a>
#define TAG_HR        172  //¬  22   // %
#define TAG_LIST      164  //¤  23   // *
#define TAG_PRE       162  //¢  24   // `
#define TAG_PRE2      163  //£  25   // '
#define TAG_HTTP      187  //»  26   // http://
*/

// Hash flags and masks
#define INLINE       0x8000             // High bit flag for tag allowing post spaces
#define PRE_BREAK    0x4000             // High bit flag for pre-tag render break
#define POST_BREAK   0x2000             // High bit flag for post tag break
#define ATTR_MASK    0x1fff             // Mask to remove high bit flags

// Hash -> tag & flag mappings
#define NUMTAGS 76

static const uint16_t tag_codes[] PROGMEM = {
            161,   TAG_HEADING1 | PRE_BREAK,           // <h1>
            162,   TAG_HEADING1 | PRE_BREAK,           // <h2>
            163,   TAG_HEADING1 | PRE_BREAK,           // <h3>
            164,   TAG_HEADING1 | PRE_BREAK,           // <h4>
            80,    TAG_CR | PRE_BREAK,                 // <p>
            226,   TAG_HR | PRE_BREAK | POST_BREAK,    // <hr>
            246,   TAG_CR | PRE_BREAK,                 // <ul>
            234,   TAG_CR | PRE_BREAK,                 // <ol>
            225,   TAG_LIST | PRE_BREAK,               // <li>
            PRETAG, TAG_PRE | PRE_BREAK,                // <pre>

            221,   TAG_HEADING2 | POST_BREAK,          // </h1>
            222,   TAG_HEADING2 | POST_BREAK,          // </h2>
            223,   TAG_HEADING2 | POST_BREAK,          // </h3>
            224,   TAG_HEADING2 | POST_BREAK,          // </h4>

            443,   TAG_CR | POST_BREAK,       // <br/>
            214,   TAG_CR | POST_BREAK,       // <br>
            110,   TAG_CR | POST_BREAK,       // </p>
            294,   TAG_CR | POST_BREAK,       // </ol>
            306,   TAG_CR | POST_BREAK,       // </ul>
            285,   TAG_CR | POST_BREAK,       // </li>
            PRETAGEND, TAG_PRE2 | POST_BREAK,     // </pre>

            66,     TAG_BOLD1 | INLINE,       // <b>
            96,     TAG_BOLD2 | INLINE,       // </b>
            5199,   TAG_BOLD1 | INLINE,       // <strong>
            6159,   TAG_BOLD2 | INLINE,       // </strong>
            65,     TAG_LINK1 | INLINE,       // <a>
            HREFTAG, TAG_LINK2 | INLINE,       // URL
            95,     TAG_LINK3 | INLINE,       // </a>

            1428, 38,  // Ampersand
            2682, 96,  // 8216; Curly single quote
            2683, 39,  // 8217; Curly single quote
            6460, 128,  // nbsp;
            2680, 34,  // 8220; Curly double quotes
            2681, 34,  // 8221; Curly double quotes
            2677, 45,  // 8211; Hyphens en
            2678, 45,  // 8212; Hyphens em
            368,  62, // Greater than
            388,  60  // Less than
};

class iGOS_Class
{
    private:

        char server[30] = "*";
        char path[60] = "";
        char url[90] = "";
        
        File file;

        struct cacheStruct {
            uint8_t    pagePtr, lastPage;                 // Pointers to current and last page indexed
            uint16_t  index[PAGEINDEXSIZE];               // File page index pointers
            uint8_t   pageState[PAGEINDEXSIZE];           // Initial tag state for page e.g. in a <strong>
        };

        cacheStruct textContent;

        struct linkStruct {
            uint8_t    linkPtr, lastLink;                  // Pointers to current and last link indexed
            uint16_t   index[LINKINDEXSIZE];               // Link 
        };

        linkStruct pageLinks;
        
        uint16_t lowestRAM;                    // Keeps tabs for low memoery alerts

        //uint8_t command;                              // Initial browser command to display the homepage
      
        uint8_t generalBuffer[55];

        void (* resetFunc) (void) = 0; //declare reset function at adress 0
        
        
        

    public:

        iGOS_Class();
        ~iGOS_Class();

        void buildURL(uint16_t pointer);
        
        void Get_Page(); //command 0
        void Page_Up(); //command 1
        void Page_Down(); //command 2
        void Next_Link(); //command 3
        void Previous_Link(); //command 4
        void Load_Page(); // command 5

        

        void Get_URL();

        byte cacheURL(char *URLserver, char *URLpath);
        void storeURL(char *local_url);

        byte displayPage(); //display parced page on Nextion

        void displayPageIndex(); //debug : display page index
        void displayLinkIndex(); //debug : display linkindex


        void freeRam();
        
        char lowerCase (char c);
        uint16_t hashOut (uint16_t hash); // Consumes data from Ethernet until the given string is found, or time runs out
        boolean inputWait(); //delays until ethernet data is available
        void splitURL (char *localURL); //split a URL into server / path

        uint8_t openCacheFile (boolean readOnly); //open cache file

        byte findUntil (uint8_t *string, boolean);

        uint8_t printCache();

};

#endif