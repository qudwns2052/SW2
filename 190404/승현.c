#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

int arr[10000];
int topindex = -1;

void Push(int data);
void Pop(void);
void Size(void);
int Empty(void);
void Top(void);

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
		else if (strcmp(str, "top") == 0)
		{
			Top();
		}

	}

	return 0;
}

void Push(int data)
{
	/*힌트
	1. topindex값 조절
	2. arr배열에 data저장
	*/
}

void Pop(void)
{

	int rdx;
	if (Empty() == 1)
		printf("%d\n", topindex);
	else
	{
		/*힌트
		topindex 활용
		Pop한 값 출력
		*/
	}
}

void Size(void)
{
	printf("%d\n", topindex + 1);
}

int Empty(void)
{
	if (topindex == -1)
		return TRUE;
	else
		return FALSE;

}

void Top(void)
{
	if (Empty() == 1)
		printf("%d\n", topindex);
	else
		printf("%d\n", arr[topindex]);

}