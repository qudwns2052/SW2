#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List2.h"

int main(void)
{
	ListNode * head = MakeNode();
	ListNode * temp;

	strcpy(head->value, "�밡��");
	InsertFirst(head, "�����ϴ� ���ε��� ����");
	InsertFirst(head, "�����͵��� ���� ��");
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
			printf("����\n");
			break;
		}

		printf("%s\n", temp->value);
	}


	return 0;
}