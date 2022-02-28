#ifndef _PROTO_LUA_H
#define _PROTO_LUA_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_LUA_PROTOS_H) && !defined(__GNUC__)
#include <clib/lua_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *LuaBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/lua.h>
#else
#include <inline/lua.h>
#endif
#elif defined(__VBCC__)
#include <inline/lua_protos.h>
#else
#include <pragma/lua_lib.h>
#endif

#endif	/*  _PROTO_LUA_H  */
