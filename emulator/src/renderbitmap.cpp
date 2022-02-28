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
				rc.x += rc.w;
			}
		}
	}
	// int xCursor = -1,yCursor = -1;
	// int colours[32];


	// renderCount++; 										// Convert Vicky ARGB format to our 12 bit format
	// for (int i = 0;i < 32;i++) {
	// 	colours[i] = HWConvertVickyLUT(lutMem+i*4);
	// }

	// if (vicky[0x13] & 1) { 								// Cursor on.
	// 	yCursor = (vicky[0x14] << 8) + vicky[0x15]; 	// Get location
	// 	xCursor = (vicky[0x16] << 8) + vicky[0x17];
	// }


	// SDL_Rect rc,rcp;
	// rc.x = xOrg;rc.y = yOrg; 							// Erase the screen background space to black default
	// rc.w = cWidth * 8 * cSize;rc.h = cHeight * 8 * cSize;
	// GFXRectangle(&rc,0x000);

	// for (int x = 0;x < cWidth;x++) {
	// 	for (int y = 0;y < cHeight;y++) {
	// 		rc.x = xOrg+x*8*cSize;
	// 		rc.y = yOrg+y*8*cSize;
	// 		rc.w = rc.h = cSize;
	// 		int offset = x+y*cBWidth;
	// 		int ch = charMem[offset];
	// 		int col = colMem[offset];
	// 		if (x == xCursor && y == yCursor & (renderCount & 4) == 0) {
	// 			col = vicky[0x10];
	// 			ch = vicky[0x11];
	// 		}
	// 		int fgr = colours[col >> 4];
	// 		int bgr = colours[(col & 0x0F)+16];
	// 		for (int yc = 0;yc < 8;yc++) {
	// 			int bitLine = fontMem[ch * 8 + yc];
	// 			rcp = rc;
	// 			rc.y += cSize;
	// 			for (int xc = 0;xc < 8;xc++) {					
	// 				GFXRectangle(&rcp,bitLine & 0x80 ? fgr:bgr);
	// 				rcp.x += cSize;
	// 				bitLine <<= 1;
	// 			}
	// 		}
	// 	}
	// }
}
