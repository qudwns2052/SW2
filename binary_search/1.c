#include <stdio.h>

#define LEN	10

int main(void)
{
	int arr[LEN];
	int i, j, temp;
	int min, max, mid, num;
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

	while (min <= max)
	{
		mid = (max + min) / 2;

		if (num == arr[mid])
		{
			ref = mid;
			break;
		}
		else if (num < arr[mid])
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}

	if (ref == -1)
		printf("ã���ô� ���� �����ϴ�\n");
	else
		printf("ã���ô� ���� %d��°�� �ִ� %d �Դϴ�\n", ref + 1, arr[ref]);
	

	system("pause");
	return 0;
}