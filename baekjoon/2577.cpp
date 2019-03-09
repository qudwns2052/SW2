#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	string sum;
	int arr[10]{ 0 };
	int i, j, len;
	
	cin >> a;
	cin >> b;
	cin >> c;

	sum = to_string(a * b* c);
	len = sum.length();
	
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (i == sum[j] - 48)
				arr[i] ++;
		}
	}
	for (i = 0; i < 10; i++)
		cout << arr[i] << endl;
	
	return 0;
}