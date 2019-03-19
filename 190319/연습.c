#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int qcount = 0;

typedef struct LinkedList {

	LinkedList* pre;
	int a;
	LinkedList* next;

}LinkedList;


void push(LinkedList* p, char command[]) {

	int j = 10, k = 0, n = 0, m = 1;
	for (; j--; j > 5) {

		if (command[j] == NULL)
			continue;
		n++;
		int l = n;
		while (l > 1) {
			m *= 10;
			l--;
		}
		k += (command[j] - '0')*m;

	}
	if (qcount) {
		p->next = (LinkedList*)malloc(sizeof(LinkedList));
		p->next->pre = p;
		p = p->next;
	}
	else
		p->pre = NULL;
	p->a = k;
	qcount += 1;

	return;
}

void pop(LinkedList* p) {

	if (qcount) {
		printf("%d", p->a);
		p->pre = NULL;
		free(p);
		qcount -= 1;
	}
	else printf("-1");

	return;
}

void size() {

	printf("%d", qcount);

	return;
}

void empty() {

	if (qcount)
		printf("1");
	else
		printf("0");

	return;
}

void top(LinkedList* p) {

	if (qcount)
		printf("%d", p->a);
	else
		printf("-1");
	return;
}


void gubyul(LinkedList* p, char command[]) {

	if (strncmp(command, "push", 4) == 0)
		push(p, command);
	else switch (command[0]) {

	case 'p':
		pop(p);
		break;

	case 's':
		size();
		break;

	case 'e':
		empty();
		break;

	case 't':
		top(p);

	}


	return;
}

int main() {

	int i;
	LinkedList p;
	char command[12];
	printf("명령의 수?:");
	scanf("%d", &i);
	for (; i--; i > 1) {

		printf("명령을 입력하세요");
		fflush(stdin);
		gets(command);
		printf("%d" strlen(command));
		gubyul(&p, command);

	}

	return 0;
}