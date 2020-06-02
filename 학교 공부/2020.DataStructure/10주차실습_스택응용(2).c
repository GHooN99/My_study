#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef int bool;


typedef struct stack
{
	char *head;
	int cur;
}stack;

bool isEmpty(stack *s)
{
	return s->cur == -1;
}
bool isNumber(char x)
{
	return '0' <= x && x <= '9';
}

int cal(int x, int y, char op)
{
	switch (op)
	{
		case '+':	return x + y;
		case '-':	return x - y;
		case '/':	return x / y;
		case '*':	return x * y;
	}
}
int Size(stack *s)
{
	return s->cur + 1;
}
void initStack(stack *s, int n)
{
	s->head = (char*)calloc(n, sizeof(char));
	s->cur = -1;
}
void Push(stack *s, int n, char data)
{
	if (Size(s) == n)
	{
		//printf("Stack FULL\n");
		return;
	}
	s->head[++(s->cur)] = data;
}
char Pop(stack *s)
{
	if (isEmpty(s))
	{
		//printf("Stack Empty\n");
		return (char)NULL;
	}
	char data = s->head[s->cur--];

	return data;
}
char Peek(stack *s)
{
	if (isEmpty(s))
	{
		return (char)NULL;
	}
	return s->head[s->cur];
}
int calPostfix(char *str)
{
	stack st;
	initStack(&st,100);
	int post[100] = { 0 };

	for (int i = 0; i < strlen(str); i++)
	{
		if (isNumber(str[i]))
			Push(&st, 100, str[i]);
		else
		{
			int a =(int)Pop(&st)-'0';
			int b =(int)Pop(&st)-'0';
			char num = (char)cal(b, a, str[i])+'0';
			
			Push(&st, 100, num);
		}
	}

	char result;
	result = Pop(&st);
	
	return (int)result - '0';

}

int main()
{

	int n;
	char str[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		printf("%d\n", calPostfix(str));
	}

	return 0;
}