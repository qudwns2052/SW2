#include<stdio.h>
#include<stdlib.h>

int top = -1;

void push(int **p) {
	top++;
	int tmp;
	printf("수를 입력하세요.");
	scanf("%d", &tmp);
	if (top)
		(int*)realloc(*p, sizeof(int)*(top + 1));
	else
		*p = (int*)malloc(sizeof(int));
	(*p)[top] = tmp;
	return;
}

void pop(int **p) {

	printf("%d\n", (*p)[top--]);
	(int*)realloc(*p, sizeof(int)*(top + 1));
	return;
}

int main() {

	int *p;

	int sel;
	while (1) {

		printf("1. push 2. pop\n:");
		scanf("%d", &sel);
		if (sel == 1)
			push(&p);
		else if (sel == 2) {
			if (top == -1) {
				printf("스택이 비어있습니다.\n");
				continue;
			}
			else
				pop(&p);
		}
	}

	return 0;
}