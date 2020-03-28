#ifndef IGOS_H_INCLUDED
#define IGOS_H_INCLUDED

#include "Arduino.h"

#define CACHEFILE      "CACHE.HTM"              // Cached HTML filename
#define HOMEPAGE       "HOME.HTM"               // First load homepage name
#define PAGEINDEXSIZE  10                       // Must small - each page uses 3 bytes
#define LINKINDEXSIZE  20                       // Must small - each link uses 2 bytes 
#define TIMEOUT        5000                     // Timeout on ethernet reads

class iGOS_Class
{
    private:
        char server[30] = "*";
        char path[60] = "";
        char url[90] = "";
        
        struct cacheStruct {
            uint8_t    pagePtr, lastPage;                 // Pointers to current and last page indexed
            uint16_t  index[PAGEINDEXSIZE];               // File page index pointers
            uint8_t   pageState[PAGEINDEXSIZE];           // Initial tag state for page e.g. in a <strong>
        };

        cacheStruct textContent = { 0, 0, false };

        struct linkStruct {
            uint8_t    linkPtr, lastLink;                  // Pointers to current and last link indexed
            uint16_t   index[LINKINDEXSIZE];               // Link 
        };

        linkStruct pageLinks = {0, 0};
        
        uint16_t lowestRAM = 2000;                        // Keeps tabs for low memoery alerts

        uint8_t command = 6;                              // Initial browser command to display the homepage
        uint16_t jX = 0, jY = 0;                          // Input joystick positions
        uint8_t generalBuffer[55];

        void (* resetFunc) (void) = 0; //declare reset function at adress 0

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

    public:

        iGOS_Class();
        ~iGOS_Class();
        void buildURL(uint16_t pointer);
        void cacheURL(char *URLserver, char *URLpath);
        void displayPageIndex(); //debug purpose
        void displayLinkIndex(); //debug purpose
        void freeRam();

};

#endif