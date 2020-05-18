#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef struct stack
{
	char *head;
	int cur;
}stack;

typedef int bool;

bool isEmpty(stack *s)
{
	return s->cur == -1;
}
void Swap(char *x, char *y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
int Size(stack *s)
{
	return s->cur + 1;
}
void initStack(stack *s,int n)
{
	s->head = (char*)calloc(n, sizeof(char));
	s->cur = -1;
}
void Push(stack *s, int n,char data)
{
	if (Size(s)==n)
	{
		printf("Stack FULL\n");
		return;
	}
	s->head[++(s->cur)] = data;
}
char Pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Empty\n");
		return (char)NULL;
	}
	char data = s->head[s->cur--];

	return data;
}
void Peek(stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Empty\n");
		return;
	}
	printf("%c", s->head[s->cur]);
}
void Duplicate(stack *s,int n)
{
	if (Size(s) == n)
	{
		printf("Stack FULL\n");
		return;
	}

	char data;
	data=Pop(s);
	if (data != (char)NULL)
	{
		Push(s, n, data);
		Push(s, n, data);
	}
}
void upRotate(stack *s,int n)
{
	if (n > Size(s)) return;
	for (int i = 0,j = 0; i < n-1; i++,j++)
	{
		Swap(&(s->head[(s->cur-j)]), &(s->head[(s->cur - j-1)]));
	}

}
void downRotate(stack *s ,int n)
{
	if (n > Size(s)) return;
	for (int i = 0, j = 0; i < n - 1; i++, j++)
	{
		Swap(&(s->head[(s->cur-n+j+1)]), &(s->head[(s->cur - n +j+2)]));
	}
}
void printStack(stack *s)
{
	for (int i = s->cur;i>=0; i--)
		printf("%c", s->head[i]);
	printf("\n");
}


int main()
{
	stack st;
	char op[7];

	int n,m;
	char data;
	scanf("%d", &n);
	initStack(&st, n);
	scanf("%d", &m);

	getchar();

	for (int i = 0; i < m; i++)
	{
		scanf("%s", op);
		getchar();
		if (strcmp(op, "POP")==0)
		{
			data = Pop(&st);
		}
		else if (strcmp(op, "PUSH")==0)
		{
			scanf("%c", &data);
			Push(&st, n, data);
		}
		else if (strcmp(op, "PRINT")==0)
		{
			printStack(&st);
		}
		else if (strcmp(op, "PEEK") == 0)
		{
			Peek(&st);
		}
		else if (strcmp(op, "DUP") == 0)
		{
			Duplicate(&st,n);
		}
		else if (strcmp(op, "UpR") == 0)
		{
			int k;
			scanf("%d", &k);
			upRotate(&st, k);
		}
		else if (strcmp(op, "DownR") == 0)
		{
			int k;
			scanf("%d", &k);
			downRotate(&st, k);
		}
		
	}

	return 0;
}