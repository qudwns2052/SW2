#include <stdio.h>
#include <windows.h>

typedef struct _Node
{
	struct _Node * link;
	int data;
}Node;

Node * Init(void)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->link = NULL;
	node->data = 0;
	return node;
}

void Push(Node * head, int data)
{
	Node * temp = head;
	Node * Newnode = Init();

	while (temp->link != NULL)
		temp = temp->link;

	temp->link = Newnode;
	Newnode->data = data;
	printf("Push: %d\n", data);

}

int Pop(Node * head)
{
	Node * temp = head->link;
	Node * front = head;
	
	if (temp == NULL)
		return -1;

	while (temp->link != NULL)
	{	
		front = front->link;
		temp = temp->link;
	}

	
	int r_data = temp->data;
	front->link = NULL;
	return r_data;
	
}


int main(void)
{
	Node * node = Init();

	for (int i = 1; i < 10; i++)
	{
		Push(node, i);
	}

	for (int j = 0; j < 12; j++)
	{
		printf("Pop %d \n",Pop(node));
	}



	system("pause");
	return 0;
}