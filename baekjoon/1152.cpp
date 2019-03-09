#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int len, cnt = 1;
	getline(cin, str);
	
	len = str.length();

	for (int i = 0; i < len ; i++)
	{
		if (str[i] == ' ')
			cnt++;

	}

	if (str[0] == ' ')
		cnt--;
	if (str[str.length() - 1] == ' ')
		cnt--;

	cout << cnt << endl;

	
	return 0;
}