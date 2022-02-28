#ifndef _VBCCINLINE_DEVICEIO_H
#define _VBCCINLINE_DEVICEIO_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

struct DeviceIO * __DIO_InitDeviceIOA(void *, CONST_STRPTR name, CONST struct TagItem * Tags) =
	"\tlwz\t0,-76(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define DIO_InitDeviceIOA(name, Tags) __DIO_InitDeviceIOA(DeviceIOBase, (name), (Tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct DeviceIO * __linearvarargs __DIO_InitDeviceIO(void *, CONST_STRPTR name, ...) =
	"\tlwz\t0,-76(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define DIO_InitDeviceIO(...) __DIO_InitDeviceIO(DeviceIOBase, __VA_ARGS__)
#endif

#endif /*  _VBCCINLINE_DEVICEIO_H  */
