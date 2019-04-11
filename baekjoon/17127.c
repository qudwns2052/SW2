#include <stdio.h>
#include <windows.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int * arr = malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	int max1;
	int max2;
	int result = 1;

	max1 = 0;

	for (int i = 1; i < N; i++)
	{
		if (arr[max1] < arr[i])
			max1 = i;
	}
	
	max2 = 0;

	for (int i = 1; i < N; i++)
	{
		if (arr[max2] < arr[i])
		{
			if (max1 == i)
				continue;
			else
				max2 = i;
		}
	}

	if (max2 - max1 > 0)
	{
		if ((max1 + (N - 1) - max2) == 3)
		{
			for (int i = max1; i < max2 + 1; i++)
			{
				result *= arr[i];
			}
			for (int i = 0; i < max1; i++)
			{
				result += arr[i];
			}
			for (int i = max2 + 1; i < N; i++)
			{
				result += arr[i];
			}
		}
	}

	printf("%d", result);



	system("pause");
	return 0;
}