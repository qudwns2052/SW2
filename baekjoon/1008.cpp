#include <iostream>
using namespace std;

int main()
{
	double a, b;
	cin >> a;
	cin >> b;
	
	cout.precision(9);
	cout << fixed << a/b << endl;

	return 0;
}