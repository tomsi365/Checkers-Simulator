#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"


// checks for malloc allocation attempts
void checkAllocation(void* node)
{
	if (node == NULL)
	{
		fprintf(stderr, "%s", "allocation error");
		exit(1);
	}
}

// find max value between two integers
int findMax(int val1, int val2)
{
	return val1 <= val2 ? val2 : val1;
}




