#include <stdio.h>
#include <windows.h>

typedef struct Node
{
	int data;
	struct Node * pre;
	struct Node * next;
}Node;

typedef struct list
{
	int cnt;
	Node * head;
	Node * tail;

}List;

Node * NewNode(int data)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->next = node->pre = NULL;
	node->data = data;

	return node;
}
void InitList(List * list)
{
	list->head = NewNode(0);
	list->tail = NewNode(0);
	list->head->next = list->tail;
	list->tail->pre = list->head;
	list->cnt = 0;
}

void Add(List * list, int data)
{
	Node * node = NewNode(data);
	node->pre = list->tail->pre;
	node->next = list->tail;
	list->tail->pre->next = node;
	list->tail->pre = node;
	list->cnt++;
}

void Print(List * list)
{
	Node * temp = list->head;

	for (int i = 0; i < list->cnt; i++)
	{
		printf("%d: %d\n", i + 1, temp->next->data);
		temp = temp->next;
	}

}

int main(void)
{
	List list;
	InitList(&list);
	int num;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		Add(&list, num);
	}
	
	Print(&list);
	Print(&list);



	system("pause");
	return 0;
}