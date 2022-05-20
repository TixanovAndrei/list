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

    push(1, NULL, &err);
    if (err != INVARG)
		fprintf(stdout, "Test_2.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_2.1\t->\tPASSED\n");

    push(2, &list, &err);
    if (err != SUCCESS)
		fprintf(stdout, "Test_2.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_2.2\t->\tPASSED\n");

    int i = 0;
    for (i = 3; i<= 10; i++) {
        push(i, &list, &err);
    }
    if (err != SUCCESS)
		fprintf(stdout, "Test_2.3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_2.3\t->\tPASSED\n");

	pop(NULL, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_3.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_3.1\t->\tPASSED\n");

	int n;
	for (i = 0; i < 9; i++) {
		n = pop(&list, &err);
		printf("%d ", n);
	}
	printf("\n");
	if (err != SUCCESS)
		fprintf(stdout, "Test_3.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_3.2\t->\tPASSED\n");

	pop(&list, &err);
	if (err != HEAD)
		fprintf(stdout, "Test_3.3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_3.3\t->\tPASSED\n");

	for (i = 2; i<= 10; i++) {
        push(i, &list, &err);
    }

    

    return 0;
}