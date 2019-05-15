#define element int

typedef struct _Node
{
	element value;
	struct _Node * next;

}ListNode;


ListNode * MakeNode(void);

ListNode * InsertFirst(ListNode * prev, element value);

ListNode * SearchFront(ListNode * head, element value);

ListNode * InsertLast(ListNode * prev, element value);


int Delete(ListNode * prev);

void DeleteAll(ListNode * head);

int GetIndex(ListNode * head, element value);

void PrintList(ListNode * head);

ListNode * SearchList(ListNode * head, element value);