#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	int cnt = 0;
	while (1)
	{
		cin.clear();
		getline(cin, str);
		cout << str << endl;
		cnt++;
		if (cnt >= 100)
			break;
	}
	return 0;
}