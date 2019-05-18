#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List2.h"

ListNode * MakeNode(void)
{
	ListNode * newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->left = NULL;
	newnode->right = NULL;


	return newnode;

}

ListNode * InsertFirst(ListNode * head, element value)
{
	ListNode * newnode = MakeNode();
	
	if (head->next == NULL)
	{
		newnode->prev = head;
		newnode->next = head;
		head->next = newnode;
		head->prev = newnode;
	}
	else
	{
		newnode->prev = head;
		newnode->next = head->next;
		head->next->prev = newnode;
		head->next = newnode;

	}
	
	strcpy(newnode->value, value);
	
	

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




ListNode * SearchList(ListNode * head, element value)
{
	ListNode * temp = head->next;

	while (temp->value != value && temp != NULL)
	{
		temp = temp->next;
	}


	return temp;

}

