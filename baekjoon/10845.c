#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

int arr[10000];
int findex = 0;
int bindex = -1;

void Push(int data);
void Pop(void);
void Size(void);
int Empty(void);
void Front(void);
void Back(void);

int main()
{
	int num;
	char str[100];
	int data;

	scanf("%d", &num);
	fflush(stdin);


	for (int i = 0; i < num; i++)
	{

		scanf("%s", str);
		fflush(stdin);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &data);
			Push(data);
		}
		else if (strcmp(str, "pop") == 0)
		{
			Pop();
		}
		else if (strcmp(str, "size") == 0)
		{
			Size();
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", Empty());
		}
		else if (strcmp(str, "front") == 0)
		{
			Front();
		}
		else if (strcmp(str, "back") == 0)
		{
			Back();
		}
	}


	system("pause");
	return 0;
}

void Push(int data)
{
	bindex++;
	arr[bindex] = data;

}

void Pop(void)
{
	int rdx;
	if (Empty() == TRUE)
		printf("-1\n");
	else
	{
		rdx = findex;
		findex++;
		printf("%d\n", arr[rdx]);
	}
}

void Size(void)
{
	printf("%d\n", bindex - findex + 1);
}

int Empty(void)
{
	if (findex>bindex)
		return TRUE;
	else
		return FALSE;

}

void Front(void)
{
	if (Empty() == TRUE)
		printf("-1\n");
	else
		printf("%d\n", arr[findex]);
}

void Back(void)
{
	if (Empty() == TRUE)
		printf("-1\n");
	else
		printf("%d\n", arr[bindex]);
}