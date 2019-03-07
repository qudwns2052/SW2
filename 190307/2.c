#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 30

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


int main()
{
	int num, much;
	char name1[NAME_LEN];
	char name2[NAME_LEN];
	Human * person1;
	Human * person2;

	printf("이름을 입력하세요: ");
	scanf("%s", name1);

	printf("이름을 입력하세요: ");
	scanf("%s", name2);
	

	person1 = initCustomer(name1);
	person2 = initSeller(name2);

	while (1)
	{
		printf("------------------------");
		printHuman(person1);
		printHuman(person2);
		printf("------------------------\n\n\n");
		printf("무엇을 구매하실 건가요? (1:사과, 2:당근, 3:양파, 4:바나나) (개당 1000원) -> ");
		scanf("%d", &num);
		printf("몇개를 구매하실 건가요? -> ");
		scanf("%d", &much);
		switch (num)
		{
		case 1:
			appleTrade(person1, person2, much);
			break;
		case 2:
			carrotTrade(person1, person2, much);
			break;
		case 3:
			onionTrade(person1, person2, much);
			break;
		case 4:
			bananaTrade(person1, person2, much);
		}


	}
	free(person1);
	free(person2);

	return 0;
}

Human * initCustomer(char *name1)
{
	Human * person1;
	person1 = malloc(sizeof(Human));
	strcpy(person1->name, name1);
	person1->money = 10000;
	person1->vege.apple = 0;
	person1->vege.carrot = 0;
	person1->vege.onion = 0;
	person1->vege.banana = 0;
	

	return person1;
}

Human * initSeller(char *name2)
{
	Human * person2;
	person2 = malloc(sizeof(Human));
	strcpy(person2->name, name2);
	person2->money = 3000;
	person2->vege.apple = 10;
	person2->vege.carrot = 5;
	person2->vege.onion = 5;
	person2->vege.banana = 5;

	return person2;
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
