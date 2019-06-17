//#include <stdio.h>
//
//int main(void)
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int *pArr = arr;
//	int i;
//
//	for (i = 0; i < 5; i++)
//		printf("%d", pArr[i]);
//	printf("\n");
//
//	for (i = 0; i < 5; i++)
//		printf("%d", *(pArr + i));
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//#define ROWS 3
//#define COLS 3
//
//void inputMatrix(int matrix[][COLS], int rows, int cols);
//void printMatrix(int matrix[][COLS], int rows, int cols);
//
//int main(void)
//{
//	int matrix[ROWS][COLS];
//	int i, j;
//
//	printf("Enter elements in %dx%d matrix\n", ROWS, COLS);
//	inputMatrix(matrix, ROWS, COLS);
//
//	printf("Elements of %dx%d matrix\n", ROWS, COLS);
//	printMatrix(matrix, ROWS, COLS);
//
//	return 0;
//}
//
//
//void inputMatrix(int matrix[][COLS], int rows, int cols)
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			scanf("%d", (*(matrix + i) + j));
//		}
//	}
//}
//
//void printMatrix(int (*matrix)[COLS], int rows, int cols)
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			printf("%d", *(*(matrix + i) + j));
//		}
//		printf("\n");
//	}
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr[5] = { 2,3,4,5,6 };
//	int result = 0;
//
//	for (int i = 0; i < 5; i++)
//	{
//		result += *(arr + i);
//	}
//
//	printf("The sum of array is : %d\n", result);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr[] = { 1,2,3,4,5 };
//
//	printf("First element: %d\n", *(arr + 0));
//	printf("Second element: %d\n", *(arr + 1));
//	printf("Third element: %d\n", *(arr + 2));
//	printf("Fourth element: %d\n", *(arr + 3));
//	printf("Fifth element: %d\n", *(arr + 4));
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int *p;
//	int val[7] = { 11,22,33,44,55,66,77 };
//
//	p = &val;
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("value:%d\taddress:%p\n", *(val + i), val + i);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	double balance[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
//	double *p;
//	int i;
//
//	p = balance;
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("value:%lf\n", *(p+i));
//	}
//
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("address:%p\n", (p+i));
//		
//	}
//
//	return 0;
//}