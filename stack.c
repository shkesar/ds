#include "stack.h"
#include "type.h"

#include <stdio.h>
#include <stdlib.h>


void grow_by_factor(stacked_t stack, int factor)
{
	stack.mem = realloc(stack.mem, sizeof(int) * stack.size * factor);
	stack.size *= factor;
}

void grow_by_size(stacked_t stack, int additional_space)
{
	stack.mem = realloc(stack.mem, sizeof(int) * (stack.size + additional_space));
	stack.size += additional_space;
}


/**** PUSH ****/
void push (stacked_t stack, void* val, type_t type)
{
	if (stack.size == stack.i - 1)
	{
		grow_by_factor(stack, 2);
	}

	any_t entry;
	entry.type = type;
	switch (entry.type)
	{
	case Int:
		entry.value.i = (int)val; break;
	case UInt:
		entry.value.ui = (unsigned int)val; break;
	case Char:
		entry.value.c = (char)val; break;
	case String:
		entry.value.s = (char*)val; break;
	case Long:
		entry.value.l = (long)val; break;
	case ULong:
		entry.value.ul = (unsigned long)val; break;
	case VoidPtr:
		entry.value.v = val; break;
	default:
		perror("Something happened!\n");
	}
	
	stack.mem[stack.i] = entry;
	stack.i += 1;
}

void push_int 	(stacked_t stack, int val) {
	void *ptr; ptr = &(val); push (stack, ptr, Int);
}
void push_uint 	(stacked_t stack, unsigned int val) {
	void *ptr; ptr = &(val); push (stack, ptr, UInt);
}
void push_char 	(stacked_t stack, char val) {
	void *ptr; ptr = &(val); push (stack, ptr, Char);
}
void push_string(stacked_t stack, char* val) {
	void *ptr; ptr = &(val); push (stack, ptr, String);
}
void push_long 	(stacked_t stack, long val) {
	void *ptr; ptr = &(val); push (stack, ptr, Long);
}
void push_ulong (stacked_t stack, unsigned long val) {
	void *ptr; ptr = &(val); push (stack, ptr, ULong);
}
/**** PUSH ****/


/*** POP ***/
any_t pop (stacked_t stack)
{
	if (stack.i < 0)
	{
		perror("stack");
		any_t val;
		val.type = String;
		val.value.s = "Empty";
		return val;
	}

	any_t entry = stack.mem[stack.i];
	stack.i -= 1;

	return entry;
}

int pop_int (stacked_t stack) {
	any_t val = pop(stack); return get_int(val);
}
unsigned int pop_uint (stacked_t stack) {
	any_t val = pop(stack); return get_uint(val);
}
char pop_char (stacked_t stack) {
	any_t val = pop(stack); return get_char(val);
}
char* pop_string (stacked_t stack) {
	any_t val = pop(stack); return get_string(val);
}
long pop_long (stacked_t stack) {
	any_t val = pop(stack); return get_long(val);
}
unsigned long pop_ulong (stacked_t stack) {
	any_t val = pop(stack); return get_ulong(val);
}
/*** POP ***/

stacked_t create_stack ()
{
	stacked_t stack;
	stack.mem = malloc(sizeof(int) * INITIAL_SIZE);
	stack.i = 0;
	stack.size = INITIAL_SIZE;

	return stack;
}

boolean_t is_empty (stacked_t stack)
{
	return stack.i == 0;
}

