#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_SIZE 5

typedef struct queue
{
	char name[5];
	int birth;
	char what[5];
}Queue;

Queue q[MAX_SIZE];
int front = 0;
int rear = 0;

void AddQueue(char * name, int birth, char * what)
{
	if (rear == MAX_SIZE)
		return;
	strcpy(q[rear].name, name, strlen(name));
	q[rear].birth = birth;
	strcpy(q[rear].what, what, strlen(what));
	rear++;
}

int DeleteQueue(void)
{
	if (rear == front)
		return -1;
	front++;
	return front - 1;
}

int main(void)
{
	AddQueue("�����", 970424, "����");
	AddQueue("�ۿ�ȣ", 960401, "��");
	AddQueue("�ֺ���", 970103, "����");

	int cnt = 0;

	while (1)
	{
		cnt = DeleteQueue();
		if (cnt == -1)
			break;
		printf("�̸�: %s\n�������: %d\n����: %s\n", q[cnt].name, q[cnt].birth, q[cnt].what);
	}


	system("pause");
	return 0;
}