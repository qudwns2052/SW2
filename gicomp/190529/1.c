#include <stdio.h>
#include <windows.h>

int main(void)
{
	//����: �迭�� 1���� ũ�� 100���� ���� 3�� ����� �ְ� �̸� ����Ͻÿ�

	//33�� ��� = for
	//33���� �־�ߵ� ũ�Ⱑ 33�� �迭
	//33���� �ִ°͵� = for

	int arr[33];
	int i;

	for (i = 0; i < 33; i++)
		arr[i] = 3*(i + 1);

	for (i = 0; i < 33; i++)
		printf("%d ", arr[i]);

	system("pause");
	return 0;
}