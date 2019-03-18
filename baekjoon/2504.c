#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

int topindex = -1;
char str[30];

void Push(char data);
void Pop(void);

int main()
{
	int i;
	char str2[30];
	int temp = 1;
	int strLen;
	int result = 0;

	scanf("%s", str2);
	getchar();
	strLen = strlen(str2);
	
	for (i = 0; i < strLen; i++)
	{
		if (str2[i] == '(')
		{
			Push(str2[i]);
			temp *= 2;
		}
		else if (str2[i] == '[')
		{
			Push(str2[i]);
			temp *= 3;
		}
		else if (str2[i] == ')')
		{
			if (str2[i - 1] == '(')
				result += temp;
			Pop();
			temp /= 2;
		}
		else if (str2[i] == ']')
		{
			if (str2[i - 1] == '[')
				result += temp;
			Pop();
			temp /= 3;
		}
	}

	return 0;
}

void Push(char data)
{
	topindex++;
	str[topindex] = data;
}

void Pop(void)
{
	int rdx;
	rdx = topindex;
	topindex--;
	return str[rdx];
}