/*
 * test5.c
 *
 *  Created on: Feb 19, 2022
 *      Author: micahbly
 */


/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/


// project includes
#include "lib_general.h"
#include "lib_general_a2560.h"

#include "lib_text.h"


// C includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// A2560 includes
#include <mcp/syscalls.h>


/*****************************************************************************/
/*                               Definitions                                 */
/*****************************************************************************/

#define RUN_TESTS	1	// define "RUN_TESTS" to include ability to run tests. If undefined, this class will not be aware of tests.

#if defined(RUN_TESTS)
	#include "test_base.h"
#endif


/*****************************************************************************/
/*                             Global Variables                              */
/*****************************************************************************/

unsigned long ditherData = 0x5555AAAA;

Screen	global_screen[2];

/*****************************************************************************/
/*                       Private Function Prototypes                         */
/*****************************************************************************/


/*****************************************************************************/
/*                       Private Function Definitions                        */
/*****************************************************************************/



/*****************************************************************************/
/*                        Public Function Definitions                        */
/*****************************************************************************/

// NOTE: lots of test junk getting put here temporarily until I can figure out why
// minunit and other stuff crashes morfe

boolean font_test(void);

boolean font_test(void)
{
	// alloc a block of memory for overwriting font data
	// need 256 chars * 8 bytes each
	
	char*	the_new_font_data;
	
	if ( (the_new_font_data = (char*)calloc(256 * 8, sizeof(char)) ) == NULL)
	{
		return false;
	}

	//DEBUG_OUT(("%s %d: font data chunk allocated ok", __func__, __LINE__));
	
	free(the_new_font_data);
	
	return true;
	//Text_ShowFontChars(ID_CHANNEL_B);
	//Text_UpdateFontData(ID_CHANNEL_B, (char*)0x000000);
}


int main(int argc, char* argv[])
{
	
	// move to startup function
	global_screen[ID_CHANNEL_A].id_ = ID_CHANNEL_A;
	global_screen[ID_CHANNEL_A].rect_.MinX = 0;
	global_screen[ID_CHANNEL_A].rect_.MinY = 0;
	global_screen[ID_CHANNEL_A].rect_.MaxX = CHANNEL_A_WIDTH;
	global_screen[ID_CHANNEL_A].rect_.MaxY = CHANNEL_A_HEIGHT;	
	global_screen[ID_CHANNEL_A].text_cols_ = TEXTA_WIDTH;
	global_screen[ID_CHANNEL_A].text_rows_ = TEXTA_HEIGHT;
	global_screen[ID_CHANNEL_A].text_ram_ = TEXTA_RAM_A2560_MORFE;
	global_screen[ID_CHANNEL_A].text_attr_ram_ = TEXTA_ATTR_A2560_MORFE;
	global_screen[ID_CHANNEL_A].text_font0_ram_ = FONT_MEMORY_BANK0_A2560_MORFE;
	global_screen[ID_CHANNEL_A].text_font1_ram_ = FONT_MEMORY_BANK0_A2560_MORFE;
	global_screen[ID_CHANNEL_A].text_font_height_ = TEXT_FONT_HEIGHT_A2650;
	global_screen[ID_CHANNEL_A].text_font_width_ = TEXT_FONT_WIDTH_A2650;
	global_screen[ID_CHANNEL_A].text_temp_buffer_1_[0] = '\0';
	global_screen[ID_CHANNEL_A].text_temp_buffer_2_[0] = '\0';
	

	global_screen[ID_CHANNEL_B].id_ = ID_CHANNEL_B;
	global_screen[ID_CHANNEL_B].rect_.MinX = 0;
	global_screen[ID_CHANNEL_B].rect_.MinY = 0;
	global_screen[ID_CHANNEL_B].rect_.MaxX = CHANNEL_B_WIDTH;
	global_screen[ID_CHANNEL_B].rect_.MaxY = CHANNEL_B_HEIGHT;	
	global_screen[ID_CHANNEL_B].text_cols_ = TEXTB_WIDTH;
	global_screen[ID_CHANNEL_B].text_rows_ = TEXTB_HEIGHT;
	global_screen[ID_CHANNEL_B].text_ram_ = TEXTB_RAM_A2560_MORFE;
	global_screen[ID_CHANNEL_B].text_attr_ram_ = TEXTB_ATTR_A2560_MORFE;
	global_screen[ID_CHANNEL_B].text_font0_ram_ = FONT_MEMORY_BANK0_A2560_MORFE;
	global_screen[ID_CHANNEL_B].text_font1_ram_ = FONT_MEMORY_BANK0_A2560_MORFE;
	global_screen[ID_CHANNEL_B].text_font_height_ = TEXT_FONT_HEIGHT_A2650;
	global_screen[ID_CHANNEL_B].text_font_width_ = TEXT_FONT_WIDTH_A2650;
	global_screen[ID_CHANNEL_B].text_temp_buffer_1_[0] = '\0';
	global_screen[ID_CHANNEL_B].text_temp_buffer_2_[0] = '\0';

	//General_LogInitialize();

	//printf("is this thing on?");

#if defined(RUN_TESTS)
//  	Text_RunTests();
#endif
	
	// extracting some test code here as maybe something wrong with minunit and morfe. can't explain the behavior I'm seeing there. Same tests here seem more stable. 
	{
		signed int		x1;
		signed int		y1;
		signed int		x2;
		signed int		y2;
	// 	signed int		h_line_len;
	// 	signed int		v_line_len;
		char*	the_message;
	
		x1 = 2;
		y1 = 5;
		x2 = 68;
		y2 = 51;
	// 	h_line_len = 67;
	// 	v_line_len = 47;

		// good values	
	//  	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_A, x1, y1, x1 + h_line_len, y1 + v_line_len, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN) == true, "Text_DrawBoxCoordsFancy failed" );
		Text_FillBox(ID_CHANNEL_A, x1+1, y1+1, x2-1, y2-1, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE);
		Text_DrawBoxCoordsFancy(ID_CHANNEL_A, x1, y1, x2, y2, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN);

		x1 = 19;
		y1 = 19;
		x2 = 41;
		y2 = 41;
	// 	h_line_len = 22;
	// 	v_line_len = 22;
	//  	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_B, x1, y1, x1 + h_line_len, y1 + v_line_len, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawBoxCoordsFancy failed" );
		Text_FillBox(ID_CHANNEL_B, x1+1, y1+1, x2-1, y2-1, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE);
		Text_DrawBoxCoordsFancy(ID_CHANNEL_B, x1, y1, x2, y2, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN);

		// bad values
	//  	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_A, x1, 1999, x1 + h_line_len, y1 + v_line_len, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == false, "Text_DrawBoxCoordsFancy accepted illegal y coord" );

	
		// good values	
		//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence.", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
		//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence. Many are shorter. Like this. Heyo! Hello-Goodbye!", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
// 		the_message = General_StrlcpyWithAlloc((char*)"This is a longish sentence but others are longer. Many are shorter. Like this. oooooh, what a nice thingamajig you've got there.", 80*60+1);
// 		the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw (which was still called LisaGraf at this point) to draw circles and ovals very quickly. That was a bit hard to do on the Macintosh, since the math for circles usually involved taking square roots, and the 68000 processor in the Lisa and Macintosh didn't support floating point operations. But Bill had come up with a clever way to do the circle calculation that only used addition and subtraction, not even multiplication or division, which the 68000 could do, but was kind of slow at.\n\nBill's technique used the fact the sum of a sequence of odd numbers is always the next perfect square (For example, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16, etc). So he could figure out when to bump the dependent coordinate value by iterating in a loop until a threshold was exceeded. This allowed QuickDraw to draw ovals very quickly.\n\nBill fired up his demo and it quickly filled the Lisa screen with randomly-sized ovals, faster than you thought was possible. But something was bothering Steve Jobs. 'Well, circles and ovals are good, but how about drawing rectangles with rounded corners? Can we do that now, too?'\n\n'No, there's no way to do that. In fact it would be really hard to do, and I don't think we really need it'.", 80*60+1);
		the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw (which was still called LisaGraf at this point) to draw circles and ovals very quickly. That was a bit hard to do on the Macintosh, since the math for circles usually involved taking square roots, and the 68000 processor in the Lisa and Macintosh didn't support floating point operations. But Bill had come up with a clever way to do the circle calculation that only used addition and subtraction, not even multiplication or division, which the 68000 could do, but was kind of slow at.\n\nBill's technique used the fact the sum of a sequence of odd numbers is always the next perfect square (For example, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16, etc). So he could figure out when to bump the dependent coordinate value by iterating in a loop until a threshold was exceeded. This allowed QuickDraw to draw ovals very quickly.\n\nBill fired up his demo and it quickly filled the Lisa screen with randomly-sized ovals, faster than you thought was possible. But something was bothering Steve Jobs. 'Well, circles and ovals are good, but how about drawing rectangles with rounded corners? Can we do that now, too?'\n\n'No, there's no way to do that. In fact it would be really hard to do, and I don't think we really need it'. I think Bill was a little miffed that Steve wasn't raving over the fast ovals and still wanted more.\n\nSteve suddenly got more intense. 'Rectangles with rounded corners are everywhere! Just look around this room!'. And sure enough, there were lots of them, like the whiteboard and some of the desks and tables. Then he pointed out the window. 'And look outside, there's even more, practically everywhere you look!'. He even persuaded Bill to take a quick walk around the block with him, pointing out every rectangle with rounded corners that he could find.\n\n\nWhen Steve and Bill passed a no-parking sign with rounded corners, it did the trick. 'OK, I give up', Bill pleaded. 'I'll see if it's as hard as I thought.' He went back home to work on it.\n\nBill returned to Texaco Towers the following afternoon, with a big smile on his face. His demo was now drawing rectangles with beautifully rounded corners blisteringly fast, almost at the speed of plain rectangles.", 80*60+1);
// 		the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw (which was still called LisaGraf at this point) to draw circles and ovals very quickly. That was a bit hard to do on the Macintosh, since the math for circles usually involved taking square roots, and the 68000 processor in the Lisa and Macintosh didn't support floating point operations. But Bill had come up with a clever way to do the circle calculation that only used addition and subtraction, not even multiplication or division, which the 68000 could do, but was kind of slow at.\n\nBill's technique used the fact the sum of a sequence of odd numbers is always the next perfect square (For example, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16, etc). So he could figure out when to bump the dependent coordinate value by iterating in a loop until a threshold was exceeded. This allowed QuickDraw to draw ovals very quickly.\n\nBill fired up his demo and it quickly filled the Lisa screen with randomly-sized ovals, faster than you thought was possible. But something was bothering Steve Jobs. 'Well, circles and ovals are good, but how about drawing rectangles with rounded corners? Can we do that now, too?'\n\n'No, there's no way to do that. In fact it would be really hard to do, and I don't think we really need it'. I think Bill was a little miffed that Steve wasn't raving over the fast ovals and still wanted more.\n\nSteve suddenly got more intense. 'Rectangles with rounded corners are everywhere! Just look around this room!'. And sure enough, there were lots of them, like the whiteboard and some of the desks and tables. Then he pointed out the window. 'And look outside, there's even more, practically everywhere you look!'. He even persuaded Bill to take a quick walk around the block with him, pointing out every rectangle with rounded corners that he could find.\n\n\nWhen Steve and Bill passed a no-parking sign with rounded corners, it did the trick. 'OK, I give up', Bill pleaded. 'I'll see if it's as hard as I thought.' He went back home to work on it.\n\nBill returned to Texaco Towers the following afternoon, with a big smile on his face. His demo was now drawing rectangles with beautifully rounded corners blisteringly fast, almost at the speed of plain rectangles. When he added the code to LisaGraf, he named the new primitive 'RoundRects'. Over the next few months, roundrects worked their way into various parts of the user interface, and soon became indispensable.\n\nThe Code\n\nAuthor: Bill Atkinson\nYear: 1981\n\nQuickDraw is the Macintosh library for creating bit-mapped graphics, which was used by MacPaint and other applications. It consists of a total of 17,101 lines in 36 files, all written in assembler language for the 68000.\n\n               .INCLUDE  GRAFTYPES.TEXT\n;-----------------------------------------------------------\n;\n;\n;     ****   ****   *****   ***   *****   ***\n;     *   *  *   *  *      *   *    *    *   *\n;     *   *  *   *  *      *        *    *\n;     ****   ****   ***    *        *     ***\n;     * *    * *    *      *        *        *\n;     *  *   *  *   *      *   *    *    *   *\n;     *   *  *   *  *****   ***     *     ***\n;\n;\n;  procedures for operating on RoundRects.\n;\n;\n    .PROC StdRRect,4\n    .REF  CheckPic,DPutPicByte,PutPicVerb,PutPicLong,PutPicRect\n    .REF  PutOval,PushVerb,DrawArc\n;---------------------------------------------------------------\n;\n;  PROCEDURE StdRRect(verb: GrafVerb; r: Rect; ovWd,ovHt: INTEGER);\n;\n;  A6 OFFSETS OF PARAMS AFTER LINK:\n;\nPARAMSIZE       .EQU    10\nVERB            .EQU    PARAMSIZE+8-2           ;GRAFVERB\nRECT            .EQU    VERB-4                  ;LONG, ADDR OF RECT\nOVWD            .EQU    RECT-2                  ;WORD\nOVHT            .EQU    OVWD-2                  ;WORD\n            LINK    A6,#0                           ;NO LOCALS\n            MOVEM.L D7/A3-A4,-(SP)                  ;SAVE REGS\n            MOVE.B  VERB(A6),D7                     ;GET VERB\n            JSR     CHECKPIC                        ;SET UP A4,A3 AND CHECK PICSAVE\n            BLE.S   NOTPIC                          ;BRANCH IF NOT PICSAVE\n            MOVE.B  D7,-(SP)                        ;PUSH VERB\n            JSR     PutPicVerb                      ;PUT ADDIONAL PARAMS TO THEPIC\n;\n;  CHECK FOR NEW OVAL SIZE\n;\n            MOVE.L  PICSAVE(A3),A0                  ;GET PICSAVE HANDLE\n            MOVE.L  (A0),A0                         ;DE-REFERENCE PICSAVE\n            MOVE.L  OVHT(A6),D0                     ;GET OVWD AND OVHT\n            CMP.L   PICOVSIZE(A0),D0                ;SAME AS CURRENT OVAL SIZE ?\n            BEQ.S   OVALOK                          ;YES, CONTINUE\n            MOVE.L  D0,PICOVSIZE(A0)                ;NO, UPDATE STATE VARIABLE\n            MOVE.L  D0,-(SP)                        ;PUSH OVSIZE FOR PutPicLong CALL\n            MOVEQ   #$0B,D0\n            JSR     DPutPicByte                     ;PUT OVSIZE OPCODE\n            JSR     PutPicLong                      ;PUT NEW OVAL SIZE DATA\nOVALOK  MOVEQ   #$40,D0                         ;PUT RRECT NOUN IN HI NIBBLE\n            ADD     D7,D0                           ;PUT VERB IN LO NIBBLE\n            MOVE.B  D0,-(SP)                        ;PUSH OPCODE\n            MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            JSR     PutPicRect                      ;PUT OPCODE AND RECTANGLE\nNOTPIC  MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            CLR.B   -(SP)                           ;PUSH HOLLOW = FALSE\n            TST.B   D7                              ;IS VERB FRAME ?\n            BNE.S   DOIT                            ;NO, CONTINUE\n            TST.L   RGNSAVE(A3)                     ;YES, IS RGNSAVE TRUE ?\n            BEQ.S   NOTRGN                          ;NO, CONTINUE\n            MOVE.L  RECT(A6),-(SP)                  ;YES, PUSH ADDR OF RECT\n            MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD, OVHT\n            MOVE.L  RGNBUF(A4),-(SP)                ;PUSH RGNBUF\n            PEA     RGNINDEX(A4)                    ;PUSH VAR RGNINDEX\n            PEA     RGNMAX(A4)                      ;PUSH VAR RGNMAX\n            JSR     PutOval                         ;ADD AN OVAL TO THERGN\nNOTRGN  MOVE.B  #1,(SP)                         ;REPLACE, PUSH HOLLOW = TRUE\nDOIT    MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD,OVHT\n            JSR     PushVerb                        ;PUSH MODE AND PATTERN\n            CLR     -(SP)                           ;PUSH STARTANGLE = 0\n            MOVE    #360,-(SP)                      ;PUSH ARCANGLE = 360", 80*60+1);

		// 	the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw", 80*60+1);

		// 	the_message = General_StrlcpyWithAlloc((char*)"\n\n\nLINE ONE\n\nLINE TWO", 80*60+1);
		//  	the_message = General_StrlcpyWithAlloc((char*)"THISISAREALLYBIGWORDBIGGERTHANANYYOUCANTHINK_OF_OR_AT_LEAST_I_THINK_SO", 80*60+1);

		x1 = 3;
		y1 = 6;
		x2 = 67;
		y2 = 50;
		Text_DrawStringInBox(ID_CHANNEL_A, x1, y1, x2, y2, the_message, FG_COLOR_OLIVE, BG_COLOR_BROWN);

		x1 = 20;
		y1 = 20;
		x2 = 40;
		y2 = 40;
		Text_DrawStringInBox(ID_CHANNEL_B, x1, y1, x2, y2, the_message, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN);
	}

	
	//exit(0);
	//sys_exit(0);
	{
// 		void*	ptr_to_hell = (void*)0x20000;
// 		goto *ptr_to_hell;
		unsigned long int i;
		for (i=1; i>0; i++)
		{
// 			Text_FillBoxSlow(ID_CHANNEL_B, 0, 10, 50, 55, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE, char_and_attr);
		}
	}
}