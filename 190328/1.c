#include <stdio.h>
#include <windows.h>
#define LEN 6



int main(void)
{
	int arr1[LEN][3] = { 0 };
	int arr2[LEN][3] = { 0 };
	int temp[LEN][2] = { 0 };
	int i, j;
	int tempdata;


	for (i = 0; i < LEN; i++)
	{
		scanf("%d %d %d", &arr1[i][0], &arr1[i][1], &arr1[i][2]);	
	}


	for (i = 0; i < LEN; i++)
	{
		temp[i][0] = arr1[i][1];
		temp[i][1] = i;
	}

	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < LEN - i - 1; j++)
		{
			if (temp[j][0] > temp[j + 1][0])
			{
				tempdata = temp[j][0];
				temp[j][0] = temp[j + 1][0];
				temp[j + 1][0] = tempdata;
				
				tempdata = temp[j][1];
				temp[j][1] = temp[j + 1][1];
				temp[j + 1][1] = tempdata;
			}
		}
	}

	int idx;

	for (i = 0; i < LEN; i++)
	{
		idx = temp[i][1];

		arr2[i][0] = arr1[idx][1];
		arr2[i][1] = arr1[idx][0];
		arr2[i][2] = arr1[idx][2];
		
	}
	
	printf("\n\n");

	for (i = 0; i < LEN; i++)
	{
		printf("%d %d %d\n", arr1[i][0], arr1[i][1], arr1[i][2]);
	}

	printf("\n\n");
	
	for (i = 0; i < LEN; i++)
	{
		printf("%d %d\n", temp[i][0], temp[i][1]);
	}

	printf("\n\n");

	for (i = 0; i < LEN; i++)
	{
		printf("%d %d %d\n", arr2[i][0], arr2[i][1], arr2[i][2]);
	}

	system("pause");
	return 0;
}