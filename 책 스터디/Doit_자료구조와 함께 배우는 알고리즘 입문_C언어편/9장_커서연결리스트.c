#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

 /* 커서로 연결리스트 만들기 */

//데이터의 크기가 크게 변하지 않고 최대개수를 알때 
//메모리를 만들고 해제하는 비용을 줄이기 위해

#define NULLCUR -1		//빈 커서

typedef int Index;		// 커서의 자료형 

/* 프리리스트 -> 리스트를 삭제하면 나오는 빈배열의 문제 해결법 */
typedef struct Node
{
	int data;			//데이터
	Index next;			//다음 노드의 인덱스 
	Index Dnext;		//프리 리스트의 다음 노드 

}Node;

typedef struct List
{
	Node *n;		//리스트 본체(배열)
	Index head;		//머리노드
	Index max;		//사용중인 꼬리 레코드
	Index deleted;   //프리 리스트의 머리노드
	Index crnt;		//선택한 노드

}List;

Index getIndex(List *list) //삽입할 레코드의 인덱스
{
	if (list->deleted == NULLCUR) //삭제할것이 없는경우
		return ++(list->max); //사용중인 꼬리인덱스 +1 반환
	else
	{
		Index rec = list->deleted; //프리리스트 머리노드
		list->deleted = list->n[rec].Dnext; //rec번째 다음노드를 새로운 프리 리스트의 머리노드에 대입
		return rec;
	}
}
void deleteIndex(List *list, Index idx) //지정 레코드를 삭제리스트에 등록
{
	if (list->deleted == NULLCUR) //삭제할것이 없는경우
	{
		list->deleted = idx;		//프리리스르의 머리노드를 idx 로
		list->n[idx].Dnext = NULLCUR;	//꼬리노드로 만들기
	}
	else
	{
		Index ptr = list->deleted;  //예전 프리리스트 머리
		list->deleted = idx; //프리리스트의 머리
		list->n[idx].Dnext = ptr; // 프리리스트의 다음 노드 를 예전 머리로 
	}
	
}

void setNode(Node *n, int data, Index next) //n이 가리키는 노드의 값 설정
{
	n->data = data;
	n->next = next;
}
void Init(List *list, int size) // 리스트 초기화
{
	list->n = calloc(size, sizeof(Node));
	list->head = NULLCUR;
	list->crnt = NULLCUR;
	list->deleted = NULLCUR;
	list->max = NULLCUR;
}
void insertFront(List *list, int data)
{
	Index ptr=list->head;
	list->head = list->crnt = getIndex(list); //새로운 머리노드 값 설정 (다음이 ptr 로 이어지게)
	setNode(&(list->n[list->head]), data, ptr); //노드의 값 설정 

}
void insertRear(List *list, int data)
{
	if (list->head == NULLCUR) //없으면 앞에다
		insertFront(list, data);
	else
	{
		Index ptr = list->head; // 머리 저장 
		while (list->n[ptr].next!=NULLCUR) //다음 노드가 꼬리가 아닐때까지
		{
			ptr = list->n[ptr].next;
		}
		//ptr은 꼬리
		list->n[ptr].next = list->crnt = getIndex(list); //뒤에 연결 
		setNode(&(list->n[list->n[ptr].next]), data, NULLCUR); // 노드 설정 
	}
}
void removeFront(List *list)
{
	if (list->head != NULLCUR) //삭제할것이 있으면
	{
		Index ptr = list->n[list->head].next; // 머리 다음 노드 저장 
		deleteIndex(list, list->head); //머리노드 삭제
		list->head = list->crnt = ptr; // 다시 연결 
	}

}
void removeRear(List *list)
{
	if (list->n[list->head].next == NULLCUR) //노드가 1개면
		removeFront(list); 
	else
	{
		Index ptr = list->head; // 머리 저장 
		Index pre; //꼬리 전 저장 
		while (list->n[ptr].next != NULLCUR) //다음 노드가 꼬리가 아닐때까지
		{
			pre = ptr;
			ptr = list->n[ptr].next;
		}
		//ptr은 꼬리 pre 는 꼬리전
		list->n[pre].next = NULLCUR;		//꼬리 끊기
		deleteIndex(list, ptr); //삭제 
		list->crnt = pre;
	}
}
void removeCurrent(List *list)
{
	if (list->crnt != NULLCUR)
	{
		Index ptr = list->head;
		while (list->n[ptr].next != list->crnt)
		{
			ptr = list->n[ptr].next;
		}
		list->n[ptr].next = list->n[list->crnt].next; //현재 선택 노드 를 현재선택 다음으로 이어주기 
		deleteIndex(list, list->crnt);
		list->crnt = ptr;
	}
}
void Clear(List *list)
{
	while (list->head != NULLCUR) // 머리노드가 없을떄까지
	{
		removeFront(list); //앞노드 삭제
	}
	list->crnt = NULLCUR;
}
void printList(const List *list) //모든 노드 출력
{
	if (list->head == NULLCUR)
		printf("Empty !!\n");
	else
	{
		Index ptr = list->head;
		printf("[ ");
		while (ptr != NULLCUR)
		{
			printf("%d, ", list->n[ptr].data); //출력 후 다음 노드로
			ptr = list->n[ptr].next;
		}
		printf("]\n");
	}

}
Index Search(List *list, int data)
{
	Index idx=0;
	Index ptr = list->head;
	while (list->n[ptr].next!=NULLCUR)
	{
		if (list->n[ptr].data == data)
		{
			list->crnt = list->n[ptr].next;
			return idx;
		}
		ptr = list->n[ptr].next;
		idx++;
	}
	return NULLCUR; //검색 실패
}
void terminate(List *list) //종료
{
	Clear(list);
	free(list->n);
}

int main()
{
	int menu, x, idx;

	List list;
	Init(&list,15);
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
			idx = Search(&list, x);
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