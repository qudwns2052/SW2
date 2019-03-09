#include <iostream>
#include <algorithm>
using namespace std;

int dp[11];

int main()
{
	int i, cnt, num;
	cin >> cnt;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (i = 0; i < cnt; i++) 
	{
		cin >> num;
		cout << dp[num] << endl;
	}

	
	return 0;
}