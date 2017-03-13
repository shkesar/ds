#include <stdio.h>

#include "stack.h"

int main(int argc, char const *argv[])
{
	stacked_t st = create_stack (8);
	push (st, 10);
	printf("%d\n", pop(st));
	push (st, 20);
	printf("%d\n", pop(st));
	return 0;
}
