//#include <stdio.h>
//
//typedef struct student
//{
//	char name[50];
//	int ID;
//	float marks;
//}Student;
//
//int main(void)
//{
//	Student student;
//
//	printf("Enter information:\n");
//	printf("Enter name: ");
//	scanf("%s", student.name);
//	printf("Enter ID: ");
//	scanf("%d", &student.ID);
//	printf("Enter marks: ");
//	scanf("%f", &student.marks);
//
//	printf("Displaying Informations:\n");
//	printf("Name: %s\n", student.name);
//	printf("Roll number: %d\n", student.ID);
//	printf("Marks: %f\n", student.marks);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct person {
//	int age;
//	float weight;
//	char name[30];
//};
//
//int main(void)
//{
//	struct person * ptr;
//	int i, n;
//
//	printf("Enter number of persons: ");
//	scanf("%d", &n);
//
//	ptr = (struct person *)malloc(sizeof(struct person)*n);
//
//	for (i = 0; i < n; i++)
//	{
//		printf("Enter first name and age respectively: ");
//		scanf("%s", ptr[i].name);
//		scanf("%d", &ptr[i].age);
//	}
//
//	printf("Displaying Information:\n");
//
//	for (i = 0; i < n; i++)
//	{
//		printf("Name: %s\t", ptr[i].name);
//		printf("Age: %d\n", ptr[i].age);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	char * str = "computer programming";
//
//	int len = strlen(str);
//	
//	for (int i = len - 1; i >= 0; i--)
//	{
//		printf("%c", str[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	char str1[] = "This is a string to be copied.";
//	char str2[100];
//
//	strcpy(str2, str1);
//	printf("The First string is : %s\n", str1);
//	printf("The Second string is : %s\n", str2);
//	printf("Number of characters copied : %d\n", strlen(str1));
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	char * str = "Welcome to Computer Programming";
//	
//	int len = strlen(str);
//	
//	int max = 0;
//	int cnt = 0;
//	char temp = 'a';
//	char ch;
//
//	for (int i = 0; i < 26; i++)
//	{
//		temp = 'a' + i;
//		cnt = 0;
//		for (int j = 0; j < len; j++)
//		{
//			if (str[j] == temp || str[j] == temp - 32)
//				cnt++;
//		}
//
//		if (max < cnt)
//		{
//			max = cnt;
//			ch = temp;
//		}
//		
//	}
//	
//	printf("ch = %c\t °³¼ö = %d\n", ch, max);
//
//	return 0;
//}