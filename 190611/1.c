#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 10

int Queue[MAX_VERTEX];
int Stack[MAX_VERTEX];
int top = -1;
int front = 0;
int rear = 0;

int visited[MAX_VERTEX];

void Push(int v)
{
	Stack[++top] = v;
}

int Pop(void)
{
	return Stack[top--];
}

int Is_emptyS(void)
{
	return (top == -1);
}

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
	return (front == rear);
}


typedef struct GraphNode
{
	int vertex;
	struct GraphNode * link;

}GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode * adj_list[MAX_VERTEX];

}GraphType;

void GraphInit(GraphType * g)
{
	for (int i = 0; i < MAX_VERTEX; i++)
		g->adj_list[i] = NULL;
}

void InsertEdge(GraphType * g, int u, int v)
{
	GraphNode * node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}


void DFS(GraphType * g, int v)
{
	GraphNode * temp = NULL;
	temp = g->adj_list[v];

	visited[v] = 1;
	printf("%d ", v);
	
	while (temp != NULL)
	{
		if (visited[temp->vertex] == 0)
			DFS(g, temp->vertex);
		else
			temp = temp->link;
	}

}

void DFS_Stack(GraphType * g, int v)
{
	visited[v] = 1;
	Push(v);

	GraphNode * temp = NULL;

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

			temp = temp->link;
		}
	}

}
void BFS(GraphType * g, int v)
{
	visited[v] = 1;
	InsertQ(v);


	GraphNode * temp = NULL;

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

			temp = temp->link;
		}

	}
}


void InitVisit(void)
{
	for (int i = 0; i < MAX_VERTEX; i++)
		visited[i] = 0;
}

int main(void)
{
	GraphType * g = (GraphType*)malloc(sizeof(GraphType));

	GraphInit(g);
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

	InitVisit();
	DFS(g, 0);
	printf("\n");

	InitVisit();
	DFS_Stack(g, 0);
	printf("\n");

	InitVisit();
	BFS(g, 0);
	printf("\n");

	system("pause");
	return 0;
}