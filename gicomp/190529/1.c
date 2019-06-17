#include <stdio.h>
#include <windows.h>

int main(void)
{
	//문제: 배열에 1보다 크고 100보다 작은 3의 배수를 넣고 이를 출력하시오

	//33번 출력 = for
	//33개를 넣어야돼 크기가 33인 배열
	//33개를 넣는것도 = for

	int arr[33];
	int i;

	for (i = 0; i < 33; i++)
		arr[i] = 3*(i + 1);

	for (i = 0; i < 33; i++)
		printf("%d ", arr[i]);

	system("pause");
	return 0;
}