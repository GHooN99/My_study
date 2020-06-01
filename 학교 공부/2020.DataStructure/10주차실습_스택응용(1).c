#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

typedef int bool;

const int value[] = { 1,2,3,3,4,4,5,5,6,6,6 };
const char symbol[] = { '|','&','<','>','-','+','/','*','!','^','%' };


typedef struct stack
{
	char *head;
	int cur;
}stack;

bool isEmpty(stack *s)
{
	return s->cur == -1;
}
bool isAlpha(char x)
{
	return 'A' <= x && x <= 'Z';
}
int findOrder(char x)
{
	if (x == '(' || x== ')')
		return 0;
	for (int i = 0; i < 11; i++)
	{
		if (x == symbol[i]) return value[i];
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

void convertPostfix(char *str)
{
	char postfix[100];
	stack op;
	int idx = 0;
	initStack(&op, 100);
	char x;
	bool number = false;

	for (int i = 0; i < strlen(str); i++)
	{
		if (isAlpha(str[i]))
			postfix[idx++] = str[i];
		else if (str[i]=='(')
			Push(&op, 100, str[i]);
		else if (str[i] == ')')
		{
			while (Peek(&op) != '(')
			{
				x= Pop(&op);
				if(x=='|'||x=='&')
				postfix[idx++] = x;

				postfix[idx++] = x;
			}
			x=Pop(&op);
		}
		else //isOperator
		{
			if (str[i] == '+' && !isAlpha(str[i - 1]))
			{
				if(str[i-1]!=')')
				str[i] = '^';
			}
					
			if (str[i] == '-' && !isAlpha(str[i - 1]))
			{
				if (str[i - 1] != ')')
				str[i] = '%';
			}
					

			if (str[i] == '|' || str[i] == '&')
				i++;

			int s1 = findOrder(str[i]);
			int s2 = findOrder(Peek(&op));

			while (!isEmpty(&op)&&s1<=s2)
			{
				x = Pop(&op);
				if (x == '|' || x == '&')
					postfix[idx++] = x;

				postfix[idx++] = x;
				s2 = findOrder(Peek(&op));
			}
			Push(&op, 100, str[i]);
		}

	}
	while (!isEmpty(&op))
	{
		x = Pop(&op);
		if (x != '(' && x != ')')
		{
			if (x == '|' || x == '&')
				postfix[idx++] = x;
			postfix[idx++] = x;
		}
	}
	postfix[idx] = '\0';

	
	for (int i = 0; i < strlen(postfix); i++)
	{
		if (postfix[i] == '^')
			postfix[i] = '+';
		if (postfix[i] == '%')
			postfix[i] = '-';
	}
	
	strcpy(str, postfix);
}
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char str[101];

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		convertPostfix(str);
		printf("%s\n", str);
	}

	return 0;
}