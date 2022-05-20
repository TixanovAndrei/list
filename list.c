#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create(int data, LIST_ERR *err)
{    
    Node *list = (Node*)malloc(sizeof(Node));

    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = MALLOC;
		return NULL;
	}
    
    list -> value = data;
    list -> next = NULL;

    *err = SUCCESS;

    return (list);
}


void deleteList(Node **head, LIST_ERR *err)
{
    if (head == NULL) {
        fprintf(stderr, "Invalid argument: head\n");
		if (err != NULL) {
		    *err = INVARG;
        }
        return;
    }
    
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);

    *err = SUCCESS;
}

int main() {
    return 0;
}