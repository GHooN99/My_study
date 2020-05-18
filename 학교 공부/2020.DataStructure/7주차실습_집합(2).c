#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	struct Node *next;
	int data;
}Node;

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void setNode(Node *n, int data, Node *next)
{
	n->next = next;
	n->data = data;
}
Node* initSet(Node **head)
{
	*head = allocNode();
	setNode(*head, 0, NULL);
	return *head;
}
int Size(Node *set)
{
	int cnt = 0;
	Node *ptr = set->next;
	while (ptr != NULL)
	{
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}
void addData(Node **set, int data)
{
	Node *ptr = *set;
	Node *new_node = allocNode();

	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = new_node;
	setNode(new_node, data, NULL);
}
int getData(Node *set, int pos)
{
	Node *ptr = set->next;
	int i = 1;
	while (ptr != NULL)
	{
		if (i == pos)
			return ptr->data;
		ptr = ptr->next;
		i++;
	}
	return ptr->data;
}
void printSet(Node *set)
{
	Node *ptr = set->next;
	while (ptr!=NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
Node* Union(Node *setA, Node *setB)
{
	Node *new_node;
	new_node = initSet(&new_node);
	int lenSetA = Size(setA);
	int lenSetB = Size(setB);

	if (lenSetA == 0)
		return setB;
	else if (lenSetB == 0)
		return setA;
	else if (lenSetA == 0 && lenSetB == 0)
		return new_node;

	int i = 1, j = 1;
	int a, b;
	while (lenSetA>=i && lenSetB>=j)
	{
		a = getData(setA, i);
		b = getData(setB, j);
		if (a < b)
		{
			addData(&new_node, a);
			i++;
		}
		else if (a > b)
		{
			addData(&new_node, b);
			j++;
		}
		else
		{
			addData(&new_node, a);
			i++;
			j++;
		}
	}
	
	while (lenSetA >= i)
	{
		a = getData(setA, i);
		addData(&new_node, a);
		i++;
	}
	while (lenSetB >= j)
	{
		b = getData(setB, j);
		addData(&new_node, b);
		j++;
	}
	return new_node;
}
Node* Intersect(Node *setA, Node *setB)
{
	Node *new_node;
	new_node = initSet(&new_node);
	int lenSetA = Size(setA);
	int lenSetB = Size(setB);

	if (lenSetA == 0 || lenSetB == 0)
		return new_node;

	int i = 1, j = 1;
	int a, b;
	while (lenSetA >= i && lenSetB >= j)
	{
		a = getData(setA, i);
		b = getData(setB, j);
		if (a < b)
			i++;
		else if (a > b)
			j++;
		else
		{
			addData(&new_node, a);
			i++;
			j++;
		}
	}
	return new_node;
}

int main()
{
	int n1, n2;
	int data;
	Node *set1, *set2;
	Node *uni, *itrsct;

	set1 = initSet(&set1);
	set2 = initSet(&set2);

	scanf("%d", &n1);

	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &data);
		addData(&set1, data);
	}
	scanf("%d", &n2);

	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &data);
		addData(&set2, data);
	}

	uni = Union(set1,set2);
	itrsct = Intersect(set1,set2);

	if (Size(uni) != 0)
		printSet(uni);
	else
		printf("0");

	printf("\n");

	if (Size(itrsct) != 0)
		printSet(itrsct);
	else
		printf("0");

	return 0;
}