/*
 * lib_text.c
 *
 *  Created on: Feb 19, 2022
 *      Author: micahbly
 */





/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

// project includes
#include "lib_text.h"
#include "lib_general.h"
#include "lib_general_a2560.h"

// C includes
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A2650 includes


/*****************************************************************************/
/*                               Definitions                                 */
/*****************************************************************************/



/*****************************************************************************/
/*                               Enumerations                                */
/*****************************************************************************/



/*****************************************************************************/
/*                             Global Variables                              */
/*****************************************************************************/

extern Screen global_screen[2];



/*****************************************************************************/
/*                       Private Function Prototypes                         */
/*****************************************************************************/

// validate screen id, x, y, and colors
boolean Text_ValidateAll(signed int the_screen_id, signed int x, signed int y, unsigned char fore_color, unsigned char back_color);

// validate the coordinates are within the bounds of the specified screen
boolean Text_ValidateXY(signed int the_screen_id, signed int x, signed int y);

// calculate the VRAM location of the specified coordinate
char* Text_GetMemLocForXY(signed int the_screen_id, signed int x, signed int y, boolean for_attr);

// Fill attribute or text char memory. Writes to char memory if for_attr is false.
// calling function must validate the screen ID before passing!
// returns false on any error/invalid input.
boolean Text_FillMemory(signed int the_screen_id, boolean for_attr, unsigned char the_fill);

// Fill character and attribute memory for a specific box area
// calling function must validate screen id, coords, attribute value before passing!
// returns false on any error/invalid input.
boolean Text_FillMemoryBoxBoth(signed int the_screen_id, signed int x, signed int y, signed int width, signed int height, unsigned char the_char, unsigned char the_attribute_value);

// Fill character OR attribute memory for a specific box area
// calling function must validate screen id, coords, attribute value before passing!
// returns false on any error/invalid input.
boolean Text_FillMemoryBox(signed int the_screen_id, signed int x, signed int y, signed int width, signed int height, boolean for_attr, unsigned char the_fill);


/*****************************************************************************/
/*                       Private Function Definitions                        */
/*****************************************************************************/

// **** NOTE: all functions in private section REQUIRE pre-validated parameters. 
// **** NEVER call these from your own functions. Always use the public interface. You have been warned!


// validate screen id, x, y, and colors
boolean Text_ValidateAll(signed int the_screen_id, signed int x, signed int y, unsigned char fore_color, unsigned char back_color)
{
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_INFO(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
			
	if (Text_ValidateXY(the_screen_id, x, y) == false)
	{
		LOG_INFO(("%s %d: illegal coordinates %li, %li", __func__, __LINE__, x, y));
		return false;
	}

	if (fore_color > 15 || back_color > 15)
	{
		LOG_INFO(("%s %d: illegal foreground (%u) or background (%u) color", __func__, __LINE__, fore_color, back_color));
		return false;
	}
	
	return true;
}


// validate the coordinates are within the bounds of the specified screen
boolean Text_ValidateXY(signed int the_screen_id, signed int x, signed int y)
{
	signed int		max_row;
	signed int		max_col;
	
	max_col = global_screen[the_screen_id].text_cols_ - 1;
	max_row = global_screen[the_screen_id].text_rows_ - 1;
	
	if (x < 0 || x > max_col || y < 0 || y > max_row)
	{
		return false;
	}

	return true;
}


// calculate the VRAM location of the specified coordinate
char* Text_GetMemLocForXY(signed int the_screen_id, signed int x, signed int y, boolean for_attr)
{
	char*			the_write_loc;
	//signed int	num_cols;
	
	// LOGIC:
	//   For plotting the VRAM, A2560 (or morfe?) uses a fixed with of 80 cols. 
	//   So even if only 72 are showing, the screen is arranged from 0-71 for row 1, then 80-151 for row 2, etc. 
	
	//num_cols = global_screen[the_screen_id].text_cols_;
	
//	the_write_loc = global_screen[the_screen_id].text_ram_ + (TEXT_COL_COUNT_FOR_PLOTTING * y) + x;
	//the_write_loc = global_screen[the_screen_id].text_ram_ + (num_cols * y) + x;
	//DEBUG_OUT(("%s %d: screen=%i, x=%i, y=%i, num_cols=%i, calc=%i", __func__, __LINE__, (signed int)the_screen_id, x, y, num_cols, (num_cols * y) + x));
	
	if (for_attr)
	{
		the_write_loc = global_screen[the_screen_id].text_attr_ram_ + (TEXT_COL_COUNT_FOR_PLOTTING * y) + x;
	}
	else
	{
		the_write_loc = global_screen[the_screen_id].text_ram_ + (TEXT_COL_COUNT_FOR_PLOTTING * y) + x;
	}
	
	//DEBUG_OUT(("%s %d: screen=%i, x=%i, y=%i, for-attr=%i, calc=%i, loc=%p", __func__, __LINE__, (signed int)the_screen_id, x, y, for_attr, (TEXT_COL_COUNT_FOR_PLOTTING * y) + x, the_write_loc));
	
	return the_write_loc;
}


// Fill attribute or text char memory. Writes to char memory if for_attr is false.
// calling function must validate the screen ID before passing!
// returns false on any error/invalid input.
boolean Text_FillMemory(signed int the_screen_id, boolean for_attr, unsigned char the_fill)
{
	char*			the_write_loc;
	unsigned long	the_write_len;
	
	if (for_attr)
	{
		the_write_loc = global_screen[the_screen_id].text_attr_ram_;
	}
	else
	{
		the_write_loc = global_screen[the_screen_id].text_ram_;
	}

	the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	
	memset(the_write_loc, the_fill, the_write_len);

	return true;
}


// Fill character and attribute memory for a specific box area
// calling function must validate screen id, coords, attribute value before passing!
// returns false on any error/invalid input.
boolean Text_FillMemoryBoxBoth(signed int the_screen_id, signed int x, signed int y, signed int width, signed int height, unsigned char the_char, unsigned char the_attribute_value)
{
	char*			the_char_loc;
	char*			the_attr_loc;
	signed int		max_row;
	
	// set up char and attribute memory initial loc
	the_char_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_CHAR);
	the_attr_loc = the_char_loc + (global_screen[the_screen_id].text_attr_ram_ - global_screen[the_screen_id].text_ram_);
	
	max_row = y + height;
	
	for (; y <= max_row; y++)
	{
		memset(the_char_loc, the_char, width);
		memset(the_attr_loc, the_attribute_value, width);
		the_char_loc += TEXT_COL_COUNT_FOR_PLOTTING;
		the_attr_loc += TEXT_COL_COUNT_FOR_PLOTTING;
	}
			
	return true;
}


// Fill character OR attribute memory for a specific box area
// calling function must validate screen id, coords, attribute value before passing!
// returns false on any error/invalid input.
boolean Text_FillMemoryBox(signed int the_screen_id, signed int x, signed int y, signed int width, signed int height, boolean for_attr, unsigned char the_fill)
{
	char*			the_write_loc;
	signed int		max_row;
	
	// set up initial loc
	the_write_loc = Text_GetMemLocForXY(the_screen_id, x, y, for_attr);
	
	max_row = y + height;
	
	for (; y <= max_row; y++)
	{
		memset(the_write_loc, the_fill, width);
		the_write_loc += TEXT_COL_COUNT_FOR_PLOTTING;
	}
			
	return true;
}



/*****************************************************************************/
/*                        Public Function Definitions                        */
/*****************************************************************************/

// ** NOTE: there is no destructor or constructor for this library, as it does not track any allocated memory. It works on the basis of a screen ID, which corresponds to the text memory for Vicky's Channel A and Channel B video memory.


// **** Block copy functions ****

// Copy a full screen of attr from an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyAttrMemToScreen(signed int the_screen_id, char* the_source_buffer)
{
	char*			the_vram_loc;
	unsigned long	the_write_len;
	
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
	the_vram_loc = global_screen[the_screen_id].text_attr_ram_;
	the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	
	memcpy(the_vram_loc, the_source_buffer, the_write_len);

	return true;
}

// Copy a full screen of attr to an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyAttrMemFromScreen(signed int the_screen_id, char* the_target_buffer)
{
	char*			the_vram_loc;
	unsigned long	the_write_len;
	
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
	the_vram_loc = global_screen[the_screen_id].text_attr_ram_;
	the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	
	memcpy(the_target_buffer, the_vram_loc, the_write_len);

	return true;
}

// Copy a full screen of text from an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyCharMemToScreen(signed int the_screen_id, char* the_source_buffer)
{
	char*			the_vram_loc;
	unsigned long	the_write_len;
	
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
	the_vram_loc = global_screen[the_screen_id].text_ram_;
	the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	
	memcpy(the_vram_loc, the_source_buffer, the_write_len);

	return true;
}

// Copy a full screen of text to an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyCharMemFromScreen(signed int the_screen_id, char* the_target_buffer)
{
	char*			the_vram_loc;
	unsigned long	the_write_len;
	
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
	the_vram_loc = global_screen[the_screen_id].text_ram_;
	the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	
	memcpy(the_target_buffer, the_vram_loc, the_write_len);

	return true;
}


// Copy a full screen of text or attr to or from an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyScreen(signed int the_screen_id, char* the_buffer, boolean to_screen, boolean for_attr)
{
	char*			the_vram_loc;
	signed int		the_write_len;
	
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
		
// this check appears to cause morfe to die
// 	if (the_buffer == NULL)
// 	{
// 		LOG_ERR(("%s %d: passed off-screen buffer was NULL", __func__, __LINE__));
// 		return false;
// 	}

	if (for_attr)
	{
		the_vram_loc = global_screen[the_screen_id].text_attr_ram_;
	}
	else
	{
		the_vram_loc = global_screen[the_screen_id].text_ram_;
	}
	
	//the_write_len = global_screen[the_screen_id].text_cols_ * global_screen[the_screen_id].text_rows_;
	the_write_len = TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING;

	if (to_screen)
	{
		memcpy(the_vram_loc, the_buffer, the_write_len);
		//DEBUG_OUT(("%s %d: vramloc=%p, buffer=%p, to_screen=%i, the_write_len=%i", the_vram_loc, the_buffer, to_screen, the_write_len));
	}
	else
	{
		memcpy(the_buffer, the_vram_loc, the_write_len);
	}

	return true;
}


// Copy a rectangular area of text or attr to or from an off-screen buffer
// returns false on any error/invalid input.
boolean Text_CopyMemBox(signed int the_screen_id, char* the_buffer, signed int x1, signed int y1, signed int x2, signed int y2, boolean to_screen, boolean for_attr)
{
	char*			the_vram_loc;
	char*			the_buffer_loc;
	signed int		the_write_len;
	signed int		initial_offset;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}
	
// this check appears to cause morfe to die
// 	if (the_buffer == NULL)
// 	{
// 		LOG_ERR(("%s %d: passed off-screen buffer was NULL", __func__, __LINE__));
// 		return false;
// 	}

	// get initial read/write locs
	initial_offset = (TEXT_COL_COUNT_FOR_PLOTTING * y1) + x1;
	the_buffer_loc = the_buffer + initial_offset;

	if (for_attr)
	{
		the_vram_loc = global_screen[the_screen_id].text_attr_ram_ + initial_offset;
	}
	else
	{
		the_vram_loc = global_screen[the_screen_id].text_ram_ + initial_offset;
	}
	
	// do copy one line at a time
	
	the_write_len = x2 - x1 + 1;

//	DEBUG_OUT(("%s %d: vramloc=%p, buffer=%p, bufferloc=%p, to_screen=%i, the_write_len=%i", the_vram_loc, the_buffer, the_buffer_loc, to_screen, the_write_len));

	for (; y1 <= y2; y1++)
	{
		if (to_screen)
		{
			memcpy(the_vram_loc, the_buffer_loc, the_write_len);
		}
		else
		{
			memcpy(the_buffer_loc, the_vram_loc, the_write_len);
		}
		
		the_buffer_loc += TEXT_COL_COUNT_FOR_PLOTTING;
		the_vram_loc += TEXT_COL_COUNT_FOR_PLOTTING;
	}

	return true;
}



// **** Block fill functions ****


// Fill attribute memory for the passed screen
// returns false on any error/invalid input.
boolean Text_FillAttrMem(signed int the_screen_id, unsigned char the_fill)
{
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
 	return Text_FillMemory(the_screen_id, SCREEN_FOR_TEXT_ATTR, the_fill);
}

// Fill character memory for the passed screen
// returns false on any error/invalid input.
boolean Text_FillCharMem(signed int the_screen_id, unsigned char the_fill)
{
	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}
	
	return Text_FillMemory(the_screen_id, SCREEN_FOR_TEXT_CHAR, the_fill);
}


// Fill character and/or attribute memory for a specific box area
// returns false on any error/invalid input.
// this version uses char-by-char functions, so it is very slow.
boolean Text_FillBoxSlow(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char the_char, unsigned char fore_color, unsigned char back_color, text_draw_choice the_draw_choice)
{
	signed int	dx;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1,fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1 + 1;
	
	for (; y1 <= y2; y1++)
	{
		if (!Text_DrawHLine(the_screen_id, x1, y1, dx, the_char, fore_color, back_color, the_draw_choice))
		{
			LOG_ERR(("%s %d: fill failed", __func__, __LINE__));
			return false;
		}
	}
			
	return true;
}


// Fill character and attribute memory for a specific box area
// returns false on any error/invalid input.
boolean Text_FillBox(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char the_char, unsigned char fore_color, unsigned char back_color)
{
	signed int		dy;
	signed int		dx;
	unsigned char	the_attribute_value;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1 + 1;
	dy = y2 - y1 + 1;

	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);

	return Text_FillMemoryBoxBoth(the_screen_id, x1, y1, dx, dy, the_char, the_attribute_value);
}


// Fill character memory for a specific box area
// returns false on any error/invalid input.
boolean Text_FillBoxCharOnly(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char the_char)
{
	signed int	dy;
	signed int	dx;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1 + 1;
	dy = y2 - y1 + 1;

	return Text_FillMemoryBox(the_screen_id, x1, y1, dx, dy, SCREEN_FOR_TEXT_CHAR, the_char);
}


// Fill attribute memory for a specific box area
// returns false on any error/invalid input.
boolean Text_FillBoxAttrOnly(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char fore_color, unsigned char back_color)
{
	signed int		dy;
	signed int		dx;
	unsigned char	the_attribute_value;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1 + 1;
	dy = y2 - y1 + 1;

	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);

	return Text_FillMemoryBox(the_screen_id, x1, y1, dx, dy, SCREEN_FOR_TEXT_ATTR, the_attribute_value);
}


// Invert the colors of a rectangular block
// As this requires sampling each character cell, it is no faster to for entire screen as opposed to a subset box
boolean Text_InvertBox(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2)
{
	unsigned char	the_attribute_value;
	unsigned char	the_inversed_value;
	char*			the_write_loc;
	signed int		the_col;
	signed int		skip_len;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// get initial read/write loc
	the_write_loc = Text_GetMemLocForXY(the_screen_id, x1, y1, SCREEN_FOR_TEXT_ATTR);	
	
	// amount of cells to skip past once we have written the specified line len
	skip_len = TEXT_COL_COUNT_FOR_PLOTTING - (x2 - x1) - 1;

	for (; y1 <= y2; y1++)
	{
		for (the_col = x1; the_col <= x2; the_col++)
		{
			the_attribute_value = (unsigned char)*the_write_loc;
			
			// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
			the_inversed_value = (((the_attribute_value & 0x0F) << 4) | ((the_attribute_value & 0xF0) >> 4));
			
			*the_write_loc++ = the_inversed_value;
		}

		the_write_loc += skip_len;
	}

	return true;
}




// **** FONT RELATED *****

// replace the current font data with the data at the passed memory buffer
boolean Text_UpdateFontData(signed int the_screen_id, char* new_font_data)
{
	// TEST: check the mem locs I have work in morfe.
	memset(global_screen[the_screen_id].text_font0_ram_, 55, 8*256*1);
	// NO EFFECT: memset(FONT_MEMORY_BANK1, 255, 8*256*1);
	// seems to be expected: apparently the second font is no longer a thing

	return true;
}

// test function to display all 256 font characters
boolean Text_ShowFontChars(signed int the_screen_id)
{
	unsigned char	the_char = 0;
	char*			the_write_loc;
	unsigned short	i;

	if (the_screen_id != ID_CHANNEL_A && the_screen_id != ID_CHANNEL_B)
	{
		LOG_ERR(("%s %d: illegal screen id", __func__, __LINE__));
		return false;
	}

	the_write_loc = global_screen[the_screen_id].text_ram_;

	//printf("\n");

	for (i = 0; i < 256; i++)
	{
		*the_write_loc++ = the_char++;
		//printf("%c", the_char++);
	}

	//printf("\n");
	
	return true;
}



// **** Set char/attr functions *****


// Set a char at a specified x, y coord
boolean Text_SetCharAtXY(signed int the_screen_id, signed int x, signed int y, unsigned char the_char)
{
	char*	the_write_loc;
	
	if (!Text_ValidateAll(the_screen_id, x, y, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id or coordinate", __func__, __LINE__));
		return false;
	}
	
	the_write_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_CHAR);	
 	*the_write_loc = the_char;
	
	return true;
}


// Set the attribute value at a specified x, y coord
boolean Text_SetAttrAtXY(signed int the_screen_id, signed int x, signed int y, unsigned char fore_color, unsigned char back_color)
{
	char*			the_write_loc;
	unsigned char	the_attribute_value;
	
	if (!Text_ValidateAll(the_screen_id, x, y, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}

	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);
	
	the_write_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_ATTR);	
 	*the_write_loc = the_attribute_value;
	
	return true;
}


// Draw a char at a specified x, y coord, also setting the color attributes
boolean Text_SetCharAndColorAtXY(signed int the_screen_id, signed int x, signed int y, unsigned char the_char, unsigned char fore_color, unsigned char back_color)
{
	char*			the_write_loc;
	unsigned char	the_attribute_value;
	
	if (!Text_ValidateAll(the_screen_id, x, y, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
		
	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);
	
	// write character memory
	the_write_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_CHAR);	
	*the_write_loc = the_char;
	
	// write attribute memory (reuse same calc, just add attr ram delta)
	the_write_loc += global_screen[the_screen_id].text_attr_ram_ - global_screen[the_screen_id].text_ram_;
	*the_write_loc = the_attribute_value;
	
	return true;
}


// **** Get char/attr functions *****


// Get the char at a specified x, y coord
unsigned char Text_GetCharAtXY(signed int the_screen_id, signed int x, signed int y)
{
	char*			the_read_loc;
	unsigned char	the_char;
	
	if (!Text_ValidateAll(the_screen_id, x, y, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id or coordinate", __func__, __LINE__));
		return false;
	}
	
	the_read_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_CHAR);	
 	the_char = (unsigned char)*the_read_loc;
	
	return the_char;
}


// Get the attribute value at a specified x, y coord
unsigned char Text_GetAttrAtXY(signed int the_screen_id, signed int x, signed int y)
{
	char*			the_read_loc;
	unsigned char	the_value;
	
	if (!Text_ValidateAll(the_screen_id, x, y, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id or coordinate", __func__, __LINE__));
		return false;
	}
	
	the_read_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_ATTR);	
 	the_value = (unsigned char)*the_read_loc;
	
	return the_value;
}


// Get the foreground color at a specified x, y coord
unsigned char Text_GetForeColorAtXY(signed int the_screen_id, signed int x, signed int y)
{
	char*			the_read_loc;
	unsigned char	the_value;
	unsigned char	the_color;
	
	if (!Text_ValidateAll(the_screen_id, x, y, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id or coordinate", __func__, __LINE__));
		return false;
	}
	
	the_read_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_ATTR);	
 	the_value = (unsigned char)*the_read_loc;
	the_color = (the_value & 0xF0) >> 4;
	
	return the_color;
}


// Get the background color at a specified x, y coord
unsigned char Text_GetBackColorAtXY(signed int the_screen_id, signed int x, signed int y)
{
	char*			the_read_loc;
	unsigned char	the_value;
	unsigned char	the_color;
	
	if (!Text_ValidateAll(the_screen_id, x, y, 0, 0))
	{
		LOG_ERR(("%s %d: illegal screen id or coordinate", __func__, __LINE__));
		return false;
	}
	
	the_read_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_ATTR);	
 	the_value = (unsigned char)*the_read_loc;
	the_color = (the_value & 0x0F);
	
	return the_color;
}



// **** Drawing functions *****


// draws a horizontal line from specified coords, for n characters, using the specified char and/or attribute
boolean Text_DrawHLine(signed int the_screen_id, signed int x, signed int y, signed int the_line_len, unsigned char the_char, unsigned char fore_color, unsigned char back_color, text_draw_choice the_draw_choice)
{
	signed int	dx;
	
	if (!Text_ValidateAll(the_screen_id, x, y, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}

	switch (the_draw_choice)
	{
		case char_only:
			for (dx = 0; dx < the_line_len; dx++)
			{
				Text_SetCharAtXY(the_screen_id, x + dx, y, the_char);
			}
			break;
			
		case attr_only:
			for (dx = 0; dx < the_line_len; dx++)
			{
				Text_SetAttrAtXY(the_screen_id, x + dx, y, fore_color, back_color);
			}
			break;
			
		case char_and_attr:
		default:
			for (dx = 0; dx < the_line_len; dx++)
			{
				Text_SetCharAndColorAtXY(the_screen_id, x + dx, y, the_char, fore_color, back_color);		
			}
			break;			
	}

	return true;
}


// draws a vertical line from specified coords, for n characters, using the specified char and/or attribute
boolean Text_DrawVLine(signed int the_screen_id, signed int x, signed int y, signed int the_line_len, unsigned char the_char, unsigned char fore_color, unsigned char back_color, text_draw_choice the_draw_choice)
{
	unsigned char dy;
	
	if (!Text_ValidateAll(the_screen_id, x, y, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}

	switch (the_draw_choice)
	{
		case char_only:
			for (dy = 0; dy < the_line_len; dy++)
			{
				Text_SetCharAtXY(the_screen_id, x, y + dy, the_char);
			}
			break;
			
		case attr_only:
			for (dy = 0; dy < the_line_len; dy++)
			{
				Text_SetAttrAtXY(the_screen_id, x, y + dy, fore_color, back_color);
			}
			break;
			
		case char_and_attr:
		default:
			for (dy = 0; dy < the_line_len; dy++)
			{
				Text_SetCharAndColorAtXY(the_screen_id, x, y + dy, the_char, fore_color, back_color);		
			}
			break;			
	}
	
	return true;
}


// draws a basic box based on 2 sets of coords, using the specified char and/or attribute for all cells
boolean Text_DrawBoxCoords(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char the_char, unsigned char fore_color, unsigned char back_color, text_draw_choice the_draw_choice)
{
	signed int	dy;
	signed int	dx;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1,fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1 + 1;
	dy = y2 - y1 + 1;
	
	if (!Text_DrawHLine(the_screen_id, x1, y1, dx, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x2, y1, dy, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawHLine(the_screen_id, x1, y2, dx, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x1, y1, dy, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
		
	return true;
}


// draws a box based on 2 sets of coords, using the predetermined line and corner "graphics", and the passed colors
boolean Text_DrawBoxCoordsFancy(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, unsigned char fore_color, unsigned char back_color)
{
	signed int	dy;
	signed int	dx;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}

	// add 1 to line len, because desired behavior is a box that connects fully to the passed coords
	dx = x2 - x1;
	dy = y2 - y1;
	
	// draw all lines one char shorter on each end so that we don't overdraw when we do corners
	
	if (!Text_DrawHLine(the_screen_id, x1+1, y1, dx, CH_WALL_H, fore_color, back_color, char_and_attr))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawHLine(the_screen_id, x1+1, y2, dx, CH_WALL_H, fore_color, back_color, char_and_attr))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x2, y1+1, dy, CH_WALL_V, fore_color, back_color, char_and_attr))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x1, y1+1, dy, CH_WALL_V, fore_color, back_color, char_and_attr))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	// draw the 4 corners with dedicated corner pieces
	Text_SetCharAndColorAtXY(the_screen_id, x1, y1, CH_WALL_UL, fore_color, back_color);		
	Text_SetCharAndColorAtXY(the_screen_id, x2, y1, CH_WALL_UR, fore_color, back_color);		
	Text_SetCharAndColorAtXY(the_screen_id, x2, y2, CH_WALL_LR, fore_color, back_color);		
	Text_SetCharAndColorAtXY(the_screen_id, x1, y2, CH_WALL_LL, fore_color, back_color);		
	
	return true;
}


// draws a basic box based on start coords and width/height, using the specified char and/or attribute for all cells
boolean Text_DrawBox(signed int the_screen_id, signed int x, signed int y, signed int the_width, signed int the_height, unsigned char the_char, unsigned char fore_color, unsigned char back_color, text_draw_choice the_draw_choice)
{	
	if (!Text_ValidateAll(the_screen_id, x, y,fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x + the_width - 1, y + the_height - 1))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (!Text_DrawHLine(the_screen_id, x, y, the_width, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x + the_width - 1, y, the_height, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawHLine(the_screen_id, x, y + the_height - 1, the_width, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
	
	if (!Text_DrawVLine(the_screen_id, x, y, the_height, the_char, fore_color, back_color, the_draw_choice))
	{
		LOG_ERR(("%s %d: draw box failed", __func__, __LINE__));
		return false;
	}
		
	return true;
}



// **** Draw string functions *****


// Draw a string at a specified x, y coord, also setting the color attributes
// Truncate, but still draw the string if it is too long to display on the line it started.
// No word wrap is performed. 
boolean Text_DrawStringAtXY(signed int the_screen_id, signed int x, signed int y, char* the_string, unsigned char fore_color, unsigned char back_color)
{
	char*			the_char_loc;
	char*			the_attr_loc;
	unsigned char	the_attribute_value;
	signed int		i;
	signed int		max_col;
	signed int		draw_len;
	
	if (!Text_ValidateAll(the_screen_id, x, y, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	draw_len = General_Strnlen(the_string, TEXT_COL_COUNT_FOR_PLOTTING); // can't be wider than the screen anyway
	max_col = global_screen[the_screen_id].text_cols_ - 1;
	
	if ( x + draw_len > max_col)
	{
		draw_len = (max_col - x) + 1;
	}
	
	//DEBUG_OUT(("%s %d: draw_len=%i, max_col=%i, x=%i", __func__, __LINE__, draw_len, max_col, x));
	
	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);

	// set up char and attribute memory initial loc
	the_char_loc = Text_GetMemLocForXY(the_screen_id, x, y, SCREEN_FOR_TEXT_CHAR);
	the_attr_loc = the_char_loc + (global_screen[the_screen_id].text_attr_ram_ - global_screen[the_screen_id].text_ram_);
	
	// draw the string
	for (i = 0; i < draw_len; i++)
	{
		*the_char_loc++ = the_string[i];
		*the_attr_loc++ = the_attribute_value;
	}
	
	return true;
}


// Draw a string in a rectangular block on the screen, with wrap
// If a word can't be wrapped, it will break the word and move on to the next line. So if you pass a rect with 1 char of width, it will draw a vertical line of chars down the screen.
// returns false on any error/invalid input.
boolean Text_DrawStringInBox(signed int the_screen_id, signed int x1, signed int y1, signed int x2, signed int y2, char* the_string, unsigned char fore_color, unsigned char back_color)
{
	char*			the_char_loc;
	char*			the_attr_loc;
	char*			orig_string;
	char*			formatted_string;
	char*			remaining_string;
	unsigned char	the_attribute_value;
	signed int		max_col;
	signed int		remaining_len;
	signed int		orig_len;
	signed int		v_pixels = 0;
	signed int		max_pix_width;
	signed int		max_pix_height;
	signed int		num_rows;
	signed int		the_row;
	signed int		this_line_len;
char		temp_buff[256];
char*		the_temp = temp_buff;
	
	if (!Text_ValidateAll(the_screen_id, x1, y1, fore_color, back_color))
	{
		LOG_ERR(("%s %d: illegal screen id, coordinate, or color", __func__, __LINE__));
		return false;
	}
	
	if (!Text_ValidateXY(the_screen_id, x2, y2))
	{
		LOG_ERR(("%s %d: illegal coordinate", __func__, __LINE__));
		return false;
	}

	if (x1 > x2 || y1 > y2)
	{
		LOG_ERR(("%s %d: illegal coordinates", __func__, __LINE__));
		return false;
	}
	
	max_col = x2 - x1 + 1;
	max_pix_width = (x2 - x1 + 1) * global_screen[the_screen_id].text_font_width_;
	max_pix_height = (y2 - y1 + 1) * global_screen[the_screen_id].text_font_height_;
	
	remaining_len = General_Strnlen(the_string, TEXT_COL_COUNT_FOR_PLOTTING * TEXT_ROW_COUNT_FOR_PLOTTING + 1); // can't be bigger than the screen (80x60=4800). +1 for terminator. 
	orig_len = remaining_len;

	//DEBUG_OUT(("%s %d: draw_len=%i, max_col=%i, x=%i", __func__, __LINE__, draw_len, max_col, x));
	
	// calculate attribute value from passed fore and back colors
	// LOGIC: text mode only supports 16 colors. lower 4 bits are back, upper 4 bits are foreground
	the_attribute_value = ((fore_color << 4) | back_color);

	// set up char and attribute memory initial loc
	the_char_loc = Text_GetMemLocForXY(the_screen_id, x1, y1, SCREEN_FOR_TEXT_CHAR);
	the_attr_loc = the_char_loc + (global_screen[the_screen_id].text_attr_ram_ - global_screen[the_screen_id].text_ram_);
	
	// format the string into chunks that will fit in the width specified, with line breaks on each line
	orig_string = the_string;
	formatted_string = global_screen[the_screen_id].text_temp_buffer_2_;
	v_pixels = General_WrapAndTrimTextToFit(&global_screen[the_screen_id], &orig_string, &formatted_string, orig_len, max_pix_width, max_pix_height);
	num_rows = v_pixels / global_screen[the_screen_id].text_font_height_;
	//DEBUG_OUT(("%s %d: v_pixels=%i, num_rows=%i", __func__, __LINE__, v_pixels, num_rows));
	remaining_string = formatted_string;
	
	// draw the string, one line at a time, until string is done or no more lines available
	
	//for (the_row = 0; the_row < num_rows; the_row++)
	the_row = 1;
	
	do
	{
		signed int	this_write_len;
		
		this_line_len = General_StrFindNextLineBreak(remaining_string, max_col);
// sprintf(the_temp, "%d: this_l=%i, rem_l=%i", __LINE__, this_line_len, remaining_len);
// Text_DrawStringAtXY(ID_CHANNEL_A, 0, the_row, the_temp, FG_COLOR_BLACK_GREEN, BG_COLOR_BROWN);

		if (this_line_len == 1)
		{
			// next/first character is a line break char
			this_write_len = 0;
// 			remaining_string++;
// 			remaining_len--;
			*(the_attr_loc) = the_attribute_value;
// 			memset(the_attr_loc, the_attribute_value, 1);
		}
		else
		{
			if (this_line_len == 0)
			{
				// there is no other line break char left in the string.
				this_write_len = General_Strnlen(remaining_string, remaining_len) - 1;
			}
			else
			{
				// there is a line break character, but some other chars come first. write up to be not including the line break
				this_write_len = this_line_len - 1; // stop short of the the actual \n char.
			}
		
			memcpy(the_char_loc, remaining_string, this_write_len);
			memset(the_attr_loc, the_attribute_value, this_write_len);
		}

				remaining_string += this_write_len + 1; // skip past the actual \n char.
				remaining_len -= (this_write_len + 1);
		
		the_char_loc += TEXT_COL_COUNT_FOR_PLOTTING;
		the_attr_loc += TEXT_COL_COUNT_FOR_PLOTTING;		
		the_row++;
	} while (the_row < num_rows && this_line_len > 0);
	
	return true;
}