#ifndef _VBCCINLINE_TOUCHPAD_H
#define _VBCCINLINE_TOUCHPAD_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

APTR __AddTouchpad(void *, struct TagItem * taglist) =
	"\tlwz\t0,-28(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define AddTouchpad(taglist) __AddTouchpad(TouchpadBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __AddTouchpadTags(void *, ...) =
	"\tlwz\t0,-28(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define AddTouchpadTags(...) __AddTouchpadTags(TouchpadBase, __VA_ARGS__)
#endif

void __RemoveTouchpad(void *, APTR touchpad, struct TagItem * taglist) =
	"\tlwz\t0,-34(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define RemoveTouchpad(touchpad, taglist) __RemoveTouchpad(TouchpadBase, (touchpad), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __RemoveTouchpadTags(void *, APTR touchpad, ...) =
	"\tlwz\t0,-34(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define RemoveTouchpadTags(touchpad, ...) __RemoveTouchpadTags(TouchpadBase, (touchpad), __VA_ARGS__)
#endif

void __FeedTouchpad(void *, APTR touchpad, UBYTE * xarray, UBYTE * yarray, ULONG buttonmask, struct TagItem * taglist) =
	"\tlwz\t0,-40(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define FeedTouchpad(touchpad, xarray, yarray, buttonmask, taglist) __FeedTouchpad(TouchpadBase, (touchpad), (xarray), (yarray), (buttonmask), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __FeedTouchpadTags(void *, APTR touchpad, UBYTE * xarray, UBYTE * yarray, ULONG buttonmask, ...) =
	"\tlwz\t0,-40(3)\n"
	"\taddi\t8,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define FeedTouchpadTags(touchpad, xarray, yarray, buttonmask, ...) __FeedTouchpadTags(TouchpadBase, (touchpad), (xarray), (yarray), (buttonmask), __VA_ARGS__)
#endif

APTR __ObtainTouchpad(void *, struct TagItem * taglist) =
	"\tlwz\t0,-46(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ObtainTouchpad(taglist) __ObtainTouchpad(TouchpadBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __ObtainTouchpadTags(void *, ...) =
	"\tlwz\t0,-46(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ObtainTouchpadTags(...) __ObtainTouchpadTags(TouchpadBase, __VA_ARGS__)
#endif

void __ReleaseTouchpad(void *, APTR touchpad, struct TagItem * taglist) =
	"\tlwz\t0,-52(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReleaseTouchpad(touchpad, taglist) __ReleaseTouchpad(TouchpadBase, (touchpad), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __ReleaseTouchpadTags(void *, APTR touchpad, ...) =
	"\tlwz\t0,-52(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReleaseTouchpadTags(touchpad, ...) __ReleaseTouchpadTags(TouchpadBase, (touchpad), __VA_ARGS__)
#endif

ULONG __GetTouchpadAttr(void *, APTR touchpad, struct TagItem * taglist) =
	"\tlwz\t0,-58(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetTouchpadAttr(touchpad, taglist) __GetTouchpadAttr(TouchpadBase, (touchpad), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __linearvarargs __GetTouchpadAttrTags(void *, APTR touchpad, ...) =
	"\tlwz\t0,-58(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetTouchpadAttrTags(touchpad, ...) __GetTouchpadAttrTags(TouchpadBase, (touchpad), __VA_ARGS__)
#endif

ULONG __SetTouchpadAttr(void *, APTR touchpad, struct TagItem * taglist) =
	"\tlwz\t0,-64(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SetTouchpadAttr(touchpad, taglist) __SetTouchpadAttr(TouchpadBase, (touchpad), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __linearvarargs __SetTouchpadAttrTags(void *, APTR touchpad, ...) =
	"\tlwz\t0,-64(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SetTouchpadAttrTags(touchpad, ...) __SetTouchpadAttrTags(TouchpadBase, (touchpad), __VA_ARGS__)
#endif

#endif /*  _VBCCINLINE_TOUCHPAD_H  */
