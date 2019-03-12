#include <stdio.h>

#define LEN	10

int main(void)
{
	int arr[LEN];
	int i, j, temp;
	int min, max, mid, num;
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
		printf("찾으시는 값이 없습니다\n");
	else
		printf("찾으시는 값은 %d번째에 있는 %d 입니다\n", ref + 1, arr[ref]);
	

	system("pause");
	return 0;
}