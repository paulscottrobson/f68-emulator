#ifndef _VBCCINLINE_BUGREPORT_H
#define _VBCCINLINE_BUGREPORT_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

void __SendBug(void *, STRPTR address, struct TagItem * taglist) =
	"\tlwz\t0,-28(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SendBug(address, taglist) __SendBug(BugReportBase, (address), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __SendBugTags(void *, STRPTR address, ...) =
	"\tlwz\t0,-28(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SendBugTags(address, ...) __SendBugTags(BugReportBase, (address), __VA_ARGS__)
#endif

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __BPrintf(void *, STRPTR format, ...) =
	"\tlwz\t0,-34(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define BPrintf(...) __BPrintf(BugReportBase, __VA_ARGS__)
#endif

void __BPutStr(void *, STRPTR string) =
	"\tlwz\t0,-40(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define BPutStr(string) __BPutStr(BugReportBase, (string))

void __ClearBug(void *) =
	"\tlwz\t0,-46(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ClearBug() __ClearBug(BugReportBase)

#endif /*  _VBCCINLINE_BUGREPORT_H  */
