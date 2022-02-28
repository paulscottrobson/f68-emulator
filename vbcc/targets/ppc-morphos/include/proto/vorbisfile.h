#ifndef _PROTO_VORBISFILE_H
#define _PROTO_VORBISFILE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_VORBISFILE_PROTOS_H) && !defined(__GNUC__)
#include <clib/vorbisfile_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *VorbisFileBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/vorbisfile.h>
#else
#include <inline/vorbisfile.h>
#endif
#elif defined(__VBCC__)
#include <inline/vorbisfile_protos.h>
#else
#include <pragma/vorbisfile_lib.h>
#endif

#endif	/*  _PROTO_VORBISFILE_H  */
