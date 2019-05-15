#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List2.h"

int main(void)
{
	ListNode * head = MakeNode();
	ListNode * temp;

	strcpy(head->value, "대가뤼");
	InsertFirst(head, "주저하는 연인들을 위해");
	InsertFirst(head, "작은것들을 위한 시");
	InsertFirst(head, "Fancy");

	char ch;
	temp = head;

	while (1)
	{
		scanf("%c", &ch);
		getchar();

		switch (ch)
		{
		case '<':
			temp = temp->prev;
			break;
		case '>':
			temp = temp->next;
			
		}
		if (ch == 'q')
		{
			printf("종료\n");
			break;
		}

		printf("%s\n", temp->value);
	}


	return 0;
}