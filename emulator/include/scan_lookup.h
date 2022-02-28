// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//      Name:       scan_lookup.h
//      Purpose:    For each possible code sent to GAVIN, the corresponding SDL Scan code
//      Created:    23rd February 2022
//      Author:     Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

static int mau_table[] = { 
0x00,										// 0x00
SDL_SCANCODE_ESCAPE,
SDL_SCANCODE_1,
SDL_SCANCODE_2,
SDL_SCANCODE_3,
SDL_SCANCODE_4,
SDL_SCANCODE_5,
SDL_SCANCODE_6,

SDL_SCANCODE_7, 							// 0x08
SDL_SCANCODE_8,
SDL_SCANCODE_9,
SDL_SCANCODE_0,
SDL_SCANCODE_MINUS,
SDL_SCANCODE_EQUALS,
SDL_SCANCODE_BACKSPACE,
SDL_SCANCODE_TAB,

SDL_SCANCODE_Q, 							// 0x10
SDL_SCANCODE_W,
SDL_SCANCODE_E,
SDL_SCANCODE_R,
SDL_SCANCODE_T,
SDL_SCANCODE_Y,
SDL_SCANCODE_U,
SDL_SCANCODE_I,

SDL_SCANCODE_O, 							// 0x18
SDL_SCANCODE_P,
SDL_SCANCODE_LEFTBRACKET,
SDL_SCANCODE_RIGHTBRACKET,
SDL_SCANCODE_RETURN,
SDL_SCANCODE_LCTRL,
SDL_SCANCODE_A,
SDL_SCANCODE_S,

SDL_SCANCODE_D, 							// 0x20
SDL_SCANCODE_F,
SDL_SCANCODE_G,
SDL_SCANCODE_H,
SDL_SCANCODE_J,
SDL_SCANCODE_K,
SDL_SCANCODE_L,
SDL_SCANCODE_SEMICOLON,

SDL_SCANCODE_APOSTROPHE, 					// 0x28
SDL_SCANCODE_NONUSHASH,
SDL_SCANCODE_LSHIFT,
SDL_SCANCODE_BACKSLASH,
SDL_SCANCODE_Z,
SDL_SCANCODE_X,
SDL_SCANCODE_C,
SDL_SCANCODE_V,

SDL_SCANCODE_B, 							// 0x30
SDL_SCANCODE_N,
SDL_SCANCODE_M,
SDL_SCANCODE_COMMA,
SDL_SCANCODE_PERIOD,
SDL_SCANCODE_SLASH,
SDL_SCANCODE_RSHIFT,
0x00,

SDL_SCANCODE_LALT,  				// 0x38
SDL_SCANCODE_SPACE,					// 0x39
SDL_SCANCODE_CAPSLOCK,
0x00,//SDL_SCANCODE_F1,
0x00,//SDL_SCANCODE_F2,
0x00,//SDL_SCANCODE_F3,
0x00,//SDL_SCANCODE_F4,
0x00,//SDL_SCANCODE_F5,

0x00,//SDL_SCANCODE_F6, 					// 0x40
0x00,//SDL_SCANCODE_F7,
0x00,//SDL_SCANCODE_F8,
0x00,//SDL_SCANCODE_F9,
0x00,//SDL_SCANCODE_F10,
SDL_SCANCODE_NUMLOCKCLEAR,
SDL_SCANCODE_SCROLLLOCK,
0x80,

SDL_SCANCODE_UP, 					// 0x48
SDL_SCANCODE_PAGEUP,
0x00,
SDL_SCANCODE_LEFT,
0x00,
SDL_SCANCODE_RIGHT,
0x00,
SDL_SCANCODE_END,

SDL_SCANCODE_DOWN, 					// 0x50
SDL_SCANCODE_PAGEDOWN,
SDL_SCANCODE_INSERT,
SDL_SCANCODE_DELETE,
0x00,
0x00,
0x00,
0x94,

0x95,  								// 0x58
0x00,
0x00,
SDL_SCANCODE_RGUI, 					// 0x5B "OS"
SDL_SCANCODE_RALT,
SDL_SCANCODE_LGUI,
SDL_SCANCODE_RCTRL,
0x00,

0x00,  								// 0x60
0x00,
0x81,
0x80,
0x84,
0x82,
0x83,
0x85,

0x86,
0x89,
0x87,
0x88,
0x00,
0x0D,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
-1 };