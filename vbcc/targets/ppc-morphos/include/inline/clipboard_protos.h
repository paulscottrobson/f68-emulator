#ifndef _VBCCINLINE_CLIPBOARD_H
#define _VBCCINLINE_CLIPBOARD_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

APTR __ReadClipTextA(void *, struct TagItem * taglist) =
	"\tlwz\t0,-28(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReadClipTextA(taglist) __ReadClipTextA(ClipboardBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __ReadClipText(void *, ...) =
	"\tlwz\t0,-28(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReadClipText(...) __ReadClipText(ClipboardBase, __VA_ARGS__)
#endif

LONG __WriteClipTextA(void *, CONST_APTR text, struct TagItem * taglist) =
	"\tlwz\t0,-34(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define WriteClipTextA(text, taglist) __WriteClipTextA(ClipboardBase, (text), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __linearvarargs __WriteClipText(void *, CONST_APTR text, ...) =
	"\tlwz\t0,-34(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define WriteClipText(text, ...) __WriteClipText(ClipboardBase, (text), __VA_ARGS__)
#endif

VOID __FreeClipText(void *, CONST_APTR text) =
	"\tlwz\t0,-40(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define FreeClipText(text) __FreeClipText(ClipboardBase, (text))

LONG __GetClipType(void *, ULONG unit) =
	"\tlwz\t0,-46(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetClipType(unit) __GetClipType(ClipboardBase, (unit))

#endif /*  _VBCCINLINE_CLIPBOARD_H  */
