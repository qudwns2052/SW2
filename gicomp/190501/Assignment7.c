//#include <stdio.h>
//
//void SimpleFunc(void)
//{
//	static int num1 = 0;
//	int num2 = 0;
//	num1++; num2++;
//	printf("static: %d, local: %d\n", num1, num2);
//}
//
//int main(void)
//{
//	int i;
//	for (i = 0; i < 3; i++)
//		SimpleFunc();
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int num = 1;
//	if (num == 1)
//	{
//		int num = 7;
//		num += 10;
//		printf("if local variable num: %d\n", num);
//	}
//	printf("main local variable num: %d\n", num);
//
//	return 0;
//}

//#include <stdio.h>
//
//int Factorial(int n)
//{
//	int num = 1;
//
//	for (int i = 1; i <= n; i++)
//	{
//		num *= i;
//	}
//
//	return num;
//}
//
//int main(void)
//{
//	printf("1! = %d\n", Factorial(1));
//	printf("2! = %d\n", Factorial(2));
//	printf("3! = %d\n", Factorial(3));
//	printf("4! = %d\n", Factorial(4));
//	printf("9! = %d\n", Factorial(9));
//
//	return 0;
//}

//#include <stdio.h>
//
//int AddToTotal(int num)
//{
//	static int total = 0;
//
//	total += num;
//	return total;
//}
//
//int main(void)
//{
//	int num, i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("enter %d: ", i + 1);
//		scanf("%d", &num);
//		printf("total: %d\n", AddToTotal(num));
//	}
//
//	return 0;
//}