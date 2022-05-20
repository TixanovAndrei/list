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

void push(int data, Node **head, LIST_ERR *err)
{    
    if (head == NULL) {
        fprintf(stderr, "Invalid argument: head\n");
		if (err != NULL) {
		    *err = INVARG;
        }
        return;
    }
    
    Node *elem = (Node*)malloc(sizeof(Node));
    
    elem -> value = data;
    elem -> next = *head;

    (*head) = elem;

    *err = SUCCESS;
}

int pop(Node **head, LIST_ERR *err)
{
    if (head == NULL) {
        fprintf(stderr, "Invalid argument: head\n");
		if (err != NULL) {
		    *err = INVARG;
        }
        return -1;
    }

    if ((*head)->next == NULL) {
        fprintf(stderr, "Impossible to remove head element\n");
		if (err != NULL) {
		    *err = HEAD;
        }
        return -1;
    }

    Node* prev = NULL;
    int val = 0;
    
    prev = (*head);
    val = prev -> value;
    *(head) = (*head) -> next;
    
    free(prev);

    *err = SUCCESS;

    return val;
}

Node *getLast(Node *head)
{
    while (head -> next) {
        head = head -> next;
    }

    return(head);
}

void pushBack(Node *head, int data, LIST_ERR *err)
{
    if (head == NULL) {
        fprintf(stderr, "Invalid argument: head\n");
		if (err != NULL) {
		    *err = INVARG;
        }
        return;
    }
    
    Node *last = getLast (head);
    
    Node *elem = (Node*) malloc(sizeof(Node));
    
    elem -> value = data;
    elem -> next = NULL;
    last -> next = elem;

    *err = SUCCESS;  
}


int main() {
    return 0;
}