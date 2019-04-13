#include <stdio.h>
#include <windows.h>

typedef struct node
{
	int data;
	struct node * pre;
	struct node * next;

}Node;

typedef struct list
{
	int cnt;
	Node * head;
	Node * tail;

}List;

Node * NewNode(int data)
{
	Node * newnode = malloc(sizeof(Node));

	newnode->data = data;
	newnode->pre = newnode->next = NULL;

	return newnode;
}

void InitList(List * list)
{
	list->head = NewNode(0);
	list->tail = NewNode(0);
	list->head->next = list->tail;
	list->tail->pre = list->head;
	list->cnt = 0;
}

void AddNode(List * list, int data)
{
	Node * newnode = NewNode(data);

	newnode->pre = list->tail->pre;
	newnode->next = list->tail;
	list->tail->pre->next = newnode;
	list->tail->pre = newnode;
	list->cnt++;



}

void Print(List * list)
{
	Node * temp = list->head->next;

	for (int i = 0; i < list->cnt; i++)
	{
		printf("%d번째 데이터: %d\n", i + 1, temp->data);
		temp = temp->next;
	}
}

void BackPrint(List * list)
{
	Node * temp = list->tail->pre;

	for (int i = 0; i < list->cnt; i++)
	{
		printf("%d번째 데이터: %d\n", i + 1, temp->data);
		temp = temp->pre;
	}
}

void Sort(List * list, List * newlist)
{
	Node * temp;

	int min = 0;
	int max = 1000;
	int least;
	
	while (newlist->cnt < 10)
	{
		temp = list->head->next;
		least = max;
		for (int i = 0; i < list->cnt; i++)
		{
			if (least > temp->data && temp->data > min)
			{
				least = temp->data;
			}
			temp = temp->next;
		}
		min = least;
		AddNode(newlist, least);
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
		AddNode(&list, num);
	}

	Print(&list);

	List newlist;
	InitList(&newlist);

	Sort(&list, &newlist);
	printf("\n오름차순\n");
	Print(&newlist);
	printf("\n내림차순\n");
	BackPrint(&newlist);

	system("pause");
	return 0;
}