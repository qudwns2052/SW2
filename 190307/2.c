#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 30
#define PERSON_LEN 6

typedef struct Vege
{
	int apple, carrot, onion, banana;
}Vege;

typedef struct Human
{
	char name[NAME_LEN];
	int money;
	Vege vege;
}Human;

Human * initCustomer(char *name1);
Human * initSeller(char *name2);
void printHuman(Human * human);
void appleTrade(Human * person1, Human * person2, int much);
void carrotTrade(Human * person1, Human * person2, int much);
void onionTrade(Human * person1, Human * person2, int much);
void bananaTrade(Human * person1, Human * person2, int much);
void Search(Human * person[], int num);

int main()
{
	int num, much, who;
	int i;
	char name[NAME_LEN];
	Human * person[PERSON_LEN];

	
	for (i = 0; i < PERSON_LEN - 1; i++)
	{
		printf("이름을 입력하세요: ");
		scanf("%s", name);
		person[i] = initCustomer(name);

	}


	printf("이름을 입력하세요: ");
	scanf("%s", name);
	person[PERSON_LEN - 1] = initSeller(name);

	
	while (1)
	{
		printf("------------------------");
		for (i = 0; i < PERSON_LEN; i++)
			printHuman(person[i]);

		printf("------------------------\n\n\n");
		printf("구매할 고객을 선택하세요 (몇번째 고객인지) ->  ");
		scanf("%d", &who);
		printf("무엇을 구매하실 건가요? (사과: 1, 당근: 2, 양파: 3, 바나나: 4, 사과 찾기: 0) ->  ");
		scanf("%d", &num);
		printf("몇개를 구매하실 건가요? (몇개를 찾고 싶나요?) ->  ");
		scanf("%d", &much);
		switch (num)
		{
		case 0:
			printf("사과가 %d개 있는 고객을 찾는 중입니다....\n", much);
			Search(person, much);
			break;
		case 1:
			appleTrade(person[who-1], person[PERSON_LEN-1], much);
			break;
		case 2:
			carrotTrade(person[who-1], person[PERSON_LEN - 1], much);
			break;
		case 3:
			onionTrade(person[who-1], person[PERSON_LEN - 1], much);
			break;
		case 4:
			bananaTrade(person[who-1], person[PERSON_LEN - 1], much);
		}


	}
	for (i = 0; i < PERSON_LEN; i++)
	{
		free(person[i]);
	}

	return 0;
}

Human * initCustomer(char *name)
{
	Human * person;
	person = malloc(sizeof(Human));
	strcpy(person->name, name);
	person->money = 10000;
	person->vege.apple = 0;
	person->vege.carrot = 0;
	person->vege.onion = 0;
	person->vege.banana = 0;
	

	return person;
}

Human * initSeller(char *name)
{
	Human * person;
	person = malloc(sizeof(Human));
	strcpy(person->name, name);
	person->money = 3000;
	person->vege.apple = 50;
	person->vege.carrot = 50;
	person->vege.onion = 50;
	person->vege.banana = 50;

	return person;
}

void printHuman(Human * human)
{
	printf("\n");
	printf("이름: %s\n", human->name);
	printf("돈: %d\n", human->money);
	printf("사과: %d\n", human->vege.apple);
	printf("당근: %d\n", human->vege.carrot);
	printf("양파: %d\n", human->vege.onion);
	printf("바나나: %d\n", human->vege.banana);
	printf("\n");
}

void appleTrade(Human * person1, Human * person2, int much)
{
	if (person1->money < (much * 1000) || person2->vege.apple < (much))
	{
		printf("\n\n돈이 부족하거나, 과일(채소)가 부족합니다.\n\n");
		return;
	}
	person1->vege.apple += much;
	person2->vege.apple -= much;
	person1->money -= (much * 1000);
	person2->money += (much * 1000);

}
void carrotTrade(Human * person1, Human * person2, int much)
{
	if (person1->money < (much * 1000) || person2->vege.carrot < (much))
	{
		printf("\n\n돈이 부족하거나, 과일(채소)가 부족합니다.\n\n");
		return;
	}
	person1->vege.carrot += much;
	person2->vege.carrot -= much;
	person1->money -= (much * 1000);
	person2->money += (much * 1000);

}
void onionTrade(Human * person1, Human * person2, int much)
{
	if (person1->money < (much * 1000) || person2->vege.onion < (much))
	{
		printf("\n\n돈이 부족하거나, 과일(채소)가 부족합니다.\n\n");
		return;
	}	person1->vege.onion += much;
	person2->vege.onion -= much;
	person1->money -= (much * 1000);
	person2->money += (much * 1000);
}


void bananaTrade(Human * person1, Human * person2, int much)
{
	if (person1->money < (much * 1000) || person2->vege.banana < (much))
	{
		printf("\n\n돈이 부족하거나, 과일(채소)가 부족합니다.\n\n");
		return;
	}
	person1->vege.banana += much;
	person2->vege.banana -= much;
	person1->money -= (much * 1000);
	person2->money += (much * 1000);

}

void Search(Human * arr[], int num)
{
	int min, mid, max;
	int ref = -1;

	min = 0;
	max = PERSON_LEN - 2;

	while (min <= max)
	{
		mid = (max + min) / 2;

		if (num == arr[mid]->vege.apple)
		{
			ref = mid;
			break;
		}
		else if (num < arr[mid]->vege.apple)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}

	if (ref == -1)
		printf("찾으시는 값이 없습니다\n");
	else
		printf("찾으시는 값은 %d번째에 있는 고객입니다\n", ref + 1);


}