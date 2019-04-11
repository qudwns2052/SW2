#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(void)
{
	char str[100];

	scanf("%s", str);

	int len = strlen(str);

	int s_str[100] = { 0, };

	int cnt = 0;
	int check;

	int count = 0;
	int here;

	while (cnt < len)
	{
		here = 0;
		int i = 'A';
		int j = 0;
		while (i < 'Z' + 1)
		{
			check = 0;

			for (j = here; j < len; j++)
			{
				if (str[j] == i)
				{
					if (s_str[j] != 0)
						continue;
					s_str[j] = str[j];
					check++;
					cnt++;
					here = j + 1;
					break;
				}
			}


			if (check >= 1)
			{
				for (int k = 0; k < len; k++)
				{
					if (s_str[k] != 0)
						printf("%c", s_str[k]);
				}
				printf("\n");
			}


			i++;

			if (cnt == len)
				break;
		}
	}
	
	system("pause");
	return 0;
}