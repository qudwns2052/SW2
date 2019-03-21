#include <stdio.h>
#include <windows.h>

#define LEN 10


int main()
{
	int arr[20];
	int result[20] = { 0 };  
	int temp[50] = { 0 };
	int mresult[50] = { 0 };
	int tvalue1, tvalue2;
	int i, j;
	int idx1, idx2;
	int fidx, sidx, cidx, ridx;
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

	fidx = 0;
	cidx = 0;


	for (i = 0; i < 5; i++)
	{ 
		sidx = 0;
		
		idx1 = (fidx * 2) + 1;

		for (j = 0; j < 5; j++)
		{
			idx2 = (sidx * 2) + 1;
			cnt = (cidx * 2) + 1;
		
			temp[cnt - 1] = arr[idx1 - 1] * arr[LEN + idx2 - 1];
			temp[cnt] = arr[idx1] + arr[LEN + idx2];
			sidx++;
			cidx++;
			
		}
		fidx++;

	}

	cidx = 0;
	
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 24 - i; j++)
		{
			if (temp[(j*2)+1] < temp[(j * 2) + 3])
			{
				tvalue1 = temp[(j * 2)];
				tvalue2 = temp[(j * 2) + 1];

				temp[(j * 2)] = temp[(j * 2) + 2];
				temp[(j * 2) + 1] = temp[(j * 2) + 3];

				temp[(j * 2) + 2] = tvalue1;
				temp[(j * 2) + 3] = tvalue2;

			}
		}
	}

	cidx = 0;
	ridx = 0;

	for (i = 0; i < 24; i++)
	{
		cnt = (cidx * 2) + 1;
		if (temp[cnt] > temp[cnt + 2])
		{
			mresult[ridx] = temp[cnt - 1];
			mresult[ridx + 1] = temp[cnt];
		}
		else if (temp[cnt] == temp[cnt + 2])
		{
			temp[cnt + 1] = temp[cnt + 1] + temp[cnt - 1];
		
		}
		ridx = ridx + 2;
		cidx++;
	}

	mresult[ridx] = temp[cnt - 1];
	mresult[ridx + 1] = temp[cnt];


	for (i = 0; i < 10; i++)
	{
		if (result[(i * 2)] != 0)
		{
			printf("덧셈의결과 ----> 계수:%d 차수:%d   ", result[(i * 2)], result[(i * 2) + 1]);
			printf("\n");
		}

		
	}

	printf("\n");

	for (i = 0; i < 25; i++)
	{
		if (mresult[(i * 2)] != 0)
		{
			printf("곱셈의결과 ----> 계수:%d 차수:%d   ", mresult[(i * 2)], mresult[(i * 2) + 1]);
			printf("\n");
		}


	}

	system("pause");
	return 0;
}