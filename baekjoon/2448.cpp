#include <iostream>
using namespace std;

void star(int num, int len);

int main()
{
	int num;
	int len = 0;

	cin >> num;
	


	star(num, len);


	system("pause");
	return 0;
}

void star(int num, int len)
{
	if (num <= 0)
		return;

	int cnt, i, j;
	int what = 1;
	int True = 0;

	num--;
	len++;
	star(num, len);

	for (cnt = 0; cnt < 10; cnt++)
	{
		if (what == ((num/3)+1))
		{
			True = 1;
			break;
		}
		what *= 2;
	}
	
	if (True==1)
	{
		if ((len - 1) / 3 >= 1)
		{
			for (j = 0; j < (len - 1) / 3; j++)
			{
				cout << "   ";
			}
		}

		for (i = 0; i < (num / 3) + 1; i++)
		{

			if (num % 3 == 0)
				cout << "  *  ";
			else if (num % 3 == 1)
				cout << " * * ";
			else
				cout << "*****";

			cout << " ";
		}
		if ((len - 1) / 3 >= 1)
		{
			for (j = 0; j < (len - 1) / 3; j++)
			{
				cout << "   ";
			}
		}
	}
	else
	{
		if (((num / 3) + 1) % 4 == 3)
		{
			for (cnt = 0; cnt < (((num / 3) + 1) / 3) + 1; cnt++)
			{
				if ((len - 1) / 3 >= 1)
					for (j = 0; j < (len - 1) / 3; j++)
						cout << "   ";


				if (num % 3 == 0)
					cout << "  *  ";
				else if (num % 3 == 1)
					cout << " * * ";
				else
					cout << "*****";

				cout << " ";

				if ((len - 1) / 3 >= 1)
					for (j = 0; j < (len - 1) / 3; j++)
						cout << "   ";

			}
		}
		

		
	}
	

	cout << endl;
	
}