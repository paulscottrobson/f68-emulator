#ifndef _PROTO_TINYGL_H
#define _PROTO_TINYGL_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_TINYGL_PROTOS_H) && !defined(__GNUC__)
#include <clib/tinygl_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *TinyGLBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/tinygl.h>
#else
#include <inline/tinygl.h>
#endif
#elif defined(__VBCC__)
#include <inline/tinygl_protos.h>
#else
#include <pragma/tinygl_lib.h>
#endif

#endif	/*  _PROTO_TINYGL_H  */
