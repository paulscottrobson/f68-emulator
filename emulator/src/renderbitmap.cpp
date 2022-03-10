// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		renderbitmap.cpp
//		Purpose:	Render bitmap display
//		Created:	27th February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

// *******************************************************************************************************************************
//													Read long from BYTE *
// *******************************************************************************************************************************

LONG32 HWReadLong(BYTE8 *p) {
	return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

// *******************************************************************************************************************************
//													Render text screen
// *******************************************************************************************************************************

void HWRenderBitmap(BYTE8 *vicky,BYTE8 *videoMem,SDL_Rect *rDraw) {
	int pWidth = 640;
	int pHeight = 480;

	if ((vicky[3] & 0x08) == 0) return; 				// No bitmap mode enabled.
	if ((vicky[0x103] & 0x01) == 0) return; 			// Layer not enabled.

	if ((vicky[2] & 0x03) == 1) { 						// Handle larger size
		pWidth = 800;
		pHeight = 600;
	}

	int convLuts[256]; 									// Convert LUTs when needed.
	for (int i = 0;i < 256;i++) convLuts[i] = -1;

	int scaleX = rDraw->w/pWidth;
	int scaleY = rDraw->h/pHeight;

	int cSize = (scaleX < scaleY) ? scaleX : scaleY;	// Char Size in pixels.

	int xOrg = rDraw->x+rDraw->w/2-pWidth*cSize/2;		// Work out character origin.
	int yOrg = rDraw->y+rDraw->h/2-pHeight*cSize/2;

	int backCol = HWConvertVickyTextLUT(vicky+12);		// Convert BGR background colour
	GFXRectangle(rDraw,backCol); 						// Draw background

	SDL_Rect rc;

	BYTE8 *pixData = videoMem;

	pixData += HWReadLong(vicky+0x104); 				// Start of bitmap data.

	int baseLut = ((vicky[0x103] >> 1) & 7) * 0x400;	// Which LUT set ?

	for (int y = 0;y < pHeight;y++) {
		rc.x = xOrg;rc.y = yOrg+y*cSize;rc.w = rc.h = cSize;
		for (int x = 0;x < pWidth;x++) {
			int col = *pixData++;
				if (col != 0) {
					if (convLuts[col] < 0) {
						convLuts[col] = HWConvertVickyBitmapLUT(vicky+0x2000+baseLut+col*4);
					}
					GFXRectangle(&rc,convLuts[col]);
			}
			rc.x += rc.w;
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
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************
