#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/*포인터 선형 연결 리스트*/

// int 형 배열 

typedef struct Node
{
	int data; //데이터
	struct Node *next; // 다음 노드의 주소
}Node;

typedef struct List
{
	Node *head; //머리노드의 주소
	Node *crnt; // 현재 선택 노드의 주소
}List;

Node* allocNode(void) //노드 동적할당 
{
	return calloc(1, sizeof(Node));
}
void setNode(Node *n, int data, Node *next) //n이 가리키는 노드의 값 설정
{
	n->data = data;
	n->next = next;
}
void Init(List *list) //리스트 초기화
{
	list->head = NULL; 
	list->crnt = NULL;
}
void insertFront(List *list, int data)  //머리에 노드를 삽입
{
	Node *ptr = list->head;  //삽입전 머리노드가 가리키는곳 저장
	list->head = list->crnt = allocNode(); //새로운 노드 머리노드에 할당 
	setNode(list->head, data, ptr); //새로운 머리노드 값 설정 (다음이 ptr 로 이어지게)
}
void insertRear(List *list, int data) //꼬리에 노드를 삽입
{
	Node *ptr;
	if (list->head == NULL) //리스트가 비어있는경우 앞에 삽입
		insertFront(list, data);
	else
	{
		ptr = list->head; //머리노드의 주소
		while (ptr->next !=NULL) //다음노드 주소가 NULL이(이면 꼬리) 아닐때 까지
		{
			ptr = ptr->next; 
		}
		ptr->next = list->crnt = allocNode(); //꼬리노드에 새 노드 할당 
		setNode(ptr->next, data, NULL); //새로운 꼬리 노드 설정
	}
}
void removeFront(List *list) //머리노드 삭제
{
	if (list->head != NULL) // 노드가존재하면
	{
		Node *ptr = list->head->next; //두번째 노드의 주소
		free(list->head); //할당 해제
		list->head = list->crnt = ptr; //두번째 주소에 연결
	}
}
void removeRear(List *list) // 꼬리노드 삭제
{
	Node *ptr,*pre=NULL;
	if (list->head != NULL) //삭제할것이 있으면
	{
		if (list->head->next == NULL) //1개만 있으면 머리 삭제
			removeFront(list);
		else
		{
			ptr = list->head; //머리노드의 주소
			while (ptr->next != NULL) //다음노드 주소가 NULL이(이면 꼬리) 아닐때 까지
			{
				pre = ptr; //삭제되기 전 노드 주소
				ptr = ptr->next;
			}
			
			free(ptr); //꼬리노드 할당 해제
			pre->next = NULL; //꼬리전 연결 해제
			list->crnt = pre; // 현재  선택노드는 꼬리
		}
	}
}
void removeCurrent(List *list) //선택 노드를 삭제
{
	if (list->crnt == list->head) //머리노드이면 머리노드 삭제
		removeFront(list);
	else
	{
		Node *ptr = list->head;
		while (ptr->next!=list->crnt) //다음이 선택노드 전까지
		{
			ptr = ptr->next;
		}
		ptr->next = list->crnt->next; //전노드의 다음주소에 선택노드의 다음주소 대입
		free(list->crnt);
		list->crnt = ptr; //현재 선택노드를 그 (전)노드로
	}
}
void Clear(List *list) //모든 노드 삭제
{
	while (list->head=NULL) // 머리노드가 없을떄까지
	{
		removeFront(list); //앞노드 삭제
	}
	list->crnt = NULL;
}
void printList(const List *list) //모든 노드 출력
{
	if (list->head == NULL)
		printf("Empty !!\n");
	else
	{
		Node *ptr=list->head;
		printf("[ ");
		while (ptr!=NULL)
		{
			printf("%d, ", ptr->data); //출력 후 다음 노드로
			ptr = ptr->next;
		}
		printf("]\n");
	}

}
void terminate(List *list) //종료
{
	Clear(list);
}
int Search(List *list, int data) //데이터 검색
{
	Node *ptr = list->head;
	int idx = 0;
	while (ptr!=NULL) //꼬리전까지
	{
		if (ptr->data == data)
		{
			list->crnt = ptr; //찾은 노드를 현재 선택노드로 함
			return idx;
		}
		ptr = ptr->next;
		idx++;
	}
	return -1; //찾기 실패
}
int main()
{
	int menu, x,idx;

	List list;
	Init(&list);
	while (1)
	{
		printList(&list);
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
				idx=Search(&list, x);
				if (idx != -1)
					printf("%d's idx : %d\n", x, idx);
				else
					printf("Fail\n");
				break;
			case 0:
				terminate(&list);
				return 0;

			default:
				break;
		}
	}
	return 0;
}

