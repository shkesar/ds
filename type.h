#ifndef _TYPE_H
#define _TYPE_H

typedef enum {
	FALSE = 0,
	TRUE = !FALSE
} boolean_t;

typedef enum {
	Int,
	UInt,
	Char,
	String,
	Long,
	ULong,
	VoidPtr
} type_t;

typedef union {
	int i;
	unsigned int ui;
	char c;
	char *s;
	long l;
	unsigned long ul;
	void *v;
} value_t;

typedef struct {
	type_t type;
	value_t value;
} any_t;


int 			get_int 	(any_t);
unsigned int 	get_uint 	(any_t);
char 			get_char 	(any_t);
char* 			get_string 	(any_t);
long 			get_long 	(any_t);
unsigned long 	get_ulong 	(any_t);
void* 			get_vptr 	(any_t);

#endif