#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

int main()
{

	int num;
	int i, j;
	int cnt1;
	int cnt2;
	char str[50];
	int strLen;

	scanf("%d", &num);
	getchar();

	for (i = 0; i < num; i++)
	{
		scanf("%s", str);
		getchar();
		strLen = strlen(str);

		cnt1 = 0;
		cnt2 = 0;

		for (j = 0; j < strLen; j++)
		{
			if (cnt1 < cnt2)
			{
				break;
			}
			if (str[j] % 2 == 0)
				cnt1++;
			else
				cnt2++;
		}
		if (cnt1 == cnt2)
			printf("YES\n");
		else
		{
			printf("NO\n");
		}

	}

	return 0;
}
