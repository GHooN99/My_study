#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� 1 

int sum(int n)
{
	if (n == 0) return 0;
	else return n + sum(n - 1);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}

// ���� 2

void printDigit(int n)
{
	if (n == 0) return;
	else
	{
		printDigit(n / 10);
		printf("%d\n", n % 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);

	printDigit(n);

	return 0;
}

// ���� 3
void printDigit(int n)
{
	if (n == 0) return;
	else
	{
		printf("%d\n", n % 10);
		printDigit(n / 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);

	printDigit(n);

	return 0;
}

//���� 4
int findMax(int arr[], int n)
{
	if (n == 1) return arr[0];
	else
	{
		int max = findMax(arr, n - 1);
		if (max > arr[n - 1]) return max;
		else return arr[n - 1];
	}
}
int main()
{
	int n,arr[20];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	printf("%d", findMax(arr, n));

	return 0;
}

// ���� 5

void hanoi(int n,char start, char end,char other)
{
	if (n == 0) return; //���� 0��

	hanoi(n - 1, start, other, end); //�� ���� ������ �������� �ٸ� ������� 
	printf("%c %c\n", start, end);  //�� �� ����� ��ǥ ������� �ű� ��� 
	hanoi(n - 1, other, end, start); // �ٸ���տ� �ִ� �������� ��ǥ������� �ű�

}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n,'A','C','B'); //A ���� (C �� b�� ��ġ��)
	return 0;
}

// ���� 6
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y,x%y);
}
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d", gcd(x, y));

	return 0;
}

// ���� 7
int findChar(char str[], char c)
{
	if (0 == strlen(str) ) return 0;
	else if (str[0] == c)
	{
		return 1+findChar(str+1, c);
	}
	else return findChar(str+1, c);
}
int main()
{
	char str[101];
	char c;
	scanf("%s", str);
	getchar();
	scanf("%c", &c);

	printf("%d", findChar(str, c));
	return 0;
}