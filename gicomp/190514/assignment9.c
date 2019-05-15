//#include <stdio.h>
//#define SIZE 5
//
//int main(void)
//{
//	int score[SIZE];
//	score[0] = 70;
//	score[1] = 90;
//	score[2] = 80;
//	score[3] = 60;
//	score[4] = 50;
//
//	for (int i = 0; i < SIZE; i++)
//		printf("%d", score[i]);
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr[6];
//
//	for (int i = 0; i < 6; i++)
//	{
//		arr[i] = i;
//	}
//
//	int total = 0;
//	double average = 0;
//
//	for (int i = 0; i < 6; i++)
//	{
//		total += arr[i];
//	}
//	average = (double)total / 6;
//
//	printf("total:%d\naverage:%lf\n", total, average);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr1[3] = { 15, 10, 12 };
//	int arr2[3];
//
//	for (int i = 0; i < 3; i++)
//	{
//		arr2[i] = arr1[i];
//	}
//
//	printf("The elements stored in the first array are: ");
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	printf("The elements stored in the second array are: ");
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr[5] = { 45, 25, 21, 11, 5 };
//
//	int max = arr[0];
//	int min = arr[0];
//	for (int i = 0; i < 5; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//		if (min > arr[i])
//			min = arr[i];
//	}
//
//	printf("Maximum element is : %d\n", max);
//	printf("Minimum element is : %d\n", min);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int arr1[7] = { 1,6,4,6,8,3,4 };
//	int arr2[7];
//	int cnt = 0;
//	int same;
//	int check = 0;
//	int nono = 0;
//
//	for (int i = 0; i < 7; i++)
//	{
//		check = 0;
//		nono = 0;
//		same = arr1[i];
//		for (int j = i; j < 7; j++)
//		{
//			for (int k = i; k < cnt; k++)
//			{
//				if (same == arr2[k])
//					nono = 1;
//			}
//			if (nono == 1)
//				break;
//
//			if (same == arr1[j])
//			{
//				check++;
//			}
//		}
//		if (check >= 2)
//		{
//			arr2[cnt] = same;
//			cnt++;
//		}
//	}
//
//	printf("The repeating elements are: ");
//
//	for (int i = 0; i < cnt; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

