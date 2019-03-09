#include <iostream>
using namespace std;

int main()
{
	int num, a, b, i;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> num;

	for (i = 0; i < num; i++)
	{
		cin >> a;
		cin >> b;
		cout << a + b << "\n";
	}

	return 0;
}