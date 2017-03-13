#ifndef _STACK_H_
#define _STACK_H_

typedef struct {
	int *mem;
	int i;
	int size;
} stacked_t;

#define INITIAL_SIZE 8


void grow_by_factor(stacked_t, int factor);

void grow_by_size(stacked_t, int additional_space);

void push (stacked_t, int);

int pop (stacked_t);

bool is_empty (stacked_t);

stacked_t create_stack (int initial_size);

stacked_t create_stack ();

#endif