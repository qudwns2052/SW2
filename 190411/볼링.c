#include <stdio.h>
#include <windows.h>

//문제: 볼링 점수 10개를 받아서 이중연결리스트 구현 후, 새로운 리스트에 오름차순으로 정렬. 그 후, 사용자가 원하는대로 출력(오름차순, 내림차순)

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

void backPrint(List * list)
{
	Node * temp = list->tail;

	for (int i = 0; i < list->cnt; i++)
	{
		printf("%d: %d\n", i + 1, temp->pre->data);
		temp = temp->pre;
	}

}

void Sort(List * list, List * newlist)
{
	int min = 0;
	int least;
	int max = 100;

	for (int i = 0; i < 10; i++)
	{
		Node * temp = list->head->next;
		
		least = max;

		while (temp != list->tail)
		{
			if (least > temp->data && temp->data > min)
				least = temp->data;
			
			temp = temp->next;
		}
		min = least;
		
		Add(newlist, min);
	}

}


int main(void)
{
	List list;
	int i;
	InitList(&list);
	int num;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		Add(&list, num);
	}
	Print(&list);
	

	List newlist;
	InitList(&newlist);

	Sort(&list, &newlist);

	printf("\n\n오름차순 정렬 >>>\n");
	Print(&newlist);

	printf("\n\n내림차순 정렬 >>>\n");
	backPrint(&newlist);



	system("pause");
	return 0;
}