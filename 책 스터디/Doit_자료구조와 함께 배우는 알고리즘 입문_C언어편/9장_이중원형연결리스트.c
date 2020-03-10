#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/* ���� ���� ����Ʈ */
// ��������� ���� ��尡 NULL ���� �ƴ� �Ӹ������ �ּҸ� ���´�
/* ���� ���� ����Ʈ*/
// �ܹ����϶� ������ ã�� ������ �� ���� ��带 ã�� ���� ���� ����


/* ���� ���� ���� ����Ʈ */
typedef int bool;
typedef int Index;
typedef struct Node
{
	int data; //������
	struct Node *next; // ���� ����� �ּ�
	struct Node *prev; // ���� ����� �ּ� 
}Node;

typedef struct List
{
	Node *head; // �Ӹ������ �ּ�
	Node *crnt; // ���� ���� ����� �ּ�
}List;

Node* allocNode(void) //��� �����Ҵ� 
{
	return calloc(1, sizeof(Node));
}
void setNode(Node *n, int data ,Node *prev, Node *next) //n�� ����Ű�� ����� �� ����
{
	n->data = data;
	n->next = next;
	n->prev = prev;
}
void Init(List *list) //����Ʈ �ʱ�ȭ
{
	Node *tmp = allocNode();
	list->head = tmp;
	list->crnt = tmp;
	tmp->next = tmp->prev = tmp;		// �ڱ� �ڽ��� ����Ű�� ���� ��� ���� 
}
bool isEmpty(const List *list)
{
	return (list->head == list->head->next);
}
void insertAfter(List *list, Node *p, int data) // p �� ����Ű�� ���� ��忡 ��� ����
{
	Node *ptr = allocNode();
	Node *nxt = p->next;  
	p->next = p->next->prev = ptr; //����� ����
	setNode(ptr, data, p, nxt);		// ���� ��� ���� 
	list->crnt = ptr;		//���� ��� ����
}
void insertFront(List *list, int data)
{
		insertAfter(list, list->head, data);
}
void insertRear(List *list, int data)
{
		insertAfter(list, list->head->prev, data);
}
void Remove(List *list, Node *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head) //�����ϰ� ������ ������
		list->crnt = list->head->next;
}
void removeFront(List *list)
{
	if (!isEmpty(list))
		Remove(list, list->head->next);
}
void removeRear(List *list)
{
	if (!isEmpty(list))
		Remove(list, list->head->prev);
}
void removeCurrent(List *list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}
void Clear(List *list)
{
	while (!isEmpty(list))
		removeFront(list);
}
Index Search(List *list, int data)
{
	Index idx=0;
	Node *ptr = list->head->next;
	while (list->head != ptr)
	{
		if (ptr->data == data)
		{
			list->crnt = ptr;
			return idx;
		}
		ptr = ptr->next;
		idx++;
	}
	return -1;
}
void printList(const List *list) //��� ��� ���
{
	if (isEmpty(list)) 
		printf("Empty !!\n");
	else
	{
		Node *ptr = list->head->next;
		printf("[ ");
		do
		{
			printf("%d, ", ptr->data); //��� �� ���� ����
			ptr = ptr->next;
		} while (ptr != list->head); // �ѹ��� ���� 
		printf("]\n");
	}
}
void printReverse(const List *list)
{
	if (isEmpty(list))
		printf("Empty !!\n");
	else
	{
		Node *ptr = list->head->prev;
		printf("[ ");
		do
		{
			printf("%d, ", ptr->data); //��� �� ���� ����
			ptr = ptr->prev;
		} while (ptr != list->head); // �ѹ��� ���� 
		printf("]\n");
	}

}
void Terminate(List *list)
{
	Clear(list);
	free(list->head); //���̳�� ����
}
int main()
{
	int menu, x, idx;

	List list;
	Init(&list);
	while (1)
	{
		printList(&list);
		printf("Reverse :");
		printReverse(&list);
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
			Terminate(&list);
			return 0;

		default:
			break;
		}
	}
	return 0;
}
