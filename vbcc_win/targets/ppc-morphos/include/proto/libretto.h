#ifndef _PROTO_LIBRETTO_H
#define _PROTO_LIBRETTO_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_LIBRETTO_PROTOS_H) && !defined(__GNUC__)
#include <clib/libretto_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *LibrettoBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/libretto.h>
#else
#include <inline/libretto.h>
#endif
#elif defined(__VBCC__)
#include <inline/libretto_protos.h>
#else
#include <pragma/libretto_lib.h>
#endif

#endif	/*  _PROTO_LIBRETTO_H  */
