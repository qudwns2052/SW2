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

	printf("���� 10���� �Է����ּ��� (�Է��Ͻø� �ڵ����� ������ �˴ϴ�(��������))\n");
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

	printf("ã���ô� ���� 1���� �Է����ּ���\n");
	scanf("%d", &num);


	min = 0;
	max = LEN - 1;

	ref = Binary_search(arr, min, max, num);
	

	if (ref == -1)
		printf("ã���ô� ���� �����ϴ�\n");
	else
		printf("ã���ô� ���� %d��°�� �ִ� %d �Դϴ�\n", ref + 1, arr[ref]);


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