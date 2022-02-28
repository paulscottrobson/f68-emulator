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
void *__asm_memcpy(__reg("a0") void *, __reg("a1") const void *,
                   __reg("d2") size_t) =
        "\tinline\n"
        "\tmoveq\t#16,d0\n"
        "\tcmp.l\td0,d2\n"
        "\tblo.b\t.3\n"
        "\tmove.l\ta0,d0\n"
        "\tmove.l\ta1,d1\n"
        "\teor.l\td1,d0\n"
        "\tlsr.l\t#1,d0\n"
        "\tbcs.b\t.5\n"
        "\tmove.l\ta0,d0\n"
        "\tlsr.l\t#1,d1\n"
        "\tbcc.b\t.2\n"
        "\tmove.b\t(a1)+,(a0)+\n"
        "\tsubq.l\t#1,d2\n"
        "\tdc.w\t$51fa\n"
        ".1\n"
        "\tmove.l\t(a1)+,(a0)+\n"
        ".2\n"
        "\tsubq.l\t#4,d2\n"
        "\tbpl.b\t.1\n"
        "\taddq.l\t#4,d2\n"
        "\tbeq.b\t.6\n"
        "\tdc.w\t$51fa\n"
        ".3\n"
        "\tmove.l\ta0,d0\n"
        "\tdc.w\t$51fa\n"
        ".4\n"
        "\tmove.b\t(a1)+,(a0)+\n"
        ".5\n"
        "\tsubq.l\t#1,d2\n"
        "\tbpl.b\t.4\n"
        ".6\n"
        "\teinline";

void *__asm_memcpy_desc(__reg("a0") void *, __reg("a1") const void *,
                        __reg("d2") size_t) =
        "\tinline\n"
        "\tmoveq\t#16,d0\n"
        "\tcmp.l\td0,d2\n"
        "\tblo.b\t.4\n"
        "\tmove.l\ta0,d0\n"
        "\tmove.l\ta1,d1\n"
        "\teor.l\td1,d0\n"
        "\tlsr.l\t#1,d0\n"
        "\tbcs.b\t.4\n"
        "\tlsr.l\t#1,d1\n"
        "\tbcc.b\t.2\n"
        "\tmove.b\t-(a1),-(a0)\n"
        "\tsubq.l\t#1,d2\n"
        "\tdc.w\t$51fa\n"
        ".1\n"
        "\tmove.l\t-(a1),-(a0)\n"
        ".2\n"
        "\tsubq.l\t#4,d2\n"
        "\tbpl.b\t.1\n"
        "\taddq.l\t#4,d2\n"
        "\tbeq.b\t.5\n"
        "\tdc.w\t$51fa\n"
        ".3\n"
        "\tmove.b\t-(a1),-(a0)\n"
        ".4\n"
        "\tsubq.l\t#1,d2\n"
        "\tbpl.b\t.3\n"
        ".5\n"
        "\tmove.l\ta0,d0\n"
        "\teinline";

void *__asm_memset(__reg("a0") void *, __reg("d0") int, __reg("d2") size_t) =
        "\tinline\n"
        "\tmove.l\ta0,a1\n"
        "\tmoveq\t#16,d1\n"
        "\tcmp.l\td1,d2\n"
        "\tblo.b\t.5\n"
        "\tmove.l\ta0,d1\n"
        "\tlsr.l\t#1,d1\n"
        "\tbcc.b\t.1\n"
        "\tmove.b\td0,(a0)+\n"
        "\tsubq.l\t#1,d2\n"
        ".1\n"
        "\tmove.b\td0,d1\n"
        "\tlsl.l\t#8,d0\n"
        "\tmove.b\td1,d0\n"
        "\tmove.w\td0,d1\n"
        "\tswap\td0\n"
        "\tmove.w\td1,d0\n"
        "\tdc.w\t$51fa\n" 
        ".2\n"
        "\tmove.l\td0,(a0)+\n"
        "\tsubq.l\t#4,d2\n"
        "\tbpl.b\t.2\n"
        "\taddq.l\t#4,d2\n"
        "\tbeq.b\t.6\n"
        "\tdc.w\t$51fa\n"
        ".4\n"
        "\tmove.b\td0,(a0)+\n"
        ".5\n"
        "\tsubq.l\t#1,d2\n"
        "\tbpl.b\t.4\n"
        ".6\n"
        "\tmove.l\ta1,d0\n"
        "\teinline";

size_t __asm_strlen(__reg("a0") const char *) =
        "\tinline\n"
        "\tmove.l\ta0,d0\n"
        ".1\n"
        "\ttst.b\t(a0)+\n"
        "\tbne.b\t.1\n"
        "\tsub.l\ta0,d0\n"
        "\tnot.l\td0\n"
        "\teinline";

char *__asm_strcpy(__reg("a0") char *, __reg("a1") const char *) =
        "\tinline\n"
        "\tmove.l\ta0,d0\n"
        ".1\n"
        "\tmove.b\t(a1)+,(a0)+\n"
        "\tbne.b\t.1\n"
        "\teinline";

char *__asm_strncpy(__reg("a0") char *, __reg("a1") const char *,
                    __reg("d1") size_t) =
        "\tinline\n"
        "\tmove.l\ta0,d0\n"
        "\tbra.b\t*+6\n"
        ".1\n"
        "\tmove.b\t(a1),(a0)+\n"
        "\tbeq.b\t.2\n"
        "\taddq.l\t#1,a1\n"
        ".2\n"
        "\tsubq.l\t#1,d1\n"
        "\tbpl.b\t.1\n"
        "\teinline";

int __asm_strcmp(__reg("a0") const char *, __reg("a1") const char *) =
        "\tinline\n"
        "\tmoveq\t#0,d0\n"
        "\tmoveq\t#0,d1\n"
        ".1\n"
        "\tmove.b\t(a0)+,d0\n"
        "\tmove.b\t(a1)+,d1\n"
        "\tbeq.b\t.2\n"
        "\tsub.l\td1,d0\n"
        "\tbeq.b\t.1\n"
        "\tmoveq\t#0,d1\n"
        ".2\n"
        "\tsub.l\td1,d0\n"
        "\teinline";

int __asm_strncmp(__reg("a0") const char *, __reg("a1") const char *,
                  __reg("d2") size_t) =
        "\tinline\n"
        "\tmoveq\t#0,d0\n"
        "\tmoveq\t#0,d1\n"
        ".1\n"
        "\tsubq.l\t#1,d2\n"
        "\tbmi.b\t.2\n"
        "\tmove.b\t(a0)+,d0\n"
        "\tmove.b\t(a1)+,d1\n"
        "\tbeq.b\t.2\n"
        "\tsub.l\td1,d0\n"
        "\tbeq.b\t.1\n"
        "\tmoveq\t#0,d1\n"
        ".2\n"
        "\tsub.l\td1,d0\n"
        "\teinline";

#define memcpy(d,s,n) __asm_memcpy(d,s,n)
#define memmove(d,s,n) ((d)<=(s) ? __asm_memcpy(d,s,n) : \
                                   __asm_memcpy_desc((char *)(d)+(n),(char *)(s)+(n),n))
#define memset(p,f,n) __asm_memset(p,f,n)
#define strlen(p) __asm_strlen(p)
#define strcpy(d,s) __asm_strcpy(d,s)
#define strncpy(d,s,n) __asm_strncpy(d,s,n)
#define strcmp(s1,s2) __asm_strcmp(s1,s2)
#define strncmp(s1,s2,n) __asm_strncmp(s1,s2,n)

#endif /* __NOINLINE__ */


#endif
