#ifndef _VBCCINLINE_HASHTABLE_H
#define _VBCCINLINE_HASHTABLE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

APTR __CreateHashTableTagList(CONST struct TagItem * taglist) =
	"\tlis\t11,HashTableBase@ha\n"
	"\tlwz\t12,HashTableBase@l(11)\n"
	"\tlwz\t0,-28(12)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define CreateHashTableTagList(taglist) __CreateHashTableTagList((taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
CONST_APTR __linearvarargs __CreateHashTableTags(...) =
	"\tlis\t11,HashTableBase@ha\n"
	"\tlwz\t12,HashTableBase@l(11)\n"
	"\tlwz\t0,-28(12)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define CreateHashTableTags(...) __CreateHashTableTags(__VA_ARGS__)
#endif

#endif /*  _VBCCINLINE_HASHTABLE_H  */
