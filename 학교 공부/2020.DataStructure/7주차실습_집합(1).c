#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef int bool;

typedef struct Node
{
	struct Node *next;
	int data;
}Node;


bool isEmpty(Node *set)
{
	return set->data == 0;
}
Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void setNode(Node *n, int data, Node *next)
{
	n->next = next;
	n->data = data;
}
void addData(Node **set, int data)
{
	if (isEmpty(*set))
	{
		setNode(*set,data,NULL);
		return;
	}

	Node *ptr=*set;
	Node *new_node = allocNode();

	while (ptr->next != NULL)
		ptr = ptr->next;
	
	ptr->next = new_node;
	setNode(new_node, data, NULL);

}
bool isMember(Node *set, int data)
{
	if (isEmpty(set))
		return false;

	Node *ptr = set;
	while (1)
	{
		if (ptr->data < data)
		{
			if (ptr->next == NULL)
				return false;
			else
				ptr = ptr->next;
		}
		else if (ptr->data > data)
			return false;
		else
			return true;
	}
}
int subset(Node **set1, Node **set2)
{
	int min=999,subset=1;
	if (isEmpty(*set1))
		return 0;
	Node *ptr = *set1;
	while (1)
	{
		if (isMember(*set2, ptr->data))
		{
			if (ptr->next == NULL)
			{
				if (subset) return 0;
				else return min;
			}
			else
				ptr = ptr->next;
		}
		else
		{
			subset = 0;
			if (min > ptr->data)
				min = ptr->data;
			if (ptr->next == NULL)
				return min;
			ptr = ptr->next;
		}
	}
}

int main()
{
	int n1, n2;
	int data;
	Node *set1, *set2;
	set1 = allocNode();
	set2 = allocNode();
	set1->data = 0;
	scanf("%d", &n1);
	
	for (int i = 0; i < n1; i++)
	{
		scanf("%d",&data);
		addData(&set1, data);
	}
	scanf("%d", &n2);

	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &data);
		addData(&set2, data);
	}
	
	printf("%d",subset(&set1, &set2));

	return 0;
}