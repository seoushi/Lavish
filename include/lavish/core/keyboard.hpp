/* 
 * File:   keyboard.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 2:38 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _KEYBOARD_HPP
#define _KEYBOARD_HPP

#include <lavish/core/platform.hpp>

namespace lavish
{


namespace keyboard
{


/**
 * an enum of the keyboard keys
 * keys are maps to thier SDL/ascii values
 * there is only a-z, A-Z are skipped since they are the same
 * Numbers are prefixed with Num (example Num0)
 * Numpad keys are prefixed with Pad (example Pad0)
 */
enum Key
{
    Unknown     = SDLK_UNKNOWN,
    First       = SDLK_FIRST,
    Backspace   = SDLK_BACKSPACE,
    Tab         = SDLK_TAB,
    Clear       = SDLK_CLEAR,
    Return      = SDLK_RETURN,
    Pause       = SDLK_PAUSE,
    Escape      = SDLK_ESCAPE,
    Space       = SDLK_SPACE,
    Exclaim     = SDLK_EXCLAIM,
    DoubleQuote = SDLK_QUOTEDBL,
    Hash        = SDLK_HASH,
    Dollar      = SDLK_DOLLAR,
    Ampersand   = SDLK_AMPERSAND,
    Quote       = SDLK_QUOTE,
    LeftParen   = SDLK_LEFTPAREN,
    RightParen  = SDLK_RIGHTPAREN,
    Asterisk    = SDLK_ASTERISK,
    Plus        = SDLK_PLUS,
    Comma       = SDLK_COMMA,
    Minus       = SDLK_MINUS,
    Period      = SDLK_PERIOD,
    Slash       = SDLK_SLASH,
    Num0        = SDLK_0,
    Num1        = SDLK_1,
    Num2        = SDLK_2,
    Num3        = SDLK_3,
    Num4        = SDLK_4,
    Num5        = SDLK_5,
    Num6        = SDLK_6,
    Num7        = SDLK_7,
    Num8        = SDLK_8,
    Num9        = SDLK_9,
    Colon       = SDLK_COLON,
    Semicolon   = SDLK_SEMICOLON,
    LessThan    = SDLK_LESS,
    Equals      = SDLK_EQUALS,
    Greater     = SDLK_GREATER,
    Question    = SDLK_QUESTION,
    At          = SDLK_AT,


    // Skip uppercase letters


    LeftBracket     = SDLK_LEFTBRACKET,
    BackSlash       = SDLK_BACKSLASH,
    RightBracket    = SDLK_RIGHTBRACKET,
    Caret           = SDLK_CARET,
    Underscore      = SDLK_UNDERSCORE,
    BackQuote       = SDLK_BACKQUOTE,
    A            = SDLK_a,
    B            = SDLK_b,
    C            = SDLK_c,
    D            = SDLK_d,
    E            = SDLK_e,
    F            = SDLK_f,
    G            = SDLK_g,
    H            = SDLK_h,
    I            = SDLK_i,
    J            = SDLK_j,
    K            = SDLK_k,
    L            = SDLK_l,
    M            = SDLK_m,
    N            = SDLK_n,
    O            = SDLK_o,
    P            = SDLK_p,
    Q            = SDLK_q,
    R            = SDLK_r,
    S            = SDLK_s,
    T            = SDLK_t,
    U            = SDLK_u,
    V            = SDLK_v,
    W            = SDLK_w,
    X            = SDLK_x,
    Y            = SDLK_y,
    Z            = SDLK_z,
    Delete       = SDLK_DELETE,


    // End of ASCII mapped keysyms


    // Numeric keypad
    Pad0            = SDLK_KP0,
    Pad1            = SDLK_KP1,
    Pad2            = SDLK_KP2,
    Pad3            = SDLK_KP3,
    Pad4            = SDLK_KP4,
    Pad5            = SDLK_KP5,
    Pad6            = SDLK_KP6,
    Pad7            = SDLK_KP7,
    Pad8            = SDLK_KP8,
    Pad9            = SDLK_KP9,
    PadPeroid       = SDLK_KP_PERIOD,
    PadDivide       = SDLK_KP_DIVIDE,
    PadMultiply     = SDLK_KP_MULTIPLY,
    PadMinus        = SDLK_KP_MINUS,
    PadPlus         = SDLK_KP_PLUS,
    PadEnter        = SDLK_KP_ENTER,
    PadEquals       = SDLK_KP_EQUALS,

    // Arrows and Home/End
    UpArrow     = SDLK_UP,
    DownArrow   = SDLK_DOWN,
    RightArrow  = SDLK_RIGHT,
    LeftArrow   = SDLK_LEFT,
    Insert      = SDLK_INSERT,
    Home        = SDLK_HOME,
    End         = SDLK_END,
    PageUp      = SDLK_PAGEUP,
    PageDown    = SDLK_PAGEDOWN,

    /* Function keys */
    F1            = SDLK_F1,
    F2            = SDLK_F2,
    F3            = SDLK_F3,
    F4            = SDLK_F4,
    F5            = SDLK_F5,
    F6            = SDLK_F6,
    F7            = SDLK_F7,
    F8            = SDLK_F8,
    F9            = SDLK_F9,
    F10           = SDLK_F10,
    F11           = SDLK_F11,
    F12           = SDLK_F12,
    F13           = SDLK_F13,
    F14           = SDLK_F14,
    F15           = SDLK_F15,

    /* Key state modifier keys */
    NumLock     = SDLK_NUMLOCK,
    CapsLock    = SDLK_CAPSLOCK,
    ScrollLock  = SDLK_SCROLLOCK,
    RShift      = SDLK_RSHIFT,
    LShift      = SDLK_LSHIFT,
    RCtrl       = SDLK_RCTRL,
    LCtrl       = SDLK_LCTRL,
    RAlt        = SDLK_RALT,
    LAlt        = SDLK_LALT,
    RMeta       = SDLK_RMETA,
    LMeta       = SDLK_LMETA,
    LSuper      = SDLK_LSUPER,        // Left Windows/Apple key
    RSuper      = SDLK_RSUPER,        // Right Windows/Apple key

    // Miscellaneous function keys
    Help        = SDLK_HELP,
    Print       = SDLK_PRINT,
    SysReq      = SDLK_SYSREQ,
    Break       = SDLK_BREAK,
    Menu        = SDLK_MENU
};


/**
 * A helper function that will convert a key into a char
 * special keys will return 1, also known as "First" in the key chart
 * enter will return '\n'
 * tab will return '\t'
 * all other keys should be returned as expected
 *
 * @param key a keyboard key
 * @return the equivalent
 */
char KeyToAscii(Key key);


} /* keyboard */




/**
 * A class that receives events related to the keyboard.
 * it must be attached to an eventListener in order for it to receive events.
 */
class KeyboardListener
{
    public:

        /**
         * A default constructor
         */
        KeyboardListener();

        /**
         * A default destructor
         */
        virtual ~KeyboardListener();


        /**
         * A pure virtual method that gets called when a key is pressed
         * @param key a keyboard key
         */
        virtual void OnKeyDown(const keyboard::Key key) = 0;


        /**
         * A pure virtual method that gets called when a key is released
         * @param key a keyboard key
         */
        virtual void OnKeyUp(const keyboard::Key key) = 0;

};


} /* lavish */

#endif    /* _KEYBOARD_HPP */

