//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int arr_1[10];
//	int *arr_2;
//	int i;
//	for (i = 0; i < 10; i++)
//		arr_1[i] = i + 1;
//
//	arr_2 = (int*)malloc(sizeof(int) * 5);
//	for (i = 0; i < 5; i++)
//	{
//		arr_2[i] = arr_1[i];
//		printf("%d ", arr_2[i]);
//	}
//	printf("\n");
//
//	realloc(arr_2, sizeof(int) * 10);
//
//	for (i = 0; i < 10; i++)
//	{
//		arr_2[i] = arr_1[i];
//		printf("%d ", arr_2[i]);
//	}
//	free(arr_2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct name
//{
//	int age;
//	char name[25];
//};
//
//int main(void)
//{
//	char *org_name;
//	struct name *myname;
//	int i;
//
//	org_name = (char*)malloc(sizeof(char) * 25);
//	myname = (struct name*)malloc(sizeof(struct name)*2);
//
//	strcpy(org_name, "yundream");
//
//	myname[0].age = 25;
//	strcpy(myname[0].name, org_name);
//
//
//	strcpy(org_name, "testname");
//	myname[1].age = 28;
//	strcpy(myname[1].name, org_name);
//
//	for (i = 0; i < 2; i++)
//		printf("%d: %s\n", myname[i].age, myname[i].name);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int * arr = (int*)malloc(sizeof(int) * 5);
//	
//	for (int i = 0; i < 5; i++)
//		arr[i] = i + 2;
//
//	arr = (int*)realloc(arr, sizeof(int) * 8);
//
//	for (int i = 0; i < 3; i++)
//		arr[i + 5] = i + 1;
//
//	int result = 0;
//
//	for (int i = 0; i < 8; i++)
//		result += arr[i];
//
//	printf("The sum of array is : %d\n", result);
//
//	free(arr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int *ptr;
//	int i;
//
//	ptr = (int*)malloc(sizeof(int) * 5);
//
//	for (i = 0; i < 5; i++)
//		ptr[i] = 25 * (i + 1);
//
//	for (i = 0; i < 5; i++)
//		printf("%d\n", ptr[i]);
//
//	free(ptr);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int *ptr = (int*)malloc(sizeof(int) * 2);
//	int i;
//	int *ptr_new;
//
//	*ptr = 10;
//	*(ptr + 1) = 20;
//
//	ptr_new = (int*)realloc(ptr, sizeof(int) * 3);
//	ptr_new[2] = 30;
//
//	for (i = 0; i < 3; i++)
//		printf("%d ", *(ptr_new + i));
//
//	return 0;
//}