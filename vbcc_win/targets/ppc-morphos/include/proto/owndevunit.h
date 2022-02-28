#ifndef _PROTO_OWNDEVUNIT_H
#define _PROTO_OWNDEVUNIT_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_OWNDEVUNIT_PROTOS_H) && !defined(__GNUC__)
#include <clib/owndevunit_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *OwnDevUnitBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/owndevunit.h>
#else
#include <inline/owndevunit.h>
#endif
#elif defined(__VBCC__)
#include <inline/owndevunit_protos.h>
#else
#include <pragma/owndevunit_lib.h>
#endif

#endif	/*  _PROTO_OWNDEVUNIT_H  */
