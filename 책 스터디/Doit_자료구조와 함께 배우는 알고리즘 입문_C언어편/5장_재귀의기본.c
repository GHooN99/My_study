#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 재귀의 기본 */

//팩토리얼 
/*
int factorial(int n)
{
	if (n > 0)  // 조건 
		return n*factorial(n - 1);   // 재귀 호출
	else
		return 1;
}
int main()
{
	int n = 4;
	printf("%d! = %d", n, factorial(n));

	return 0;
}
*/
//유클리드 호제법
/*
int gcd(int x, int y)
{
	if (y == 0) return x; //종료 조건 //
	else return gcd(y, x%y);  //  세로 12 이고 가로는 8 이 남음 -> 12,8 / 8,12 나 같게됨 

}
int main()
{
	int x=8, y=12;  //가로 8 세로 12 인 직사각형 
	printf("%d %d 의 최대공약수 %d", x, y, gcd(x, y));

	return 0;
}
*/
//문제 3번 
// 배열 a 의 모든 요소 최대공약수 구하기 (재귀)

int gcd(int x, int y)
{
	if (y == 0) return x; //종료 조건 //
	else return gcd(y, x%y);  //  세로 12 이고 가로는 8 이 남음 -> 12,8 / 8,12 나 같게됨 

}
int gcd_array(const int arr[], int n)
{
	if (n == 1)	return arr[0];	//종료조건 요소가 하나일때 맨앞이 최대공약수
	if (n == 2)	return gcd(arr[0],arr[1]); //0,1 에 최대공약수구하기
	else return gcd(arr[0], gcd_array(arr+1, n - 1));  //뒤쪽부터 앞으로 
}
int main()
{
	int *arr;
	int i, n;
	printf("요소 개수 :");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	
	printf("최대공약수 : %d", gcd_array(arr,n));

	free(arr);
	return 0;
}
