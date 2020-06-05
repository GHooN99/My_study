#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef int bool;

typedef struct deque
{
	struct deque *prev;
	struct deque *next;
	int data;
}deque;

bool isEmpty(deque *front, deque *rear)
{
	return front == NULL && rear == NULL;
}
deque* allocNode()
{
	return (deque *)calloc(1, sizeof(deque));
}
void addFront(deque **front, deque **rear, int data)
{
	deque *new_node = allocNode();
	
	new_node->next = *front;
	
	if (*front == NULL) *rear = new_node;
	else (*front)->prev = new_node;

	*front = new_node;

	new_node->data = data;
}
void addRear(deque **front, deque **rear, int data)
{
	deque *new_node = allocNode();

	new_node->prev = *rear;

	if (*rear == NULL) *front = new_node;
	else (*rear)->next = new_node;

	*rear = new_node;

	new_node->data = data;
}
void deleteFront(deque **front, deque **rear)
{
	deque *ptr = (*front);
	if (*front == *rear)
		*front = *rear = NULL;
	else
	{
		(*front) = (*front)->next;
		(*front)->prev = NULL;
	}
	free(ptr);
}
void deleteRear(deque **front, deque **rear)
{
	deque *ptr = (*rear);
	if (*front == *rear)
		*front = *rear = NULL;
	else
	{
		(*rear) = (*rear)->prev;
		(*rear)->next = NULL;
	}
	free(ptr);
}
void printDeque(deque *front, deque *rear)
{
	deque *ptr = front;
	while (ptr != NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int main()
{
	deque *front=NULL, *rear = NULL;
	int n,data;
	char op[3];
	scanf("%d", &n);


	for (int i = 0; i < n; i++)
	{
		
		scanf("%s", op);
		if (strcmp(op, "AF") == 0)
		{
			scanf("%d", &data);
			addFront(&front, &rear, data);
		}
		else if (strcmp(op, "AR") == 0)
		{
			scanf("%d", &data);
			addRear(&front, &rear, data);
		}
		else if (strcmp(op, "DF") == 0)
		{
			if (isEmpty(front, rear))
			{
				printf("underflow");
				return -1;
			}
			deleteFront(&front, &rear);
		}
		else if (strcmp(op, "DR") == 0)
		{
			if (isEmpty(front, rear))
			{
				printf("underflow");
				return -1;
			}
			deleteRear(&front, &rear);
		}
		else if(strcmp(op,"P")==0)
		{
			printDeque(front, rear);
		}

	}

}