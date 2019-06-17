#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
}Node;

Node * MakeNode(void)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->data = 0;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

int SearchNode(Node * head, int data)
{
	Node * temp = head;

	while (temp!=NULL)
	{
		if (temp->data < data)
		{
			temp = temp->right;
		}
		else if (temp->data > data)
		{
			temp = temp->left;
		}
		else
			break;
	}

	if (temp != NULL)
		return 1;
	else
		return 0;

}

void MakeRandNode(Node * head)
{
	Node * newnode = MakeNode();
	Node * temp = head;

	newnode->data = rand() % 20 + 1;
	
	while (SearchNode(head, newnode->data))
		newnode->data = rand() % 20 + 1;
		


		while (1)
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
		}

		printf("%d를 삽입\n", newnode->data);
}

void DeleteNode(Node * head, int data)
{
	Node * temp = head->right;
	Node * front = head;
	Node * t_front = NULL;
	Node * remove = NULL;

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

	if (temp != NULL)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			if (front->right == temp)
				front->right = NULL;
			else
				front->left = NULL;
		}
		else if (temp->left == NULL && temp->right != NULL)
		{
			if (front->left == temp)
			{
				front->left = temp->right;
			}
			else
				front->right = temp->right;
		}
		else if (temp->left != NULL && temp->right == NULL)
		{
			if (front->left == temp)
			{
				front->left = temp->left;
			}
			else
				front->right = temp->left;
		}
		else
		{
			remove = temp;
			t_front = temp;
			temp = temp->right;

			while (temp->left != NULL)
			{
				t_front = temp;
				temp = temp->left;
			}

			if (front->right == remove)
				front->right = temp;
			else
				front->left = temp;

			if (temp->right == NULL)
			{
				if (t_front->right == temp)
					t_front->right = NULL;
				else
					t_front->left = NULL;
			}
			else
			{
				if (t_front->right == temp)
					t_front->right = temp->right;
				else
					t_front->left = temp->right;
			}

			temp->left = remove->left;
			temp->right = remove->right;
		}
		printf("%d 삭제 완료\n", data);
	}

	else
	{
		printf("데이터가 존재하지 않습니다\n");
	}

}

Node * Queue[50];
int front = -1;
int rear = -1;

void addQueue(Node * node)
{
	if (rear == 49)
		return;

	Queue[++rear] = node;
}

Node * delQueue(void)
{
	if (front == rear)
		return NULL;

	return Queue[++front];
}

void InorderSearch(Node * node)
{
	Node * temp = node;

	if (temp == NULL)
		return;

	InorderSearch(temp->left);
	printf("%d\n", temp->data);
	InorderSearch(temp->right);
}

void LevelSearch(Node * node)
{
	if (node == NULL)
		return;

	Node * temp = NULL;
	
	addQueue(node);

	while (1)
	{
		temp = delQueue();

		if (temp == NULL)
			break;

		printf("%d\n", temp->data);

		if (temp->left != NULL)
			addQueue(temp->left);

		if (temp->right != NULL)
			addQueue(temp->right);
	}
	


}

int main(void)
{
	srand((unsigned)time(NULL));

	Node * head = MakeNode();
	int num;

	for (int i = 0; i < 10; i++)
	{
		MakeRandNode(head);
	}

	while (1)
	{
		printf("----------------------------\n");
		InorderSearch(head->right);
		printf("----------------------------\n");
		printf("삭제할 노드의 data?\n>> ");
		scanf("%d", &num);

		DeleteNode(head, num);
	}


	system("pause");

	return 0;
}