#ifndef CRYNU_DISPLAY_H
#define CRYNU_DISPLAY_H

#include "progmem.h"
#include "crynu_font.h"
#include <stdio.h>

#define FORMAT_MESSAGE_FORMAT_SIZE 10

const int DISPLAY_WIDTH = 128;
const int SMALL_CHAR_WIDTH = 6;
const int MAX_SMALL_CHARACTERS = DISPLAY_WIDTH / SMALL_CHAR_WIDTH;
const int LARGE_CHARACTER_WIDTH = 12;
const int LOCK1 = DISPLAY_WIDTH - LARGE_CHARACTER_WIDTH - LARGE_CHARACTER_WIDTH - 2; // position in display of lock1
const int LOCK2 = DISPLAY_WIDTH - LARGE_CHARACTER_WIDTH; // position in display of lock2
const int MESSAGE_MAX = LOCK1;
const int MAX_LARGE_CHARACTERS = MESSAGE_MAX / LARGE_CHARACTER_WIDTH;

char *formFontMessageFormat = "%%-%d.%ds"; // contains the form of the large font sprintf format string.
const int largeFontMessageSize = MAX_LARGE_CHARACTERS + 1;
char largeFontMessageFormat[FORMAT_MESSAGE_FORMAT_SIZE];
const int smallFontMessageSize = MAX_SMALL_CHARACTERS + 1;
char smallFontMessageFormat[FORMAT_MESSAGE_FORMAT_SIZE];

enum LOCK{ NONE = 0, CAPS = 1, NUM = 2, SCROLL = 4, REC = 8 };

int crynu_lock_state = 0;


void smallFont(const char *message, char *buffer)
{    
    char fomattedMessage[smallFontMessageSize];
    sprintf(smallFontMessageFormat, formFontMessageFormat, MAX_SMALL_CHARACTERS, MAX_SMALL_CHARACTERS); // dynamically creates the small message sprintf format string. 
    sprintf(fomattedMessage,smallFontMessageFormat, message);
    int characterIndex = SMALL_CHAR_WIDTH, 
    character = -1;
    for(int i=0; i<LOCK2; ++i)
    {
        if(characterIndex >= SMALL_CHAR_WIDTH)
        {
            ++character;
            characterIndex = 0;
        }
        int expandedAddress = fomattedMessage[character] * SMALL_CHAR_WIDTH + characterIndex;
        buffer[i] = font[expandedAddress];
        ++characterIndex;
    }


}

/**
 * character is the character to retrieve
 * pass is 0 or 1
****************************************************/
char getFont2At(const int character, const int index )
{
    int expandedAddress = character * LARGE_CHARACTER_WIDTH * 2 + index;
    return font2[expandedAddress];    
}

/* gets the character image data
 * message is the text pass is the top or the bottom
 * half of the double hight character.
 ****************************************************/
void largeFont(const char *message, int pass, char *buffer) // largeFont(const char *message, int pass, char *buffer)
{
    char fomattedMessage[largeFontMessageSize];
    sprintf(largeFontMessageFormat,formFontMessageFormat, MAX_LARGE_CHARACTERS, MAX_LARGE_CHARACTERS); // dynamically creates the large message sprintf format string.
    sprintf(fomattedMessage,largeFontMessageFormat, message);

    int characterIndex = LARGE_CHARACTER_WIDTH, character = -1, passAddition = 0;
    if(pass) passAddition = LARGE_CHARACTER_WIDTH;
    for(int i=0; i<LOCK2; ++i)
    {
        if(characterIndex >= LARGE_CHARACTER_WIDTH)
        {
            ++character;
            characterIndex = 0;
        }
        buffer[i] = getFont2At(fomattedMessage[character], characterIndex + passAddition);
        ++characterIndex;
    }

}



void setLocks(const int state)
{
    crynu_lock_state = state;
}

void getLockStateImage(const int row, char *buffer)
{
    char caps = 0x05;
    char num = 0x04;
    char scroll = 0x03;
    char rec = 0x06;
    char one = ' ';
    char two = ' ';
    int passAddition = 0;
    
    if(row % 2) passAddition = LARGE_CHARACTER_WIDTH;   
    
    if(row < 2)
    {
        if(crynu_lock_state & CAPS)
        {
            one = caps;
        }
        if(crynu_lock_state & NUM)
        {            
            two = num;
        }
    }
    else 
    {
        if(crynu_lock_state & SCROLL)
        {
            one = scroll;
        }
        if(crynu_lock_state & REC)
        {
            two = rec;
        }
    }  

    for(int i=0; i<LARGE_CHARACTER_WIDTH; ++i)
    {
        buffer[i+LOCK1] = getFont2At( one, i + passAddition );
    }
    buffer[LOCK2 - 1] = 0;              
    buffer[LOCK2 - 2] = 0;              
    for(int i=0; i<LARGE_CHARACTER_WIDTH; ++i)
    {
        buffer[i+LOCK2] = getFont2At( two, i + passAddition );
    }  
}


#endif