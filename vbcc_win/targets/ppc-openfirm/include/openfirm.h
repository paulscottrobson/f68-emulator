/*
 * vbcc PPC/OpenFirmware
 * (c)2006 by Frank Wille
 */

/* Generic functions */
int OF_test(char *);

/* Device tree functions */
int OF_peer(int);
int OF_child(int);
int OF_parent(int);
int OF_instance_to_package(int);
int OF_getproplen(int,char *);
int OF_getprop(int,char *,void *,int);
int OF_nextprop(int,char *,void *);
int OF_setprop(int,char *,void *,int);
int OF_canon(const char *,char *,int);
int OF_finddevice(const char *);
int OF_instance_to_path(int,char *,int);
int OF_package_to_path(int,char *,int);
int OF_call_method(char *,int,int,int,...);

/* Device I/O functions */
int OF_open(char *);
void OF_close(int);
int OF_read(int,void *,int);
int OF_write(int,void *,int);
int OF_seek(int,unsigned long long);

/* Memory functions */
void *OF_claim(void *,unsigned int,unsigned int);
void OF_release(void *,unsigned int);

/* Control transfer functions */
void OF_boot(char *);
void OF_enter(void);
void OF_exit(void);

/* Time function */
unsigned long OF_milliseconds(void);
