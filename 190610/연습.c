#include <stdio.h>
#include <windows.h>

#define MAX_H 1000000

typedef struct node
{
	int data;

}Node;

int main(void)
{
	Node ** hashTable = (Node**)malloc(sizeof(Node*) * MAX_H);

	for (int i = 0; i < MAX_H; i++)
	{
		hashTable[i] = (Node*)malloc(sizeof(Node));
		hashTable[i]->data = i;
	}


	for (int i = 0; i < MAX_H; i++)
		printf("%d\n", hashTable[i]->data);

	system("pause");
	return 0;
}