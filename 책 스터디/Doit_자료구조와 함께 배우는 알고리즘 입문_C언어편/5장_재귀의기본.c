#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ����� �⺻ */

//���丮�� 
/*
int factorial(int n)
{
	if (n > 0)  // ���� 
		return n*factorial(n - 1);   // ��� ȣ��
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
//��Ŭ���� ȣ����
/*
int gcd(int x, int y)
{
	if (y == 0) return x; //���� ���� //
	else return gcd(y, x%y);  //  ���� 12 �̰� ���δ� 8 �� ���� -> 12,8 / 8,12 �� ���Ե� 

}
int main()
{
	int x=8, y=12;  //���� 8 ���� 12 �� ���簢�� 
	printf("%d %d �� �ִ����� %d", x, y, gcd(x, y));

	return 0;
}
*/
//���� 3�� 
// �迭 a �� ��� ��� �ִ����� ���ϱ� (���)

int gcd(int x, int y)
{
	if (y == 0) return x; //���� ���� //
	else return gcd(y, x%y);  //  ���� 12 �̰� ���δ� 8 �� ���� -> 12,8 / 8,12 �� ���Ե� 

}
int gcd_array(const int arr[], int n)
{
	if (n == 1)	return arr[0];	//�������� ��Ұ� �ϳ��϶� �Ǿ��� �ִ�����
	if (n == 2)	return gcd(arr[0],arr[1]); //0,1 �� �ִ��������ϱ�
	else return gcd(arr[0], gcd_array(arr+1, n - 1));  //���ʺ��� ������ 
}
int main()
{
	int *arr;
	int i, n;
	printf("��� ���� :");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	
	printf("�ִ����� : %d", gcd_array(arr,n));

	free(arr);
	return 0;
}
