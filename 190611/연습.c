#include <stdio.h>
#include <windows.h>

#define MAX_VERTEX 10

typedef struct Node
{
	int vertex;
	struct Node * link;
}Node;

int visited[MAX_VERTEX];

typedef struct GraphType
{
	int n;
	Node * adj_list[MAX_VERTEX];
}GraphType;


void InitGraph(GraphType * g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++)
		g->adj_list[i] = NULL;
}

void InsertNode(GraphType * g, int v)
{
	if (g->n + 1 >= MAX_VERTEX)
	{
		printf("²Ë Âü\n");
		return;
	}

	g->n++;
}

void InsertEdge(GraphType * g, int u, int v)
{
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->vertex = v;
	
	temp->link = g->adj_list[u];
	g->adj_list[u] = temp;
}

void InitVisited(void)
{
	for (int i = 0; i < MAX_VERTEX; i++)
		visited[i] = 0;
}

void DFS(GraphType * g, int v)
{
	visited[v] = 1;
	printf("%d ", v);

	Node * temp = g->adj_list[v];

	while (temp != NULL)
	{
		if (visited[temp->vertex] == 0)
		{
			DFS(g, temp->vertex);
		}
		temp = temp->link;
	}
}

int Queue[MAX_VERTEX];
int rear = 0;
int front = 0;

void InsertQ(int v)
{
	Queue[rear++] = v;
}

int DeleteQ(void)
{
	return Queue[front++];
}

int Is_emptyQ(void)
{
	return (rear == front);
}

void BFS(GraphType * g, int v)
{
	InsertQ(v);
	visited[v] = 1;
	Node * temp = NULL;

	while (!Is_emptyQ())
	{
		v = DeleteQ();
		printf("%d ", v);
		temp = g->adj_list[v];
		while (temp != NULL)
		{
			if (visited[temp->vertex] == 0)
			{
				InsertQ(temp->vertex);
				visited[temp->vertex] = 1;
			}
			else
				temp = temp->link;
		}
	}

}

int Stack[MAX_VERTEX];
int top = -1;

void Push(int v)
{
	Stack[++top] = v;
}

int Pop (void)
{
	return Stack[top--];
}

int Is_emptyS(void)
{
	return (top == -1);
}

void DFS_Stack(GraphType * g, int v)
{
	Push(v);
	visited[v] = 1;
	Node * temp = NULL;

	while (!Is_emptyS())
	{
		v = Pop();
		printf("%d ", v);
		temp = g->adj_list[v];
		while (temp != NULL)
		{
			if (visited[temp->vertex] == 0)
			{
				Push(temp->vertex);
				visited[temp->vertex] = 1;
			}
			else
				temp = temp->link;
		}
	}
}

int main(void)
{
	GraphType * g = (GraphType*)malloc(sizeof(GraphType));

	InitGraph(g);
	for(int i=0; i<5; i++)
		InsertNode(g, i);

	InsertEdge(g, 0, 5);
	InsertEdge(g, 0, 1);
	InsertEdge(g, 1, 0);
	InsertEdge(g, 1, 2);
	InsertEdge(g, 2, 1);
	InsertEdge(g, 2, 5);
	InsertEdge(g, 2, 3);
	InsertEdge(g, 3, 2);
	InsertEdge(g, 3, 4);
	InsertEdge(g, 4, 3);
	InsertEdge(g, 5, 0);
	InsertEdge(g, 5, 2);

	InitVisited();
	DFS(g, 0);
	printf("\n");

	InitVisited();
	BFS(g, 0);
	printf("\n");

	InitVisited();
	DFS_Stack(g, 0);
	printf("\n");


	system("pause");
	return 0;
}