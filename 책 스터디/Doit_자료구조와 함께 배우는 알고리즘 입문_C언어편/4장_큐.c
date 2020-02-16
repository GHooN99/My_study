#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 큐 와 스택 */

// 배열이동하는 큐 구현 
/*
typedef struct 
{
	int max; //최대 데이터
	int num; //현재 데이터
	int *que; // 첫 큐의 포인터

}ArrayIntQueue;

int init(ArrayIntQueue *q, int max)
{
	q->num = 0; //현재 데이터 개수 초기화
	q->que = (int*)calloc(max, sizeof(int)); //동적할당 
	if (q->que == NULL)
	{
		q->max = 0; // 접근 막음
		return -1;
	}
	q->max = max;
	return 0;
}
int Enque(ArrayIntQueue *q, int x)
{
	if (q->max <= q->num)	return -1;
	q->que[(q->num)++] = x;
	return 0;
}
int Deque(ArrayIntQueue *q, int *x)
{
	if (q->num <= 0) return -1;
	*x = q->que[0];
	for (int i = 0; i < q->num -1 ; i++)
	{
		q->que[i] = q->que[i + 1];
	}
	q->que[(q->num)--] = 0;
	return 0;

}
void print(ArrayIntQueue *q)
{
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[i]);
	printf("\n");
}
int main()
{
	ArrayIntQueue queue;
	int max,n,x;

	scanf("%d", &max);
	int c =  init(&queue, max);
	while (1)
	{
		printf("_________________\n");
		scanf("%d", &n);
		if (n == 0)	break;
		switch (n)
		{
		case 1:
			scanf("%d", &x);
			c = Enque(&queue, x);
			break;
		case 2:
			c = Deque(&queue, &x);
			break;
		case 3: 
			print(&queue);

		default:
			break;
		}

	}
	
	return 0;
}
*/

// 링 버퍼 (ring buffer) 로 큐 구현 

typedef struct
{
	int max;
	int num;
	int front;
	int rear;
	int *que;

}IntQueue;

int Init(IntQueue *q, int max)
{
	q->front = q->rear = q->num = 0; //현재 데이터 개수 초기화
	q->que = (int*)calloc(max, sizeof(int)); //동적할당 
	if (q->que == NULL)
	{
		q->max = 0; // 접근 막음
		return -1;
	}
	q->max = max;
	return 0;
}
int Enque(IntQueue *q, int x)
{
	if (q->max <= q->num)	return -1;
	q->num++;
	q->que[(q->rear)++] = x;
	if (q->rear == q->max)		//인덱스 넘어가기 방지 다시 0으로 되돌림
		q->rear = 0;
	return 0;
}
int Deque(IntQueue *q, int *x)
{
	if (q->num <= 0) return -1;
	q->num--;
	*x = q->que[(q->front)++];
	if (q->front == q->max)		//인덱스 초과 방지
		q->front = 0;

	return 0;
}
int Peek(IntQueue *q, int *x)
{
	if (q->num <= 0)	return -1;
	*x = q->que[q->front];
	return 0;
}
void Clear(IntQueue *q)
{
	q->front = q->rear = q->num = 0; // 초기화

}
int Capacity(const IntQueue *q)
{
	return q->max;
}
int Size(const IntQueue *q)
{
	return q->num;
}
int isEmpty(const IntQueue *q)
{
	return q->num == 0;
}
int isFull(const IntQueue *q)
{
	return q->num == q->max;
}
int Search(const IntQueue *q, int x)  //현재 인덱스 자체
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(i + (q->front)) % (q->max)] == x)
			return (i + (q->front)) % (q->max);
	}
	return -1;
}
int Search2(const IntQueue *q, int x)	//앞부터 상대적 위치
{
	
	for (int i = 0,idx=0; i < q->num; i++,idx++)
	{
		if (q->que[(i + (q->front)) % (q->max)] == x)
			return idx;
	}

	return -1;

}
void Print(const IntQueue *q)
{
	for (int i =0; i < q->num; i++)
		printf("%d ", q->que[(i+(q->front))%(q->max)]);
	printf("\n");
}
void Terminate(IntQueue *q)
{
	q->front = q->rear = q->num = 0;
	free(q->que);
}
int main()
{
	IntQueue queue;
	int max, menu,x,idx;

	printf("최대 데이터 값 :");
	scanf("%d", &max);

	if (Init(&queue, max) == -1)
	{
		printf("초기화 실패\n");
		return -1;
	}

	while (1)
	{
		printf("___________________\n");
		printf("현재 데이터 수 %d/%d\n", Size(&queue), Capacity(&queue));
		printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search1 (6)Search2 (7)Clear (0)Exit\nmenu :");
		scanf("%d", &menu);

		if (menu == 0)	break;

		switch (menu)
		{
			case 1:
				printf("데이터 :");
				scanf("%d", &x);
				if (Enque(&queue, x) == -1)
					printf("Enqueue Error\n");
				break;
			case 2:
				if( Deque(&queue, &x)==-1)
					printf("Deque Error\n");
				else
					printf("디큐한 데이터는 %d 입니다.\n", x);
				break;
			case 3:
				if (Peek(&queue,&x) == -1)
					printf("Peek Error\n");
				else
					printf("피크 데이터는 %d 입니다.\n", x);
				break;
			case 4:
				Print(&queue);
				break;
			case 5:
				printf("검색값 : ");
				scanf("%d", &x);
				idx = Search(&queue, x);
				if (-1 == idx)
					printf("검색 실패\n");
				else
					printf("%d는 인덱스 %d 에 존재합니다.\n", x, idx);
				break;
			case 6:
				printf("검색값 : ");
				scanf("%d", &x);
				idx = Search2(&queue, x);
				if (-1 == idx)
					printf("검색 실패\n");
				else
					printf("%d는 인덱스 %d 에 존재합니다.\n", x, idx);

				break;
			case 7:
				Clear(&queue);
				printf("큐 초기화\n");
				break;
			default:
				printf("다시입력\n");
				break;
		}

	}

	return 0;
}