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

	int size;

}List;

Node* alllocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void setNode(Node *n, Node* prev,Node *next,dataType data)
{
	n->prev = prev;
	n->next = next;
	n->data = data;
}

bool isValidPosition(List *list , index position)
{
	if (position > 0)
	{
		if (list->size >= position)
			return true;
		else return false;
	}
	return false;
}

void initializeList(List *list)
{
	list->head = alllocNode();
	list->tail = alllocNode();
	setNode(list->head, NULL, list->tail, 0);
	setNode(list->tail,list->head, NULL, 0);
	
	list->crnt = list->head;
	list->size = 0;
}
void setCurrentNode(List *list, index position)
{
	index i = 1;

	Node *ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (i == position)
		{
			list->crnt = ptr;
			return;
		}
		i++;
		ptr = ptr->next;
	}
}
void addItem(List *list, index position, dataType item)
{
	list->size++;
	if (!isValidPosition(list, position))
	{
		printf("invalid position\n");
		list->size--;
		return;
	}
	setCurrentNode(list, position - 1); // 해당 위치 앞에

	Node *new_node = alllocNode();
	Node *old_next_ptr = list->crnt->next;

	list->crnt->next = new_node;
	old_next_ptr->prev = new_node;

	setNode(new_node,list->crnt ,old_next_ptr, item);
	list->crnt = list->head;
}
void deleteItem(List *list, index position)
{
	if (!isValidPosition(list, position))
	{
		printf("invalid position\n");
		return ;
	}
	setCurrentNode(list, position);

	Node *del_p = list->crnt;

	del_p->prev->next = del_p->next;
	del_p->next->prev = del_p->prev;

	list->crnt = list->head;
	list->size--;

	free(del_p);
}
dataType getEntry(List *list, index position)
{
	if (!isValidPosition(list, position))
	{
		printf("invalid position\n");
		return 1;
	}
	setCurrentNode(list, position);
	return list->crnt->data;
}
void printList(List *list)
{
	if (list->size > 0)
	{
		Node *ptr = list->head->next;
		while (ptr != list->tail)
		{
			printf("%c", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	else
	{
		printf("invalid position\n");
	}
}
void terminateList(List *list)
{
	while (list->size !=0)
	{
		deleteItem(list, 1);
	}
	free(list->head);
	free(list->tail);
}
int main()
{

	List list;

	initializeList(&list);

	int n;
	char func;
	index idx;
	dataType data;

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		printList(&list);
		printf("___________________________\n");
		scanf("%c" ,&func);
		
		if (func == 'A')
		{
			scanf("%d %c", &idx, &data);
			addItem(&list, idx, data);
		}
		else if (func == 'D')
		{
			scanf("%d", &idx);
			deleteItem(&list, idx);
		}
		else if (func == 'P')
		{
			printList(&list);
		}
		else if (func == 'G')
		{
			scanf("%d", &idx);
			
			char k = getEntry(&list, idx);
			if(!(k==1))
			printf("%c\n", k);
		}
		getchar();
	}

	terminateList(&list);

	return 0;
}