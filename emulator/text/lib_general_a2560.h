/*
 * lib_general_a2560.h
 *
 *  Created on: Feb 19, 2022
 *      Author: micahbly
 */

#ifndef GENERAL_A2560_H_
#define GENERAL_A2560_H_


/* about this class
 *
 *
 *
 *** things this class needs to be able to do
 * various utility functions that any app could find useful.
 * intended to be re-usable across apps, with at most minimal differences.
 * this file should contain only cross-platform code. platform-specific code should go into lib_general_[platformname].h/.c
 *
 *** things objects of this class have
 *
 *
 */


/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/



/*****************************************************************************/
/*                            Macro Definitions                              */
/*****************************************************************************/

// A2560 OTHER
#define EA_USER				(char*)0x020000	// start of user space. ie, put your program here.
#define EA_STACK			(char*)0x080000	// stack location

// A2560 VICKY III
#define VICKY					(char*)0xfec40000	// vicky registers?
#define TEXTA_RAM_A2560_MORFE	(char*)0xfec60000	// channel A text
#define TEXTA_ATTR_A2560_MORFE	(char*)0xfec68000	// channel A attr
#define TEXTB_RAM_A2560_MORFE	(char*)0xfeca0000	// channel B text
#define TEXTB_ATTR_A2560_MORFE	(char*)0xfeca8000	// channel B attr
#define TEXTA_RAM_A2560K		(char*)0xfec60000	// channel A text
#define TEXTA_ATTR_A2560K		(char*)0xfec68000	// channel A attr
#define TEXTB_RAM_A2560K		(char*)0xfeca0000	// channel B text
#define TEXTB_ATTR_A2560K		(char*)0xfeca8000	// channel B attr

// subtract 0xfe000000 from the UM map for Vicky (to get the old/morfe addresses)
// size of some areas changed too:
//   channel-A text went 0xc6:0000 -> 0xFEC6:0000, but channel-A color went 0xc6:8000 -> 0xFEC6:4000
//   channel-B text went 0xca:0000-> 0xFECA:0000, channel-B color went 0xca:8000 -> 0xFECA:4000
// btw, one thing to keep in mind is device-mem access granularity -- while in morfe you can do 8-32bit accesses, on the actual hw you will need to adhere to the area access granularity
//  see user manual, the "SIZE" columns

#define TEXTA_WIDTH			72	// channel A width
#define TEXTA_HEIGHT		56	// channel A height
#define TEXTB_WIDTH			80	// channel B width
#define TEXTB_HEIGHT		60	// channel B height

#define TEXT_COL_COUNT_FOR_PLOTTING		80	// regardless of visible cols (between borders), VRAM seems to be fixed at 80 cols across.
#define TEXT_ROW_COUNT_FOR_PLOTTING		60	// regardless of visible rows (between borders), VRAM seems to be fixed at 60 rows up/down.

#define CHANNEL_A_WIDTH		576	// pixels in between the borders
#define CHANNEL_A_HEIGHT	448	// pixels in between the borders
#define CHANNEL_B_WIDTH		640	// pixels in between the borders
#define CHANNEL_B_HEIGHT	480	// pixels in between the borders

#define ID_CHANNEL_A			0	// for use in lib_text() calls, etc. 
#define ID_CHANNEL_B			1	// for use in lib_text() calls, etc.

#define TEXT_FONT_WIDTH_A2650	8	// for text mode, the width of the fixed-sized font chars
#define TEXT_FONT_HEIGHT_A2650	8	// for text mode, the height of the fixed-sized font chars. I believe this is supposed to be 16, but its 8 in morfe at the moment.

//#define FONT_MEMORY_BANK0	(char*)0xAF8000	// $AF8000 - $AF87FF
//#define FONT_MEMORY_BANK1	(char*)0xAF8800	// $AF8800 - $AF8FFF

// from vicky3.go in morfe tho:
//const FONT_MEMORY_BANK0           = 0x8000
#define FONT_MEMORY_BANK0_A2560_MORFE	(char*)0xc48000	// $AF8000 - $AF87FF
#define FONT_MEMORY_BANK1_A2560_MORFE	(char*)0xc48800	// $AF8800 - $AF8FFF
#define FONT_MEMORY_BANK0_A2560K		(char*)0xfec68000	//
#define FONT_MEMORY_BANK1_A2560K		(char*)0xfec68000	// only 1 font bank on A2560K?

// gadget:
// If it's the same as on the C256 line, each character consists of 8 bytes.  Upper left hand corner is the high-bit of byte zero, upper right is the low bit of byte zero, lower left is the high bit of byte 7, lower right is the low bit of byte 7.  The bytes are placed in memory from character zero to character 255, 0..7, 0..7, 0..7, etc.

// pjw:
// Yeah, C256 and A2560U fonts are the same layout. The A2560K is a little different. The mostly-text-mode screen supports an 8x16 font layout, where the structure is essentially the same, but each character is 16 bytes rather than 8.

// beethead:
// The 2nd font was removed when the U line came in since it was not being used.  Atleast on the C256's.






// amiga rawkey codes
#define KEYCODE_CURSOR_LEFT		79
#define KEYCODE_CURSOR_RIGHT	78
#define KEYCODE_CURSOR_UP		76
#define KEYCODE_CURSOR_DOWN		77

#define KEYCODE_RETURN			0x44					// rawkey code
#define KEYCODE_RETURN_UP		KEY_RAW_RETURN & 0x80
#define KEY_RETURN			13	// vanilla key
#define KEY_ESC				27	// vanilla key

#define CHAR_UMLAUT			0xA8	// ¨ char -- will use in place of ellipsis when truncating strings
#define CHAR_ELLIPSIS		CHAR_UMLAUT

#define KEY_BUFFER_SIZE		16	// unlikely anyone would ever want to type 15 chars to select a file

#define ALERT_MAX_MESSAGE_LEN		256	// 255 chars + terminator. seems long, but with formatting chars, not crazy.

#define ALERT_DIALOG_SHOW_AS_ERROR	true	// parameter for General_ShowAlert()
#define ALERT_DIALOG_SHOW_AS_INFO	false	// parameter for General_ShowAlert()

#define ALERT_DIALOG_INCLUDE_CANCEL	true	// parameter for General_ShowAlert()
#define ALERT_DIALOG_NO_CANCEL_BTN	false	// parameter for General_ShowAlert()

#define ALERT_DIALOG_1ST_BUTTON	0	// return value for General_ShowAlert()
#define ALERT_DIALOG_2ND_BUTTON	1	// return value for General_ShowAlert()
#define ALERT_DIALOG_3RD_BUTTON	2	// return value for General_ShowAlert()
// NOTE: can't define "OK" as 1 or 0, because it depends on passing ok, then cancel (eg). Buttons appear to be numbered from RIGHT to LEFT!

/*****************************************************************************/
/*                               Enumerations                                */
/*****************************************************************************/

// abandoning enum idea for now: in testing, if I abused it and put -1, 3, etc, it blew up morfe. 
// typedef enum ScreenID
// {
// 	ID_CHANNEL_A		= 0,
// 	ID_CHANNEL_B 		= 1,
// } ScreenID;


/*****************************************************************************/
/*                                 Structs                                   */
/*****************************************************************************/

typedef struct Coordinate
{
    int x;
    int y;
} Coordinate;

typedef struct Rectangle
{
	signed short   MinX, MinY;
	signed short   MaxX, MaxY;
} Rectangle;

typedef struct Screen
{
	signed int		id_;
	Rectangle		rect_;
	unsigned short	text_cols_;
	unsigned short	text_rows_;
	char*			text_ram_;
	char*			text_attr_ram_;
	char*			text_font0_ram_;	// 1K of memory holding font definitions. Some Foenix computers have 2 banks. Some only 1.
	char*			text_font1_ram_;	// 1K of memory holding font definitions. Some Foenix computers have 2 banks. Some only 1.
	signed int		text_font_height_;	// in text mode, the height in pixels for the fixed width font. Should be either 8 or 16, depending on which Foenix. used for calculating text fit.
	signed int		text_font_width_;	// in text mode, the width in pixels for the fixed width font. Unlikely to be other than '8' with Foenix machines. used for calculating text fit.
	char			text_temp_buffer_1_[TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING + 1];	// general use temp buffer - do NOT use for real storage - any utility function clobber it
	char			text_temp_buffer_2_[TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING + 1];	// general use temp buffer - do NOT use for real storage - any utility function clobber it
} Screen;


typedef enum
{
	false = 0,
	true = 1
} boolean;

/*****************************************************************************/
/*                             Global Variables                              */
/*****************************************************************************/


/*****************************************************************************/
/*                       Public Function Prototypes                          */
/*****************************************************************************/
// 
// // pop up a requester box with message to user. var args are for the message. 
// unsigned long General_ShowAlert(struct Window* the_window, const char* the_title, boolean is_error, boolean with_cancel, const char* message_format, ...);
 
// calculates how many characters of the passed string will fit into the passed pixel width
// TODO: adapt this to reference the currently selected screen font, once non-fixed width fonts are available (if ever)
// returns -1 in any error condition
signed int General_TextFit(struct Screen* the_screen, char* the_string, signed int the_len, signed int available_width);

// Format a string by wrapping and trimming to fit the passed width and height. returns number of vertical pixels required. 
// Passing a 0 for height disables the governor on allowed vertical space. 
// If the string cannot be displayed in the specified height and width, processing will stop, but it is not an error condition
// If max_chars_to_format is less than len of string, processing will stop after that many characters.
// returns -1 in any error condition
signed int General_WrapAndTrimTextToFit(struct Screen* the_screen, char** orig_string, char** formatted_string, signed int max_chars_to_format, signed int max_width, signed int max_height);
 
// // draw a line in an intuition window
// void General_DrawLine(struct RastPort* the_rastport, signed long x1, signed long y1, signed long x2, signed long y2, char the_color_pen);
// 
// // draw a poly in an intuition window
// void General_DrawPoly(struct RastPort* the_rastport, short num_coords, short* the_coordinates, char the_color_pen);
// 
// // draw a rectangle in the rastport passed. If do_undraw is TRUE, try to undraw it (unimplemented TODO)
// void General_DrawBox(struct RastPort* the_rastport, signed short x1, signed short y1, signed short x2, signed short y2, boolean do_undraw, char the_color_pen);
// 
// // checks a file exists without locking the file. tries to get a lock on the dir containing the file, then checks contents until it matches
// // SLOW, and probably pointless, but struggling with issue of locks not unlocking when checking for existence of an icon file.
// boolean General_CheckFileExists(char* the_file_path);
// 
// // return current date/time as a timestamp. 
// struct DateStamp* General_GetCurrentDateStampWithAlloc(void);





#endif /* GENERAL_A2560_H_ */
