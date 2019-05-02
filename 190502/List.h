#define element int

typedef struct _Node
{
	element value1;
	element value2;
	struct _Node * next;

}ListNode;


ListNode * MakeNode(void);

ListNode * InsertFirst(ListNode * prev, element value1, element value2);

ListNode * InsertLast(ListNode * prev, element value1, element value2);


void Delete(ListNode * prev);

void DeleteAll(ListNode * head);

int GetIndex(ListNode * head, element value1, element value2);

void PrintList(ListNode * head);

ListNode * SearchList(ListNode * head, element value1);