// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		rendertext.cpp
//		Purpose:	Render text display
//		Created:	23rd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

// *******************************************************************************************************************************
//											Convert a Vicky LUT to our RGB format
// *******************************************************************************************************************************

int HWConvertVickyTextLUT(BYTE8 *lut) {
	int parts[4];
	for (int i = 0;i < 4;i++) {
		parts[i] = (lut[i]) >> 4;
		if (parts[i] < 0) parts[i] = 0;
		if (parts[i] > 15) parts[i] = 15;
	}
	return parts[3]+(parts[2] << 4)+(parts[1] << 8);		// ARGB Bigendian
}

int HWConvertVickyBitmapLUT(BYTE8 *lut) {
	int parts[4];
	for (int i = 0;i < 4;i++) {
		parts[i] = (lut[i]) >> 4;
		if (parts[i] < 0) parts[i] = 0;
		if (parts[i] > 15) parts[i] = 15;
	}
	return parts[0]+(parts[1] << 4)+(parts[2] << 8);		// ARGB Bigendian
}

// *******************************************************************************************************************************
//													Render text screen
// *******************************************************************************************************************************

static int renderCount = 0;

void HWRenderTextScreen(char vType,BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem,SDL_Rect *rDraw) {

	if ((vicky[3] & 0x01) == 0) return; 				// No text mode enabled.

	int pWidth,pHeight;

	if (vType == 'A') {									// Vicky III A
		pWidth = 800;
		pHeight = 600;
		if (vicky[2] & 0x01) { 				
			pWidth = 1024;pHeight = 768;
		}
	} else { 											// Vicky III B
		pWidth = 640;
		pHeight = 480;
		if (vicky[2] & 1) { 
			pWidth = 800;pHeight = 600; 
		}
	}		
	int cBWidth = pWidth/8; 							// Byte lines per width pre border

	pWidth = pWidth - (vicky[5] & 0x3F)*2;				// Adjust for border.
	pHeight = pHeight - (vicky[6] & 0x3F)*2;

	int scaleX = rDraw->w/pWidth;
	int scaleY = rDraw->h/pHeight;

	int cWidth = pWidth/8; 								// Chars per line
	int cHeight = pHeight/8; 							// Lines per screen
	int cSize = (scaleX < scaleY) ? scaleX : scaleY;	// Char Dot Size in pixels.
	if (cSize < 1) cSize = 1;

	int xCursor = -1,yCursor = -1;
	int colours[32];

	int border = HWConvertVickyTextLUT(vicky+8);		// Convert BGR
	GFXRectangle(rDraw,border); 						// Draw border

	renderCount++; 										// Convert Vicky ARGB format to our 12 bit format
	for (int i = 0;i < 32;i++) {
		colours[i] = HWConvertVickyTextLUT(lutMem+i*4);
	}

	if (vicky[0x13] & 1) { 								// Cursor on.
		yCursor = (vicky[0x14] << 8) + vicky[0x15]; 	// Get location
		xCursor = (vicky[0x16] << 8) + vicky[0x17];
	}

	int xOrg = rDraw->x+rDraw->w/2-cWidth*8*cSize/2; 	// Work out character origin.
	int yOrg = rDraw->y+rDraw->h/2-cHeight*8*cSize/2;

	SDL_Rect rc,rcp;
	rc.x = xOrg;rc.y = yOrg; 							// Erase the screen background space to black default
	rc.w = cWidth * 8 * cSize;rc.h = cHeight * 8 * cSize;
	GFXRectangle(&rc,0x000);

	for (int x = 0;x < cWidth;x++) {
		for (int y = 0;y < cHeight;y++) {
			rc.x = xOrg+x*8*cSize;
			rc.y = yOrg+y*8*cSize;
			rc.w = rc.h = cSize;
			int offset = x+y*cBWidth;
			int ch = charMem[offset];
			int col = colMem[offset];
			if (x == xCursor && y == yCursor & (renderCount & 4) == 0) {
				col = vicky[0x10];
				ch = vicky[0x11];
			}
			int fgr = colours[col >> 4];
			int bgr = colours[(col & 0x0F)+16];
			for (int yc = 0;yc < 8;yc++) {
				int bitLine = fontMem[ch * 8 + yc];
				rcp = rc;
				rc.y += cSize;
				for (int xc = 0;xc < 8;xc++) {					
					GFXRectangle(&rcp,bitLine & 0x80 ? fgr:bgr);
					rcp.x += cSize;
					bitLine <<= 1;
				}
			}
		}
	}
}
