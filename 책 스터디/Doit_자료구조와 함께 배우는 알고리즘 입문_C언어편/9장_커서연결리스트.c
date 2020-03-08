#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

 /* Ŀ���� ���Ḯ��Ʈ ����� */

//�������� ũ�Ⱑ ũ�� ������ �ʰ� �ִ밳���� �˶� 
//�޸𸮸� ����� �����ϴ� ����� ���̱� ����

#define NULLCUR -1		//�� Ŀ��

typedef int Index;		// Ŀ���� �ڷ��� 

/* ��������Ʈ -> ����Ʈ�� �����ϸ� ������ ��迭�� ���� �ذ�� */
typedef struct Node
{
	int data;			//������
	Index next;			//���� ����� �ε��� 
	Index Dnext;		//���� ����Ʈ�� ���� ��� 

}Node;

typedef struct List
{
	Node *n;		//����Ʈ ��ü(�迭)
	Index head;		//�Ӹ����
	Index max;		//������� ���� ���ڵ�
	Index deleted;   //���� ����Ʈ�� �Ӹ����
	Index crnt;		//������ ���

}List;

Index getIndex(List *list) //������ ���ڵ��� �ε���
{
	if (list->deleted == NULLCUR) //�����Ұ��� ���°��
		return ++(list->max); //������� �����ε��� +1 ��ȯ
	else
	{
		Index rec = list->deleted; //��������Ʈ �Ӹ����
		list->deleted = list->n[rec].Dnext; //rec��° ������带 ���ο� ���� ����Ʈ�� �Ӹ���忡 ����
		return rec;
	}
}
void deleteIndex(List *list, Index idx) //���� ���ڵ带 ��������Ʈ�� ���
{
	if (list->deleted == NULLCUR) //�����Ұ��� ���°��
	{
		list->deleted = idx;		//������������ �Ӹ���带 idx ��
		list->n[idx].Dnext = NULLCUR;	//�������� �����
	}
	else
	{
		Index ptr = list->deleted;  //���� ��������Ʈ �Ӹ�
		list->deleted = idx; //��������Ʈ�� �Ӹ�
		list->n[idx].Dnext = ptr; // ��������Ʈ�� ���� ��� �� ���� �Ӹ��� 
	}
	
}

void setNode(Node *n, int data, Index next) //n�� ����Ű�� ����� �� ����
{
	n->data = data;
	n->next = next;
}
void Init(List *list, int size) // ����Ʈ �ʱ�ȭ
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULLCUR;
	list->crnt = NULLCUR;
	list->deleted = NULLCUR;
	list->max = NULLCUR;
}
void insertFront(List *list, int data)
{
	Index ptr=list->head;
	list->head = list->crnt = getIndex(list); //���ο� �Ӹ���� �� ���� (������ ptr �� �̾�����)
	setNode(&(list->n[list->head]), data, ptr); //����� �� ���� 

}
void insertRear(List *list, int data)
{
	if (list->head == NULLCUR) //������ �տ���
		insertFront(list, data);
	else
	{
		Index ptr = list->head; // �Ӹ� ���� 
		while (list->n[ptr].next!=NULLCUR) //���� ��尡 ������ �ƴҶ�����
		{
			ptr = list->n[ptr].next;
		}
		//ptr�� ����
		list->n[ptr].next = list->crnt = getIndex(list); //�ڿ� ���� 
		setNode(&(list->n[list->n[ptr].next]), data, NULLCUR); // ��� ���� 
	}
}
void removeFront(List *list)
{
	if (list->head != NULLCUR) //�����Ұ��� ������
	{
		Index ptr = list->n[list->head].next; // �Ӹ� ���� ��� ���� 
		deleteIndex(list, list->head); //�Ӹ���� ����
		list->head = list->crnt = ptr; // �ٽ� ���� 
	}

}
void removeRear(List *list)
{
	if (list->n[list->head].next == NULLCUR) //��尡 1����
		removeFront(list); 
	else
	{
		Index ptr = list->head; // �Ӹ� ���� 
		Index pre; //���� �� ���� 
		while (list->n[ptr].next != NULLCUR) //���� ��尡 ������ �ƴҶ�����
		{
			pre = ptr;
			ptr = list->n[ptr].next;
		}
		//ptr�� ���� pre �� ������
		list->n[pre].next = NULLCUR;		//���� ����
		deleteIndex(list, ptr); //���� 
		list->crnt = pre;
	}
}
void removeCurrent(List *list)
{
	if (list->crnt != NULLCUR)
	{
		Index ptr = list->head;
		while (list->n[ptr].next != list->crnt)
		{
			ptr = list->n[ptr].next;
		}
		list->n[ptr].next = list->n[list->crnt].next; //���� ���� ��� �� ���缱�� �������� �̾��ֱ� 
		deleteIndex(list, list->crnt);
		list->crnt = ptr;
	}
}
void Clear(List *list)
{
	while (list->head != NULLCUR) // �Ӹ���尡 ����������
	{
		removeFront(list); //�ճ�� ����
	}
	list->crnt = NULLCUR;
}
void printList(const List *list) //��� ��� ���
{
	if (list->head == NULLCUR)
		printf("Empty !!\n");
	else
	{
		Index ptr = list->head;
		printf("[ ");
		while (ptr != NULLCUR)
		{
			printf("%d, ", list->n[ptr].data); //��� �� ���� ����
			ptr = list->n[ptr].next;
		}
		printf("]\n");
	}

}
Index Search(List *list, int data)
{
	Index idx=0;
	Index ptr = list->head;
	while (list->n[ptr].next!=NULLCUR)
	{
		if (list->n[ptr].data == data)
		{
			list->crnt = list->n[ptr].next;
			return idx;
		}
		ptr = list->n[ptr].next;
		idx++;
	}
	return NULLCUR; //�˻� ����
}
void terminate(List *list) //����
{
	Clear(list);
	free(list->n);
}

int main()
{
	int menu, x, idx;

	List list;
	Init(&list,15);
	while (1)
	{
		printList(&list);
		printf("__________________________________________________________\n");
		printf("(1)insertFront (2)insertRear (3)removeFront (4)removeRear\n");
		printf("(5)removeCurrent (6)Clear (7)Search (0)Exit\n");
		printf("Menu :");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("Data :");
			scanf("%d", &x);
			insertFront(&list, x);
			break;
		case 2:
			printf("Data :");
			scanf("%d", &x);
			insertRear(&list, x);
			break;
		case 3:
			removeFront(&list);
			break;
		case 4:
			removeRear(&list);
			break;
		case 5:
			removeCurrent(&list);
			break;
		case 6:
			Clear(&list);
			break;
		case 7:
			printf("Data :");
			scanf("%d", &x);
			idx = Search(&list, x);
			if (idx != -1)
				printf("%d's idx : %d\n", x, idx);
			else
				printf("Fail\n");
			break;
		case 0:
			terminate(&list);
			return 0;

		default:
			break;
		}
	}
	return 0;
}