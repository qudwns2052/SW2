#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
int Calculate(char * str);
int Push(int data);
int Pop(void);
int Peek(void);
int Prec(char ch);

char * infix_to_postfix(char * str)
{
	char * temp = (char*)malloc(sizeof(char)*MAX_SIZE);
	int i = 0;
	int cnt = 0;
	while (str[i] != '\0')
	{
		char ch = str[i];
		switch (ch)
		{
		case '*': case '/': case '+': case '-':
			if (Prec(Peek()) >= Prec(ch))
				temp[cnt++] = Pop();
			Push(ch);
			break;

		case '(':
			Push(ch);
			break;
		case ')':
			while (Peek() != '(')
				temp[cnt++] = Pop();
			Pop();
			break;
		default:
			temp[cnt++] = ch;
		}
		i++;
	}
	while (top != -1)
		temp[cnt++] = Pop();

	temp[cnt] = '\0';
	return temp;
}

int Push(int data)
{
	if (top == MAX_SIZE - 1)
		return -1;
	return stack[++top] = data;
}

int Pop(void)
{
	if (top == -1)
		return -1;
	return stack[top--];
}

int Peek(void)
{
	if (top == -1)
		return -1;
	return stack[top];
}

int Prec(char ch)
{
	switch (ch)
	{
	case '*': case '/': return 3;
	case '+': case '-': return 2;
	case '(': case ')': return 1;
	default: return -1;
	}
}

int main(void)
{
	char * str1 = "(2+3)*4+9";
	printf("중위표기: %s\n", str1);
	
	char * str2 = NULL;
	str2 = infix_to_postfix(str1);
	printf("후위표기: %s\n", str2);
	
	int result;
	result = Calculate(str2);
	printf("결과: %d\n", result);
	free(str2);
	system("pause");
	return 0;
}

int Calculate(char * str)
{
	int i = 0;
	char op1, op2;
	int op3;
	int result;
	while (str[i] != '\0')
	{
		char ch = str[i];
		switch (ch)
		{
		case '*':
			op2 = Pop();
			op1 = Pop();
			op3 = op1 * op2;
			Push(op3);
			break;
		case '/':
			op2 = Pop();
			op1 = Pop();
			op3 = op1 / op2;
			Push(op3);
			break;
		case '+':
			op2 = Pop();
			op1 = Pop();
			op3 = op1 + op2;
			Push(op3);
			break;
		case '-':
			op2 = Pop();
			op1 = Pop();
			op3 = op1 - op2;
			Push(op3);
			break;
		default:
			Push(ch-'0');
		}
		i++;
	}
	result = Pop();
	return result;
}