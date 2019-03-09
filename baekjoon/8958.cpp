#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int num, i, j, len;
	int cnt, score;
	cin >> num;
	cin.get();
	

	for (i = 0; i < num; i++)
	{
		
		getline(cin, str);
		
		len = str.length();
		cnt = 0;
		score = 0;

		
		for (j = 0; j < len; j++)
		{
			if (str[j] == 0)
				break;

			if ('O' == str[j])
			{
				cnt++;
				score += cnt;
			}
			else
			{
				cnt = 0;
			}
		}

		cout << score << endl;
	
	}
	system("pause");
	return 0;
}