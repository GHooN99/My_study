#pragma warning(disable:4996)
#include <stdio.h>

void move(int no, int x, int y) //���� 1~ no��  ��� x ���� ��� y �� �ű� 
{
	if (no > 1) //1�� 
	{
		move(no - 1, x, 6 - x - y);  // �߰� ����� ��ȣ�� 6-x-y �� ���� 
	}

	printf("���� %d �� %d����� ���� %d����� �� �ű�\n",no,x,y); // 2�� (1���� ������� Ȥ�� 1,3 �� ������ �ȵɶ� ���)

	if (no > 1)//3�� 
	{
		move(no - 1, 6 - x - y , y);   //�߰���� 6-x-y
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n, 1, 3); //n���� 1��տ��� 3������� �ű� 
	return 0;
}


