#include <stdio.h>

#define SIZE 1000

int Queue[SIZE];
int index = -1;

void Add(int data)
{
	Queue[++index] = data;
	
}

int Delete(int N, int K)
{
	int temp;
	int num_cnt = 0;

	while (1)
	{
		index = (index + 1) % N;
		
		while (num_cnt < K-1)
		{
			if (Queue[index] != -1)
			{
				num_cnt++;
			}
			index = (index + 1) % N;
		}
		if (Queue[index] != -1)
		{
			temp = Queue[index];
			Queue[index] = -1;
			return temp;
		}
		
	}

}

int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		Add(i + 1);


	printf("<");
	for (int i = 0; i < N; i++)
	{
		printf("%d", Delete(N, K));
		if (i != N - 1)
			printf(", ");
		else
			printf(">");
	}


	return 0;
}