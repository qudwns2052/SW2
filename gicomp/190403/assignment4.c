//#include <stdio.h>
//
//int main(void)
//{
//	int x.y;
//	printf("enter the value of x:");
//	scanf("%d, &x");
//	printf("enter the value of y:");
//	scanf("%d", &y);
//	if (x > y)
//		printf("x is greater than y\n");
//	if (x < y)
//		printf("x is less than y\n");
//	if (x == y)
//		printf("x is equal to y\n");
//	printf("End of Program");
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int number;
//	printf("Enter integer:");
//	scanf("%d", number);
//
//	if (number % 2 == 0)
//		printf("even number\n");
//	else
//		printf("odd number\n");
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch >= 'A' && ch <= 'Z')
//		printf("%c is uppercase\n", ch);
//	else if (ch >= 'a' && ch <= 'z')
//		printf("%c is lowercase\n", ch);
//	else if (ch >= '0' && ch <= '9')
//		printf("%c is figure\n", ch);
//	else
//		printf("%c is other character\n", ch);
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	char op;
//	int x, y, result;
//
//	printf("Enter (ex. 2+ 5)\n");
//	printf(">>");
//	scanf("%d %c %d", &x, &op, &y);
//
//	if (op == '+')
//		result = x + y;
//	else if (op == '-')
//		result = x - y;
//	else if (op == '*')
//		result = x * y;
//	else if (op == '%')
//		result = x % y;
//	else
//		printf("no operation\n");
//	printf("%d %c %d = %d\n", x, op, y, result);
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int x;
//	int num = 0;
//	scanf("%d", &x);
//
//	switch (x)
//	{
//	case -1:
//		num--;
//		break;
//	case 1:
//		num++;
//		break;
//	default:
//		num = 0;
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	char ch;
//	int x = 0;
//	int y = 0;
//
//	scanf("%c", &ch);
//
//	if (ch == 'X')
//		x++;
//	else if (ch == 'Y')
//		y++;
//	else
//		x = y = 0;
//
//	return 0;
//}