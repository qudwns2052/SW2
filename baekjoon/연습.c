#include<stdio.h>
#include<string.h>

int top_index = -1;
int main() {
	int howmany;
	scanf("%d", &howmany);
	char command[10];
	int arr[100];
	int x;

	for (int i = 0; i < howmany; i++) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) 
		{
			top_index++;
			scanf("%d", &x);
			arr[top_index] = x;
		}
		else if (strcmp(command, "pop") == 0) 
		{
			if (top_index == -1)
				printf("%d\n", -1);
			else 
			{
				printf("%d\n", arr[top_index]);
				top_index--;
			}
		}
		else if (strcmp(command, "size") == 0)
			printf("%d\n", top_index + 1);
		else if (strcmp(command, "empty") == 0) 
		{
			if (top_index == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(command, "top") == 0)
			if (top_index == -1)
				printf("-1\n");
			else
				printf("%d\n", arr[top_index]);
	}

	return 0;
}