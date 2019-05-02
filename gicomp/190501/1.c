#include <stdio.h>
#include <windows.h>

int main(void)
{
	int (*list)[5];

	list = malloc(sizeof(int) * 3 * 5);

	memset(list, 0, sizeof(list));

	list[0][0] = 5;
	list[1][1] = 7;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d \n", list[i][j]);
	}

	system("pause");
	return 0;
}