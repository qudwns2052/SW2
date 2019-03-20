//#include <stdio.h>
//
//int main()
//{
//	int n1 = +2147483647;
//	int n2 = -2147483647;
//	printf("before overflow: %d\n", n1);
//	n1 = n1 + 100;
//	printf("after overflow: %d\n", n1);
//
//	printf("before underflow: %d\n", n2);
//	n2 = n2 - 100;
//	printf("after overflow: %d\n", n2);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char code1 = 'B';
//	char code2 = 66;
//	char code3 = 'C';
//	char code4 = 67;
//	char code5 = 'D';
//	char code6 = 68;
//	printf("code1 = %c\n", code1);
//	printf("code2 = %c\n", code2);
//	printf("code3 = %c\n", code3);
//	printf("code4 = %c\n", code4);
//	printf("code5 = %c\n", code5);
//	printf("code6 = %c\n", code6);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char code = 'A';
//	printf("%d %d %d \n", code, code + 1, code + 2);
//	printf("%c %c %c \n", code, code + 1, code + 2)";
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("char: %d %d\n", sizeof(char), sizeof(unsigned char));
//	printf("short: %d %d\n", sizeof(short), sizeof(unsigned short));
//	printf("int: %d %d\n", sizeof(int), sizeof(200));
//	printf("long: %d %d\n", sizeof(long), sizeof(300L));
//	printf("long long: %d %d\n", sizeof(long long), sizeof(900LL));
//	printf("float: %d %d\n", sizeof(float), sizeof(3.14F));
//	printf("double: %d %d\n", sizeof(float), sizeof(3.14));
//	
//	system("pause");
//	return 0;
//}