/* string.h - vbcc i386 */

#ifndef __STRING_H
#define __STRING_H 1

#ifndef __SIZE_T
#define __SIZE_T 1
typedef unsigned long size_t;
#endif

#undef NULL
#define NULL ((void *)0)

void *memcpy(void *,const void *,size_t);
void *memmove(void *,const void *,size_t);
char *strcpy(char *,const char *);
char *strncpy(char *,const char *,size_t);
char *strcat(char *,const char *);
char *strncat(char *,const char *,size_t);
int memcmp(const void *,const void *,size_t);
int strcmp(const char *,const char *);
int strncmp(const char *,const char *,size_t);
void *memchr(const void *,int,size_t);
char *strchr(const char *,int);
size_t strcspn(const char *,const char *);
char *strpbrk(const char *,const char *);
char *strrchr(const char *,int);
size_t strspn(const char *,const char *);
char *strstr(const char *,const char *);
void *memset(void *,int,size_t);
size_t strlen(const char *);
char *strtok(char *,const char *);
char *strerror(int);
int strcoll(const char *,const char *);
size_t strxfrm(char *,const char *,size_t);

#ifndef __NOINLINE__
/* i386 inline functions */
size_t __asm_strlen(__reg("%edi") const char *) =
        "\tcld\n"
        "\txor\t%eax,%eax\n"
        "\tmov\t%eax,%ecx\n"
        "\tdec\t%ecx\n"
        "\trepne\n"
        "\tscasb\n"
        "\tnot\t%ecx\n"
        "\tlea\t-1(%ecx),%eax";

#define strlen(p) __asm_strlen(p)
#endif /* __NOINLINE__ */

#endif
