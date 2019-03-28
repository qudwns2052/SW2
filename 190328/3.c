#include <stdio.h>
#include <windows.h>
#define LEN 6



int main(void)
{
	int arr1[LEN][3] = { 0 };
	int arr2[LEN][3] = { 0 };
	int result[LEN * 2][3] = { 0 };
	int i, j, k;
	int True;


	for (i = 0; i < LEN; i++)
	{
		scanf("%d %d %d", &arr1[i][0], &arr1[i][1], &arr1[i][2]);
	}
	

	for (i = 0; i < LEN; i++)
	{
		scanf("%d %d %d", &arr2[i][0], &arr2[i][1], &arr2[i][2]);
	}

	for (i = 0; i < LEN; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j] = arr1[i][j];
		}
		
	}

	printf("\n\n");

	for (i = 0; i < LEN; i++)
	{
		printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
	}


	int cnt = 0;

	for (i = 0; i < LEN; i++)
	{
		True = 0;

		for (k = 0; k < LEN; k++)
		{
			if ((arr2[i][0] == result[k][0]) && (arr2[i][1] == result[k][1]))
			{
				result[k][2] += arr2[i][2];
				True = 1;
				break;
			}

		}
		if(True == 0)
		{
			for (j = 0; j < 3; j++)
			{
				result[LEN + cnt][j] = arr2[i][j];
			}
			cnt++;
		}
	}



	
	
	printf("\n\n");

	for (i = 0; i < LEN * 2; i++)
	{
		printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
	}

	printf("\n\n");

	printf("cnt : %d\n", cnt);


	system("pause");
	return 0;
}