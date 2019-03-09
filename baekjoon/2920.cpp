#include <iostream>
using namespace std;

int main()
{
	int arr[8];
	int i;
	int cnt1 = 0;
	int cnt2 = 0;
	for (i = 0; i < 8; i++)
		cin >> arr[i];

	for (i = 0; i < 8; i++)
	{
		if (arr[i] != i + 1 && cnt1 == 0)
		{
			cnt1++;
		}
		else if (arr[i] != 8 - i && cnt2 == 0)
		{
			cnt2++;
		}

	}

	if (cnt1 == 0)
		cout << "ascending" << endl;
	else if (cnt2 == 0)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;


	system("pause");
	return 0;
}