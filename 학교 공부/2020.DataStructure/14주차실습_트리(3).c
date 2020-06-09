#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node  //��� ���� 
{
	struct Node *left;    // ���� ����� �ּ�
	struct Node *right;   // ������ ����� �ּ�
	int id;					// ����� ��ȣ
}Node;

Node* allocNode()   //��� �Ҵ��Լ� 
{
	return (Node*)calloc(1, sizeof(Node)); //1���� ��带 �Ҵ���
}
void setNode(Node **root)  //Ʈ�� �Է� �Լ� 
{
	int x, y, z;  //�Է� ���� ����

	if (*root != NULL)   // ��Ʈ ��尡 NULL �� �ƴҶ� 
	{
		scanf("%d %d %d", &x, &y, &z);   //������ �Է� 

		Node *left_child = allocNode();  //���� �ڽĳ�� �Ҵ�
		Node *right_child = allocNode(); // ������ �ڽĳ�� �Ҵ�

		(*root)->id = x;			//���� ����� ��ȣ ����

		if (y != 0)				//0�� �ƴҶ�
		{
			(*root)->left = left_child;   //���� ��� ����
			left_child->id = y;			// ���� ��ȣ ����
		}
		else
			(*root)->left = NULL;    // 0�̸� �����ڽ��� ����

		if (z != 0)			// 0�� �ƴҶ�
		{
			(*root)->right = right_child;  //������ ��� ����
			right_child->id = z;			// ������ ��ȣ ����
		}
		else				
			(*root)->right = NULL;   //0�̸� ������ �ڽ��� ����

		setNode(&((*root)->left));   // ��� ȣ�� (����)��ȸ ������ ���� �Է��� �� �Է��� ��������
		setNode(&((*root)->right));   // ��� ȣ�� (����)��ȸ ������ ���� �Է��� �� �Է��� ����������
	}
	else   // NULL�� �� ��忡 �����ϸ�
		return;  // ��� ����������
}
void printTree(Node *root, char *str)  // Ʈ�� ��ȸ
{
	Node *ptr = root;   // �ӽ� ��� ����
	int n = strlen(str); //���ڿ��� ���� ����
	for (int i = 0; i <= n; i++) //����+1 �� �ݺ� 
	{
		printf(" %d", ptr->id);  // ���� ��� ��ȣ ��� 
		if (str[i] == 'L')  // l �̸� ���� ���� �̵�
			ptr = ptr->left;
		else if (str[i] == 'R')  // r �̸� ������ ���� �̵�
			ptr = ptr->right;
	}
}
int main()
{
	int n;		//���� ���� 
	char str[101];
	Node *root=allocNode();  // �Ѹ� ��� �Ҵ� 

	scanf("%d", &n);  //�Է�

	setNode(&root);  //Ʈ�� ���� 

	scanf("%d", &n);  //Ž�� Ƚ�� 
	for (int i = 0; i < n; i++)  //n�� �ݺ�
	{
		scanf("%s", str);  // ���ڿ� �Է� 
		printTree(root, str); //Ž����� ��� 
		printf("\n"); // ����
	}
	return 0;
}