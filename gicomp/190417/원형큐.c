#include <stdio.h>
#include <windows.h>
#define MAX_SIZE 21
#define True 1
#define False 0

typedef struct queue
{
	int data[MAX_SIZE];
	int rear;
	int front;
}Queue;

void InitQueue(Queue * q)
{
	q->rear = 0;
	q->front = 0;
}

int Is_full(Queue * q)
{
	if ((q->rear + 1) % MAX_SIZE == q->front)
		return True;
	else
		return False;
}

int Is_empty(Queue * q)
{
	if (q->rear == q->front)
		return True;
	else
		return False;
}

int AddQueue(Queue * q, int data)
{
	if (Is_full(q) == True)
		return -1;

	q->rear++;
	
	q->rear = q->rear % MAX_SIZE;

	return q->data[q->rear] = data;
	
}

int DelQueue(Queue *q)
{
	if (Is_empty(q) == True)
		return -1;

	q->front++;

	q->front = q->front % MAX_SIZE;

	return q->data[q->front];
}

int main(void)
{
	Queue q;

	InitQueue(&q);
	int num;


	while (1)
	{
		scanf("%d", &num);

		for (int i = 0; i < num; i++)
		{
			printf("Add: %d\n", AddQueue(&q, i));
		}

		scanf("%d", &num);

		for (int i = 0; i < num; i++)
		{
			printf("Del: %d\n", DelQueue(&q));
		}

	}
	system("pause");
	return 0;
}