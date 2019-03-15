#include "tree.h"

static Node *createTree();
static int get_num(Node *);
static Node *find_min(Node *);
static Node *find_max(Node *);
static void turn_left(Node **);
static void turn_right(Node **);
static void balance_(Node **);
static void print_s(Node *);
static void draw_(Node *,int );

static Node *createTree()
{
	Node *ptr;
	int ch;
	printf("#-,-:");
	scanf("%d",&ch);
	if(0 == ch)
		ptr = NULL;
	else	
	{
		if(!(ptr = (Node *)malloc(sizeof(Node))))
				return NULL;
		ptr->l = ptr->r = NULL;
		ptr->data = ch;
		printf("Now is %d leaf_node\n",ch);
		ptr->l = createTree();
		printf("Now is %d right_node\n",ch);
		ptr->r = createTree();
	}
	return ptr;
}
//////////// Balance ////////////
static int get_num(Node *ptr)
{
    if(ptr == NULL)
        return 0;
    return get_num(ptr->l) + 1 + get_num(ptr->r);
}

static Node *find_min(Node *ptr)
{
    if(ptr->l == NULL)
        return ptr;
    return find_min(ptr->l);
}

static Node *find_max(Node *ptr)
{
    if(ptr->r == NULL)
        return ptr;
    return find_max(ptr->r);
}

static void turn_left(Node **ptr)
{
    Node *cur = *ptr;    

    *ptr = cur->r;
    cur->r = NULL;
    find_min(*ptr)->l = cur;
}

static void turn_right(Node **ptr)
{
    Node *cur = *ptr;
    *ptr = cur->l;
    cur->l = NULL;
    find_max(*ptr)->r = cur;
}

static void balance_(Node **ptr)
{
    int sub;

    if(*ptr == NULL)
        return ;
    
    while(1)
    {
        sub = get_num((*ptr)->l) - get_num((*ptr)->r);
        if(sub >= -1 && sub <= 1)
            break; 
        if(sub < -1)
            turn_left(ptr);
        else
            turn_right(ptr);
    }
    balance_(&(*ptr)->l);
    balance_(&(*ptr)->r);
}
//////////// Balance over ////////////
//////////// Draw ////////////
static void print_s(Node *ptr)
{
	printf("%d\n",ptr->data);
}

static void draw_(Node *ptr,int level)
{
    int i;
    if(ptr == NULL)
        return ;    
    draw_(ptr->r,level+1);
    for(i = 0 ; i < level; i++)
        printf("    ");
    print_s(ptr);
    draw_(ptr->l,level+1);
}
//////////// Draw over ////////////
Node *create()
{
	Node *ptr;
	if(!(ptr = createTree()))
		return NULL;
	return ptr;
}

int balance(Node *ptr)
{
	balance_(&ptr);	
	return 0;
}

void draw(Node *ptr)
{
	printf("\33[31mDrawing Tree\33[0m\n");
    draw_(ptr,0);
	printf("\33[31mDrawing Tree\33[0m\n");
}

void freeTree(Node *ptr)
{
	if(!ptr)
		return;
	freeTree(ptr->l);
	freeTree(ptr->r);
	free(ptr);
	ptr = NULL;
}
