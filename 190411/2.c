#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];

int top = -1;

void Push(int data)
{
	stack[++top] = data;
}

int Pop(void)
{
	return stack[top--];
}
int Peek(void)
{
	if (top == -1)
		return -1;
	else
		return stack[top];
}

int Prec(char ch)
{
	switch (ch)
	{
	case '*': case'/':
		return 2;
	case '+': case'-':
		return 1;
	}
	return -1;
}

void infix_to_postfix(char * str)
{

	int i = 0;
	int len = strlen(str);

	while (i < len)
	{
		char ch = str[i];
		switch (ch)
		{
		case '*':case '/': case'+': case'-':
			if (Prec(Peek()) >= Prec(ch))
			{
				printf("%c", Pop());
			}
			Push(ch);
			break;
		case '(':
			Push(ch);
			break;
		case ')':
			while (Peek() != '(')
			{
				printf("%c", Pop());
			}
			Pop();
			break;
		default:
			printf("%c", ch);
			break;
		}
		i++;
	}
	while (Peek() != -1)
	{
		printf("%c", Pop());
	}

}
int main(void)
{
	char * str = "2+3*(5+4*2)-3+6";
	
	infix_to_postfix(str);
	

	system("pause");
	return 0;
}