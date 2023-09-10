#ifndef CRYNU_DISPLAY_H
#define CRYNU_DISPLAY_H

#include "progmem.h"
#include "crynu_font.h"
#include <stdio.h>

const int DISPLAY_WIDTH = 128;
const int LARGE_CHARACTER_WIDTH = 12;
const int LOCK1 = DISPLAY_WIDTH - LARGE_CHARACTER_WIDTH - LARGE_CHARACTER_WIDTH - 2;
const int LOCK2 = DISPLAY_WIDTH - LARGE_CHARACTER_WIDTH;
const int MESSAGE_MAX = LOCK1;

enum LOCK{ NONE = 0, CAPS = 1, NUM = 2, SCROLL = 4, REC = 8 };

int crynu_lock_state = 0;


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
void largeFont(const char *message, int pass, char *buffer)
{
    const int CHARACTER_MAX = MESSAGE_MAX / LARGE_CHARACTER_WIDTH;
    char *preformat = "%%-%d.%ds";
    char format[10];
    char fomattedMessage[CHARACTER_MAX + 1];

    sprintf(format,preformat,CHARACTER_MAX, CHARACTER_MAX);
    sprintf(fomattedMessage,format, message);

    int characterIndex = LARGE_CHARACTER_WIDTH, 
    character = -1, 
    passAddition = 0;
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
                   
    for(int i=0; i<LARGE_CHARACTER_WIDTH; ++i)
    {
        buffer[i+LOCK2] = getFont2At( two, i + passAddition );
    }  
}


#endif