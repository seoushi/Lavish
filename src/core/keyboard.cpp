/* 
 * File:   keyboard.cpp
 * Author: Sean Chapel
 * 
 * Created on May 29, 2009, 2:38 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/core/keyboard.hpp>

namespace lavish
{

namespace keyboard
{


char KeyToAscii(Key key)
{

    if(  ((key >= Space) && (key < At)) ||      // ' ' to '@'
         ((key >= LeftBracket) && (key < Z)))   // '[' to 'z'
    {
        return (char) key;
    }


    switch(key)
    {
        // Numpad keys
        case Pad0:
            return '0';
        case Pad1:
            return '1';
        case Pad2:
            return '2';
        case Pad3:
            return '3';
        case Pad4:
            return '4';
        case Pad5:
            return '5';
        case Pad6:
            return '6';
        case Pad7:
            return '7';
        case Pad8:
            return '8';
        case Pad9:
            return '9';
        case PadPeroid:
            return '.';
        case PadDivide:
            return '/';
        case PadMultiply:
            return '*';
        case PadMinus:
            return '-';
        case PadPlus:
            return '+';
        case PadEnter:
            return '\n';
        case PadEquals:
            return '=';

        // tab and enter
        case Return:
            return '\n';
        case Tab:
            return '\t';
	    
		default:
			break;
    }

    return 1;
}


} /* keyboard */


KeyboardListener::KeyboardListener()
{
}

KeyboardListener::~KeyboardListener()
{
}


} /* airitch */