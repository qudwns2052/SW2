#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_LEN 100

typedef struct stack
{
	int * data;
	int capacity;
	int top;
}Stack;

void InitStack(Stack * s)
{
	s->capacity = 1;
	s->top = -1;
	s->data = (int*)malloc(sizeof(int)*s->capacity);
}
int Is_empty(Stack * s);
int Is_full(Stack * s);
void Push(Stack * s, int data)
{
	if (Is_full(s) == True)
	{
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, sizeof(int)*s->capacity);
	}
	s->data[++(s->top)] = data;
}

int Pop(Stack * s)
{
	if (Is_empty(s) == True)
		return -1;
	else
		return s->data[(s->top)--];
}

int Peek(Stack * s)
{
	if (Is_empty(s) == True)
		return -1;
	else
		return s->data[s->top];
}

int Is_empty(Stack * s)
{
	if (s->top == -1)
		return True;
	else
		return False;
}

int Is_full(Stack * s)
{
	if ((s->top) + 1 == (s->capacity))
		return True;
	else
		return False;
}

int Prec(char ch)
{
	switch(ch)
	{
		case '[': case ']': return 3;
		case '{': case '}': return 2;
		case '(': case ')': return 1;
	}
	return 4;
}

int Check(Stack * s, char * str)
{
	char ch;
	int i = 0;
	
	while (str[i] != '\0')
	{
		ch = str[i];
		i++;
		switch (ch)
		{
		case '[': case '{': case '(':
			if (Prec(Peek(s)) < Prec(ch))
				return -1;
			else
			{
				Push(s, ch);
				break;
			}
		case ']': case '}': case ')':
			if (Prec(Peek(s)) == Prec(ch))
			{
				Pop(s);
				break;
			}
			else
				return -1;

		default:
			break;
		}
	}
	return 1;
}

int main(void)
{
	Stack s;
	InitStack(&s);
	int result;
	char * str = (char*)malloc(sizeof(char)*MAX_LEN);
	scanf("%s", str);

	result = Check(&s, str);

	if (result > 0)
		printf("성공\n");
	else
		printf("실패\n");

	free(s.data);
	free(str);


	return 0;
}