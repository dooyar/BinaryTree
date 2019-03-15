#include "tree.h"

int main()
{
//	int i = 0;
//	int str[] = {1,3,2,0,0,5,0,0,0,7,4,8,0,0,6,0,0,9,0,0};
	Node *ptr = NULL;

//	for(;i < sizeof(str)/sizeof(int);i++)
		if(!(ptr = create()))
		{
			printf("Error!\n");
			exit(1);
		}
//	balance(ptr);
	draw(ptr);
	freeTree(ptr);
	return 0;
}
