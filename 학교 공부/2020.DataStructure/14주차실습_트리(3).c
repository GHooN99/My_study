#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node  //노드 정의 
{
	struct Node *left;    // 왼쪽 노드의 주소
	struct Node *right;   // 오른쪽 노드의 주소
	int id;					// 노드의 번호
}Node;

Node* allocNode()   //노드 할당함수 
{
	return (Node*)calloc(1, sizeof(Node)); //1개의 노드를 할당함
}
void setNode(Node **root)  //트리 입력 함수 
{
	int x, y, z;  //입력 변수 선언

	if (*root != NULL)   // 루트 노드가 NULL 이 아닐때 
	{
		scanf("%d %d %d", &x, &y, &z);   //데이터 입력 

		Node *left_child = allocNode();  //왼쪽 자식노드 할당
		Node *right_child = allocNode(); // 오른쪽 자식노드 할당

		(*root)->id = x;			//현재 노드의 번호 설정

		if (y != 0)				//0이 아닐때
		{
			(*root)->left = left_child;   //왼쪽 노드 연결
			left_child->id = y;			// 왼쪽 번호 설정
		}
		else
			(*root)->left = NULL;    // 0이면 왼쪽자식은 없음

		if (z != 0)			// 0이 아닐때
		{
			(*root)->right = right_child;  //오른쪽 노드 연결
			right_child->id = z;			// 오른쪽 번호 설정
		}
		else				
			(*root)->right = NULL;   //0이면 오른쪽 자식은 없음

		setNode(&((*root)->left));   // 재귀 호출 (전위)순회 순서에 따라 입력을 함 입력후 왼쪽으로
		setNode(&((*root)->right));   // 재귀 호출 (전위)순회 순서에 따라 입력을 함 입력후 오른쪽으로
	}
	else   // NULL인 끝 노드에 도착하면
		return;  // 재귀 빠져나오기
}
void printTree(Node *root, char *str)  // 트리 선회
{
	Node *ptr = root;   // 임시 노드 변수
	int n = strlen(str); //문자열의 길이 저장
	for (int i = 0; i <= n; i++) //길이+1 번 반복 
	{
		printf(" %d", ptr->id);  // 현재 노드 번호 출력 
		if (str[i] == 'L')  // l 이면 왼쪽 노드로 이동
			ptr = ptr->left;
		else if (str[i] == 'R')  // r 이면 오른쪽 노드로 이동
			ptr = ptr->right;
	}
}
int main()
{
	int n;		//변수 선언 
	char str[101];
	Node *root=allocNode();  // 뿌리 노드 할당 

	scanf("%d", &n);  //입력

	setNode(&root);  //트리 설정 

	scanf("%d", &n);  //탐색 횟수 
	for (int i = 0; i < n; i++)  //n번 반복
	{
		scanf("%s", str);  // 문자열 입력 
		printTree(root, str); //탐색결과 출력 
		printf("\n"); // 개행
	}
	return 0;
}