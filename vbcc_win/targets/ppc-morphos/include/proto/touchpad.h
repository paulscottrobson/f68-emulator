#ifndef _PROTO_TOUCHPAD_H
#define _PROTO_TOUCHPAD_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_TOUCHPAD_PROTOS_H) && !defined(__GNUC__)
#include <clib/touchpad_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *TouchpadBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/touchpad.h>
#else
#include <inline/touchpad.h>
#endif
#elif defined(__VBCC__)
#include <inline/touchpad_protos.h>
#else
#include <pragma/touchpad_lib.h>
#endif

#endif	/*  _PROTO_TOUCHPAD_H  */
