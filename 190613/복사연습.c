#include <stdio.h>

typedef struct Node 
{
	int data;
	struct Node * left;
	struct Node * right;
}Node;

void Copy(Node * tree1)
{
	Node * head = tree1;
	Node * t_left = head->left;
	Node * t_right = head->right;
	Node * temp = head;
	Node * sub = head;

	while (sub->left != NULL)
	{





		
	}


}