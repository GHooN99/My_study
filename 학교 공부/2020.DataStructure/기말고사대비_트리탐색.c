#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
}Tree;
typedef struct Node
{
	Tree *node;
	struct Node *next;
}Node;
Tree* allocTree()
{
	return (Tree*)calloc(1, sizeof(Tree));
}

Node* allocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

void setNode(Node **crnt, Node *next, Tree *node)
{
	(*crnt)->node = node;
	(*crnt)->next = next;
}
void initList(Node **head)
{
	(*head) = allocNode();
	setNode(head, NULL, 0);
}
int Size(Node *head)
{
	Node *ptr = head->next;
	int cnt = 0;
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





void addFirst(Node **list,Tree *node)
{
	Node *new_node = allocNode();

	setNode(&new_node, (*list)->next, node);
	(*list)->next = new_node;

}
Tree *removeLast(Node **list)
{
	Node *prev_ptr = (*list);
	Node *ptr = (*list)->next;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		prev_ptr = prev_ptr->next;
	}
	Tree *node = ptr->node;
	prev_ptr->next = NULL;
	free(ptr);
	return node;
}
void printList(Node *list)
{
	Node *ptr = list->next;
	while (ptr!=NULL)
	{
		printf("%d ", ptr->node->data);
		ptr = ptr->next;
	}
	printf("\n");
}
void setTree(Tree **root)
{
	int x, y, z;
	if (*root != NULL)
	{
		scanf("%d %d %d", &x, &y, &z);
		Tree *left_child = allocTree();
		Tree *right_child = allocTree();
		(*root)->data = x;
		if (y != 0)
		{
			(*root)->left = left_child;
			left_child->data = y;
		}
		else
		{
			(*root)->left = NULL;
		}
		if (z != 0)
		{
			(*root)->right = right_child;
			right_child->data = z;
		}
		else
		{
			(*root)->right = NULL;
		}
		setTree(&(*root)->left);
		setTree(&(*root)->right);
	}
	else 
		return;

}


void enqueue(Node **que,Tree *data)
{
	addFirst(que, data);
}
Tree* dequeue(Node **que)
{
	return removeLast(que);
}
void preorder(Tree *tree)
{
	if (tree != NULL)
	{
		printf("%d -> ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
	else
		return;
}
void inorder(Tree *tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		printf("%d -> ", tree->data);
		inorder(tree->right);
	}
	else
		return;
}
void postorder(Tree *tree)
{
	if (tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d -> ", tree->data);
	}
	else
		return;
}
void levelorder(Tree *tree)
{
	Tree *node;
	Node *queue = allocNode();
	initList(&queue);
	enqueue(&queue,tree);
	while (!isEmpty(queue))
	{
		node = dequeue(&queue);
		printf("%d -> ", node->data);
		if(node->left!=NULL)
			enqueue(&queue, node->left);
		if (node->right != NULL)
			enqueue(&queue, node->right);
	}

}
int main()
{
	Tree *root = allocTree();

	int data;

	setTree(&root);
	printf("pre:");
	preorder(root);
	printf("\n");
	printf("in:");
	inorder(root);
	printf("\n");
	printf("post:");
	postorder(root);
	printf("\n");
	printf("level:");
	levelorder(root);

	/*
	Node *queue;
	initList(&queue);
	for(int i=0;i<5;i++)
	{
		printf("_____\n");
		printList(queue);
		scanf("%d", &data);
		enqueue(&queue, data);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("_____\n");
		printList(queue);
		printf("%d",dequeue(&queue));
	}

	*/
	return 0;
}