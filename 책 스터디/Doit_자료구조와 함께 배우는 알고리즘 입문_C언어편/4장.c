#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ���ð� ť */
//���� 

// int �� ���� ���� 

typedef struct IntStack
{
	int max;		//���� �뷮
	int ptr;		//���� ������ 
	int *stk;		//���� ù��� ������

}IntStack;

int init(IntStack *s, int max);	//���� �ʱ�ȭ
int Push(IntStack *s, int x);	// Ǫ��
int Pop(IntStack *s, int *x);	// ��
int Peek(const IntStack *s, int *x); //��ũ
void Clear(IntStack *s); //���ú���
int Capacity(const IntStack *s); //���� �ִ�뷮
int Size(const IntStack *s); //������ ����
int isEmpty(const IntStack *s);	//���� ����ִ��� 
int isFull(const IntStack *s);	//���� ���ִ��� 
int Search(const IntStack *s,int x);	//���� �˻�
void Print(const IntStack *s); //��� ������ ���
void Terminate(IntStack *s); // ��������

int main()
{
	IntStack stack;
	int max,idx,menu, x;;
	printf("�ִ� ���� ���� :");
	scanf("%d", &max);
	if (init(&stack, max) == -1)
	{
		printf("���� ���� ����\n");
		return -1;
	}
	while (1)
	{
		
		printf("_______________________\n");
		printf("���� ������ �� : %d /%d \n",stack.ptr,stack.max);
		printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear (6)Search (0)Exit\n�Է� :");
		scanf("%d", &menu);

		if (0 == menu) break;

		switch (menu)
		{
			case 1:
				printf("�Է� :");
				scanf("%d", &x);
				if(Push(&stack, x)==-1)
					printf("����\n");
				else
					printf("%d �� push �߽��ϴ�.\n", x);
				break;
			case 2:
				if (Pop(&stack, &x) == -1)
					printf("����\n");
				else
					printf("%d �� pop �߽��ϴ�.\n", x);
				break;
			case 3:
				if (Peek(&stack, &x) == -1)
					printf("����\n");
				else
					printf("peek �����ʹ� %d �Դϴ�.\n", x);
				break;
			case 4:
				printf("���� ������ : ");
				Print(&stack);
				break;
			case 5:
				Clear(&stack);
				printf("������ ������ϴ�.\n");
				break;
			case 6:
				printf("�˻��� ���� �Է� :");
				scanf("%d", &x);
				idx = Search(&stack, x);
				if (idx >= 0)
					printf("%d��°�� ��ġ�մϴ�.\n", idx + 1);
				else
					printf("�˻� ����\n");
				break;

			default:
				break;
		}

	}
	printf("���� \n");
	Terminate(&stack);

	return 0;
}
int init(IntStack *s, int max)	//���� �ʱ�ȭ
{
	s->ptr = 0; //������ ���� �ʱ�ȭ
	s->stk = (int*)calloc(max, sizeof(int));   //max ���� �迭 ���� 

	if (s->stk == NULL)
	{
		s->max = 0;  //�ٸ� �Լ� ���� �������� 
		return -1; // �Ҵ� ���� Ȯ��
	}
	s->max = max; //�ִ밪 �ʱ�ȭ 
	return 0; //���� ���� 
}
int Push(IntStack *s, int x)	// Ǫ��
{
	if (s->ptr >= s->max) return -1; //������ �����Ҷ�
		s->stk[(s->ptr)++] = x; //s[]���� x���� �� ��Ұ��� ����  
	return 0; //���� ���� 

}
int Pop(IntStack *s, int *x)// ��
{
	if (s->ptr <= 0) return -1; //������ ����
	*x = s->stk[--(s->ptr)];	//�� ���� �ִ°��� ���� 
	return 0;
}
int Peek(const IntStack *s, int *x) //��ũ ������� �����͸� ������ 
{
	if (s->ptr <= 0) return -1; //������ ����
	
	*x = s->stk[s->ptr - 1];

	return 0;
}
void Clear(IntStack *s) //���ú���
{
	s->ptr = 0; // ��� ���� 0���� 
}
int Capacity(const IntStack *s) //���� �ִ�뷮
{
	return s->max;   //�ִ밪 ��ȯ
}
int Size(const IntStack *s) //������ ����
{
	return s->ptr; //���� ��ȯ 
}
int isEmpty(const IntStack *s)//���� ����ִ���
{
	if (s->ptr <= 0) return 1;
	return 0;
}
int isFull(const IntStack *s)	//���� ���ִ��� 
{
	if (s->ptr >= s->max) return 1;
	return 0;
}
int Search(const IntStack *s, int x)	//���� �˻�
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x) return i;		//�ε��� ��ȯ
	}
	return -1;
}
void Print(const IntStack *s) //��� ������ ���
{
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);
	printf("\n");
}
void Terminate(IntStack *s) // ��������
{
	if (s->stk != NULL)
		free(s->stk);

	s->max = s->ptr = 0;
	
}