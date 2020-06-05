#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef int bool;

typedef struct queue
{
	int *arr;

	int front;
	int rear;

	int data;
}queue;
void initQueue(queue *que,int q)
{
	que->arr = (int*)calloc(q, sizeof(int));
	que->front = 0;
	que->rear = 0;
}
bool isEmpty(queue *que)
{
	return que->front == que->rear;
}
bool isFull(queue *que,int N)
{
	return que->front == (que->rear+1)%N;
}
void printQueue(queue *que, int N)
{
	for (int i = 0; i < N; i++)
		printf(" %d", que->arr[i]);
	printf("\n");
}
int enqueue(queue *que,int N,int data)
{
	if (isFull(que, N))
	{
		printf("overflow");
		printQueue(que,N);
		return -1;
	}
	que->rear = (que->rear + 1) % N;
	que->arr[que->rear] = data;
	return data;

}
int dequeue(queue *que, int N)
{
	int data;
	if (isEmpty(que))
	{
		printf("underflow\n");
		return -1;
	}
	data = que->front;
	
	que->front= (que->front + 1) % N;
	que->arr[que->front] = 0;
	return data;
}
int main()
{
	int q, n,data;
	char op;
	queue que;

	scanf("%d",&q);
	scanf("%d", &n);
	initQueue(&que, q);
	getchar();
	
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &op);
		
		switch (op)
		{
			case 'I':
				scanf("%d", &data);
				data = enqueue(&que, q, data);
				if (data == -1) return -1;
				break;
			case 'D':
				data = dequeue(&que, q);
				if (data == -1) return -1;
				break;
			case 'P':
				printQueue(&que, q);
				break;
			default:
				break;
		}
		getchar();
	}
	return 0;
}