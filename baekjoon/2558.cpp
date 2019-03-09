#include <iostream>
using namespace std;

int main()
{
	int num, sum = 0;
	char arr[100];
	
	cin >> num;
	cin >> arr;


	for (int i = 0; i < num ; i++)
	{
		sum += (arr[i] - '0');
	}

	cout << sum << endl;

	return 0;
}