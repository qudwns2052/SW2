#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_SIZE 20

char * stack;

int top = -1;

void Push(char data)
{
	stack[++top] = data;
}

char Pop(void)
{
	return stack[top--];
}

int main(void)
{
	char * str1 = "A[(i+1)]=0;}}}}}}";
	char * str2 = "A[(i+1)]=0;";

	int result1 = 0;
	int result2 = 0;

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i;


	stack = malloc(sizeof(char)*MAX_SIZE);

	i = 0;
	while (i < len1 && result1 != -1)
	{
		char ch = str1[i];

		switch (ch)
		{
		case '(': case '{': case '[':
			Push(ch);
			break;
		case ')':
			if (Pop() != '(')
				result1 = -1;
			break;
		case '}':
			if (Pop() != '{')
				result1 = -1;
			break;
		case ']':
			if (Pop() != '[')
				result1 = -1;
			break;
		default:
			break;
		}
		i++;

	}


	if (top == -1 && result1 != -1)
	{
		printf("성공!!\n");
	}
	else
	{
		printf("실패!!\n");
	}


	free(stack);
	stack = malloc(sizeof(char)*MAX_SIZE);

	top = -1;
	i = 0;

	while (i < len2 && result2 != -1)
	{
		char ch = str2[i];

		switch (ch)
		{
		case '(': case '{': case '[':
			Push(ch);
			break;
		case ')':
			if (Pop() != '(')
				result2 = -1;
			break;
		case '}':
			if (Pop() != '{')
				result2 = -1;
			break;
		case ']':
			if (Pop() != '[')
				result2 = -1;
			break;
		default:
			break;
		}
		i++;
	}

	if (top == -1 && result2 != -1)
	{
		printf("성공!!\n");
	}
	else
	{
		printf("실패!!\n");
	}

	free(stack);


	system("pause");
	return 0;
}