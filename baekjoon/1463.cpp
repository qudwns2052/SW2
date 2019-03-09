#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001]{ 0 };

int main()
{
	int i, num;


	cin >> num;
	
	arr[1] = 0;

	for (i = 2; i <= num; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		else if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}

	cout << arr[num] << endl;
	
	return 0;
}