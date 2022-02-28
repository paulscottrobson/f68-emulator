#ifndef _PROTO_LOG_H
#define _PROTO_LOG_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_LOG_PROTOS_H) && !defined(__GNUC__)
#include <clib/log_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *LogBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/log.h>
#else
#include <inline/log.h>
#endif
#elif defined(__VBCC__)
#include <inline/log_protos.h>
#else
#include <pragma/log_lib.h>
#endif

#endif	/*  _PROTO_LOG_H  */
