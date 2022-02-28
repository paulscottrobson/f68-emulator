/* MorphOS POSIX compatibility */

#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#ifndef __MORPHOS_SHAREDLIBS
#error sys/types.h exists for compatibility with __MORPHOS_SHAREDLIBS only!
#endif

#include <stdint.h>

typedef unsigned char            u_int8_t;
typedef unsigned short          u_int16_t;
typedef unsigned int            u_int32_t;
typedef unsigned long long      u_int64_t;

typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
typedef unsigned short  ushort;         /* Sys V compatibility */
typedef unsigned int    uint;           /* Sys V compatibility */

typedef u_int64_t       u_quad_t;       /* quads */
typedef int64_t         quad_t;
typedef quad_t *        qaddr_t;

typedef int32_t         off_t;          /* file offset */

#endif /* _SYS_TYPES_H_ */
