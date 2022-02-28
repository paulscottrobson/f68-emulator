#ifndef _VBCCINLINE_EXTRAS_H
#define _VBCCINLINE_EXTRAS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

struct BitMap* __LoadImageToBitMapA(void *, CONST_STRPTR path, struct TagItem* taglist) =
	"\tlwz\t0,-28(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadImageToBitMapA(path, taglist) __LoadImageToBitMapA(ExtrasBase, (path), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct BitMap* __linearvarargs __LoadImageToBitMap(void *, CONST_STRPTR path, ...) =
	"\tlwz\t0,-28(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadImageToBitMap(path, ...) __LoadImageToBitMap(ExtrasBase, (path), __VA_ARGS__)
#endif

APTR __LoadFileA(void *, CONST_STRPTR path, struct TagItem* taglist) =
	"\tlwz\t0,-34(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadFileA(path, taglist) __LoadFileA(ExtrasBase, (path), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __LoadFile(void *, CONST_STRPTR path, ...) =
	"\tlwz\t0,-34(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadFile(path, ...) __LoadFile(ExtrasBase, (path), __VA_ARGS__)
#endif

APTR __LoadImageToArrayA(void *, CONST_STRPTR path, struct TagItem* taglist) =
	"\tlwz\t0,-40(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadImageToArrayA(path, taglist) __LoadImageToArrayA(ExtrasBase, (path), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __LoadImageToArray(void *, CONST_STRPTR path, ...) =
	"\tlwz\t0,-40(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define LoadImageToArray(path, ...) __LoadImageToArray(ExtrasBase, (path), __VA_ARGS__)
#endif

#endif /*  _VBCCINLINE_EXTRAS_H  */
