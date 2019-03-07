#include <stdio.h>
#include <stdlib.h>

int * Result(int arr[], int arr2[][3]);
int Sort(int arr3[], int idx, int len);

int main()
{
	int arr[7] = { 1,5,2,6,3,7,4 };
	int what[3][3] = { 2,5,3,4,4,1,1,7,3 };
	int *ptr;

	ptr=Result(arr, what);

	printf("return값: [%d, %d, %d]\n", ptr[0], ptr[1], ptr[2]);
	free(ptr);

	system("pause");
	return 0;
}



int * Result(int arr[], int arr2[][3])
{
	int * result = malloc(sizeof(int));
	int arr3[7];
	int len;
	int i, j;
	int start, end, idx;
	for (i = 0; i < 3; i++)
	{
		start = arr2[i][0];
		end = arr2[i][1];
		idx = arr2[i][2];
		len = end - start + 1;
		for (j = 0; j < len; j++)
		{
			arr3[j] = arr[start - 1 + j];
		}
		printf("[1, 5, 2, 6, 3, 7, 4]를 %d번째부터 %d번째까지 자른 후 정렬하여 %d번째 값을 저장합니다. \n", start, end, idx);
		result[i]=Sort(arr3, idx, len);
	}
	printf("\n");
	return result;
}

int Sort(int arr3[], int idx, int len)
{
	int i, j, temp;

	for (i = 0; i < len-1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr3[j] > arr3[j + 1])
			{
				temp = arr3[j];
				arr3[j] = arr3[j + 1];
				arr3[j + 1] = temp;
			}
		}
	}
	return arr3[idx-1];
}
