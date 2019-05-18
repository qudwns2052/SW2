#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct TreeNode
{
	char data;
	struct TreeNode * left;
	struct TreeNode * right;
}TreeNode;

TreeNode n1 = { 'h', NULL, NULL };
TreeNode n2 = { 'g', NULL, NULL };
TreeNode n3 = { 'f', NULL, NULL };
TreeNode n4 = { 'e', &n2, &n1 };
TreeNode n5 = { 'd', &n3, NULL };
TreeNode n6 = { 'c', &n4, NULL };
TreeNode n7 = { 'b', NULL, &n5 };
TreeNode n8 = { 'a', &n7, &n6 };
TreeNode * root = &n8;

TreeNode * stack[20];
int topindex = -1;

void Push(TreeNode * data)
{
	if (topindex + 1 >= 20)
		return;

	if (data == NULL)
		return;

	topindex++;
	stack[topindex] = data;
}

TreeNode * Pop(void)
{
	if (topindex == -1)
		return NULL;

	return stack[topindex--];
}

void SPreOrder(TreeNode * root)
{
	TreeNode * a = NULL;

	Push(root);

	while (1)
	{
		a = Pop();

		if (a == NULL)
			break;

		printf("%c\n", a->data);

		Push(a->right);
		Push(a->left);
	}
}

void SInOrder(TreeNode * root)
{
	TreeNode * a = NULL;

	a = root;
	
	while (1)
	{
		while (a != NULL)
		{
			Push(a);
			a = a->left;
		}
		a = Pop();

		if (a == NULL)
			break;
	
		printf("%c\n", a->data);
		
		a = a->right;
			
	}

		
	
}

void SPostOrder(TreeNode * root)
{
	TreeNode * a = NULL;

	a = root;

	while (1)
	{
		while (a != NULL)
		{
			if (a->data != 'Z')
			{
				Push(a);
				a = a->left;
			}
		}
		a = Pop();
		
		if (a == NULL)
			break;

		if (a->right != NULL && a->right->data != 'Z')
		{
			Push(a);
			a = a->right;
		}
		else
		{
			printf("%c\n", a->data);
			a->data = 'Z';
			a = NULL;
		}
	}

}


void PreOrder(TreeNode * root)
{
	if (root == NULL)
		return;
	printf("%c\n", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(TreeNode * root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c\n", root->data);
	InOrder(root->right);

}

void PostOrder(TreeNode * root)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c\n", root->data);
}

int main(void)
{
	printf("PreOrder\n");
	PreOrder(root);
	printf("SPreOrder\n");
	SPreOrder(root);

	printf("InOrder\n");
	InOrder(root);
	printf("SInOrder\n");
	SInOrder(root);
	
	printf("PostOrder\n");
	PostOrder(root);
	printf("SPostOrder\n");
	SPostOrder(root);
	


	system("pause");

	return 0;
}