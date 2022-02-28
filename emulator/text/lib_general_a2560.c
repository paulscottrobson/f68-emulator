/*
 * lib_general_a2560.c
 *
 *  Created on: Feb 19, 2022
 *      Author: micahbly
 */





/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

#include "lib_text.h"

// project includes
#include "lib_general.h"
#include "lib_general_a2560.h"
//#include "localize.h"

// C includes
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

// A2560 includes



/*****************************************************************************/
/*                               Definitions                                 */
/*****************************************************************************/




/*****************************************************************************/
/*                             Global Variables                              */
/*****************************************************************************/

static char				message_buffer[ALERT_MAX_MESSAGE_LEN];	// used for alert dialogs sprintfs




/*****************************************************************************/
/*                       Private Function Prototypes                         */
/*****************************************************************************/

// PRIVATE - no checking of parameters
// copy the specified length of text from this_line_start into the write buffer, and overwrite the null terminator with a line break character
// advance the read and write buffers to the next position
void General_WrapParaWriteLine(char** source, char** target, signed int write_len);

// PRIVATE - no checking of parameters
// passed a string with no line breaks in it, and a buffer to write into, copies the string contents into the target buffer, performing line breaks as it goes
// stops when all characters have been processed, or when all available vertical space has been used up.
signed int General_WrapPara(struct Screen* the_screen, char* this_line_start, char* formatted_text, signed int remaining_len, signed int max_width, signed int remaining_v_pixels, signed int font_height);




/*****************************************************************************/
/*                       Private Function Definitions                        */
/*****************************************************************************/

// PRIVATE - no checking of parameters
// copy the specified length of text from this_line_start into the write buffer, and overwrite the null terminator with a line break character
// advance the read and write buffers to the next position
void General_WrapParaWriteLine(char** source, char** target, signed int write_len)
{
	General_Strlcpy(*target, *source, write_len);
	*(*target + write_len - 1) = '\n'; // overwrite the \0 from strlcpy				
	*target += write_len; // move formatted_text up to the next spot for writing
	*source += write_len; // move unformatted_text up to the next spot for reading
}


// PRIVATE - no checking of parameters
// passed a string with no line breaks in it, and a buffer to write into, copies the string contents into the target buffer, performing line breaks as it goes
// stops when all characters have been processed, or when all available vertical space has been used up.
signed int General_WrapPara(struct Screen* the_screen, char* this_line_start, char* formatted_text, signed int remaining_len, signed int max_width, signed int remaining_v_pixels, signed int font_height)
{
	signed int		v_pixels = 0;
	boolean			line_complete;
	signed int		next_line_len;

	// Initial condition is next line and this line are the same thing. 
	// Next line start will move word by word to the right until what's left no longer fits on a line
	// then this_line is written out, and next_line and this line are equal again
	next_line_len = remaining_len;
	
	// outer loop: continue until the entire string has been copied to formatted text, or until we have exceeded the v pixel budget
	do
	{
		signed int		this_line_len = 0;
		char*			next_line_start = this_line_start;

		line_complete = false;

		// inner loop: Each pass is one word. Process until the end of a line is reached
		while (line_complete == false)
		{
			signed int			next_soft_break_pos;
		
			next_soft_break_pos = General_StrFindNextWordEnd(next_line_start, next_line_len);
				
			if (next_soft_break_pos < 0)
			{
				signed int		chars_that_fit;

				// there are no more word breaks in this string. 2 possible conditions:
				//   A. We previously started a new line, and have at least 1 word. there's ONE more word then end of string
				//   B. We are at the start of processing a line, and came to the end of the string. There is one word, it may be larger than will fit. 
				// The word may fit on the current line, or it may not. We haven't measured it. 
				//   if it's longer than the allowed line width, it must be broken mid-word.
				
				// check if the word will fit on the line, and if so, add it and exit the function.
				//   if it will not fit:
				//   A) if already have 1+ words on the line, wrap at this point, add the word, exit the function
				//   B) if no words on line, force break the word at max width and continue.
				
				signed int	proposed_new_line_len = this_line_len + next_line_len;
				
				chars_that_fit = General_TextFit(the_screen, this_line_start, proposed_new_line_len, max_width);
				
				if (chars_that_fit >= proposed_new_line_len)
				{
					// the upcoming word will fit on current line
					// extend length of current line; push start of next line to position past the word
					General_WrapParaWriteLine(&this_line_start, &formatted_text, proposed_new_line_len);

					this_line_len = 0;

					this_line_start = NULL;
					next_line_start = NULL;
					next_line_len = 0;
				}
				else
				{
					// either we got an error, or all the characters will not fit on this line
					// if we have a current line, end it and add line break + remaining string. if no current line, force break the rest of the string at max width and continue.

					// any words on the current line?
					if (this_line_len > 0)
					{
						// we already have some words, so end the current line and continue
						General_WrapParaWriteLine(&this_line_start, &formatted_text, this_line_len);
						this_line_len = 0;
					}
					else
					{
						// the whole string is word-break-less: we must force a break
						General_WrapParaWriteLine(&this_line_start, &formatted_text, chars_that_fit);
					}
				}
				
				line_complete = true;	
			}
			else
			{
				// we found the next word break. test if we can fit everything to that point. if so, continue on. if not, back up to last pos and break there

				signed int	proposed_new_line_len = this_line_len + next_soft_break_pos;
				signed int	chars_that_fit;
			
				chars_that_fit = General_TextFit(the_screen, this_line_start, proposed_new_line_len, max_width);
		
				if (chars_that_fit >= proposed_new_line_len)
				{
					// the upcoming word will fit on current line
					// extend length of current line; push start of next line to position past the word
					this_line_len = proposed_new_line_len;
					next_line_start += next_soft_break_pos;
					next_line_len -= next_soft_break_pos;
				}
				else
				{
					// either we got an error, or all the characters will not fit on this line
					// in either case, end the current line, write it to formatted

					General_WrapParaWriteLine(&this_line_start, &formatted_text, this_line_len);

					this_line_len = 0;

					line_complete = true;

					//DEBUG_OUT(("%s %d: print out of formatted_text after copy...", __func__ , __LINE__));
					//General_PrintBufferCharacters(formatted_text-8, (unsigned short)remaining_len);
					//DEBUG_OUT(("%s %d: line complete. next_line_len=%i, this_line_start='%s'", __func__ , __LINE__, next_line_len, this_line_start));		

					if (chars_that_fit == -1)
					{
						// handle error condition: having completed the current line, force function to exit with an error.
						printf("\nError! ln %d next_line_len=%i, this_line_start='%s'", __LINE__, next_line_len, this_line_start);
						*(formatted_text) = '\0';
						return -1;
					}
				}
			}
		}
		
		v_pixels += font_height;
		remaining_v_pixels -= font_height;
		
	} while (this_line_start != NULL && remaining_v_pixels > 0);
	
	//DEBUG_OUT(("%s %d: print out of final version of para", __func__ , __LINE__));
	//General_PrintBufferCharacters(start_of_formatted, (unsigned short)orig_len+4);
	
	return v_pixels;
}


/*****************************************************************************/
/*                        Public Function Definitions                        */
/*****************************************************************************/





// calculates how many characters of the passed string will fit into the passed pixel width
// TODO: adapt this to reference the currently selected screen font, once non-fixed width fonts are available (if ever)
// returns -1 in any error condition
signed int General_TextFit(struct Screen* the_screen, char* the_string, signed int the_len, signed int available_width)
{
	signed int		fit_count;
	signed int		char_width;
	signed int		required_width;
	
	if (the_screen == NULL)
	{
		LOG_ERR(("%s %d: passed screen object was null", __func__ , __LINE__));
		return -1;
	}

	if (the_len < 1)
	{
		return -1;
	}
	
	// LOGIC:
	//   in a system that had proportionally spaced fonts, we would examine each character in the string, and get the width of that char
	//   the foenix computers currently only offer fixed with fonts in their text mode
	//   if foenix or users add a way to do proportionally spaced fonts in the future, this will need a helper routine a la Amiga's TextFit()
	//   for now, we can just multiply chars * char width
	
	char_width = the_screen->text_font_width_;
	required_width = the_len * char_width;
	
	if (available_width >= required_width)
	{
		fit_count = the_len;
	}
	else
	{
		fit_count = available_width / char_width;
	}
	
	return fit_count;	
}


// Format a string by wrapping and trimming to fit the passed width and height. returns number of vertical pixels required. 
// Passing a 0 for height disables the governor on allowed vertical space. 
// If the string cannot be displayed in the specified height and width, processing will stop, but it is not an error condition
// If max_chars_to_format is less than len of string, processing will stop after that many characters.
// returns -1 in any error condition
signed int General_WrapAndTrimTextToFit(struct Screen* the_screen, char** orig_string, char** formatted_string, signed int max_chars_to_format, signed int max_width, signed int max_height)
{
	signed int		font_height;
	char*			formatted_text;
	signed int		v_pixels = 0;
	signed int		new_v_pixels_used;
	char*			remaining_text;
	signed int		remaining_len = max_chars_to_format;
	boolean			format_complete = false;
	signed int		remaining_v_pixels;
	static char		para_buff[1024];
	char*			the_para = para_buff;
	
	font_height = the_screen->text_font_height_;
	remaining_v_pixels = max_height;
	
	remaining_text = *orig_string;
	formatted_text = *formatted_string;
		
	// Outer Loop: each pass is one line
	do
	{
		boolean			line_complete = false;
		signed int		dist_to_next_hard_break;
		signed int		len_to_process;
		
		
		dist_to_next_hard_break = General_StrFindNextLineBreak(remaining_text, remaining_len);
		
		if (dist_to_next_hard_break == 1)
		{
			*(formatted_text) = '\n';
			// the first char in the string is a line break - skip over and continue
			new_v_pixels_used = font_height;
			// account for the line break char we are skipping past
			len_to_process = 1;
		}
		else
		{
			char*			para_to_process;
			
			if (dist_to_next_hard_break < 1)
			{
				// there are no more line breaks in the string. process the entire string
				para_to_process = remaining_text;
				len_to_process = remaining_len + 1;	// +1 because there is no line break we want snipped off. 
			}
			else
			{
				// there is a line break. Send off that paragraph for processing
				para_to_process = para_buff;
				len_to_process = dist_to_next_hard_break; // not +1 because we don't want to add the line break; WrapPara will always add one at the end
				General_Strlcpy(the_para, remaining_text, dist_to_next_hard_break);
			}		
				
			// process one paragraph
			new_v_pixels_used = General_WrapPara(the_screen, para_to_process, formatted_text, len_to_process, max_width, remaining_v_pixels, font_height);		
		}
		
		if (new_v_pixels_used == -1)
		{
		}
		else
		{
			v_pixels += new_v_pixels_used;
			remaining_v_pixels -= new_v_pixels_used;
			remaining_len -= len_to_process;
			formatted_text += len_to_process;
			remaining_text += len_to_process;
			
			if (remaining_v_pixels < 0 || remaining_len < 1)
			{
				format_complete = true;
			}
			
		}
		
	} while ( format_complete == false);

	//DEBUG_OUT(("%s %d: print out of formatted_text after processing...", __func__ , __LINE__));
	//General_PrintBufferCharacters(*formatted_string, (unsigned short)max_chars_to_format+10);
	//DEBUG_OUT(("%s %d: v pixels used=%i", __func__ , __LINE__, v_pixels));
	
	return v_pixels;
}




/*
// draw a line in an intuition window
void General_DrawLine(struct RastPort* the_rastport, signed long x1, signed long y1, signed long x2, signed long y2, unsigned char the_color_pen)
{
	// move the pen to the first coordinate, or it will draw a line from where it is, to there
	Move( the_rastport, x1, y1 );

	// draw the line
	SetAPen( the_rastport, the_color_pen );
	Draw( the_rastport, x2, y2 );
}
*/


/*
// draw a poly in an intuition window
void General_DrawPoly(struct RastPort* the_rastport, short num_coords, short* the_coordinates, unsigned char the_color_pen)
{
	short	x = *(the_coordinates + 0);
	short	y = *(the_coordinates + 1);

	// move the pen to the first coordinate, or it will draw a line from where it is, to there
	Move( the_rastport, x, y );

	// draw the poly
	SetAPen( the_rastport, the_color_pen );
	PolyDraw( the_rastport, num_coords, the_coordinates );
}
*/


/*
// draw a rectangle in the rastport passed. If do_undraw is TRUE, try to undraw it (unimplemented TODO)
void General_DrawBox(struct RastPort* the_rastport, signed short x1, signed short y1, signed short x2, signed short y2, boolean do_undraw, unsigned char the_color_pen)
{
	short				coordinates[10];

	// COMPLEMENT mode will simply inverse pixels. This makes it possible to draw once, then draw again, to restore what was there
	SetDrMd(the_rastport, COMPLEMENT);

	// need 10 coords to use Intuitions PolyDraw for a box
	coordinates[0] = x1;
	coordinates[1] = y1;

	coordinates[2] = x2;
	coordinates[3] = y1;

	coordinates[4] = x2;
	coordinates[5] = y2;

	coordinates[6] = x1;
	coordinates[7] = y2;

	coordinates[8] = x1;
	coordinates[9] = y1;
	
	//DEBUG_OUT(("%s %d: %i, %i to %i, %i", __func__ , __LINE__, x1, y1, x2, y2));

	// set a dotted line pattern
	//SetDrPt(the_rastport, 0xAAAA);
	SetDrPt(the_rastport, 0xFFFF);

	// draw the surrounding box
	General_DrawPoly(the_rastport, 5, &coordinates[0], the_color_pen);

	// turn off pattern
	//SetDrPt(the_rastport, 0xFFFF);

	// reset draw mode in case we need it for plotting/replotting/etc.
	SetDrMd(the_rastport, JAM1);
}
*/




/*
// checks a file exists without locking the file. tries to get a lock on the dir containing the file, then checks contents until it matches
// SLOW, and probably pointless, but struggling with issue of locks not unlocking when checking for existence of an icon file.
boolean General_CheckFileExists(unsigned char* the_file_path)
{
	BPTR 					the_dir_lock;
	struct FileInfoBlock*	fileInfo;
	LONG					the_io_error;
	unsigned char*			the_file_name_to_check;
	int						filename_len;
	unsigned char*			the_directory_path;

	// get a string for the directory portion of the filepath
	if ( (the_directory_path = General_ExtractPathToParentFolderWithAlloc(the_file_path)) == NULL)
	{
		return false;
	}
	LOG_ALLOC(("%s %d:	__ALLOC__	the_directory_path	%p	size	%i		'%s'", __func__ , __LINE__, the_directory_path, General_Strnlen(the_directory_path, FILE_MAX_PATHNAME_SIZE) + 1, the_directory_path));
	
	// get the name portion of the path, so we can compare it later to each file we find in the parent directory
	the_file_name_to_check = FilePart(the_file_path);
	filename_len = General_Strnlen(the_file_name_to_check, FILE_MAX_PATHNAME_SIZE);

	// FileInfoBlocks have to be byte aligned, so needs AllocDosObject
	fileInfo = AllocDosObject(DOS_FIB, NULL);
	LOG_ALLOC(("%s %d:	__ALLOC__	fileInfo	%p	size	%i		AllocDosObject", __func__ , __LINE__, fileInfo, sizeof(struct FileInfoBlock)));

	// try to get lock on the  directory
	if ( (the_dir_lock = Lock((STRPTR)the_directory_path, SHARED_LOCK)) == 0)
	{
		LOG_INFO(("%s %d: Failed to lock dir %s!", __func__ , __LINE__, the_directory_path));
		LOG_ALLOC(("%s %d:	__FREE__	the_directory_path	%p	size	%i		'%s'", __func__ , __LINE__, the_directory_path, General_Strnlen(the_directory_path, FILE_MAX_PATHNAME_SIZE) + 1, the_directory_path));
		free(the_directory_path);
		the_directory_path = NULL;
		return false;
	}
	//printf("General_CheckFileExists: debug - dir-lock: %li / %p\n", the_dir_lock, BADDR( the_dir_lock ));

	if (Examine(the_dir_lock, fileInfo) != 0)
	{
		while ( ExNext(the_dir_lock, fileInfo) ) // data = ExamineDir(context))
		{
			if (fileInfo->fib_DirEntryType > 0)
			{
				// it's a directory
			}
			else
			{
				// it's a file... is it the we are looking for?
				if (General_Strncmp(the_file_name_to_check, (unsigned char*)fileInfo->fib_FileName, filename_len) == 0)
				{
					// it's the file we were looking for
					//printf("General_CheckFileExists: Confirmed file %s!\n", the_file_path);
					LOG_ALLOC(("%s %d:	__FREE__	the_directory_path	%p	size	%i		'%s'", __func__ , __LINE__, the_directory_path, General_Strnlen(the_directory_path, FILE_MAX_PATHNAME_SIZE) + 1, the_directory_path));
					free(the_directory_path);
					the_directory_path = NULL;
					
					LOG_ALLOC(("%s %d:	__FREE__	fileInfo	%p	size	%i		FreeDosObject", __func__ , __LINE__, fileInfo, sizeof(struct FileInfoBlock)));
					FreeDosObject(DOS_FIB, fileInfo);
					
					UnLock(the_dir_lock);
					return true;
				}
				else
				{
	//				printf("General_CheckFileExists: found |%s|!\n", fileInfo->fib_FileName);
				}
			}
		}
	}


	the_io_error = IoErr();

	if (the_io_error == ERROR_NO_MORE_ENTRIES)
	{
		// last file read: fail condition
	}
	else
	{
		// some other io error happened: just another fail condition
	}

	// free objects allocated in this method
	LOG_ALLOC(("%s %d:	__FREE__	the_directory_path	%p	size	%i", __func__ , __LINE__, the_directory_path, General_Strnlen(the_directory_path, FILE_MAX_PATHNAME_SIZE) + 1));
	free(the_directory_path);
	the_directory_path = NULL;
	
	LOG_ALLOC(("%s %d:	__FREE__	fileInfo	%p	size	%i		FreeDosObject", __func__ , __LINE__, fileInfo, sizeof(struct FileInfoBlock)));
	FreeDosObject(DOS_FIB, fileInfo);
	
	UnLock(the_dir_lock);

	return false;
}
*/


/*
// return current date/time as a timestamp. 
struct DateStamp* General_GetCurrentDateStampWithAlloc(void)
{
	struct DateStamp*	the_datetime;

	if ( (the_datetime = (struct DateStamp*)calloc(1, sizeof(struct DateStamp)) ) == NULL)
	{
		LOG_ERR(("%s %d: could not allocate memory to create new datestamp", __func__ , __LINE__));
		return NULL;
	}
	LOG_ALLOC(("%s %d:	__ALLOC__	the_datetime	%p	size	%i", __func__ , __LINE__, the_datetime, sizeof(struct DateStamp)));
	
	// have Amiga populate with the current time/date
	DateStamp(the_datetime);
	
	return the_datetime;
}
*/

