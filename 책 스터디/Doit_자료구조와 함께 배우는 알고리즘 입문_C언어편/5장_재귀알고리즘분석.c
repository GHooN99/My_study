#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
//��� �� ����� �м� 
//�� �ڵ�  
void recur2(int n)
{
	if (n > 0)
	{
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}
int main()
{
	recur2(3);
	return 0;
}
*/

// ����� �м� 

/*
recur2(0) : x
recur2(1) : recur2(-1) / 1 /recur2(0) -> 1���
recur2(2) : recur2(0) / 2 / recur2(1) -> 2 ��� , 1��� 
recur2(3) : recur2(1) / 3 / recur2(2) -> 1��� , 3��� ,2��� ,1��� 

���: 1,3,2,1 ��� 
*/

//����� �м� 
/*
				recur2(1) /			 3 /			  recur2(2)
		recur2(-1)/1/recur2(0)      ���2		recur2(0)  / 2    /      recur2(1)
		x		���1	x							x     ���3    recur2(-1) / 1 / recur2(0)
					                                               x          ���4   x
��� : 1, 3, 2, 1 ���
*/

//���->�����
//��������
/*
void recur2(int n)
{
	Top : 
	if (n > 0)
	{
		recur2(n - 2);
		printf("%d\n", n);
		n--;
		goto Top;  //���� ����
	}
}
int main()
{
	recur2(3);
	return 0;
}

*/
// ��� �� ���� -> �����ڷᱸ�� �� �̿� 
/*
void recur2(int n)
{
Top:
	if (n > 0)
	{
		Push(stk, n);	//n�� Ǫ�� 
		n=n-2;   //n���̰� 
		goto Top;  //
	}
	if (!isEmtpy) //������� ���� �����̸�
	{
		Pop(stk, n);   //n�� ��
		printf("%d\n", n);   
		n = n - 1;  //n���̰�
		goto Top;
	}

	
}
int main()
{
	recur2(3);
	return 0;
}
*/