#ifndef _PROTO_VIRTUAL_H
#define _PROTO_VIRTUAL_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_VIRTUAL_PROTOS_H) && !defined(__GNUC__)
#include <clib/virtual_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *VirtualBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/virtual.h>
#else
#include <inline/virtual.h>
#endif
#elif defined(__VBCC__)
#include <inline/virtual_protos.h>
#else
#include <pragma/virtual_lib.h>
#endif

#endif	/*  _PROTO_VIRTUAL_H  */
