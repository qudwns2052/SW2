//#include <stdio.h>
//
//int main(void)
//{
//	int count = 1;
//	while (count <= 4)
//	{
//		printf("%d ", count);
//		count++;
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int i = 1, j = 1;
//	while (i <= 4 || j <= 3)
//	{
//		printf("5d %d\n", i, j);
//		i++;
//		j++;
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int j = 0;
//	do
//	{
//		printf("Value of variable j is: %d\n", j);
//		j++;
//	} while (j <= 3);
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int a = 10;
//
//	do {
//		printf("value of a: %d\n", a);
//		a = a + 1;
//	} while (a < 20);
//
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int num, count, sum = 0;
//
//	printf("Enter a positive integer: ");
//	scanf("%d", &num);
//
//	for (count = 1; count <= num; ++count)
//	{
//		sum += count;
//	}
//
//	printf("Sum = %d", sum);
//
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int i;
//	int j;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d, %d\n", i, j);
//		}
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int i, j;
//	for (i = 1, j = 1; i < 3 || j < 5; i++, j++)
//	{
//		printf("%d, %d\n", i, j);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//int main(void)
//{
//	int answer = 41;
//	int guess;
//	int tries = 0;
//
//	do {
//		printf("guess the answer: ");
//		scanf("%d", &guess);
//		tries++;
//
//		if (guess > answer)
//			printf("the number is higher than answer\n");
//		if (guess < answer)
//			printf("the number is lower than answer\n");
//	} while (guess != answer);
//
//	printf("tries = %d\n", tries);
//	return 0;
//}