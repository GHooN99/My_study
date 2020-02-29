#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int max; // �ִ� ���� ���� 
	int num; //���� ���� ����
	int *set; //���� �迭 ù���� ������
}IntSet;


int Init(IntSet *s, int max)  //���� �ʱ�ȭ
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;	//������ ����
	}
	s->max = max;
	return 0; //���� ���� 
}
int isMember(const IntSet *s, int n) //���� ã�� 
{
	for (int i = 0; i < s->num; i++)
		if (s->set[i] == n) return i;	//���� ã���� �ε��� ��ȯ

	return -1; //������ -1 ��ȯ
}
int Add(IntSet *s, int n) //���� �߰� 
{
	if (s->num == s->max)	return -1;  //�����÷� Ȯ��
	if (isMember(s, n) != -1) return -1; //�ߺ��� ����
	else
		s->set[s->num++] = n; //���� �߰� �� ���� ���� ����
		return 0; //���� ����
}
int Remove(IntSet *s, int n) //���� ����
{
	int idx = isMember(s,n);
	if (s->num == 0)	return -1; //���� �Ұ�
	if (idx == -1)	return -1; //ã�°��� ���� 
	else
		s->set[idx] = s->set[--(s->num)]; //�������� �ִ� ���� ������ �ε����� ���� �� ������ ����
	return 0;
}
void Assign(IntSet *s1, const IntSet *s2) //���� s2�� s1�� ����
{
	int n;
	if (s1->max < s2->num) n = s1->max; // �ִ�� �ִ븸ŭ
	else n = s2->num;  //���� ������ ���� s2 ��ŭ

	for (int i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;

}
int isEqual(const IntSet *s1, const IntSet *s2) //���� �������� Ȯ��
{
	int j = 0;
	if (s1->num != s2->num) return 0;
	for (int i = 0; i < s1->num; i++)
	{
		for (j = 0; j < s2->num; j++)
			if (s2->set[j] == s1->set[i]) break;
		if (j == s2->num) return 0; //������ ã�� ���� 
	}
	return 1;
}

IntSet* Union(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2,s3 �� �������� s1 �� ���� 
{
	Assign(s1, s2); //s1�� s2 �� ����
	for (int i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]); //s1�� s3�� ���� 

	return s1; //s1 �ּҸ� ��ȯ 
}
IntSet* Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2,s3 �� �������� s1 �� ���� 
{
	s1->num = 0; //s1 �� ���������� 
	int j;

	for (int i = 0; i < s2->num; i++)
	{
		for (j = 0; j < s3->num; j++)
		{
			if (s3->set[j] == s2->set[i])
				Add(s1, s2->set[i]);
		}
	}
	return s1; //s1 �ּҸ� ��ȯ 
}
IntSet* Difference(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2���� s3 ���� �������� s1 �� ���� 
{
	s1->num = 0; //s1 �� ���������� 
	int j;


	for (int i = 0; i < s2->num; i++)
	{
		for (j = 0; j < s3->num; j++)
			if (s3->set[j] == s2->set[i])  //������ ������ 
				break;

		if (j == s3->num)
			Add(s1, s2->set[i]);  //�߰� 
	}

	return s1; //s1 �ּҸ� ��ȯ 
}
void Print(const IntSet *s) // ���� ��� 
{
	printf("{ ");
	for (int i = 0; i < s->num; i++)
	{
		printf("%d ", s->set[i]);
	}
	printf("}\n");
}
void Terminate(IntSet *s)  //���� ����
{
	free(s->set);
	s->max = 0;
	s->num = 0;
}

int main()
{

	int menu, n, max,c;
	IntSet s1, s2, s3; // ���� 3�� �ʱ�ȭ
	printf("�ִ� ���� ���� ���� :");
	scanf("%d", &max);
	Init(&s1, 10);
	Init(&s2, 10);
	Init(&s3, 10);

	while (1)
	{
		printf("s1: ");
		Print(&s1);
		printf("s2: ");
		Print(&s2);
		printf("___Menu___\n");
		printf("(1)Add (2)Remove (3)Assign (4)Operation (0)Exit\n");
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
			printf("(0)s1���� s2�� ���� (1)s2���� s1�� ����:");
			scanf("%d", &c);
			if (!c)	Assign(&s2, &s1);
			else Assign(&s1, &s2);
			break;



		case 4:
			printf("Union : ");
			Union(&s3, &s1, &s2);
			Print(&s3);

			printf("Intersection : ");
			Intersection(&s3, &s1, &s2);
			Print(&s3);

			printf("Difference (s1-s2): ");
			Difference(&s3, &s1, &s2);
			Print(&s3);
			printf("Difference (s2-s1): ");
			Difference(&s3, &s2, &s1);
			Print(&s3);
			break;
		case 0:
			Terminate(&s1);
			Terminate(&s2);
			Terminate(&s3);
			return 0;
		default:
			break;
		}

	}
	
	return 0;
}