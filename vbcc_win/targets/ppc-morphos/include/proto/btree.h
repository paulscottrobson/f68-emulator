#ifndef _PROTO_BTREE_H
#define _PROTO_BTREE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_BTREE_PROTOS_H) && !defined(__GNUC__)
#include <clib/btree_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *BTreeBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/btree.h>
#else
#include <inline/btree.h>
#endif
#elif defined(__VBCC__)
#include <inline/btree_protos.h>
#else
#include <pragma/btree_lib.h>
#endif

#endif	/*  _PROTO_BTREE_H  */
