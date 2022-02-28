// unit testing framework
#include "minunit.h"

// project includes
#include "test_base.h"
#include "lib_general.h"
#include "lib_general_a2560.h"

// class being tested
#include "lib_text.h"

// A2650 includes

// variables needed for testing

extern Screen global_screen[2];



// static int foo = 0;
// static int bar = 0;
// static double dbar = 0.1;
// static const char* foostring = "Thisstring";
// static const char* newkey1 = (char*)"newkey1";
// static const char* newkey1case = (char*)"NewKey1";
// static const char* newkey2 = (char*)"newkey2";
// static const char* newvalue1 = (char*)"foo";
// static const char* newvalue2 = (char*)"BAR";
// static const char* boolkey1 = (char*)"mybool1";
// static const char* boolkey2 = (char*)"mybool2";
// static const char* boolkey3 = (char*)"mybool3";
// static const char* boolstring = (char*)"false";
// static const char* intkey = (char*)"myint";
// static const char* intstring = (char*)"12345";
// static int myint = 12345;

void text_test_setup(void)	// this is called EVERY test
{
// 	foo = 7;
// 	bar = 4;
// 	
}


void text_test_teardown(void)	// this is called EVERY test
{

}


MU_TEST(text_test_block_copy)
{
	char*	buffer1;
	char*	buffer2;
	
	mu_assert( (buffer1 = (char*)calloc(TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING, sizeof(char)) ) != NULL, "could not alloc space for screen buffer 1");
 	mu_assert( (buffer2 = (char*)calloc(TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING, sizeof(char)) ) != NULL, "could not alloc space for screen buffer 2");
	//DEBUG_OUT(("%s %d: buffer1=%p, buffer2=%p", buffer1, buffer2));
	// can't say why, but in this function, when I get out 2 buffers, the 2nd appears to fail. don't get assert failure though, but if used, crashes morfe. 
	
	// copy text on channel B, to off-screen buffer 1	
	mu_assert( Text_CopyScreen(ID_CHANNEL_B, buffer1, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy chan B char to buffer 1" );
 
 	// copy text on channel A, to off-screen buffer 2
 	mu_assert( Text_CopyScreen(ID_CHANNEL_A, buffer2, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy chan A char to buffer 2" );
 	
 	// copy text in offscreen buffer 1, to channel A
 	mu_assert( Text_CopyScreen(ID_CHANNEL_A, buffer1, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy buffer1 to chan A char" );
 
 	// copy text in offscreen buffer 2, to channel B
	mu_assert( Text_CopyScreen(ID_CHANNEL_B, buffer2, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy buffer2 to chan B char" );
 	
 	// copy attr on channel B, to off-screen buffer 1	
	mu_assert( Text_CopyScreen(ID_CHANNEL_B, buffer1, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy chan B attr to buffer 1" );
 
 	// copy attr on channel A, to off-screen buffer 2
	mu_assert( Text_CopyScreen(ID_CHANNEL_A, buffer2, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy chan A attr to buffer 2" );
 	
 	// copy attr in offscreen buffer 1, to channel A
	mu_assert( Text_CopyScreen(ID_CHANNEL_A, buffer1, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy buffer1 to chan A attr" );
 
 	// copy attr in offscreen buffer 2, to channel B
// 	mu_assert( Text_CopyScreen(ID_CHANNEL_B, buffer2, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy buffer2 to chan B attr" );


// 	// copy text on channel B, to off-screen buffer 1	
// 	mu_assert( Text_CopyCharMemFromScreen(ID_CHANNEL_B, buffer1) == true, "Could not copy chan B char to buffer 1" );
// 
// 	// copy text on channel A, to off-screen buffer 2
// 	mu_assert( Text_CopyCharMemFromScreen(ID_CHANNEL_A, buffer2) == true, "Could not copy chan A char to buffer 2" );
// 	
// 	// copy text in offscreen buffer 1, to channel A
// 	mu_assert( Text_CopyCharMemToScreen(ID_CHANNEL_A, buffer1) == true, "Could not copy buffer1 to chan A char" );
// 
// 	// copy text in offscreen buffer 2, to channel B
// 	mu_assert( Text_CopyCharMemToScreen(ID_CHANNEL_B, buffer2) == true, "Could not copy buffer2 to chan B char" );
// 	
// 	// copy attr on channel B, to off-screen buffer 1	
// 	mu_assert( Text_CopyAttrMemFromScreen(ID_CHANNEL_B, buffer1) == true, "Could not copy chan B attr to buffer 1" );
// 
// 	// copy attr on channel A, to off-screen buffer 2
// 	mu_assert( Text_CopyAttrMemFromScreen(ID_CHANNEL_A, buffer2) == true, "Could not copy chan A attr to buffer 2" );
// 	
// 	// copy attr in offscreen buffer 1, to channel A
// 	mu_assert( Text_CopyAttrMemToScreen(ID_CHANNEL_A, buffer1) == true, "Could not copy buffer1 to chan A attr" );
// 
// 	// copy attr in offscreen buffer 2, to channel B
// 	mu_assert( Text_CopyAttrMemToScreen(ID_CHANNEL_B, buffer2) == true, "Could not copy buffer2 to chan B attr" );
	
	free(buffer1);
	free(buffer2);
}


MU_TEST(text_test_block_copy_box)
{
	signed int		x;
	signed int		y;
	signed int		h_line_len;
	signed int		v_line_len;
	char*			buffer1;
	char*			buffer2;
	
	x = 45;
	y = 4;
	h_line_len = 6;
	v_line_len = 6;
	
	// get out 2 buffers that are the full size of the screens. this block copy is designed to use same offsets as a normal sized screen. 
	mu_assert( (buffer1 = (char*)calloc(TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING, sizeof(char)) ) != NULL, "could not alloc space for screen buffer 1");
	mu_assert( (buffer2 = (char*)calloc(TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING, sizeof(char)) ) != NULL, "could not alloc space for screen buffer 2");
//	printf("box copy buffers ok\n\n");
	
	// copy text on channel B, to off-screen buffer 1	
	mu_assert( Text_CopyMemBox(ID_CHANNEL_B, buffer1, x, y, x+h_line_len, y+v_line_len, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy box of chan B char to buffer 1" );

	// copy text on channel A, to off-screen buffer 2
	mu_assert( Text_CopyMemBox(ID_CHANNEL_A, buffer2, 0, 0, 71, 8, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy box of chan A char to buffer 2" );
	
	// copy text in offscreen buffer 1, to channel A
	mu_assert( Text_CopyMemBox(ID_CHANNEL_A, buffer1, x, y, x+h_line_len, y+v_line_len, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_CHAR == true),  "Could not copy box of buffer1 to chan A char" );

	// copy text in offscreen buffer 2, to channel B
	mu_assert( Text_CopyMemBox(ID_CHANNEL_B, buffer2, 0, 0, 71, 8, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_CHAR == true), "Could not copy box of buffer2 to chan B char" );
	
	// copy attr on channel B, to off-screen buffer 1	
	mu_assert( Text_CopyMemBox(ID_CHANNEL_B, buffer1, x, y, x+h_line_len, y+v_line_len, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy box of chan B attr to buffer 1" );

	// copy attr on channel A, to off-screen buffer 2
	mu_assert( Text_CopyMemBox(ID_CHANNEL_A, buffer2, 0, 0, 71, 8, SCREEN_COPY_FROM_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy box of chan A attr to buffer 2" );
	
	// copy attr in offscreen buffer 1, to channel A
	mu_assert( Text_CopyMemBox(ID_CHANNEL_A, buffer1, x, y, x+h_line_len, y+v_line_len, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy box of buffer1 to chan A attr" );

	// copy attr in offscreen buffer 2, to channel B
 	mu_assert( Text_CopyMemBox(ID_CHANNEL_B, buffer2, 0, 0, 71, 8, SCREEN_COPY_TO_SCREEN, SCREEN_FOR_TEXT_ATTR == true), "Could not copy box of buffer2 to chan B attr" );
		
	free(buffer1);
	free(buffer2);
}


MU_TEST(text_test_fill_text)
{
	mu_assert( Text_FillCharMem(ID_CHANNEL_A, 'Z'), "Could not fill character memory in channel A" );
	//mu_assert( Text_FillCharMem(ID_CHANNEL_B, 4), "Could not fill character memory in channel B" );
	// 4 = diamond. good mix of fore/back color
}


MU_TEST(text_test_fill_attr)
{
	mu_assert( Text_FillAttrMem(ID_CHANNEL_A, 127), "Could not fill attribute memory in channel A" );
	//mu_assert( Text_FillAttrMem(ID_CHANNEL_B, 148), "Could not fill attribute memory in channel B" );
		// 31=black on white
		// 64=dark blue on black
		// 96=dark cyan on black
		// 112=medium gray on black
		// 128=medium gray on black
		// 138=black on light green
		// 139=black on bright yellow
		// 140=gray? on medium blue
		// 141=gray? on pink
		// 142=gray? on light cyan

		// 143=black/gray? on white
		// 15=black on white
	
		// 144=red on black
		// 16=dark red on black
	
		// 145=light red on dark red
		// 17=dark red on dark red
	
		// 146=light red on medium green
		// 18=dark red on medium green
	
		// 147=light red on olive
		// 19=dark red on medium green?
	
		// 148=light red on dark blue
}


MU_TEST(text_test_fill_box)
{
	// good values
// 	mu_assert( Text_FillBoxSlow(ID_CHANNEL_A, 0, 6, 15, 8, CH_CHECKERED1, FG_COLOR_OLIVE, BG_COLOR_BROWN, char_and_attr) == true, "Text_FillBoxSlow failed" );
// 	mu_assert( Text_FillBoxSlow(ID_CHANNEL_A, 21, 5, 39, 7, CH_CHECKERED2, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE, char_and_attr) == true, "Text_FillBoxSlow failed" );
	mu_assert( Text_FillBox(ID_CHANNEL_A, 3, 6, 67, 50, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE) == true, "Text_FillBox failed" );
	mu_assert( Text_FillBox(ID_CHANNEL_B, 21, 21, 40, 40, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE) == true, "Text_FillBox failed" );

	// bad values
// 	mu_assert( Text_FillBoxSlow(200, 0, 6, 15, 8, CH_CHECKERED1, FG_COLOR_OLIVE, BG_COLOR_BROWN, char_and_attr) == false, "Text_FillBoxSlow accepted an illegal screen ID" );
// 	mu_assert( Text_FillBox(ID_CHANNEL_B, -67, 6, 72, 30, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE) == false, "Text_FillBoxSlow accepted an illegal x coord" );
}


MU_TEST(text_test_invert_box)
{
	signed int i;
	
	for (i = 0; i < 999; i++)
	{
		mu_assert( Text_InvertBox(ID_CHANNEL_B, 0, 6, 15, 8), "Could not invert color of a box" );
	}
	
	mu_assert( Text_InvertBox(ID_CHANNEL_B, 50, 13, 71, 16), "Could not invert color of a box" );
}


MU_TEST(text_test_font_overwrite)
{
//	mu_assert( Text_UpdateFontData(ID_CHANNEL_A, (char*)0x000000), "Could not replace font data for channel A" );
	mu_assert( Text_UpdateFontData(ID_CHANNEL_B, (char*)0x000000), "Could not replace font data for channel B" );
}


MU_TEST(text_test_show_font)
{
	mu_assert( Text_ShowFontChars(ID_CHANNEL_A), "Could not show font chars for channel A" );
// 	mu_assert( Text_ShowFontChars(ID_CHANNEL_B), "Could not show font chars for channel B" );
}


//test char placement
MU_TEST(text_test_char_placement)
{
	signed int	x;
	signed int	y;
	
	for (y = 4; y < 40; y = y+2)
	{
		for (x = 0; x < 50; x++)
		{
			mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, x, y, 'X'), "text char placement failed" );
		}
	}
	
	// test some illegal parameters, and make sure the produce fails
//  	mu_assert( Text_SetCharAtXY(3, 0, 0, 'X') == false, "Text_SetCharAtXY accepted illegal screen ID" );
//  	mu_assert( Text_SetCharAtXY(-1, 0, 2, 'a') == false, "Text_SetCharAtXY accepted illegal screen ID" );
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, -1, 3, 'b') == false, "Text_SetCharAtXY accepted illegal coordinates" );
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, -1, -1, 'c') == false, "Text_SetCharAtXY accepted illegal coordinates" );
// no idea why, but it seems that any 4 of these can run safely, and the 5th or 6th will cause morfe to crash. 
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, 0, -1, 'd') == false, "Text_SetCharAtXY accepted illegal coordinates" );
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, 500, 4, 'e') == false, "Text_SetCharAtXY accepted illegal coordinates" );
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, 500, 500, 'f') == false, "Text_SetCharAtXY accepted illegal coordinates" );
// 	mu_assert( Text_SetCharAtXY(ID_CHANNEL_A, 0, 500, 'g') == false, "Text_SetCharAtXY accepted illegal coordinates" );
}


// char and color writing
MU_TEST(text_test_char_and_attr_writing)
{
// same story here: 4 or so works ok, add more, and it's likely to crash. 
 	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_A, 0, 4, 33, FG_COLOR_BLACK, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
 	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_A, 1, 4, 34, FG_COLOR_DK_RED, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 2, 4, 35, FG_COLOR_GREEN, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 3, 4, 36, FG_COLOR_BLUE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 4, 4, 37, FG_COLOR_OLIVE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 5, 4, 38, FG_COLOR_MED_CYAN, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 6, 4, 39, FG_COLOR_VIOLET, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 7, 4, 40, FG_COLOR_LT_GRAY, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 8, 4, 41, FG_COLOR_BROWN, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 9, 4, 42, FG_COLOR_BLACK_RED, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 10, 4, 43, FG_COLOR_BLACK_GREEN, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 11, 4, 44, FG_COLOR_BLACK_BLUE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 12, 4, 45, FG_COLOR_DK_GRAY, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 13, 4, 46, FG_COLOR_MED_GRAY, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 14, 4, 47, FG_COLOR_WHITE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 15, 4, 48, FG_COLOR_OLIVE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 0, 5, 33, FG_COLOR_WHITE, BG_COLOR_BLACK) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 1, 5, 34, FG_COLOR_WHITE, BG_COLOR_DK_RED) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 2, 5, 35, FG_COLOR_WHITE, BG_COLOR_GREEN) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 3, 5, 36, FG_COLOR_WHITE, BG_COLOR_BLUE) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 4, 4, 37, FG_COLOR_WHITE, BG_COLOR_DK_OLIVE) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 5, 5, 38, FG_COLOR_WHITE, BG_COLOR_DK_CYAN) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 6, 5, 39, FG_COLOR_WHITE, BG_COLOR_DK_VIOLET) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 7, 5, 40, FG_COLOR_WHITE, BG_COLOR_DK_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 8, 5, 41, FG_COLOR_WHITE, BG_COLOR_DK_ORANGE) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 9, 5, 42, FG_COLOR_WHITE, BG_COLOR_BROWN) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 10, 5, 43, FG_COLOR_WHITE, BG_COLOR_BLACK_RED) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 11, 5, 44, FG_COLOR_WHITE, BG_COLOR_BLACK_GREEN) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 12, 5, 45, FG_COLOR_WHITE, BG_COLOR_BLACK_BLUE) == true, "Text_SetCharAndColorAtXY failed" );
//  	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 13, 5, 46, FG_COLOR_WHITE, BG_COLOR_MED_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
 	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 14, 5, 47, FG_COLOR_WHITE, BG_COLOR_LT_GRAY) == true, "Text_SetCharAndColorAtXY failed" );
 	mu_assert( Text_SetCharAndColorAtXY(ID_CHANNEL_B, 15, 5, 48, FG_COLOR_WHITE, BG_COLOR_WHITE) == true, "Text_SetCharAndColorAtXY failed" );
}


// test char and color reading
MU_TEST(text_test_char_and_attr_reading)
{
	unsigned char	the_color;
	unsigned char	the_value;
	unsigned char	the_char;
	unsigned char	the_attribute_value;
	signed int		x;
	signed int		y;
	
	x = 0;
	y = 6;
	the_attribute_value = ((COLOR_ORANGE << 4) | BG_COLOR_BLACK_RED);

	// set known chars and colors to test again
	Text_SetAttrAtXY(ID_CHANNEL_A, x, y, FG_COLOR_WHITE, BG_COLOR_BLACK);
	Text_SetAttrAtXY(ID_CHANNEL_A, x+1, y, FG_COLOR_VIOLET, BG_COLOR_DK_GRAY);
	Text_SetAttrAtXY(ID_CHANNEL_A, x+2, y, COLOR_ORANGE, BG_COLOR_BLACK_RED);
	Text_SetCharAtXY(ID_CHANNEL_A, x, y, CH_DIAMOND);
	Text_SetCharAtXY(ID_CHANNEL_A, x+1, y, CH_CLUB);
	Text_SetCharAtXY(ID_CHANNEL_A, x+2, y, CH_SPADE);
	
	mu_assert( (the_color = Text_GetForeColorAtXY(ID_CHANNEL_A, x, y)) == FG_COLOR_WHITE, "Text_GetForeColorAtXY failed" );
	mu_assert( (the_color = Text_GetBackColorAtXY(ID_CHANNEL_A, x, y)) == BG_COLOR_BLACK, "Text_GetBackColorAtXY failed" );
	
	x++;
	mu_assert( (the_color = Text_GetForeColorAtXY(ID_CHANNEL_A, x, y)) == FG_COLOR_VIOLET, "Text_GetForeColorAtXY failed" );
	mu_assert( (the_color = Text_GetBackColorAtXY(ID_CHANNEL_A, x, y)) == BG_COLOR_DK_GRAY, "Text_GetBackColorAtXY failed" );

	x++;
	mu_assert( (the_color = Text_GetAttrAtXY(ID_CHANNEL_A, x, y)) == the_attribute_value, "Text_GetAttrAtXY failed");
	
	x = 0;
	mu_assert( (the_char = Text_GetCharAtXY(ID_CHANNEL_A, x, y)) == CH_DIAMOND, "Text_GetCharAtXY failed");	
	x++;
	mu_assert( (the_char = Text_GetCharAtXY(ID_CHANNEL_A, x, y)) == CH_CLUB, "Text_GetCharAtXY failed");	
	x++;
	mu_assert( (the_char = Text_GetCharAtXY(ID_CHANNEL_A, x, y)) == CH_SPADE, "Text_GetCharAtXY failed");	
}


MU_TEST(text_test_line_drawing)
{
	signed int		x;
	signed int		y;
	signed int		line_len;
	unsigned char	the_char;
	
	// good values	
	x = 20;
	y = 4;
	line_len = 20;
	the_char = CH_WALL_H;	
 	mu_assert( Text_DrawHLine(ID_CHANNEL_A, x, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BLUE, char_only) == true, "Text_DrawHLine failed" );
	
	y = 8;
 	mu_assert( Text_DrawHLine(ID_CHANNEL_A, x, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BLUE, char_and_attr) == true, "Text_DrawHLine failed" );
	
	y = 4;
	line_len = 4;
	the_char = CH_WALL_V;	
 	mu_assert( Text_DrawVLine(ID_CHANNEL_A, x, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BLUE, attr_only) == true, "Text_DrawVLine failed" );

	x = x + 20;	
 	mu_assert( Text_DrawVLine(ID_CHANNEL_A, x, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == true, "Text_DrawVLine failed" );

	// bad values
//  	mu_assert( Text_DrawVLine(-1, x, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == false, "Text_DrawVLine accepted illegal screen ID" );
//   	mu_assert( Text_DrawVLine(ID_CHANNEL_B, -1, y, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == false, "Text_DrawVLine accepted illegal x coord" );
//  	mu_assert( Text_DrawVLine(ID_CHANNEL_B, x, 425, line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == false, "Text_DrawVLine accepted illegal y coord" );
	

}


MU_TEST(text_test_basic_box_coords)
{
	signed int		x;
	signed int		y;
	signed int		h_line_len;
	signed int		v_line_len;
	unsigned char	the_char;
	
	x = 45;
	y = 4;
	h_line_len = 6;
	v_line_len = 6;
	the_char = CH_CHECKERED1;

	// good values	
 	mu_assert( Text_DrawBoxCoords(ID_CHANNEL_A, x, y, x + h_line_len, y + v_line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == true, "Text_DrawBoxCoords failed" );

	// bad values
	

}


MU_TEST(text_test_basic_box_hw)
{
	signed int		x;
	signed int		y;
	signed int		h_line_len;
	signed int		v_line_len;
	unsigned char	the_char;
	
	x = 60;
	y = 6;
	h_line_len = 6;
	v_line_len = 6;
	the_char = CH_CHECKERED3;

	// good values	
 	mu_assert(Text_DrawBox(ID_CHANNEL_A, x, y, h_line_len, v_line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == true, "Text_DrawBox failed" );

	x += 7;
	y += 2;
 	mu_assert(Text_DrawBox(ID_CHANNEL_A, x, y, h_line_len-2, v_line_len+5, --the_char, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN, char_and_attr) == true, "Text_DrawBox failed" );


	// bad values
 	mu_assert(Text_DrawBox(ID_CHANNEL_B, -10, y, h_line_len, v_line_len, the_char, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN, char_and_attr) == false, "Text_DrawBox accepted illegal x coord" );
}


MU_TEST(text_test_fancy_box)
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
	mu_assert( Text_FillBox(ID_CHANNEL_A, x1+1, y1+1, x2-1, y2-1, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE) == true, "Text_FillBox failed" );
 	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_A, x1, y1, x2, y2, FG_COLOR_BLACK_BLUE, BG_COLOR_BROWN) == true, "Text_DrawBoxCoordsFancy failed" );

	x1 = 19;
	y1 = 19;
	x2 = 41;
	y2 = 41;
// 	h_line_len = 22;
// 	v_line_len = 22;
//  	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_B, x1, y1, x1 + h_line_len, y1 + v_line_len, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawBoxCoordsFancy failed" );
	mu_assert( Text_FillBox(ID_CHANNEL_B, x1+1, y1+1, x2-1, y2-1, CH_CHECKERED3, FG_COLOR_BLUE, BG_COLOR_BLACK_BLUE) == true, "Text_FillBox failed" );
 	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_B, x1, y1, x2, y2, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawBoxCoordsFancy failed" );

	// bad values
//  	mu_assert(Text_DrawBoxCoordsFancy(ID_CHANNEL_A, x1, 1999, x1 + h_line_len, y1 + v_line_len, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == false, "Text_DrawBoxCoordsFancy accepted illegal y coord" );

	
	// good values	
   	//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence.", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
  	//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence. Many are shorter. Like this. Heyo! Hello-Goodbye!", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
//    	mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a longish sentence but others are longer. Many are shorter. Like this. oooooh, what a nice thingamajig you've got there.", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
	the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw (which was still called LisaGraf at this point) to draw circles and ovals very quickly. That was a bit hard to do on the Macintosh, since the math for circles usually involved taking square roots, and the 68000 processor in the Lisa and Macintosh didn't support floating point operations. But Bill had come up with a clever way to do the circle calculation that only used addition and subtraction, not even multiplication or division, which the 68000 could do, but was kind of slow at.\n\nBill's technique used the fact the sum of a sequence of odd numbers is always the next perfect square (For example, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16, etc). So he could figure out when to bump the dependent coordinate value by iterating in a loop until a threshold was exceeded. This allowed QuickDraw to draw ovals very quickly.\n\nBill fired up his demo and it quickly filled the Lisa screen with randomly-sized ovals, faster than you thought was possible. But something was bothering Steve Jobs. 'Well, circles and ovals are good, but how about drawing rectangles with rounded corners? Can we do that now, too?'\n\n'No, there's no way to do that. In fact it would be really hard to do, and I don't think we really need it'. I think Bill was a little miffed that Steve wasn't raving over the fast ovals and still wanted more.\n\nSteve suddenly got more intense. 'Rectangles with rounded corners are everywhere! Just look around this room!'. And sure enough, there were lots of them, like the whiteboard and some of the desks and tables. Then he pointed out the window. 'And look outside, there's even more, practically everywhere you look!'. He even persuaded Bill to take a quick walk around the block with him, pointing out every rectangle with rounded corners that he could find.\n\n\nWhen Steve and Bill passed a no-parking sign with rounded corners, it did the trick. 'OK, I give up', Bill pleaded. 'I'll see if it's as hard as I thought.' He went back home to work on it.\n\nBill returned to Texaco Towers the following afternoon, with a big smile on his face. His demo was now drawing rectangles with beautifully rounded corners blisteringly fast, almost at the speed of plain rectangles. When he added the code to LisaGraf, he named the new primitive 'RoundRects'. Over the next few months, roundrects worked their way into various parts of the user interface, and soon became indispensable.\n\nThe Code\n\nAuthor: Bill Atkinson\nYear: 1981\n\nQuickDraw is the Macintosh library for creating bit-mapped graphics, which was used by MacPaint and other applications. It consists of a total of 17,101 lines in 36 files, all written in assembler language for the 68000.\n\n               .INCLUDE  GRAFTYPES.TEXT\n;-----------------------------------------------------------\n;\n;\n;     ****   ****   *****   ***   *****   ***\n;     *   *  *   *  *      *   *    *    *   *\n;     *   *  *   *  *      *        *    *\n;     ****   ****   ***    *        *     ***\n;     * *    * *    *      *        *        *\n;     *  *   *  *   *      *   *    *    *   *\n;     *   *  *   *  *****   ***     *     ***\n;\n;\n;  procedures for operating on RoundRects.\n;\n;\n    .PROC StdRRect,4\n    .REF  CheckPic,DPutPicByte,PutPicVerb,PutPicLong,PutPicRect\n    .REF  PutOval,PushVerb,DrawArc\n;---------------------------------------------------------------\n;\n;  PROCEDURE StdRRect(verb: GrafVerb; r: Rect; ovWd,ovHt: INTEGER);\n;\n;  A6 OFFSETS OF PARAMS AFTER LINK:\n;\nPARAMSIZE       .EQU    10\nVERB            .EQU    PARAMSIZE+8-2           ;GRAFVERB\nRECT            .EQU    VERB-4                  ;LONG, ADDR OF RECT\nOVWD            .EQU    RECT-2                  ;WORD\nOVHT            .EQU    OVWD-2                  ;WORD\n            LINK    A6,#0                           ;NO LOCALS\n            MOVEM.L D7/A3-A4,-(SP)                  ;SAVE REGS\n            MOVE.B  VERB(A6),D7                     ;GET VERB\n            JSR     CHECKPIC                        ;SET UP A4,A3 AND CHECK PICSAVE\n            BLE.S   NOTPIC                          ;BRANCH IF NOT PICSAVE\n            MOVE.B  D7,-(SP)                        ;PUSH VERB\n            JSR     PutPicVerb                      ;PUT ADDIONAL PARAMS TO THEPIC\n;\n;  CHECK FOR NEW OVAL SIZE\n;\n            MOVE.L  PICSAVE(A3),A0                  ;GET PICSAVE HANDLE\n            MOVE.L  (A0),A0                         ;DE-REFERENCE PICSAVE\n            MOVE.L  OVHT(A6),D0                     ;GET OVWD AND OVHT\n            CMP.L   PICOVSIZE(A0),D0                ;SAME AS CURRENT OVAL SIZE ?\n            BEQ.S   OVALOK                          ;YES, CONTINUE\n            MOVE.L  D0,PICOVSIZE(A0)                ;NO, UPDATE STATE VARIABLE\n            MOVE.L  D0,-(SP)                        ;PUSH OVSIZE FOR PutPicLong CALL\n            MOVEQ   #$0B,D0\n            JSR     DPutPicByte                     ;PUT OVSIZE OPCODE\n            JSR     PutPicLong                      ;PUT NEW OVAL SIZE DATA\nOVALOK  MOVEQ   #$40,D0                         ;PUT RRECT NOUN IN HI NIBBLE\n            ADD     D7,D0                           ;PUT VERB IN LO NIBBLE\n            MOVE.B  D0,-(SP)                        ;PUSH OPCODE\n            MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            JSR     PutPicRect                      ;PUT OPCODE AND RECTANGLE\nNOTPIC  MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            CLR.B   -(SP)                           ;PUSH HOLLOW = FALSE\n            TST.B   D7                              ;IS VERB FRAME ?\n            BNE.S   DOIT                            ;NO, CONTINUE\n            TST.L   RGNSAVE(A3)                     ;YES, IS RGNSAVE TRUE ?\n            BEQ.S   NOTRGN                          ;NO, CONTINUE\n            MOVE.L  RECT(A6),-(SP)                  ;YES, PUSH ADDR OF RECT\n            MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD, OVHT\n            MOVE.L  RGNBUF(A4),-(SP)                ;PUSH RGNBUF\n            PEA     RGNINDEX(A4)                    ;PUSH VAR RGNINDEX\n            PEA     RGNMAX(A4)                      ;PUSH VAR RGNMAX\n            JSR     PutOval                         ;ADD AN OVAL TO THERGN\nNOTRGN  MOVE.B  #1,(SP)                         ;REPLACE, PUSH HOLLOW = TRUE\nDOIT    MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD,OVHT\n            JSR     PushVerb                        ;PUSH MODE AND PATTERN\n            CLR     -(SP)                           ;PUSH STARTANGLE = 0\n            MOVE    #360,-(SP)                      ;PUSH ARCANGLE = 360", 80*60+1);

// 	the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw", 80*60+1);

// 	the_message = General_StrlcpyWithAlloc((char*)"\n\n\nLINE ONE\n\nLINE TWO", 80*60+1);
//  	the_message = General_StrlcpyWithAlloc((char*)"THISISAREALLYBIGWORDBIGGERTHANANYYOUCANTHINK_OF_OR_AT_LEAST_I_THINK_SO", 80*60+1);

	x1 = 3;
	y1 = 6;
	x2 = 67;
	y2 = 50;
  	mu_assert(Text_DrawStringInBox(ID_CHANNEL_A, x1, y1, x2, y2, the_message, FG_COLOR_OLIVE, BG_COLOR_BROWN) == true, "Text_DrawStringInBox failed" );

	x1 = 20;
	y1 = 20;
	x2 = 40;
	y2 = 40;
  	mu_assert(Text_DrawStringInBox(ID_CHANNEL_B, x1, y1, x2, y2, the_message, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawStringInBox failed" );


}


MU_TEST(text_test_draw_string)
{
	char*	the_message;
	
	// good values	
	mu_assert((the_message = General_StrlcpyWithAlloc((char*)"this is a string", 250)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
	mu_assert_string_eq("this is a string", (char*)the_message);
 	mu_assert(Text_DrawStringAtXY(ID_CHANNEL_B, 0, 5, the_message, FG_COLOR_OLIVE, BG_COLOR_BROWN) == true, "Text_DrawStringAtXY failed" );
 	mu_assert(Text_DrawStringAtXY(ID_CHANNEL_B, 67, 4, the_message, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawStringAtXY failed" );
		
	// bad values
 	mu_assert(Text_DrawStringAtXY(ID_CHANNEL_B, -1, 0, the_message, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == false, "Text_DrawBoxCoordsFancy accepted illegal x coord" );
}

MU_TEST(text_test_draw_string_in_box)
{
	char*	the_message;
	
	// good values	
   	//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence.", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
  	//mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a short sentence. Many are shorter. Like this. Heyo! Hello-Goodbye!", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
//    	mu_assert((the_message = General_StrlcpyWithAlloc((char*)"This is a longish sentence but others are longer. Many are shorter. Like this. oooooh, what a nice thingamajig you've got there.", 80*60+1)) != NULL, "General_StrlcpyWithAlloc returned NULL" );
	the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw (which was still called LisaGraf at this point) to draw circles and ovals very quickly. That was a bit hard to do on the Macintosh, since the math for circles usually involved taking square roots, and the 68000 processor in the Lisa and Macintosh didn't support floating point operations. But Bill had come up with a clever way to do the circle calculation that only used addition and subtraction, not even multiplication or division, which the 68000 could do, but was kind of slow at.\n\nBill's technique used the fact the sum of a sequence of odd numbers is always the next perfect square (For example, 1 + 3 = 4, 1 + 3 + 5 = 9, 1 + 3 + 5 + 7 = 16, etc). So he could figure out when to bump the dependent coordinate value by iterating in a loop until a threshold was exceeded. This allowed QuickDraw to draw ovals very quickly.\n\nBill fired up his demo and it quickly filled the Lisa screen with randomly-sized ovals, faster than you thought was possible. But something was bothering Steve Jobs. 'Well, circles and ovals are good, but how about drawing rectangles with rounded corners? Can we do that now, too?'\n\n'No, there's no way to do that. In fact it would be really hard to do, and I don't think we really need it'. I think Bill was a little miffed that Steve wasn't raving over the fast ovals and still wanted more.\n\nSteve suddenly got more intense. 'Rectangles with rounded corners are everywhere! Just look around this room!'. And sure enough, there were lots of them, like the whiteboard and some of the desks and tables. Then he pointed out the window. 'And look outside, there's even more, practically everywhere you look!'. He even persuaded Bill to take a quick walk around the block with him, pointing out every rectangle with rounded corners that he could find.\n\n\nWhen Steve and Bill passed a no-parking sign with rounded corners, it did the trick. 'OK, I give up', Bill pleaded. 'I'll see if it's as hard as I thought.' He went back home to work on it.\n\nBill returned to Texaco Towers the following afternoon, with a big smile on his face. His demo was now drawing rectangles with beautifully rounded corners blisteringly fast, almost at the speed of plain rectangles. When he added the code to LisaGraf, he named the new primitive 'RoundRects'. Over the next few months, roundrects worked their way into various parts of the user interface, and soon became indispensable.\n\nThe Code\n\nAuthor: Bill Atkinson\nYear: 1981\n\nQuickDraw is the Macintosh library for creating bit-mapped graphics, which was used by MacPaint and other applications. It consists of a total of 17,101 lines in 36 files, all written in assembler language for the 68000.\n\n               .INCLUDE  GRAFTYPES.TEXT\n;-----------------------------------------------------------\n;\n;\n;     ****   ****   *****   ***   *****   ***\n;     *   *  *   *  *      *   *    *    *   *\n;     *   *  *   *  *      *        *    *\n;     ****   ****   ***    *        *     ***\n;     * *    * *    *      *        *        *\n;     *  *   *  *   *      *   *    *    *   *\n;     *   *  *   *  *****   ***     *     ***\n;\n;\n;  procedures for operating on RoundRects.\n;\n;\n    .PROC StdRRect,4\n    .REF  CheckPic,DPutPicByte,PutPicVerb,PutPicLong,PutPicRect\n    .REF  PutOval,PushVerb,DrawArc\n;---------------------------------------------------------------\n;\n;  PROCEDURE StdRRect(verb: GrafVerb; r: Rect; ovWd,ovHt: INTEGER);\n;\n;  A6 OFFSETS OF PARAMS AFTER LINK:\n;\nPARAMSIZE       .EQU    10\nVERB            .EQU    PARAMSIZE+8-2           ;GRAFVERB\nRECT            .EQU    VERB-4                  ;LONG, ADDR OF RECT\nOVWD            .EQU    RECT-2                  ;WORD\nOVHT            .EQU    OVWD-2                  ;WORD\n            LINK    A6,#0                           ;NO LOCALS\n            MOVEM.L D7/A3-A4,-(SP)                  ;SAVE REGS\n            MOVE.B  VERB(A6),D7                     ;GET VERB\n            JSR     CHECKPIC                        ;SET UP A4,A3 AND CHECK PICSAVE\n            BLE.S   NOTPIC                          ;BRANCH IF NOT PICSAVE\n            MOVE.B  D7,-(SP)                        ;PUSH VERB\n            JSR     PutPicVerb                      ;PUT ADDIONAL PARAMS TO THEPIC\n;\n;  CHECK FOR NEW OVAL SIZE\n;\n            MOVE.L  PICSAVE(A3),A0                  ;GET PICSAVE HANDLE\n            MOVE.L  (A0),A0                         ;DE-REFERENCE PICSAVE\n            MOVE.L  OVHT(A6),D0                     ;GET OVWD AND OVHT\n            CMP.L   PICOVSIZE(A0),D0                ;SAME AS CURRENT OVAL SIZE ?\n            BEQ.S   OVALOK                          ;YES, CONTINUE\n            MOVE.L  D0,PICOVSIZE(A0)                ;NO, UPDATE STATE VARIABLE\n            MOVE.L  D0,-(SP)                        ;PUSH OVSIZE FOR PutPicLong CALL\n            MOVEQ   #$0B,D0\n            JSR     DPutPicByte                     ;PUT OVSIZE OPCODE\n            JSR     PutPicLong                      ;PUT NEW OVAL SIZE DATA\nOVALOK  MOVEQ   #$40,D0                         ;PUT RRECT NOUN IN HI NIBBLE\n            ADD     D7,D0                           ;PUT VERB IN LO NIBBLE\n            MOVE.B  D0,-(SP)                        ;PUSH OPCODE\n            MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            JSR     PutPicRect                      ;PUT OPCODE AND RECTANGLE\nNOTPIC  MOVE.L  RECT(A6),-(SP)                  ;PUSH ADDR OF RECT\n            CLR.B   -(SP)                           ;PUSH HOLLOW = FALSE\n            TST.B   D7                              ;IS VERB FRAME ?\n            BNE.S   DOIT                            ;NO, CONTINUE\n            TST.L   RGNSAVE(A3)                     ;YES, IS RGNSAVE TRUE ?\n            BEQ.S   NOTRGN                          ;NO, CONTINUE\n            MOVE.L  RECT(A6),-(SP)                  ;YES, PUSH ADDR OF RECT\n            MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD, OVHT\n            MOVE.L  RGNBUF(A4),-(SP)                ;PUSH RGNBUF\n            PEA     RGNINDEX(A4)                    ;PUSH VAR RGNINDEX\n            PEA     RGNMAX(A4)                      ;PUSH VAR RGNMAX\n            JSR     PutOval                         ;ADD AN OVAL TO THERGN\nNOTRGN  MOVE.B  #1,(SP)                         ;REPLACE, PUSH HOLLOW = TRUE\nDOIT    MOVE.L  OVHT(A6),-(SP)                  ;PUSH OVWD,OVHT\n            JSR     PushVerb                        ;PUSH MODE AND PATTERN\n            CLR     -(SP)                           ;PUSH STARTANGLE = 0\n            MOVE    #360,-(SP)                      ;PUSH ARCANGLE = 360", 80*60+1);

// 	the_message = General_StrlcpyWithAlloc((char*)"\nThe Anecdote\n\nBill Atkinson worked mostly at home, but whenever he made significant progress he rushed in to Apple to show it off to anyone who would appreciate it. This time, he visited the Macintosh offices at Texaco Towers to show off his brand new oval routines in Quickdraw, which were implemented using a really clever algorithm.\n\nBill had added new code to QuickDraw", 80*60+1);

// 	the_message = General_StrlcpyWithAlloc((char*)"\n\n\nLINE ONE\n\nLINE TWO", 80*60+1);
//  	the_message = General_StrlcpyWithAlloc((char*)"THISISAREALLYBIGWORDBIGGERTHANANYYOUCANTHINK_OF_OR_AT_LEAST_I_THINK_SO", 80*60+1);


  	mu_assert(Text_DrawStringInBox(ID_CHANNEL_A, 3, 6, 67, 50, the_message, FG_COLOR_OLIVE, BG_COLOR_BROWN) == true, "Text_DrawStringInBox failed" );
  	mu_assert(Text_DrawStringInBox(ID_CHANNEL_B, 21, 21, 40, 40, the_message, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN) == true, "Text_DrawStringInBox failed" );
}


// MU_TEST(test_check)
// {
// 	mu_check(foo == 7);
// }
// 
// MU_TEST(test_check_fail)
// {
// 	mu_check(foo != 7);
// }
// 
// MU_TEST(test_assert)
// {
// 	mu_assert(foo == 7, "foo should be 7");
// }
// 
// MU_TEST(test_assert_fail)
// {
// 	mu_assert(foo != 7, "foo should be <> 7");
// }
// 
// MU_TEST(test_assert_int_eq)
// {
// 	mu_assert_int_eq(4, bar);
// }
// 
// MU_TEST(test_assert_int_eq_fail)
// {
// 	mu_assert_int_eq(5, bar);
// }
// 
// MU_TEST(test_assert_double_eq)
// {
// 	mu_assert_double_eq(0.1, dbar);
// }
// 
// MU_TEST(test_assert_double_eq_fail)
// {
// 	mu_assert_double_eq(0.2, dbar);
// }
// 
// MU_TEST(test_fail)
// {
// 	mu_fail("Fail now!");
// }
// 
// MU_TEST(test_string_eq){
// 	mu_assert_string_eq("Thisstring", foostring);
// }
// 
// MU_TEST(test_string_eq_fail){
// 	mu_assert_string_eq("Thatstring", foostring);
// }

MU_TEST_SUITE(text_test_suite)
{
	long start;
	long end;
	
	start = mu_timer_real();
	
	MU_SUITE_CONFIGURE(&text_test_setup, &text_test_teardown);

// 	MU_RUN_TEST(text_test_fill_text);
// 	MU_RUN_TEST(text_test_fill_attr);
// 	MU_RUN_TEST(text_test_fill_box);
	
//	MU_RUN_TEST(text_test_show_font);

//	MU_RUN_TEST(text_test_char_placement);

// 	MU_RUN_TEST(text_test_block_copy_box);

//	MU_RUN_TEST(text_test_font_overwrite);
// 	MU_RUN_TEST(text_test_update_font);
	
// 	MU_RUN_TEST(text_test_char_and_attr_writing);
// 	MU_RUN_TEST(text_test_char_and_attr_reading);
// 	
// 	MU_RUN_TEST(text_test_line_drawing);
// 	MU_RUN_TEST(text_test_basic_box_coords);
// 	MU_RUN_TEST(text_test_basic_box_hw);
	MU_RUN_TEST(text_test_fancy_box);
// 	
// 	MU_RUN_TEST(text_test_draw_string);
// 	MU_RUN_TEST(text_test_draw_string_in_box);

// 	MU_RUN_TEST(text_test_invert_box);
	
// 	MU_RUN_TEST(text_test_block_copy);
	
	
// 	MU_RUN_TEST(test_check);
// 	MU_RUN_TEST(test_assert);
// 	MU_RUN_TEST(test_assert_int_eq);
// 	MU_RUN_TEST(test_assert_double_eq);
// 
// 	MU_RUN_TEST(test_check_fail);
// 	MU_RUN_TEST(test_assert_fail);
// 	MU_RUN_TEST(test_assert_int_eq_fail);
// 	MU_RUN_TEST(test_assert_double_eq_fail);
// 	
// 	MU_RUN_TEST(test_string_eq);
// 	MU_RUN_TEST(test_string_eq_fail);
// 
// 	MU_RUN_TEST(test_fail);

	end = mu_timer_real();

}

int Text_RunTests(void)
{
	MU_RUN_SUITE(text_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
