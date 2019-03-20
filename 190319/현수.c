#include <stdio.h>

int main()
{
	int a[3][2];
	int b[3][2];
	int c[3][2];

	int za = 0;
	int zb = 0;
	int zc = 0;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
	}

	for (int i0 = 0; i0 < 3; i0++)
	{
		scanf("%d %d", &b[i0][0], &b[i0][1]);
	}

	while (1)
	{
		if (za > 2)
		{
			if (zb > 2)
				break;
			else
			{
				c[zc][0] = b[zb][0];
				c[zc][1] = b[zb][1];

				zc++;
				zb++;
			}
		}

		else if (zb > 2)
		{
			c[zc][0] = a[za][0];
			c[zc][1] = a[za][1];

			zc++;
			za++;

		}
		else if (a[za][1] > b[za][1])
		{
			c[zc][0] = a[za][0];
			c[zc][1] = a[za][1];

			zc++;
			za++;

		}

		else if (a[za][1] == b[zb][1] && a[za][0] * b[zb][0] != 0)
		{
			c[zc][0] = a[za][0] + b[zb][0];
			c[zc][1] = a[za][1];

			zc++;
			zb++;
			za++;

		}

		else if (b[zb][1] > a[za][1] && b[zb][0] != 0)
		{
			c[zc][0] = b[zb][0];
			c[zc][1] = b[zb][1];

			zc++;
			zb++;
		}

	}

	for (int ia = 0; ia < 3; ia++)
	{
		printf("%d %d\n", c[ia][0], c[ia][1]);
	}
}