#ifndef CRYNU_DISPLAY_H
#define CRYNU_DISPLAY_H

#include "progmem.h"
#include "crynu_font.h"
#include <stdio.h>

static const int DISPLAY_WIDTH = 128;
static const int DISPLAY_ROWS = 4;
static const int MESSAGE_MAX = 12;

enum LOCK{ NONE = 0, CAPS = 1, NUM = 2, SCROLL = 4, REC = 8 }

static LOCK state = NONE;

static char crynu_buf[128];

// 
void textSize2(const char *message, int length, int row)
{
    for 
}



void readLockState( const int pass)
{

    if(state & CAPS)
    {
        
    }
    if(state & NUM)
    {
        
    }
    if(state & SCROLL)
    {
        
    }
    if(state & REC)
    {
        
    }
}

void lockStates

#endif