#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


const char order[4] = { '+','-','*','/' };
const int rank[4] = { 1,1,2,2};

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}
void initList(Node **head)
{
	(*head) = allocNode();
	(*head)->data = -1;
	(*head)->next = NULL;
}
void addFirst(Node **head,char data)
{
	Node *new_node = allocNode();

	new_node->next = (*head)->next;
	(*head)->next = new_node;
	new_node->data = data;
}
char removeFirst(Node **head)
{
	Node *ptr = (*head)->next;
	(*head)->next = ptr->next;
	char data = ptr->data;
	free(ptr);
	return data;
}

int Size(Node *head)
{
	int cnt = 0;
	Node *ptr = head->next;
	while (ptr!=NULL)
	{
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}
bool isEmpty(Node *head)
{
	return Size(head) == 0;
}
void Push(Node **head,char data)
{
	addFirst(head, data);
}
char Pop(Node **head )
{
	return removeFirst(head);
}
char Peek(Node *head)
{
	return head->next->data;
}
void Print(Node *head)
{
	Node *ptr = head->next;
	while (ptr != NULL)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
bool isOpen(char c)
{
	return c == '(' || c == '{' || c == '[';
}
bool isClose(char c)
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
bool isVaild(char *str, int *n)
{
	Node *stack;
	bool check = true;
	initList(&stack);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isOpen(str[i]))
		{
			Push(&stack, str[i]);
			(*n)++;
		}
		else if (isClose(str[i]))
		{
			(*n)++;
			if (isEmpty(stack))
			{
				check = false;
				continue;
			}
			char symbol = Pop(&stack);
			if (!isCounter(symbol, str[i]))
			{
				check = false;
			}
		}
	}
	if (!check) return false;
	else return isEmpty(stack);
}
bool isAlpha(char x)
{
	return 'A' <= x && x <= 'Z';
}
int oprank(char x)
{
	if (x == '(' || x == ')') return 0;
	for (int i = 0; i <3; i++)
	{
		if (x == order[i])
			return rank[i];
	}
	return -1;
}
void toPostfix(char *str)
{
	Node *stack;
	initList(&stack);
	char data;
	char postfix[101];
	int idx = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isOpen(str[i]))
			Push(&stack, str[i]);
		else if (isClose(str[i]))
		{
			while (Peek(stack)!= '(')
			{
				data = Pop(&stack);
				postfix[idx++] = data;
			}
			data = Pop(&stack); //'(' ²¨³¿ 
		}
		else if (isAlpha(str[i]))
		{
			postfix[idx++] = str[i];
		}
		else
		{
			if (isEmpty(stack))
				Push(&stack, str[i]);
			else
			{
				data = Peek(stack);
				while (!isEmpty(stack))
				{
					if (oprank(str[i]) <= oprank(data))
						postfix[idx++] = Pop(&stack);
					else
						break;
				}
				Push(&stack, str[i]);
			}
		}
	}
	while (!isEmpty(stack))
		postfix[idx++] = Pop(&stack);

	postfix[idx] = '\0';
	strcpy(str, postfix);
}
int main()
{
	char str[101];
	int n = 0;
	gets(str);
	
	if (isVaild(str,&n))
		printf("OK_%d\n", n);
	else
		printf("Wrong_%d\n", n);

	toPostfix(str);
	printf("%s", str);
	return 0;
}
