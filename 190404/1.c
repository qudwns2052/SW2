#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define True 1
#define False 0

typedef struct StackType
{
	int *data;
	int capacity;
	int top;
}StackType;

void StackInit(StackType *s);
void Push(StackType *s, int data);
int Pop(StackType *s);
int Isfull(StackType *s);

void StackInit(StackType * s)
{
	s->capacity = 1;
	s->data = (int*)malloc(sizeof(int)*(s->capacity));
	s->top = -1;

}

void Push(StackType *s, int data)
{
	if (Isfull(s))
	{
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, sizeof(int)*(s->capacity));
	}
	
	s->data[++(s->top)] = data;
}

int Pop(StackType *s)
{
	return s->data[(s->top)--];
}


int Isfull(StackType *s)
{
	return (s->top == (s->capacity) - 1);
}

int main(void)
{
	StackType * s;

	s = (StackType *)malloc(sizeof(StackType));

	StackInit(s);
	
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", Pop(s));
	}

	free(s);

	system("pause");
	return 0;
}