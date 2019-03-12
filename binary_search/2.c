#include <stdio.h>
#include <windows.h>

#define LEN	10

int Binary_search(int arr[], int min, int max, int num);

int main(void)
{
	int arr[LEN];
	int i, j, temp;
	int min, max, num;
	int ref = -1;

	printf("숫자 10개를 입력해주세요 (입력하시면 자동으로 정렬이 됩니다(오름차순))\n");
	for (i = 0; i < LEN; i++)
	{
		scanf("%d", &arr[i]);
	}



	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < LEN - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("찾으시는 숫자 1개를 입력해주세요\n");
	scanf("%d", &num);


	min = 0;
	max = LEN - 1;

	ref = Binary_search(arr, min, max, num);
	

	if (ref == -1)
		printf("찾으시는 값이 없습니다\n");
	else
		printf("찾으시는 값은 %d번째에 있는 %d 입니다\n", ref + 1, arr[ref]);


	system("pause");
	return 0;
}

int Binary_search(int arr[], int min, int max, int num)
{
	int mid = (max + min) / 2;

	if (min > max)
		return -1;
	else if (num == arr[mid])
		return mid;
	else if (num < arr[mid])
		return Binary_search(arr, min, mid - 1, num);
	else
		return Binary_search(arr, mid + 1, max, num);

}