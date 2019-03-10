#include <stdio.h>

int heap[100000] = { 0 }, pos = 0;

void Push(int num)
{
	int curpos = pos;
	heap[curpos] = num;

	int parentpos = (curpos - 1) / 2;
	while (curpos > 0 && heap[parentpos] > heap[curpos])
	{
		int temp = heap[curpos];
		heap[curpos] = heap[parentpos];
		heap[parentpos] = temp;
		curpos = parentpos;
		parentpos = (curpos - 1) / 2;
	}
	pos++;

}

int Pop(void)
{
	if (pos == 0)
		return 0;

	int result = heap[0];

	pos--;
	heap[0] = heap[pos];

	int parentpos = 0;

	while (1)
	{
		int leftpos = parentpos * 2 + 1;
		int rightpos = leftpos + 1;
		if (leftpos >= pos)
			break;
		int temp = heap[parentpos];

		if ((rightpos >= pos || heap[leftpos] <= heap[rightpos]) && heap[leftpos] < heap[parentpos])
		{
			heap[parentpos] = heap[leftpos];
			heap[leftpos] = temp;
			parentpos = leftpos;
		}
		else if (heap[rightpos] < heap[leftpos] && heap[rightpos] < heap[parentpos])
		{
			heap[parentpos] = heap[rightpos];
			heap[rightpos] = temp;
			parentpos = rightpos;
		}
		else
			break;

	}

	return result;
}

int main()
{
	int i, data, num;


	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &data);

		if (data == 0)
			printf("%d\n", Pop());
		else
			Push(data);
	}


	system("pause");

	return 0;
}