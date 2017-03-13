#include <stdio.h>

#include "stack.h"

int main(int argc, char const *argv[])
{
	stacked_t st = create_stack (8);

	push_int (st, 10);
	push_int (st, 20);
	push_char (st, 'S');

	printf("%c\n", pop_string(st));
	printf("%d\n", pop_int(st));;
	printf("%d\n", pop_int(st));

	return 0;
}
