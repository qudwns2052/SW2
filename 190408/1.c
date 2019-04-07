#include <stdio.h>
#include <windows.h>

void matrix(int n, int * arr1, int * arr2)
{
	int * result = malloc(sizeof(int)* n);

	int bit = 1;

	for (int i = 0; i < n; i++)
	{
		result[i] = arr1[i] | arr2[i];
		bit *= 2;

	}

	for (int i = 0; i < n; i++)
	{
		int seek = bit;

		while (seek /= 2)
		{
			printf("%c", result[i] & seek ? '#' : ' ');
		}
		printf("\n");


	}

}


int main(void)
{
	int n;

	scanf("%d", &n);

	int * arr1 = malloc(sizeof(int) *n);
	int * arr2 = malloc(sizeof(int) *n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr2[i]);
	}

	matrix(n, arr1, arr2);



	system("pause");
	return 0;
}