#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct Node
{
	int data;
	struct Node * left;
	struct Node * right;

}Node;

Node * NodeInit(void)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

Node * NewNode(int data)
{
	Node * newnode = NodeInit();
	newnode->data = data;

	return newnode;
}

int BinarySearchTree(Node * head, Node * newnode)
{
	Node * temp = head;

	while (temp != NULL)
	{
		if (temp->data < newnode->data)
		{
			if (temp->right == NULL)
			{
				temp->right = newnode;
				break;
			}
			else
				temp = temp->right;
		}
		else if (temp->data > newnode->data)
		{
			if (temp->left == NULL)
			{
				temp->left = newnode;
				break;
			}
			else
				temp = temp->left;
		}
		else
		{
			printf("겹치네\n");
			return 0;
		}
	}

	return 1;
}

void Inorder(Node * node)
{
	if (node == NULL)
		return;
	Inorder(node->left);
	printf("%d ", node->data);
	Inorder(node->right);

}

void DeleteNode(Node * head, int data)
{
	Node * temp = head;
	Node * front = NULL;
	while (temp != NULL)
	{
		if (temp->data < data)
		{
			front = temp;
			temp = temp->right;
		}
		else if (temp->data > data)
		{
			front = temp;
			temp = temp->left;
		}
		else
			break;
	}

	if (temp == NULL)
	{
		printf("없음\n");
		return;
	}

	if (temp->left == NULL && temp->right == NULL)
	{
		if (front->left == temp)
			front->left = NULL;
		else
			front->right = NULL;
	}
	else if (temp->left == NULL && temp->right != NULL)
	{
		if (front->left == temp)
			front->left = temp->right;
		else
			front->right = temp->right;
	}
	else if (temp->left != NULL && temp->right == NULL)
	{
		if (front->left == temp)
			front->left = temp->left;
		else
			front->right = temp->left;
	}
	else
	{
		Node * sub = temp->right;
		Node * sub_front = NULL;

		while (sub->left != NULL)
		{
			sub_front = temp;
			sub = sub->left;
		}

		if (front->left == temp)
			front->left = sub;
		else
			front->right = sub;

		if (sub_front == NULL)
		{
			sub->left = temp->left;
			temp->right = NULL;
		}
		else if (sub->right == NULL)
		{
			sub->left = temp->left;
			sub->right = temp->right;
			sub_front->left = NULL;
		}
		else
		{
			sub->left = temp->left;
			sub_front->left = sub->right;
			sub->right = temp->right;
		}



	}


}


int main(void)
{
	srand((unsigned)time(NULL));

	Node * head = NewNode(0);

	int num;
	for (int i = 0; i < 10; i++)
	{
		num = rand() % 20 + 1;
	
		if (BinarySearchTree(head, NewNode(num)) == 0)
			i--;
	}

	Inorder(head->right);
	printf("\n");

	while (1)
	{
		printf("삭제할 노드 번호 >> ");
		scanf("%d", &num);
		DeleteNode(head, num);
		Inorder(head->right);
		printf("\n");
	}


	system("pause");
	return 0;
}