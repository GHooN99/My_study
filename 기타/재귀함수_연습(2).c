#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//CodeUp 1920 재귀 2진수 변환
void toBin(long n)
{
	if (n == 0) return ;
	else
	{
		toBin(n / 2);
		printf("%d", n%2);
	}
}
int main()
{

	long n;

	scanf("%d", &n);
	if (n == 0)
		printf("0");
	else
		toBin(n);

	return 0;
}


// CodeUp 1928,1929(반대) 재귀 우박수(3N+1) 

void solve_reverse(int n)
{
	if (n == 1)
	{
		printf("%d\n", n);
		return;
	}
	else
	{
		if (n % 2 == 0)
			solve_reverse(n / 2);
		else
			solve_reverse(3 * n + 1);
		printf("%d\n", n);
	}
}
void solve(int n)
{
	if (n == 1)
	{
		printf("%d", n);
		return;
	}
	else
	{
		printf("%d\n", n);
		if (n % 2 == 0)
			solve(n / 2);
		else
			solve(3 * n + 1);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	
	solve_reverse(n);
	solve(n);

	return 0;
}

//CodeUp 1904 두수사이의 홀수 출력 (재귀)
void printOdd(int n)
{
	if (n % 2 == 1)
		printf("%d ", n);
}
void solve(int a, int b)
{
	if (a == b)
	{
		printOdd(a);
		return;
	}
	else
		printOdd(a);

	solve(a+1, b);

}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	solve(a, b);

	return 0;
}


