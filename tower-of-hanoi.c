#include <stdio.h>
#include <stdlib.h>

void tower (int num, char *pegA, char *pegB, char *pegC)
{
	if (num == 1) {
		printf("%s -> %s\n", pegA, pegC);
		return;
	}

	tower(num-1, pegA, pegC, pegB);
	printf("%s -> %s\n", pegA, pegC);
	tower(num-1, pegB, pegA, pegC);
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