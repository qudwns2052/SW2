#include <stdio.h>
#include <windows.h>

int calculate(char * str, int n)
{
	int cnt = 0;
	int score[3];
	int i = 0;
	int sub = 1;
	int starcnt = 0;
	int achacnt = 0;


	while (cnt < 3)
	{
		int j = 0;
		char temp[2];
		int num_cnt = 0;
		while ('0' <= str[i] && str[i] <= '9')
		{
			temp[j++] = str[i++];
			num_cnt++;
		}
		if (num_cnt == 2)
			score[cnt] = (temp[0] - '0') * 10 + (temp[1] - '0');
		else
			score[cnt] = (temp[0] - '0');
		
		switch (str[i++])
		{
		case 'S':
			break;
		case 'D':
			score[cnt] *= score[cnt];
			break;
		case 'T':
			for (int k = 0; k < 3; k++)
				sub *= score[cnt];
			score[cnt] = sub;
			break;
		}
		switch (str[i])
		{
		case '*':
			score[cnt] *= 2;
			if (cnt != 0)
				score[cnt - 1] *= 2;
			i++;
			break;
		case '#':
			score[cnt] *= -1;
			i++;
			break;
		default:
			break;
		}
		cnt++;
	}

	int result = score[0] + score[1] + score[2];
	return result;

}


int main(void)
{
	char str[9];
	int result;


	scanf("%s", str);

	result = calculate(str, strlen(str));
	
	printf("%d", result);


	system("pause");
	return 0;
}