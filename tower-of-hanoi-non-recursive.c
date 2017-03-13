#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void tower (int num, char *pegA, char *pegB, char *pegC)
{
	stacked_t num_st, pegA_st, pegB_st, pegC_st;

	push_int(num_st, num);
	push_string(pegA_st, pegA);
	push_string(pegB_st, pegB);
	push_string(pegC_st, pegC);

	while (!is_empty(num_st))
	{
		if (num == 1) {
			printf("%s -> %s\n", pegA, pegC);
			continue;
		}

		push_int(num_st, num-1);
		push_string(pegA_st, pegA);
		push_string(pegB_st, pegC);
		push_string(pegC_st, pegB);
		// tower(num-1, pegA, pegC, pegB);

		printf("%s -> %s\n", pegA, pegC);

		push_int(num_st, num-1);
		push_string(pegA_st, pegB);
		push_string(pegB_st, pegA);
		push_string(pegC_st, pegC);
		// tower(num-1, pegB, pegA, pegC);
	}

	return;
}

int main(int argc, char const *argv[])
{
	int peg_count = atoi(argv[1]);
	char* pegA = "A";
	char* pegB = "B";
	char* pegC = "C";

	tower(peg_count, pegA, pegB, pegC);
	return 0;
}