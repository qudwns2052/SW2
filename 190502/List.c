#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListNode * MakeNode(void)
{
	ListNode * newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;

	return newnode;

}

ListNode * InsertFirst(ListNode * head, element value1, element value2)
{
	ListNode * newnode = MakeNode();

	newnode->next = head->next;
	head->next = newnode;
	newnode->value1 = value1;
	newnode->value2 = value2;

	return newnode;
}

ListNode * InsertLast(ListNode * head, element value1, element value2)
{
	ListNode * newnode = MakeNode();

	ListNode * temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;

	}

	newnode->next = temp->next;
	temp->next = newnode;
	newnode->value1 = value1;
	newnode->value2 = value2;

	return newnode;
}



void Delete(ListNode * prev)
{
	if (prev->next == NULL)
		return;

	ListNode * temp = prev->next;

	prev->next = prev->next->next;

	free(temp);
}

void DeleteAll(ListNode * head)
{
	ListNode * temp = head;
	ListNode * remove = temp;

	while (remove != NULL)
	{
		temp = temp->next;
		free(remove);
		remove = temp;
	}
}

int GetIndex(ListNode * head, element value1, element value2)
{
	int cnt = 0;

	ListNode * temp = head->next;

	while ((temp->value1 != value1 && temp->value2 != value2) && temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}

	return cnt;
}

void PrintList(ListNode * head)
{
	ListNode * temp = head->next;

	while (temp != NULL)
	{
		printf("index %d -> %d %d\n", GetIndex(head, temp->value1, temp->value2), temp->value1, temp->value2);
		temp = temp->next;
	}
}

ListNode * SearchList(ListNode * head, element value1)
{
	ListNode * temp = head->next;

	while (temp->value1 != value1 && temp != NULL)
	{
		temp = temp->next;
	}


	return temp;

}

