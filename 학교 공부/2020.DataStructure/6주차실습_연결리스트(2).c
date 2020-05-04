#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

typedef struct Node
{
	int coef;
	int exp;
	struct Node *next;
}Node;

typedef struct List
{
	Node *head;
	Node *crnt;
}List;

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void setNode(Node *n, int coef,int exp, Node *next) //n이 가리키는 노드의 값 설정
{
	n->next = next;
	n->coef = coef;
	n->exp = exp;
}
void initializeList(List *list)
{
	list->head = allocNode();
	setNode(list->head, 0, 0, NULL);
	list->crnt = list->head;
}
void addLast(List *list, int coef, int exp)
{
	Node *new_node = allocNode();
	Node *ptr=list->head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new_node;
	
	setNode(new_node, coef, exp, NULL);

}
void printList(List *list)
{
	Node *ptr = list->head->next;
	while (ptr!=NULL)
	{
		printf(" %d %d", ptr->coef, ptr->exp);
		ptr = ptr->next;
	}
}
void addPoly(List *list1, List *list2,List *list3)
{
	Node *ptr1 = list1->head->next;
	Node *ptr2 = list2->head->next;

	while (ptr1!=NULL && ptr2!=NULL)
	{
		if (ptr1->exp > ptr2->exp)
		{
			addLast(list3, ptr1->coef, ptr1->exp);
			ptr1 = ptr1->next;
		}
		else if (ptr1->exp < ptr2->exp)
		{
			addLast(list3, ptr2->coef, ptr2->exp);
			ptr2 = ptr2->next;
		}
		else
		{
			int sum_coef = ptr1->coef + ptr2->coef;
			if(sum_coef!=0)
				addLast(list3, sum_coef, ptr1->exp);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	while (ptr1 != NULL)
	{
		addLast(list3, ptr1->coef, ptr1->exp);
		ptr1 = ptr1->next;
	}
	while (ptr2 != NULL)
	{
		addLast(list3, ptr2->coef, ptr2->exp);
		ptr2 = ptr2->next;
	}

}
int main()
{
	List *list;
	int n1, n2;
	int coef, exp;
	list = (List*)calloc(3, sizeof(List));

	for (int i = 0; i < 3; i++)
		initializeList(list + i);

	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d %d", &coef,&exp);
		addLast(list, coef, exp);
	}

	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		scanf("%d %d", &coef, &exp);
		addLast(list+1, coef, exp);
	}


	addPoly(list, list + 1,list+2);
	

	printList(list + 2);

	return 0;
}
