#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListNode * MakeNode(void)
{
	ListNode * newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->value = 0;

	return newnode;

}

ListNode * InsertFirst(ListNode * head, element value)
{
	ListNode * newnode = MakeNode();


	if (head->next == NULL)
	{
		newnode->next = head->next;
		head->next = newnode;
		newnode->value = value;
		
		return newnode;
	}
	
	ListNode * front = SearchFront(head, value);

	newnode->next = front->next;
	front->next = newnode;
	newnode->value = value;



	return newnode;
}

ListNode * SearchFront(ListNode * head, element value)
{
	ListNode * temp = head->next;
	ListNode * front = head;
	


	while (temp != NULL)
	{
		if (temp->value < value)
		{
			break;
		}
		
		temp = temp->next;
		front = front->next;
		
	}

	return front;

}

ListNode * InsertLast(ListNode * head, element value)
{
	ListNode * newnode = MakeNode();

	ListNode * temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;

	}

	newnode->next = temp->next;
	temp->next = newnode;
	newnode->value = value;

	return newnode;
}



int Delete(ListNode * prev)
{
	if (prev->next == NULL)
		return -1;

	ListNode * temp = prev->next;
	
	prev->next = prev->next->next;

	int value = temp->value;

	free(temp);

	return value;
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

int GetIndex(ListNode * head, element value)
{
	int cnt = 0;

	ListNode * temp = head->next;

	while ((temp->value != value) && temp != NULL)
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
		printf("index %d -> %d\n", GetIndex(head, temp->value), temp->value);
		temp = temp->next;
	}
}

ListNode * SearchList(ListNode * head, element value)
{
	ListNode * temp = head->next;

	while (temp->value != value && temp != NULL)
	{
		temp = temp->next;
	}


	return temp;

}

