#ifndef _PROTO_HARFBUZZ_H
#define _PROTO_HARFBUZZ_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_HARFBUZZ_PROTOS_H) && !defined(__GNUC__)
#include <clib/harfbuzz_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *HarfbuzzBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/harfbuzz.h>
#else
#include <inline/harfbuzz.h>
#endif
#elif defined(__VBCC__)
#include <inline/harfbuzz_protos.h>
#else
#include <pragma/harfbuzz_lib.h>
#endif

#endif	/*  _PROTO_HARFBUZZ_H  */
