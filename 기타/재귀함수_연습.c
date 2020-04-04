#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// CodeUp 1953 2Áß ? Àç±ÍÇÔ¼ö ¿¬½À

void star(int n) // º° Ãâ·Â Àç±Í
{
	if (n == 0) return;
	else 
	{
		printf("*");
		star(n - 1);
	}

}
void line(int n) // ÁÙ ¹Ù²Þ Àç±Í 
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
