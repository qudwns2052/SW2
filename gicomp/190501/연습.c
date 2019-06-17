#include <stdio.h>
#include <windows.h>

int main(void)
{
	int a = 10;

	printf("%x %p", &a, &a);

	system("pause");
}