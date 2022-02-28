#ifndef _PROTO_ISO639_H
#define _PROTO_ISO639_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_ISO639_PROTOS_H) && !defined(__GNUC__)
#include <clib/iso639_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *ISO639Base;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/iso639.h>
#else
#include <inline/iso639.h>
#endif
#elif defined(__VBCC__)
#include <inline/iso639_protos.h>
#else
#include <pragma/iso639_lib.h>
#endif

#endif	/*  _PROTO_ISO639_H  */
