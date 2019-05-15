//#include <stdio.h>
//int main(void)
//{
//	int *p;
//	int var = 10;
//	p = &var;
//
//	printf("Value of variablee var is: %d\n", var);
//	printf("Value of variable var is: %d\n", *p);
//	printf("Address of variable var is: %p\n", &var);
//	printf("Address of variable var is: %p\n", p);
//	printf("Address of pointer p is: %p", &p);
//
//	return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//	int var = 10;
//	int *p;
//	p = &var;
//
//	printf("Address of var is: %p\n", &var);
//	printf("Address of var is: %p\n", p);
//	printf("Value of var is: %d\n", var);
//	printf("Value of var is: %d\n", *p);
//	printf("Value of var is: %d\n", *(&var));
//	printf("Value of pointer p is: %p\n", p);
//	printf("Address of pointer p is: %p\n", &p);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int *ptr;
//	int x;
//
//	ptr = &x;
//
//	x = 0;
//	printf("x = %d\n", x);
//	printf("*ptr = %d\n", *ptr);
//	x = 5;
//	printf("x = %d\n", x);
//	printf("*ptr = %d\n", *ptr);
//	x = 6;
//	printf("x = %d\n", x);
//	printf("*ptr = %d\n", *ptr);
//	
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int x = 10;
//	int y = 20;
//	int *ptr1 = &x;
//	int *ptr2 = &y;
//
//	printf("x + y = %d\n", *ptr1 + *ptr2);
//
//	return 0;
//}


//#include <stdio.h>
//
//int sum(int *ptr1, int *ptr2)
//{
//	int temp;
//
//	temp = *ptr1 + *ptr2;
//
//	return temp;
//}
//
//int main(void)
//{
//	int x = 10;
//	int y = 40;
//
//	int z = sum(&x, &y);
//
//	printf("x + y = %d\n", z);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Big(int *ptr1, int *ptr2)
//{
//	if (*ptr1 > *ptr2)
//		return *ptr1;
//	else
//		return *ptr2;
//}
//
//int main(void)
//{
//	int x = 5;
//	int y = 10;
//	int z = Big(&x, &y);
//
//	printf("x=%d, y=%d, Big=%d\n", x, y, z);
//
//	return 0;
//}