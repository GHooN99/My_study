#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/* 원형 연결 리스트 */
// 꼬리노드의 다음 노드가 NULL 값이 아닌 머리노드의 주소를 갖는다
/* 이중 연결 리스트*/
// 단방향일땐 다음을 찾기 쉽지만 그 전의 노드를 찾기 힘든 것을 개선


/* 원형 이중 연결 리스트 */
typedef int bool;
typedef int Index;
typedef struct Node
{
	int data; //데이터
	struct Node *next; // 다음 노드의 주소
	struct Node *prev; // 이전 노드의 주소 
}Node;

typedef struct List
{
	Node *head; // 머리노드의 주소
	Node *crnt; // 현재 선택 노드의 주소
}List;

Node* allocNode(void) //노드 동적할당 
{
	return calloc(1, sizeof(Node));
}
void setNode(Node *n, int data ,Node *prev, Node *next) //n이 가리키는 노드의 값 설정
{
	n->data = data;
	n->next = next;
	n->prev = prev;
}
void Init(List *list) //리스트 초기화
{
	Node *tmp = allocNode();
	list->head = tmp;
	list->crnt = tmp;
	tmp->next = tmp->prev = tmp;		// 자기 자신을 가리키는 더미 노드 생성 
}
bool isEmpty(const List *list)
{
	return (list->head == list->head->next);
}
void insertAfter(List *list, Node *p, int data) // p 가 가리키는 다음 노드에 노드 삽입
{
	Node *ptr = allocNode();
	Node *nxt = p->next;  
	p->next = p->next->prev = ptr; //새노드 연결
	setNode(ptr, data, p, nxt);		// 기존 노드 연결 
	list->crnt = ptr;		//현재 노드 설정
}
void insertFront(List *list, int data)
{
		insertAfter(list, list->head, data);
}
void insertRear(List *list, int data)
{
		insertAfter(list, list->head->prev, data);
}
void Remove(List *list, Node *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head) //삭제하고 남은게 없으면
		list->crnt = list->head->next;
}
void removeFront(List *list)
{
	if (!isEmpty(list))
		Remove(list, list->head->next);
}
void removeRear(List *list)
{
	if (!isEmpty(list))
		Remove(list, list->head->prev);
}
void removeCurrent(List *list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}
void Clear(List *list)
{
	while (!isEmpty(list))
		removeFront(list);
}
Index Search(List *list, int data)
{
	Index idx=0;
	Node *ptr = list->head->next;
	while (list->head != ptr)
	{
		if (ptr->data == data)
		{
			list->crnt = ptr;
			return idx;
		}
		ptr = ptr->next;
		idx++;
	}
	return -1;
}
void printList(const List *list) //모든 노드 출력
{
	if (isEmpty(list)) 
		printf("Empty !!\n");
	else
	{
		Node *ptr = list->head->next;
		printf("[ ");
		do
		{
			printf("%d, ", ptr->data); //출력 후 다음 노드로
			ptr = ptr->next;
		} while (ptr != list->head); // 한바퀴 돌기 
		printf("]\n");
	}
}
void printReverse(const List *list)
{
	if (isEmpty(list))
		printf("Empty !!\n");
	else
	{
		Node *ptr = list->head->prev;
		printf("[ ");
		do
		{
			printf("%d, ", ptr->data); //출력 후 다음 노드로
			ptr = ptr->prev;
		} while (ptr != list->head); // 한바퀴 돌기 
		printf("]\n");
	}

}
void Terminate(List *list)
{
	Clear(list);
	free(list->head); //더미노드 삭제
}
int main()
{
	int menu, x, idx;

	List list;
	Init(&list);
	while (1)
	{
		printList(&list);
		printf("Reverse :");
		printReverse(&list);
		printf("__________________________________________________________\n");
		printf("(1)insertFront (2)insertRear (3)removeFront (4)removeRear\n");
		printf("(5)removeCurrent (6)Clear (7)Search (0)Exit\n");
		printf("Menu :");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("Data :");
			scanf("%d", &x);
			insertFront(&list, x);
			break;
		case 2:
			printf("Data :");
			scanf("%d", &x);
			insertRear(&list, x);
			break;
		case 3:
			removeFront(&list);
			break;
		case 4:
			removeRear(&list);
			break;
		case 5:
			removeCurrent(&list);
			break;
		case 6:
			Clear(&list);
			break;
		case 7:
			printf("Data :");
			scanf("%d", &x);
			idx = Search(&list, x);
			if (idx != -1)
				printf("%d's idx : %d\n", x, idx);
			else
				printf("Fail\n");
			break;
		case 0:
			Terminate(&list);
			return 0;

		default:
			break;
		}
	}
	return 0;
}
