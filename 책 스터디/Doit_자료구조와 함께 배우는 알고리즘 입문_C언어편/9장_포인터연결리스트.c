#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/*������ ���� ���� ����Ʈ*/

// int �� �迭 

typedef struct Node
{
	int data; //������
	struct Node *next; // ���� ����� �ּ�
}Node;

typedef struct List
{
	Node *head; //�Ӹ������ �ּ�
	Node *crnt; // ���� ���� ����� �ּ�
}List;

Node* allocNode(void) //��� �����Ҵ� 
{
	return calloc(1, sizeof(Node));
}
void setNode(Node *n, int data, Node *next) //n�� ����Ű�� ����� �� ����
{
	n->data = data;
	n->next = next;
}
void Init(List *list) //����Ʈ �ʱ�ȭ
{
	list->head = NULL; 
	list->crnt = NULL;
}
void insertFront(List *list, int data)  //�Ӹ��� ��带 ����
{
	Node *ptr = list->head;  //������ �Ӹ���尡 ����Ű�°� ����
	list->head = list->crnt = allocNode(); //���ο� ��� �Ӹ���忡 �Ҵ� 
	setNode(list->head, data, ptr); //���ο� �Ӹ���� �� ���� (������ ptr �� �̾�����)
}
void insertRear(List *list, int data) //������ ��带 ����
{
	Node *ptr;
	if (list->head == NULL) //����Ʈ�� ����ִ°�� �տ� ����
		insertFront(list, data);
	else
	{
		ptr = list->head; //�Ӹ������ �ּ�
		while (ptr->next !=NULL) //������� �ּҰ� NULL��(�̸� ����) �ƴҶ� ����
		{
			ptr = ptr->next; 
		}
		ptr->next = list->crnt = allocNode(); //������忡 �� ��� �Ҵ� 
		setNode(ptr->next, data, NULL); //���ο� ���� ��� ����
	}
}
void removeFront(List *list) //�Ӹ���� ����
{
	if (list->head != NULL) // ��尡�����ϸ�
	{
		Node *ptr = list->head->next; //�ι�° ����� �ּ�
		free(list->head); //�Ҵ� ����
		list->head = list->crnt = ptr; //�ι�° �ּҿ� ����
	}
}
void removeRear(List *list) // ������� ����
{
	Node *ptr,*pre=NULL;
	if (list->head != NULL) //�����Ұ��� ������
	{
		if (list->head->next == NULL) //1���� ������ �Ӹ� ����
			removeFront(list);
		else
		{
			ptr = list->head; //�Ӹ������ �ּ�
			while (ptr->next != NULL) //������� �ּҰ� NULL��(�̸� ����) �ƴҶ� ����
			{
				pre = ptr; //�����Ǳ� �� ��� �ּ�
				ptr = ptr->next;
			}
			
			free(ptr); //������� �Ҵ� ����
			pre->next = NULL; //������ ���� ����
			list->crnt = pre; // ����  ���ó��� ����
		}
	}
}
void removeCurrent(List *list) //���� ��带 ����
{
	if (list->crnt == list->head) //�Ӹ�����̸� �Ӹ���� ����
		removeFront(list);
	else
	{
		Node *ptr = list->head;
		while (ptr->next!=list->crnt) //������ ���ó�� ������
		{
			ptr = ptr->next;
		}
		ptr->next = list->crnt->next; //������� �����ּҿ� ���ó���� �����ּ� ����
		free(list->crnt);
		list->crnt = ptr; //���� ���ó�带 �� (��)����
	}
}
void Clear(List *list) //��� ��� ����
{
	while (list->head=NULL) // �Ӹ���尡 ����������
	{
		removeFront(list); //�ճ�� ����
	}
	list->crnt = NULL;
}
void printList(const List *list) //��� ��� ���
{
	if (list->head == NULL)
		printf("Empty !!\n");
	else
	{
		Node *ptr=list->head;
		printf("[ ");
		while (ptr!=NULL)
		{
			printf("%d, ", ptr->data); //��� �� ���� ����
			ptr = ptr->next;
		}
		printf("]\n");
	}

}
void terminate(List *list) //����
{
	Clear(list);
}
int Search(List *list, int data) //������ �˻�
{
	Node *ptr = list->head;
	int idx = 0;
	while (ptr!=NULL) //����������
	{
		if (ptr->data == data)
		{
			list->crnt = ptr; //ã�� ��带 ���� ���ó��� ��
			return idx;
		}
		ptr = ptr->next;
		idx++;
	}
	return -1; //ã�� ����
}
int main()
{
	int menu, x,idx;

	List list;
	Init(&list);
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
				idx=Search(&list, x);
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

