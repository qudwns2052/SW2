#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	long a;
	srand((unsigned)time(NULL));
	a = (((long)rand() << 15) | rand()) % 5000000;
	
	printf("%d", a);

	system("pause");
	return 0;
}