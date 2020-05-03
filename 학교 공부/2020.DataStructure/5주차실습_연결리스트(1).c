#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;
typedef char dataType;
typedef int index;

typedef struct Node
{
	struct Node *prev;
	dataType data;
	struct Node *next;
}Node;
typedef struct List
{
	Node *head;
	Node *tail;
	Node *crnt;
}List;

Node* alllocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void setNode(Node *n, Node* prev, Node *next, dataType data)
{
	n->prev = prev;
	n->next = next;
	n->data = data;
}
int sizeOfList(const List *list)
{
	int cnt = 0;
	Node *ptr = list->head->next;
	while (ptr->next != NULL)
	{
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}
bool isEmpty(const List *list)
{
	if (list->head->next == list->tail) return true;
	else return false;
}
bool isValidPosition(const List *list, index pos)
{
	int size = sizeOfList(list);
	if (pos < 0 || size < pos) return false;
	else return true;
}

void setCurrentNode(List *list, index pos)
{
	if (isEmpty(list))
	{
		list->crnt = list->tail;
		return;
	}
	Node *ptr = list->head;
	for (index i = 0; i <= pos; ptr = ptr->next,i++)
	{
		list->crnt = ptr;
	}
}
void initializeList(List *list)
{
	list->head = alllocNode();
	list->tail = alllocNode();
	setNode(list->head, NULL, list->tail, 0);
	setNode(list->tail, list->head, NULL, 0);

	list->crnt = list->head;
}
void printList(const List *list)
{
	Node *ptr = list->head->next;
	if (!isEmpty(list))
	{
		while (ptr->next != NULL)
		{
			printf("%c", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void addData(List *list, index pos, dataType data)
{
	if (!isValidPosition(list, pos-1))
	{
		printf("invalid position\n");
		return;
	}

	setCurrentNode(list, pos);

	Node *new_node = alllocNode();
	Node *crnt_node = list->crnt->prev;
	
	crnt_node->next = new_node;
	list->crnt->prev = new_node;

	setNode(new_node, crnt_node, list->crnt, data);

}
void deleteData(List *list, index pos)
{
	if (!isValidPosition(list, pos))
	{
		printf("invalid position\n");
		return;
	}
	setCurrentNode(list, pos);

	Node *A = list->crnt->prev;
	Node *B = list->crnt->next;
	
	A->next = B;
	B->prev = A;

	free(list->crnt);

	list->crnt =list->head;

}
dataType getData(List *list, index pos)
{
	if (!isValidPosition(list, pos))
	{
		printf("invalid position\n");
		return -1;
	}

	setCurrentNode(list, pos);

	return list->crnt->data;
}

void terminateList(List *list)
{
	while (!isEmpty(list))
	{
		deleteData(list, 1);
	}
	list->crnt = NULL;
	free(list->head);
	free(list->tail);
}
int main()
{
	List list;
	index idx;
	int n;
	char func,data,r;

	initializeList(&list);

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &func);

		if (func == 'A')
		{
			scanf("%d %c", &idx, &data);
			addData(&list, idx, data);
		}
		else if (func == 'D')
		{
			scanf("%d", &idx);
			deleteData(&list, idx);
		}
		else if (func == 'P')
		{
			printList(&list);
		}
		else if (func == 'G')
		{
			scanf("%d", &idx);
			r = getData(&list, idx);
			if (r != -1)
				printf("%c\n", r);
			
			
		}
		getchar();

	}

	terminateList(&list);

	return 0;
}