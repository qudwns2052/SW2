#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr[100];
	
	int i, j, cnt;

	cin >> arr;
	
	cnt = strlen(arr) / 10;

	for (i = 0; i < cnt + 1; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arr[i * 10 + j] == 0)
			{
				break;
			}
			else
				cout << arr[i * 10 + j];
		}
		cout << endl;
		
	}

	
	return 0;

}