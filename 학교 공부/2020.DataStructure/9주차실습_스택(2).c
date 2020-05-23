#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAX_SIZE 1001

typedef struct stack
{
	char head[MAX_SIZE];
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
void initStack(stack *s)
{
	s->cur = -1;
}
void Push(stack *s,  char data)
{
	s->head[++(s->cur)] = data;
}
char Pop(stack *s)
{
	if (isEmpty(s))
	{
		return (char)NULL;
	}
	char data = s->head[s->cur--];

	return data;
}
void printStack(stack *s)
{
	for (int i = s->cur; i >= 0; i--)
		printf("%c", s->head[i]);
	printf("\n");
}

bool isOpenSymbol(char c)
{
	return c == '(' || c == '{' || c == '[';
}
bool isCloseSymbol(char c)
{
	return c == ')' || c == '}' || c == ']';
}
bool isCounter(char x, char y)
{
	if (x == '('&&y == ')')	return true;
	if (x == '['&&y == ']') return true;
	if (x == '{'&&y == '}')	return true;
	else return false;
}
bool isValid(char *str, int *n)
{
	stack st;
	bool check = true;
	char p;
	initStack(&st);

	for (int i = 0; i < strlen(str); i++)
	{
		if (isOpenSymbol(str[i]))
		{
			(*n)++;
			Push(&st, str[i]);
		}
		else if (isCloseSymbol(str[i]))
		{
			(*n)++;
			if (isEmpty(&st))
				check = false;

			p = Pop(&st);

			if (!isCounter(p, str[i]))
				check = false;
		}
	}

	if (!check) return check;
	else return isEmpty(&st);
}

int main()
{
	char str[1001];
	int n=0;
	
	gets(str);
	
	if (isValid(str,&n))
		printf("OK_%d", n);
	else
		printf("Wrong_%d", n);

	return 0;
}