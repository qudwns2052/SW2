#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "List.h"

int main(void)
{
	ListNode * head1 = MakeNode();
	ListNode * head2 = MakeNode();
	ListNode * sum = MakeNode();

	int num1, num2;

	printf("ù��° ���׽��� �Է��ϼ���: ex) ����:5 ���:3�̸� -> 5 3\n\n");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &num1, &num2);
		InsertLast(head1, num1, num2);
	}

	printf("�ι�° ���׽��� �Է��ϼ���: ex) 3 5\n\n");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &num1, &num2);
		InsertLast(head2, num1, num2);
	}

	printf("\n����Ʈ1\n----------------------------\n");
	PrintList(head1);
	printf("----------------------------\n");
	printf("\n����Ʈ2\n----------------------------\n");
	PrintList(head2);
	printf("----------------------------\n");
	ListNode * temp1 = head1->next;
	ListNode * temp2 = head2->next;

	while (temp1 != NULL && temp2 != NULL)
	{

		if (temp1->value1 > temp2->value1)
		{
			InsertLast(sum, temp1->value1, temp1->value2);
			temp1 = temp1->next;
		}
		else if (temp1->value1 < temp2->value1)
		{
			InsertLast(sum, temp2->value1, temp2->value2);
			temp2 = temp2->next;
		}
		else
		{
			InsertLast(sum, temp1->value1, temp1->value2 + temp2->value2);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	if(temp1 == NULL && temp2 != NULL)
	{
		while (temp2 != NULL)
		{
			InsertLast(sum, temp2->value1, temp2->value2);
			temp2 = temp2->next;
		}
	}

	else if (temp1 != NULL && temp2 == NULL)
	{
		while (temp1 != NULL)
		{
			InsertLast(sum, temp1->value1, temp1->value2);
			temp1 = temp1->next;
		}
	}

	printf("\n���\n----------------------------\n");
	PrintList(sum);
	printf("----------------------------\n");


	DeleteAll(head1);
	DeleteAll(head2);
	DeleteAll(sum);

	system("pause");
	return 0;
}