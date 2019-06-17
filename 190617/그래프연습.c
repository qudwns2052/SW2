#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int visited[SIZE];

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

void Graph_init(GraphType * g)
{
	g->n = 0;

	for (int i = 0; i < SIZE; i++)
		g->adj_list[i] = NULL;
}

void Insert_vertex(GraphType * g, int v)
{
	if (g->n + 1 > SIZE || v + 1 > SIZE)
	{
		printf("에러\n");
		return;
	}

	g->n++;
}

void Insert_edge(GraphType * g, int u, int v)
{
	GraphNode * node = (GraphNode*)malloc(sizeof(node));

	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void Visited_init(void)
{
	for (int i = 0; i < SIZE; i++)
		visited[i] = 0;
}

void PrintAdjlist(GraphType * g, int v)
{
	GraphNode * temp = g->adj_list[v];

	while (temp != NULL)
	{
		printf("%d ", temp->vertex);
		temp = temp->link;
	}
}

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

int Queue[SIZE];
int rear = 0;
int front = 0;

void InsertQ(int data)
{
	if (rear + 1 >= SIZE)
	{
		printf("꽉 찼습니다.\n");
		return;
	}

	Queue[rear++] = data;
}

int DeleteQ(void)
{
	if (rear == front)
	{
		printf("비어 있습니다.\n");
		return -1;
	}

	return Queue[front++];
}

void BFS(GraphType * g, int v)
{
	GraphNode * temp = NULL;
	visited[v] = 1;

	InsertQ(v);

	while (rear != front)
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

int main(void)
{
	GraphType * g = (GraphType*)malloc(sizeof(GraphType));

	Graph_init(g);

	for (int i = 0; i < 6; i++)
		Insert_vertex(g, i);

	Insert_edge(g, 0, 1);
	Insert_edge(g, 0, 5);
	Insert_edge(g, 1, 0);
	Insert_edge(g, 1, 2);
	Insert_edge(g, 2, 1);
	Insert_edge(g, 2, 5);
	Insert_edge(g, 2, 3);
	Insert_edge(g, 3, 2);
	Insert_edge(g, 3, 4);
	Insert_edge(g, 4, 3);
	Insert_edge(g, 5, 0);
	Insert_edge(g, 5, 2);

	Visited_init();
	DFS(g, 2);
	printf("\n");

	Visited_init();
	BFS(g, 2);
	printf("\n");


	for (int i = 0; i < 6; i++)
	{
		printf("%d의 인접리스트: ", i);
		PrintAdjlist(g, i);
		printf("\n");
	}

	system("pause");
	return 0;

}