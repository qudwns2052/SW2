#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int id;
	char name[11];
	char phone[12];
} STUDENT;

#define SWAP(x, y, t) ( ((t)=(x)), ((x)=(y)), ((y)=(t)))
#define SWAPSTR(x, y, t) {strcpy(t,x); strcpy(x,y); strcpy(y, t);}
#define DATASIZE 100000

int partition_byname(STUDENT *list, int left, int right) {
	char  pivot[11];
	int low, high;
	char tmp[11];

	low = left;
	high = right + 1;
	strcpy(pivot, list[left].name);

	do {
		do low++;
		while (low <= right && (strcmp(list[low].name, pivot)) < 0);

		do high--;
		while (high >= left && (strcmp(list[high].name, pivot)) > 0);

		if (low < high) SWAPSTR(list[low].name, list[high].name, tmp);
	} while (low < high);

	SWAPSTR(list[left].name, list[high].name, tmp);
	return high;
}

void quick_sort_byname(STUDENT *list, int left, int right) {
	if (left < right) {
		int q = partition_byname(list, left, right);
		quick_sort_byname(list, left, q - 1);
		quick_sort_byname(list, q + 1, right);
	}
}

int partition(STUDENT *list, int left, int right) {
	int  pivot;
	int low, high;
	STUDENT tmp;

	low = left;
	high = right + 1;
	pivot = list[left].id;

	do {
		do low++;
		while (low <= right && (list[low].id < pivot));

		do high--;
		while (high >= left && (list[high].id > pivot));

		if (low < high) SWAP(list[low], list[high], tmp);
	} while (low < high);

	SWAP(list[left], list[high], tmp);
	return high;
}

void quick_sort(STUDENT *list, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

STUDENT *createdata() {
	STUDENT *org;
	int		year;
	int		i, j;
	int		idnum1, idnum2;
	int		phone1, phone2;
	org = malloc(DATASIZE * sizeof(STUDENT));
	srand((unsigned int)time(NULL));

	for (i = 0; i < DATASIZE; i++) {
		// 학번 만들기
		year = rand() % 6 + 2013;
		idnum1 = rand() % 1000;
		idnum2 = rand() % 100;
		org[i].id = year * 100000 + idnum1 * 100 + idnum2;

		// 이름 만들기
		for (j = 0; j < 10; j++)
			org[i].name[j] = rand() % 26 + 'A';
		org[i].name[j] = 0;

		// 전화번호 만들기
		phone1 = rand() % 10000;
		phone2 = rand() % 10000;
		sprintf(org[i].phone, "010%04d%04d", phone1, phone2);
		//		printf("%10d  %10s  %11s\n", org[i].id, org[i].name, org[i].phone);
	}
	return org;
}

main() {
	STUDENT *org, *copy;
	clock_t start, end;
	int		i;
	//1000명분의 랜덤 데이터 만들기.

	org = createdata();

	copy = malloc(DATASIZE * sizeof(STUDENT));	//복사본 만들기
	memcpy(copy, org, sizeof(STUDENT)* DATASIZE);

	start = clock();
	/*
	printf("재귀 퀵 정렬\n");
	quick_sort(copy, 0, DATASIZE-1);
	end = clock();
	printf("재귀 퀵 정렬 시간 : %f밀리 초 %d %d\n", (double)(end - start), end, start);
	printf("\n");
	*/
	printf("재귀 퀵 정렬\n");
	quick_sort_byname(copy, 0, DATASIZE - 1);
	end = clock();
	printf("재귀 퀵 정렬 시간 : %f밀리 초 %d %d\n", (double)(end - start), end, start);
	printf("\n");

	for (i = 0; i < DATASIZE; i += 100)
		printf("%10d  %10s  %11s\n", copy[i].id, copy[i].name, copy[i].phone);

}
