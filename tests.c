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

    pushBack(NULL, 11, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_4.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_4.1\t->\tPASSED\n");

	pushBack(list, 11, &err);
	if (err != SUCCESS)
		fprintf(stdout, "Test_4.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_4.2\t->\tPASSED\n");

	for (i = 12; i < 16; i++) {
		pushBack(list, i, &err);
	}

	popBack(NULL, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_5.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_5.1\t->\tPASSED\n");

	for (i = 0; i < 14; i++) {
		n = popBack(&list, &err);
		printf("%d ", n);
	}
	printf("\n");
	if (err != SUCCESS)
		fprintf(stdout, "Test_5.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_5.2\t->\tPASSED\n");

	popBack(&list, &err);
	if (err != HEAD)
		fprintf(stdout, "Test_5.3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_5.3\t->\tPASSED\n");

    deleteList(NULL, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_6.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_6.1\t->\tPASSED\n");
	
	deleteList(&list, &err);
	if (err != SUCCESS)
		fprintf(stdout, "Test_6.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_6.2\t->\tPASSED\n");

	list = create(1, &err);

	for (i = 2; i <= 5; i++) {
		pushBack(list, i, &err);
	}

	search(NULL, 2, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_7.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_7.1\t->\tPASSED\n");

	search(&list, 6, &err);
	if (err != NOTEXIST)
		fprintf(stdout, "Test_7.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_7.2\t->\tPASSED\n");

	search(&list, 3, &err);
	if (err != SUCCESS)
		fprintf(stdout, "Test_7.3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_7.3\t->\tPASSED\n");

	find(NULL, 2, &err);
	if (err != INVARG)
		fprintf(stdout, "Test_8.1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_8.1\t->\tPASSED\n");

	find(&list, 6, &err);
	if (err != NOTEXIST)
		fprintf(stdout, "Test_8.2\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_8.2\t->\tPASSED\n");

	find(&list, 3, &err);
	if (err != SUCCESS)
		fprintf(stdout, "Test_8.3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_8.3\t->\tPASSED\n");

	deleteList(&list, &err);


    return 0;
}