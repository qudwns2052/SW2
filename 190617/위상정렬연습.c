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
		printf("에러\n");
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

int Stack[SIZE];
int top = -1;

void Push(int data)
{
	if (top + 1 >= SIZE)
	{
		printf("꽉 찼습니다.\n");
		return;
	}
	Stack[++top] = data;
}

int Pop(void)
{
	if (top == -1)
	{
		printf("비었습니다.\n");
		return -1;
	}
	return Stack[top--];
}

void TopoSort(GraphType * g)
{
	GraphNode * node;
	int v;

	int * in_degree = (int*)malloc(sizeof(int)*g->n);

	for (int i = 0; i < g->n; i++)
		in_degree[i] = 0;

	for (int i = 0; i < g->n; i++)
	{
		node = g->adj_list[i];
		while (node != NULL)
		{
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	for (int i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)
			Push(i);
	}
	
	while (top != -1)
	{
		v = Pop();
		printf("%d ", v);
		node = g->adj_list[v];

		while (node != NULL)
		{
			in_degree[node->vertex]--;
			if (in_degree[node->vertex] == 0)
				Push(node->vertex);
			node = node->link;
		}


	}

	free(in_degree);

}

int main(void)
{
	GraphType * g = (GraphType*)malloc(sizeof(GraphType));
	GraphInit(g);

	for (int i = 0; i < 6; i++)
		InsertVertex(g, i);

	InsertEdge(g, 0, 2);
	InsertEdge(g, 0, 3);
	
	InsertEdge(g, 1, 3);
	InsertEdge(g, 1, 4);
	
	InsertEdge(g, 2, 3);
	InsertEdge(g, 2, 5);
	
	InsertEdge(g, 3, 5);
	
	InsertEdge(g, 4, 5);


	TopoSort(g);
	printf("\n");


	system("pause");
	return 0;
}