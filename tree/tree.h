#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct tree
{
	struct tree *l,*r;
	char data;
}Node;

//static Node *newnode;
Node *create();
int balance(Node *);
void draw(Node *);
void freeTree(Node *);
