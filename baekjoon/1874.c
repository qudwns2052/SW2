#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

int arr1[100000];
int arr2[100000];
char arr3[200000];
int charidx = 0;
int topindex = -1;

void Push(int data);
void Pop(void);

int main()
{
	int num;
	int i, j;
	int cnt = 1;
	int index;

	scanf("%d", &num);


	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr2[i]);
	}

	for (i = 0; i < num; i++)
	{
		if (arr2[i] > cnt - 1)
		{
			index = cnt - 1;

			for (j = 0; j < arr2[i] - index; j++)
				Push(cnt++);
			Pop();
		}
		else
		{
			if (arr2[i] == arr1[topindex])
				Pop();
			else
			{
				printf("NO\n");
				return 0;
			}

		}


	}

	for (i = 0; i < charidx; i++)
		printf("%c\n", arr3[i]);

	system("pause");
	return 0;
}

void Push(int data)
{
	topindex += 1;
	arr1[topindex] = data;
	arr3[charidx] = '+';
	charidx++;
}

void Pop(void)
{
	topindex -= 1;
	arr3[charidx] = '-';
	charidx++;
	
}

