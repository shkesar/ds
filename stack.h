#ifndef _STACK_H_
#define _STACK_H_

#include "type.h"

#define INITIAL_SIZE 8


typedef struct {
	any_t *mem;
	int i;
	int size;
} stacked_t;

void grow_by_factor(stacked_t, int factor);

void grow_by_size(stacked_t, int additional_space);

void 			push 		(stacked_t, void *val, type_t);
void 			push_int 	(stacked_t, int);
void 			push_uint 	(stacked_t, unsigned int);
void 			push_char 	(stacked_t, char);
void 			push_string(stacked_t, char*);
void 			push_long 	(stacked_t, long);
void 			push_ulong (stacked_t, unsigned long);

any_t 			pop 		(stacked_t);
int 			pop_int 	(stacked_t);
unsigned int 	pop_uint 	(stacked_t);
char 			pop_char 	(stacked_t);
char* 			pop_string 	(stacked_t);
long 			pop_long 	(stacked_t);
unsigned long 	pop_ulong 	(stacked_t);

boolean_t is_empty (stacked_t);

stacked_t create_stack ();


#endif