#include <stdio.h>
#include <stdlib.h>
typedef char Data;

typedef struct _TreeNode
{
	Data data;
	struct _TreeNode * left;
	struct _TreeNode * right;
}TreeNode;

TreeNode * MakeNode(Data data);

void Preorder(TreeNode * node);
void Inorder(TreeNode * node);
void Postorder(TreeNode * node);


int main(void)
{
	int num;
	int i;
	int cnt = 1;
	char A = 'A';
	int idx;
	
	TreeNode * Node[26];

	Data data1, data2, data3;

	scanf("%d", &num);
	getchar();
	
	Node[0] = MakeNode(A);

	
	for (i = 0; i < num; i++)
	{
		scanf("%c%c%c", &data1, &data2, &data3);
		getchar();


		idx = data1 - A;

		if (data2 != '.')
		{
			Node[cnt] = MakeNode(data2);
			Node[idx]->left = Node[cnt];
			cnt++;
		}

		if (data3 != '.')
		{
			Node[cnt] = MakeNode(data3);
			Node[idx]->right = Node[cnt];
			cnt++;
		}

	}


	Preorder(Node[0]); printf("\n");
	Inorder(Node[0]); printf("\n");
	Postorder(Node[0]); printf("\n");

	for (i = 0; i < num; i++)
		free(Node[i]);
	
	system("pause");

	return 0;
}

TreeNode * MakeNode(Data data)
{
	TreeNode * nd = (TreeNode *)malloc(sizeof(TreeNode));
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

void Preorder(TreeNode * node)
{
	if (node == NULL)
		return;

	printf("%c", node->data);

	Preorder(node->left);
	Preorder(node->right);
}

void Inorder(TreeNode * node)
{
	if (node == NULL)
		return;

	Inorder(node->left);
	printf("%c", node->data);
	Inorder(node->right);
}

void Postorder(TreeNode * node)
{
	if (node == NULL)
		return;


	Postorder(node->left);
	Postorder(node->right);
	printf("%c", node->data);
}