#include <stdio.h>
#include <windows.h>
#define LEN 6

void quick_sort(int arr[][2], int low, int high) {

	if (low >= high) return;

	int mid = (low + high) / 2;
	int pivot = arr[mid][0];
	int temp[2];

	temp[0] = arr[low][0];
	temp[1] = arr[low][1];
	
	arr[low][0] = arr[mid][0];
	arr[low][1] = arr[mid][1];

	arr[mid][0] = temp[0];
	arr[mid][1] = temp[1];


	int p = low + 1, q = high;

	while (1) {
		while (arr[p][0] <= pivot) { p++; }
		while (arr[q][0] > pivot) { q--; }

		if (p > q) break;

		temp[0] = arr[p][0];
		temp[1] = arr[p][1];

		arr[p][0] = arr[q][0];
		arr[p][1] = arr[q][1];

		arr[q][0] = temp[0];
		arr[q][1] = temp[1];
	}

	temp[0] = arr[low][0];
	temp[1] = arr[low][1];

	arr[low][0] = arr[q][0];
	arr[low][1] = arr[q][1];

	arr[q][0] = temp[0];
	arr[q][1] = temp[1];

	quick_sort(arr, low, q - 1);
	quick_sort(arr, q + 1, high);

}


int main(void)
{
	int arr1[LEN][3] = { 0 };
	int arr2[LEN][3] = { 0 };
	int temp[LEN][2] = { 0 };
	int i;


	for (i = 0; i < LEN; i++)
	{
		scanf("%d %d %d", &arr1[i][0], &arr1[i][1], &arr1[i][2]);
	}


	for (i = 0; i < LEN; i++)
	{
		temp[i][0] = arr1[i][1];
		temp[i][1] = i;
	}

	
	quick_sort(temp, 0, LEN-1);

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