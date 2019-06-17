#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_VERTEX 10
#define MAX_STACK_SIZE 1000

typedef struct node
{
	int vertex;
	struct node * link;
}GraphNode;

typedef struct GraphType{
	int n;
	GraphNode * adj_list[MAX_VERTEX];
}GraphType;

typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
}StackType;

void InitGraph(GraphType * g)
{
	for (int i = 0; i < MAX_VERTEX; i++)
		g->adj_list[i] = NULL;
	
	g->n = 0;
}

void InsertVertex(GraphType * g, int v)
{
	if ((g->n) + 1 > MAX_VERTEX)
	{
		printf("정점 추가 실패\n");
		exit(1);
	}

	g->n++;
}

void InsertEdge(GraphType * g, int u, int v)
{
	GraphNode * node = (GraphNode*)malloc(sizeof(GraphNode));

	if (node == NULL)
	{
		printf("메모리 할당 에러\n");
		exit(1);
	}

	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void Init(StackType * s)
{
	s->top = -1;
}

int Is_empty(StackType * s)
{
	return (s->top == -1);
}

int Is_full(StackType * s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void Push(StackType * s, int item)
{
	if (Is_full(s))
	{
		printf("스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

int Pop(StackType * s)
{
	if (Is_empty(s))
	{
		printf("스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

int TopoSort(GraphType * g)
{
	int i, u, v;

	StackType s;
	GraphNode * node = NULL;

	int * in_degree = (int*)malloc(sizeof(int)*g->n);

	for (i = 0; i < g->n; i++)
		in_degree[i] = 0;

	for (i = 0; i < g->n; i++)
	{
		node = g->adj_list[i];
		while (node != NULL)
		{
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	Init(&s);

	for (i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)
			Push(&s, i);
	}

	printf("위상 순서 : ");
	while (!Is_empty(&s))
	{
		v = Pop(&s);
		printf("%d -> ", v);
		node = g->adj_list[v];

		while (node != NULL)
		{
			u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0)
				Push(&s, u);
			node = node->link;
		}
	}

	free(in_degree);
	return 0;
}

int main(void)
{
	GraphType graph;
	int i;

	InitGraph(&graph);

	for (i = 0; i < 10; i++)
		InsertVertex(&graph, i);

	InsertEdge(&graph, 2, 0);
	InsertEdge(&graph, 3, 1);
	InsertEdge(&graph, 4, 1);
	InsertEdge(&graph, 4, 2);
	InsertEdge(&graph, 6, 2);
	InsertEdge(&graph, 7, 3);
	InsertEdge(&graph, 7, 4);
	InsertEdge(&graph, 6, 5);
	InsertEdge(&graph, 8, 5);
	InsertEdge(&graph, 7, 6);
	InsertEdge(&graph, 9, 6);





	TopoSort(&graph);


	system("pause");
	return 0;
}