#ifndef _PROTO_SENSORS_H
#define _PROTO_SENSORS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_SENSORS_PROTOS_H) && !defined(__GNUC__)
#include <clib/sensors_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *SensorsBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/sensors.h>
#else
#include <inline/sensors.h>
#endif
#elif defined(__VBCC__)
#include <inline/sensors_protos.h>
#else
#include <pragma/sensors_lib.h>
#endif

#endif	/*  _PROTO_SENSORS_H  */
