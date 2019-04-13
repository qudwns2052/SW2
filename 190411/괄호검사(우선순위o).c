#include <stdio.h>
#include <windows.h>

#define STACK_LEN 20
int stack[STACK_LEN];
int topindex = -1;

int Push(int data)
{
	if (topindex == STACK_LEN - 1)
		return -1;
	else
		stack[++topindex] = data;

	return data;
}

int Pop(void)
{
	if (topindex == -1)
		return -1;

	return stack[topindex--];
}

int Peek(void)
{
	if (topindex == -1)
		return -1;

	return stack[topindex];
}

int Prec(char ch)
{
	switch (ch)
	{
	case '[': case ']':
		return 3;
	case '{': case '}':
		return 2;
	case '(': case ')':
		return 1;
	default:
		return 4;
	}
}

int Check(char *str)
{
	char ch;
	int len = strlen(str);


	for (int i = 0; i < len; i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '[': case '{': case '(':
			if (Prec(Peek()) < Prec(ch))
				return -1;
			else
				printf("Push %c\n", Push(ch));
			break;
		case ']': case '}': case ')':
			if (Prec(Peek()) == Prec(ch))
				printf("Pop %c\n", Pop());
			else
				return -1;
			break;
		default:
			break;
		}
	}
	return 1;
}

int main(void)
{
	char * str = "3+[4*2-[3+4+{5-2+(3+2)}]]";

	int check = Check(str);

	if (check == -1)
		printf("오류 발생\n");
	else
		printf("성공\n");


	system("pause");
	return 0;
}