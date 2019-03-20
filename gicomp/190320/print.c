#include <stdio.h>
extern int num1;
int numprintf(void)
{
	num1 = 5;
	printf("num: %d\n", num1);
}