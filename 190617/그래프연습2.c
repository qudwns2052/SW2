#include <stdio.h>
#include <windows.h>

#define SIZE 10


typedef struct GraphNode
{
	int vertex;
	struct GraphNode * link;
}GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode * adj_list[SIZE];
}GraphType;

void GraphInit(GraphType * g)
{
	g->n = 0;
	for (int i = 0; i < SIZE; i++)
		g->adj_list[i] = NULL;
}

void InsertVertex(GraphType * g, int v)
{
	if (g->n + 1 > SIZE || v + 1 > SIZE)
	{
		printf("¿¡·¯\n");
		return;
	}

	g->n++;
}

void InsertEdge(GraphType * g, int u, int v)
{
	GraphNode * node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

}

int visited[SIZE];

void DFS(GraphType * g, int v)
{
	GraphNode * temp = g->adj_list[v];
	visited[v] = 1;
	printf("%d ", v);

	while (temp != NULL)
	{
		if (visited[temp->vertex] == 0)
			DFS(g, temp->vertex);
		temp = temp->link;
	}
}