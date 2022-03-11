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
//													Get display information
// *******************************************************************************************************************************

void HWGetDisplayInfo(DISPLAYINFO *d,char vType,BYTE8 *vicky,SDL_Rect *rDrawArea) {

	d->vType = vType; 									// Save type

	int pWidth,pHeight;
	if (vType == 'A') {									// Vicky III A resolutions
		pWidth = 800;
		pHeight = 600;
		if (vicky[2] & 0x08) { 				
			pWidth = 1024;pHeight = 768;
		}
	} else { 											// Vicky III B resolutions
		pWidth = 640;
		pHeight = 480;
		if (vicky[2] & 0x01) { 
			pWidth = 800;pHeight = 600; 
		}
	}		
	int cWidth = pWidth/8; 								// Chars per line
	int cHeight = pHeight/8; 							// Lines per screen

	int scaleX = rDrawArea->w/pWidth; 					// Scale for full screen
	int scaleY = rDrawArea->h/pHeight;


	d->pSize = (scaleX < scaleY) ? scaleX : scaleY;		// Char Dot Size in pixels.
	if (d->pSize < 1) d->pSize = 1;

	d->dWidth = pWidth;d->dHeight = pHeight; 			// Save display size.


	d->rcFull = *rDrawArea;

	d->rcDraw.w = pWidth * d->pSize;					// Work out drawing rectangle
	d->rcDraw.h = pHeight * d->pSize;
	d->rcDraw.x = rDrawArea->x+rDrawArea->w/2-d->rcDraw.w/2;
	d->rcDraw.y = rDrawArea->y+rDrawArea->h/2-d->rcDraw.h/2;


	int border = HWConvertVickyTextLUT(vicky+8);		// Convert BGR
	int backColour = HWConvertVickyTextLUT(vicky+12);

	GFXRectangle(rDrawArea,border); 					// Draw border
	GFXRectangle(&(d->rcDraw),backColour);				// Erase background

}

// *******************************************************************************************************************************
//													Render text screen
// *******************************************************************************************************************************

static int renderCount = 0;

void HWRenderTextScreen(DISPLAYINFO *d,BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem) {

	if ((vicky[3] & 0x01) == 0) return; 				// No text mode enabled.

	int pWidth,pHeight;
	int xCursor = -1,yCursor = -1;
	int colours[32];

	int cBWidth = d->dWidth/8; 							// Byte lines per width pre border

	pWidth = d->dWidth - (vicky[6] & 0x3F)*2;			// Adjust for border.
	pHeight = d->dHeight - (vicky[5] & 0x3F)*2;

	int cWidth = pWidth / 8; 							// Actual chracters per line to write.
	int cHeight = pHeight / 8;

														// Work out horizontal/vertical chars displayed.
	int xOrg = d->rcDraw.x+d->rcDraw.w/2-cWidth*8*d->pSize/2; 	
	int yOrg = d->rcDraw.y+d->rcDraw.h/2-cHeight*8*d->pSize/2; 	

	renderCount++; 										// Convert Vicky ARGB format to our 12 bit format
	for (int i = 0;i < 32;i++) {
		colours[i] = HWConvertVickyTextLUT(lutMem+i*4);
	}

	if (vicky[0x13] & 1) { 								// Cursor on.
		yCursor = (vicky[0x14] << 8) + vicky[0x15]; 	// Get location
		xCursor = (vicky[0x16] << 8) + vicky[0x17];
	}

	SDL_Rect rc,rcp;

	for (int x = 0;x < cWidth;x++) { 					// Scan column and row
		for (int y = 0;y < cHeight;y++) {
			rc.x = xOrg+x*8*d->pSize; 					// RC is text chara position
			rc.y = yOrg+y*8*d->pSize;
			rc.w = rc.h = d->pSize;
			int offset = x+y*cBWidth; 					// Position in Text VRAM 
			int ch = charMem[offset]; 					// Char and colour byte here
			int col = colMem[offset];

														// Check cursor here
			if (x == xCursor && y == yCursor & (renderCount & 4) == 0) {
				col = vicky[0x10];
				ch = vicky[0x11];
			}

			int fgr = colours[col >> 4];				// Get colours
			int bgr = colours[(col & 0x0F)+16];

			int bgTransparent = (col & 0x0F) == 0;		// 0 is transparent, unless overlay bit clear.
			if ((vicky[3] & 0x02) == 0) bgTransparent = 0;

			for (int yc = 0;yc < 8;yc++) { 				// Draw the character out
				int bitLine = fontMem[ch * 8 + yc];
				rcp = rc;
				rc.y += d->pSize;
				for (int xc = 0;xc < 8;xc++) {		
					if (bitLine & 0x80)	{
						GFXRectangle(&rcp,fgr); 
					} else {
						if (bgTransparent == 0) GFXRectangle(&rcp,bgr);
					}
					rcp.x += d->pSize;
					bitLine <<= 1;
				}
			}
		}
	}
}

// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Changes made
//	
//		Date 			Changes
//		---- 			-------
//		11-Mar-22 		Code reorganisation to allow overlay
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************
