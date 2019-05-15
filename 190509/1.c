#include <stdio.h>
#include "List.h"
#include <time.h>
#include <stdlib.h>


int main(void)
{
	srand((unsigned)time(NULL));

	ListNode * dummy1 = MakeNode();
	
	int i, j;
	int num;

	for (i = 0; i < 50; i++)
	{
		num = (rand() % 105) - 5;


		if (num < 0)
		{
			for (j = 0; j < num; j++)
			{
				Delete(dummy1);
			}
		}
		else
		{
			InsertFirst(dummy1, num);
		}
		
	}
	PrintList(dummy1);

	


	free(dummy1);

	scanf("%d", &num);

	return 0;

}