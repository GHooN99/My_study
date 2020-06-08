#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct Node
{
	struct Node *left;
	struct Node *right;
	int id;
	int data;
}Node;

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

void setNode(Node *crnt, Node *left, Node *right,int id, int data)
{
	(crnt)->data = data;
	(crnt)->left = left;
	(crnt)->right = right;
	crnt->id = id;
}

void preOrder(Node *root)
{
	if (root != NULL)
	{
		printf(" %d", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
	else
		return;
}
void postOrder(Node *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d", root->data);
	}
	else
		return;
}
void inOrder(Node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf(" %d", root->data);
		inOrder(root->right);
	}
	else
		return;
}
void searchNode(Node *root, int id,int *find,Node **find_node)
{
	if (root != NULL)
	{
		if (root->id == id)
		{
			*find = root->id;
			*find_node = root;
		}
		searchNode(root->left, id, find, find_node);
		searchNode(root->right, id, find, find_node);
	}
	else
		return;
}
int main()
{
	Node *Tree[8];
	for (int i = 0; i < 8; i++)
		Tree[i] = allocNode();

	Node *root=Tree[0];


	setNode(Tree[3], NULL, NULL,4, 70);
	setNode(Tree[4], NULL, NULL, 5,90);
	setNode(Tree[6], NULL, NULL,7, 130);
	setNode(Tree[7], NULL, NULL,8, 80);

	setNode(Tree[5], Tree[6], Tree[7],6, 120);
	setNode(Tree[1], Tree[3], Tree[4], 2,30);
	setNode(Tree[2], NULL, Tree[5],3 ,50);
	setNode(Tree[0], Tree[1], Tree[2],1, 20);

	int n, node_id,find_id =0;

	scanf("%d %d", &n, &node_id);


	
	if (node_id > 8)
	{
		printf("-1");
		return -1;
	}
	else
	{
		Node *find_node = NULL;
		 searchNode(root, node_id,&find_id,&find_node);
		root = find_node;

		switch (n)
		{
			case 1:
				preOrder(root);
				break;
			case 2:
				inOrder(root);
				break;
			case 3:
				postOrder(root);
				break;
			default:
				break;
		}
	}

	return 0;
}