#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// CodeUp 1953 2�� ? ����Լ� ����

void star(int n) // �� ��� ���
{
	if (n == 0) return;
	else 
	{
		printf("*");
		star(n - 1);
	}

}
void line(int n) // �� �ٲ� ��� 
{
	if (n == 0) return;

	line(n - 1);

	star(n);
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);

	line(n);

	return 0;
}
