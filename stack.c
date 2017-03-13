#include "stack.h"

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

void push (stacked_t stack, int val)
{
	if (stack.size == stack.i - 1)
	{
		grow_by_factor(stack, 2);
	}
	stack.mem[stack.i] = val;
	stack.i += 1;
}

bool is_empty (stacked_t stack)
{
	return stack.i == 0;
}

int pop (stacked_t stack)
{
	if (stack.i < 0)
	{
		perror("stack");
		return -1;
	}
	return stack.mem[stack.i];
	stack.i -= 1;
}

stacked_t create_stack ()
{
	stacked_t stack;
	stack.mem = malloc(sizeof(int) * INITIAL_SIZE);
	stack.i = 0;
	stack.size = INITIAL_SIZE;

	return stack;
}
