#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/* ��Ʈ ���ͷ� ���� ����� */

/* ������ �ִ� ����� ������ ���� ���
��Ʈ(1���� ����)�� ���� ������ ���� */

// ��Ʈ ������ ���� �ʿ� 


typedef unsigned long BitSet;	// 32��Ʈ �� bitset���� ��� 
#define BitSetNULL (BitSet)0		// 0 ������
#define BitSetBits 32			//��ȿ ��Ʈ ��
#define Setof(no) ((BitSet)1<<(no))		//����Ʈ ������(1�� no ��ŭ ����Ʈ) 
										// no�� �ִ� ������ �����.

int isMember(BitSet s, int n)  //���� s �� n���ִ��� Ȯ�� 
{
	return s &Setof(n); //���� ���� , n�������� ��Ʈ 1  ������ ��� ��Ʈ 0��ȯ
}
void Add(BitSet *s, int n)	//���տ� �߰� 
{
	*s |= Setof(n); // s�� ��Ʈ�� ��Ÿ�� n �� �� �� ���� 
}
void Remove(BitSet *s, int n) //����
{
	*s &= ~Setof(n); // s �� ~n �� �� �� ���� 
}
int Size(BitSet s) //���� ���� ��ȯ
{
	int n=0;
	for (n = 0; s != BitSetNULL; n++) // ������ �϶����� ����
		s &= s - 1;  //���տ��� 1�� �ִ°��� 0���� �ٲٴ� ���� 

	return n; //���� Ƚ���� 1�� ���� 
}
void Print(BitSet s) //��� 
{
	printf("{");
	for (int i = 0; i < BitSetBits; i++) // ��� ��Ʈ�� ���鼭 Ȯ��
	{
		if (isMember(s, i)) printf("%d ", i); //�ش� ��Ʈ�� ã���� ��� 
	}
	printf("}\n");
}
int main()
{
	int menu, n, c;
	BitSet 
	s1 = BitSetNULL,
	s2 = BitSetNULL,
	s3 = BitSetNULL; // ���� 3�� �ʱ�ȭ

	while (1)
	{
		printf("s1: ");
		Print(s1);
		printf("s2: ");
		Print(s2);
		printf("___Menu___\n");
		printf("(1)Add (2)Remove (3)isEqual (4)Operation (0)Exit\n");
		printf("Menu :");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("(0)s1�� �߰� (1)s2�� �߰� :");
			scanf("%d", &c);
			printf("�߰� �� ���� :");
			scanf("%d", &n);
			if (!c)	Add(&s1, n);
			else Add(&s2, n);
			break;
		case 2:
			printf("(0)s1���� ���� (1)s2���� ���� :");
			scanf("%d", &c);
			printf("���� �� ���� :");
			scanf("%d", &n);
			if (!c)	Remove(&s1, n);
			else Remove(&s2, n);
			break;
		case 3:
			printf("s1 �� s2�� %s���ϴ�.\n",s1==s2 ? "��":"���� ��");
			break;
		case 4:
			printf("Union : ");
			s3 = s1 | s2;
			Print(s3);

			printf("Intersection : ");
			s3 = s1 & s2;
			Print(s3);

			printf("Difference (s1-s2): ");
			s3 = s1 & ~s2; //1��2�� => 1-2
			Print(s3);

			printf("Difference (s2-s1): ");
			s3 = s2 & ~s1; //2��1�� => 2-1
			Print(s3);

			break;
		case 0:
			return 0;
		default:
			break;
		}

	}

	return 0;
}
