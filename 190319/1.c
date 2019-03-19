#include <stdio.h>
#include <windows.h>

#define LEN 10

int main()
{
	int arr[20];
	int result[20] = { 0 };
	int i, j;
	int idx1, idx2;
	int fidx, sidx, cidx;
	int cnt;


	printf("첫번째 다항식을 입력해주세요 -> ");

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);

	}

	printf("두번째 다항식을 입력해주세요 -> ");
	for (i = 0; i < 10; i++)
	{

		scanf("%d", &arr[LEN + i]);

	}

	printf("\n\n두 다항식을 더합니다\n\n");

	fidx = 0;
	sidx = 0;
	cidx = 0;

	for (i = 0; i < 10; i++)
	{
		idx1 = (fidx * 2) + 1;
		idx2 = (sidx * 2) + 1;
		cnt = (cidx * 2) + 1;

		if (idx1 > 10)
		{
			if (idx2 > 10)
				break;
			else
			{
				for (j = LEN + idx2; j < 20; j = j + 2)
				{
					result[cnt - 1] = arr[j - 1];
					result[cnt] = arr[j];
					cnt = cnt + 2;
				}
				break;
			}
		}
		else if (idx2 > 10)
		{
			for (j = idx1; j < 10; j = j + 2)
			{
				result[cnt - 1] = arr[j - 1];
				result[cnt] = arr[j];
				cnt = cnt + 2;
			}
			break;
			
		}
		else if (arr[idx1] == arr[LEN + idx2])
		{
			result[cnt-1] = arr[idx1 - 1] + arr[LEN + idx2 - 1];
			result[cnt] = arr[idx1];
			fidx++;
			sidx++;
		}
		else if (arr[idx1] > arr[LEN + idx2])
		{
			result[cnt - 1] = arr[idx1 - 1];
			result[cnt] = arr[idx1];
			fidx++;
		}
		else if (arr[idx1] < arr[LEN + idx2])
		{
			result[cnt - 1] = arr[LEN + idx2 - 1];
			result[cnt] = arr[LEN + idx2];
			sidx++;
		}

		cidx++;
		
	}


	for (i = 0; i < 10; i++)
	{
		if (result[(i * 2)] == 0 && result[(i * 2) + 1] == 0)
		{
			continue;
		}
		else
			printf("계수:%d 차수:%d   ", result[(i * 2)], result[(i * 2) + 1]);
		
		printf("\n");
	}

	system("pause");
	return 0;
}