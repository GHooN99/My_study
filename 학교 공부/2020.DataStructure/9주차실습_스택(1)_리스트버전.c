#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack   //���� ����ü
{
	char data;   // ������
	struct stack *next;  // ���� ����� �ּ� �̱� ����Ʈ 
}stack;  // ���� ����ü ����

typedef int bool;  // ���� ������

bool isEmpty(stack *s)  // ���� ������� Ȯ�� 
{
	return s->next == NULL;   //������ �ۿ� ������ �� ����
}
void Swap(char *x, char *y)  //�����Լ�
{
	char tmp = *x;  //�ӽú���
	*x = *y;   //���� �ٲٱ�
	*y = tmp;  // ���� �ٲٱ�
}
int Size(stack *s)   //������ ũ�� �Լ�
{
	int cnt = 0;  // ���� �ʱ�ȭ
	stack *ptr = s->next;  // ������ Ž������ �ʱ�ȭ
	while (ptr != NULL)  //���� ������ Ž��
	{
		ptr = ptr->next;  // ���� ����
		cnt++;  //ũ�� ����
	}
	return cnt;  // ũ�� ��ȯ 

}
stack* allocNode()   // ��� �Ҵ� �Լ�
{
	return (stack*)calloc(1, sizeof(stack));  // 1�� ��� �Ҵ�
}
void initStack(stack **s, int n)  // ���� �ʱ�ȭ �Լ�
{
	(*s) = allocNode();   // ������ �Ҵ�
	(*s)->next = NULL;  //������ �ʱ�ȭ
}
void Push(stack **s, int n, char data)   //Ǫ�� �Լ�
{
	if (Size(*s) == n)  // ����� �ִ��϶�
	{
		printf("Stack FULL\n");  //�޽������ 
		return; // ����
	}
	stack *ptr = (*s)->next;		//��� ���� ������ ����
	stack *new_node = allocNode();  // ���ο� ��� �Ҵ� 

	(*s)->next = new_node;  // �Ǿտ� ���ο� ��� ����
	new_node->next = ptr;   // ���ο� ��� ���� ��带 ���� 
	new_node->data = data;  //�����͸� ����

}
char Pop(stack **s)   //�� �Լ� 
{
	if (isEmpty(*s))  // �� �����̸� 
	{
		printf("Stack Empty\n");  //�޽��� ��� 
		return (char)NULL;  // �Լ�����
	}
	
	stack *ptr = (*s)->next;   // �ӽ� ������ ����
	char data = ptr->data;   // ������ ����  
	(*s)->next = ptr->next;   // �Ǿ� ��� ���� ����
	free(ptr);  // �Ҵ� ����

	return data;  // ������ ��ȯ 
}
void Peek(stack *s) //��ũ �Լ� 
{
	if (isEmpty(s))   // �����̸� 
	{
		printf("Stack Empty\n"); // �޽��� ��� 
		return; //����
	}
	printf("%c", s->next->data);  // ������ �ִ� �����͸� ��� 
}
void Duplicate(stack **s, int n)   // ���� �Լ� 
{
	if (Size(*s) == n)  //������ �������� 
	{
		printf("Stack FULL\n"); // �޽��� ��� 
		return;   // ���� 
	}

	char data;   // ��������
	data = Pop(s);  // ���� ������ ���� 
	if (data != (char)NULL)   //���������� �����͸� �޾����� 
	{
		Push(s, n, data);    // ���� �����ͷ� Ǫ�� 2�� 
		Push(s, n, data);
	}
}
void upRotate(stack **s, int n)   // ȸ�� �Լ� 
{
	if (n > Size(*s)) return;   // ũ�⺸�� ũ�� ����

	stack *ptr = (*s)->next;   //�ӽ� ������ ����

	for (int i = 0; i < n - 1; i++)   //n-1���ݺ�
	{
		Swap(&(ptr->data), &(ptr->next->data));   //�� �� �����ͺ��� ���� ���� �����͸� �ٲ� �����͸� n-1�� ���� 
		ptr = ptr->next;   //���� ���� 
	}
}
void downRotate(stack **s, int n,int k)   // ȸ���Լ�
{
	char data;  // �����ͺ���
	stack *ptrprev=NULL;  // �ӽú��� ���� ����� �ּ� 
	if (n > Size(*s)) return;   // ũ�⺸�� ũ�� ���� 

	stack *ptr = (*s);   // �ӽ� ������ ����
	for (int i = 0; i < n; i++) //n�� �ݺ� ���̳��� ptr�� n��° ��带 ����Ű������
	{
		ptrprev = ptr;  // ���� ����� �ּ� ���� 
		ptr = ptr->next;  // ���� ����� �ּ� ���� 
	}
	ptrprev->next = ptr->next;  // n��° ��� ��������
	data = ptr->data;		//n��° ��� ������ ���� 
	free(ptr);  // �Ҵ� ����
	Push(s, k, data);  //n��° ��带 Ǫ���ؼ� ������ 
}
void printStack(stack *s)  // ���� ��� �Լ�
{
	stack *ptr = s->next;  // �ӽ� Ž�� �����ͺ���
	while (ptr!=NULL)   //���� ������ Ž��
	{
		printf("%c", ptr->data);  //������ ��� 
		ptr = ptr->next;		// ���� ���� 
	}
	printf("\n");  //����
}


int main()		//�����Լ�
{
	stack *st;		//���� ����
	char op[7];    //���� ���� 

	int n, m;   // ���� ���� 
	char data;
	scanf("%d", &n);   //�ִ� ũ�� ���� 
	initStack(&st, n);   //���� �ʱ�ȭ
	scanf("%d", &m);  //�ݺ� Ƚ�� ���� 

	getchar();  //����

	for (int i = 0; i < m; i++)  //m�� �ݺ� 
	{
		scanf("%s", op);  // �������� �Է� 
		getchar();
		if (strcmp(op, "POP") == 0)   //pop�̸� 
		{
			data = Pop(&st);  //���Լ� ȣ�� 
		}
		else if (strcmp(op, "PUSH") == 0)  //push �̸���� 
		{
			scanf("%c", &data); //������ �Է� 
			Push(&st, n, data);  //push �Լ� ȣ�� 
		}
		else if (strcmp(op, "PRINT") == 0)  // print �̸� 
		{
			printStack(st);  //����Լ� ȣ�� 
		}
		else if (strcmp(op, "PEEK") == 0)   //peek �̸� 
		{
			Peek(st);  //peek�Լ� ȣ�� 
		}
		else if (strcmp(op, "DUP") == 0)  //dup�̸� 
		{
			Duplicate(&st, n);  //dup �Լ� ȣ�� 
		}
		else if (strcmp(op, "UpR") == 0)  //upr �̸� 
		{
			int k;  //��ġ�Է�
			scanf("%d", &k); 
			upRotate(&st, k); // �Լ�ȣ�� 
		}
		else if (strcmp(op, "DownR") == 0)  //downr�̸� 
		{
			int k;  //��ġ�Է� 
			scanf("%d", &k);  
			downRotate(&st, k,n); // �Լ�ȣ�� 
		}
	}
	return 0;  //���� 
}