#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    Node *list = NULL;
    LIST_ERR err;

	list = create(1, &err);
	if (list == NULL)
		fprintf(stdout, "Test_1.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1.1\t->\tPASSED\n");


return 0;
}