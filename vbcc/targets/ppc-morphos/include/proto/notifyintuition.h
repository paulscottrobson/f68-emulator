#ifndef _PROTO_NOTIFYINTUITION_H
#define _PROTO_NOTIFYINTUITION_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_NOTIFYINTUITION_PROTOS_H) && !defined(__GNUC__)
#include <clib/notifyintuition_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *NotIBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/notifyintuition.h>
#else
#include <inline/notifyintuition.h>
#endif
#elif defined(__VBCC__)
#include <inline/notifyintuition_protos.h>
#else
#include <pragma/notifyintuition_lib.h>
#endif

#endif	/*  _PROTO_NOTIFYINTUITION_H  */
