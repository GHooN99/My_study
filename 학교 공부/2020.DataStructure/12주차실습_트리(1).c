#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
}Node;

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

void setNode(Node *crnt, Node *left, Node *right, int data)
{
	(crnt)->data = data;
	(crnt)->left = left;
	(crnt)->right = right;
}

int main()
{
	Node *Tree[8];
	int n;
	scanf("%d", &n);
	n--;
	for (int i = 0; i < 8; i++)
		Tree[i] = allocNode();

	setNode(Tree[3], NULL,NULL, 70);
	setNode(Tree[4], NULL, NULL,  90);
	setNode(Tree[6], NULL, NULL,  130);
	setNode(Tree[7], NULL, NULL, 80);

	setNode(Tree[5], Tree[6], Tree[7], 120);
	setNode(Tree[1], Tree[3], Tree[4], 30);
	setNode(Tree[2], NULL, Tree[5], 50);
	setNode(Tree[0], Tree[1], Tree[2], 20);

	if (n > 7) printf("-1");
	else
	{
		printf("%d ", Tree[n]->data);

		if (Tree[n]->left != NULL)
			printf("%d ", Tree[n]->left->data);
		if(Tree[n]->right != NULL)
			printf("%d ", Tree[n]->right->data);
	}
	
	return 0;
}