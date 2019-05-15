#define element char*

typedef struct _Node
{
	char value[20];
	struct _Node * next;
	struct _Node * prev;

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