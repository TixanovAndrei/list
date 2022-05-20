#ifndef _LIST_H_
#define _LIST_H_

struct Node{
    int value;
    struct Node *next;
};

typedef struct Node Node;

typedef enum {
    HEAD,
    INVARG,
    SUCCESS,
    MALLOC
} LIST_ERR;

Node *create(int data, LIST_ERR *err);

void push(int data, Node **head, LIST_ERR *err);

int pop(Node **head, LIST_ERR *err);

Node *getLast(Node *head);

void pushBack(Node *head, int val, LIST_ERR *err);

Node *getPenult (Node* head);

int popBack (Node **head, LIST_ERR *err);

void deleteList(Node **head, LIST_ERR *err);

#endif